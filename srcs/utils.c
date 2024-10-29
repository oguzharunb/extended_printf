#include "../includes/og_printf.h"
#include "../libft/libft.h"

#include <stdio.h> // temporary

int	og_isin(char const *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	print_flags(t_format*flags) // temporary
{
	printf("flag_min: %d\n", flags->flag_min);
	printf("flag_plus: %d\n", flags->flag_plus);
	printf("flag_space: %d\n", flags->flag_space);
	printf("flag_zero: %d\n", flags->flag_zero);
	printf("flag_hash: %d\n", flags->flag_hash);
	printf("lm_short: %d\n", flags->lm_short);
	printf("lm_long: %d\n", flags->lm_long);
	printf("dyn_width: %d\n", flags->dyn_width);
	printf("width: %d\n", flags->width);
	printf("precision: %d\n", flags->precision);
	printf("size: %d\n", flags->size);
	printf("conversion: %c\n", flags->conversion);
}

void	reset_flags(t_format *flags)
{
	ft_bzero(flags, sizeof(t_format));
	flags->precision = -1;
	flags->base = 10;
}

// '-' included
size_t	og_number_len_base(long number, size_t base)
{
	size_t	len;

	if (!number)
		return (1);
	len = 0;
	if (number < 0)
	{
		len++;
		number = -number;
	}
	while(number)
	{
		len++;
		number /= base;      
	}
	return (len);
}

size_t	og_unumber_len_base(unsigned long number, size_t base)
{
	size_t	len;

	if (!number)
		return (1);
	len = 0;
	while(number)
	{
		len++;
		number /= base;      
	}
	return (len);
}

long	cast_number(t_format *flags, long nbr)
{
	if (flags->lm_long == 0)
		nbr = (int)nbr;
	if (flags->lm_short == 1)
		nbr = (short)nbr;
	else if (flags->lm_short == 2)
		nbr = (char)nbr;
	return (nbr);
}

unsigned long	cast_unumber(t_format *flags, unsigned long nbr)
{
	if (flags->lm_long == 0)
		nbr = (unsigned int)nbr;
	if (flags->lm_short == 1)
		nbr = (unsigned short)nbr;
	else if (flags->lm_short == 2)
		nbr = (unsigned char)nbr;
	return (nbr);
}

void	set_base(t_format *flags)
{
	if (flags->conversion == 'x' || flags->conversion == 'X')
		flags->base = 16;
	else if (flags->conversion == 'o')
		flags->base = 8;
	else if (flags->conversion == 'b')
		flags->base = 2;
}

