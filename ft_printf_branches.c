/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_branches.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:33:10 by cclaude           #+#    #+#             */
/*   Updated: 2019/10/16 22:09:12 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write(1, &s[i++], 1);
}

void	ft_putmem(unsigned long n, int start)
{
	char	*set;
	int		i;

	if (start)
		write (1, "0x", 2);
	set = "0123456789abcdef";
	if (n / 16 > 0)
		ft_putmem(n / 16, 0);
	i = n % 16;
	write(1, &set[i], 1);
}

void	ft_putnbr(int n)
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
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_putuns(unsigned int n)
{
	char	c;

	if (n / 10 > 0)
		ft_putuns(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_puthex(unsigned int n)
{
	char	*set;
	int		i;

	set = "0123456789abcdef";
	if (n / 16 > 0)
		ft_puthex(n / 16);
	i = n % 16;
	write(1, &set[i], 1);
}

void	ft_puthexcap(unsigned int n)
{
	char	*set;
	int		i;

	set = "0123456789ABCDEF";
	if (n / 16 > 0)
		ft_puthexcap(n / 16);
	i = n % 16;
	write(1, &set[i], 1);
}
