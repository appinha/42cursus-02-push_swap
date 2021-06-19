/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2c_pop_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:01:18 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/19 16:13:20 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: Circular Doubly Linked List
** SYNOPSIS: remove element (node) from list and returns it
**
** DESCRIPTION:
** 		Takes as a parameter an element (node) to remove from linked list, which
**	is then returned.
*/

#include "libft.h"

t_lst2	*lst2c_pop_node(t_lst2 **first, t_lst2 *node)
{
	if (*first == node)
	{
		if (node == node->next)
			*first = 0;
		else
			*first = node->next;
	}
	if (node != node->next)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
