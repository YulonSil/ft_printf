/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_branch_cspdi.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:51:15 by cclaude           #+#    #+#             */
/*   Updated: 2019/10/31 17:26:41 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_char(char c, struct s_flgs flags)
{
	if (flags.width > 0 && flags.minus == 1)
		return (ft_putchar_minwid(c, flags.width));
	else if (flags.width > 0 && flags.zero == 1)
		return (ft_putchar_zerowid(c, flags.width));
	else if (flags.width > 0)
		return (ft_putchar_wid(c, flags.width));
	else
		return (ft_putchar(c));
}

int		ft_print_str(char *s, struct s_flgs flags)
{
	if (s == NULL)
	{
		if (flags.width > 0 && flags.dot == 1)
			return (ft_putstr_prewid("(null)", flags));
		else if (flags.width > 0)
			return (ft_putstr_wid("(null)", flags));
		else if (flags.dot == 1)
			return (ft_putstr_pre("(null)", flags.precision));
		else
			return (ft_putstr("(null)"));
	}
	else
	{
		if (flags.width > 0 && flags.dot == 1)
			return (ft_putstr_prewid(s, flags));
		else if (flags.width > 0)
			return (ft_putstr_wid(s, flags));
		else if (flags.dot == 1)
			return (ft_putstr_pre(s, flags.precision));
		else
			return (ft_putstr(s));
	}
}

int		ft_print_mem(unsigned long n, int start, struct s_flgs flags)
{
	if (flags.width > 0 && flags.dot == 1)
		return (ft_putmem_prewid(n, flags));
	if (flags.width > 0 && flags.zero == 0)
		return (ft_putmem_wid(n, flags));
	else if (flags.dot == 1 || (flags.width > 0 && flags.zero == 1))
		return (ft_putmem_pre(n, flags));
	else
		return (ft_putmem(n, 1));
}

int		ft_print_nbr(long n, struct s_flgs flags)
{
	// if (flags.dot == 1 && flags.precision == 0 && )
	if (flags.width > 0 && flags.dot == 1)
		return (ft_putnbr_prewid(n, flags));
	else if (flags.width > 0 && flags.zero == 0)
		return (ft_putnbr_wid(n, flags));
	else if (flags.dot == 1 || (flags.width > 0 && flags.zero == 1))
		return (ft_putnbr_pre(n, flags));
	else
		return (ft_putnbr(n));
}
