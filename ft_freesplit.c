/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:02:49 by fmaurer           #+#    #+#             */
/*   Updated: 2025/04/22 11:17:01 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Free a split. Set the param to NULL to avoid accidental use of it later on in
 * the program. */
void	ft_freesplit(char ***split)
{
	char	**tmp;

	tmp = *split;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(*split);
	*split = NULL;
}
