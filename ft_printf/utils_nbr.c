/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:30:43 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/09 19:57:13 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include "libft/libft.h"

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

int	f_putnbr(long n, int bytes)
{
	int		count;
	char	*nstr;

	count = 0;
	if (n == H_INT_MIN)
		n = (long)(H_INT_MIN * -1);
	else if (n < 0)
	{
		count += f_putchar('-');
		n *= -1;
		bytes--;
	}
	count += pad_char('0', bytes - get_digits(n));
	nstr = ft_itoa(n);
	ft_putstr_fd(nstr, 1);
	count += ft_strlen(nstr);
	free(nstr);
	return (count);
}