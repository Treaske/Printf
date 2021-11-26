/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:22:42 by ade-blas          #+#    #+#             */
/*   Updated: 2021/11/16 16:32:19 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	donull(void)
{
	write(1, &"(null)", 6);
}

int	ft_putstr(char *c)
{
	int		cont;

	cont = 0;
	if (!c || c == NULL)
	{
		cont = 6;
		donull();
		return (cont);
	}
	else
	{
		while (c[cont])
		{
			write(1, &c[cont], 1);
			cont++;
		}
	}
	return (cont);
}
