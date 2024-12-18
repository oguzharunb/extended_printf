/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_signed_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:53:27 by obastug           #+#    #+#             */
/*   Updated: 2024/12/18 12:54:12 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

typedef struct s_arguments
{
	long	number;
	int		i;
	long	tmp;
}	t_arguments;

static int	omg(char *dest)
{
	*dest = '0';
	return (1);
}

static void	w2(t_arguments *arg, char *dest, t_format *flags)
{
	char	c;

	if (!arg->tmp && omg(dest))
		return ;
	if (flags->flag_space)
		c = ' ';
	else
		c = '+';
	while (arg->number)
	{
		dest[--arg->i] = (arg->number % 10) + '0';
		arg->number /= 10;
	}
	if (arg->tmp < 0)
	{
		if (flags->flag_zero)
			*dest = '-';
		else
			dest[arg->i - 1] = '-';
	}
	else if (flags->flag_space || flags->flag_plus)
	{
		if (flags->flag_zero)
			*dest = c;
		else
			dest[arg->i - 1] = c;
	}
}

#include <stdio.h>
void	write_signed_number(long number, char *dest, t_format *flags)
{
	int			i;
	int			filler;
	long		tmp;
	t_arguments	arg;

	number = cast_number(flags, number);
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
		i = (int)og_number_len_base(tmp, 10);
	arg.number = number;
	arg.i = i;
	arg.tmp = tmp;
	w2(&arg, dest, flags);
}
