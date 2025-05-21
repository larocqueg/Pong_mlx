/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:29:14 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/11 17:40:51 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, char *base, int i, unsigned int baselen)
{
	if (n >= baselen)
		i = ft_putnbr_base(n / baselen, base, i, baselen);
	i += ft_putchar(base[n % baselen]);
	return (i);
}
