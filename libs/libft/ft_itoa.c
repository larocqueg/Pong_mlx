/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:37:52 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/31 12:15:13 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_completestr(int n, size_t len, size_t neg)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + neg + 1));
	if (!str)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	str[len + neg] = '\0';
	len--;
	while (n >= 10)
	{
		str[len + neg] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	str[len + neg] = n + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	len = ft_numlen(n);
	return (ft_completestr(n, len, neg));
}
/*
#include "ft_strdup.c"
#include "ft_atoi.c"
#include "ft_strlen.c"
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char *dest = ft_itoa(ft_atoi(av[1]));
		printf("The int (%d)\nafter itoa is a str (%s)\n", 
		ft_atoi(av[1]), dest);
		free(dest);
	}
	else if (ac > 2)
		printf("Too many arguments!\n");
	else
		printf("Missing command-line argument!\n");
	return (1);
}*/
