#include "../../includes/og_printf.h"
#include "../../libft/libft.h"
#include "../tester.h"

#include <stdio.h>
void	test_length_c()
{
	char	flag_str[100];
	t_format	flags;
	//size_t	ret_size_t;
	reset_flags(&flags);
	ft_strlcpy(flag_str, "4", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_c(&flags) == 4, "Test 1: just width");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "-4", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_c(&flags) == 4, "Test 2: width and minus");
}

void	test_length_s()
{
	char	flag_str[100];
	t_format	flags;

	reset_flags(&flags);
	ft_strlcpy(flag_str, "4s", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_s(&flags, "hello") == 5, "Test 1: len over width");

	reset_flags(&flags);
	ft_strlcpy(flag_str, ".4s", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_s(&flags, "hello") == 4, "Test 2: precision over len");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "7.4s", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_s(&flags, "hello") == 7, "Test 3: width over precision over len");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "#7.4s", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_s(&flags, "hello") == 7, "Test 4: width over precision over len with another flag");
}

void	test_length_f()
{
	char	flag_str[100];
	t_format	flags;

	reset_flags(&flags);
	ft_strlcpy(flag_str, "", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_f(&flags, 12.25) == 5, "Test 1: no flags");

	reset_flags(&flags);
	ft_strlcpy(flag_str, ".1", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_f(&flags, 12.25) == 4, "Test 2: precision limited");
	
	reset_flags(&flags);
	ft_strlcpy(flag_str, "", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_f(&flags, 12.0625) == 7, "Test 3: no flags");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_f(&flags, 12.03125) == 8, "Test 4: no flags");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "10", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_f(&flags, 12.03125) == 10, "Test 5: width over len");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "10.3", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_f(&flags, 12.03125) == 10, "Test 6: width over len with limited precision");
}

void	test_length_i()
{
	char		flag_str[100];
	t_format	flags;

	reset_flags(&flags);
	ft_strlcpy(flag_str, "", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_i(&flags, 12) == 2, "Test 1: no flags");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "l", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_i(&flags, 21474836471) == 11, "Test 2: long with 'l'");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_i(&flags, 21474836471) == 2, "Test 3: long without 'l'");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_i(&flags, -1) == 2, "Test 4: minus int");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "hhi", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_i(&flags, -1) == 2, "Test 5: minus int in char");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "hhi", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_i(&flags, -257) == 2, "Test 6: minus int in char, is type casting works");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "lli", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_i(&flags, -257) == 4, "Test 7: minus int in long long");
}

void	test_length_u(void)
{
	char		flag_str[100];
	t_format	flags;

	reset_flags(&flags);
	ft_strlcpy(flag_str, "", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_u(&flags, 12) == 2, "Test 1: no flag, no edge case");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "u", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_u(&flags, -1) == 10, "Test 2: minus assigned");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "hhu", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_u(&flags, -1) == 3, "Test 3: flag hh");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "llu", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_u(&flags, -257) == 20, "Test 4: flag ll with casting");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "lu", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_u(&flags, -257) == 20, "Test 5: flag l with casting");
}