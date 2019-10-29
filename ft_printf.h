/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:07:57 by cclaude           #+#    #+#             */
/*   Updated: 2019/10/29 11:44:43 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

struct fl_gs
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

int		ft_print_char(char c, struct fl_gs flags);
int		ft_print_str(char *s, struct fl_gs flags);
int		ft_print_mem(unsigned long n, int start, struct fl_gs flags);
int		ft_print_nbr(int n, struct fl_gs flags);
int		ft_print_uns(unsigned int n, struct fl_gs flags);
int		ft_print_hex(unsigned int n, struct fl_gs flags);
int		ft_print_hexcap(unsigned int n, struct fl_gs flags);

int		is_end_flag(const char c);
int		is_valid_flag(const char c);
int		ft_atoi_star(const char *s, int *i, va_list args);
void	flagger(const char *s, int *i, struct fl_gs *flags, va_list args);
int		func_branch(const char *s, int *i, va_list args);
int		ft_printf(const char *string, ...);
#endif
