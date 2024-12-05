/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smpl_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:39:47 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/05 00:17:58 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

/* Output one char to stdout. */
void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}

/* Output string to stdout. */
void	ft_putstr(char *s)
{
	ft_putstr_fd(s, 1);
}
