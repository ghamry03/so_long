/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:49:46 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 14:04:17 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_exit_gate(int key, t_sl *sl)
{
	if ((key == 13 || key == 0 || key == 1
			|| key == 2) && sl->map.big_map[sl->player.y / sl->player.width]
		[sl->player.x / sl->player.height] == 'E' && sl->coin.counter == 0)
	{
		ft_printf("\033[0;32m");
		ft_printf("YOU WIN\nNNUMBER OF MOVEMENTS: %d\n", sl->player.count);
		ft_exit(sl);
	}
}

void	ft_move_check(int key, t_sl *sl)
{
	ft_exit_gate(key, sl);
	ft_printf("\033[0;33m");
	ft_printf("movement count: %u\n", sl->player.count);
}

int	cross_window(t_sl *sl)
{
	ft_red("YOU LOSE\n");
	ft_exit(sl);
	return (0);
}

int	exit_window(int key, t_sl *sl)
{
	if (key == 12)
	{
		ft_red("YOU LOSE\n");
		ft_exit(sl);
	}
	return (0);
}
