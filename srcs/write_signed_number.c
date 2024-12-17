#include "../includes/og_printf.h"

typedef struct	s_arguments
{
	long	number;
	int		i;
	long	tmp;
}	t_arguments;

static void	write_signed_number2(long number, char *dest, t_format *flags, int i, long tmp)
{
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
	else if (flags->flag_space)
	{
		if (flags->flag_zero)
			*dest = ' ';
		else
			dest[i - 1] = ' ';
	}
	else if (flags->flag_plus)
	{
		if (flags->flag_zero)
			*dest = '+';
		else
			dest[i - 1] = '+';
	}
}

void	write_signed_number(long number, char *dest, t_format *flags)
{
	int 	i;
	int		filler;
	long 	tmp;

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
	write_signed_number2(number, dest, flags, i, tmp);
}
