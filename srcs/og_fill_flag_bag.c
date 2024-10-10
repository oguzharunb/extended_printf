#include "../includes/og_printf.h"

void og_fill_flag_bag(char const *to_replace, size_t size, t_flags *flags)
{
	size_t	i;

	i = 0;
	while (og_isin(FLAGS, *(to_replace + i)) && i < size)
	{
		if (*(to_replace) == FLAG_HASH)
			flags->flag_hash = 1;
		if (*(to_replace) == FLAG_MINUS)
			flags->flag_min = 1;
		if (*to_replace == FLAG_PLUS)
			flags->flag_plus = 1;
		if (*to_replace == FLAG_SPACE)
			flags->flag_space = 1;
		if (*to_replace == FLAG_ZERO)
			flags->flag_zero = 1;
		i++;
	}

	if ((*(to_replace + i) == DYN_WIDTH))
	{
		flags->dyn_width = 1;
		i++;
	}
	else
	{
		while (og_isin(NUMBERS, *(to_replace + i)) && i < size) // width
		{
			flags->width = (flags->width * 10) + *(to_replace + i) - '0';
			i++;
		}
	}

	if (*(to_replace + i) == PRECISION_START)
	{
		i++;
		while (og_isin(NUMBERS, *(to_replace + i)) && i < size) // if dot is found
		{
			flags->precision = flags->precision * 10 + *(to_replace + i) - '0';
			i++;
		}
	}

	while (og_isin(*(to_replace + i)) && i < size)
	{
		if (*(to_replace + i) == LM_SHORT)
			flags->lm_short = flags->lm_short + 1;
		else if (*(to_replace + i) == LM_LONG)
			flags->lm_long = flags->lm_long + 1;
		i++;
	}
	if (og_isin(CONVERSIONS, *(to_replace + i)) && i < size)
		return (1);
}