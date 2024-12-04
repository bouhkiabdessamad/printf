/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:59:32 by abouhki           #+#    #+#             */
/*   Updated: 2024/12/03 15:41:43 by abouhki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress(unsigned long nbr)
{
	int		i;
	int		len;
	char	*hex;
	char	buff[17];

	buff[16] = '\0';
	hex = "0123456789abcdef";
	i = 0;
	while (nbr >= 16)
	{
		buff[i++] = hex[nbr % 16];
		nbr = nbr / 16;
	}
	buff[i] = hex[nbr];
	len = i + 1;
	len += write(1, "0x", 2);
	while (i >= 0)
		write(1, &buff[i--], 1);
	return (len);
}
