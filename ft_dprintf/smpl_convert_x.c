/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smpl_convert_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:03:27 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/23 18:22:49 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static char	*hextoa_uint(unsigned int n, int upper);

static int	hex_digits_uint(unsigned int n);

/* Print smpl 'x' conversion. */
int	ftdpr_converter_x(unsigned int i, int upper, int fd)
{
	char	*num;
	int		r;

	if (upper)
		num = hextoa_uint(i, 1);
	else
		num = hextoa_uint(i, 0);
	ft_putstr_fd(num, fd);
	r = ft_strlen(num);
	free(num);
	return (r);
}

/* Helper func. Count hex digits of unsigned int. */
static int	hex_digits_uint(unsigned int n)
{
	int	d;

	if (!n)
		return (1);
	d = 0;
	while (n)
	{
		n /= 16;
		d++;
	}
	return (d);
}

/* Helper func. Print hex upper/lowercase digits of unsigned int. */
static char	*hextoa_uint(unsigned int n, int upper)
{
	char	*a;
	int		i;

	i = hex_digits_uint(n);
	a = (char *)malloc(i * sizeof (char) + 1);
	if (!a)
		return (NULL);
	a[i] = '\0';
	while (--i >= 0)
	{
		if (n % 16 < 10)
			a[i] = '0' + n % 16;
		else if (upper)
			a[i] = 'A' + (n % 16 - 10);
		else
			a[i] = 'a' + (n % 16 - 10);
		n /= 16;
	}
	return (a);
}
