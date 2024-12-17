/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   og_fill_flag_bag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:02:19 by obastug           #+#    #+#             */
/*   Updated: 2024/12/17 17:13:35 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/og_printf.h"

void	parse_width(char const *tr, size_t *i, size_t size, t_format *flags)
{
	if (*(tr + *i) == DYN_WIDTH && *i < size)
	{
		flags->dyn_width += 1;
		(*i)++;
	}
	else
	{
		while (og_isin(NUMBERS, *(tr + *i)) && *i < size)
		{
			flags->width = (flags->width * 10) + *(tr + *i) - '0';
			(*i)++;
		}
	}
}

void	prec(char const *tor, size_t *i, size_t size, t_format *flags)
{
	if (*(tor + *i) == PRECISION_START && *i < size)
	{
		(*i)++;
		flags->precision = 0;
		while (og_isin(NUMBERS, *(tor + *i)) && *i < size)
		{
			flags->precision = flags->precision * 10 + *(tor + *i) - '0';
			(*i)++;
		}
	}
}

void	parse_conversion(char const *to_replace, size_t *i, t_format *flags)
{
	if (og_isin(CONVERSIONS, *(to_replace + *i)))
	{
		flags->conversion = *(to_replace + *i);
		(*i)++;
	}
}

void	og_fill_flag_bag(char const *to_replace, size_t size, t_format *flags)
{
	size_t	i;

	i = 0;
	reset_flags(flags);
	if (*(to_replace + i) == '%')
		i++;
	parse_flags(to_replace, &i, flags, size);
	parse_width(to_replace, &i, size, flags);
	prec(to_replace, &i, size, flags);
	l_mod(to_replace, &i, flags, size);
	parse_conversion(to_replace, &i, flags);
	set_base(flags);
	if (flags->base == 8)
		flags->hash_len = 1;
	else if (flags->base == 16)
		flags->hash_len = 2;
}
