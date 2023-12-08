/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:28:04 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/08 14:42:50 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum	e_format_spec
{
	CHAR_SPEC,
	STRING_SPEC,
	POINTER_SPEC,
	DECIMAL_SPEC,
	INTEGER_SPEC,
	UNS_DECIMAL_SPEC,
	HEX_LOWER_SPEC,
	HEX_UPPER_SPEC,
	PERCENT_SPEC,
	INVALID_SPEC,
};

/*
   left_justify 	= '-'
   zero_pad 		= '0'
   precision 		= '.'
   hash 			= '#'
   plus 			= '+'
   splace 			= ' '
*/
typedef struct s_flags
{
	int	left_justify;
	int	zero_pad;
	int	precision;
	int	hash;
	int	plus;
	int	space;
}		t_flags;

int		ft_printf(const char *format, ...);

int		f_putchar(int c);
int		f_format_c(va_list ap, t_flags *f);
int		f_format_s(va_list ap, t_flags *f);
int		f_format_d(va_list ap, t_flags *f);

#endif
