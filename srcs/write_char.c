/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:30:15 by obastug           #+#    #+#             */
/*   Updated: 2024/12/17 17:30:22 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	write_char(char c, char *dest, t_format *flags)
{
	ft_memset(dest, ' ', flags->width);
	if (flags->flag_min)
		dest[0] = c;
	else
	{
		if (flags->width)
			dest[flags->width - 1] = c;
		else
			dest[0] = c;
	}
}
