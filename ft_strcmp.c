/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:35:26 by fmaurer           #+#    #+#             */
/*   Updated: 2025/01/06 08:23:08 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* My strcmp. Protected against NULL pointers. If s1 and s2 == NULL, return 0
 * (as NULL == NULL !). If only one of them == NULL, return 1. For !NULL
 * strings: returns *s1 - *s2 for first unmatching char and 0 if both strings
 * are equal. */
int	ft_strcmp(char	*s1, char *s2)
{
	int	len1;
	int	len2;

	if (!s1 && !s2)
		return (0);
	if ((!s1 && s2) || (s1 && !s2))
		return (1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 < len2)
	{
		if (!ft_strncmp(s1, s2, len1))
			return (-*(s2 + len1));
		else
			return (ft_strncmp(s1, s2, len1));
	}
	if (len1 > len2)
	{
		if (!ft_strncmp(s1, s2, len2))
			return (*(s1 + len2));
		else
			return (ft_strncmp(s1, s2, len2));
	}
	return (ft_strncmp(s1, s2, len1));
}
