#include "../includes/og_printf.h"
#include <stdarg.h>
#include "../libft/libft.h"

//gives the actual length of the string
size_t	lengthf(char const *string, va_list *args)
{
	size_t		len;
	size_t		i;
	size_t		j;
	t_format	flags;

	len = 0;
	i = 0;
	while (string[i])
	{
		j = 0;
		if ('%' == string[i + j])
		{
			i++;
			while (!og_isin(CONVERSIONS, string[i + j]))
				j++;
			og_fill_flag_bag(string + i, j, &flags);
			if (!flag_check(&flags, j))
				continue;
			len += decoder(&flags, args) - 1; // '%' excluded
		}
		else
		{
			len++;
			j++;
		}
		i += j;
	}
	return (len);
}

size_t	decoder(t_format *flags, va_list *args)
{
	if ('a' == flags->conversion)
		return (og_length_a(flags, va_arg(*args, double)));
	else if ('b' == flags->conversion)
		return (og_length_b(flags));
	else if ('c' == flags->conversion)
		return (og_length_b(flags));
	else if (og_isin("di", flags->conversion))
		return (og_length_i(flags, va_arg(*args, long)));
	else if ('e' == flags->conversion)
		return (og_length_e(flags, va_arg(*args, double)));
	else if ('f' == flags->conversion)
		return (og_length_f(flags, va_arg(*args, double)));
	else if (og_isin("uox", flags->conversion))
		return (og_length_u(flags, va_arg(*args, unsigned long)));
	else if ('s' == flags->conversion)
		return (og_length_s(flags, va_arg(*args, const char *)));
	else if ('p' == flags->conversion)
		return (og_length_p(flags, va_arg(*args, void *)));
	return (0);
}

