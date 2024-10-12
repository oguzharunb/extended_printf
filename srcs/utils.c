#include "../includes/og_printf.h"
#include <stdio.h> // temporary

int	og_isin(char const *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	print_flags(t_flags *flags) // temporary
{
	printf("flag_min: %d\n", flags->flag_min);
	printf("flag_plus: %d\n", flags->flag_plus);
	printf("flag_space: %d\n", flags->flag_space);
	printf("flag_zero: %d\n", flags->flag_zero);
	printf("flag_hash: %d\n", flags->flag_hash);
	printf("lm_short: %d\n", flags->lm_short);
	printf("lm_long: %d\n", flags->lm_long);
	printf("dyn_width: %d\n", flags->dyn_width);
	printf("width: %d\n", flags->width);
	printf("precision: %d\n", flags->precision);
	printf("size: %d\n", flags->size);
}

void	og_reset_flags(t_flags *flags)
{
	og_bzero(flags, sizeof(t_flags));
	flags->precision = -1;
}

size_t	og_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
