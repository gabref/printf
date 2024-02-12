/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:28:04 by galves-f          #+#    #+#             */
/*   Updated: 2024/02/12 10:53:46 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_BASE_LOWERCASE "0123456789abcdef"
# define HEX_BASE_UPPERCASE "0123456789ABCDEF"
# define H_INT_MAX 2147483647
# define H_INT_MIN -2147483648L
# define H_LONG_MIN 9223372036854775808UL
# define H_ULONG_MAX 18446744073709551615UL
# define NULL_STRING "(null)"

# ifdef __APPLE__
#  define NIL_STRING "0x0"
# endif
# ifdef __unix__
#  define NIL_STRING "(nil)"
# endif

enum		e_format_spec
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

enum		e_case
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
*/
typedef struct s_flags
{
	int		left_justify;
	int		zero_pad;
	int		precision;
	int		hash;
	int		plus;
	int		space;
	int		width;
	int		specifier;
	int		letter_case;
	int		is_zero_pad;
	int		precision_value;
}			t_flags;

typedef int	(*t_pn)(long, int, t_flags *);

typedef struct s_lengths
{
	int		num_len;
	int		pad_len;
}			t_lengths;

/* main function */
int			ft_printf(const char *format, ...);

/* format functions */
int			f_format_c(va_list ap, t_flags *f);
int			f_format_s(va_list ap, t_flags *f);
int			f_format_d(va_list ap, t_flags *f);
int			f_format_x(va_list ap, t_flags *f);
int			f_format_u(va_list ap, t_flags *f);
int			f_format_p(va_list ap, t_flags *f);
int			f_format_per(va_list ap, t_flags *f);

/* utils */
int			f_putchar(int c);
int			f_putstr(char *str);
int			pad_char(char c, int bytes);
int			size_of_string(char *str, t_flags *f);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_itoa(int n);
char		*ft_strdup(const char *s);

/* number utils */
int			f_putnbr(long n, int bytes, t_flags *f);
int			f_putnbr_base(long nbr, int bytes, t_flags *f);
int			f_putnbr_unsigned(long n, int bytes, t_flags *f);
int			get_digits(long n);
int			get_digits_base(unsigned long n, int base);
int			get_digits_unsigned(unsigned long n);

/* flag utils */
int			map_flags(const char *str, t_flags *f);
int			flag_handler_number(long n, int len, t_flags *f, t_pn pn);
void		map_conv_spec(char specifier, t_flags *f);
void		start_flags(t_flags *f);
int			flag_handler_s(char *str, int len, t_flags *f);

#endif
