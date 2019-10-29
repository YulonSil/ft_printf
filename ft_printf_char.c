/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:01:31 by cclaude           #+#    #+#             */
/*   Updated: 2019/10/29 14:35:56 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_minwid(char c, int width)
{
	int	count;

	count = 0;
	write(1, &c, 1);
	while (count++ < width - 1)
		write(1, " ", 1);
	return (width);
}

int	ft_putchar_zerowid(char c, int width)
{
	int	count;

	count = 0;
	while (count++ < width - 1)
		write(1, "0", 1);
	write(1, &c, 1);
	return (width);
}

int	ft_putchar_wid(char c, int width)
{
	int	count;

	count = 0;
	while (count++ < width - 1)
		write(1, " ", 1);
	write(1, &c, 1);
	return (width);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
