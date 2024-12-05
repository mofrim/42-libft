/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:43:50 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/05 01:13:35 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

/*
 * Combined flag or conv char testing func.
 *
 * If you want to test for flagconvness f.ex. use `if(ftfpr_isflagconv(c))`. If
 * only convness of char c should be tested: if(ftfpr_isflagconv(c) == 1)...
 * NOTE: well, actually not 100% clean code. having seperate functions would be
 * cleaner. but i choose compactness over cleanliness here.
 *
 * @param c The char to be tested for flagconvness.
 * @return Returns
 * 			1	if c is a conv char
 * 			2	if c is a flag char
 * 			3	if c is a digit or dot
 */
int	ftfpr_isflagconv(char c)
{
	int	rval;

	rval = 0;
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
			c == 'u' || c == 'x' || c == 'X' || c == '%')
		rval = 1;
	if (c == ' ' || c == '+' || c == '-' || c == '#' || c == '0')
		rval = 2;
	if ((ft_isdigit(c) || c == '.') && c != '0')
		rval = 3;
	return (rval);
}

/*
 * Convert non-negative string of digits to int. Detect possible int overflow.
 *
 * @return -1 if first char is no digit or if number represented by string is
 * bigger than INT_MAX. num in [0, INT_MAX] else.
 */
int	ftfpr_atoi_overflow(const char *s)
{
	long	num;

	num = 0;
	if (!ft_isdigit(*s))
		return (-1);
	while (ft_isdigit(*s))
	{
		num = num * 10 + *s++ - '0';
		if (num > INT_MAX)
			return (-1);
	}
	return ((int)num);
}

/* Return strlen of integer converted to ascii string. */
int	ftfpr_intstrlen(int d)
{
	char	*numstr;
	int		ret;

	numstr = ft_itoa(d);
	if (!numstr)
		return (0);
	ret = ft_strlen(numstr);
	free(numstr);
	return (ret);
}

/* Return strlen of unsigned integer converted to ascii string. */
int	ftfpr_uintstrlen(unsigned int d)
{
	char	*numstr;
	int		ret;

	numstr = ftfpr_utoa(d);
	if (!numstr)
		return (0);
	ret = ft_strlen(numstr);
	free(numstr);
	return (ret);
}

/* Helper function for printing 0x in #-conversion. */
void	ftfpr_print_zerox(int doit, int c, unsigned int num, int fd)
{
	if (!doit || !num)
		return ;
	if (c == 'x')
		ft_putstr_fd("0x", fd);
	if (c == 'X')
		ft_putstr_fd("0X", fd);
}
