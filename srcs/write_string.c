#include "../includes/og_printf.h"
#include "../libft/libft.h"

// 'minus', 'width', 'precision'

// "hello    ", "     hello", "   hel", "hel    "
void	write_string(char *string, char *dest, t_format *flags)
{
	unsigned long	i;
	unsigned long	start;
	unsigned long	string_len;

	i = 0;
	ft_memset(dest, ' ', flags->width);
	if (flags->precision >= 0)
		string_len = flags->precision;
	else
		string_len = ft_strlen(string);
	start = 0;
	if (!flags->flag_min)
		start = flags->width - string_len;
	while (i < string_len)
	{
		dest[i + start] = string[i];
		i++;
	}
}