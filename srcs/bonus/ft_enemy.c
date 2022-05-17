/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:59:42 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 11:44:39 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

void	ft_enemy_assets(t_sl *sl)
{
	int		x;
	int		y;

	x = sl->enemy.width;
	y = sl->enemy.height;
	sl->enemy.enemy_dir = (char **)ft_calloc(3, sizeof(char *));
	sl->enemy.enemy_ptr = (void **)ft_calloc(2, sizeof(void *));
	sl->enemy.enemy_dir[0] = ft_strdup("./assets/xpm/enemy/enemy.xpm");
	sl->enemy.enemy_dir[1] = ft_strdup("./assets/xpm/enemy/enemy_l.xpm");
	sl->enemy.enemy_ptr[0] = mlx_xpm_file_to_image(sl->mlx.mlx_ptr,
			sl->enemy.enemy_dir[0], &x, &y);
	sl->enemy.enemy_ptr[1] = mlx_xpm_file_to_image(sl->mlx.mlx_ptr,
			sl->enemy.enemy_dir[1], &x, &y);
	free (sl->enemy.enemy_dir[0]);
	free (sl->enemy.enemy_dir[1]);
	free (sl->enemy.enemy_dir);
}

void	ft_enemy_count(t_sl *sl)
{
	int		i;
	int		x;

	x = 0;
	while (sl->map.map[x])
	{
		i = 0;
		while (sl->map.map[x][i])
		{
			if (sl->map.map[x][i] == 'X')
				sl->enemy.count++;
			i++;
		}
		x++;
	}
}

void	ft_put_enemy(int width, int height, t_sl *sl)
{
	static int	j;

	j += 0;
	if (sl->alloc_flag == 0)
		ft_enemy_assets(sl);
	mlx_put_image_to_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr,
		sl->enemy.enemy_ptr[0], width, height);
	sl->enemy.x[j] = width;
	sl->enemy.y[j] = height;
	sl->enemy.flag[j] = -1;
	j++;
}

void	ft_enemy(t_sl *sl)
{
	int		i;
	int		x;
	int		width;
	int		height;

	x = -1;
	height = sl->mlx.height / 4;
	ft_enemy_count(sl);
	sl->enemy.flag = (int *)malloc(sizeof(int) * (sl->enemy.count));
	sl->enemy.x = (int *)malloc(sizeof(int) * (sl->enemy.count));
	sl->enemy.y = (int *)malloc(sizeof(int) * (sl->enemy.count));
	if (!sl->enemy.x || !sl->enemy.y)
		ft_exit(sl);
	while (sl->map.map[++x])
	{
		i = -1;
		width = sl->mlx.width / 4;
		while (sl->map.map[x][++i])
		{
			if (sl->map.map[x][i] == 'X')
				ft_put_enemy(width, height, sl);
			width += sl->mlx.width;
		}
		height += sl->mlx.height;
	}
}
