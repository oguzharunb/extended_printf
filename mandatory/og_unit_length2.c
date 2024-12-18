/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   og_unit_length2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:24:57 by obastug           #+#    #+#             */
/*   Updated: 2024/12/17 17:25:04 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

size_t	og_length_u(t_format *flags, unsigned long nbr)
{
	int	len;

	len = 0;
	set_base(flags);
	nbr = cast_unumber(flags, nbr);
	len = og_unumber_len_base(nbr, flags->base);
	if (flags->flag_plus && nbr > 0)
		len++;
	if (len > flags->width && len > flags->precision)
		return (len);
	if (flags->width > flags->precision)
		return (flags->width);
	return (flags->precision);
}

size_t	og_length_o(t_format*flags, int nbr)
{
	int	len;

	len = og_number_len_base(nbr, 8);
	if (flags->flag_hash > 0)
		len++;
	if (len > flags->width && len > flags->precision)
		return (len);
	if (flags->width > flags->precision)
		return (flags->width);
	return (flags->precision);
}

size_t	og_length_b(t_format *flags)
{
	if (flags->width < 2)
		return (8);
	else
		return (((flags->width - 1) * 9) + 8);
}
