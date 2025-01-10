/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:29:04 by fmaurer           #+#    #+#             */
/*   Updated: 2025/01/10 14:30:55 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return index of s from left with first non-trim-char.
static size_t	fdltrim(const char *s, const char *set)
{
	size_t	i;

	i = 0;
	while (s[i] && ft_strchr(set, s[i]))
		i++;
	return (i);
}

// return index of s from right with first non-trim-char.
// extra safe version were there is no dangere of s being indexed with -1.
// had this before:
// 		while ((len - ++i) >= 0 && ft_strchr(set, s[len - i])) ;
// if condition fails after first test, and does not check 2nd condi, everything
// is fine. but if not...
// also i am trying to be extra careful about size_t's usignedness handling.
// NOTE: is this compiler dependend, that is, any danger at all?
static size_t	fdrtrim(const char *s, const char *set)
{
	size_t	i;
	size_t	len;
	int		go;

	len = ft_strlen(s);
	i = 1;
	go = 1;
	while ((int)(len - i) >= 0 && go)
	{
		if (ft_strchr(set, s[len - i]))
			i++;
		else
			go = 0;
	}
	if ((int)(len - i) < 0)
		return (0);
	return (len - i);
}

/**
 * Trim from the end of string s any char from set.
 *
 * Allocates (with malloc(3)) and returns a copy of
 * ’s1’ with the characters specified in ’set’ removed
 * from the beginning and the end of the string.
 *
 * @param	s	The string to be trimmed.
 * @param	set	The reference set of characters to trim.
 * @return	The trimmed string or NULL if something goes wrong.
 *
 * @example
 * 	ft_strtrim("42 School\n", "\n");
 */
char	*ft_strtrim(char const *s, char const *set)
{
	char		*tri;
	size_t		start;
	size_t		end;
	size_t		i;

	if (!s)
		return (NULL);
	if (!set)
		return (ft_strdup(s));
	start = fdltrim(s, set);
	end = fdrtrim(s, set);
	if (end == 0 && start == ft_strlen(s))
		return (ft_strdup(""));
	tri = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!tri)
		return (NULL);
	ft_bzero(tri, end - start + 2);
	i = -1;
	while (++i <= end - start)
		tri[i] = s[start + i];
	return (tri);
}
