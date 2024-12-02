/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:48:15 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/02 18:51:03 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The  strdup()  function  returns  a  pointer to a new string which is a
// duplicate of the string s.  Memory for the new string is obtained with mal‐
// loc(3), and can be freed with free(3).
//
// On success, the strdup() function returns a pointer to the duplicated string.
// It returns NULL if insufficient memory was available, with errno set to
// indicate the error.
//
// ERRORS
//    ENOMEM Insufficient memory available to allocate duplicate string.
char	*ft_strdup(const char *str)
{
	char	*dupl;
	int		i;

	if (!str)
		return (NULL);
	dupl = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!dupl)
		return (NULL);
	i = -1;
	while (str[++i])
		dupl[i] = str[i];
	dupl[i] = '\0';
	return (dupl);
}
