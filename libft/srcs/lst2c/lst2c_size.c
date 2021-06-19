/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2c_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:28:27 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/19 18:19:10 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: Circular Doubly Linked List
** SYNOPSIS: get size (length) of a list
**
** DESCRIPTION:
** 		Counts the number of elements in a list.
*/

#include "libft.h"

int	lst2c_size(t_lst2 *first)
{
	int	count;

	first->prev->next = NULL;
	count = 0;
	while (first)
	{
		first = first->next;
		count++;
	}
	return (count);
}
