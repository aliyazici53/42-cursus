/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:52:35 by alyazici          #+#    #+#             */
/*   Updated: 2022/01/21 14:55:28 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
/*
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	idx;

	idx = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (!(dest) || !(s))
		return (0);
	while (start < ft_strlen((char *)s) && s[start + idx] && idx < len)
	{
		dest[idx] = s[start + idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}


int main(void)
{
    char    s[25] = "Ali-Imran Yazici Benim";
    printf("%s", ft_substr(s, 5, 12));
    return (0);
}*/
/*Parameters #1. The string from which to create the substring.
#2. The start index of the substring in the string 's'.
#3. The maximum length of the substring.*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	strlen;

	if (s == NULL)
		return (NULL);
	strlen = ft_strlen((char *)s);
	if (start > strlen)
		return (ft_strdup(""));
	if (strlen - start >= len)
		sstr = (char *)malloc((len + 1) * sizeof(char));
	else
		sstr = (char *)malloc((strlen - start + 1) * sizeof(char));
	if (sstr == NULL)
		return (NULL);
	ft_strlcpy(sstr, (s + start), (len + 1));
	return (sstr);
}
