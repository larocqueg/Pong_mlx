/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:56:26 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/26 14:16:21 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
/*
#include "ft_strlen.c"
#include <stdio.h>
int	main(int ac, char **av)
{
	void	*s;
	size_t	n;
	int		i;

	if (ac == 2)
	{
		n = ft_strlen(av[1]) / 2;
		s = (void *)av[1];
		printf("Original string is: %s\n", av[1]);
		printf("After ft_bzero the chars = '.' are the erased ones!\n");
		ft_bzero(s, n);
		i = 0;
		while (av[1][i++] == 0)
			printf(".");
		i--;
		while (av[1][i])
			printf("%c", av[1][i++]);
		printf("\n");
		return (0);
	}
	else if (ac > 2)
		printf("Too many arguments!\n");
	else
		printf("Missin command-line argument!\n");
	return (1);
}*/
