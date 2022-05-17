/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 03:25:46 by ommohame          #+#    #+#             */
/*   Updated: 2022/05/16 09:59:29 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_b.h"

void	ft_red(char *str)
{
	ft_printf("\033[1;31m");
	ft_printf("%s", str);
}

void	ft_green(char *str)
{
	ft_printf("\033[0;32m");
	ft_printf("%s", str);
}

void	ft_yellow(char *str)
{
	ft_printf("\033[0;33m");
	ft_printf("%s", str);
}
