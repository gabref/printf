/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:03:45 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/09 10:05:45 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	printf_format(va_list ap, const char *fmt, int (*fn[])(va_list, t_flags *))
{
	t_flags	f;
	int		i;
	int		bwritten;

	i = 0;
	bwritten = 0;
	while (fmt[i])
	{
		start_flags(&f);
		if (fmt[i] == '%' && fmt[++i])
		{
			i += map_flags(&fmt[i], &f);
			if (f.specifier != INVALID_SPEC)
				bwritten += fn[f.specifier](ap, &f);
			else
				bwritten += f_putchar(fmt[i]);
		}
		else
			bwritten += f_putchar(fmt[i]);
		i++;
	}
	return (bwritten);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		bwritten;
	int		(*formatters[9])(va_list, t_flags *);

	formatters[STRING_SPEC] = &f_format_s;
	formatters[CHAR_SPEC] = &f_format_c;
	formatters[DECIMAL_SPEC] = &f_format_d;
	formatters[UNS_DECIMAL_SPEC] = &f_format_u;
	formatters[HEX_LOWER_SPEC] = &f_format_x;
	formatters[HEX_UPPER_SPEC] = &f_format_x;
	formatters[PERCENT_SPEC] = &f_format_per;
	bwritten = 0;
	va_start(ap, format);
	bwritten = printf_format(ap, format, formatters);
	va_end(ap);
	return (bwritten);
}
