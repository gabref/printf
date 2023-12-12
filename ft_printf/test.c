/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:35:22 by galves-f          #+#    #+#             */
/*   Updated: 2023/12/12 11:47:39 by galves-f         ###   ########.fr       */
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

	r = ft_printf("%.s\n", "");
	e = printf("%.s\n", "");
	assert(e, r);
	r = ft_printf(" %.1s\n", "");
	e = printf(" %.1s\n", "");
	assert(e, r);
	r = ft_printf("%.1s \n", "");
	e = printf("%.1s \n", "");
	assert(e, r);
	r = ft_printf(" %.s \n", "");
	e = printf(" %.s \n", "");
	assert(e, r);
	r = ft_printf(" %.s \n", "-");
	e = printf(" %.s \n", "-");
	assert(e, r);
	r = ft_printf(" %.2s %.1s \n", "", "-");
	e = printf(" %.2s %.1s \n", "", "-");
	assert(e, r);
	r = ft_printf(" %.3s %.2s \n", " - ", "");
	e = printf(" %.3s %.2s \n", " - ", "");
	assert(e, r);
	r = ft_printf(" %.1s %.2s %.3s %.4s \n", " - ", "", "4", "");
	e = printf(" %.1s %.2s %.3s %.4s \n", " - ", "", "4", "");
	assert(e, r);
	r = ft_printf(" %.2s %.3s %.4s %.5s %.1s \n", " - ", "", "4", "", "2 ");
	e = printf(" %.2s %.3s %.4s %.5s %.1s \n", " - ", "", "4", "", "2 ");
	assert(e, r);

	r = ft_printf("hello %10.5s \n", "gabriel");
	e = printf("hello %10.5s \n", "gabriel");
	assert(e, r);
}

