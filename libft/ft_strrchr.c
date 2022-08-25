/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:51:01 by alyazici          #+#    #+#             */
/*   Updated: 2022/01/14 21:38:00 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	int	idx;

	idx = ft_strlen((char *)str) + 1;
	while (idx--)
	{
		if (*(str + idx) == c)
			return ((char *)str + idx);
	} 
	return (0);
}

int main(void)
{
    char data[] = "Ali Imran Yazici";
    printf("%s\n",strrchr(data, 0));
    printf("%s", ft_strrchr(data, 0));
    return (0);
}*/

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	ch;

	ch = (unsigned char)c;
	len = ft_strlen((char *)s);
	if (ch == '\0')
		return ((char *)(&s[len]));
	while (--len >= 0)
	{
		if (s[len] == ch)
			return ((char *)(&s[len]));
	}
	return (NULL);
}
