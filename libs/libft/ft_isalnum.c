/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:56:06 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/26 16:51:22 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int i)
{
	if (ft_isalpha(i) == 1 || ft_isdigit(i) == 1)
		return (1);
	else
		return (0);
}
/*
#include "ft_strlen.c"
#include "ft_isalpha.c"
#include "ft_isdigit.c"
#include <stdio.h>
int	main(int ac, char **av)
{
	size_t	i = 0;
	if (ac == 2)
	{
		while (ft_isalnum(av[1][i]) == 1)
			i++;
		if (i == ft_strlen(av[1]))
			printf("The given argument contains only alnum characters!\n");
		else
			printf("There is a non alnum character in the given argument!\n");
		return (0);
	}
	else if (ac > 2)
		printf("Too many arguments!\n");
	else
		printf("Missing command-line argument!\n");
	return (0);
}*/
