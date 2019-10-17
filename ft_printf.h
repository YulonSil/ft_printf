/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:07:57 by cclaude           #+#    #+#             */
/*   Updated: 2019/10/17 17:34:14 by cclaude          ###   ########.fr       */
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
	int star;
	int width;
};

void	ft_print_char(char c, struct fl_gs flags);
void	ft_print_str(char *s, struct fl_gs flags);
void	ft_print_mem(unsigned long n, int start, struct fl_gs flags);
void	ft_print_nbr(int n, struct fl_gs flags);
void	ft_print_uns(unsigned int n, struct fl_gs flags);
void	ft_print_hex(unsigned int n, struct fl_gs flags);
void	ft_print_hexcap(unsigned int n, struct fl_gs flags);
int		is_end_flag(const char c);
int		is_valid_flag(const char c);
int		ft_atoi(const char *str, int *i);
void	flagger(const char *s, int *i, struct fl_gs *flags);
void	func_branch(const char *s, int *i, va_list args);
int		ft_printf(const char *string, ...);
#endif
