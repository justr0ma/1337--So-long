/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:17:24 by halaqoh           #+#    #+#             */
/*   Updated: 2022/02/21 20:40:32 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *msg)
{
	perror(msg);
	exit(1);
}

void	fe_chek_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			ft_error("map is not valid wall");
		i++;
	}
}

int	cep_chek(char *line, t_rvars *ts)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			ts->coin[0] += 1;
		else if (line[i] == 'E')
			ts->coin[1] += 1;
		else if (line[i] == 'P')
			ts->coin[2] += 1;
		else if (line[i] != '1' && line[i] != '0' )
			ft_error("map not valid, char is not 10epc");
		i++;
	}
	return (1);
}

void	ft_malta(char *ln, t_rvars *ts, int l[4] )
{
	static char	*lastline;

	if (ln && cep_chek(ln, ts))
	{
		lastline = ln;
		if (ln[0] != '1' || ln[len(ln) - 1] != '1' || len(ln) != l[0])
			ft_error("map is not valid map");
	}
	else
		fe_chek_wall(lastline);
}

int	chek_map(char *map, t_rvars *ts)
{
	int		l[4];
	char	*ln;

	l[3] = 0;
	while (l[3] < 3)
		ts->coin[l[3]++] = 0;
	l[2] = open(map, O_RDONLY);
	if (l[2] < 0)
		ft_error("file error :/ ");
	ln = get_next_line(l[2]);
	l[0] = len(ln);
	l[1] = 0;
	fe_chek_wall(ln);
	ft_malta(ln, ts, l);
	while (ln && (l[1]++ >= 0))
	{
		free(ln);
		ln = get_next_line(l[2]);
		ft_malta(ln, ts, l);
	}
	if (ts->coin[0] == 0 || ts->coin[2] != 1 || ts->coin[1] == 0)
		ft_error("E C P at least one of them not exist");
	return (l[1]);
}
