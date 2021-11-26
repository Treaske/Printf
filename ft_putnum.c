/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:23:10 by ade-blas          #+#    #+#             */
/*   Updated: 2021/11/16 16:31:47 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	leng(int n)
{
	int			len;
	long int	n2;

	n2 = (long) n;
	len = 0;
	if (n2 < 0)
	{
		n2 = n2 * -1;
		len++;
	}
	while (n2 > 0)
	{
		n2 = n2 / 10;
		len++;
	}
	if (n == 0)
		len = 1;
	return (len);
}

static int	positive(int c, int cont)
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

static int	negative(int c, int cont)
{
	long int	min;
	char		*num;

	num = malloc(sizeof (int) * cont + 1);
	if (!num)
		return (0);
	num[cont] = 0;
	min = (long) c;
	num[0] = '-';
	write(1, &num[0], 1);
	min = min * -1;
	while (min > 0)
	{
		num[cont - 1] = 48 + (min % 10);
		min = min / 10;
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

int	ft_putnum(int c)
{
	int		cont;
	char	num;
	int		cont2;

	num = '0';
	cont2 = 0;
	cont = leng(c);
	if (c == 0)
		write(1, &num, 1);
	else if (c > 0)
		cont2 = positive(c, cont);
	else if (c < 0)
		cont2 = negative(c, cont);
	return (cont);
}
