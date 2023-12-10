/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:06:30 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/10 00:03:51 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	get_digits_base(unsigned long n, int base)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		digits++;
	}
	return (digits);
}

int	ft_double_char(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (*(str + i))
	{
		j = i + 1;
		while (*(str + j))
		{
			if (*(str + i) == *(str + j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_putnbr_base_print(unsigned long n_long, unsigned long base_value,
		char *symbols)
{
	int	count;

	count = 0;
	if (n_long >= base_value)
		count += ft_putnbr_base_print(n_long / base_value, base_value, symbols);
	count += f_putchar(symbols[n_long % base_value]);
	return (count);
}

int	ft_putnbr_base(unsigned long nbr, char *base, int bytes)
{
	unsigned long	base_value;
	int				count;

	base_value = 0;
	while (base[base_value])
	{
		if (base[base_value] == '+' || base[base_value] == '-')
			return (0);
		++base_value;
	}
	if (base_value < 2)
		return (0);
	if (ft_double_char(base))
		return (0);
	count = pad_char('0', bytes - get_digits_base(nbr, 16));
	count += ft_putnbr_base_print(nbr, base_value, base);
	return (count);
}
