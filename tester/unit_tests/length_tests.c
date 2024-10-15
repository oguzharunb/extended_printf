#include "../../includes/og_printf.h"
#include "../../libft/libft.h"
#include "../tester.h"

void	test_length_c()
{
	char	flag_str[100];
	t_flags	flags;
	//size_t	ret_size_t;
	og_reset_flags(&flags);
	ft_strlcpy(flag_str, "4", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_c(&flags) == 4, "Test 1: just width");

	
}