/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_branch_uxxper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:53:06 by cclaude           #+#    #+#             */
/*   Updated: 2019/10/31 12:53:07 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_uns(unsigned int n, struct s_flgs flags)
{
	char	c;

	if (n / 10 > 0)
		ft_print_uns(n / 10, flags);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (0);
}

int		ft_print_hex(unsigned int n, struct s_flgs flags)
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

int		ft_print_hexcap(unsigned int n, struct s_flgs flags)
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

int		ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
