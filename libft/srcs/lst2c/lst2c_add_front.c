/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2c_add_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:59:16 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/19 16:00:03 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: Circular Doubly Linked List
** SYNOPSIS: add new element at beginning of list
**
** DESCRIPTION:
** 		Adds the element 'new' at the beginning of the list.
*/

#include "libft.h"

void	lst2c_add_front(t_lst2 **first, t_lst2 *new)
{
	lst2c_add_back(first, new);
	*first = new;
}
