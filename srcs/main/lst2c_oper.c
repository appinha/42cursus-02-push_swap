/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2c_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:44:07 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/26 20:22:55 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Circular doubly linked list's basic operations.
*/

#include "push_swap.h"

t_lst2	*lst2c_last(t_lst2 *lst)
{
	t_lst2	*first;

	if (!lst)
		return (0);
	first = lst;
	while (lst->next && lst->next != first)
		lst = lst->next;
	return (lst);
}

void	lst2c_addback(t_lst2 **lst, t_lst2 *new)
{
	t_lst2	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = lst2c_last(*lst);
	last->next = new;
	new->prev = last;
	new->next = *lst;
	(*lst)->prev = new;
}

void	lst2c_addfront(t_lst2 **lst, t_lst2 *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	new->next = *lst;
	new->prev = (*lst)->prev;
	*lst = new;
}

t_lst2	*lst2c_delnode(t_lst2 **lst, t_lst2 *node)
{
	if (*lst == node)
	{
		if (node == node->next)
			*lst = 0;
		else
			*lst = node->next;
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

void	lst2c_clear(t_lst2 **lst)
{
	t_lst2	*aux;

	if (!*lst)
		return ;
	aux = lst2c_last(*lst);
	aux->next = NULL;
	while (*lst)
	{
		aux = (*lst)->next;
		free_null((void **)lst);
		*lst = aux;
	}
	*lst = 0;
}
