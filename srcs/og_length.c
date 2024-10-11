#include "../includes/og_printf.h"

size_t og_length_s(t_flags *flags, char const *str)
{
	int	len;

	len = ft_strlen(str);
	if (flags->precision < len && flags->precision != -1)
		len = flags->precision;
	if (flags->width > len)
		return (flags->width);
	return ((size_t)len);
}

size_t	og_length_c(t_flags *flags)
{
	if (flags->width)
		return (flags->width);
	return (1);
}

//size_t	og_length_d()