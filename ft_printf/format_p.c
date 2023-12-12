/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:13:37 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/12 10:42:30 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	justify_p(unsigned long pv, int len, t_flags *f)
{
	int bwritten = 0;
	if (f->left_justify)
	{
		bwritten += f_putnbr_base(pv, len - 2, f);
		bwritten += pad_char(' ', f->width - len);
	}
	else
	{
		bwritten += pad_char(' ', f->width - len);
		bwritten += f_putnbr_base(pv, len - 2, f);
	}
	return (bwritten);
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
	f->hash = 1;
	p_value = (unsigned long)p;
	len = get_digits_base(p_value, 16) + 2;
	bwritten = justify_p(p_value, len, f);
	return (bwritten);
}
