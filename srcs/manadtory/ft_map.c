/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:56:32 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 14:04:06 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_read_map(char *str, t_sl *sl)
{
	int		fd;
	char	*map_tmp;

	str = ft_strjoin(str, ".ber");
	sl->map.map_dir = ft_strjoin("./maps/", str);
	fd = open(sl->map.map_dir, O_RDONLY);
	map_tmp = get_next_line(fd);
	if (!map_tmp || fd == -1)
	{
		ft_red("INVALID MAP\n");
		exit(0);
	}
	free(str);
	sl->map.map = ft_split(map_tmp, '\n');
	free(sl->map.map_dir);
	free(map_tmp);
}

void	ft_check_map_width(t_sl *sl)
{
	size_t	i;
	size_t	j;
	int		x;

	x = -1;
	i = 0;
	j = 0;
	while (sl->map.map[0][i] == 49)
		i++;
	while (sl->map.map[++x])
	{
		if (!sl->map.map[x + 1])
		{
			while (sl->map.map[x][j] == 49)
				j++;
		}
	}
	if (i == j && i == ft_strlen(sl->map.map[0]))
		sl->map.width = i;
	else
	{
		ft_red("MAP ERROR: MISSING WALLS\n");
		ft_free_map(sl);
		exit(0);
	}
}

void	ft_check_map_height(t_sl *sl)
{
	int		i;
	int		j;
	int		x;
	int		y;

	x = 0;
	y = sl->map.width - 1;
	i = 0;
	while (sl->map.map[x])
	{
		j = ft_strlen(sl->map.map[x]) - 1;
		if (sl->map.map[x][0] == 49 && sl->map.map[x][j] == 49 && y == j)
			i++;
		x++;
	}
	if (i == x)
		sl->map.height = i;
	else
	{
		ft_red("MAP ERROR: MISSING WALLSSSSS\n");
		ft_free_map(sl);
		exit(0);
	}
}

void	ft_map(char **av, t_sl *sl)
{
	ft_read_map(av[1], sl);
	ft_map_check(sl);
	ft_check_map_width(sl);
	ft_check_map_height(sl);
	ft_map_check_invalid(sl);
	sl->map.height *= sl->mlx.height;
	sl->map.width *= sl->mlx.width;
}

void	ft_build_map(t_sl *sl)
{
	sl->w_x = 0;
	sl->w_width = 0;
	if (sl->alloc_flag == 0)
		ft_map_assets(sl);
	while (sl->map.map[sl->w_x])
	{
		sl->w_i = 0;
		sl->w_height = 0;
		while (sl->map.map[sl->w_x][sl->w_i])
		{
			mlx_put_image_to_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr,
				sl->map.ground_ptr, sl->w_height, sl->w_width);
			if (sl->map.map[sl->w_x][sl->w_i] == 49)
				ft_walls(sl);
			sl->w_height += sl->mlx.height;
			sl->w_i++;
		}
		sl->w_width += sl->mlx.width;
		sl->w_x++;
	}
}
