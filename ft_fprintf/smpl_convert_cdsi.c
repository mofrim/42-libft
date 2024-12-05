/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smpl_convert_cdsi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:18:16 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/05 01:08:15 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

/* Print smpl 'i' conversion. */
int	ftfpr_converter_i(int i, int fd)
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
int	ftfpr_converter_d(int i, int fd)
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
int	ftfpr_converter_u(unsigned int i, int fd)
{
	char	*num;
	int		r;

	num = ftfpr_utoa(i);
	ft_putstr_fd(num, fd);
	r = ft_strlen(num);
	free(num);
	return (r);
}

/* Print smpl 'c' conversion. */
int	ftfpr_converter_c(int i, int fd)
{
	ft_putchar_fd(i, fd);
	return (1);
}

/* Print smpl 's' conversion. */
int	ftfpr_converter_s(char *str, int fd)
{
	if (!str)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}
