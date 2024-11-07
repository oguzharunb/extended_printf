#include "../../includes/og_printf.h"
#include "../../libft/libft.h"
#include "../tester.h"

#include <stdlib.h>
#include <stdio.h>
void	write_util_tests(void)
{
	unsigned long	ret;
	long			step = 0;
	ret = float_fraction(0.25, 1, 0, &step, 5);
	test_function(ret == 25 && step == 2, "Test 1: 0.25");

	step = 0;
	ret = float_fraction(0.75, 1, 0, &step, 5);
	test_function(ret == 75 && step == 2, "Test 2: 0.75");
}