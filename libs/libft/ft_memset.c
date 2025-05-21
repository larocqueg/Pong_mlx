/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:17:39 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/28 10:39:22 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*b;

	if (n == 0)
		return (s);
	i = 0;
	b = (unsigned char *)s;
	while (i < n)
	{
		b[i] = (unsigned char)c;
		i++;
	}
	return ((void *)b);
}
/*
#include "ft_atoi.c"
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 4)
	{
		printf("%s\n", (char *)ft_memset(av[1], av[2][0], ft_atoi(av[3])));
		return (0);
	}
	else if (ac > 4)
		printf("Too many arguments!\n");
	else
		printf("Missing command-line argument!\n");
	return (1);
}*/
