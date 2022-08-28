/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 03:12:14 by aabduvak          #+#    #+#             */
/*   Updated: 2022/03/06 10:27:12 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	has_space(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (32);
		if (*str == '\t')
			return (9);
		if (*str == '\r')
			return (13);
		str++;
	}
	return (0);
}

void	join_with_space(char **s1, char *s2)
{
	*s1 = ft_strjoin(*s1, s2);
	*s1 = ft_strjoin(*s1, " ");
}

char	*take_args(int argc, char **argv)
{
	int			i;
	int			counter;
	char		**tmp;
	char		*res;
	int			j;

	counter = 0;
	res = (char *)malloc(sizeof(char) * 400);
	i = 1;
	while (i < argc)
	{
		if (has_space(argv[i]))
		{
			tmp = ft_split(argv[i], ' ');
			counter = ft_count_words(argv[i], ' ');
			j = -1;
			while (++j < counter)
				join_with_space(&res, tmp[j]);
			free_char(tmp, counter);
		}
		else
			join_with_space(&res, argv[i]);
		i++;
	}
	return (res);
}

int		args_count(char *res)
{
	int		counter;

	counter = ft_count_words(res, ' ');
	return (counter);
}
