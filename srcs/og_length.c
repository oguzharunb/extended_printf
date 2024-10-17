#include "../includes/og_printf.h"

// '-' included
size_t	og_number_len_base(long number, size_t base)
{
	size_t	len;

	if (!number)
		return (1);
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

size_t	og_unumber_len_base(unsigned long number, size_t base)
{
	size_t	len;

	if (!number)
		return (1);
	len = 0;
	while(number)
	{
		len++;
		number /= base;      
	}
	return (len);
}

long	cast_number(t_format *flags, long nbr)
{
	if (flags->lm_long == 0)
		nbr = (int)nbr;
	if (flags->lm_short == 1)
		nbr = (short)nbr;
	else if (flags->lm_short == 2)
		nbr = (char)nbr;
	return (nbr);
}

unsigned long	cast_unumber(t_format *flags, unsigned long nbr)
{
	if (flags->lm_long == 0)
		nbr = (unsigned int)nbr;
	if (flags->lm_short == 1)
		nbr = (unsigned short)nbr;
	else if (flags->lm_short == 2)
		nbr = (unsigned char)nbr;
	return (nbr);
}

void	set_base(t_format *flags)
{
	if (flags->conversion == 'x')
		flags->base = 16;
	else if (flags->conversion == 'o')
		flags->base = 8;
	else if (flags->conversion == 'b')
		flags->base = 2;
}

size_t	og_length_s(t_format*flags, char const *str)
{
	int	len;

	len = og_strlen(str);
	if (flags->precision < len && flags->precision != -1)
		len = flags->precision;
	if (flags->width > len)
		return (flags->width);
	return ((size_t)len);
}

size_t	og_length_c(t_format*flags)
{
	if (flags->width)
		return (flags->width);
	return (1);
}

size_t	og_length_p(t_format*flags, void *ptr)
{
	size_t		len;

	len = 2 + og_number_len_base((unsigned long)ptr, 16);
	if ((size_t)flags->width > len)
		return (flags->width);
	return (len);
}

size_t	og_length_i(t_format*flags, long nbr)
{
	int		len;

	nbr = cast_number(flags, nbr);
	len = og_number_len_base(nbr, flags->base);
	if (len > flags->width && len > flags->precision)
		return (len);
	if (flags->width > flags->precision)
		return (flags->width);
	return (flags->precision);
}

size_t	og_length_u(t_format *flags, unsigned long nbr)
{
	int	len;

	len = 0;
	set_base(flags);
	nbr = cast_unumber(flags, nbr);
	len = og_unumber_len_base(nbr, flags->base);
	if (len > flags->width && len > flags->precision)
		return (len);
	if (flags->width > flags->precision)
		return (flags->width);
	return (flags->precision);
}

size_t	og_length_o(t_format*flags, int nbr)
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
size_t	og_length_f(t_format*flags, float number) //what if dyn_width is there
{
	unsigned int			number_i;
	register unsigned int	precision_wiss;
	int						precision_len;
	int						minus_one;
	size_t					len;

	number_i = (unsigned int)*(unsigned int *)&number;
	minus_one = -1;
	precision_wiss = 0;
	while (number_i == (number_i & (minus_one << precision_wiss)))
		precision_wiss++;
	precision_len = 24 - precision_wiss - (int)(((number_i & FLOAT_EXPONENT_MASK) >> 23) - 127); // (int)(((number_i & 2139095040) >> 23) - 127) is exponent
	if (flags->precision < precision_len && flags->precision != -1)
		precision_len = flags->precision;
	len = precision_len + 1 + (og_number_len_base((int)number, 10)); // minus included
	if (flags->width > (int)len)
		return (flags->width);
	return (len);
}

size_t	og_length_e(t_format*flags, double number)
{
	size_t	len;
	
	len = og_length_f(flags, number);	
	len += 4;
	return (len);
}

size_t	og_length_a(t_format*flags, double number)
{
	unsigned long	number_i = (unsigned long)*(unsigned long *)&number;
	unsigned long	exponent;
	unsigned long	minus_one;
	unsigned long	wiss;
	size_t			len;

	minus_one = -1;
	exponent = (((DOUBLE_EXPONENT_MASK & number_i) >> 52));
	if (exponent)
		exponent -= 1023;
	wiss = 0;
	while ((DOUBLE_PRECISION_MASK & number_i) == ((DOUBLE_PRECISION_MASK & number_i) & (minus_one << (wiss + 4))) && wiss < 52)
		wiss += 4;
	wiss = (52 - wiss) / 4;
	if ((int)wiss < flags->precision)
		wiss = flags->precision;
	len = wiss + og_number_len_base(exponent, 10) + 5;
	if (wiss)
		len++;
	return (len);
}
