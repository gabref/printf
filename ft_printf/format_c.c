/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:21:17 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/08 14:39:27 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	f_format_c(va_list ap, t_flags *f)
{
	char	c;

	(void)f;
	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	f_putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
