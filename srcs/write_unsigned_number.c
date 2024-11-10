#include "../includes/og_printf.h"
#include "../libft/libft.h"
// -, #
// if 0 # is overlapped
// 0x123    
// # is not for u
static void	write_usigned_number2(unsigned long number, char *dest, t_format *flags, int i)
{
	char	str[17];
	
	ft_strlcpy(str, "0123456789abcdef", sizeof(str));
	if (flags->conversion == 'X')
		ft_strlcpy(str, "0123456789ABCDEF", sizeof(str));
	while (number)
	{
		dest[--i] = str[number % flags->base];
		number /= flags->base;
	}
	if (flags->flag_hash && !flags->flag_zero)
	{
		if (flags->conversion == 'o')
			dest[--i] = '0';
		else if (flags->conversion == 'X')
			ft_memcpy(dest + i - 2, "0X", 2);
		else if (flags->conversion == 'x')
			ft_memcpy(dest + i - 2, "0x", 2);
	}
}

void	write_usigned_number(unsigned long number, char *dest, t_format *flags)
{
	int			 	i;
	int				filler;
	unsigned long 	tmp;

	tmp = number;
	i = 0;
	if (flags->flag_zero)
		filler = '0';
	else
		filler = ' ';
	while (i < flags->width)
		dest[i++] = filler;
	if (flags->flag_min)
		i = 0;
	if (i < (int)og_unumber_len_base(tmp, flags->base))
		i = (int)og_unumber_len_base(tmp, flags->base);
	if ((int)og_unumber_len_base(tmp, flags->base) + flags->hash_len >= i
		&& !flags->flag_zero && flags->flag_hash && flags->conversion != 'u')
		i += flags->hash_len;
	write_usigned_number2(number, dest, flags, i);
}
