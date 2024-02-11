/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flags_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:28:09 by galves-f          #+#    #+#             */
/*   Updated: 2024/02/11 19:25:45 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

void	config_lengths(long n, int len, t_lengths *l, t_flags *f)
{
	int	is_neg;

	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	if (f->precision)
		if (f->precision_value > (len - is_neg))
			l->num_len = f->precision_value + is_neg;
	if (f->width > len && n != 0 && f->precision)
		l->pad_len = f->width - l->num_len;
	else if (f->width && n == 0 && f->precision && !f->precision_value)
		l->pad_len = f->width;
	else if (f->width > len && !f->precision && f->is_zero_pad)
		l->num_len = f->width;
	else if (f->width > len && !f->precision && !f->is_zero_pad)
		l->pad_len = f->width - l->num_len;
}

void	config_lengths_u(long n, int len, t_lengths *l, t_flags *f)
{
	if (f->precision)
		if (f->precision_value > len)
			l->num_len = f->precision_value;
	if (f->width > len && n != 0 && f->precision)
		l->pad_len = f->width - l->num_len;
	else if (f->width && n == 0 && f->precision && !f->precision_value)
		l->pad_len = f->width;
	else if (f->width > len && !f->precision && f->is_zero_pad)
		l->num_len = f->width;
	else if (f->width > len && !f->precision && !f->is_zero_pad)
		l->pad_len = f->width - l->num_len;
}

int	flag_handler_number(long n, int len, t_flags *f, t_pn pn)
{
	int			bwritten;
	t_lengths	lengths;

	bwritten = 0;
	lengths.num_len = len;
	lengths.pad_len = 0;
	if (f->specifier == UNS_DECIMAL_SPEC || f->specifier == HEX_LOWER_SPEC
		|| f->specifier == HEX_UPPER_SPEC)
		config_lengths_u(n, len, &lengths, f);
	else
		config_lengths(n, len, &lengths, f);
	if (f->left_justify)
	{
		bwritten += pn(n, lengths.num_len, f);
		bwritten += pad_char(' ', lengths.pad_len);
	}
	else
	{
		bwritten += pad_char(' ', lengths.pad_len);
		bwritten += pn(n, lengths.num_len, f);
	}
	return (bwritten);
}
