/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2c_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:44:07 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/19 15:16:31 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Circular doubly linked list's basic operations.
*/

#include "push_swap.h"

t_lst2	*lst2c_new(int nbr)
{
	t_lst2	*new;

	new = calloc_ver(1, sizeof(t_lst2));
	new->nbr = nbr;
	return (new);
}

void	lst2c_addback(t_lst2 **first, t_lst2 *new)
{
	t_lst2	*last;

	if (!new)
		return ;
	if (!*first)
	{
		*first = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = (*first)->prev;
	last->next = new;
	new->prev = last;
	new->next = *first;
	(*first)->prev = new;
}

void	lst2c_addfront(t_lst2 **first, t_lst2 *new)
{
	lst2c_addback(first, new);
	*first = new;
}

t_lst2	*lst2c_delnode(t_lst2 **first, t_lst2 *node)
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

void	lst2c_clear(t_lst2 **first)
{
	t_lst2	*aux;

	if (!*first)
		return ;
	(*first)->prev->next = NULL;
	while (*first)
	{
		aux = (*first)->next;
		free((void **)first);
		*first = aux;
	}
	*first = 0;
}
