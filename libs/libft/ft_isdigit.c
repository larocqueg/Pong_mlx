/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:56:33 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/26 14:35:08 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
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
		while (ft_isdigit(av[1][i]) == 1)
			i++;
		if (i == ft_strlen(av[1]))
			printf("The given argument contains only num characters!\n");
		else
			printf("The given argument contains a non num characters!\n");
		return (0);
	}
	else if (ac > 2)
		printf("Too many arguments!\n");
	else
		printf("Missing command-line argument!\n");
	return (1);
}*/
