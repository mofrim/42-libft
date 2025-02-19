/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_is_conv_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:45:16 by fmaurer           #+#    #+#             */
/*   Updated: 2024/12/23 18:22:49 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
/*
 * Determine if we have a smpl, compl or no conv starting from *s.
 *
 * Check if substr at `s` is a simple conv or flagged conv
 * Return Values:
 * 		0	no conv
 * 		1	only simple conv needed
 * 	   -1	complex conversion
 *
 */
int	ftdpr_is_conversion(const char *s)
{
	if (ftdpr_smpl_isconv(s))
		return (1);
	if (*s == '%' && ftdpr_compl_isconv(s) == 1)
		return (-1);
	return (0);
}

/*
 * Check if the conv-sequence at hand is VALID, INVALID or WRONG.
 *
 * Return Values:
 * 		1	VALID & CORRECT sequence
 * 		0	WRONG or INCOMPLETE but not invalid sequence
 * 	   -1	INVALID sequence -> no output at all, ft_printf returns -1
 *
 * ::The Rules... at least some important ones::
 *
 * i)  	 a '%' can be followed by any mix of '+- 0#'
 * ii)   BUT after the first number != 0 OR a '.' there can only be
 * iii)	 more numbers (UP TO INT_MAX)
 * iv) 	 NO 2 DOTS! ONLY ONE DOT ALLOWED!!
 * v) 	 if the first thing was a number, there can be a dot followed by another
 *     	 number, or simply a dot
 * vi)	 after a '.' only a number and the conv_spec are allowed
 * vii)	 the '%' conversion can have any valid combination of flags (including
 *     	 width and prec) in between first % and final %. the final % can be
 *     	 followed by valid conv_char, it still will be printed like %%.
 * viii) a '0' after a '.' is ingored but valid
 * ix)	 IF there is a invalid sequence at the end of fmtstring nothing will
 * 		 be printed, not even preceeding valid characters or conversions
 * 		 and -1 has to be returned!
 * x)	 there must not be any width or prec numbers bigger than INT_MAX in the
 * 		 conversion string. this would be an INVALID FMTSTRING!!!
 *
 * NOTE: WRONG sequences lead to parts of or the whole sequence being printed.
 * but there are lot of combinations where the ignored or doubled stuff is not
 * printed even though it has no effect.
 *
 * NOTE: *s is pointing to the first '%' in the conversion string of interest.
 * so the loop starts looking at the first char after the %
 *
 */
int	ftdpr_compl_isconv(const char *s)
{
	int	num;
	int	dot;

	num = 0;
	dot = 0;
	while (*(++s))
	{
		if (!ftdpr_isflagconv(*s))
			return (0);
		if (ftdpr_isflagconv(*s) == 2 && *s != '0' && (num || dot))
			return (0);
		if (*s == '.' && dot)
			return (0);
		if (ftdpr_isflagconv(*s) == 1)
			return (1);
		if (ft_isdigit(*s) && !num && *s != '0')
			num = 1;
		if (ft_isdigit(*s) && *s != '0' && ftdpr_atoi_overflow(s) == -1)
			return (-1);
		if (*s == '.')
			dot = 1;
	}
	return (-1);
}
