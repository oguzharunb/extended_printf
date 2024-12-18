/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:44 by obastug           #+#    #+#             */
/*   Updated: 2024/12/18 13:28:40 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_printf(const char *string, ...)
{
	va_list	args;
	char	*final_string;
	size_t	len;

	va_start(args, string);
	len = lengthf(string, &args);
	if (!len)
		return (0);
	final_string = ft_calloc(len + 1, 1);
	if (!final_string)
		return (-1);
	va_start(args, string);
	fill_string(string, &args, final_string);
	len = ft_strlen(final_string);
	write(1, final_string, len);
	free(final_string);
	return (len);
}
