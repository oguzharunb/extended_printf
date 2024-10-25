#include "../../includes/og_printf.h"
#include "../../libft/libft.h"
#include "../tester.h"

#include <stdio.h>
void	test_flag_check()
{
	char		 string[100];
	t_format	flags;

	ft_strlcpy(string, "test", sizeof(string));
	og_fill_flag_bag(string, ft_strlen(string), &flags);
	test_function(flag_check(&flags, ft_strlen(string)) == 0, "Test 1: just text");

	ft_strlcpy(string, "%hi", sizeof(string));
	og_fill_flag_bag(string, ft_strlen(string), &flags);
	test_function(flag_check(&flags, ft_strlen(string)) == 3, "Test 2: short int");

	ft_strlcpy(string, "%li", sizeof(string));
	og_fill_flag_bag(string, ft_strlen(string), &flags);
	test_function(flag_check(&flags, ft_strlen(string)) == 3, "Test 3: long int");

	ft_strlcpy(string, "%lwfsdasi", sizeof(string));
	og_fill_flag_bag(string, ft_strlen(string), &flags);
	test_function(flag_check(&flags, ft_strlen(string)) == 0, "Test 4: text with % start");
}
