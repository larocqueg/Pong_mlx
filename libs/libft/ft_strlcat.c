/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:41:53 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/30 11:19:56 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		len;
	size_t	i;

	i = 0;
	if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	else
	{
		while (dst[i])
			i++;
		ft_strlcpy(&dst[i], src, size - i);
		len = ft_strlen(src) + i;
		return (len);
	}
}
/*
#include <stdio.h>
#include "ft_strlen.c"
#include "ft_strlcpy.c"
int main(int ac, char **av)
{
	if (ac == 3)
	{
		char *dest = av[1];
		const char *src = av[2];
		printf("%zu\n",
		ft_strlcat(dest, src, ft_strlen(dest) + ft_strlen(src) + 1));
		printf("Result: %s\n", dest);
		return (0);
	}
	else if (ac > 3)
		printf("Too many arguments!\n");
	else
		printf("Missing command-line argument!\n");
	return (1);
}*/
