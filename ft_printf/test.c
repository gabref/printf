/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:35:22 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/09 10:50:31 by galves-f         ###   ########.fr       */
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

void	test_(void)
{
	int	r;
	int	e;

	r = ft_printf("same exact test\n");
	e = printf("same exact test\n");
	assert(e, r);
}

void	test_c(void)
{
	int	r;
	int	e;

	ft_printf("Testing %%c\n\n");
	r = ft_printf("same exact %c\n", 'c');
	e = printf("same exact %c\n", 'c');
	assert(e, r);
}

void	test_s(void)
{
	int	r;
	int	e;

	ft_printf("Testing %%s\n\n");
	r = ft_printf("same exact %s\n", " text!");
	e = printf("same exact %s\n", " text!");
	assert(e, r);
	r = ft_printf("%s\n", NULL);
	e = printf("%s\n", NULL);
	assert(e, r);
}

void	test_d(void)
{
	int	r;
	int	e;

	ft_printf("Testing %%d\n\n");
	r = ft_printf("same exact %d, %d, %d, %d\n", 0, 42, -42, 1024);
	e = printf("same exact %d, %d, %d, %d\n", 0, 42, -42, 1024);
	assert(e, r);
}

void	test_i(void)
{
	int	r;
	int	e;

	ft_printf("Testing %%i\n\n");
	r = ft_printf("test %i %i %i %i %i %li %lli\n", 42, 0x2a, 052, 0b101010,
			42u, 42l, -42ll);
	e = printf("test %i %i %i %i %i %li %lli\n", 42, 0x2a, 052, 0b101010, 42u,
			42l, -42ll);
	assert(e, r);
}

void	test_per(void)
{
	int	r;
	int	e;

	ft_printf("Testing %%\n\n");
	r = ft_printf("same exact %% text\n");
	e = printf("same exact %% text\n");
	assert(e, r);
}

void	test_x(void)
{
	int	r;
	int	e;

	ft_printf("Testing %%x\n\n");
	r = ft_printf("same exact %x %x %x %x %x text\n", 0, 42, -42, 1024, -1);
	e = printf("same exact %x %x %x %x %x text\n", 0, 42, -42, 1024, -1);
	assert(e, r);
	r = ft_printf("same exact %X %X %X %X %X text\n", 0, 42, -42, 1024, -1);
	e = printf("same exact %X %X %X %X %X text\n", 0, 42, -42, 1024, -1);
	assert(e, r);
}

void	test_u(void)
{
	int	r;
	int	e;

	ft_printf("Testing %%u\n\n");
	r = ft_printf("same exact %u %u %u %u %u text\n", 0, 42, -42, 1024, -1);
	e = printf("same exact %u %u %u %u %u text\n", 0, 42, -42, 1024, -1);
	assert(e, r);
}

void	test_p(void)
{
	int		r;
	int		e;
	char	*str;

	ft_printf("Testing %%p\n\n");
	str = "meu test";
	r = ft_printf("some address: %p\n", str);
	e = printf("some address: %p\n", str);
	assert(e, r);
}

int	main(void)
{
	test_();
	test_c();
	test_s();
	test_p();
	test_d();
	test_i();
	test_u();
	test_x();
	test_per();
	return (0);
}
