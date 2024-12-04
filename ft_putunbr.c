/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:04:28 by abouhki           #+#    #+#             */
/*   Updated: 2024/11/25 18:00:56 by abouhki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 10)
	{
		i += ft_putunbr(nbr / 10);
		i += ft_putunbr(nbr % 10);
	}
	else
		i += ft_putchar(nbr + 48);
	return (i);
}
