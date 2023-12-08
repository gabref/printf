/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:43:54 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/08 15:01:52 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include "libft/libft.h"

int	number_of_digits(int n)
{
	int	digits;

	digits = 0;
	if (n < 0)
	{
		n = -n;
		digits++;
	}
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

int	f_format_d(va_list ap, t_flags *f)
{
	int	bytes;
	int	n;

	(void)f;
	bytes = 0;
	n = va_arg(ap, int);
	bytes = number_of_digits(n);
	ft_putnbr_fd(n, 1);
	return (bytes);
}
