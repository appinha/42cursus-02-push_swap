/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2c_del_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:15:28 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/19 17:25:27 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: Circular Doubly Linked List
** SYNOPSIS: delete element from list
**
** DESCRIPTION:
** 		Takes as a parameter an element and frees the memory of the element's
**	data using the function 'del' given as a parameter and free the element.
**	The memory of 'next' must not be freed.
*/

#include "libft.h"

void	lst2c_del_node(t_lst2 *node, void (*del)(void *))
{
	if (!node)
		return ;
	del(node->data);
	free(node);
}
