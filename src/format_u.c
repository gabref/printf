/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:52:39 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/12 12:21:49 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	f_format_u(va_list ap, t_flags *f)
{
	int				bytes;
	unsigned int	n;

	bytes = 0;
	n = va_arg(ap, unsigned int);
	bytes = flag_handler_number(n, get_digits_unsigned(n), f,
			f_putnbr_unsigned);
	return (bytes);
}
