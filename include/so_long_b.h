/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_b.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:05:02 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 14:02:26 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_B_H
# define SO_LONG_B_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "structure_b.h"
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define UP 13
# define A_UP 126
# define LEFT 0
# define A_LEFT 123
# define RIGHT 2
# define A_RIGHT 124
# define DOWN 1
# define A_DOWN 125
# define SPACE 49
# define Q 12

void	so_long(t_sl *sl);

void	ft_map(char *av, t_sl *sl);
void	ft_map_assets(t_sl *sl);
void	ft_map_assets_dir(t_sl *sl);
void	ft_dimensions(t_sl *sl);
void	ft_read_map(char *str, t_sl *sl);
void	ft_check_map_width(t_sl *sl);
void	ft_big_map_height(t_sl *sl);
void	ft_build_map(t_sl *sl);
void	ft_map_check(t_sl *sl);
void	ft_map_check_invalid(t_sl *sl);
int		ft_map_check_char(char *c, size_t counter, size_t x, t_sl *sl);
void	ft_big_map_width(size_t x, size_t z, t_sl *sl);
void	ft_walls(t_sl *sl);
void	ft_top_walls(t_sl *sl);
void	ft_bot_walls(t_sl *sl);
void	ft_side_walls(t_sl *sl);

void	ft_coin(t_sl *sl);
void	ft_coin_check(t_sl *sl);
void	ft_coin_assets(t_sl *sl);
void	ft_collect_coin(t_sl *sl);

void	ft_player(t_sl *sl);
void	ft_player_assets(t_sl *sl);
void	ft_player_check(t_sl *sl);
void	ft_move_player_x(int key, t_sl *sl);
void	ft_move_player_right(t_sl *sl);
void	ft_move_player_left(t_sl *sl);
void	ft_move_player_y(int key, t_sl *sl);
void	ft_move_player_up(void);
void	ft_move_player_down(t_sl *sl);
int		ft_move_player(int key, t_sl *sl);

void	ft_gate(t_sl *sl);
void	ft_gate_check(t_sl *sl);
void	ft_gate_assets(t_sl *sl);
void	ft_exit_gate(int key, t_sl *sl);

void	ft_red(char *str);
void	ft_green(char *str);
void	ft_yellow(char *str);

void	ft_exit(t_sl *sl);
void	ft_free_map_dir(t_sl *sl);
void	ft_free_maps(t_sl *sl);

int		ft_jump(int key, t_sl *sl);
void	ft_jump_up(t_sl *sl);
void	ft_jump_down(t_sl *sl);

int		ft_render(t_sl *sl);
int		ft_gravity(t_sl *sl);

void	ft_enemy_assets(t_sl *sl);
void	ft_enemy(t_sl *sl);
void	ft_enemy_count(t_sl *sl);
void	ft_put_enemy(int width, int height, t_sl *sl);

void	ft_move_enemy(t_sl *sl);
void	ft_move_enemy_right(int i, t_sl *sl);
void	ft_move_enemy_left(int i, t_sl *sl);

int		exit_window(int key, t_sl *sl);
int		cross_window(t_sl *sl);

void	ft_death(t_sl *sl);
void	ft_movecount(t_sl *sl);

#endif
