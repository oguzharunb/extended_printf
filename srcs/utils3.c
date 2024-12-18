/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:27:16 by obastug           #+#    #+#             */
/*   Updated: 2024/12/17 17:27:22 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
