/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:18:30 by alyazici          #+#    #+#             */
/*   Updated: 2022/02/12 20:31:50 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	int		idx;
	char	*line;

	idx = 0;
	if (!str[idx])
		return (NULL);
	while (str[idx] != '\n' && str[idx] != '\0')
		idx++;
	line = (char *)malloc(sizeof(char) * (idx + 2));
	if (!line)
		return (NULL);
	idx = 0;
	while (str[idx] && str[idx] != '\n')
	{
		line[idx] = str[idx];
		idx++;
	}
	if (str[idx] == '\n')
	{
		line[idx] = str[idx];
		idx++;
	}
	line[idx] = '\0';
	return (line);
}

char	*get_remain(char *str)
{
	int		i;
	int		s;
	int		_lenstr;
	char	*remain;

	_lenstr = ft_strlen(str);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	remain = (char *)malloc(sizeof(char) * (_lenstr - i + 1));
	if (!remain)
		return (NULL);
	i++;
	s = 0;
	while (str[i] != '\0')
		remain[s++] = str[i++];
	remain[s] = '\0';
	free(str);
	return (remain);
}

char	*ft_update(int fd, char *saved)
{
	int		read_bytes;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(saved, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(saved);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		saved = ft_strjoin(saved, buff);
	}
	free(buff);
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, str, 0) < 0)
		return (NULL);
	str = ft_update(fd, str);
	line = get_line(str);
	str = get_remain(str);
	return (line);
}

/*
int main()
{
	int fd;

	fd = open("get_next_line.h", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}*/