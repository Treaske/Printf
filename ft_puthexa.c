/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:25:32 by ade-blas          #+#    #+#             */
/*   Updated: 2021/11/16 18:05:47 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	leng(unsigned long long c)
{
	int	cont;

	cont = 0;
	while (c >= 16)
	{
		c = c / 16;
		cont++;
	}
	cont++;
	return (cont);
}

static char	putnum(unsigned long long rest, int letter)
{
	char	num;

	num = 'o';
	if (rest <= 9)
		num = 48 + rest;
	else if (rest > 9)
	{
		if (letter == 1)
			num = 96 + (rest - 9);
		else if (letter == 2)
			num = 64 + (rest - 9);
	}
	return (num);
}

static void	turn(char *hexa, int cont)
{
	int	i;

	i = 0;
	while (hexa[i] != 0)
	{
		write(1, &hexa[cont - 1], 1);
		cont--;
		i++;
	}
}

int	ft_puthexa(unsigned long long c, int letter)
{
	unsigned long long		rest;
	char					*hexa;
	long					cont;

	cont = leng(c);
	hexa = malloc(sizeof(char) * cont + 1);
	if (!hexa || c == 0)
	{
		write(1, &"0", 1);
		free(hexa);
		return (1);
	}
	hexa[cont] = 0;
	rest = 0;
	cont = 0;
	while (c != 0)
	{
		rest = c % 16;
		c = c / 16;
		hexa[cont] = putnum(rest, letter);
		cont++;
	}
	turn(hexa, cont);
	free(hexa);
	return (cont);
}
