/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:35:22 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/09 19:58:30 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <limits.h>

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
	r = ft_printf("%-1c\n", '0');
	e = printf("%-1c\n", '0');
	assert(e, r);
	r = ft_printf(" %-2c \n", '0');
	e = printf(" %-2c \n", '0');
	assert(e, r);
	r = ft_printf(" %-3c\n", '0' - 256);
	e = printf(" %-3c\n", '0' - 256);
	assert(e, r);
	r = ft_printf("%-4c \n", '0' + 256);
	e = printf("%-4c \n", '0' + 256);
	assert(e, r);
	r = ft_printf(" %-1c %-2c %-3c \n", '0', 0, '1');
	e = printf(" %-1c %-2c %-3c \n", '0', 0, '1');
	assert(e, r);
	r = ft_printf(" %-1c %-2c %-3c \n", ' ', ' ', ' ');
	e = printf(" %-1c %-2c %-3c \n", ' ', ' ', ' ');
	assert(e, r);
	r = ft_printf(" %-1c %-2c %-3c \n", '1', '2', '3');
	e = printf(" %-1c %-2c %-3c \n", '1', '2', '3');
	assert(e, r);
	r = ft_printf(" %-1c %-2c %-3c \n", '2', '1', 0);
	e = printf(" %-1c %-2c %-3c \n", '2', '1', 0);
	assert(e, r);
	r = ft_printf(" %-1c %-2c %-3c \n", 0, '1', '2');
	e = printf(" %-1c %-2c %-3c \n", 0, '1', '2');
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
	e = printf("%s\n", (char *)NULL);
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
	// r = ft_printf("same exact %x %x %x %x %x text\n", 0, 42, -42, 1024, -1);
	// e = printf("same exact %x %x %x %x %x text\n", 0, 42, -42, 1024, -1);
	// assert(e, r);
	// r = ft_printf("same exact %X %X %X %X %X text\n", 0, 42, -42, 1024, -1);
	// e = printf("same exact %X %X %X %X %X text\n", 0, 42, -42, 1024, -1);
	// assert(e, r);
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
	// str = "meu test";
	// r = ft_printf("some address: %p\n", str);
	// e = printf("some address: %p\n", str);
	// assert(e, r);
	// r = ft_printf("test long max and min: %p %p\n", LONG_MAX, LONG_MIN);
	// e = printf("test long max and min: %p %p\n", (void *)LONG_MAX,
	// 		(void *)LONG_MIN);
	// assert(e, r);
	// r = ft_printf("test ulong max: %p %p\n", ULONG_MAX, -ULONG_MAX);
	// e = printf("test ulong max: %p %p\n", (void *)ULONG_MAX,
	// 		(void *)-ULONG_MAX);
	// assert(e, r);
	// r = ft_printf("test null: %p %p\n", NULL, NULL);
	// e = printf("test null: %p %p\n", NULL, NULL);
	// assert(e, r);
	// r = ft_printf("test zero: %p %p\n", 0, 0);
	// e = printf("test zero: %p %p\n", (void *)0, (void *)0);
	// assert(e, r);

	// r = ft_printf(" %p %p\n", (void *)INT_MAX , (void *)INT_MIN);
	// e = printf(" %p %p\n", (void *)INT_MAX , (void *)INT_MIN);
	// assert(e, r);

	r = ft_printf(" %2p \n", (void *)-1);
	e = printf(" %2p \n", (void *)-1);
	assert(e, r);
	r = ft_printf(" %-2p \n", (void *)-1);
	e = printf(" %-2p \n", (void *)-1);
	assert(e, r);
	r = ft_printf(" %-2p \n", (void *)1);
	e = printf(" %-2p \n", (void *)1);
	assert(e, r);
	r = ft_printf(" %-2p \n", (void *)15);
	e = printf(" %-2p \n", (void *)15);
	assert(e, r);
	r = ft_printf(" %-3p \n", (void *)16);
	e = printf(" %-3p \n", (void *)16);
	assert(e, r);
	r = ft_printf(" %-4p \n", (void *)17);
	e = printf(" %-4p \n", (void *)17);
	assert(e, r);
	r = ft_printf(" %-9p %-10p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	e = printf(" %-9p %-10p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	assert(e, r);
	r = ft_printf(" %-11p %-12p \n", (void *)INT_MIN, (void *)INT_MAX);
	e = printf(" %-11p %-12p \n", (void *)INT_MIN, (void *)INT_MAX);
	assert(e, r);
	r = ft_printf(" %-13p %-14p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	e = printf(" %-13p %-14p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	assert(e, r);
	r = ft_printf(" %-1p %-2p \n", (void *)0, (void *)0);
	e = printf(" %-1p %-2p \n", (void *)0, (void *)0);
	assert(e, r);
}

int	main(void)
{
	// test_();
	// test_c();
	// test_s();
	// test_p();
	test_d();
	// test_i();
	// test_u();
	// test_x();
	// test_per();
	return (0);
}
