/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:58:29 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 12:58:35 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_player(t_sl *sl)
{
	int		i;
	int		x;
	int		width;
	int		height;

	x = -1;
	height = sl->mlx.height / 4;
	ft_player_assets(sl);
	while (sl->map.map[++x])
	{
		i = -1;
		width = sl->mlx.width / 4;
		while (sl->map.map[x][++i])
		{
			if (sl->map.map[x][i] == 'P')
			{
				mlx_put_image_to_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr,
					sl->player.player_ptr, width, height);
				sl->player.x = width;
				sl->player.y = height;
			}
			width += sl->mlx.width;
		}
		height += sl->mlx.height;
	}
}

void	ft_move_player_y(int key, t_sl *sl)
{
	if (key == 13)
	{
		ft_move_player_up(sl);
		ft_move_check(key, sl);
	}
	else if (key == 1)
	{
		ft_move_player_down(sl);
		ft_move_check(key, sl);
	}
}

void	ft_move_player_x(int key, t_sl *sl)
{
	if (key == 2)
	{
		ft_move_player_right(sl);
		ft_move_check(key, sl);
	}
	else if (key == 0)
	{
		ft_move_player_left(sl);
		ft_move_check(key, sl);
	}
}

int	ft_move_player(int key, t_sl *sl)
{
	ft_move_player_x(key, sl);
	ft_move_player_y(key, sl);
	mlx_clear_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr);
	ft_build_map(sl);
	ft_collect_coin(sl);
	ft_gate(sl);
	mlx_put_image_to_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr,
		sl->player.player_ptr, sl->player.x, sl->player.y);
	return (key);
}
