/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:49:35 by alyazici          #+#    #+#             */
/*   Updated: 2022/01/09 16:50:45 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include <string.h>*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[h] != '\0')
	{
		n = 0;
		while (haystack[h + n] == needle[n] && (h + n) < len)
		{
			if (haystack[h + n] == '\0' && needle[n] == '\0')
				return ((char *)&haystack[h]);
			n++;
		}
		if (needle[n] == '\0')
			return ((char *)haystack + h);
		h++;
	}
	return (0);
}

/*
int main(void)
{
    const char *largestring = "Foo Bar";
	const char *smallstring = "Barr";
	char	*ptr;

	ptr = ft_strnstr(largestring, smallstring, 12);//NULL
   	printf("%s", ptr);
}*/