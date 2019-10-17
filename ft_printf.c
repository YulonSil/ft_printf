/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:18:32 by cclaude           #+#    #+#             */
/*   Updated: 2019/10/17 17:53:39 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_end_flag(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int		is_valid_flag(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%' || c == ' ')
		return (1);
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(const char *str, int *i)
{
	int	num;

	num = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num = num * 10 + (str[*i] - 48);
		(*i)++;
	}
	return (num);
}

void	flagger(const char *s, int *i, struct fl_gs *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->star = 0;
	flags->width = 0;
	while (is_end_flag(s[*i]) == 0 && is_valid_flag(s[*i]))
	{
		if (s[*i] == '-')
			flags->minus = 1;
		else if (s[*i] == '0')
			flags->zero = 1;
		else if (s[*i] == '.')
			flags->dot = 1;
		else if (s[*i] == '*')
			flags->star = 1;
		else if (s[*i] >= '0' && s[*i] >= '9')
			flags->width = ft_atoi(s, i);
		(*i)++;
	}
}

void	func_branch(const char *s, int *i, va_list args)
{
	struct fl_gs	flags;

	(*i)++;
	flagger(s, i, &flags);
	if (s[*i] == 'c')
		ft_print_char(va_arg(args, int), flags);
	else if (s[*i] == 's')
		ft_print_str(va_arg(args, char *), flags);
	else if (s[*i] == 'p')
		ft_print_mem(va_arg(args, unsigned long), 1, flags);
	else if (s[*i] == 'd' || s[*i] == 'i')
		ft_print_nbr(va_arg(args, int), flags);
	else if (s[*i] == 'u')
		ft_print_uns(va_arg(args, unsigned int), flags);
	else if (s[*i] == 'x')
		ft_print_hex(va_arg(args, unsigned int), flags);
	else if (s[*i] == 'X')
		ft_print_hexcap(va_arg(args, unsigned int), flags);
	(*i)++;
}

int		ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		printed;

	va_start(args, string);
	i = 0;
	printed = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
			func_branch(string, &i, args);
		else
		{
			write(1, &string[i++], 1);
			printed++;
		}
	}
	va_end(args);
	return (printed);
}
