#include "tester.h"
#include <stddef.h>
#include "../libft/libft.h"

#include <stdio.h>
void	test_function(int state, char *message)
{
	if (state)
		printf(GREEN "[PASS] " RESET "%s\n", message);
	else
		printf(RED "[FAIL] " RESET "%s\n", message);
}

void	run_tests(void (*f)(void), const char *function_name)
{
	printf("Running tests for %s\n", function_name);
	printf("-----------------\n");
	f();
	printf("-----------------\n");
}
