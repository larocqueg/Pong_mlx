/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:56:58 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/26 16:40:25 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
		return (1);
	else
		return (0);
}
/*
// to test a non printable use $(printf 'non_printable_here')
#include "ft_strlen.c"
#include <stdio.h>
int	main(int ac, char **av)
{
	size_t	i = 0;
	if (ac == 2)
	{
		while (ft_isprint(av[1][i]) == 1)
			i++;
		if (i == ft_strlen(av[1]))
			printf("The given argument contains only printable characters!\n");
		else
			printf("The given argument contains a non printable charactere!\n");
		return (0);
	}
	else if (ac > 2)
		printf("Too many arguments!\n");
	else
		printf("Missing command-line argument!\n");
	return (1);
}*/
