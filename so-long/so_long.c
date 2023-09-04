/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:45:25 by halaqoh           #+#    #+#             */
/*   Updated: 2022/02/22 21:18:36 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_roma(t_rvars *t, int i, int j, char *imgg)
{
	if (t->mapo[i][j] == '0')
	{
		t->ib = mlx_xpm_file_to_image(t->mlx, "./img/b.xpm", &t->x, &t->y);
		mlx_put_image_to_window(t->mlx, t->win, t->ib, j * 40, i * 40);
	}
	else
	{
		if (t->mapo[i][j] == 'P')
		{
			t->t = j * 40;
			t->p = i * 40;
		}
		t->img = mlx_xpm_file_to_image(t->mlx, imgg, &t->x, &t->y);
		mlx_put_image_to_window(t->mlx, t->win, t->img, j * 40, i * 40);
	}
}

t_rvars	*put_img_to_map(t_rvars *t, int d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d)
	{
		j = 0;
		while (t->mapo[i][j])
		{
			if (t->mapo[i][j] == '1')
				ft_roma(t, i, j, "./img/i.xpm");
			if (t->mapo[i][j] == '0')
				ft_roma(t, i, j, "./img/b.xpm");
			if (t->mapo[i][j] == 'E')
				ft_roma(t, i, j, "./img/g.xpm");
			if (t->mapo[i][j] == 'P')
				ft_roma(t, i, j, "./img/r.xpm");
			if (t->mapo[i][j] == 'C')
				ft_roma(t, i, j, "./img/o.xpm");
			j++;
		}
		i++;
	}
	t->img = mlx_xpm_file_to_image(t->mlx, "./img/r.xpm", &t->x, &t->y);
	return (t);
}

void	ft_mv(t_rvars *tr, int i, int j, int keycode)
{
	if (tr->mapo[j / 40][i / 40] == 'C')
	{
		tr->mapo[j / 40][i / 40] = '0';
		tr->coin[0] -= 1;
	}
	if (keycode == 0)
	{
		mlx_put_image_to_window(tr->mlx, tr->win, tr->ib, i + 40, j);
		mlx_put_image_to_window(tr->mlx, tr->win, tr->img, i, j);
	}
	if (keycode == 1)
	{
		mlx_put_image_to_window(tr->mlx, tr->win, tr->ib, i, j - 40);
		mlx_put_image_to_window(tr->mlx, tr->win, tr->img, i, j);
	}
	if (keycode == 2)
	{
		mlx_put_image_to_window(tr->mlx, tr->win, tr->ib, i - 40, j);
		mlx_put_image_to_window(tr->mlx, tr->win, tr->img, i, j);
	}
	if (keycode == 13)
	{
		mlx_put_image_to_window(tr->mlx, tr->win, tr->ib, i, j + 40);
		mlx_put_image_to_window(tr->mlx, tr->win, tr->img, i, j);
	}
}

int	keyft(int keycode, t_rvars *t)
{
	if (keycode == 0 && t->mapo[t->p / 40][(t->t - 40) / 40] != '1')
		if ((t->mapo[t->p / 40][(t->t - 40) / 40] != 'E' || t->coin[0] <= 0))
			if (ft_printf("%d\n", t->i++))
				ft_mv(t, t->t -= 40, t->p, keycode);
	if (keycode == 2 && t->mapo[t->p / 40][(t->t + 40) / 40] != '1' )
		if ((t->mapo[t->p / 40][(t->t + 40) / 40] != 'E' || t->coin[0] <= 0))
			if (ft_printf("%d\n", t->i++))
				ft_mv(t, t->t += 40, t->p, keycode);
	if (keycode == 1 && t->mapo[(t->p + 40) / 40][t->t / 40] != '1' )
		if ((t->mapo[(t->p + 40) / 40][t->t / 40] != 'E' || t->coin[0] <= 0))
			if (ft_printf("%d\n", t->i++))
				ft_mv(t, t->t, t->p += 40, keycode);
	if (keycode == 13 && t->mapo[(t->p - 40) / 40][t->t / 40] != '1' )
		if ((t->mapo[(t->p - 40) / 40][t->t / 40] != 'E' || t->coin[0] <= 0))
			if (ft_printf("%d\n", t->i++))
				ft_mv(t, t->t, t->p -= 40, keycode);
	if (keycode == 53 || t->mapo[(t->p) / 40][t->t / 40] == 'E')
		exit(1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_rvars	ts;
	int		d;
	int		i;
	int		fd;

	i = 0;
	ts.i = 1;
	if (argc == 2 && ft_chr(argv[1] + (len(argv[1]) - 4)))
	{
		d = chek_map(argv[1], &ts);
		ts.mapo = malloc((d + 1) * sizeof(char *));
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			ft_error("file error");
		while (i < d)
			ts.mapo[i++] = get_next_line(fd);
		ts.mlx = mlx_init();
		ts.win = mlx_new_window(ts.mlx, len(ts.mapo[0]) * 40, d * 40, "roma");
		put_img_to_map(&ts, d);
		mlx_key_hook(ts.win, keyft, &ts);
		mlx_hook(ts.win, 17, 0, clos, &ts);
		mlx_loop(ts.mlx);
	}
	else
		ft_error("map :/  ");
}
