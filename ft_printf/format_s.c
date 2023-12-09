/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:22:07 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/09 15:11:20 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	f_format_s(va_list ap, t_flags *f)
{
	char	*str;
	int		len;
	int		i;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (f->width > len)
	{
		i = 0;
		if (!f->left_justify)
			while (i++ < f->width - len)
				ft_putchar_fd(' ', 1);
		ft_putstr_fd(str, 1);
		if (f->left_justify)
			while (i++ < f->width - len)
				ft_putchar_fd(' ', 1);
		return (f->width);
	}
	ft_putstr_fd(str, 1);
	return (len);
}
