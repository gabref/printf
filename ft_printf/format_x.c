/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:43:25 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/12 10:39:39 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	justify_x(unsigned int n, int len, t_flags *f)
{
	int	bwritten;
	int	num_len;
	int	pad_len;

	bwritten = 0;
	num_len = len;
	pad_len = 0;
	if (f->is_zero_pad)
		num_len = f->width;
	if (f->precision)
		num_len = f->precision_value;
	if (!f->is_zero_pad && f->width > len)
		pad_len = f->width - len;
	if (f->precision && f->width > len)
	{
		num_len = f->precision_value;
		pad_len = f->width - num_len;
	}
	if (f->left_justify)
	{
		bwritten += f_putnbr_base(n, num_len, f);
		bwritten += pad_char(' ', pad_len);
	}
	else
	{
		bwritten += pad_char(' ', pad_len);
		bwritten += f_putnbr_base(n, num_len, f);
	}
	return (bwritten);
}

int	f_format_x(va_list ap, t_flags *f)
{
	int				bytes;
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	bytes = justify_x(n, get_digits_base(n, 16), f);
	return (bytes);
}
