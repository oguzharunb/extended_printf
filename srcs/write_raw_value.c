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

#include <stdio.h>

void	write_float_number(float number, char *dest, t_format *flags)
{
	(void)number;
	(void)dest;
	(void)flags;
}