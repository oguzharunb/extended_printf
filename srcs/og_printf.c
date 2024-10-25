#include "../includes/og_printf.h"
#include <stdarg.h>

int	og_printf(const char *string, ...)
{
	va_list	args;
	size_t	len;

	va_start(args, string);
	len = lengthf(string, &args);
	return (int)len;
}