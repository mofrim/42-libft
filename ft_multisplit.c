/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multisplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:14:06 by fmaurer           #+#    #+#             */
/*   Updated: 2025/01/21 00:40:13 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* determine length of split at hand. */
static int	splitlen(const char *s, char *splitchars)
{
	int		k;
	size_t	sclen;

	k = 0;
	sclen = ft_strlen(splitchars);
	while (!ft_memchr(splitchars, *s, sclen) && *s)
	{
		s++;
		k++;
	}
	return (k);
}

/* number of splits in string given.
 * init splits = 1 because we return at least str unsplit.
 * return 0 if str is empty or if only splits where found in s.
 * do not count substrings of length 0!! */
static int	numofsplits(const char *s, char *splitchars)
{
	int		splits;
	int		onlysplits;
	size_t	sclen;

	if (!*s || !splitchars)
		return (0);
	splits = 1;
	onlysplits = 1;
	sclen = ft_strlen(splitchars);
	while (*s)
	{
		if (!ft_memchr(splitchars, *s, sclen))
			onlysplits = 0;
		if (ft_memchr(splitchars, *s, sclen) && !ft_memchr(splitchars,
				*(s + 1), sclen) && *(s + 1) && !onlysplits)
			splits++;
		s++;
	}
	return (splits * (!onlysplits));
}

/* free all subarrays helper function in case subarray allocation goes wrong.
 * tbh: seems a bit optional to me. how to fail malloc? */
void	*free2stars(char **arr, int k)
{
	int	i;

	i = -1;
	while (++i < k)
		free(arr[i]);
	free(arr);
	return (NULL);
}

/* inner loop split function. responsible for substring-array allocation. if
 * anything goes wrong returns 0 for processing in ft_split func. */
static int	copy_split(const char **s, char **substrs, char *splitchars, int i)
{
	char	*substr_ptr;
	size_t	sclen;

	substrs[i] = (char *) malloc(sizeof(char) * (splitlen(*s, splitchars) + 1));
	if (!substrs[i])
		return (0);
	sclen = ft_strlen(splitchars);
	substr_ptr = substrs[i];
	while (!ft_memchr(splitchars, **s, sclen) && **s)
	{
		*substr_ptr = **s;
		(*s)++;
		substr_ptr++;
	}
	*substr_ptr = '\0';
	return (1);
}

/**
 * Split string s by a splitchar chracterset.
 *
 * To be called with the ft_strlen(splitchars) as 3rd arg!
 *
 * Example:
 * 		
 * 		ft_multisplit("abc.defg;hij'", ".;'") -> {"abc", "defg", "hij"}
 */
char	**ft_multisplit(char const *s, char *splitchars, size_t sclen)
{
	char	**substrs;
	int		nsplits;
	int		i;
	int		ok;

	if (!splitchars || !s || sclen != ft_strlen(splitchars))
		return (NULL);
	nsplits = numofsplits(s, splitchars);
	substrs = (char **)malloc(sizeof(char *) * (nsplits + 1));
	if (!substrs)
		return (NULL);
	i = -1;
	ok = 1;
	while (++i < nsplits && ok)
	{
		while (ft_memchr(splitchars, *s, sclen) && (*s != 0))
			s++;
		if (splitlen(s, splitchars))
			ok = copy_split(&s, substrs, splitchars, i);
	}
	if (!ok)
		return (free2stars(substrs, i - 1));
	substrs[nsplits] = NULL;
	return (substrs);
}
