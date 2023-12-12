/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:43:54 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/12 11:38:13 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	f_format_d(va_list ap, t_flags *f)
{
	int		bytes;
	long	n;

	(void)f;
	bytes = 0;
	n = (long)va_arg(ap, int);
	bytes = flag_handler_number(n, get_digits(n), f);
	return (bytes);
}
