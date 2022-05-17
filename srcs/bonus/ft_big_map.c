/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:37:01 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/16 19:24:25 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

void	ft_big_map_width(size_t x, size_t z, t_sl *sl)
{
	size_t		i;
	size_t		j;
	size_t		y;
	size_t		ratio;

	i = 0;
	y = -1;
	ratio = sl->mlx.width / sl->player.width;
	sl->map.big_map[z] = (char *)ft_calloc(
			((ft_strlen(sl->map.map[x]) * ratio) + 1), sizeof(char));
	if (!sl->map.big_map[z])
	{
		ft_free_maps(sl);
		exit (0);
	}
	while (sl->map.map[x][++y])
	{
		j = 0;
		while (j < ratio)
		{
			sl->map.big_map[z][i] = sl->map.map[x][y];
			i++;
			j++;
		}
	}
}

void	ft_big_map_height(t_sl *sl)
{
	size_t		i;
	size_t		j;
	size_t		x;
	size_t		tmp;

	x = -1;
	i = sl->mlx.height / sl->player.height;
	tmp = 0;
	while (sl->map.map[tmp])
		tmp++;
	sl->map.big_map = (char **)ft_calloc(((tmp * i) + 1), sizeof(char *));
	if (!sl->map.big_map)
	{
		ft_free_maps(sl);
		exit (0);
	}
	tmp = i;
	i = 0;
	while (sl->map.map[++x])
	{
		j = 0;
		while (j++ < tmp)
			ft_big_map_width(x, i++, sl);
	}
	sl->map.big_map[i] = 0;
}
