/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:55:26 by abouhki           #+#    #+#             */
/*   Updated: 2024/12/03 17:45:22 by abouhki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_chdx(va_list args, char pr)
{
	if (pr == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (pr == 'X')
		return (ft_putuhex(va_arg(args, unsigned int), 0));
	else if (pr == 'd')
		return (ft_putnbr(va_arg(args, int)));
	return (0);
}

int	ft_shp(va_list args, char pr, char *d)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if ((d[0] == ' ' || d[1] == '+') && (pr == 'd'))
	{
		i = va_arg(args, int);
		if (i >= 0 && d[1] == '+')
			len += write(1, "+", 1);
		else if (i >= 0 && d[0] == ' ')
			len += write(1, " ", 1);
		return (len += ft_putnbr(i));
	}
	else if (d[2] == '#' && pr == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (d[2] == '#' && pr == 'X')
		return (ft_putuhex(va_arg(args, unsigned int), 1));
	return (ft_chdx(args, pr));
}

int	ft_chpr(const char *frm, va_list args, int *i, char *d)
{
	while (frm[++(*i)])
	{
		if (frm[*i] == ' ')
			d[0] = ' ';
		else if (frm[*i] == '+')
			d[1] = '+';
		else if (frm[*i] == '#')
			d[2] = '#';
		if (frm[*i] == 's')
			return (ft_putstr(va_arg(args, char *)));
		else if (frm[*i] == 'd' || frm[*i] == 'i')
			return (ft_shp(args, 'd', d));
		else if (frm[*i] == 'u')
			return (ft_putunbr(va_arg(args, unsigned int)));
		else if (frm[*i] == 'p')
			return (ft_putadress(va_arg(args, unsigned long)));
		else if (frm[*i] == 'x' || frm[*i] == 'X')
			return (ft_shp(args, frm[*i], d));
		else if (frm[*i] == 'c')
			return (ft_putchar(va_arg(args, int)));
		else if (frm[*i] != '+' && frm[*i] != ' ' && frm[*i] != '#')
			return (ft_putchar(frm[*i]));
	}
	return (0);
}

int	ft_printf(const char *frm, ...)
{
	int		i;
	char	d[4];
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(args, frm);
	while (frm[i])
	{
		if (frm[i] == '%')
		{
			ft_bzero(d, 4);
			len += ft_chpr(frm, args, &i, d);
		}
		else
			len += ft_putchar(frm[i]);
		if (frm[i] != '\0')
			i++;
	}
	va_end(args);
	return (len);
}
