/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:37:01 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 12:47:10 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_big_map_width(size_t x, size_t z, t_sl *sl)
{
	size_t		i;
	size_t		j;
	size_t		y;
	size_t		ratio;

	i = 0;
	y = 0;
	ratio = sl->mlx.width / sl->player.width;
	sl->map.big_map[z] = (char *)malloc(sizeof(char)
			* (ft_strlen(sl->map.map[x]) * ratio) + 1);
	if (!sl->map.big_map[z])
		exit (0);
	while (sl->map.map[x][y])
	{
		j = 0;
		while (j < ratio)
		{
			sl->map.big_map[z][i] = sl->map.map[x][y];
			i++;
			j++;
		}
		y++;
	}
	sl->map.big_map[i] = 0;
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
	sl->map.big_map = (char **)malloc(sizeof(char *)
			* ((tmp * i) + 1));
	if (!sl->map.big_map)
		exit (0);
	tmp = i;
	i = -1;
	while (sl->map.map[++x])
	{
		j = -1;
		while (++j < tmp)
			ft_big_map_width(x, ++i, sl);
	}
	sl->map.big_map[i] = 0;
}
