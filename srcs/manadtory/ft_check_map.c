/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:40:02 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 12:32:03 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_map_check_char(char *c, size_t counter, size_t x, t_sl *sl)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (sl->map.map[x][i])
	{
		j = 0;
		while (c[j])
		{
			if (c[j] == sl->map.map[x][i])
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

void	ft_map_check_invalid(t_sl *sl)
{
	size_t	x;
	size_t	counter;
	char	*c;

	x = 0;
	counter = 0;
	c = ft_strdup("10PCE");
	while (sl->map.map[x])
	{
		counter = ft_map_check_char(c, counter, x, sl);
		x++;
	}
	free(c);
	if (counter != (size_t)(sl->map.width * sl->map.height))
	{
		ft_red("MAP ERROR: INVALID CHARACTER\n");
		exit (0);
	}
}
