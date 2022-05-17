/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:27:02 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/16 09:59:11 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

// void	ft_jump_up(void)
// {
// 	int		x;
// 	int		new_x;
// 	int		new_y;
// 	int		wd;

// 	x = s_player.x;
// 	wd = s_player.width;
// 	new_y = s_player.y - s_player.move;
// 	new_x = s_player.x + s_player.width - 1;
// 	if (s_map.big_map[new_y / wd][x / wd] == '1' && new_y % wd != 0)
// 		return ;
// 	else
// 	{
// 		if (s_map.big_map[new_y / wd][new_x / wd] == '1' && new_y % wd != 0)
// 			return ;
// 		else
// 			s_player.y = new_y;
// 	}
// }

// void	ft_jump_down(t_sl *sl)
// {
// 	int		x;
// 	int		new_x;
// 	int		new_y;
// 	int		wd;

// 	x = s_player.x;
// 	wd = s_player.width;
// 	new_y = s_player.y + s_player.move;
// 	new_x = s_player.x + s_player.width - 1;
// 	if (s_map.big_map[new_y / wd + 1][x / wd] == '1' && new_y % wd != 0)
// 		return ;
// 	else
// 	{
// 		if (s_map.big_map[new_y / wd + 1][new_x / wd] == '1' && new_y % wd != 0)
// 			return ;
// 		else
// 			s_player.y = new_y;
// 	}
// }

// void	ft_jump_up(void)
// {
// 	int		i;
// 	int		x;
// 	int		new_x;
// 	int		new_y;
// 	int		wd;

// 	x = s_player.x;
// 	wd = s_player.width;
// 	new_y = s_mlx.height + (s_mlx.height / 4);
// 	new_x = s_player.x + s_player.width - 1;
// 	i = -1;
// 	if (s_map.big_map[new_y / wd][x / wd] == '1' && new_y % wd != 0)
// 		return ;
// 	else
// 	{
// 		if (s_map.big_map[new_y / wd][new_x / wd] == '1' && new_y % wd != 0)
// 			return ;
// 		else
// 		{
// 			while (++i < s_mlx.height + (s_mlx.height / 4))
// 						s_player.y -= 1;
// 			s_player.jmp_flg = 0;
// 		}
// 	}
// }
void	ft_jump_up(t_sl *sl)
{
	int			x;
	int			new_x;
	int			new_y;
	int			wd;
	static int	i;

	i += 0;
	x = sl->player.x;
	wd = sl->player.width;
	new_y = sl->player.y - 16;
	new_x = sl->player.x + sl->player.width - 1;
	if (i >= sl->mlx.height + (sl->mlx.height / 4))
	{
		i = 0;
		sl->player.jmp_flg = 0;
	}
	else if (sl->map.big_map[new_y / wd][x / wd] == '1' && new_y % wd != 0)
		sl->player.jmp_flg = 0;
	else
		if (sl->map.big_map[new_y / wd][new_x / wd] == '1' && new_y % wd != 0)
			sl->player.jmp_flg = 0;
	else
			sl->player.y = new_y;
	ft_exit_gate(DOWN, sl);
	i += 16;
}

int	ft_gravity(t_sl *sl)
{
	int		x;
	int		new_x;
	int		new_y;
	int		wd;

	x = sl->player.x;
	wd = sl->player.width;
	new_y = sl->player.y + 16;
	new_x = sl->player.x + sl->player.width -1;
	if (sl->map.big_map[new_y / wd + 1][x / wd] == '1' && new_y % wd != 0)
		return (0);
	else
	{
		if (sl->map.big_map[new_y / wd + 1][new_x / wd] == '1'
			&& new_y % wd != 0)
			return (0);
		else
			sl->player.y = new_y;
		ft_exit_gate(DOWN, sl);
	}
	return (1);
}
