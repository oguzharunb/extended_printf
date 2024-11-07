#include "./includes/og_printf.h"
#include <stdio.h>


int main(void)
{
	float a = 0.625f;
	long exponent;
	long fraction_b = *(int *)&a;
	unsigned long iter = 5;
	long i = 0;
	unsigned long total = 0;
	long step = 0;
	exponent = ((*(int *)&a & FLOAT_EXPONENT_MASK) >> 23) - 127;
	if (exponent >= 0)
		fraction_b = ((*(int *)&a & FLOAT_FRACTION_MASK)) << exponent;
	else
		fraction_b = ((((*(int *)&a & FLOAT_FRACTION_MASK)) >> 1) | FRACTION_ITER) >> (ft_abs(exponent) - 1);
	while (i < 19)
	{
		if ((FRACTION_ITER >> i) & fraction_b)
		{
			if (step)
				total = total * power(10, i - step + 1) + iter;
			else
				total = total + iter;
			printf("total: %ld, iter: %lu, i: %ld, step: %ld, power: %ld\n", total, iter, i, step, power(10, step));
			step = i + 1;
		}
		iter *= 5;
		i++;
	}
	printf("final: %0*ld\n", (int)step, total);
	return (0);
}
