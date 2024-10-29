#include <stdarg.h>
#include "og_printf.h"

static int	write_format_to_dest(t_format *flags, va_list *args, char *dest)
{
	(void)flags;
	(void)args;
	(void)dest;
	return (0);
}


int	fill_string(char *string, va_list *args, char *dest)
{
	int			si;
	int			di;
	int			j;
	t_format	flags;

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
		j = 1;
		while (ft_isin(string[si + j], CONVERSIONS) && string[si + j])
			j++;
		og_fill_flag_bag(string + si, ++j, &flags);
		replace_dynwidth(&flags, args);
		if (!flags_check(&flags, args))
		{
			dest[di] = string[si];
			di++;
			si++;
			continue ;
		}
		write_format_to_dest(&flags, args, dest + di);
		while (dest[di])
			di++;
	}
}