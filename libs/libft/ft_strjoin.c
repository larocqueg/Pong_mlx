/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:34:35 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/30 11:05:09 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*dest;

	if (s1 && s2)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
		if (dest == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			dest[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			dest[s1_len] = s2[i];
			s1_len++;
		}
		dest[s1_len] = '\0';
		return (dest);
	}
	return (NULL);
}
/*
#include "ft_strlen.c"
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		char	*dest;
		dest = ft_strjoin(av[1], av[2]);
		printf("%s\n", dest);
		free (dest);
		return (0);
	}
	else if (ac > 3)
		printf("Too many arguments!\n");
	else
		printf("Missing command-line argument!\n");
	return (1);
}*/
