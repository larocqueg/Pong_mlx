/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:21:16 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/04 11:12:31 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
#include "ft_lstnew.c"
#include <stdio.h>
int	main(void)
{
	t_list *head = NULL;
	
	t_list *node1 = ft_lstnew("1");
	t_list *node2 = ft_lstnew("2");

	ft_lstadd_front(&head, node1);
    
    printf("1st node is : %s\nlocated at: (%p)\n",
	(char *)head->content, (void *)head->content);
	printf("and it points to : (%p)\n\n", (void *)head->next);

	ft_lstadd_front(&head, node2);
    
	printf("After ft_lstadd_front the 1st node is : %s\nlocated at : (%p)\n",
	(char *)head->content, (void *)head->content);
	printf("and it points to : (%p)\n", (void *)head->next->content);

    free(node1);
    free(node2);
    return (0);
}*/
