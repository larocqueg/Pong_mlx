/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:13 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/04 12:52:14 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
/*
static void	del(void *lst)
{
	free(lst);
}

#include "ft_lstsize.c"
#include "ft_lstnew.c"
#include "ft_lstlast.c"
#include "ft_lstadd_back.c"
#include "ft_strdup.c"
#include "ft_strlen.c"
#include <stdio.h>
int	main(void)
{
	t_list *list = NULL;
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->content = ft_strdup("hello!");
	node1->next = node2;

	node2->content = ft_strdup("world!");
	node2->next = node3;

	node3->content = ft_strdup("!");
	node3->next = NULL;

	list = node1;

	ft_lstclear(&list, del);

	if (list == NULL)
		printf("List successfully cleared.\n");
	else
	{
		printf("List not cleared. Freeing remaining nodes...\n");
		while (list)
		{
			t_list *temp = list;
			list = list->next;
			del(temp->content);
			free(temp);
		}
		printf("Remaining nodes freed.\n");
	}
	return (0);
}*/
