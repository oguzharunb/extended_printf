#include "../includes/og_printf.h"
#include <stdint.h>

// '-' included
size_t	og_number_len_base(int number, size_t base)
{
	size_t	len;
	
	len = 0;
	if (number < 0)
	{
		len++;
		number = -number;
	}
	while(number)
	{
		len++;
		number /= base;
	}
	return (len);
}

size_t og_length_s(t_flags *flags, char const *str)
{
	int	len;

	len = og_strlen(str);
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

	len = 2 + og_number_len_base((unsigned long)ptr, 16);
	if ((size_t)flags->width > len)
		return (flags->width);
	return (len);
}

size_t	og_length_d(t_flags *flags, int	nbr)
{
	int	len;

	len = og_number_len_base(nbr, 10);
	if (len > flags->width && len > flags->precision)
		return (len);
	if (flags->width > flags->precision)
		return (flags->width);
	return (flags->precision);
}

size_t	og_length_o(t_flags *flags, int nbr)
{
	int	len;

	len = og_number_len_base(nbr, 8);
	if (flags->flag_hash > 0)
		len++;
	if (len > flags->width && len > flags->precision)
		return (len);
	if (flags->width > flags->precision)
		return (flags->width);
	return (flags->precision);
}

//printf("%d\n", ((number_i & 2139095040) >> 23) - 127); // 2139095040 = 0'1111111'00000000000000000000000 // that is exponent
size_t	og_length_f(t_flags *flags, float number) //what if dyn_width is there
{
	unsigned int			number_i = (unsigned int)*(unsigned int *)&number;
	register unsigned int	precision_wiss;
	int						precision_len;
	int						minus_one;
	size_t					len;

	minus_one = -1;
	precision_wiss = 0;
	while (number_i == (number_i & (minus_one << precision_wiss)))
		precision_wiss++;
	precision_len = 24 - precision_wiss - (int)(((number_i & 2139095040) >> 23) - 127); // (int)(((number_i & 2139095040) >> 23) - 127) is exponent
	if (flags->precision > precision_len)
		precision_len = flags->precision;
	len = precision_len + 1 + (og_number_len_base((int)number, 10)); // minus included
	return (len);
}