/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:57:11 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/10/25 13:48:06 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src_cpy;
	unsigned char	*dest_cpy;

	if (n == 0 || src == dest)
		return (dest);
	src_cpy = (unsigned char *)src;
	dest_cpy = (unsigned char *)dest;
	if (!src && !dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	dest = (void *)dest_cpy;
	return (dest);
}
/*
#include "ft_atoi.c"
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 4)
	{
		printf("%s\n", (char *)ft_memcpy(av[2], av[1], ft_atoi(av[3])));
		return (0);
	}
	else if (ac > 4)
		printf("Too many arguments!\n");	
	else
		printf("Missing command-line argument!\n");
	return (1);
}*/
