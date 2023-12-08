/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:43:25 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/08 16:42:02 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include "libft/libft.h"

static int	get_digits_base(long n, int base)
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

void	ft_putnbr_base_print(long n_long, int base_value, char *symbols)
{
	if (n_long < 0)
	{
		n_long = -n_long;
		ft_putchar_fd('-', 1);
	}
	if (n_long >= base_value)
		ft_putnbr_base_print(n_long / base_value, base_value, symbols);
	ft_putchar_fd(symbols[n_long % base_value], 1);
}

void	ft_putnbr_base(long nbr, char *base)
{
	int	base_value;

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

int	f_format_x(va_list ap, t_flags *f)
{
	int				bytes;
	unsigned int	n;

	(void)f;
	n = va_arg(ap, unsigned int);
	if (f->letter_case == LOWERCASE)
		ft_putnbr_base(n, HEX_BASE_LOWERCASE);
	else
		ft_putnbr_base(n, HEX_BASE_UPPERCASE);
	bytes = get_digits_base(n, 16);
	return (bytes);
}
