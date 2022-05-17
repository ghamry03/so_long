/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:02:27 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/17 15:57:09 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;
	char	*ch;

	ch = (char *)s;
	if (!ch)
		return (NULL);
	i = 0;
	while (ch[i])
	{
		if (ch[i] == (unsigned char)c)
			return (ch + i);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	i = -1;
	j = -1;
	str = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = 0;
	free (s1);
	return (str);
}
