#include "../includes/og_printf.h"
#include "tester.h"

#include <stdio.h>
int main(void)
{
	run_tests(test_length_c, "test_length_c");
	run_tests(test_length_s, "test_length_s");
	run_tests(test_length_f, "test_length_f");
	run_tests(test_length_i, "test_length_i");
	run_tests(test_length_u, "test_length_u");
	run_tests(test_length_b, "test_length_b");
	run_tests(test_length_total, "test_length_total");
	run_tests(test_flag_check, "test_flag_check");
	run_tests(write_signed_number_tests, "write_signed_number_tests");
	run_tests(write_usigned_number_tests, "write_usigned_number_tests");
	run_tests(write_util_tests, "write_util_tests");
	run_tests(write_float_number_tests, "write_float_number_tests");
	run_tests(write_string_tests, "write_string_tests");
	return (0);
}
