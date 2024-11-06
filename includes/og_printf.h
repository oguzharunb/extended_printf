#ifndef OG_PRINTF_H
# define OG_PRINTF_H
# define CONVERSIONS "bscdeaEfiouxX%"
# define FLAGS "0#+- "
# define LENGTH_MODIFIER "hl"
# define NUMBERS "0123456789"
# define PRECISION_START '.'

# define FLAG_ZERO '0'
# define FLAG_SPACE ' '
# define FLAG_HASH '#'
# define FLAG_MINUS '-'
# define FLAG_PLUS '+'

# define LM_SHORT 'h'
# define LM_LONG 'l'

# define DYN_WIDTH '*'

# define S_FLAGS "- "
# define C_FLAGS ""

# define DOUBLE_EXPONENT_MASK	0b0111111111110000000000000000000000000000000000000000000000000000//9218868437227405312
# define DOUBLE_PRECISION_MASK	0b0000000000001111111111111111111111111111111111111111111111111111//4503599627370495
# define FLOAT_EXPONENT_MASK	0b01111111100000000000000000000000//2139095040
# define MASK_64_TO_32			0b0000000000000000000000000000000011111111111111111111111111111111 //4294967295
# define FLOAT_FRACTION_MASK	0b00000000011111111111111111111111
# define FRACTION_ITER			0b00000000010000000000000000000000
# include <stddef.h>
# include <stdarg.h>

//MILESTONE 1

typedef struct s_format
{
	int		flag_min;
	int		flag_plus;
	int		flag_space;
	int		flag_zero;
	int		flag_hash;
	int		lm_short;
	int		lm_long;
	int		dyn_width;
	int		width;
	int		precision;
	int		size;
	int		base;
	char	conversion;
} t_format;

void			og_fill_flag_bag(char const *to_replace, size_t size, t_format*flags);
void			print_flags(t_format*flags); // temporary
int				og_isin(char const *str, char c);
void			reset_flags(t_format*flags);
void			set_base(t_format *flags);
unsigned long	cast_unumber(t_format *flags, unsigned long nbr);
long			cast_number(t_format *flags, long nbr);
size_t			og_unumber_len_base(unsigned long number, size_t base);
size_t			og_number_len_base(long number, size_t base);
long			power(long number, unsigned long power);
long			ft_abs(long number);

size_t			og_length_a(t_format*flags, double number);
size_t			og_length_e(t_format*flags, double number);
size_t			og_length_f(t_format*flags, float number, int i);
size_t			og_length_o(t_format*flags, int nbr);
size_t			og_length_u(t_format *flags, unsigned long nbr);
size_t			og_length_i(t_format*flags, long nbr);
size_t			og_length_p(t_format*flags, void *ptr);
size_t			og_length_c(t_format*flags);
size_t			og_length_s(t_format*flags, char const *str);
size_t			og_length_b(t_format*flags);

size_t			lengthf(char const *string, va_list *args);
int				flag_check(t_format *flags, size_t size);
int				replace_dynwidth(t_format *flags, va_list *args);

unsigned long	float_fraction(float number, long i);

void			write_signed_number(long number, char *dest, t_format *flags);
void			write_unsigned_number(unsigned long, char *dest, t_format *flags);
void			write_float_number(float number, char *dest, t_format *flags);

int				og_printf(const char *string, ...);
#endif