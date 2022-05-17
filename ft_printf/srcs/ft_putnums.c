/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:49:41 by ommohame          #+#    #+#             */
/*   Updated: 2022/04/16 04:41:17 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_len(int n, int len)
{
	long	i;
	char	tmp;

	i = 10;
	if (n == -2147483648)
	{
		len = ft_putchar_len('-', len);
		len = ft_putchar_len('2', len);
		n = 147483648;
	}
	if (n < 0)
	{
		len = ft_putchar_len('-', len);
		n *= -1;
	}
	while (n >= i)
		i *= 10;
	while (i > 1)
	{
		i /= 10;
		tmp = (n / i) + 48;
		len = ft_putchar_len(tmp, len);
		n %= i;
	}
	return (len);
}

int	ft_unputnbr_len(unsigned int n, int len)
{
	long			i;
	unsigned char	tmp;

	i = 10;
	while (n >= i)
		i *= 10;
	while (i > 1)
	{
		i /= 10;
		tmp = (n / i) + 48;
		len = ft_putchar_len(tmp, len);
		n %= i;
	}
	return (len);
}
