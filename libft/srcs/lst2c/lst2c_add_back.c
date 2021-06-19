/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2c_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:49:42 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/19 16:27:11 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: Circular Doubly Linked List
** SYNOPSIS: add new element at end of list
**
** DESCRIPTION:
** 		Adds the element 'new' at the end of the list.
*/

#include "libft.h"

void	lst2c_add_back(t_lst2 **first, t_lst2 *new)
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
	last = lst2c_last(*first);
	last->next = new;
	new->prev = last;
	new->next = *first;
	(*first)->prev = new;
}
