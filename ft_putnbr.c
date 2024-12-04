/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:33:46 by abouhki           #+#    #+#             */
/*   Updated: 2024/11/28 17:33:55 by abouhki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
		i += write(1, "-2147483648", 11);
	else if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
		i += ft_putnbr(nbr) + 1;
	}
	else if (nbr >= 10)
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putnbr(nbr % 10);
	}
	else
		i += ft_putchar(nbr + 48);
	return (i);
}
