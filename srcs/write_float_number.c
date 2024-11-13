#include "../includes/og_printf.h"

// (number, 0, 0, 0, 5)

unsigned long	float_fraction(float number, long i, unsigned long total, long *step, unsigned long iter);

void	write_float_number(float number, char *dest)
{
    unsigned long	fraction;
    unsigned long	integer;
    unsigned long	i;
    long			save;

    i = og_unumber_len_base(fraction, 10) + og_unumber_len_base(integer, 10);
    memset(dest, '0', i);
    while (fraction)
    {
        dest[i] = (fraction % 10) + '0';
        fraction /= 10;
        i--;
    }
    dest[i--] = '.';
    while (integer)
    {
        dest[i] = (integer % 10) + '0';
        integer /= 10;
        i--;
    }
	return (og_unumber_len_base(fraction, 10) + og_unumber_len_base(integer, 10));
}

// number, 0, 0, &step = 0, 5
unsigned long	float_fraction(float number, long i, unsigned long total, long *step, unsigned long iter)
{
	long exponent;
	long fraction_b;

	fraction_b = *(int *)&number;
	i = 0;
	exponent = ((*(int *)&number & FLOAT_EXPONENT_MASK) >> 23) - 127;
	if (exponent >= 0)
		fraction_b = ((*(int *)&number & FLOAT_FRACTION_MASK)) << exponent;
	else
		fraction_b = ((((*(int *)&number & FLOAT_FRACTION_MASK)) >> 1)
					| FRACTION_ITER) >> (ft_abs(exponent) - 1);
	while (i < 19)
	{
		if ((FRACTION_ITER >> i) & fraction_b)
		{
			if (*step)
				total = total * power(10, i - *step + 1) + iter;
			else
				total = total + iter;
			*step = i + 1;
		}
		iter *= 5;
		i++;
	}
	return (total);
}
