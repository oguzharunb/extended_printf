#ifndef OG_PRINTF_H
# define OG_PRINTF_H
# define CONVERSIONS "bscdeEfiouxX%"
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
# define FLOAT_EXPONENT_MASK	0b1111111100000000000000000000000//2139095040
# include <stddef.h>

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

void	og_fill_flag_bag(char const *to_replace, size_t size, t_format*flags);
void	print_flags(t_format*flags); // temporary
int		og_isin(char const *str, char c);
void	og_reset_flags(t_format*flags);
size_t	og_strlen(const char *s);
size_t	og_number_len_base(long number, size_t base);

size_t	og_length_o(t_format*flags, int nbr);
size_t	og_length_d(t_format*flags, long nbr);
size_t	og_length_p(t_format*flags, void *ptr);
size_t	og_length_c(t_format*flags);
size_t 	og_length_s(t_format*flags, char const *str);
size_t	og_length_f(t_format*flags, float number);
size_t	og_length_e(t_format*flags, double number);
size_t	og_length_a(t_format*flags, double number);
#endif