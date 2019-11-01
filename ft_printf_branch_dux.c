/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_branch_dux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:20:16 by cclaude           #+#    #+#             */
/*   Updated: 2019/11/01 17:05:57 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_nbr(long n, struct s_flgs flags)
{
	int	i;

	i = 0;
	if (flags.dot == 1 && flags.precision == 0 && n == 0)
	{
		while (i++ < flags.width)
			write(1, " ", 1);
		return (flags.width);
	}
	else if (flags.width > 0 && flags.dot == 1)
		return (ft_putnbr_prewid(n, flags));
	else if (flags.width > 0 && flags.zero == 0)
		return (ft_putnbr_wid(n, flags));
	else if (flags.dot == 1 || (flags.width > 0 && flags.zero == 1))
		return (ft_putnbr_pre(n, flags));
	else
		return (ft_putnbr(n));
}

int		ft_print_hex(unsigned int n, struct s_flgs flags, int cap)
{
	int	i;

	i = 0;
	if (flags.dot == 1 && flags.precision == 0 && n == 0)
	{
		while (i++ < flags.width)
			write(1, " ", 1);
		return (flags.width);
	}
	else if (flags.width > 0 && flags.dot == 1)
		return (ft_puthex_prewid(n, flags, cap));
	else if (flags.width > 0 && flags.zero == 0)
		return (ft_puthex_wid(n, flags, cap));
	else if (flags.dot == 1 || (flags.width > 0 && flags.zero == 1))
		return (ft_puthex_pre(n, flags, cap));
	else
		return (ft_puthex(n, cap));
}

int		ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
