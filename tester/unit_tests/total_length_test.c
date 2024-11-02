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
	test_function(ret == 19, "Test 5: dynamic width");

	ret = og_printf("hello world %20.1d %d", 12, 12);
	test_function(ret == 35, "Test 6: static width");

	ret = og_printf("hello world %0+20.1d %d", 12, 12);
	test_function(ret == 35, "Test 7: static width, zero flag, plus flag");

	ret = og_printf("%f", 1.0625f);
	printf("ret: %d\n", ret);
	test_function(ret == 6, "Test 8: float");

	ret = og_printf("%f", 0.5f);
	printf("ret: %d\n", ret);
	test_function(ret == 3, "Test 9: float < 1");

	ret = og_printf("%f", 0.25f);
	printf("ret: %d\n", ret);
	test_function(ret == 4, "Test 9: float < 1");

	ret = og_printf("%f", 0.125f);
	printf("ret: %d\n", ret);
	test_function(ret == 5, "Test 9: float < 1");

	ret = og_printf("%f", 0.0625f);
	printf("ret: %d\n", ret);
	test_function(ret == 6, "Test 9: float < 1");
	
	ret = og_printf("%f", 0.03125f);
	printf("ret: %d\n", ret);
	test_function(ret == 7, "Test 9: float < 1");
}