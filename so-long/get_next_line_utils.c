/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:17:26 by halaqoh           #+#    #+#             */
/*   Updated: 2022/02/22 18:08:01 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clos(void)
{
	exit(1);
	return (0);
}

int	ft_strchr(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	len(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		b;
	int		a;

	b = 0;
	a = 0;
	if (!s1)
		s1 = ft_strdup("");
	join = (char *) malloc(len(s1) + len(s2) + 1);
	if (!join)
		return (0);
	while (s1[a])
	{
		join[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		join[a] = s2[b];
		a++;
		b++;
	}
	join[a] = '\0';
	free(s1);
	return (join);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		k;

	k = 0;
	dup = (char *) malloc(len(src) + 1);
	if (!dup)
		return (0);
	while (k < len(src))
	{
		dup[k] = src[k];
		k++;
	}
	dup[k] = '\0';
	return (dup);
}
