/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:35:22 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/08 14:54:38 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

void	assert(int e, int r)
{
	if (r == e)
		printf("\033[0;32mok\033[m\n\n");
	else
		printf("\033[0;31mexpected = %d, got %d\033[m\n\n", e, r);
}

int	main(void)
{
	int	r;
	int	e;

	r = ft_printf("same exact test\n");
	e = printf("same exact test\n");
	assert(e, r);
	r = ft_printf("same exact %s\n", " text!");
	e = printf("same exact %s\n", " text!");
	assert(e, r);
	r = ft_printf("same exact %c\n", 'c');
	e = printf("same exact %c\n", 'c');
	assert(e, r);
	r = ft_printf("same exact %d, %d, %d\n", 42, -42, 1024);
	e = printf("same exact %d, %d, %d\n", 42, -42, 1024);
	assert(e, r);
	return (0);
}
