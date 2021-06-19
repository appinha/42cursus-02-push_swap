/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2c_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:13:51 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/19 17:53:42 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: Circular Doubly Linked List
** SYNOPSIS: delete sequence of elements of list from a starting point
**
** DESCRIPTION:
** 		Deletes and frees the given element and every successor of that element,
**	using the function 'del' and free(3). Finally, the pointer to the list must
**	be set to NULL.
*/

#include "libft.h"

void	lst2c_clear(t_lst2 **first, void (*del)(void*))
{
	t_lst2	*aux;

	if (!*first)
		return ;
	(*first)->prev->next = NULL;
	while (*first)
	{
		aux = (*first)->next;
		lst2c_del_node(*first, del);
		*first = aux;
	}
	*first = 0;
}
