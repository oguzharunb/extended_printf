#include "../includes/og_printf.h"
#include "../libft/libft.h"

void	write_char(char c, char *dest, t_format *flags)
{
	ft_memset(dest, ' ', flags->width);
	if (flags->flag_min)
		dest[0] = c;
	else
	{
		if (flags->width)
			dest[flags->width - 1] = c;
		else
			dest[0] = c;
	}
}