/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:43:25 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/10 00:10:12 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	justify_x(unsigned int n, int len, t_flags *f, char *symbols)
{
	int	bwritten;

	bwritten = 0;
	if (f->is_zero_pad)
		bwritten += ft_putnbr_base(n, symbols, f->width);
	else
	{
		if (f->left_justify)
		{
			bwritten += ft_putnbr_base(n, symbols, len);
			bwritten += pad_char(' ', f->width - len);
		}
		else
		{
			bwritten += pad_char(' ', f->width - len);
			bwritten += ft_putnbr_base(n, symbols, len);
		}
	}
	return (bwritten);
}

int	f_format_x(va_list ap, t_flags *f)
{
	int				bytes;
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	if (f->letter_case == LOWERCASE)
		bytes = justify_x(n, get_digits_base(n, 16), f, HEX_BASE_LOWERCASE);
	else
		bytes = justify_x(n, get_digits_base(n, 16), f, HEX_BASE_UPPERCASE);
	return (bytes);
}
