/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:56:28 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/31 12:18:13 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;

	if (!s)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include "ft_toupper.c"
#include "ft_strlen.c"
#include <stdio.h>
char to_uppercase(unsigned int index, char c)
{
    if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char *dest = ft_strmapi(av[1], to_uppercase);
		printf("%s\n", dest);
		return (0);
	}
	else if (ac > 2)
		printf("Too many arguments!\n");
	else
		printf("Missing command-line argument!\n");
	return (1);
}*/
