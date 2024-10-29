#include "../../includes/og_printf.h"
#include "../../libft/libft.h"
#include "../tester.h"

#include <stdio.h>
void	test_length_total()
{
	int			ret;	
	//size_t	ret_size_t;
	ret = og_printf("hello world");
	test_function(ret == 11, "Test 1: just text");

	ret = og_printf("hello%s world", "hello");
	test_function(ret == 16, "Test 2: string as argument");
	
	ret = og_printf("hello world %s", "hello");
	test_function(ret == 17, "Test 3: string as argument");

	ret = og_printf("hello world %s %d", "hello", 12);
	test_function(ret == 20, "Test 4: string, int as argument");

	ret = og_printf("hello world %*d %d", 4, 12, 12);
	printf("ret: %d\n", ret);
	test_function(ret == 19, "Test 4: string, int as argument");
}