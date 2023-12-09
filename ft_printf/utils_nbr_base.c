/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:06:30 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/09 16:41:35 by galves-f         ###   ########.fr       */
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

void	ft_putnbr_base_print(unsigned long n_long, unsigned long base_value,
		char *symbols)
{
	if (n_long >= base_value)
		ft_putnbr_base_print(n_long / base_value, base_value, symbols);
	ft_putchar_fd(symbols[n_long % base_value], 1);
}

void	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned long	base_value;

	base_value = 0;
	while (base[base_value])
	{
		if (base[base_value] == '+' || base[base_value] == '-')
			return ;
		++base_value;
	}
	if (base_value < 2)
		return ;
	if (ft_double_char(base))
		return ;
	ft_putnbr_base_print(nbr, base_value, base);
}
