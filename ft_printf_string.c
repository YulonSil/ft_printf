/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:55:18 by cclaude           #+#    #+#             */
/*   Updated: 2019/10/29 19:12:20 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr_prewid(char *s, struct fl_gs flags)
{
	int	ssize;
	int	padsize;
	int	i;

	ssize = (ft_strlen(s) < flags.precision) ? ft_strlen(s) : flags.precision;
	padsize = (flags.width > ssize) ? flags.width - ssize : 0;
	i = 0;
	while (flags.minus == 1 && i < flags.precision && s[i] != '\0')
		write(1, &s[i++], 1);
	i = 0;
	while (flags.zero == 0 && i++ < padsize)
		write(1, " ", 1);
	i = 0;
	while (flags.zero == 1 && i++ < padsize)
		write(1, "0", 1);
	i = 0;
	while (flags.minus == 0 && i < flags.precision && s[i] != '\0')
		write(1, &s[i++], 1);
	return (ssize > flags.width ? ssize : flags.width);
}

int	ft_putstr_wid(char *s, struct fl_gs flags)
{
	int	padsize;
	int	i;

	padsize = (flags.width > ft_strlen(s)) ? flags.width - ft_strlen(s) : 0;
	i = 0;
	while (flags.minus == 1 && s[i] != '\0')
		write(1, &s[i++], 1);
	i = 0;
	while (flags.zero == 0 && i++ < padsize)
		write(1, " ", 1);
	i = 0;
	while (flags.zero == 1 && i++ < padsize)
		write(1, "0", 1);
	i = 0;
	while (flags.minus == 0 && s[i] != '\0')
		write(1, &s[i++], 1);
	return (ft_strlen(s) > flags.width ? ft_strlen(s) : flags.width);
}
