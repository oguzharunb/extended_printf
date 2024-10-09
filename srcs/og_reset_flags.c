#include "../includes/og_printf.h"

og_reset_flags(t_flags *flags)
{
	flags->dyn_width = 0;
	flags->flag_hash = 0;
	flags->flag_min = 0;
	flags->flag_plus = 0;
	flags->flag_space = 0;
	flags->flag_zero = 0;
	flags->lm_long = 0;
	flags->lm_short = 0;
	flags->precision = 0;
	flags->size = 0;
	flags->width = 0;
}
