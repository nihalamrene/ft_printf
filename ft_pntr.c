/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pntr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namrene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:10:58 by namrene           #+#    #+#             */
/*   Updated: 2023/11/15 18:20:20 by namrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_hex(unsigned long l, int isFirstDigit)
{
	char	*base;
	int		i; 

	base = "0123456789abcdef";
	i = 0; 
	if (l >= 16)
	{
		i += ft_hex(l / 16, isFirstDigit);
		i += ft_hex(l % 16, 0);
	}
	else
	{
		if (isFirstDigit)
		{
			ft_putchar('0');
			ft_putchar('x');
			i += 2; 
		}
		ft_putchar(base[l]); 
		i++; 
	}
	return (i);
}

int	ft_pntr(void *p)
{
	unsigned long	l;

	l = (unsigned long)p;
	return (ft_hex(l, 1)); 
}
