/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_branches.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:33:10 by cclaude           #+#    #+#             */
/*   Updated: 2019/10/30 12:29:37 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_char(char c, struct fl_gs flags)
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

int		ft_print_str(char *s, struct fl_gs flags)
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

int		ft_print_mem(unsigned long n, int start, struct fl_gs flags)
{
	char	*set;
	int		i;

	if (start)
		write (1, "0x", 2);
	set = "0123456789abcdef";
	if (n / 16 > 0)
		ft_print_mem(n / 16, 0, flags);
	i = n % 16;
	write(1, &set[i], 1);
	return (0);
}

int		ft_print_nbr(int n, struct fl_gs flags)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
		{
			write(1, "2", 1);
			n = -147483648;
		}
		n = -n;
	}
	if (n / 10 > 0)
		ft_print_nbr(n / 10, flags);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (0);
}

int		ft_print_uns(unsigned int n, struct fl_gs flags)
{
	char	c;

	if (n / 10 > 0)
		ft_print_uns(n / 10, flags);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (0);
}

int		ft_print_hex(unsigned int n, struct fl_gs flags)
{
	char	*set;
	int		i;

	set = "0123456789abcdef";
	if (n / 16 > 0)
		ft_print_hex(n / 16, flags);
	i = n % 16;
	write(1, &set[i], 1);
	return (0);
}

int		ft_print_hexcap(unsigned int n, struct fl_gs flags)
{
	char	*set;
	int		i;

	set = "0123456789ABCDEF";
	if (n / 16 > 0)
		ft_print_hexcap(n / 16, flags);
	i = n % 16;
	write(1, &set[i], 1);
	return (0);
}
