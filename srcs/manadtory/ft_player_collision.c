/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_collision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 01:37:39 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/16 10:55:22 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_move_player_right(t_sl *sl)
{
	int		y;
	int		new_y;
	int		new_x;
	int		ht;

	y = sl->player.y;
	new_y = y + sl->player.height - 1;
	ht = sl->player.height;
	new_x = sl->player.x + sl->player.move;
	if (sl->map.big_map[y / ht][new_x / ht + 1] == '1' && new_x % ht != 0)
		return ;
	else
	{
		if (sl->map.big_map[new_y / ht][new_x / ht + 1] == '1'
				&& new_x % ht != 0)
			return ;
		else
		{
			sl->player.x = new_x;
			sl->player.count++;
		}
	}
}

void	ft_move_player_left(t_sl *sl)
{
	int		y;
	int		new_y;
	int		new_x;
	int		ht;

	y = sl->player.y;
	new_y = y + sl->player.height - 1;
	ht = sl->player.height;
	new_x = sl->player.x - sl->player.move;
	if (sl->map.big_map[y / ht][new_x / ht] == '1' && new_x % ht != 0)
		return ;
	else
	{
		if (sl->map.big_map[new_y / ht][new_x / ht] == '1' && new_x % ht != 0)
			return ;
		else
		{
			sl->player.x = new_x;
			sl->player.count++;
		}
	}
}

void	ft_move_player_up(t_sl *sl)
{
	int		x;
	int		new_x;
	int		new_y;
	int		wd;

	x = sl->player.x;
	wd = sl->player.width;
	new_y = sl->player.y - sl->player.move;
	new_x = sl->player.x + sl->player.width - 1;
	if (sl->map.big_map[new_y / wd][x / wd] == '1' && new_y % wd != 0)
		return ;
	else
	{
		if (sl->map.big_map[new_y / wd][new_x / wd] == '1' && new_y % wd != 0)
			return ;
		else
		{
			sl->player.y = new_y;
			sl->player.count++;
		}
	}
}

void	ft_move_player_down(t_sl *sl)
{
	int		x;
	int		new_x;
	int		new_y;
	int		wd;

	x = sl->player.x;
	wd = sl->player.width;
	new_y = sl->player.y + sl->player.move;
	new_x = sl->player.x + sl->player.width - 1;
	if (sl->map.big_map[new_y / wd + 1][x / wd] == '1' && new_y % wd != 0)
		return ;
	else
	{
		if (sl->map.big_map[new_y / wd + 1][new_x / wd] == '1'
				&& new_y % wd != 0)
			return ;
		else
		{
			sl->player.y = new_y;
			sl->player.count++;
		}
	}
}
