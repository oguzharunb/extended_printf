#include "./includes/og_printf.h"
#include <stdio.h>

#define FRACTION_ITER 0b00000000010000000000000000000000
int main(void)
{
	float a = 10.125f;
	int exponent;
	int fraction_b = *(int *)&a;
	int iter = 5;
	int i = 0;
	long total = 0;
	exponent = ((*(int *)&a & FLOAT_EXPONENT_MASK) >> 23) - 127;
	fraction_b = ((*(int *)&a & FLOAT_FRACTION_MASK)) << exponent;
	while (i < 23)
	{
		if ((FRACTION_ITER >> i) & fraction_b)
		{
			total = (total * 10) + iter;
			iter *= 5;
			printf("i: %d\n", (FRACTION_ITER >> i) & fraction_b);
			printf("total: %ld\n", total);
		}
		i++;
	}
	return (0);
}
