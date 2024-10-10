#include "../includes/og_printf.h"

size_t og_length_s(t_flags *flags, char const *str)
{
	size_t	len;

	len = og_strlen(str);
	if (flags->precision < len && flags->precision != -1)
		len = flags->precision;
	return (len);
}