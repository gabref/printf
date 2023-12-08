/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:03:45 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/08 14:53:15 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

/* maps conversion specifier */
int	map_conv_spec(char specifier)
{
	if (specifier == 'c')
		return (CHAR_SPEC);
	else if (specifier == 's')
		return (STRING_SPEC);
	else if (specifier == 'p')
		return (POINTER_SPEC);
	else if (specifier == 'd')
		return (DECIMAL_SPEC);
	else if (specifier == 'i')
		return (INTEGER_SPEC);
	else if (specifier == 'u')
		return (UNS_DECIMAL_SPEC);
	else if (specifier == 'x')
		return (HEX_LOWER_SPEC);
	else if (specifier == 'X')
		return (HEX_UPPER_SPEC);
	else if (specifier == '%')
		return (PERCENT_SPEC);
	else
		return (INVALID_SPEC);
}

int	ft_printf(const char *format, ...)
{
	int					i;
	int					bwritten;
	t_flags				f;
	va_list				ap;
	static int			(*formatters[4])(va_list, t_flags *);
	enum e_format_spec	conv_flag;

	formatters[STRING_SPEC] = &f_format_s;
	formatters[CHAR_SPEC] = &f_format_c;
	formatters[DECIMAL_SPEC] = &f_format_d;
	i = 0;
	bwritten = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[++i])
		{
			conv_flag = map_conv_spec(format[i]);
			if (conv_flag != INVALID_SPEC)
				bwritten += formatters[conv_flag](ap, &f);
			else
				bwritten += f_putchar(format[i]);
		}
		else
		{
			bwritten += f_putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (bwritten);
}
