/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:27:01 by alyazici          #+#    #+#             */
/*   Updated: 2022/01/14 16:57:48 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h>
#include <stdio.h>*/

//MINE 
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		*(char *)s = (unsigned char)c;
		s++;
		i++;
	}
	return (ptr);
}

/*
int main(void)
{
    char data[25] = "Ali Imran Yazici";

    ft_memset(data, 'A', 7);
    puts(data);
}*/