/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:52:04 by abouhki           #+#    #+#             */
/*   Updated: 2024/12/03 15:09:34 by abouhki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *frm, ...);
int		ft_putchar(int c);
int		ft_putnbr(int nbr);
int		ft_putstr(char *str);
int		ft_putunbr(unsigned int nbr);
void	ft_bzero(void *s, size_t len);
int		ft_putadress(unsigned long nbr);
int		ft_puthex(unsigned int nbr, int c);
int		ft_putuhex(unsigned int nbr, int c);

#endif