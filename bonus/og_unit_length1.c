/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   og_unit_length1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:17:49 by obastug           #+#    #+#             */
/*   Updated: 2024/12/18 13:40:48 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

size_t	og_length_s(t_format*flags, char const *str)
{
	int	len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	if (flags->precision < len && flags->precision != -1)
		len = flags->precision;
	if (flags->width > len)
		return (flags->width);
	return ((size_t)len);
}

size_t	og_length_c(t_format*flags)
{
	if (flags->width)
		return (flags->width);
	return (1);
}

size_t	og_length_p(t_format*flags, void *ptr)
{
	size_t		len;

	len = 2 + og_number_len_base((unsigned long)ptr, 16);
	if ((size_t)flags->width > len)
		return (flags->width);
	return (len);
}

size_t	og_length_i(t_format*flags, long nbr)
{
	int		len;

	nbr = cast_number(flags, nbr);
	len = og_number_len_base(nbr, flags->base);
	if (flags->flag_plus && nbr > 0)
		len++;
	if (len > flags->width && len > flags->precision)
		return (len);
	if (flags->width > flags->precision)
		return (flags->width);
	return (flags->precision);
}
