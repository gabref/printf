/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:13:37 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/09 10:30:54 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include "libft/libft.h"

int	f_format_p(va_list ap, t_flags *f)
{
	int				bwritten;
	unsigned long	p_value;

	(void)f;
	p_value = (unsigned long)va_arg(ap, void *);
	bwritten = get_digits_base(p_value, 16) + 2;
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(p_value, HEX_BASE_LOWERCASE);
	return (bwritten);
}
