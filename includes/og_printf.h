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

# include <stddef.h>

typedef struct s_flags
{
	int	flag_min;
	int	flag_plus;
	int	flag_space;
	int	flag_zero;
	int	flag_hash;
	int	lm_short;
	int	lm_long;
	int	dyn_width;
	int	width;
	int	precision;
	int	size;
} t_flags;

void	og_fill_flag_bag(char const *to_replace, size_t size, t_flags *flags);
void	print_flags(t_flags *flags); // temporary
int		og_isin(char const *str, char c);
void	ft_bzero(void *s, size_t n); // temporary
void	ft_reset_flags(t_flags *flags);
size_t	ft_strlen(const char *s);
size_t	ft_number_len_base(unsigned long number, size_t base);

size_t	og_length_o(t_flags *flags, int nbr);
size_t	og_length_d(t_flags *flags, int	nbr);
size_t	og_length_p(t_flags *flags, void *ptr);
size_t	og_length_c(t_flags *flags);
size_t og_length_s(t_flags *flags, char const *str);
#endif