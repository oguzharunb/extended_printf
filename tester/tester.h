#ifndef TESTER_H
# define TESTER_H

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
// prototypes
void	test_function(int state, char *message);
void	run_tests(void (*f)(void), const char *function_name);

void	test_length_s(void);
void	test_length_c(void);
void	test_length_f(void);
void	test_length_i(void);
void	test_length_u(void);
void	test_length_b(void);

void	test_flag_check(void);
void	test_length_total(void);
void	write_signed_number_tests(void);
void	write_usigned_number_tests(void);
void	write_string_tests(void);
void	write_char_tests(void);
void	write_pointer_tests(void);

void	printf_test(void);
#endif
