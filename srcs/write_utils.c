#include "../includes/og_printf.h"

// (number, 0, 0, 0, 5)
unsigned long	float_fraction(float number, long i, unsigned long total, long basamak, unsigned long iter)
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
			if (basamak)
				total = total * power(10, i - basamak + 1) + iter;
			else
				total = total + iter;
			basamak = i + 1;
		}
		iter *= 5;
		i++;
	}
	return (total);
}
