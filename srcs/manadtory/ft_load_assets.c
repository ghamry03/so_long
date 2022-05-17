/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:23:56 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 12:40:32 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_map_assets_dir(t_sl *sl)
{
	sl->map.ground = ft_strdup("./assets/xpm/map/ground.xpm");
	sl->map.wall_um = ft_strdup("./assets/xpm/map/wall_tm.xpm");
	sl->map.wall_ul = ft_strdup("./assets/xpm/map/wall_tl.xpm");
	sl->map.wall_ur = ft_strdup("./assets/xpm/map/wall_tr.xpm");
	sl->map.wall_ml = ft_strdup("./assets/xpm/map/wall_ml.xpm");
	sl->map.wall_mr = ft_strdup("./assets/xpm/map/wall_mr.xpm");
	sl->map.wall_lm = ft_strdup("./assets/xpm/map/wall_bm.xpm");
	sl->map.wall_ll = ft_strdup("./assets/xpm/map/wall_bl.xpm");
	sl->map.wall_lr = ft_strdup("./assets/xpm/map/wall_br.xpm");
	sl->map.wall_grn = ft_strdup("./assets/xpm/map/wall.xpm");
}

void	ft_map_assets(t_sl *sl)
{
	ft_map_assets_dir(sl);
	sl->map.ground_ptr = mlx_xpm_file_to_image(sl->mlx.mlx_ptr,
			sl->map.ground, &sl->map.width, &sl->map.height);
	sl->map.wall_um_ptr = mlx_xpm_file_to_image(sl->mlx.mlx_ptr,
			sl->map.wall_um, &sl->map.width, &sl->map.height);
	sl->map.wall_ul_ptr = mlx_xpm_file_to_image(sl->mlx.mlx_ptr,
			sl->map.wall_ul, &sl->map.width, &sl->map.height);
	sl->map.wall_ur_ptr = mlx_xpm_file_to_image(sl->mlx.mlx_ptr,
			sl->map.wall_ur, &sl->map.width, &sl->map.height);
	sl->map.wall_ml_ptr = mlx_xpm_file_to_image(sl->mlx.mlx_ptr,
			sl->map.wall_ml, &sl->map.width, &sl->map.height);
	sl->map.wall_mr_ptr = mlx_xpm_file_to_image(sl->mlx.mlx_ptr,
			sl->map.wall_mr, &sl->map.width, &sl->map.height);
	sl->map.wall_lm_ptr = mlx_xpm_file_to_image(sl->mlx.mlx_ptr,
			sl->map.wall_lm, &sl->map.width, &sl->map.height);
	sl->map.wall_ll_ptr = mlx_xpm_file_to_image(sl->mlx.mlx_ptr,
			sl->map.wall_ll, &sl->map.width, &sl->map.height);
	sl->map.wall_lr_ptr = mlx_xpm_file_to_image(sl->mlx.mlx_ptr,
			sl->map.wall_lr, &sl->map.width, &sl->map.height);
	sl->map.wall_grn_ptr = mlx_xpm_file_to_image(sl->mlx.mlx_ptr,
			sl->map.wall_grn, &sl->map.width, &sl->map.height);
	ft_free_dir(sl);
}

void	ft_player_assets(t_sl *sl)
{
	int		x;
	int		y;

	x = sl->player.width;
	y = sl->player.height;
	sl->player.player_dir = ft_strdup("./assets/xpm/player/player.xpm");
	sl->player.player_ptr = mlx_xpm_file_to_image(sl->mlx.mlx_ptr,
			sl->player.player_dir, &x, &y);
	free(sl->player.player_dir);
}
