from cellmlmanip.printer import Printer
from sympy import Pow, Mul, S
from sympy.printing.cxxcode import cxxcode
from sympy.printing.precedence import precedence
from sympy.core.mul import _keep_coeff


class ChastePrinter(Printer):
    """
    Converts Sympy expressions to strings for use in Chaste code generation.

    To use, create a :class:`ChastePrinter` instance, and call its method
    :meth:`doprint()` with a Sympy expression argument.

    Arguments:

    ``symbol_function``
        A function that converts symbols to strings (variable names).
    ``derivative_function``
        A function that converts derivatives to strings.

    """
    _function_names = {
        'abs_': 'fabs',
        'acos_': 'acos',
        'cos_': 'cos',
        'exp_': 'exp',
        'sqrt_': 'sqrt',
        'sin_': 'sin',

        'Abs': 'fabs',
        'acos': 'acos',
        'acosh': 'acosh',
        'asin': 'asin',
        'asinh': 'asinh',
        'atan': 'atan',
        'atan2': 'atan2',
        'atanh': 'atanh',
        'ceiling': 'ceil',
        'cos': 'cos',
        'cosh': 'cosh',
        'exp': 'exp',
        'expm1': 'expm1',
        'factorial': 'factorial',
        'floor': 'floor',
        'log': 'log',
        'log10': 'log10',
        'log1p': 'log1p',
        'log2': 'log2',
        'sin': 'sin',
        'sinh': 'sinh',
        'sqrt': 'sqrt',
        'tan': 'tan',
        'tanh': 'tanh',

        'sign': 'Signum',
        'GetIntracellularAreaStimulus': 'GetIntracellularAreaStimulus',
        'HeartConfig::Instance()->GetCapacitance': 'HeartConfig::Instance()->GetCapacitance',
        'GetExperimentalVoltageAtTimeT': 'GetExperimentalVoltageAtTimeT'
    }

    _literal_names = {
        'e': 'e',
        'nan': 'NAN',
        'pi': 'M_PI',
    }

    def __init__(self, symbol_function=None, derivative_function=None):
        super().__init__(symbol_function, derivative_function)
        self.lookup_tables = None

    def _print_lookup_table_item(self, expr):
        if self.lookup_tables is not None:
            printed_expr = self.lookup_tables.print_lut_expr(expr)
            if printed_expr is not None:
                return printed_expr
        return False

    def _is_lookup_table_item(self, expr):
        if self.lookup_tables is not None:
            return self.lookup_tables.is_lut_expr(expr)
        return False

    def _print(self, expr, **kwargs):
        """Internal dispatcher.
        Here we intercept lookup table expressions if we have lookup tables"""
        printed_expr = self._print_lookup_table_item(expr)
        if printed_expr:
            return printed_expr
        return super()._print(expr, **kwargs)

    def _print_Function(self, expr):
        """ Handles function calls. """

        # Check if function is known to python math
        name = expr.func.__name__
        # Convert arguments
        args = self._bracket_args(expr.args, 0)

        if name in self._function_names:
            name = self._function_names[name]
        else:
            raise ValueError('Unsupported function: ' + str(name))

        return name + '(' + args + ')'

    def _print_And(self, expr):
        """ Handles logical And. """
        my_prec = precedence(expr)
        return ' && '.join(['(' + self._bracket(x, my_prec) + ')' for x in expr.args])

    def _print_BooleanFalse(self, expr):
        """ Handles False """
        return 'false'

    def _print_BooleanTrue(self, expr):
        """ Handles True """
        return 'true'

    def _print_Or(self, expr):
        """ Handles logical Or. """
        my_prec = precedence(expr)
        return ' || '.join(['(' + self._bracket(x, my_prec) + ')' for x in expr.args])

    def _print_ordinary_pow(self, expr):
        """ Handles Pow(), handles just ordinary powers without division.
        For C++ printing we need to write ``x**y`` as ``pow(x, y)`` with lowercase ``p``."""
        p = precedence(expr)
        if expr.exp == 0.5:
            return 'sqrt(' + self._bracket(expr.base, p) + ')'
        return 'pow(' + self._bracket(expr.base, p) + ', ' + self._bracket(expr.exp, p) + ')'

    def _print_ternary(self, cond, expr):
        parts = ''
        parts += '('
        parts += self._print(cond)
        parts += ') ? ('
        parts += self._print(expr)
        parts += ') : ('
        return parts

    def _print_float(self, expr):
        """ Handles ``float``s. """
        return cxxcode(expr, standard='C++11')

    def _print_Mul(self, expr):
        """
        Handles multiplication & division, with n terms.

        Division is specified as a power: ``x / y --> x * y**-1``.
        Subtraction is specified as ``x - y --> x + (-1 * y)``.
        """
        # This method is mostly copied from sympy.printing.Str
        # With a tweak to prevet pritnting 1.0 * ...
        # And to deal with lookup tables

        # Check overall sign of multiplication
        sign = ''
        c, e = expr.as_coeff_Mul()
        if c < 0:
            expr *= -1 #= _keep_coeff(-c, e)
            sign = '-'

        # Collect all pows with more than one base element and exp = -1
        pow_brackets = []

        # Gather terms for numerator and denominator
        a, b = [], []
        for item in Mul.make_args(expr):
            if item != 1.0:  # don't print 1.0 *...
                # Check if this is a negative power that we can write as a division
                negative_power = (
                    not self._is_lookup_table_item and  # don't turn lookup tabe expressions into devisions
                    item.is_commutative and item.is_Pow
                    and item.exp.is_Rational and item.exp.is_negative)
                if negative_power:
                    if item.exp != -1:
                        # E.g. x * y**(-2 / 3) --> x / y**(2 / 3)
                        # Add as power
                        b.append(Pow(item.base, -item.exp, evaluate=False))
                    else:
                        # Add without power
                        b.append(Pow(item.base, -item.exp))

                        # Check if it's a negative power that needs brackets
                        # Sympy issue #14160
                        if (len(item.args[0].args) != 1
                                and isinstance(item.base, Mul)):
                            pow_brackets.append(item)

                # Split Rationals over a and b, ignoring any 1s
                elif item.is_Rational:
                    if item.p != 1:
                        a.append(Rational(item.p))
                    if item.q != 1:
                        b.append(Rational(item.q))

                else:
                    a.append(item)

        # Replace empty numerator with one
        a = a or [S.One]

        # Convert terms to code
        my_prec = precedence(expr)
        a_str = [self._bracket(x, my_prec) for x in a]
        b_str = [self._bracket(x, my_prec) for x in b]

        # Fix brackets for Pow with exp -1 with more than one Symbol
        for item in pow_brackets:
            assert item.base in b, "item.base should be kept in b for powers"
            b_str[b.index(item.base)] = \
                '(' + b_str[b.index(item.base)] + ')'

        # Combine numerator and denomenator and return
        a_str = sign + ' * '.join(a_str)
        if len(b) == 0:
            return a_str
        b_str = ' * '.join(b_str)
        return a_str + ' / ' + (b_str if len(b) == 1 else '(' + b_str + ')')