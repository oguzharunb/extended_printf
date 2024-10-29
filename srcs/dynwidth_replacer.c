#include "../includes/og_printf.h"

int	replace_dynwidth(t_format *flags, va_list *args)
{
	if (!flags->dyn_width)
		return (0);
	flags->dyn_width = va_arg(*args, int);
	return (1);
}
