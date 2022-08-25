/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:01:39 by alyazici          #+#    #+#             */
/*   Updated: 2022/01/14 16:53:07 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <ctype.h>
#include <stdio.h>*/

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || \
		(c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
int main(void)
{
    printf("%d\n", ft_isalnum(96));
    printf("%d", isalnum(95));
}*/