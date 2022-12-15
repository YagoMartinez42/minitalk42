/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:03:56 by samartin          #+#    #+#             */
/*   Updated: 2022/12/14 13:05:59 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*settled_node;
	t_list	*node;
	t_list	*head;

	if (!lst)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (!head)
		return (NULL);
	settled_node = head;
	while (lst->next != NULL)
	{
		lst = lst->next;
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		settled_node->next = node;
		settled_node = node;
	}
	return (head);
}
