/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:35:01 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/30 14:37:58 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*dest;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include "ft_strlen.c"
#include "ft_strdup.c"
#include "ft_atoi.c"
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		char *dest = ft_substr(av[1], ft_atoi(av[2]), ft_strlen(av[1]));
		printf("%s\n", dest);
		free(dest);
		return (0);
	}
	else if (ac > 3)
		printf("Too many arguments!\n");
	else
		printf("Missing command-line argument!\n");
	return (1);
}*/
