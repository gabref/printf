/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:43:54 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/10 00:06:09 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	justify_d(long n, int len, t_flags *f)
{
	int	bwritten;

	bwritten = 0;
	if (f->is_zero_pad)
	{
		bwritten += f_putnbr(n, f->width);
	}
	else
	{
		if (f->left_justify)
		{
			bwritten += f_putnbr(n, len);
			bwritten += pad_char(' ', f->width - len);
		}
		else
		{
			bwritten += pad_char(' ', f->width - len);
			bwritten += f_putnbr(n, len);
		}
	}
	return (bwritten);
}

int	f_format_d(va_list ap, t_flags *f)
{
	int	bytes;
	long	n;

	(void)f;
	bytes = 0;
	n = (long)va_arg(ap, int);
	bytes = justify_d(n, get_digits(n), f);
	return (bytes);
}
