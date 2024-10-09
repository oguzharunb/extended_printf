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
