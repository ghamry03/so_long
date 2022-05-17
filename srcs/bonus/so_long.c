/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:51:59 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 11:17:11 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

int	ft_render(t_sl *sl)
{
	mlx_clear_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr);
	ft_build_map(sl);
	ft_collect_coin(sl);
	ft_gate(sl);
	if (sl->player.jmp_flg == 1 && sl->player.death != 1)
		ft_jump_up(sl);
	else if (sl->player.death != 1)
		ft_gravity(sl);
	else if (sl->player.death == 1)
		ft_death(sl);
	ft_move_enemy(sl);
	if (sl->player.death != 1)
		mlx_put_image_to_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr,
			sl->player.player_ptr[sl->player.i], sl->player.x, sl->player.y);
	ft_movecount(sl);
	return (0);
}

void	so_long_v2(t_sl *sl)
{
	ft_build_map(sl);
	ft_big_map_height(sl);
	ft_player(sl);
	ft_gate(sl);
	ft_enemy(sl);
}

void	so_long(t_sl *sl)
{
	sl->mlx.mlx_ptr = mlx_init();
	if (!sl->mlx.mlx_ptr)
	{
		ft_red("INVALID DISPLAY\n");
		exit (0);
	}
	sl->mlx.win_ptr = mlx_new_window(sl->mlx.mlx_ptr, sl->map.width,
			sl->map.height, "so_long");
	if (!sl->mlx.win_ptr)
	{
		ft_red("INVALID DISPLAY\n");
		exit (0);
	}
	so_long_v2(sl);
	if (sl->player.death != 1)
	{
		mlx_hook(sl->mlx.win_ptr, 2, 0, ft_move_player, sl);
		mlx_key_hook(sl->mlx.win_ptr, ft_jump, sl);
		mlx_hook(sl->mlx.win_ptr, 17, (1L << 0), cross_window, sl);
	}
	mlx_loop_hook(sl->mlx.mlx_ptr, ft_render, sl);
	sl->alloc_flag = 1;
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
	sl->player.i = 0;
	sl->player.jmp_flg = 0;
	sl->enemy.width = 32;
	sl->enemy.height = 32;
	sl->enemy.count = 0;
	sl->enemy.move = 4;
	sl->map_check.gate = 0;
	sl->map_check.player = 0;
	sl->map_check.coin = 0;
	sl->alloc_flag = 0;
	sl->coin.counter = 0;
	sl->player.death = 0;
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
	if (!sl)
		exit(0);
	ft_dimensions(sl);
	ft_map(av[1], sl);
	so_long(sl);
	return (0);
}
