#include "../../includes/ft_printf.h"
#include "../../libft/libft.h"
#include "../tester.h"

#include <stdio.h>
void	test_length_total()
{
	int			ret;	
	//size_t	ret_size_t;
	ret = ft_printf("hello world");
	printf("ret: %d\n", ret);
	test_function(ret == 11, "Test 1: just text");

	ret = ft_printf("hello%s world", "hello");
	printf("ret: %d\n", ret);
	test_function(ret == 16, "Test 2: string as argument");
	
	ret = ft_printf("hello world %s", "hello");
	printf("ret: %d\n", ret);
	test_function(ret == 17, "Test 3: string as argument");

	ret = ft_printf("hello world %s %d", "hello", 12);
	printf("ret: %d\n", ret);
	test_function(ret == 20, "Test 4: string, int as argument");

	ret = ft_printf("hello world %*d %d", 4, 12, 12);
	printf("ret: %d\n", ret);
	test_function(ret == 19, "Test 5: dynamic width");

	ret = ft_printf("hello world %20.1d %d", 12, 12);
	printf("ret: %d\n", ret);
	test_function(ret == 35, "Test 6: static width");

	ret = ft_printf("hello world %0+20.1d %d", 12, 12);
	printf("ret: %d\n", ret);
	test_function(ret == 35, "Test 7: static width, zero flag, plus flag");
}