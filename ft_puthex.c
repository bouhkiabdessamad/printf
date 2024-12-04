/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:47:21 by abouhki           #+#    #+#             */
/*   Updated: 2024/12/03 16:40:21 by abouhki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr, int c)
{
	int		i;
	int		len;
	char	*hex;
	char	buff[9];

	buff[8] = '\0';
	hex = "0123456789abcdef";
	i = 0;
	if (nbr == 0)
		return (len = write(1, "0", 1));
	while (nbr >= 16)
	{
		buff[i++] = hex[nbr % 16];
		nbr = nbr / 16;
	}
	buff[i] = hex[nbr];
	len = i + 1;
	if (c == 1)
		len += write(1, "0x", 2);
	while (i >= 0)
		write(1, &buff[i--], 1);
	return (len);
}
