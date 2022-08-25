/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:46:48 by alyazici          #+#    #+#             */
/*   Updated: 2022/01/14 21:41:59 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h>
#include <strings.h>
#include <stdio.h>*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size)
		dst[i] = '\0';
	return (len);
}

/*
int main(void)
{
	char dest[20] = "Ali Imran Yaz";
	char src[20] = "Ahmet Faruk Yazici";
	int  size = 5;

	printf("%d", ft_strlcpy(dest, src, size));
	printf("%d", strlcpy(dest, src, size));
}	
*/
