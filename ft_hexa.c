/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namrene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:27:43 by namrene           #+#    #+#             */
/*   Updated: 2023/11/15 15:31:58 by namrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned int nb, char x)
{
	char	*base;
	int		i;

	if (x == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	if (nb >= 16)
	{
		i += ft_hexa(nb / 16, x);
		i += ft_hexa(nb % 16, x);
	}
	else
	{
		i += ft_putchar(base[nb]);
	}
	return (i);
}
