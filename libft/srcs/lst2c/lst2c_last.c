/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2c_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:21:35 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/19 16:27:01 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: Circular Doubly Linked List
** SYNOPSIS: get last element of list
**
** DESCRIPTION:
** 		Returns the last element of the list.
*/

#include "libft.h"

t_lst2	*lst2c_last(t_lst2 *first)
{
	return (first->prev);
}
