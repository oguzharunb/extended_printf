#include "../../includes/og_printf.h"
#include "../../libft/libft.h"
#include "../tester.h"

#include <stdlib.h>
#include <stdio.h>
void	write_util_tests(void)
{
	unsigned long ret;

	ret = float_fraction(0.25, 1);
	test_function(ret = 25, "Test 1: 0.25");
}