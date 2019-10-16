/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:07:57 by cclaude           #+#    #+#             */
/*   Updated: 2019/10/16 22:12:14 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putmem(unsigned long n, int start);
void	ft_putnbr(int n);
void	ft_putuns(unsigned int n);
void	ft_puthex(unsigned int n);
void	ft_puthexcap(unsigned int n);
int		arg_type(const char c);
void	func_branch(const char c, va_list args);
int		ft_printf(const char *string, ...);
#endif
