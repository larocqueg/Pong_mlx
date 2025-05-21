/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:21:48 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/11 17:48:17 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
//int			ft_printf(const char *str, ...);
static int	ft_putnbr(int nb, int i);
static int	ft_type(const char *type, va_list argument);
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

int	ft_printf(const char *str, ...)
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
				i += ft_type(str, arguments);
			else
				i += ft_putchar(*str);
		}
		else
		{
			i += ft_putchar(*str);
		}
		str++;
	}
	va_end(arguments);
	return (i);
}

static int	ft_putnbr(int nb, int i)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		i++;
	}
	if (n > 9)
		i = ft_putnbr(n / 10, i);
	i += ft_putchar(n % 10 + '0');
	return (i);
}

static int	ft_type(const char *type, va_list argument)
{
	int	i;

	i = 0;
	if (*type == 'c')
		i += ft_putchar(va_arg(argument, int));
	else if (*type == 's')
		i += ft_putstr(va_arg(argument, char *));
	else if (*type == 'd' || *type == 'i')
		i += ft_putnbr(va_arg(argument, int), 0);
	else if (*type == 'u')
		i += ft_putnbr_base(va_arg(argument, unsigned int),
				"0123456789", 0, 10);
	else if (*type == 'p')
		i += ft_putpointer(va_arg(argument, char *));
	else if (*type == 'x')
		i += ft_putnbr_base(va_arg(argument, unsigned int),
				"0123456789abcdef", 0, 16);
	else if (*type == 'X')
		i += ft_putnbr_base(va_arg(argument, unsigned int),
				"0123456789ABCDEF", 0, 16);
	return (i);
}
