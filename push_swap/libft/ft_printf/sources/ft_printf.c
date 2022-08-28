/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:08:43 by alyazici          #+#    #+#             */
/*   Updated: 2022/02/12 17:19:17 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put(char chr, va_list args)
{
	int	counter;

	counter = 0;
	if (chr == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (chr == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (chr == 'd' || chr == 'i')
		ft_putnbr(va_arg(args, int), &counter);
	else if (chr == 'u')
		ft_putbase_d(va_arg(args, unsigned int), &counter);
	else if (chr == 'x')
		ft_putbase_h(va_arg(args, unsigned int), "0123456789abcdef", &counter);
	else if (chr == 'X')
		ft_putbase_h(va_arg(args, unsigned int), "0123456789ABCDEF", &counter);
	else if (chr == '%')
		counter += ft_putchar('%');
	else if (chr == 'p')
	{
		counter += ft_putstr("0x");
		ft_putbase_h(va_arg(args, unsigned long long), "0123456789abcdef", \
		&counter);
	}
	return (counter);
}

int	detect(const char *str, va_list args)
{
	int	counter;
	int	idx;

	idx = 0;
	counter = 0;
	while (str[idx])
	{
		if (str[idx] == '%' && str[idx + 1])
		{
			idx++;
			while (str[idx] == ' ')
				idx++;
			if (!str[idx])
				return (-1);
			counter += put(str[idx], args);
		}
		else
			counter += ft_putchar(str[idx]);
		idx++;
	}
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, str);
	counter += detect(str, args);
	va_end(args);
	return (counter);
}

/*
int main()
{
	int a = ft_printf("merhaba %   s","erm");
	printf("\n");
	int b = printf("merhaba %   s","erm");
	printf("\n%d %d",a,b);
	
	int t = 10;
	printf("\n");
	int c = ft_printf("%p",&t);
	printf("\n");
	int d = printf("%p",&t);
	printf("\n%d %d",c,d);
}*/
