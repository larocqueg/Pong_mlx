/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputpointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:48:09 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/04/05 12:16:03 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_fputpointer(int fd, void *ptr)
{
	unsigned long	address;
	int				counter;

	if (!ptr)
		return (ft_fputstr(fd, "(nil)"));
	ft_fputstr(fd, "0x");
	address = (unsigned long)ptr;
	counter = 0;
	counter = ft_fputnbr_base(fd, address, "0123456789abcdef", counter);
	return (counter + 2);
}
