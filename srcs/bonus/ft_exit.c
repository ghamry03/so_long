/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 03:48:13 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 12:30:26 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

void	ft_free_maps(t_sl *sl)
{
	int		x;

	x = 0;
	while (sl->map.map[x])
	{	
		free(sl->map.map[x]);
		x++;
	}
	free(sl->map.map[x]);
	free(sl->map.map);
	if (sl->map.big_map)
	{
		x = 0;
		while (sl->map.big_map[x])
		{
			free(sl->map.big_map[x]);
			x++;
		}
		free(sl->map.big_map[x]);
		free(sl->map.big_map);
	}
}

void	ft_free_map_dir(t_sl *sl)
{
	free(sl->map.wall_um);
	free(sl->map.wall_ul);
	free(sl->map.wall_ur);
	free(sl->map.wall_ml);
	free(sl->map.wall_mr);
	free(sl->map.wall_ll);
	free(sl->map.wall_lm);
	free(sl->map.wall_lr);
	free(sl->map.wall_grn);
	free(sl->map.ground);
}

void	ft_death(t_sl *sl)
{
	int			i;
	static int	x;

	x += 0;
	i = x + 9;
	sl->player.i = i;
	if (i == 15)
	{
		ft_red("YOU LOSE\n");
		ft_exit(sl);
	}
	mlx_put_image_to_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr,
		sl->player.player_ptr[sl->player.i],
		sl->player.x, sl->player.y - (i * 4));
	x++;
}

void	ft_free_ptrs(t_sl *sl)
{
	int		i;

	i = -1;
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.ground_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_um_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_ur_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_ml_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_mr_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_lm_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_ll_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_lr_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_grn_ptr);
	if (sl->enemy.count != 0)
	{
		mlx_destroy_image(sl->mlx.mlx_ptr, sl->enemy.enemy_ptr[0]);
		mlx_destroy_image(sl->mlx.mlx_ptr, sl->enemy.enemy_ptr[1]);
		free(sl->enemy.enemy_ptr);
	}
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->coin.coin_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->gate.gate_open_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->gate.gate_close_ptr);
	while (++i < 15)
		mlx_destroy_image(sl->mlx.mlx_ptr, sl->player.player_ptr[i]);
	free(sl->player.player_ptr);
}

void	ft_exit(t_sl *sl)
{
	if (sl->enemy.count != 0)
	{
		free(sl->enemy.x);
		free(sl->enemy.flag);
		free(sl->enemy.y);
	}
	ft_free_maps(sl);
	ft_free_ptrs(sl);
	mlx_destroy_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr);
	free(sl->mlx.mlx_ptr);
	free(sl);
	exit (0);
}
