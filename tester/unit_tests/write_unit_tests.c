#include "../../includes/og_printf.h"
#include "../../libft/libft.h"
#include "../tester.h"

#include <stdlib.h>
#include <stdio.h>
void	write_signed_number_tests(void)
{
	t_format	flags;
	char *str = calloc(50, 1);

	og_fill_flag_bag("%i", 2, &flags);
	write_signed_number(123, str, &flags);
	test_function(!ft_memcmp(str, "123", ft_strlen(str)), "Test 1: int number");

	og_fill_flag_bag("%5i", 3, &flags);
	write_signed_number(123, str, &flags);
	test_function(!ft_memcmp(str, "  123", ft_strlen(str)), "Test 2: int number with width");

	og_fill_flag_bag("%-5i", 3, &flags);
	write_signed_number(123, str, &flags);
	test_function(!ft_memcmp(str, "123  ", ft_strlen(str)), "Test 3: int number with width and - flag");

	og_fill_flag_bag("%05i", 3, &flags);
	write_signed_number(123, str, &flags);
	test_function(!ft_memcmp(str, "00123", ft_strlen(str)), "Test 4: int number with width and 0 flag");

	og_fill_flag_bag("%05i", 4, &flags);
	write_signed_number(123456, str, &flags);
	test_function(!ft_memcmp(str, "123456", ft_strlen(str)), "Test 5: len > width and 0 flag");

	og_fill_flag_bag("%+05i", 5, &flags);
	ft_bzero(str, 50);
	write_signed_number(123, str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(str, "+0123", ft_strlen(str)), "Test 6: int number with width and 0 flag and plus addition");

	og_fill_flag_bag("%-7i", 5, &flags);
	write_signed_number(123, str, &flags);
	test_function(!ft_memcmp(str, "123     ", ft_strlen(str)), "Test 7: int number with width and - flag");

	og_fill_flag_bag("%+07i", 5, &flags);
	write_signed_number(123, str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(str, "+000123", ft_strlen(str)), "Test 8: int number with width and '+'(plus) flag");

	og_fill_flag_bag("% 07i", 5, &flags);
	write_signed_number(123, str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(str, " 000123", ft_strlen(str)), "Test 9: int number with width and ' '(space) flag");

}

void	write_usigned_number_tests(void)
{
	t_format	flags;
	char *str = calloc(50, 1);

	og_fill_flag_bag("%u", 2, &flags);
	write_usigned_number(123, str, &flags);
	test_function(!ft_memcmp(str, "123", ft_strlen(str)), "Test 1: uint number");

	og_fill_flag_bag("%o", 2, &flags);
	write_usigned_number(123, str, &flags);
	test_function(!ft_memcmp(str, "173", ft_strlen(str)), "Test 2: uint number conversion 'o'");

	og_fill_flag_bag("%#o", 3, &flags);
	write_usigned_number(123, str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(str, "0173", ft_strlen(str)), "Test 3: uint number conversion 'o' and flag '#'");

	ft_bzero(str, 50);
	og_fill_flag_bag("%x", 2, &flags);
	write_usigned_number(123, str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(str, "7b", ft_strlen(str)), "Test 4: uint number conversion 'x'");

	ft_bzero(str, 50);
	og_fill_flag_bag("%#x", 3, &flags);
	write_usigned_number(123, str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(str, "0x7b", ft_strlen(str)), "Test 5: uint number conversion 'x' and flag '#'");

	ft_bzero(str, 50);
	og_fill_flag_bag("%#7x", 4, &flags);
	write_usigned_number(123, str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(str, "   0x7b", ft_strlen(str)), "Test 6: uint number conversion 'x' and flag '#' and width");

	ft_bzero(str, 50);
	og_fill_flag_bag("%07x", 4, &flags);
	write_usigned_number(123, str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(str, "000007b", ft_strlen(str)), "Test 7: uint number conversion 'x' and flag '0' and width");

	ft_bzero(str, 50);
	og_fill_flag_bag("%-7x", 4, &flags);
	write_usigned_number(123, str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(str, "7b     ", ft_strlen(str)), "Test 8: uint number conversion 'x' and flag '-' and width");

	ft_bzero(str, 50);
	og_fill_flag_bag("%-#7x", 5, &flags);
	write_usigned_number(123, str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(str, "0x7b   ", ft_strlen(str)), "Test 9: uint number conversion 'x' and flag '-' and flag '#' and width");

}

void	write_float_number_tests(void)
{
	t_format	flags;
	char *str = calloc(50, 1);

	og_fill_flag_bag("%f", 2, &flags);
	write_float_number(10.f, str);
	printf("str: '%s'\n", str);
	test_function(!ft_memcmp(str, "10.0", ft_strlen(str)), "Test 1: float number");

	og_fill_flag_bag("%f", 2, &flags);
	write_float_number(10.75f, str);
	printf("str: '%s'\n", str);
	test_function(!ft_memcmp(str, "10.75", ft_strlen(str)), "Test 2: float number with fraction");

	og_fill_flag_bag("%f", 2, &flags);
	write_float_number(10.1f, str);
	printf("str: '%s'\n", str);
	test_function(!ft_memcmp(str, "10.1000003814697265625", ft_strlen(str)), "Test 3: float number with fraction");
}

void	write_string_tests(void)
{
	t_format	flags;
	char	*str = calloc(50, 1);

	og_fill_flag_bag("%s", 2, &flags);
	write_string("hello world", str, &flags);
	printf("%s\n", str);
	test_function(!ft_memcmp("hello world", str, ft_strlen(str)), "Test 1: just string");

	ft_bzero(str, 50);
	og_fill_flag_bag("%10s", 3, &flags);
	write_string("hello", str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp("     hello", str, ft_strlen(str)), "Test 2: string with width");

	ft_bzero(str, 50);
	og_fill_flag_bag("%-10s", 4, &flags);
	write_string("hello", str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp("hello     ", str, ft_strlen(str)), "Test 3: string with width and flag min");

	ft_bzero(str, 50);
	og_fill_flag_bag("%-10.2s", 6, &flags);
	write_string("hello", str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp("he        ", str, ft_strlen(str)), "Test 4: string with width and flag min and precision");
}

void	write_char_tests(void)
{
	char		*str = calloc(50, 1);
	t_format	flags;

	og_fill_flag_bag("%c", 2, &flags);
	write_char('a', str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp("a", str, ft_strlen(str)), "Test 1: just char");

	og_fill_flag_bag("%2c", 3, &flags);
	write_char('a', str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp(" a", str, ft_strlen(str)), "Test 2: char and width");

	og_fill_flag_bag("%-2c", 3, &flags);
	write_char('a', str, &flags);
	printf("'%s'\n", str);
	test_function(!ft_memcmp("a ", str, ft_strlen(str)), "Test 3: char and width and minus flag");

}