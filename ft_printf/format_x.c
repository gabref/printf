/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:43:25 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/09 17:13:45 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	justify_x(unsigned int n, int len, t_flags *f, char *symbols)
{
	if (f->left_justify)
	{
		ft_putnbr_base(n, symbols);
		pad_char(' ', f->width - len);
	}
	else
	{
		pad_char(' ', f->width - len);
		ft_putnbr_base(n, symbols);
	}
	if (len < f->width)
		return (f->width);
	return (len);
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
