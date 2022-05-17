/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:49:46 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 11:14:05 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

void	ft_exit_gate(int key, t_sl *sl)
{
	if ((key == UP || key == A_UP || key == SPACE
			|| key == DOWN || key == A_DOWN || key == RIGHT
			|| key == A_RIGHT || key == LEFT || key == A_LEFT)
		&& sl->map.big_map[sl->player.y / sl->player.width]
		[sl->player.x / sl->player.height] == 'E' && sl->coin.counter == 0)
	{
		ft_printf("\033[0;32m");
		ft_printf("YOU WIN\nNNUMBER OF MOVEMENTS: %d\n", sl->player.count);
		ft_exit(sl);
	}
}

void	ft_movecount(t_sl *sl)
{
	char	*tmp;
	char	*str;

	tmp = ft_itoa(sl->player.count);
	str = ft_strjoin("movement count: ", tmp);
	mlx_string_put(sl->mlx.mlx_ptr, sl->mlx.win_ptr, 10, 10,
		0x00FF0000, str);
	free(tmp);
	free(str);
}

int	exit_window(int key, t_sl *sl)
{
	if (key == Q)
	{
		ft_red("YOU LOSE\n");
		ft_exit(sl);
	}
	return (0);
}

int	cross_window(t_sl *sl)
{
	ft_red("YOU LOSE\n");
	ft_exit(sl);
	return (0);
}
