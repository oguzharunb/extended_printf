#include "../includes/og_printf.h"

void	write_signed_number(long number, char *dest, t_format *flags)
{
	int i;
	int filler;
	int tmp;

	tmp = number;
	i = 0;
	if (flags->flag_zero)
		filler = '0';
	else
		filler = ' ';
	while (i < flags->width)
		dest[i++] = filler;
	if (i < (int)og_number_len_base(tmp, 10))
		i = (int)og_number_len_base(tmp, 10);
	if (number < 0)
		number = -number;
	if (flags->flag_min)
		i = og_number_len_base(tmp, 10);
	while (number)
	{
		dest[--i] = (number % 10) + '0';
		number /= 10;
	}
	if (tmp < 0)
	{
        if (flags->flag_zero)
            *dest = '-';
        else
            dest[i - 1] = '-';
    }
    else if (flags->flag_plus)
    {
		if (flags->flag_plus)
			*dest = '+';
		else
			dest[i - 1] = '+';
	}
}
//	float a = 0.625f;
//	long exponent;
//	long fraction_b = *(int *)&a;
//	unsigned long iter = 5;
//	long i = 0;
//	unsigned long total = 0;
//	long basamak = 0;
//	exponent = ((*(int *)&a & FLOAT_EXPONENT_MASK) >> 23) - 127;
//	if (exponent >= 0)
//		fraction_b = ((*(int *)&a & FLOAT_FRACTION_MASK)) << exponent;
//	else
//		fraction_b = ((((*(int *)&a & FLOAT_FRACTION_MASK)) >> 1) | FRACTION_ITER) >> (ft_abs(exponent) - 1);
//	while (i < 19)
//	{
//		if ((FRACTION_ITER >> i) & fraction_b)
//		{
//			if (basamak)
//				total = total * power(10, i - basamak + 1) + iter;
//			else
//				total = total + iter;
//			printf("total: %ld, iter: %lu, i: %ld, basamak: %ld, power: %ld\n", total, iter, i, basamak, power(10, basamak));
//			basamak = i + 1;
//		}
//		iter *= 5;
//		i++;
//	}
//	printf("final: %0*ld\n", (int)basamak, total);
#include <stdio.h>

void	write_float_number(float number, char *dest, t_format *flags)
{
	(void)number;
	(void)dest;
	(void)flags;
}