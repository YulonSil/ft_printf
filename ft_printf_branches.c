/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_branches.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:33:10 by cclaude           #+#    #+#             */
/*   Updated: 2019/10/17 17:53:21 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c, struct fl_gs flags)
{
	write(1, &c, 1);
}

void	ft_print_str(char *s, struct fl_gs flags)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write(1, &s[i++], 1);
}

void	ft_print_mem(unsigned long n, int start, struct fl_gs flags)
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
}

void	ft_print_nbr(int n, struct fl_gs flags)
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
}

void	ft_print_uns(unsigned int n, struct fl_gs flags)
{
	char	c;

	if (n / 10 > 0)
		ft_print_uns(n / 10, flags);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_print_hex(unsigned int n, struct fl_gs flags)
{
	char	*set;
	int		i;

	set = "0123456789abcdef";
	if (n / 16 > 0)
		ft_print_hex(n / 16, flags);
	i = n % 16;
	write(1, &set[i], 1);
}

void	ft_print_hexcap(unsigned int n, struct fl_gs flags)
{
	char	*set;
	int		i;

	set = "0123456789ABCDEF";
	if (n / 16 > 0)
		ft_print_hexcap(n / 16, flags);
	i = n % 16;
	write(1, &set[i], 1);
}
