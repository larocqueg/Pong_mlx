/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:09:01 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/02 13:11:26 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
#include "ft_lstnew.c"
#include <stdio.h>
int main(void)
{
    t_list *node = ft_lstnew("1");
    node->next = ft_lstnew("2");
    node->next->next = ft_lstnew("3");
    node->next->next->next = ft_lstnew("4");
    node->next->next->next->next = ft_lstnew("5");

    int size = ft_lstsize(node);
    printf("The size of the list is: %d\n", size);
    while (node)
	{
        t_list *temp = node;
        node = node->next;
        free(temp);
    }
    return (0);
}*/
