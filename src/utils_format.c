/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:27:53 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/09 16:40:17 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	pad_char(char c, int bytes)
{
	int	count;

	count = 0;
	while (bytes-- > 0)
	{
		ft_putchar_fd(c, 1);
		count++;
	}
	return (count);
}
