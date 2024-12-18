/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:01:36 by obastug           #+#    #+#             */
/*   Updated: 2024/12/18 15:28:46 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>

int	flag_check(t_format *flags, size_t expected_size)
{
	size_t	size;

	size = 0;
	size += !!flags->conversion + flags->flag_hash + flags->flag_min
		+ flags->flag_plus + flags->flag_space + flags->flag_zero
		+ flags->lm_long + flags->lm_short + (flags->precision != -1)
		* (og_unumber_len_base(flags->precision, 10) + 1)
		+ ((!!flags->width) * og_unumber_len_base(flags->width, 10)) + 1;
	if (flags->flag_hash && flags->flag_min)
	{
		write(STDERR_FILENO, "# and - flags cannot be used together.\n", 39);
		return (0);
	}
	if (size != expected_size)
		return (0);
	return (size);
}
