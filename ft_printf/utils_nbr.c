/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:30:43 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/12 12:20:40 by galves-f         ###   ########.fr       */
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

int	f_putnbr(long n, int bytes, t_flags *f)
{
	int		count;
	char	*nstr;
	int		i;

	i = 0;
	count = 0;
	if (n == H_INT_MIN)
		i++;
	if (f->space && n >= 0)
		count += f_putchar(' ');
	else if (f->plus && n >= 0)
		count += f_putchar('+');
	if (n < 0)
	{
		count += f_putchar('-');
		n *= -1;
		bytes--;
	}
	count += pad_char('0', bytes - get_digits(n));
	nstr = ft_itoa(n);
	count += f_putstr(&nstr[i]);
	free(nstr);
	return (count);
}

int	f_putnbr_unsigned(long n, int bytes, t_flags *f)
{
	int				count;
	unsigned long	uln;

	(void)f;
	uln = (unsigned long)n;
	count = 0;
	count += pad_char('0', bytes - get_digits_unsigned(uln));
	if (uln > 9)
		count += f_putnbr_unsigned(uln / 10, 0, f);
	count += f_putchar(uln % 10 + 0x30);
	return (count);
}
