/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:30:45 by obastug           #+#    #+#             */
/*   Updated: 2024/12/17 17:31:01 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	write_pointer(void *ptr, char *dest, t_format *flags)
{
	unsigned long	number;

	if (!ptr)
	{
		ft_strlcpy(dest, "(nil)", 10);
		return ;
	}
	number = (unsigned long)ptr;
	flags->conversion = 'x';
	flags->flag_hash = 1;
	set_base(flags);
	if (flags->base == 8)
		flags->hash_len = 1;
	else if (flags->base == 16)
		flags->hash_len = 2;
	write_usigned_number(number, dest, flags);
}
