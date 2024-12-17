#include "../includes/og_printf.h"
#include "../libft/libft.h"

// (number, 0, 0, 0, 5)

#include <stdio.h>
void	write_float_number(float number, char *dest)
{
    unsigned long	fraction;
    unsigned long	integer;
    unsigned long	i;
	long	step;

	step = 0;
	integer = (unsigned long)number;
	fraction = float_fraction(number, 0, 0, &step);
	printf("varan 2 (fraction): %li\n", fraction);
    i = og_unumber_len_base(fraction, 10) + og_unumber_len_base(integer, 10);
    //ft_memset(dest, '0', i);
	if (!fraction)
		dest[i--] = '0';
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
	printf("varan 3 (what is written): %s\n", dest);
}

// number, 0, 0, &step = 0, 5
unsigned long	float_fraction(float number, long i, unsigned long total, long *step)
{
	long			exponent;
	long			fraction_b;
	unsigned long	iter;

	iter = 5;
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
