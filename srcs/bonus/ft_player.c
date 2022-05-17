/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:58:29 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 11:12:34 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

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
					sl->player.player_ptr[0], width, height);
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
	if (key == DOWN || key == A_DOWN)
	{
		ft_move_player_down(sl);
		ft_exit_gate(key, sl);
	}
}

void	ft_move_player_x(int key, t_sl *sl)
{
	if (key == RIGHT || key == A_RIGHT)
	{
		ft_move_player_right(sl);
		ft_exit_gate(key, sl);
		if (sl->player.i >= 4)
			sl->player.i = 1;
		else if (key == RIGHT || key == A_RIGHT)
			sl->player.i++;
	}
	else if (key == LEFT || key == A_LEFT)
	{
		ft_move_player_left(sl);
		ft_exit_gate(key, sl);
		if (sl->player.i >= 8 || sl->player.i < 4)
			sl->player.i = 5;
		else if (key == LEFT || key == A_LEFT)
			sl->player.i++;
	}
}

int	ft_jump(int key, t_sl *sl)
{
	exit_window(key, sl);
	if (key == SPACE || key == UP || key == A_UP)
	{
		if (sl->player.jmp_flg != 1)
		{
			sl->player.jmp_flg = 1;
			sl->player.count++;
		}
	}
	return (key);
}

int	ft_move_player(int key, t_sl *sl)
{
	if (sl->player.i == 9)
		sl->player.i = 0;
	ft_move_player_x(key, sl);
	ft_move_player_y(key, sl);
	return (key);
}
