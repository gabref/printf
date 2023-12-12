/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:06:30 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/12 11:11:52 by galves-f         ###   ########.fr       */
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

unsigned long	check_base(char *base)
{
	unsigned long	base_value;

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
	return (base_value);
}

int	f_putnbr_base_print(unsigned long n_long, unsigned long base_value,
		char *symbols)
{
	int	count;

	count = 0;
	if (n_long >= base_value)
		count += f_putnbr_base_print(n_long / base_value, base_value, symbols);
	count += f_putchar(symbols[n_long % base_value]);
	return (count);
}

int	f_putnbr_base(unsigned long nbr, int bytes, t_flags *f)
{
	unsigned long	base_value;
	int				count;
	char			*base;

	base = HEX_BASE_LOWERCASE;
	if (f->letter_case == UPPERCASE)
		base = HEX_BASE_UPPERCASE;
	base_value = check_base(base);
	if (base_value == 0)
		return (0);
	count = 0;
	if (f->hash && nbr != 0)
	{
		if (f->letter_case == LOWERCASE)
			count += f_putstr("0x");
		else
			count += f_putstr("0X");
	}
	count += pad_char('0', bytes - get_digits_base(nbr, 16));
	count += f_putnbr_base_print(nbr, base_value, base);
	return (count);
}
