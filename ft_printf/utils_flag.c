/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:25:42 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/12 11:18:55 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

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
void	start_flags(t_flags *f)
{
	f->left_justify = 0;
	f->zero_pad = 0;
	f->precision = 0;
	f->hash = 0;
	f->plus = 0;
	f->space = 0;
	f->letter_case = LOWERCASE;
	f->specifier = INVALID_SPEC;
	f->width = 0;
	f->precision_value = 0;
	f->is_zero_pad = 0;
}

/* maps conversion specifier */
void	map_conv_spec(char specifier, t_flags *f)
{
	if (specifier == 'c')
		f->specifier = CHAR_SPEC;
	else if (specifier == 's')
		f->specifier = STRING_SPEC;
	else if (specifier == 'p')
		f->specifier = POINTER_SPEC;
	else if (specifier == 'd')
		f->specifier = DECIMAL_SPEC;
	else if (specifier == 'i')
		f->specifier = INTEGER_SPEC;
	else if (specifier == 'u')
		f->specifier = UNS_DECIMAL_SPEC;
	else if (specifier == 'x')
		f->specifier = HEX_LOWER_SPEC;
	else if (specifier == 'X')
	{
		f->specifier = HEX_UPPER_SPEC;
		f->letter_case = UPPERCASE;
	}
	else if (specifier == '%')
		f->specifier = PERCENT_SPEC;
	else
		f->specifier = INVALID_SPEC;
}

int	isspecifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	parse_digits(char c, t_flags *f)
{
	// else if (str[i] == '0')
	// 	f->zero_pad = 1;
	if (c == '0' && !f->width && !f->precision)
		f->is_zero_pad = 1;
	else if(c == '0' && f->width && !f->precision)
		f->width *= 10;
	else if(c == '0' && f->precision)
		f->precision_value *= 10;
	else if (ft_isdigit(c))
	{
		if (f->precision)
			f->precision_value = (f->precision_value * 10) + (c - 0x30);
		else
			f->width = (f->width * 10) + (c - 0x30);
	}
}

/* maps all the specifiers and flags to t_flags */
/* change to while to make it accepts more specifiers, TODO: add priority */
int	map_flags(const char *str, t_flags *f)
{
	int	i;

	i = 0;
	while (str[i] && (!isspecifier(str[i]) || ft_isdigit(str[i])))
	{
		if (str[i] == '-')
			f->left_justify = 1;
		else if (str[i] == '.')
			f->precision = 1;
		else if (str[i] == '#')
			f->hash = 1;
		else if (str[i] == '+')
			f->plus = 1;
		else if (str[i] == ' ')
			f->space = 1;
		else if (ft_isdigit(str[i]))
			parse_digits(str[i], f);
		i++;
	}
	if (str[i] && isspecifier(str[i]))
		map_conv_spec(str[i++], f);
	return (--i);
}
