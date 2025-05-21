/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:56:14 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/26 14:14:35 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int i)
{
	if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))
		return (1);
	else
		return (0);
}
/*
#include "ft_strlen.c"
#include <stdio.h>
int	main(int ac, char **av)
{
	size_t	i = 0;

	if (ac == 2)
	{
		while (ft_isalpha(av[1][i]) == 1)
			i++;
		if (i == ft_strlen(av[1]))
			printf("The given argument contains olny alpha characters!\n");
		else
			printf("The given argumen contains a non alpha character!\n");
		return (0);
	}
	else if (ac > 2)
		printf("Too Many arguments!\n");
	else
		printf("Missing command-line argument!\n");
	return (1);
}*/
