/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:07:57 by cclaude           #+#    #+#             */
/*   Updated: 2019/10/31 17:26:54 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

struct	s_flgs
{
	int minus;
	int zero;
	int dot;
	int precision;
	int width;
};

int		ft_putchar_minwid(char c, int width);
int		ft_putchar_zerowid(char c, int width);
int		ft_putchar_wid(char c, int width);
int		ft_putchar(char c);

int		ft_strlen(char *s);
int		ft_putstr_prewid(char *s, struct s_flgs flags);
int		ft_putstr_wid(char *s, struct s_flgs flags);
int		ft_putstr_pre(char *s, int prec);
int		ft_putstr(char *s);

int		ft_plen(unsigned long n);
int		ft_putmem_prewid(unsigned long n, struct s_flgs flags);
int		ft_putmem_wid(unsigned long n, struct s_flgs flags);
int		ft_putmem_pre(unsigned long n, struct s_flgs flags);
int		ft_putmem(unsigned long n, int start);

int		ft_nbrlen(long n);
int		ft_putnbr_prewid(long n, struct s_flgs flags);
int		ft_putnbr_pre(long n, struct s_flgs flags);
int		ft_putnbr_wid(long n, struct s_flgs flags);
int		ft_putnbr(long n);

int		ft_print_char(char c, struct s_flgs flags);
int		ft_print_str(char *s, struct s_flgs flags);
int		ft_print_mem(unsigned long n, int start, struct s_flgs flags);
int		ft_print_nbr(long n, struct s_flgs flags);

int		ft_print_uns(unsigned int n, struct s_flgs flags);
int		ft_print_hex(unsigned int n, struct s_flgs flags);
int		ft_print_hexcap(unsigned int n, struct s_flgs flags);
int		ft_print_percent(void);

int		is_end_flag(const char c);
int		is_valid_flag(const char c);
int		ft_atoi_star(const char *s, int *i, va_list args);
void	flagger(const char *s, int *i, struct s_flgs *flags, va_list args);

int		func_branch(const char *s, int *i, va_list args);
int		ft_printf(const char *string, ...);
#endif
