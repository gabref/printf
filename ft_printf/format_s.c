/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:22:07 by galves-f          #+#    #+#             */
/*   Updated: 2024/02/11 15:20:03 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	f_putstr_size(char *str, int size)
{
	int	i;

	i = 0;
	while (str[i] && i < size)
		ft_putchar_fd(str[i++], 1);
	return (i);
}

int	f_putstr(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	precision_s(char *str, t_flags *f)
{
	if (f->precision)
		return (f_putstr_size(str, f->precision_value));
	else
		return (f_putstr(str));
}

int	flag_handler_s(char *str, int len, t_flags *f)
{
	int	bwritten;

	bwritten = 0;
	if (f->width > len)
	{
		if (!f->left_justify)
			bwritten += pad_char(' ', f->width - len);
		bwritten += precision_s(str, f);
		if (f->left_justify)
			bwritten += pad_char(' ', f->width - len);
		return (bwritten);
	}
	bwritten += precision_s(str, f);
	return (bwritten);
}

int	f_format_s(va_list ap, t_flags *f)
{
	char	*str;
	int		bwritten;
	int		len;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		len = ft_strlen(NULL_STRING);
		if (f->precision  && f->precision_value < len)
			return (ft_printf(""));
		return (flag_handler_s(NULL_STRING, len, f));
	}
	len = ft_strlen(str);
	if (f->precision && f->precision_value < len)
		len = f->precision_value;
	bwritten = flag_handler_s(str, len, f);
	return (bwritten);
}
