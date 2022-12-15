/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:25:27 by samartin          #+#    #+#             */
/*   Updated: 2022/12/14 13:06:13 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst)
	{
		f(lst->content);
		while (lst->next != NULL)
		{
			lst = lst->next;
			f(lst->content);
		}
	}
}
