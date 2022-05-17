/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:15:20 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 11:18:34 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

void	ft_move_enemy_right(int i, t_sl *sl)
{
	int		y;
	int		new_y;
	int		new_x;
	int		ht;

	y = sl->enemy.y[i];
	new_y = y + sl->enemy.height - 1;
	new_x = sl->enemy.x[i] + sl->enemy.move;
	ht = sl->enemy.height;
	if (sl->map.big_map[y / ht][new_x / ht + 1] == '1' && new_x % ht != 0)
	{
		sl->enemy.flag[i] = 1;
		return ;
	}
	else
	{
		if (sl->map.big_map[new_y / ht][new_x / ht] == '1' && new_x % ht != 0)
		{
			sl->enemy.flag[i] = 1;
			return ;
		}
		else
			sl->enemy.x[i] = new_x;
		sl->enemy.flag[i] = 0;
	}
}

void	ft_move_enemy_left(int i, t_sl *sl)
{
	int		y;
	int		new_y;
	int		new_x;
	int		ht;

	y = sl->enemy.y[i];
	new_y = y + sl->enemy.height - 1;
	new_x = sl->enemy.x[i] - sl->enemy.move;
	ht = sl->enemy.height;
	if (sl->map.big_map[y / ht][new_x / ht] == '1' && new_x % ht != 0)
	{
		sl->enemy.flag[i] = 0;
		return ;
	}
	else
	{
		if (sl->map.big_map[new_y / ht][new_x / ht] == '1' && new_x % ht != 0)
		{
			sl->enemy.flag[i] = 0;
			return ;
		}
		else
			sl->enemy.x[i] = new_x;
		sl->enemy.flag[i] = 1;
	}
}

	// if ((s_player.x == s_enemy.x[i] - 16 && s_player.y == s_enemy.y[i] + 16)
	// 	|| (s_player.x - 32 == s_enemy.x[i] && s_player.y == s_enemy.y[i] + 16))
	// if (((s_player.x == s_enemy.x[i] || s_player.x + 8 == s_enemy.x[i]
	// 			|| s_player.x + 16 == s_enemy.x[i]
	// 			|| s_player.x + 24 == s_enemy.x[i]
	// 			|| s_player.x + 32 == s_enemy.x[i])
	// 		&& (s_player.y == s_enemy.y[i]
	// 			|| s_player.y + 8 == s_enemy.y[i]
	// 			|| s_player.y + 16 == s_enemy.y[i]
	// 			|| s_player.y + 24 == s_enemy.y[i]
	// 			|| s_player.y + 32 == s_enemy.y[i]))
	// 	|| (((s_player.x == s_enemy.x[i]
	// 				|| s_player.x - 8 == s_enemy.x[i]
	// 				|| s_player.x - 16 == s_enemy.x[i]
	// 				|| s_player.x - 24 == s_enemy.x[i]
	// 				|| s_player.x - 32 == s_enemy.x[i])
	// 			&& (s_player.y == s_enemy.y[i]
	// 				|| s_player.y - 8 == s_enemy.y[i]
	// 				|| s_player.y - 16 == s_enemy.y[i]
	// 				|| s_player.y - 24 == s_enemy.y[i]
	// 				|| s_player.y - 32 == s_enemy.y[i]))))

void	ft_kill_player_v2(int i, t_sl *sl)
{
	int		p_x;
	int		p_y;

	p_x = sl->player.x;
	p_y = sl->player.y;
	while (p_y > sl->player.y - sl->player.height)
	{
		if (p_y == sl->enemy.y[i])
		{
			while (p_x < sl->player.x + sl->player.width)
			{
				if (p_x == sl->enemy.x[i])
					sl->player.death = 1;
				p_x++;
			}
			p_x = sl->player.x;
			while (p_x > sl->player.x - sl->player.width)
			{
				if (p_x == sl->enemy.x[i])
					sl->player.death = 1;
				p_x--;
			}
		}
		p_y--;
	}
}

void	ft_kill_player(int i, t_sl *sl)
{
	int		p_x;
	int		p_y;

	p_x = sl->player.x;
	p_y = sl->player.y;
	while (p_y < sl->player.y + sl->player.height)
	{
		if (p_y == sl->enemy.y[i])
		{
			while (p_x < sl->player.x + sl->player.width)
			{
				if (p_x == sl->enemy.x[i])
					sl->player.death = 1;
				p_x++;
			}
			p_x = sl->player.x + 1;
			while (--p_x > sl->player.x - sl->player.width)
			{
				if (p_x == sl->enemy.x[i])
					sl->player.death = 1;
			}
		}
		p_y++;
	}
	ft_kill_player_v2(i, sl);
}

void	ft_move_enemy(t_sl *sl)
{
	int		i;

	i = 0;
	while (i < sl->enemy.count)
	{
		if (sl->enemy.flag[i] != 1 && sl->enemy.flag[i] != 0)
		{
			if (i % 2 == 1)
				sl->enemy.flag[i] = 0;
			else
				sl->enemy.flag[i] = 1;
		}
		if (sl->enemy.flag[i] == 0)
			ft_move_enemy_right(i, sl);
		else
			ft_move_enemy_left(i, sl);
		mlx_put_image_to_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr,
			sl->enemy.enemy_ptr[sl->enemy.flag[i]],
			sl->enemy.x[i], sl->enemy.y[i]);
		ft_kill_player(i, sl);
		i++;
	}
}
