#include "../includes/og_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int	og_printf(const char *string, ...)
{
	va_list	args;
	size_t	len;
	char	*final_string;

	va_start(args, string);
	len = lengthf(string, &args);
	final_string = malloc(len + 1);
	if (!final_string)
		return (0);
	va_start(args, string);
	//fill_string(string, args, final_string);
	return (int)len;
}