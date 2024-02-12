/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:21:17 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/12 12:44:21 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	flag_handler_c(t_flags *f, char c)
{
	int	i;

	i = 0;
	if (!f->left_justify)
		while (i++ < f->width - 1)
			ft_putchar_fd(' ', 1);
	ft_putchar_fd(c, 1);
	if (f->left_justify)
		while (i++ < f->width - 1)
			ft_putchar_fd(' ', 1);
}

int	f_format_c(va_list ap, t_flags *f)
{
	char	c;
	int		bwritten;

	c = va_arg(ap, int);
	flag_handler_c(f, c);
	bwritten = 1;
	if (f->width)
		bwritten = f->width;
	return (bwritten);
}

int	f_putchar(int c)
{
	return (write(1, &c, 1));
}
