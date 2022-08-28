/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:11:08 by alyazici          #+#    #+#             */
/*   Updated: 2022/01/12 12:57:21 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <ctype.h>
#include <stdio.h>*/

int	ft_isascii(int x)
{
	if (x > -1 && x < 128)
		return (1);
	return (0);
}

/*
int main(void)
{
    for (int i = -128; i < 128; i++)
    {
        printf("%d\n",isascii(i));
    }
    printf("************************");
    for (int i = -128; i < 128; i++)
    {
        printf("%d\n",ft_isascii(i));
    }
}*/
