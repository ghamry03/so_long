/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:51:59 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 13:00:50 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	so_long(t_sl *sl)
{
	sl->mlx.mlx_ptr = mlx_init();
	sl->mlx.win_ptr = mlx_new_window(sl->mlx.mlx_ptr, sl->map.width,
			sl->map.height, "so_long");
	ft_build_map(sl);
	ft_big_map_height(sl);
	ft_player(sl);
	ft_coin(sl);
	ft_gate(sl);
	mlx_hook(sl->mlx.win_ptr, 2, 0, ft_move_player, sl);
	mlx_key_hook(sl->mlx.win_ptr, exit_window, sl);
	mlx_hook(sl->mlx.win_ptr, 17, (1L << 0), cross_window, sl);
	mlx_loop(sl->mlx.mlx_ptr);
}

void	ft_dimensions(t_sl *sl)
{
	sl->player.count = 0;
	sl->mlx.width = 64;
	sl->mlx.height = 64;
	sl->coin.width = 32;
	sl->coin.height = 32;
	sl->gate.width = 64;
	sl->gate.height = 64;
	sl->player.width = 32;
	sl->player.height = 32;
	sl->player.move = 16;
	sl->map_check.gate = 0;
	sl->map_check.player = 0;
	sl->map_check.coin = 0;
}

int	main(int ac, char **av)
{
	t_sl	*sl;

	if (ac != 2)
	{
		ft_red("YOU SHOULD ONLY ENTER THE MAP NAME\n");
		return (0);
	}
	sl = malloc(sizeof(t_sl));
	ft_dimensions(sl);
	ft_map(av, sl);
	so_long(sl);
	return (0);
}
