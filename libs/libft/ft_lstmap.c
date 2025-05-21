/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:38:02 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/11/05 11:11:15 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_newl(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	void	*content;

	if (!list || !f || !del)
		return (NULL);
	content = f(list->content);
	new_lst = ft_lstnew(content);
	if (!new_lst)
	{
		del(content);
		return (NULL);
	}
	return (new_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*head;

	new_lst = ft_newl(lst, f, del);
	if (!new_lst)
		return (NULL);
	head = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = ft_lstnew(f(lst->content));
		if (!new_lst->next)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
	new_lst->next = NULL;
	return (head);
}
/*
#include "ft_strdup.c"
#include "ft_lstnew.c"
#include "ft_strlen.c"
#include "ft_lstclear.c"
#include <stdio.h>

void *to_uppercase(void *content);
void del_content(void *content);

int main(int ac, char **av)
{
	if (ac == 5)
    {
		t_list *node1 = ft_lstnew(ft_strdup(av[1]));
    	t_list *node2 = ft_lstnew(ft_strdup(av[2]));
    	t_list *node3 = ft_lstnew(ft_strdup(av[3]));
    	t_list *node4 = ft_lstnew(ft_strdup(av[4]));

    	node1->next = node2;
    	node2->next = node3;
    	node3->next = node4;

    	t_list *new_list = ft_lstmap(node1, to_uppercase, del_content);

    	t_list *temp = new_list;
    	while (temp)
    	{
        	printf("%s\n", (char *)temp->content);
        	temp = temp->next;
    	}

    	temp = new_list;
    	while (temp)
    	{
        	t_list *next = temp->next;
        	free(temp->content);
        	free(temp);
        	temp = next;
    	}

    	temp = node1;
    	while (temp)
    	{
        	t_list *next = temp->next;
        	free(temp->content);
        	free(temp);
        	temp = next;
    	}
		return (0);
	}
	else if (ac > 5)
	{
		printf("Too many arguments!\n");
		return (2);
	}
	else
		printf("Missing command-line argument!\n");
	return (1);
}

void *to_uppercase(void *content)
{
    char *str = (char *)content;
    char *new_str = ft_strdup(str);
    if (!new_str)
        return NULL;

    for (int i = 0; new_str[i]; i++)
    {
        if (new_str[i] >= 'a' && new_str[i] <= 'z')
        {
            new_str[i] = new_str[i] - ('a' - 'A');
        }
    }
    return new_str;
}

void del_content(void *content)
{
    free(content);
}*/
