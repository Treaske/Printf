/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:11:05 by ade-blas          #+#    #+#             */
/*   Updated: 2021/11/18 16:58:09 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int			ft_putchar(char c);
int			ft_putstr(char *c);
int			ft_puthexa(unsigned long long c, int letter);
int			ft_putnum(int c);
int			ft_putunnum(unsigned long long c);
int			ft_printf(const char *msg, ...);

#endif