void	test_d(void)
{
	int	r;
	int	e;

	ft_printf("Testing %%d\n\n");

	r = ft_printf(" %d ", INT_MIN);
	e = printf(" %d ", INT_MIN);
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

	// r = ft_printf(" %-1x \n", 0);
	// e = printf(" %-1x \n", 0);
	// assert(e, r);
	// r = ft_printf(" %-2x \n", -1);
	// e = printf(" %-2x \n", -1);
	// assert(e, r);
	// r = ft_printf(" %-3x \n", 1);
	// e = printf(" %-3x \n", 1);
	// assert(e, r);
	// r = ft_printf(" %-4x \n", 9);
	// e = printf(" %-4x \n", 9);
	// assert(e, r);
	// r = ft_printf(" %-1x \n", 10);
	// e = printf(" %-1x \n", 10);
	// assert(e, r);
	// r = ft_printf(" %-2x \n", 11);
	// e = printf(" %-2x \n", 11);
	// assert(e, r);
	// r = ft_printf(" %-3x \n", 15);
	// e = printf(" %-3x \n", 15);
	// assert(e, r);
	// r = ft_printf(" %-4x \n", 16);
	// e = printf(" %-4x \n", 16);
	// assert(e, r);
	// r = ft_printf(" %-5x \n", 17);
	// e = printf(" %-5x \n", 17);
	// assert(e, r);
	// r = ft_printf(" %-1x \n", 99);
	// e = printf(" %-1x \n", 99);
	// assert(e, r);
	// r = ft_printf(" %-2x \n", 100);
	// e = printf(" %-2x \n", 100);
	// assert(e, r);
	// r = ft_printf(" %-3x \n", 101);
	// e = printf(" %-3x \n", 101);
	// assert(e, r);
	// r = ft_printf(" %-1x \n", -9);
	// e = printf(" %-1x \n", -9);
	// assert(e, r);
	// r = ft_printf(" %-2x \n", -10);
	// e = printf(" %-2x \n", -10);
	// assert(e, r);
	// r = ft_printf(" %-3x \n", -11);
	// e = printf(" %-3x \n", -11);
	// assert(e, r);
	// r = ft_printf(" %-4x \n", -14);
	// e = printf(" %-4x \n", -14);
	// assert(e, r);
	// r = ft_printf(" %-5x \n", -15);
	// e = printf(" %-5x \n", -15);
	// assert(e, r);
	// r = ft_printf(" %-6x \n", -16);
	// e = printf(" %-6x \n", -16);
	// assert(e, r);
	// r = ft_printf(" %-1x \n", -99);
	// e = printf(" %-1x \n", -99);
	// assert(e, r);
	// r = ft_printf(" %-2x \n", -100);
	// e = printf(" %-2x \n", -100);
	// assert(e, r);
	// r = ft_printf(" %-3x \n", -101);
	// e = printf(" %-3x \n", -101);
	// assert(e, r);
	// r = ft_printf(" %-9x \n", INT_MAX);
	// e = printf(" %-9x \n", INT_MAX);
	// assert(e, r);
	// r = ft_printf(" %-10x \n", INT_MIN);
	// e = printf(" %-10x \n", INT_MIN);
	// assert(e, r);
	// r = ft_printf(" %-11x \n", LONG_MAX);
	// e = printf(" %-11x \n", LONG_MAX);
	// assert(e, r);
	// r = ft_printf(" %-12x \n", LONG_MIN);
	// e = printf(" %-12x \n", LONG_MIN);
	// assert(e, r);
	// r = ft_printf(" %-13x \n", UINT_MAX);
	// e = printf(" %-13x \n", UINT_MAX);
	// assert(e, r);
	// r = ft_printf(" %-14x \n", ULONG_MAX);
	// e = printf(" %-14x \n", ULONG_MAX);
	// assert(e, r);
	// r = ft_printf(" %-15x \n", 9223372036854775807LL);
	// e = printf(" %-15x \n", 9223372036854775807LL);
	// assert(e, r);
	// r = ft_printf(" %-9x %-10x %-11x %-12x %-13x %-14x %-15x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// e = printf(" %-9x %-10x %-11x %-12x %-13x %-14x %-15x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// assert(e, r);

	// r = ft_printf(" %.1x \n", 0);
	// e = printf(" %.1x \n", 0);
	// assert(e, r);
	// r = ft_printf(" %.2x \n", -1);
	// e = printf(" %.2x \n", -1);
	// assert(e, r);
	// r = ft_printf(" %.2x \n", 1);
	// e = printf(" %.2x \n", 1);
	// assert(e, r);
	// r = ft_printf(" %.1x \n", 9);
	// e = printf(" %.1x \n", 9);
	// assert(e, r);
	// r = ft_printf(" %.2x \n", 10);
	// e = printf(" %.2x \n", 10);
	// assert(e, r);
	// r = ft_printf(" %.3x \n", 11);
	// e = printf(" %.3x \n", 11);
	// assert(e, r);
	// r = ft_printf(" %.4x \n", 15);
	// e = printf(" %.4x \n", 15);
	// assert(e, r);
	// r = ft_printf(" %.5x \n", 16);
	// e = printf(" %.5x \n", 16);
	// assert(e, r);
	// r = ft_printf(" %.6x \n", 17);
	// e = printf(" %.6x \n", 17);
	// assert(e, r);
	// r = ft_printf(" %.1x \n", 99);
	// e = printf(" %.1x \n", 99);
	// assert(e, r);
	// r = ft_printf(" %.2x \n", 100);
	// e = printf(" %.2x \n", 100);
	// assert(e, r);
	// r = ft_printf(" %.3x \n", 101);
	// e = printf(" %.3x \n", 101);
	// assert(e, r);
	// r = ft_printf(" %.1x \n", -9);
	// e = printf(" %.1x \n", -9);
	// assert(e, r);
	// r = ft_printf(" %.2x \n", -10);
	// e = printf(" %.2x \n", -10);
	// assert(e, r);
	// r = ft_printf(" %.3x \n", -11);
	// e = printf(" %.3x \n", -11);
	// assert(e, r);
	// r = ft_printf(" %.4x \n", -14);
	// e = printf(" %.4x \n", -14);
	// assert(e, r);
	// r = ft_printf(" %.1x \n", -15);
	// e = printf(" %.1x \n", -15);
	// assert(e, r);
	// r = ft_printf(" %.2x \n", -16);
	// e = printf(" %.2x \n", -16);
	// assert(e, r);
	// r = ft_printf(" %.3x \n", -99);
	// e = printf(" %.3x \n", -99);
	// assert(e, r);
	// r = ft_printf(" %.3x \n", -100);
	// e = printf(" %.3x \n", -100);
	// assert(e, r);
	// r = ft_printf(" %.4x \n", -101);
	// e = printf(" %.4x \n", -101);
	// assert(e, r);
	// r = ft_printf(" %.8x \n", INT_MAX);
	// e = printf(" %.8x \n", INT_MAX);
	// assert(e, r);
	// r = ft_printf(" %.9x \n", INT_MIN);
	// e = printf(" %.9x \n", INT_MIN);
	// assert(e, r);
	// r = ft_printf(" %.10x \n", LONG_MAX);
	// e = printf(" %.10x \n", LONG_MAX);
	// assert(e, r);
	// r = ft_printf(" %.11x \n", LONG_MIN);
	// e = printf(" %.11x \n", LONG_MIN);
	// assert(e, r);
	// r = ft_printf(" %.12x \n", UINT_MAX);
	// e = printf(" %.12x \n", UINT_MAX);
	// assert(e, r);
	// r = ft_printf(" %.13x \n", ULONG_MAX);
	// e = printf(" %.13x \n", ULONG_MAX);
	// assert(e, r);
	// r = ft_printf(" %.14x \n", 9223372036854775807LL);
	// e = printf(" %.14x \n", 9223372036854775807LL);
	// assert(e, r);
	// r = ft_printf(" %.8x %.9x %.10x %.11x %.12x %.13x %.14x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// e = printf(" %.8x %.9x %.10x %.11x %.12x %.13x %.14x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// assert(e, r);


	r = ft_printf(" %#x \n", 0);
	e = printf(" %#x \n", 0);
	assert(e, r);
	r = ft_printf(" %#x \n", -1);
	e = printf(" %#x \n", -1);
	assert(e, r);
	r = ft_printf(" %#x \n", 1);
	e = printf(" %#x \n", 1);
	assert(e, r);
	r = ft_printf(" %#x \n", 9);
	e = printf(" %#x \n", 9);
	assert(e, r);
	r = ft_printf(" %#x \n", 10);
	e = printf(" %#x \n", 10);
	assert(e, r);
	r = ft_printf(" %#x \n", 11);
	e = printf(" %#x \n", 11);
	assert(e, r);
	r = ft_printf(" %#x \n", 15);
	e = printf(" %#x \n", 15);
	assert(e, r);
	r = ft_printf(" %#x \n", 16);
	e = printf(" %#x \n", 16);
	assert(e, r);
	r = ft_printf(" %#x \n", 17);
	e = printf(" %#x \n", 17);
	assert(e, r);
	r = ft_printf(" %#x \n", 99);
	e = printf(" %#x \n", 99);
	assert(e, r);
	r = ft_printf(" %#x \n", 100);
	e = printf(" %#x \n", 100);
	assert(e, r);
	r = ft_printf(" %#x \n", 101);
	e = printf(" %#x \n", 101);
	assert(e, r);
	r = ft_printf(" %#x \n", -9);
	e = printf(" %#x \n", -9);
	assert(e, r);
	r = ft_printf(" %#x \n", -10);
	e = printf(" %#x \n", -10);
	assert(e, r);
	r = ft_printf(" %#x \n", -11);
	e = printf(" %#x \n", -11);
	assert(e, r);
	r = ft_printf(" %#x \n", -14);
	e = printf(" %#x \n", -14);
	assert(e, r);
	r = ft_printf(" %#x \n", -15);
	e = printf(" %#x \n", -15);
	assert(e, r);
	r = ft_printf(" %#x \n", -16);
	e = printf(" %#x \n", -16);
	assert(e, r);
	r = ft_printf(" %#x \n", -99);
	e = printf(" %#x \n", -99);
	assert(e, r);
	r = ft_printf(" %#x \n", -100);
	e = printf(" %#x \n", -100);
	assert(e, r);
	r = ft_printf(" %#x \n", -101);
	e = printf(" %#x \n", -101);
	assert(e, r);
	r = ft_printf(" %#x \n", INT_MAX);
	e = printf(" %#x \n", INT_MAX);
	assert(e, r);
	r = ft_printf(" %#x \n", INT_MIN);
	e = printf(" %#x \n", INT_MIN);
	assert(e, r);
	r = ft_printf(" %#x \n", LONG_MAX);
	e = printf(" %#x \n", LONG_MAX);
	assert(e, r);
	r = ft_printf(" %#x \n", LONG_MIN);
	e = printf(" %#x \n", LONG_MIN);
	assert(e, r);
	r = ft_printf(" %#x \n", UINT_MAX);
	e = printf(" %#x \n", UINT_MAX);
	assert(e, r);
	r = ft_printf(" %#x \n", ULONG_MAX);
	e = printf(" %#x \n", ULONG_MAX);
	assert(e, r);
	r = ft_printf(" %#x \n", 9223372036854775807LL);
	e = printf(" %#x \n", 9223372036854775807LL);
	assert(e, r);
	r = ft_printf(" %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	e = printf(" %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	assert(e, r);
	r = ft_printf(" %#x%#x \n", INT_MAX, INT_MIN);
	e = printf(" %#x%#x \n", INT_MAX, INT_MIN);
	assert(e, r);

	printf(" %#x - %#X \n", INT_MAX, INT_MAX);

}

void	test_u(void)
{
	int	r;
	int	e;

	r = ft_printf(" %.1u \n", 0);
	e = printf(" %.1u \n", 0);
	assert(e, r);
	r = ft_printf(" %.2u \n", -1);
	e = printf(" %.2u \n", -1);
	assert(e, r);
	r = ft_printf(" %.2u \n", 1);
	e = printf(" %.2u \n", 1);
	assert(e, r);
	r = ft_printf(" %.1u \n", 9);
	e = printf(" %.1u \n", 9);
	assert(e, r);
	r = ft_printf(" %.2u \n", 10);
	e = printf(" %.2u \n", 10);
	assert(e, r);
	r = ft_printf(" %.3u \n", 11);
	e = printf(" %.3u \n", 11);
	assert(e, r);
	r = ft_printf(" %.4u \n", 15);
	e = printf(" %.4u \n", 15);
	assert(e, r);
	r = ft_printf(" %.5u \n", 16);
	e = printf(" %.5u \n", 16);
	assert(e, r);
	r = ft_printf(" %.6u \n", 17);
	e = printf(" %.6u \n", 17);
	assert(e, r);
	r = ft_printf(" %.1u \n", 99);
	e = printf(" %.1u \n", 99);
	assert(e, r);
	r = ft_printf(" %.2u \n", 100);
	e = printf(" %.2u \n", 100);
	assert(e, r);
	r = ft_printf(" %.3u \n", 101);
	e = printf(" %.3u \n", 101);
	assert(e, r);
	r = ft_printf(" %.1u \n", -9);
	e = printf(" %.1u \n", -9);
	assert(e, r);
	r = ft_printf(" %.2u \n", -10);
	e = printf(" %.2u \n", -10);
	assert(e, r);
	r = ft_printf(" %.3u \n", -11);
	e = printf(" %.3u \n", -11);
	assert(e, r);
	r = ft_printf(" %.4u \n", -14);
	e = printf(" %.4u \n", -14);
	assert(e, r);
	r = ft_printf(" %.1u \n", -15);
	e = printf(" %.1u \n", -15);
	assert(e, r);
	r = ft_printf(" %.2u \n", -16);
	e = printf(" %.2u \n", -16);
	assert(e, r);
	r = ft_printf(" %.3u \n", -99);
	e = printf(" %.3u \n", -99);
	assert(e, r);
	r = ft_printf(" %.3u \n", -100);
	e = printf(" %.3u \n", -100);
	assert(e, r);
	r = ft_printf(" %.4u \n", -101);
	e = printf(" %.4u \n", -101);
	assert(e, r);
	r = ft_printf(" %.8u \n", INT_MAX);
	e = printf(" %.8u \n", INT_MAX);
	assert(e, r);
	r = ft_printf(" %.9u \n", INT_MIN);
	e = printf(" %.9u \n", INT_MIN);
	assert(e, r);
	r = ft_printf(" %.10u \n", LONG_MAX);
	e = printf(" %.10u \n", (unsigned int)LONG_MAX);
	assert(e, r);
	r = ft_printf(" %.11u \n", LONG_MIN);
	e = printf(" %.11u \n", LONG_MIN);
	assert(e, r);
	r = ft_printf(" %.12u \n", UINT_MAX);
	e = printf(" %.12u \n", UINT_MAX);
	assert(e, r);
	r = ft_printf(" %.13u \n", ULONG_MAX);
	e = printf(" %.13u \n", ULONG_MAX);
	assert(e, r);
	r = ft_printf(" %.14u \n", 9223372036854775807LL);
	e = printf(" %.14u \n", (unsigned int)9223372036854775807LL);
	assert(e, r);
	r = ft_printf(" %.8u %.9u %.10u %.11u %.12u %.13u %.14u\n", INT_MAX, INT_MIN, (unsigned int)LONG_MAX, (unsigned int)LONG_MIN, (unsigned int)ULONG_MAX, 0, -42);
	e = printf(" %.8u %.9u %.10u %.11u %.12u %.13u %.14u\n", INT_MAX, INT_MIN, (unsigned int)LONG_MAX, (unsigned int)LONG_MIN, (unsigned int)ULONG_MAX, 0, -42);
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
	r = ft_printf("test long max and min: %p %p\n", LONG_MAX, LONG_MIN);
	e = printf("test long max and min: %p %p\n", (void *)LONG_MAX,
			(void *)LONG_MIN);
	assert(e, r);
	r = ft_printf("test ulong max: %p %p\n", ULONG_MAX, -ULONG_MAX);
	e = printf("test ulong max: %p %p\n", (void *)ULONG_MAX,
			(void *)-ULONG_MAX);
	assert(e, r);
	r = ft_printf("test null: %p %p\n", NULL, NULL);
	e = printf("test null: %p %p\n", NULL, NULL);
	assert(e, r);
	r = ft_printf("test zero: %p %p\n", 0, 0);
	e = printf("test zero: %p %p\n", (void *)0, (void *)0);
	assert(e, r);

	r = ft_printf(" %p %p\n", (void *)INT_MAX , (void *)INT_MIN);
	e = printf(" %p %p\n", (void *)INT_MAX , (void *)INT_MIN);
	assert(e, r);

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
