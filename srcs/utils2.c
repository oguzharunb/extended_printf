/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:12:40 by obastug           #+#    #+#             */
/*   Updated: 2024/12/17 17:27:01 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/og_printf.h"

void	parse_flags(char const *tr, size_t *i, t_format *flags, size_t size)
{
	while (og_isin(FLAGS, *(tr + *i)) && *i < size)
	{
		if (*(tr + *i) == FLAG_HASH)
			flags->flag_hash += 1;
		else if (*(tr + *i) == FLAG_MINUS)
			flags->flag_min += 1;
		else if (*(tr + *i) == FLAG_PLUS)
			flags->flag_plus += 1;
		else if (*(tr + *i) == FLAG_SPACE)
			flags->flag_space += 1;
		else if (*(tr + *i) == FLAG_ZERO)
			flags->flag_zero += 1;
		(*i)++;
	}
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

long	power(long number, unsigned long pw)
{
	if (pw == 0)
		return (1);
	return (number * power(number, pw - 1));
}

long	ft_abs(long number)
{
	if (number < 0)
		return (-number);
	return (number);
}