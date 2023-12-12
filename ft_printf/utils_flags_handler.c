/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flags_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:28:09 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/12 14:35:30 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

void	config_lengths(long n, int len, t_lengths *l, t_flags *f)
{
	if (f->is_zero_pad)
		l->num_len = f->width;
	if (f->precision)
		l->num_len = f->precision_value;
	if (!f->is_zero_pad && f->width > len)
		l->pad_len = f->width - len;
	if (f->precision && f->width > len)
	{
		l->num_len = f->precision_value;
		l->pad_len = f->width - l->num_len;
	}
	if (n < 0 && f->precision && f->precision_value >= f->width)
		l->num_len++;
}

void	config_lengths_u(int len, t_lengths *l, t_flags *f)
{
	if (f->is_zero_pad)
		l->num_len = f->width;
	if (f->precision)
		l->num_len = f->precision_value;
	if (!f->is_zero_pad && f->width > len)
		l->pad_len = f->width - len;
	if (f->precision && f->width > len)
	{
		l->num_len = f->precision_value;
		l->pad_len = f->width - l->num_len;
	}
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
		config_lengths_u(len, &lengths, f);
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
