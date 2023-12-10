/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:13:37 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/10 00:12:23 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	justify_p(unsigned long pv, int len, t_flags *f)
{
	if (f->left_justify)
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base(pv, HEX_BASE_LOWERCASE, len - 2);
		pad_char(' ', f->width - len);
	}
	else
	{
		pad_char(' ', f->width - len);
		ft_putstr_fd("0x", 1);
		ft_putnbr_base(pv, HEX_BASE_LOWERCASE, len - 2);
	}
	if (len < f->width)
		return (f->width);
	return (len);
}

int	f_format_p(va_list ap, t_flags *f)
{
	unsigned long	p_value;
	void			*p;
	int				len;
	int				bwritten;

	p = va_arg(ap, void *);
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	p_value = (unsigned long)p;
	len = get_digits_base(p_value, 16) + 2;
	bwritten = justify_p(p_value, len, f);
	return (bwritten);
}
