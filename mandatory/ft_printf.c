/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:50:26 by obastug           #+#    #+#             */
/*   Updated: 2024/12/18 13:50:26 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	specifier_check(const char *format, va_list args)
{
	int	count;

	count = -1;
	if (*format == '%')
		count = ft_putchar(*format);
	else if (*format == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (*format == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		count = ft_putunbr(va_arg(args, unsigned int));
	else if (*format == 'x' || *format == 'X')
		count = ft_puthexnbr(va_arg(args, unsigned int), *format);
	else if (*format == 'p')
		count = ft_putaddr(va_arg(args, void *));
	else if (*format)
	{
		count = ft_putchar(*(format - 1));
		count += ft_putchar(*format);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		tmp;

	va_start(args, format);
	count = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			tmp = specifier_check(format, args);
			if (tmp == -1)
				return (-1);
			count += tmp;
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
