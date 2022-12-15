/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:45:55 by samartin          #+#    #+#             */
/*   Updated: 2022/12/14 13:06:19 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*swap;

	if (lst)
	{
		while (*lst)
		{
			swap = (*lst)->next;
			if (del)
				ft_lstdelone(*lst, del);
			*lst = swap;
		}
	}
}
