#include "../includes/og_printf.h"

// it expects a string with the flags to replace
// the flag have to be in the order of FLAGS
void	og_fill_flag_bag(char const *to_replace, size_t size, t_format*flags)
{
	size_t	i;

	i = 0;
	reset_flags(flags);
	if (*(to_replace + i) == '%')
		i++;
	while (og_isin(FLAGS, *(to_replace + i)) && i < size)
	{
		if (*(to_replace + i) == FLAG_HASH)
			flags->flag_hash += 1;
		else if (*(to_replace + i) == FLAG_MINUS)
			flags->flag_min += 1;
		else if (*(to_replace + i) == FLAG_PLUS)
			flags->flag_plus += 1;
		else if (*(to_replace + i) == FLAG_SPACE)
			flags->flag_space += 1;
		else if (*(to_replace + i) == FLAG_ZERO)
			flags->flag_zero += 1;
		i++;
	}
	if ((*(to_replace + i) == DYN_WIDTH) && i < size)
	{
		flags->dyn_width += 1;
		i++;
	}
	else
	{
		while (og_isin(NUMBERS, *(to_replace + i)) && i < size)
		{
			flags->width = (flags->width * 10) + *(to_replace + i) - '0';
			i++;
		}
	}
	if (*(to_replace + i) == PRECISION_START && i < size)
	{
		i++;
		flags->precision = 0;
		while (og_isin(NUMBERS, *(to_replace + i)) && i < size)
		{
			flags->precision = flags->precision * 10 + *(to_replace + i) - '0';
			i++;
		}
	}
	if (*(to_replace + i) == LM_SHORT && i < size)
	{
		flags->lm_short += 1;
		if (*(to_replace + (i + 1)) == LM_SHORT)
		{
			flags->lm_short += 1;
			i++;
		}
		i++;
	}
	else if (*(to_replace + i) == LM_LONG && i < size)
	{
		flags->lm_long = flags->lm_long + 1;
		if (*(to_replace + (i + 1)) == LM_LONG)
		{
			flags->lm_long += 1;
			i++;
		}
		i++;
	}
	if (og_isin(CONVERSIONS, *(to_replace + i)))
	{
		flags->conversion = *(to_replace + i);
		i++;
	}
}
