/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:30:43 by galves-f          #+#    #+#             */
/*   Updated: 2024/02/11 19:23:52 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_uitoa(unsigned int nbr)
{
	char			*result;
	int				len;
	unsigned int	aux;

	len = 1;
	aux = nbr;
	while (aux / 10 != 0 && len++)
		aux = aux / 10;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	while (len-- != 0)
	{
		result[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
}

int	handle_signs(long *n, t_flags *f)
{
	int	count;

	count = 0;
	if (n == NULL)
		return (count);
	if (f->space && *n >= 0)
		count += f_putchar(' ');
	else if (f->plus && *n >= 0)
		count += f_putchar('+');
	if (*n < 0)
	{
		count += f_putchar('-');
		*n *= -1;
	}
	return (count);
}

int	f_putnbr(long n, int bytes, t_flags *f)
{
	int		count;
	char	*nstr;
	int		i;
	int		digits;

	i = 0;
	count = 0;
	digits = get_digits(n);
	if (n == H_INT_MIN)
		i++;
	count += handle_signs(&n, f);
	if (f->precision && f->precision_value == 0 && n == 0)
		nstr = ft_strdup("");
	else
		nstr = ft_itoa(n);
	count += pad_char('0', bytes - digits);
	count += f_putstr(&nstr[i]);
	free(nstr);
	return (count);
}

int	f_putnbr_unsigned(long n, int bytes, t_flags *f)
{
	int				count;
	char			*nstr;
	int				i;
	unsigned long	uln;
	int				digits;

	uln = (unsigned long)n;
	i = 0;
	count = 0;
	digits = get_digits_unsigned(uln);
	if (f->space)
		count += f_putchar(' ');
	else if (f->plus)
		count += f_putchar('+');
	if (f->precision && f->precision_value == 0 && uln == 0)
		nstr = ft_strdup("");
	else
		nstr = ft_uitoa(uln);
	count += pad_char('0', bytes - digits);
	count += f_putstr(&nstr[i]);
	free(nstr);
	return (count);
}
