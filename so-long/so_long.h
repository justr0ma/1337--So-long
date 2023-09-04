/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:17:10 by halaqoh           #+#    #+#             */
/*   Updated: 2022/02/22 18:10:00 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>

typedef struct vars
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*ib;
	char	**mapo;
	int		x;
	int		y;
	int		t;
	int		p;
	int		coin[3];
	int		i;
}t_rvars;
void	ft_error(char *msg);
char	*get_next_line(int fd);
int		ft_strchr(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
int		len(char *src);
int		chek_map(char *map, t_rvars *ts);
int		ft_printf(const char *str, ...);
int		ft_chr(char *str);
int		clos(void);

#endif