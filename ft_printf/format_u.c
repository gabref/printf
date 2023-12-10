/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:52:39 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/10 00:32:36 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	justify_u(long n, int len, t_flags *f)
{
	int	bwritten;

	bwritten = 0;
	if (f->is_zero_pad)
	{
		bwritten += pad_char('0', f->width - len);
		bwritten += f_putnbr_unsigned(n, len);
	}
	else
	{
		if (f->left_justify)
		{
			bwritten += f_putnbr_unsigned(n, len);
			bwritten += pad_char(' ', f->width - len);
		}
		else
		{
			bwritten += pad_char(' ', f->width - len);
			bwritten += f_putnbr_unsigned(n, len);
		}
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
