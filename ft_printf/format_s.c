/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:22:07 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/10 00:59:18 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int f_putstr_size(char *str, int size)
{
	int i = 0;
	while (str[i] && i < size)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}

int f_putstr(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int justify_s(char *str, int len, t_flags *f)
{
	int bwritten = 0;
	if (f->width > len)
	{
		if (!f->left_justify)
			pad_char(' ', f->width - len);
		if (f->precision)
			f_putstr_size(str, f->precision_value);
		else
			f_putstr(str);
		if (f->left_justify)
			pad_char(' ', f->width - len);
		return (f->width);
	}
	ft_putstr_fd(str, 1);
	return (bwritten);
}

int	f_format_s(va_list ap, t_flags *f)
{
	char	*str;
	int		bwritten;

	str = va_arg(ap, char *);
	if (str == NULL)
		return (f_putstr("(null)"));
	bwritten = justify_s(str, ft_strlen(str), f);
	return (bwritten);
}
