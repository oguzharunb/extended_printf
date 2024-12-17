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

void	l_mod(char const *tr, size_t *i, t_format *flags, size_t size)
{
	if (*(tr + *i) == LM_SHORT && *i < size)
	{
		flags->lm_short += 1;
		if (*(tr + (*i + 1)) == LM_SHORT)
		{
			flags->lm_short += 1;
			(*i)++;
		}
		(*i)++;
	}
	else if (*(tr + *i) == LM_LONG && *i < size)
	{
		flags->lm_long = flags->lm_long + 1;
		if (*(tr + (*i + 1)) == LM_LONG)
		{
			flags->lm_long += 1;
			(*i)++;
		}
		(*i)++;
	}
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

size_t		og_unumber_len_base(unsigned long number, size_t base)
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
