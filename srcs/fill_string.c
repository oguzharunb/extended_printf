#include <stdarg.h>
#include "../includes/og_printf.h"
#include "../libft/libft.h"

#include <unistd.h>
#include <stdio.h>
static int	write_format_to_dest(t_format *flags, va_list *args, char *dest)
{
	if (ft_isin(flags->conversion, "xXou"))
		write_usigned_number(va_arg(*args, unsigned long), dest, flags);
	else if (ft_isin(flags->conversion, "id"))
		write_signed_number(va_arg(*args, long), dest, flags);
	else if (flags->conversion == 'c')
		write_char(va_arg(*args, int), dest, flags);
	else if (flags->conversion == 's')
	{
		write_string(va_arg(*args, char *), dest, flags);
		printf("string has been wrote\n");
	}
	else if (flags->conversion == 'p')
		write_pointer(va_arg(*args, void *), dest, flags);
	else if (flags->conversion == 'f')
	{
		printf("varan 1\n");
		write_float_number(va_arg(*args, double), dest);
	}
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
			//print_flags(&flags);
			replace_dynwidth(&flags, args);
			//printf("j: %d\n", j);
			if (!flag_check(&flags, j))
			{
				write(1, "god help me\n", 13);
				dest[di] = string[si];
				di++;
				si++;
				continue ;
			}
			//printf("di: %d\n", di);
			write_format_to_dest(&flags, args, dest + di);
			//printf("dest[%d] = %p = %c\n", 0, 0 + dest, dest[0]);
			//printf("dest[%d] = %p = %c\n", 1, 1 + dest, dest[1]);
			//printf("dest[%d] = %p = %c\n", 2, 2 + dest, dest[2]);
			//printf("dest[%d] = %p = %c\n", 3, 3 + dest, dest[3]);
			//printf("dest[%d] = %p = %c\n", 4, 4 + dest, dest[4]);
			//printf("dest[%d] = %p = %c\n", 5, 5 + dest, dest[5]);
			//printf("dest[%d] = %p = %c\n", 6, 6 + dest, dest[6]);
			//printf("dest[%d] = %p = %c\n", 7, 7 + dest, dest[7]);
			//printf("dest[%d] = %p = %c\n", 8, 8 + dest, dest[8]);
			//printf("dest[%d] = %p = %c\n", 9, 9 + dest, dest[9]);
			while (*(dest + di))
				di++;
			si += j;
		}
	}
}
