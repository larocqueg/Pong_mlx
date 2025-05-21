/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:02:10 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/26 17:27:29 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*dest;
	size_t				i;

	dest = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (dest[i] == (unsigned char)c)
			return ((void *)(dest + i));
		i++;
	}
	return (NULL);
}
/*
#include "ft_strlen.c"
#include <stdio.h>
int	main(int ac, char **av)
{
	char	*str = av[1];
	const void	*stv = str;
	int	i = av[2][0];
	if (ac == 3)
	{
		printf("%s\n", (char *)ft_memchr(str, i, ft_strlen(av[1]) + 1));
		return (1);
	}
	else if (ac > 3)
		printf("Too many arguments!\n");
	else
		printf("Missing command-line argument!\n");
	return (0);
}*/
