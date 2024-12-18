/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynwidth_replacer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:37:41 by obastug           #+#    #+#             */
/*   Updated: 2024/12/17 16:37:42 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	replace_dynwidth(t_format *flags, va_list *args)
{
	if (!flags->dyn_width)
		return (0);
	flags->width = va_arg(*args, int);
	return (1);
}
