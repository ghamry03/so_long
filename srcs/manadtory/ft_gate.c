/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:00:46 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 12:43:44 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_gate_assets(t_sl *sl)
{
	int		x;
	int		y;

	x = 16;
	y = 16;
	sl->gate.gate_open_dir = ft_strdup("./assets/xpm/gate/gate_open.xpm");
	sl->gate.gate_open_ptr = mlx_xpm_file_to_image(sl->mlx.mlx_ptr,
			sl->gate.gate_open_dir, &x, &y);
	sl->gate.gate_close_dir = ft_strdup("./assets/xpm/gate/gate_close.xpm");
	sl->gate.gate_close_ptr = mlx_xpm_file_to_image(sl->mlx.mlx_ptr,
			sl->gate.gate_close_dir, &x, &y);
	free(sl->gate.gate_open_dir);
	free(sl->gate.gate_close_dir);
}

void	ft_gate_status(int width, int height, t_sl *sl)
{
	if (sl->coin.counter == 0)
		mlx_put_image_to_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr,
			sl->gate.gate_open_ptr, width, height);
	else
		mlx_put_image_to_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr,
			sl->gate.gate_close_ptr, width, height);
}

void	ft_gate(t_sl *sl)
{
	int		i;
	int		x;
	int		width;
	int		height;

	x = -1;
	height = 0;
	sl->coin.counter = 0;
	ft_gate_assets(sl);
	ft_coin(sl);
	while (sl->map.map[++x])
	{
		i = -1;
		width = 0;
		while (sl->map.map[x][++i])
		{
			if (sl->map.map[x][i] == 'E')
				ft_gate_status(width, height, sl);
			width += sl->mlx.width;
		}
		height += sl->mlx.height;
	}
}
