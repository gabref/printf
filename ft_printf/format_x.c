/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:43:25 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/12 12:42:43 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	f_format_x(va_list ap, t_flags *f)
{
	int				bytes;
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	bytes = flag_handler_number(n, get_digits_base(n, 16), f, f_putnbr_base);
	return (bytes);
}
