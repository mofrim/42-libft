/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smpl_convert_cdsi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:18:16 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/23 18:22:49 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

/* Print smpl 'i' conversion. */
int	ftdpr_converter_i(int i, int fd)
{
	char	*num;
	int		r;

	num = ft_itoa(i);
	ft_putstr_fd(num, fd);
	r = ft_strlen(num);
	free(num);
	return (r);
}

/* Print smpl 'd' conversion. */
int	ftdpr_converter_d(int i, int fd)
{
	char	*num;
	int		r;

	num = ft_itoa(i);
	ft_putstr_fd(num, fd);
	r = ft_strlen(num);
	free(num);
	return (r);
}

/* Print smpl 'u' conversion. */
int	ftdpr_converter_u(unsigned int i, int fd)
{
	char	*num;
	int		r;

	num = ftdpr_utoa(i);
	ft_putstr_fd(num, fd);
	r = ft_strlen(num);
	free(num);
	return (r);
}

/* Print smpl 'c' conversion. */
int	ftdpr_converter_c(int i, int fd)
{
	ft_putchar_fd(i, fd);
	return (1);
}

/* Print smpl 's' conversion. */
int	ftdpr_converter_s(char *str, int fd)
{
	if (!str)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}
