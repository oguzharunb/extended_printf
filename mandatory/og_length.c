/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   og_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:14:08 by obastug           #+#    #+#             */
/*   Updated: 2024/12/17 17:23:31 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include "../libft/libft.h"

//gives the actual length of the string
//gives the actual length of the string
static size_t	decoder(t_format *flags, va_list *args)
{
	if ('c' == flags->conversion)
		return (og_length_c(flags));
	else if (og_isin("di", flags->conversion))
		return (og_length_i(flags, va_arg(*args, long)));
	else if (og_isin("uoxX", flags->conversion))
		return (og_length_u(flags, va_arg(*args, unsigned long)));
	else if ('s' == flags->conversion)
		return (og_length_s(flags, va_arg(*args, const char *)));
	else if ('p' == flags->conversion)
		return (og_length_p(flags, va_arg(*args, void *)));
	else if ('%' == flags->conversion)
		return (1);
	return (0);
}

void	literal_string(const char *s, size_t *i, size_t *len)
{
	while (s[*i] && s[*i] != '%')
	{
		(*len)++;
		(*i)++;
	}
}

void	placeholder(const char *string, size_t *i, size_t *len, va_list *args)
{
	size_t		j;
	t_format	flags;

	j = 1;
	while (!ft_isin(string[*i + j], CONVERSIONS) && string[*i + j])
		j++;
	og_fill_flag_bag(string + *i, ++j, &flags);
	replace_dynwidth(&flags, args);
	if (!flag_check(&flags, j))
	{
		(*i)++;
		(*len)++;
		return ;
	}
	(*len) += decoder(&flags, args);
	*i += j;
}

size_t	lengthf(const char *string, va_list *args)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (string[i])
	{
		if (string[i] != '%')
			literal_string(string, &i, &len);
		else
			placeholder(string, &i, &len, args);
	}
	return (len);
}
