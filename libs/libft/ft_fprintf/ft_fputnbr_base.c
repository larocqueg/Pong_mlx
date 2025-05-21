/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:29:14 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/04/05 12:17:35 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static unsigned int	ft_fstrlen(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_fputnbr_base(int fd, unsigned long n, char *base, int i)
{
	unsigned int	baselen;

	baselen = ft_fstrlen(base);
	if (n >= baselen)
		i = ft_fputnbr_base(fd, n / baselen, base, i);
	i += ft_fputchar(fd, base[n % baselen]);
	return (i);
}
