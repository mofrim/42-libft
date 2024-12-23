/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_flag_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:17:08 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/23 18:22:49 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

/* Initialize the t_flags struct with all zeros. */
t_flags	*init_flags(void)
{
	t_flags	*flags;

	flags = (t_flags *) malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->plus = 0;
	flags->minus = 0;
	flags->hash = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->prec = 0;
	flags->zero = 0;
	flags->space = 0;
	return (flags);
}
