/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:21:18 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/04/05 12:16:05 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_fputstr(int fd, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_fputstr(fd, "(null)"));
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}
