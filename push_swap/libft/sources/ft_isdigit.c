/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:12:33 by alyazici          #+#    #+#             */
/*   Updated: 2022/01/14 16:50:52 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <ctype.h>
#include <stdio.h>*/

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*
int main(void)
{
    for (int i = 0; i < 100; i++)
    {
        printf("%d\n",isdigit(i));
    }
    
    printf("%s","****************************");
    for (int i = 0; i < 100; i++)
    {
        printf("%d\n",ft_isdigit(i));
    }
    return (0);
}
*/