/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_writers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:18:30 by alyazici          #+#    #+#             */
/*   Updated: 2022/02/12 17:27:27 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	if (!str)
	{
		idx += write(1, "(null)", 6);
		return (idx);
	}
	while (str[idx])
	{
		ft_putchar(str[idx]);
		idx++;
	}
	return (idx);
}

void	ft_putnbr(int n, int *counter)
{
	if (n == INT_MIN)
	{
		*counter += ft_putchar('-');
		*counter += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		n *= -1;
		*counter += ft_putchar('-');
	}
	if (n >= 0 && n <= 9)
	{
		*counter += ft_putchar((n % 10) + '0');
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, counter);
		*counter += ft_putchar((n % 10) + '0');
	}
}

void	ft_putbase_d(unsigned long long n, int *counter)
{
	const char	*base;

	base = "0123456789";
	if (n < 0)
		return ;
	if (n < 10)
	{
		*counter = ft_putchar(base[n % 10]);
		return ;
	}
	else
	{
		ft_putbase_d(n / 10, counter);
		*counter += ft_putchar(base[n % 10]);
	}
}

void	ft_putbase_h(unsigned long long n, const char *base, int *counter)
{
	if (n < 0)
		return ;
	if (n < 16)
	{
		*counter += ft_putchar(base[n % 16]);
		return ;
	}
	else
	{
		ft_putbase_h(n / 16, base, counter);
		*counter += ft_putchar(base[n % 16]);
	}
}

/*

int main()
{
    int a;
    a = ft_putnbr(123);
    printf("%d", a);
}*/
