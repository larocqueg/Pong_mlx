/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:45:58 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/04 11:14:03 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n_node;

	n_node = (t_list *)malloc(sizeof(t_list));
	if (!n_node)
		return (NULL);
	n_node->content = content;
	n_node->next = NULL;
	return (n_node);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 4)
	{
		t_list	*node1 = ft_lstnew((char *)av[1]);
		t_list	*node2 = ft_lstnew((char *)av[2]);
		t_list	*node3 = ft_lstnew((char *)av[3]);

		printf("Node1->content: %s, located at: %p\n\n", 
		(char *)node1->content, (char *)node1->content);
		printf("Node2->content: %s, located at: %p\n\n",
		(char *)node2->content, (char *)node2->content);
		printf("Node3->content: %s, located at: %p\n",
		(char *)node3->content, (char *)node3->content);
		free(node1);
		free(node2);
		free(node3);
		return (0);
	}
	printf("Usage: 'av[1]' 'av[2]' 'av[3]'\n");
	return (1);
}*/
