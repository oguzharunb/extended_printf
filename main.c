#include "./includes/og_printf.h"
#include <stdio.h>


int main(void)
{

	int a = 17;
	printf("%-#5X\n", a);
	printf("%-#5o\n", a);
	printf("%0#5o\n", a);
	printf("%o\n", 123);
	printf("%x\n", 123);
	printf("%#x\n", 123);
	return (0);
}
