/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:24:45 by alyazici          #+#    #+#             */
/*   Updated: 2022/01/14 17:11:38 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h>
#include <stdio.h>*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!(dest) && !(src))
		return (0);
	while (i < n)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}

/*
int main(void)
{
    int dest[] = {1, 2};
    int dest1[] = {1, 2};
    int src[] = {6, 7};

    memcpy(dest1, src, 2 * sizeof(int));
    ft_memcpy(dest, src, 2 * sizeof(int));

    printf("Main Function : %d %d\n", dest1[0], dest1[1]);
    printf("My Function : %d %d",dest[0],dest[1]);
}*/