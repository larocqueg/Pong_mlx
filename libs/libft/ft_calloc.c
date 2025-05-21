/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:50:38 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/31 12:33:39 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	dest = (void *)malloc(nmemb * size);
	if (!dest)
		return (NULL);
	ft_bzero(dest, nmemb * size);
	return (dest);
}
/*
#include "ft_bzero.c"
#include "ft_strlen.c"
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	i = 0;
		char *dest = ft_calloc(sizeof(char), ft_strlen(av[1]));
		printf("av[1] after ft_calloc is a new null string");
		printf(" and has the same size of av[1]\n");
		while(dest[i] == '\0' && i < ft_strlen(av[1]))
		{
			printf(". ");
			i++;
		}
		printf("\n");
		free(dest);
		return (0);
	}
	else if (ac > 2)
		printf("Too many arguments!\n");
	else
		printf("Missing command-line argument!\n");
	return (1);
}*/
