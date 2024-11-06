#include "../includes/og_printf.h"
#include "../libft/libft.h"

// write signed number
// handle ' ' flag
// handle '+' flag
// handle '-' flag

int	write_di_format(t_format *flags, char *dest, long number)
{
	size_t	len;
	size_t	i;
	char	filler;

	len = og_number_len_base(number, flags->base);
	if (number > 0 && (flags->flag_plus || flags->flag_space))
		len++;
	i = 0;
	while (len + i < flags->width && !flags->flag_min)
		dest[i++] = filler;
	write_signed_number(number, dest, flags);
	while (len + i < flags->width && flags->flag_min)
		dest[i++] = filler;
	return (1);
}

int	write_uoxX_format(t_format *flags, char *dest, unsigned long number)
{
	size_t	len;
	
	len = og_unumber_len_base(number, flags->base);
	return (1);
}

int	write_s_format(t_format *flags, char *dest, char *src)
{
	(void)flags;
	(void)dest;
	(void)src;
	return (1);
}

int	write_p_format(t_format *flags, char *dest, void *address)
{
	(void)flags;
	(void)dest;
	(void)address;
	return (1);
}

int	write_a_format(t_format *flags, char *dest, double number)
{
	(void)flags;
	(void)dest;
	(void)number;
	return (1);
}

int	write_e_format(t_format *flags, char *dest, double number)
{
	(void)flags;
	(void)dest;
	(void)number;
	return (1);
}

int write_f_format(t_format *flags, char *dest, float number)
{
	(void)flags;
	(void)dest;
	(void)number;
	return (1);
}

