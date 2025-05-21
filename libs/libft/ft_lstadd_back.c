/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:18:00 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/04 11:32:06 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}
/*
#include "ft_lstnew.c"
#include "ft_lstlast.c"
#include "ft_lstsize.c"
#include "ft_lstadd_front.c"
#include <stdio.h>
int	main(void)
{
	t_list *head = NULL;

	t_list *node1 = ft_lstnew("1");
	t_list *node2 = ft_lstnew("2");
	
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node1);

	printf("\n=====BEFORE=====\n");
	printf("The size of the list is : %i\n", ft_lstsize(head));
    printf("1st node is : %s\nlocated at: (%p)\n",
	(char *)head->content, (void *)head->content);
	printf("and it points to : (%p)\n\n", (void *)head->next);
	printf("2nd node is : %s\nlocated at : (%p)\n",
	(char *)head->next->content, (void *)head->next->content);
	printf("and it points to : (%p)\n\n", (void *)head->next->next);

	t_list *node3 = ft_lstnew("3");
	ft_lstadd_back(&head, node3);

	printf("=====AFTER=====\n");
	printf("The size of the list is : %i\n", ft_lstsize(head));
    printf("1st node is : %s\nlocated at: (%p)\n",
	(char *)head->content, (void *)head->content);
	printf("and it points to : (%p)\n\n", (void *)head->next);
	printf("2nd node is : %s\nlocated at : (%p)\n",
	(char *)head->next->content, (void *)head->next->content);
	printf("and it points to : (%p)\n\n", (void *)head->next->next);
	printf("3rd node is : %s\nlocated at : (%p)\n",
	(char *)head->next->next->content, (void *)head->next->next->content);
	printf("and it points to : %p\n", (void *)head->next->next->next);

    free(node1);
    free(node2);
	free(node3);
    return (0);
}*/
