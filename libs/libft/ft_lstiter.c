/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:12:22 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/05 10:50:51 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include "ft_lstnew.c"
#include <stdio.h>

static void print_node(void *content);

int	main(void)
{
	t_list	*node1 = ft_lstnew("Hello");
	t_list	*node2 = ft_lstnew("World!");
	t_list	*node3 = ft_lstnew("Bye");
	t_list	*node4 = ft_lstnew("World!");

	if (!node1 || !node2 || !node3 || !node4)
	{
		printf("Memory allocation fail!\n");
		free(node1);
		free(node2);
		free(node3);
		free(node4);
		return (1);
	}

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;

	ft_lstiter(node1, print_node);

	free(node1);
	free(node2);
	free(node3);
	free(node4);
	return (0);
}

static void print_node(void *content)
{
    printf("%s\n", (char *)content);
}*/
