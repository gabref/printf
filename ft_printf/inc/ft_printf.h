/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:28:04 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/09 10:19:10 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_BASE_LOWERCASE "0123456789abcdef"
# define HEX_BASE_UPPERCASE "0123456789ABCDEF"

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

enum	e_case
{
	UPPERCASE,
	LOWERCASE,
};

/*
   left_justify 	= '-'
   zero_pad 		= '0'
   precision 		= '.'
   hash 			= '#'
   plus 			= '+'
   splace 			= ' '
   letter_case
   specifier
*/
typedef struct s_flags
{
	int	left_justify;
	int	zero_pad;
	int	precision;
	int	hash;
	int	plus;
	int	space;
	int	letter_case;
	int	specifier;
}		t_flags;

int		ft_printf(const char *format, ...);

int		f_format_c(va_list ap, t_flags *f);
int		f_format_s(va_list ap, t_flags *f);
int		f_format_d(va_list ap, t_flags *f);
int		f_format_x(va_list ap, t_flags *f);
int		f_format_u(va_list ap, t_flags *f);
int		f_format_p(va_list ap, t_flags *f);
int		f_format_per(va_list ap, t_flags *f);

int		f_putchar(int c);
void	ft_putnbr_base(long nbr, char *base);
int		get_digits_base(long n, int base);

void	map_conv_spec(char specifier, t_flags *f);
void	start_flags(t_flags *f);
int		map_flags(const char *str, t_flags *f);

#endif
