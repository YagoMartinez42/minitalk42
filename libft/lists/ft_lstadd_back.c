/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:52:03 by samartin          #+#    #+#             */
/*   Updated: 2022/12/14 13:06:23 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
		{
			while ((*lst)->next != NULL)
				lst = &(*lst)->next;
			(*lst)->next = new;
		}
		else
			*lst = new;
	}
}
