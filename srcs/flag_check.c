#include "../includes/og_printf.h"

#include <stdio.h> // temporary
int	flag_check(t_format *flags, size_t expected_size)
{
	size_t	size;

	size = 0;
	size += !!flags->conversion + flags->flag_hash + flags->flag_min
			+ flags->flag_plus + flags->flag_space + flags->flag_zero
			+ flags->lm_long + flags->lm_short
			+  og_unumber_len_base(flags->width, 10) + 1;
	printf("size: %li, expected size: %li\n", size, expected_size);
	if (size == expected_size)
		return (size);
	return (0);
}