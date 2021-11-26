/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:14:39 by ade-blas          #+#    #+#             */
/*   Updated: 2021/11/18 19:19:08 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

static int	porc(void)
{
	write(1, "%%", 1);
	return (1);
}

static int	ft_get_percent(va_list percen, char c)
{
	int	cont;

	cont = 0;
	if (c == 'c')
		cont = ft_putchar(va_arg(percen, int));
	else if (c == 's')
		cont = ft_putstr(va_arg(percen, char *));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		cont = ft_puthexa(va_arg(percen, unsigned long int), 1);
		cont += 2;
	}
	else if (c == 'd' || c == 'i')
		cont = ft_putnum(va_arg(percen, int));
	else if (c == 'u')
		cont = ft_putunnum((unsigned int)va_arg(percen, int));
	else if (c == 'x')
		cont = ft_puthexa((unsigned int)va_arg(percen, int), 1);
	else if (c == 'X')
		cont = ft_puthexa((unsigned int)va_arg(percen, int), 2);
	else if (c == '%')
		cont = porc();
	return (cont);
}

int	ft_printf(const char *msg, ...)
{
	va_list	percen;
	int		i;
	char	c;
	int		cont;

	va_start(percen, msg);
	i = 0;
	cont = 0;
	while (msg[i] != '\0')
	{
		if (msg[i] != '%')
		{
			write(1, &msg[i], 1);
			cont++;
		}
		else
		{
			c = msg[i + 1];
			cont = (ft_get_percent(percen, c) + cont);
			i++;
		}
		i++;
	}
	va_end(percen);
	return (cont);
}
