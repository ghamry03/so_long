/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 03:48:13 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 12:56:55 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_free_map(t_sl *sl)
{
	int		x;

	x = -1;
	while (sl->map.map[++x])
		free(sl->map.map[x]);
	free(sl->map.map);
}

void	ft_free_big_map(t_sl *sl)
{
	int		x;

	x = -1;
	while (sl->map.big_map[++x])
		free(sl->map.big_map[x]);
	free(sl->map.big_map);
}

void	ft_free_dir(t_sl *sl)
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

void	ft_free_ptr(t_sl *sl)
{
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_um_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_ul_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_ur_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_ml_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_mr_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_ll_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_lm_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_lr_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.wall_grn_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->map.ground_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->player.player_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->coin.coin_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->gate.gate_close_ptr);
	mlx_destroy_image(sl->mlx.mlx_ptr, sl->gate.gate_open_ptr);
}

void	ft_exit(t_sl *sl)
{
	ft_free_map(sl);
	ft_free_big_map(sl);
	ft_free_ptr(sl);
	mlx_destroy_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr);
	free(sl->mlx.mlx_ptr);
	free(sl);
	exit (0);
}
