#include "../includes/og_printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	og_printf(const char *string, ...)
{
	va_list	args;
	char	*final_string;
	size_t	len;
	va_start(args, string);
	len = lengthf(string, &args);
	if (!len)
		return (0);
	final_string = ft_calloc(len + 1, 1);
	if (!final_string)
		return (0);
	va_start(args, string);
	fill_string(string, &args, final_string);
	write(1, final_string, ft_strlen(final_string));
	return ft_strlen(final_string);
}