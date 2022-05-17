/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:09:33 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/16 23:40:16 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "so_long.h"

typedef struct s_mlx
{
	int		x;
	int		y;
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	char	**big_map;
	char	*wall_um;
	char	*wall_ul;
	char	*wall_ur;
	char	*wall_ml;
	char	*wall_mr;
	char	*wall_lm;
	char	*wall_ll;
	char	*wall_lr;
	char	*wall_grn;
	char	*ground;
	char	*map_dir;
	void	*ground_ptr;
	void	*wall_um_ptr;
	void	*wall_ul_ptr;
	void	*wall_ur_ptr;
	void	*wall_ml_ptr;
	void	*wall_mr_ptr;
	void	*wall_lm_ptr;
	void	*wall_ll_ptr;
	void	*wall_lr_ptr;
	void	*wall_grn_ptr;
}	t_map;

typedef struct s_map_check
{
	int		gate;
	int		coin;
	int		player;
}	t_map_check;

typedef struct s_player
{
	int		x;
	int		y;
	int		move;
	int		width;
	int		height;
	size_t	count;
	char	*player_dir;
	void	*player_ptr;
}	t_player;

typedef struct s_coin
{
	int		width;
	int		height;
	int		counter;
	char	*coin_dir;
	void	*coin_ptr;
}	t_coin;

typedef struct s_gate
{
	int		width;
	int		height;
	int		x_flag;
	int		y_flag;
	char	*gate_open_dir;
	char	*gate_close_dir;
	void	*gate_open_ptr;
	void	*gate_close_ptr;
}	t_gate;

typedef struct s_sl
{
	int			alloc_flag;
	size_t		w_i;
	size_t		w_x;
	size_t		w_width;
	size_t		w_height;
	t_mlx		mlx;
	t_map		map;
	t_map_check	map_check;
	t_player	player;
	t_coin		coin;
	t_gate		gate;
}	t_sl;

#endif