#include <stdarg.h>
#include "../includes/og_printf.h"
#include "../libft/libft.h"

#include <unistd.h>
static int	write_format_to_dest(t_format *flags, va_list *args, char *dest)
{
	if (ft_isin(flags->conversion, "xXou"))
		write_usigned_number(va_arg(*args, unsigned long), dest, flags);
	else if (ft_isin(flags->conversion, "id"))
		write_signed_number(va_arg(*args, long), dest, flags);
	else if (flags->conversion == 'c')
		write_char(va_arg(*args, int), dest, flags);
	else if (flags->conversion == 's')
		write_string(va_arg(*args, char *), dest, flags);
	else if (flags->conversion == 'p')
		write_pointer(va_arg(*args, void *), dest, flags);
	else if (flags->conversion == 'f')
		write_float_number(va_arg(*args, double), dest);
	return (0);
}

void	fill_string(const char *string, va_list *args, char *dest)
{
	int			si;
	int			di;
	int			j;
	t_format	flags;

	(void)args;
	si = 0;
	di = 0;
	while(string[si])
	{
		if (string[si] != '%')
		{
			dest[di] = string[si];
			si++;
			di++;
			continue ;
		}
		else
		{
			j = 1;
			while (!ft_isin(string[si + j], CONVERSIONS) && string[si + j])
				j++;
			og_fill_flag_bag(string + si, ++j, &flags);
			replace_dynwidth(&flags, args);
			if (!flag_check(&flags, j))
			{
				dest[di] = string[si];
				di++;
				si++;
				continue ;
			}
			write_format_to_dest(&flags, args, dest + di);
			while (*(dest + di))
				di++;
			si += j;
		}
	}
}
