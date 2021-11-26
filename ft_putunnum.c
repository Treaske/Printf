/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:25:21 by ade-blas          #+#    #+#             */
/*   Updated: 2021/11/16 16:34:02 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	leng(unsigned long long n)
{
	int			len;
	long int	n2;

	n2 = (long) n;
	len = 0;
	while (n2 > 0)
	{
		n2 = n2 / 10;
		len++;
	}
	if (n == 0)
		len = 1;
	return (len);
}

static int	positive(unsigned long long c, int cont)
{
	char	*num;

	num = malloc(sizeof (int) * cont + 1);
	if (!num)
		return (0);
	num[cont] = 0;
	while (c > 0)
	{
		num[cont - 1] = 48 + (c % 10);
		c = c / 10;
		cont--;
	}
	while (num[cont])
	{
		write(1, &num[cont], 1);
		cont++;
	}
	free(num);
	return (cont);
}

int	ft_putunnum(unsigned long long c)
{
	int		cont;
	int		cont2;
	char	num;

	num = '0';
	cont2 = 0;
	cont = leng(c);
	if (c == 0)
		write(1, &num, 1);
	else if (c > 0)
		cont2 = positive(c, cont);
	return (cont);
}
