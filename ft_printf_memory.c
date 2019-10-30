/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:11:08 by cclaude           #+#    #+#             */
/*   Updated: 2019/10/30 17:01:17 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_plen(unsigned long n)
{
	int	len;

	len = 0;
	if (n / 16 > 0)
		len += ft_plen(n / 16);
	len++;
	return (len);
}

int		ft_putmem_prewid(unsigned long n, struct fl_gs flags)
{
	char	*set;
	int		i;
	int		printed;
	int		padding;
	int		count;

	count = flags.precision - ft_plen(n);
	padding = flags.width - count - ft_plen(n) - 2;
	printed = 2 + padding + count;
	while (flags.minus == 0 && padding-- > 0)
		write(1, " ", 1);
	write(1, "0x", 2);
	while (count-- > 0)
		write(1, "0", 1);
	printed += ft_putmem(n, 0);
	while (flags.minus == 1 && padding-- > 0)
		write(1, " ", 1);
	return (printed);
}

int		ft_putmem_wid(unsigned long n, struct fl_gs flags)
{
	char	*set;
	int		i;
	int		printed;
	int		padding;

	printed = 0;
	padding = (flags.dot == 1) ? flags.precision : flags.width - 2;
	padding -= ft_plen(n);
	while (flags.minus == 0 && padding-- > 0)
	{
		write(1, " ", 1);
		printed++;
	}
	set = "0123456789abcdef";
	printed += ft_putmem(n, 1);
	while (flags.minus == 1 && padding-- > 0)
	{
		write(1, " ", 1);
		printed++;
	}
	return (printed);
}

int		ft_putmem_pre(unsigned long n, struct fl_gs flags)
{
	char	*set;
	int		i;
	int		printed;
	int		count;

	write(1, "0x", 2);
	printed = 2;
	count = (flags.dot == 1) ? flags.precision : flags.width - 2;
	count -= ft_plen(n);
	while (count-- > 0)
	{
		write(1, "0", 1);
		printed++;
	}
	set = "0123456789abcdef";
	if (n / 16 > 0)
		printed += ft_putmem(n / 16, 0);
	i = n % 16;
	write(1, &set[i], 1);
	printed++;
	return (printed);
}

int		ft_putmem(unsigned long n, int start)
{
	char	*set;
	int		i;
	int		printed;

	printed = 0;
	if (start)
	{
		write (1, "0x", 2);
		printed += 2;
	}
	set = "0123456789abcdef";
	if (n / 16 > 0)
		printed += ft_putmem(n / 16, 0);
	i = n % 16;
	write(1, &set[i], 1);
	printed++;
	return (printed);
}
