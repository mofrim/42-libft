/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:26:13 by fmaurer           #+#    #+#             */
/*   Updated: 2025/05/26 08:02:15 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H
# include "../libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	plus;
	int	minus;
	int	hash;
	int	width;
	int	dot;
	int	prec;
	int	zero;
	int	space;
}	t_flags;

// the main functions
int		ft_dprintf(int fd, const char *f, ...);
int		ftdpr_is_conversion(const char *s);

int		ftdpr_smpl_isconv(const char *s);
int		ftdpr_compl_isconv(const char *s);

int		ftdpr_smpl_convert(va_list args, const char *s, int *r, int fd);
int		ftdpr_gather_flags_and_conv(va_list args, const char *fmt, int *r,
			int fd);

int		ftdpr_compl_do_conv(va_list args, char conv, t_flags *flags, int fd);

// the compl workers
int		ftdpr_compl_converter_d(int d, t_flags *flags, int fd);
int		ftdpr_compl_converter_u(unsigned int d, t_flags *flags, int fd);
int		ftdpr_compl_converter_c(int c, t_flags *flags, int fd);
int		ftdpr_compl_converter_s(char *s, t_flags *fl, int fd);
int		ftdpr_compl_converter_p(unsigned long p, t_flags *fl, int fd);
int		ftdpr_compl_converter_x(unsigned int i, t_flags *fl, int c, int fd);

// the smpl workers
int		ftdpr_converter_d(int i, int fd);
int		ftdpr_converter_u(unsigned int i, int fd);
int		ftdpr_converter_c(int i, int fd);
int		ftdpr_converter_s(char *str, int fd);
int		ftdpr_converter_p(unsigned long l, int fd);
int		ftdpr_converter_x(unsigned int i, int upper, int fd);

// flag related
t_flags	*init_flags(void);

// bonus utils
int		ftdpr_isflagconv(char c);
int		ftdpr_atoi_overflow(const char *s);
int		ftdpr_intstrlen(int d);
int		ftdpr_uintstrlen(unsigned int d);
void	ftdpr_print_zerox(int doit, int c, unsigned int num, int fd);

// smpl utils
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ftdpr_utoa(unsigned int n);
int		ftdpr_hex_digits(unsigned long n);

#endif
