/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:33:29 by fmaurer           #+#    #+#             */
/*   Updated: 2025/01/05 14:18:17 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copy string src to dest. Copies up to size - 1 chars to dest! Always
 * 0-terminates dest if size > 0. If size == 0 does nothing.
 * Remark: strlcpy is safer than strncpy bc it always ensures 0-termination, so
 * prefer using strlcpy.
 * This libft-version also does a NULL-check on both src or dest to prevent
 * segfaults. If any == NULL returns 0.*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (!size)
		return (len);
	if (!dst || !src)
		return (0);
	if (size == 1)
	{
		*dst = '\0';
		return (len);
	}
	while (--size && *src)
		*(dst++) = *(src++);
	*(dst++) = '\0';
	return (len);
}
