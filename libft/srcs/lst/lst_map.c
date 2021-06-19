/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:37:39 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/19 17:25:00 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: Singly Linked List
** SYNOPSIS: apply function to data of all list's elements into new list
**
** DESCRIPTION:
** 		Iterates the list 'lst' and applies the function 'f' to the data of
**	each element. Creates a new list resulting of the successive applications of
**	the function 'f'. The 'del' function is used to delete the data of an
**	element if needed.
*/

#include "libft.h"

t_list	*lst_map(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*elem;

	if (!lst)
		return (0);
	new_lst = 0;
	while (lst)
	{
		elem = lst_new(f(lst->data));
		if (!elem)
		{
			lst_clear(&new_lst, del);
			return (0);
		}
		lst_add_back(&new_lst, elem);
		lst = lst->next;
	}
	return (new_lst);
}
