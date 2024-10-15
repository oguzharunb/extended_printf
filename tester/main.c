#include "../includes/og_printf.h"
#include "tester.h"

#include <stdio.h>
int main(void)
{
	run_tests(test_length_c, "test_length_c");
	run_tests(test_length_s, "test_length_s");
	run_tests(test_length_f, "test_length_f");
	run_tests(test_length_integer, "test_length_integer");
}
