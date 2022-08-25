/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:52:05 by alyazici          #+#    #+#             */
/*   Updated: 2022/01/12 14:02:58 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

//MAIN
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size_s1;

	if (!s1 || !set)
		return (0);
	while (ft_strchr((char *)set, *s1) && *s1 != '\0')
		s1++;
	size_s1 = ft_strlen((char *)s1);
	while (ft_strchr((char *)set, s1[size_s1]) && size_s1 != '\0')
		size_s1--;
	return (ft_substr((char *)s1, 0, size_s1 + 1));
}

/*
int main(void)
{
    char *s1 = "Ali Imran Yazici";
    char *set = "Imran Yazici";

    printf("%s", ft_strtrim(s1, set));
}*/