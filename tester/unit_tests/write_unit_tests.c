#include "../../includes/og_printf.h"
#include "../../libft/libft.h"
#include "../tester.h"

#include <stdlib.h>
#include <stdio.h>
void	write_unit_tests(void)
{
	t_format	flags;
	char *str = calloc(50, 1);

	og_fill_flag_bag("%i", 2, &flags);
	write_signed_number(123, str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(str, "123", ft_strlen(str)), "Test 1: int number");

	og_fill_flag_bag("%5i", 3, &flags);
	write_signed_number(123, str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(str, "  123", ft_strlen(str)), "Test 2: int number with width");

	og_fill_flag_bag("%-5i", 3, &flags);
	write_signed_number(123, str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(str, "123  ", ft_strlen(str)), "Test 3: int number with width and - flag");

	og_fill_flag_bag("%05i", 3, &flags);
	write_signed_number(123, str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(str, "00123", ft_strlen(str)), "Test 4: int number with width and 0 flag");

	og_fill_flag_bag("%05i", 4, &flags);
	write_signed_number(123456, str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(str, "123456", ft_strlen(str)), "Test 5: len > width and 0 flag");

	og_fill_flag_bag("%+05i", 5, &flags);
	write_signed_number(123, str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(str, "+0123", ft_strlen(str)), "Test 6: int number with width and 0 flag and plus addition");
}