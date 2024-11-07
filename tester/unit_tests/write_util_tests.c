#include "../../includes/og_printf.h"
#include "../../libft/libft.h"
#include "../tester.h"

#include <stdlib.h>
#include <stdio.h>
void	write_util_tests(void)
{
	unsigned long	ret;
	long			basamak = 0;
	ret = float_fraction(0.25, 1, 0, &basamak, 5);
	test_function(ret == 25 && basamak == 2, "Test 1: 0.25");

	basamak = 0;
	ret = float_fraction(0.75, 1, 0, &basamak, 5);
	test_function(ret == 75 && basamak == 2, "Test 2: 0.75");
}