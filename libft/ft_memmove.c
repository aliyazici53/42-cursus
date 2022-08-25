/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:26:28 by alyazici          #+#    #+#             */
/*   Updated: 2022/01/11 14:15:43 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h>
#include <stdio.h>*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		idx;

	if (dest == src || !n)
		return (dest);
	idx = 0;
	if (dest < src)
	{
		while (idx < n)
		{
			*((char *)dest + idx) = *((char *)src + idx);
			idx++;
		}
	}
	else
	{
		while (n > 0)
		{
			*((char *)dest + n - 1) = *((char *)src + n - 1);
			n--;
		}
	}
	return (dest);
}
