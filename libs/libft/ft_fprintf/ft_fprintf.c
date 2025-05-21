/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:21:48 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/04/05 12:14:21 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include <stdio.h>
//int			ft_fprintf(const char *str, ...);
static int	ft_fputnbr(int fd, int nb, int i);
static int	ft_ftype(int fd, const char *type, va_list argument);
/*
int	main(int ac, char **av)
{
	int	neg = -2147483648;
	int pos = 2147483647;

	ft_printf("c == %c\n", av[1][0]);
	ft_printf("s == %s\n", av[1]);
	ft_printf("p == %p\n", av[1]);
	ft_printf("d == %d\n", pos);
	ft_printf("d == %d\n", neg);
	ft_printf("i == %i\n", pos);
	ft_printf("i == %i\n", neg);
	ft_printf("u == %u\n", pos);
	ft_printf("x == %x\n", av[1]);
	ft_printf("X == %X\n", av[1]);
	return (0);
}*/

int	ft_fprintf(int fd, const char *str, ...)
{
	va_list	arguments;
	int		i;

	i = 0;
	va_start(arguments, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_strchar("cspdiuxX", *str))
				i += ft_ftype(fd, str, arguments);
			else
				i += ft_fputchar(fd, *str);
		}
		else
		{
			i += ft_fputchar(fd, *str);
		}
		str++;
	}
	va_end(arguments);
	return (i);
}

static int	ft_fputnbr(int fd, int nb, int i)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_fputchar(fd, '-');
		n = -n;
		i++;
	}
	if (n > 9)
		i = ft_fputnbr(fd, n / 10, i);
	i += ft_fputchar(fd, n % 10 + '0');
	return (i);
}

static int	ft_ftype(int fd, const char *type, va_list argument)
{
	int	i;

	i = 0;
	if (*type == 'c')
		i += ft_fputchar(fd, va_arg(argument, int));
	else if (*type == 's')
		i += ft_fputstr(fd, va_arg(argument, char *));
	else if (*type == 'd' || *type == 'i')
		i += ft_fputnbr(fd, va_arg(argument, int), 0);
	else if (*type == 'u')
		i += ft_fputnbr_base(fd, va_arg(argument, unsigned int),
				"0123456789", 0);
	else if (*type == 'p')
		i += ft_fputpointer(fd, va_arg(argument, char *));
	else if (*type == 'x')
		i += ft_fputnbr_base(fd, va_arg(argument, unsigned int),
				"0123456789abcdef", 0);
	else if (*type == 'X')
		i += ft_fputnbr_base(fd, va_arg(argument, unsigned int),
				"0123456789ABCDEF", 0);
	return (i);
}
