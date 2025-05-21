/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:57:53 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/04/17 22:21:22 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*dup;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include "ft_strlen.c"
#include <stdio.h>
int	main(int ac, char **av)
{
	char	*dup = NULL;
	if (ac == 2)
	{
		dup = ft_strdup(av[1]);
		printf("String to be duplicated is (%s)\n", av[1]);
		printf("the memory address is (%p)\n", (void *)av[1]);
		printf("The duplicated string is (%s)\n", dup);
		printf("the memory address is (%p)\n", (void *)dup);
		free (dup);
		return (0);
	}
	else if (ac > 2)
		printf("Too many arguments!\n");
	else
		printf("Missing command-line argument!\n");
	return (1);
}*/
