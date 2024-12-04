/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:41:04 by abouhki           #+#    #+#             */
/*   Updated: 2024/12/03 16:40:27 by abouhki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuhex(unsigned int nbr, int c)
{
	int		i;
	int		len;
	char	*hex_u;
	char	buff[9];

	buff[8] = '\0';
	hex_u = "0123456789ABCDEF";
	i = 0;
	if (nbr == 0)
		return (len = write(1, "0", 1));
	while (nbr >= 16)
	{
		buff[i++] = hex_u[nbr % 16];
		nbr = nbr / 16;
	}
	buff[i] = hex_u[nbr];
	len = i + 1;
	if (c == 1)
		len += write(1, "0X", 2);
	while (i >= 0)
		write(1, &buff[i--], 1);
	return (len);
}
