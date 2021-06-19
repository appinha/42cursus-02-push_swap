/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:06:49 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/19 17:24:16 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: Singly Linked List
** SYNOPSIS: delete element from list
**
** DESCRIPTION:
** 		Takes as a parameter an element and frees the memory of the element's
**	data using the function 'del' given as a parameter and free the element.
**	The memory of 'next' must not be freed.
*/

#include "libft.h"

void	lst_del_node(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->data);
	free(lst);
}
