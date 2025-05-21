/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:31:03 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/28 15:55:42 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	n;

	if (!s || !f)
		return ;
	n = 0;
	while (s[n])
	{
		f(n, s + n);
		n++;
	}
}
/*
#include <stdio.h>
void to_uppercase(unsigned int index, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("Original string: %s\n", av[1]);
		ft_striteri(av[1], to_uppercase);			    
		printf("Modified string: %s\n", av[1]);
		return (0);
	}
	else if (ac > 2)
		printf("Too many arguments!\n");
	else
		printf("Missing command-line argument!\n");
	return (0);
}*/
