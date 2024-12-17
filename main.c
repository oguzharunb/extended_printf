#include "./includes/og_printf.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
	og_printf("hello world '%d'\n", -1);
	return (0);
}
