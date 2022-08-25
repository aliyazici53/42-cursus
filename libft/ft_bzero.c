/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:15:28 by alyazici          #+#    #+#             */
/*   Updated: 2022/01/21 12:34:08 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)s = (unsigned char) '\0';
		s++;
		i++;
	}
}

/*
int main(void)
{
    char data[25] = "Ali Imran Yazici";
    ft_bzero(data, 5);
    int i;

    i = 0;
    while (data != '\0')
    {
        printf("%c", data[i]);
        i++;
    }
}
*/
