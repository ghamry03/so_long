/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:02:32 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/13 16:55:42 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# define  BUFFER_SIZE	1

size_t	gnl_strlen(const char *s);

char	*gnl_strjoin(char *s1, char *s2);

char	*reallocStr(char *str);

char	*linooo(char *str);

char	*gnl_strchr(const char *s, int c);

char	*reading(char *str, char *bfr, int fd);

char	*get_next_line(int fd);

#endif