/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smpl_utoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:49:37 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/23 18:22:49 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

/* Counts and returns num of digits of unsigned int param. */
static int	dec(unsigned int n)
{
	int	d;

	if (!n)
		return (1);
	d = 0;
	while (n)
	{
		n /= 10;
		d++;
	}
	return (d);
}

/* Returns digit char string of param unsigned int. */
char	*ftdpr_utoa(unsigned int n)
{
	char	*a;
	int		i;

	i = dec(n);
	a = (char *)malloc(i * sizeof (char) + 1);
	if (!a)
		return (NULL);
	a[i] = '\0';
	while (--i >= 0)
	{
		a[i] = '0' + n % 10;
		n /= 10;
	}
	return (a);
}
