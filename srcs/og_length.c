#include "../includes/og_printf.h"
#include <stdint.h>

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

size_t	og_length_p(t_flags *flags, void *ptr)
{
	size_t		len;

	len = 2 + ft_number_len_base((unsigned long)ptr, 16);
	if ((size_t)flags->width > len)
		return (flags->width);
	return (len);
}

size_t	og_length_d(t_flags *flags, int	nbr)
{
	int	len;

	len = ft_number_len_base(nbr, 10);
	if (len > flags->width && len > flags->precision)
		return (len);
	if (flags->width > flags->precision)
		return (flags->width);
	return (flags->precision);
}

size_t	og_length_o(t_flags *flags, int nbr)
{
	int	len;

	len = ft_number_len_base(nbr, 8);
	if (flags->flag_hash > 0)
		len++;
	if (len > flags->width && len > flags->precision)
		return (len);
	if (flags->width > flags->precision)
		return (flags->width);
	return (flags->precision);
}