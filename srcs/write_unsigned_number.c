#include "../includes/og_printf.h"

void	write_usigned_number2(unsigned long number, char *dest, t_format *flags, int i, unsigned long tmp)
{
	(void)number;
	(void)dest;
	(void)flags;
	(void)i;
	(void)tmp;
}

void	write_usigned_number(unsigned long number, char *dest, t_format *flags)
{
	int			 	i;
	int				filler;
	unsigned long 	tmp;

	tmp = number;
	i = 0;
	if (flags->flag_zero)
		filler = '0';
	else
		filler = ' ';
	while (i < flags->width)
		dest[i++] = filler;
	if (i < (int)og_unumber_len_base(tmp, flags->base))
		i = (int)og_unumber_len_base(tmp, flags->base);
	if (flags->flag_min)
		i = og_unumber_len_base(tmp, flags->base);
	write_usigned_number2(number, dest, flags, i, tmp);
}
