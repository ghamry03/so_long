/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:26:45 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/16 22:52:03 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

void	ft_top_walls(t_sl *sl)
{
	if (sl->w_x == 0)
	{
		if (sl->w_i == 0)
			mlx_put_image_to_window(sl->mlx.mlx_ptr,
				sl->mlx.win_ptr, sl->map.wall_ul_ptr,
				sl->w_height, sl->w_width);
		else if (sl->w_i == ft_strlen(sl->map.map[0]) - 1)
			mlx_put_image_to_window(sl->mlx.mlx_ptr,
				sl->mlx.win_ptr, sl->map.wall_ur_ptr,
				sl->w_height, sl->w_width);
		else
			mlx_put_image_to_window(sl->mlx.mlx_ptr,
				sl->mlx.win_ptr, sl->map.wall_um_ptr,
				sl->w_height, sl->w_width);
	}
}

void	ft_bot_walls(t_sl *sl)
{
	size_t	j;

	j = 0;
	while (sl->map.map[j + 1])
		j++;
	if (sl->w_x == j)
	{
		if (sl->w_i == 0)
			mlx_put_image_to_window(sl->mlx.mlx_ptr,
				sl->mlx.win_ptr, sl->map.wall_ll_ptr,
				sl->w_height, sl->w_width);
		else if (sl->w_i == ft_strlen(sl->map.map[0]) - 1)
			mlx_put_image_to_window(sl->mlx.mlx_ptr,
				sl->mlx.win_ptr, sl->map.wall_lr_ptr,
				sl->w_height, sl->w_width);
		else
			mlx_put_image_to_window(sl->mlx.mlx_ptr,
				sl->mlx.win_ptr, sl->map.wall_lm_ptr,
				sl->w_height, sl->w_width);
	}
}

void	ft_side_walls(t_sl *sl)
{
	size_t	j;

	j = 0;
	while (sl->map.map[j + 1])
		j++;
	if (sl->w_x != 0 && sl->w_x != j)
	{
		if (sl->w_i == 0)
			mlx_put_image_to_window(sl->mlx.mlx_ptr,
				sl->mlx.win_ptr, sl->map.wall_ml_ptr,
				sl->w_height, sl->w_width);
		else if (sl->w_i == ft_strlen(sl->map.map[0]) - 1)
			mlx_put_image_to_window(sl->mlx.mlx_ptr,
				sl->mlx.win_ptr, sl->map.wall_mr_ptr,
				sl->w_height, sl->w_width);
		else
			mlx_put_image_to_window(sl->mlx.mlx_ptr,
				sl->mlx.win_ptr, sl->map.wall_grn_ptr,
				sl->w_height, sl->w_width);
	}
}

void	ft_walls(t_sl *sl)
{
	ft_top_walls(sl);
	ft_bot_walls(sl);
	ft_side_walls(sl);
}
