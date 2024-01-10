/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:13:37 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/10 10:57:06 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	flag_handler_pointer(unsigned long pv, int len, t_flags *f)
{
	int	bwritten;

	bwritten = 0;
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
		return (f_putstr(NIL_STRING));
	f->hash = 1;
	p_value = (unsigned long)p;
	len = get_digits_base(p_value, 16) + 2;
	bwritten = flag_handler_pointer(p_value, len, f);
	return (bwritten);
}
