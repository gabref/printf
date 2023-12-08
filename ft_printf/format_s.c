/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:22:07 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/08 14:40:30 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	f_format_s(va_list ap, t_flags *f)
{
	char	*str;

	(void) f;
	str = va_arg(ap, char *);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
