/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:17:14 by halaqoh           #+#    #+#             */
/*   Updated: 2022/02/21 15:25:39 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define BUFFER_SIZE 4

int	ft_chr(char *str)
{
	int		i;
	char	*ber;

	ber = ".ber";
	i = 0;
	while (str[i])
	{
		if (str[i] != ber[i])
			return (0);
		i++;
	}
	return (1);
}

char	*get_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = malloc((sizeof(char) * i) + 2);
	else
		line = malloc(sizeof(char) * i + 1);
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next(char *str)
{
	int		i;
	char	*new_line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		new_line = ft_strdup(str + i + 1);
		free(str);
		return (new_line);
	}
	free(str);
	return (NULL);
}

char	*ft_read(char *str, int fd)
{
	int		retread;
	char	*buf;

	retread = 1;
	buf = malloc(BUFFER_SIZE + 1);
	while (retread != 0 && !ft_strchr(str))
	{
		retread = read(fd, buf, BUFFER_SIZE);
		if (retread < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[retread] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			retread;

	retread = 1;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	str = ft_read(str, fd);
	if (!str)
		return (NULL);
	if (str[0] == '\0')
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	line = get_line(str);
	str = get_next(str);
	return (line);
}
