/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:08:51 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 15:53:10 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

void	ft_gate_check(t_sl *sl)
{
	int		i;
	int		x;

	x = -1;
	while (sl->map.map[++x])
	{
		i = -1;
		while (sl->map.map[x][++i])
		{
			if (sl->map.map[x][i] == 'E')
				sl->map_check.gate++;
		}
	}
	if (sl->map_check.gate != 1)
	{
		ft_red("MAP ERROR: INVALID NUMBER OF EXITS\n");
		free(sl->map.map_dir);
		exit(0);
	}
}

void	ft_player_check(t_sl *sl)
{
	int		i;
	int		x;

	x = -1;
	while (sl->map.map[++x])
	{
		i = -1;
		while (sl->map.map[x][++i])
		{
			if (sl->map.map[x][i] == 'P')
				sl->map_check.player++;
		}
	}
	if (sl->map_check.player != 1)
	{
		ft_red("MAP ERROR: INVALID NUMBER OF PLAYERS\n");
		free(sl->map.map_dir);
		exit(0);
	}
}

void	ft_coin_check(t_sl *sl)
{
	int		i;
	int		x;

	x = -1;
	sl->map_check.coin = 0;
	while (sl->map.map[++x])
	{
		i = -1;
		while (sl->map.map[x][++i])
		{
			if (sl->map.map[x][i] == 'C')
				sl->map_check.coin++;
		}
	}
	if (sl->map_check.coin == 0)
	{
		ft_red("MAP ERROR: COLLECTABLES ARE LESS THAN ONE\n");
		free(sl->map.map_dir);
		exit(0);
	}
}

void	ft_map_check(t_sl *sl)
{
	ft_gate_check(sl);
	ft_player_check(sl);
	ft_coin_check(sl);
}
