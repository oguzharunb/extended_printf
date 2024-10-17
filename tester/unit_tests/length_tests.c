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
	ft_strlcpy(flag_str, "4", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_s(&flags, "hello") == 5, "Test 1: len over width");

	reset_flags(&flags);
	ft_strlcpy(flag_str, ".4", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_s(&flags, "hello") == 4, "Test 2: precision over len");

	reset_flags(&flags);
	ft_strlcpy(flag_str, "7.4", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_s(&flags, "hello") == 7, "Test 3: width over precision over len");
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
}