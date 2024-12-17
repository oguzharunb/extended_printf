/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:39:12 by obastug           #+#    #+#             */
/*   Updated: 2024/12/17 17:26:10 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../includes/og_printf.h"
#include "../libft/libft.h"
#include <unistd.h>

typedef struct s_StringState
{
	int	si;	
	int	di;
}	t_StringState;

static int	write_format_to_dest(t_format *flags, va_list *args, char *dest)
{
	if (ft_isin(flags->conversion, "xXou"))
		write_usigned_number(va_arg(*args, unsigned long), dest, flags);
	else if (ft_isin(flags->conversion, "id"))
		write_signed_number(va_arg(*args, long), dest, flags);
	else if (flags->conversion == 'c')
		write_char(va_arg(*args, int), dest, flags);
	else if (flags->conversion == 's')
		write_string(va_arg(*args, char *), dest, flags);
	else if (flags->conversion == 'p')
		write_pointer(va_arg(*args, void *), dest, flags);
	return (0);
}

void	liter(const char *s, t_StringState *state, char *dest)
{
	while (s[state->si] && s[state->si] != '%')
	{
		dest[state->di] = s[state->si];
		state->si++;
		state->di++;
	}
}

void	pc_place(const char *s, va_list *args, t_StringState *state, char *dest)
{
	int			j;
	t_format	flags;

	j = 1;
	while (!ft_isin(s[state->si + j], CONVERSIONS) && s[state->si + j])
		j++;
	og_fill_flag_bag(s + state->si, ++j, &flags);
	replace_dynwidth(&flags, args);
	if (!flag_check(&flags, j))
	{
		dest[state->di] = s[state->si];
		state->di++;
		state->si++;
		return ;
	}
	write_format_to_dest(&flags, args, dest + state->di);
	while (dest[state->di])
		state->di++;
	state->si += j;
}

void	fill_string(const char *string, va_list *args, char *dest)
{
	t_StringState	state;

	ft_bzero(&state, sizeof(t_StringState));
	while (string[state.si])
	{
		if (string[state.si] != '%')
			liter(string, &state, dest);
		else
			pc_place(string, args, &state, dest);
	}
}
