/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:50:45 by obastug           #+#    #+#             */
/*   Updated: 2024/12/18 13:57:37 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s && write(1, "(null)", 6))
		return (6);
	while (s[count])
		count++;
	return (write(1, s, count));
}
