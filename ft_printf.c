/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namrene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:21:16 by namrene           #+#    #+#             */
/*   Updated: 2023/11/15 18:43:27 by namrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namrene <namrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:26:54 by namrene           #+#    #+#             */
/*   Updated: 2023/11/15 17:55:18 by namrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	pr_function(va_list ar, const char f)
{
	int	i;

	i = 0;
	if (f == 'c')
		i += ft_putchar(va_arg(ar, int));
	else if (f == 's')
		i += ft_putstr(va_arg(ar, char *));
	else if (f == 'p')
		i += ft_pntr(va_arg(ar, void *));
	else if (f == 'd' || f == 'i')
		i += ft_putnbr(va_arg(ar, int));
	else if (f == 'u')
		i += ft_unsg(va_arg(ar, unsigned int));
	else if (f == 'x' || f == 'X')
		i += ft_hexa(va_arg(ar, unsigned int), f);
	else 
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *f, ...)
{
	va_list	ar;
	int		i;
	int		leng;

	va_start(ar, f);
	i = 0;
	leng = 0;
	if (write(1, "", 0) < 0)
		return (-1);
	while (f[i])
	{
		if (f[i] == '%')
		{
			i++;
			leng += pr_function(ar, f[i]);
		}
		else
			leng += ft_putchar(f[i]);
		if (f[i])
			i++;
	}
	va_end(ar);
	return (leng);
}
