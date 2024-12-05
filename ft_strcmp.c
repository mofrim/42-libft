/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:35:26 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/05 18:05:20 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* My strcmp. Protected against NULL pointers. If s1 and s2 == NULL, return 0
 * (as NULL == NULL !). If only one of them == NULL, return 1. For !NULL
 * strings: returns *s1 - *s2 for first unmatching char and 0 if both strings
 * are equal. */
int	ft_strcmp(char	*s1, char *s2)
{
	if (!s1 && !s2)
		return (0);
	if ((!s1 && s2) || (s1 && !s2))
		return (1);
	if (!ft_strlen(s1) && ft_strlen(s2))
		return (-*s2);
	if (ft_strlen(s1) && !ft_strlen(s2))
		return (*s1);
	return (ft_strncmp(s1, s2, ft_strlen(s1)));
}
