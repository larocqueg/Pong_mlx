/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:56:21 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/26 14:28:57 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int i)
{
	if (i >= 0 && i <= 127)
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
		while (ft_isascii(av[1][i]) == 1)
		{
			if (av[1][i] == '\0')
				break;
			i++;
		}
		if (i == ft_strlen(av[1]))
			printf("The given argument contains only ASCII character!\n");
		else
			printf("The given argument contains a non ASCII character!\n");
		return (0);
	}
	else if (ac > 2)
		printf("Too many arguments!\n");
	else
		printf("Missing command-line argument!\n");
	return (1);
}*/
