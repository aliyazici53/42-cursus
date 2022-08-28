/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:21:32 by alyazici          #+#    #+#             */
/*   Updated: 2022/01/09 16:23:18 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h>
#include <stdio.h>*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		if (*((unsigned char *)s1 + idx) == *((unsigned char *)s2 + idx))
			idx++;
		else
			return (*((unsigned char *)s1 + idx) - \
					*((unsigned char *)s2 + idx));
	}
	return (0);
}

/*
int main(void)
{
    char dizi[] = "Hell wory";
    char dizi1[] = "Hell wora";
    printf("%d\n", memcmp(dizi, dizi1, 9));
    printf("%d", ft_memcmp(dizi, dizi1, 9));
    return (0);
}*/
//Yanlış olan: (*(unsigned char *)s1 + idx)
// Doğru olan: *((unsigned char *)s1 + idx)