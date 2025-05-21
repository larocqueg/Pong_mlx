/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:46:27 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/28 10:52:09 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}
/*
#include "ft_putchar_fd.c"
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_putstr_fd(av[1], 1);
		return (0);
	}
	else if (ac > 2)
		ft_putstr_fd("Too many arguments!\n", 1);
	else
		ft_putstr_fd("Missing command-line argument!\n", 1);
	return (1);
}*/
