/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flags_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:28:09 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/12 11:42:45 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

void config_lengths(long n, int len, int *num_len, int *pad_len, t_flags *f)
{
	if (f->is_zero_pad)
		*num_len = f->width;
	if (f->precision)
		*num_len = f->precision_value;
	if (!f->is_zero_pad && f->width > len)
		*pad_len = f->width - len;
	if (f->precision && f->width > len)
	{
		*num_len = f->precision_value;
		*pad_len = f->width - *num_len;
	}
	if (n < 0 && f->precision && f->precision_value >= f->width)
		(*num_len)++;
}

void config_lengths_u(int len, int *num_len, int *pad_len, t_flags *f)
{
	if (f->is_zero_pad)
		*num_len = f->width;
	if (f->precision)
		*num_len = f->precision_value;
	if (!f->is_zero_pad && f->width > len)
		*pad_len = f->width - len;
	if (f->precision && f->width > len)
	{
		*num_len = f->precision_value;
		*pad_len = f->width - *num_len;
	}
}

int	flag_handler_number(long n, int len, t_flags *f)
{
	int	bwritten;
	int	num_len;
	int	pad_len;

	bwritten = 0;
	num_len = len;
	pad_len = 0;
	config_lengths(n, len, &num_len, &pad_len, f);
	if (f->left_justify)
	{
		bwritten += f_putnbr(n, num_len, f);
		bwritten += pad_char(' ', pad_len);
	}
	else
	{
		bwritten += pad_char(' ', pad_len);
		bwritten += f_putnbr(n, num_len, f);
	}
	return (bwritten);
}
