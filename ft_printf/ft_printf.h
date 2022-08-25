/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:28:53 by alyazici          #+#    #+#             */
/*   Updated: 2022/02/12 17:36:04 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

int		ft_printf(const char *str, ...);
int		detect(const char *str, va_list args);
int		put(char chr, va_list args);
int		ft_putchar(int c);
int		ft_putstr(char *str);
void	ft_putnbr(int n, int *counter);
void	ft_putbase_d(unsigned long long n, int *counter);
void	ft_putbase_h(unsigned long long n, const char *base, int *counter);
#endif
