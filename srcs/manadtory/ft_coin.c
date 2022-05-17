/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:31:54 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 12:41:57 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_coin_assets(t_sl *sl)
{
	int		x;
	int		y;

	x = 16;
	y = 16;
	sl->coin.coin_dir = ft_strdup("./assets/xpm/collectable/collectable.xpm");
	sl->coin.coin_ptr = mlx_xpm_file_to_image(sl->mlx.mlx_ptr,
			sl->coin.coin_dir, &x, &y);
	free(sl->coin.coin_dir);
}

void	ft_coin(t_sl *sl)
{
	int		i;
	int		x;
	int		width;
	int		height;

	x = -1;
	height = sl->mlx.height / 4;
	sl->coin.counter = 0;
	ft_coin_assets(sl);
	while (sl->map.map[++x])
	{
		i = -1;
		width = sl->mlx.height / 4;
		while (sl->map.map[x][++i])
		{
			if (sl->map.map[x][i] == 'C')
			{
				mlx_put_image_to_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr,
					sl->coin.coin_ptr, width, height);
				sl->coin.counter++;
			}
			width += sl->mlx.width;
		}
		height += sl->mlx.height;
	}
}

void	ft_collect_coin(t_sl *sl)
{
	int	x;
	int	y;
	int	ht;
	int	wd;

	x = sl->player.x;
	y = sl->player.y;
	wd = sl->mlx.width;
	ht = sl->mlx.height;
	if (sl->map.map[y / wd][x / ht] == 'C')
	{
		sl->map.map[y / wd][x / ht] = '0';
		sl->coin.counter--;
	}
	ft_coin(sl);
}
