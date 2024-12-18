#include "../../includes/ft_printf.h"
#include <stdio.h>

void	printf_test(void)
{
	printf("hello world");
	ft_printf("hello world");
	
	putchar('\n');
	printf("hello world %s\n", "oguz");
	putchar('\n');
	ft_printf("hello world %s\n", "oguz");
	
	putchar('\n');
	printf("hello world %d\n", 21);
	putchar('\n');
	ft_printf("hello world %d\n", 21);
	
	putchar('\n');
	printf("hello world '%23d'\n", 21);
	putchar('\n');
	ft_printf("hello world '%23d'\n", 21);
	
	putchar('\n');
	printf("hello world '%23d' '%12s'\n", 12, "hello");
	putchar('\n');
	ft_printf("hello world '%23d' '%12s'\n", 12,  "hello");
}