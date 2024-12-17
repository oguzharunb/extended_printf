#include "../includes/og_printf.h"
#include "../libft/libft.h"

void	write_pointer(void *ptr, char *dest, t_format *flags)
{
	unsigned long	number;

	if (!ptr)
	{
		ft_strlcpy(dest, "(nil)", 10);
		return ;
	}
	number = (unsigned long)ptr;
	flags->conversion = 'x';
	flags->flag_hash = 1;
	set_base(flags);
	if (flags->base == 8)
		flags->hash_len = 1;
	else if (flags->base ==  16)
		flags->hash_len = 2;
	write_usigned_number(number, dest, flags);
}
