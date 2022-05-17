/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:24:27 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/15 21:15:50 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reading(char *str, char *bfr, int fd)
{
	int		ret;

	ret = read(fd, bfr, BUFFER_SIZE);
	if (ret == -1)
	{
		free (bfr);
		return (NULL);
	}
	bfr[ret] = 0;
	str = gnl_strjoin(str, bfr);
	while (ret != 0)
	{
		ret = read(fd, bfr, BUFFER_SIZE);
		if (ret == -1)
		{
			free (bfr);
			return (NULL);
		}
		bfr[ret] = 0;
		str = gnl_strjoin(str, bfr);
	}
	free(bfr);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*bfr;
	static char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bfr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bfr)
		return (NULL);
	str = reading(str, bfr, fd);
	if (!str)
		return (NULL);
	return (str);
}
