#include "../../includes/og_printf.h"
#include "../../libft/libft.h"
#include "../tester.h"

#include <stdio.h>
void	test_length_c()
{
	char	flag_str[100];
	t_format	flags;
	//size_t	ret_size_t;
	ft_strlcpy(flag_str, "4", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_c(&flags) == 4, "Test 1: just width");

	ft_strlcpy(flag_str, "-4", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_c(&flags) == 4, "Test 2: width and minus");
}

void	test_length_s()
{
	char	flag_str[100];
	t_format	flags;

	ft_strlcpy(flag_str, "4s", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_s(&flags, "hello") == 5, "Test 1: len over width");

	ft_strlcpy(flag_str, ".4s", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_s(&flags, "hello") == 4, "Test 2: precision over len");

	ft_strlcpy(flag_str, "7.4s", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_s(&flags, "hello") == 7, "Test 3: width over precision over len");

	ft_strlcpy(flag_str, "#7.4s", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_s(&flags, "hello") == 7, "Test 4: width over precision over len with another flag");
}

void	test_length_i()
{
	char		flag_str[100];
	t_format	flags;

	ft_strlcpy(flag_str, "%li", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_i(&flags, 12) == 2, "Test 1: no flags");

	ft_strlcpy(flag_str, "%li", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_i(&flags, 21474836471) == 11, "Test 2: long with 'l'");

	ft_strlcpy(flag_str, "%i", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_i(&flags, 21474836471) == 2, "Test 3: long without 'l'");

	ft_strlcpy(flag_str, "%i", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_i(&flags, -1) == 2, "Test 4: minus int");

	ft_strlcpy(flag_str, "%hhi", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_i(&flags, -1) == 2, "Test 5: minus int in char");

	ft_strlcpy(flag_str, "%hhi", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_i(&flags, -257) == 2, "Test 6: minus int in char, is type casting works");

	ft_strlcpy(flag_str, "%lli", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_i(&flags, -257) == 4, "Test 7: minus int in long long");

	ft_strlcpy(flag_str, "%0+20d", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_i(&flags, 12) == 20, "Test 8: plus flag, zero flag, 20 width");

}

void	test_length_u(void)
{
	char		flag_str[100];
	t_format	flags;

	ft_strlcpy(flag_str, "%u", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_u(&flags, 12) == 2, "Test 1: no flag, no edge case");

	ft_strlcpy(flag_str, "%u", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_u(&flags, -1) == 10, "Test 2: minus assigned");

	ft_strlcpy(flag_str, "%hhu", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_u(&flags, -1) == 3, "Test 3: flag hh");

	ft_strlcpy(flag_str, "%llu", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_u(&flags, -257) == 20, "Test 4: flag ll with casting");

	ft_strlcpy(flag_str, "%lu", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_u(&flags, -257) == 20, "Test 5: flag l with casting");
}
