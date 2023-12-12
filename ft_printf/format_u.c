/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:52:39 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/12 12:01:19 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	justify_u(long n, int len, t_flags *f)
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
		bwritten += f_putnbr_unsigned(n, num_len);
		bwritten += pad_char(' ', pad_len);
	}
	else
	{
		bwritten += pad_char(' ', pad_len);
		bwritten += f_putnbr_unsigned(n, num_len);
	}
	return (bwritten);
}

int	f_format_u(va_list ap, t_flags *f)
{
	int				bytes;
	unsigned int	n;

	bytes = 0;
	n = va_arg(ap, unsigned int);
	bytes = justify_u(n, get_digits_unsigned(n), f);
	return (bytes);
}
