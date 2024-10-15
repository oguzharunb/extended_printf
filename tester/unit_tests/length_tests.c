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

	og_reset_flags(&flags);
	ft_strlcpy(flag_str, "-4", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_c(&flags) == 4, "Test 2: width and minus");
}

void	test_length_s()
{
	char	flag_str[100];
	t_flags	flags;

	og_reset_flags(&flags);
	ft_strlcpy(flag_str, "4", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_s(&flags, "hello") == 5, "Test 1: len over width");

	og_reset_flags(&flags);
	ft_strlcpy(flag_str, ".4", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_s(&flags, "hello") == 4, "Test 2: precision over len");

	og_reset_flags(&flags);
	ft_strlcpy(flag_str, "7.4", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_s(&flags, "hello") == 7, "Test 3: width over precision over len");
}

void	test_length_f()
{
	char	flag_str[100];
	t_flags	flags;

	og_reset_flags(&flags);
	ft_strlcpy(flag_str, "", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_f(&flags, 12.25) == 5, "Test 1: no flags");

	og_reset_flags(&flags);
	ft_strlcpy(flag_str, ".1", sizeof(flag_str));
	og_fill_flag_bag(flag_str, ft_strlen(flag_str), &flags);
	test_function(og_length_f(&flags, 12.25) == 4, "Test 2: precision limited");

}