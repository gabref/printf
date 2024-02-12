/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_per.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:08:38 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/12 12:53:05 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	f_format_per(va_list ap, t_flags *f)
{
	int	bytes;

	bytes = 1;
	(void)f;
	(void)ap;
	ft_putchar_fd('%', 1);
	return (bytes);
}
