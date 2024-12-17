/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   og_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:14:36 by obastug           #+#    #+#             */
/*   Updated: 2024/12/17 17:12:50 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define DOUBLE_EXPONENT_MASK	(long)9218868437227405312L
# define DOUBLE_PRECISION_MASK	(long)4503599627370495L
# define FLOAT_EXPONENT_MASK	2139095040
# define MASK_64_TO_32			(unsigned int)4294967295U
# define FLOAT_FRACTION_MASK	8388607
# define FRACTION_ITER			4194304
# include <stddef.h>
# include <stdarg.h>

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
	int		hash_len;
	char	conversion;
}	t_format;

void			og_fill_flag_bag(char const *to_r, size_t s, t_format *f);
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

size_t			og_length_o(t_format*flags, int nbr);
size_t			og_length_u(t_format *flags, unsigned long nbr);
size_t			og_length_i(t_format*flags, long nbr);
size_t			og_length_p(t_format*flags, void *ptr);
size_t			og_length_c(t_format*flags);
size_t			og_length_s(t_format*flags, char const *str);

size_t			lengthf(char const *string, va_list *args);
int				flag_check(t_format *flags, size_t size);
int				replace_dynwidth(t_format *flags, va_list *args);

void			write_usigned_number(unsigned long n, char *d, t_format *f);
void			write_signed_number(long number, char *dest, t_format *flags);
void			write_float_number(float number, char *dest);
void			write_string(char *string, char *dest, t_format *flags);
void			write_char(char c, char *dest, t_format *flags);
void			write_pointer(void *ptr, char *dest, t_format *flags);
int				og_printf(const char *string, ...);
void			fill_string(const char *string, va_list *args, char *dest);

void	l_mod(char const *tr, size_t *i, t_format *flags, size_t size);
void	parse_flags(char const *tr, size_t *i, t_format *flags, size_t size);
#endif