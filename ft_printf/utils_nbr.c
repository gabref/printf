/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:30:43 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/10 00:29:11 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	get_digits(long n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		digits++;
	}
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

int	get_digits_unsigned(unsigned long n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

int	f_putnbr(long n, int bytes)
{
	int		count;
	char	*nstr;
	int		i;

	i = 0;
	count = 0;
	if (n == H_INT_MIN)
		i++;
	if (n < 0)
	{
		count += f_putchar('-');
		n *= -1;
		bytes--;
	}
	count += pad_char('0', bytes - get_digits(n));
	nstr = ft_itoa(n);
	ft_putstr_fd(&nstr[i], 1);
	count += ft_strlen(&nstr[i]);
	free(nstr);
	return (count);
}

int	f_putnbr_unsigned(unsigned long n, int bytes)
{
	int		count;

	count = 0;
	if (n > 9)
		count += f_putnbr_unsigned(n / 10, bytes - 1);
	count += f_putchar(n % 10 + 0x30);
	return (count);
}
