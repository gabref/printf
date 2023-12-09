/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:52:39 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/09 20:00:36 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

// void	putnbr_fd(long n, int fd)
// {
// 	long	ln;
//
// 	ln = (long)n;
// 	if (ln < 0)
// 	{
// 		ln *= -1;
// 		ft_putchar_fd('-', fd);
// 	}
// 	if (ln > 9)
// 		ft_putnbr_fd((int)(ln / 10), fd);
// 	ft_putchar_fd((char)(ln % 10 + 48), fd);
// }
//
// int	justify_u(long n, int len, t_flags *f)
// {
// 	if (f->left_justify)
// 	{
// 		putnbr_fd(n, 1);
// 		pad_char(' ', f->width - len);
// 	}
// 	else
// 	{
// 		pad_char(' ', f->width - len);
// 		putnbr_fd(n, 1);
// 	}
// 	if (len < f->width)
// 		return (f->width);
// 	return (len);
// }

int	justify_u(long n, int len, t_flags *f)
{
	int	bwritten;

	bwritten = 0;
	if (f->is_zero_pad)
	{
		bwritten += f_putnbr(n, f->width);
	}
	else
	{
		if (f->left_justify)
		{
			bwritten += f_putnbr(n, len);
			bwritten += pad_char(' ', f->width - len);
		}
		else
		{
			bwritten += pad_char(' ', f->width - len);
			bwritten += f_putnbr(n, len);
		}
	}
	return (bwritten);
}

int	f_format_u(va_list ap, t_flags *f)
{
	int				bytes;
	unsigned int	n;

	bytes = 0;
	n = va_arg(ap, unsigned int);
	bytes = justify_u(n, get_digits(n), f);
	return (bytes);
}
