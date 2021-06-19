/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2c_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:20:45 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/19 17:25:49 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: Circular Doubly Linked List
** SYNOPSIS: create new element
**
** DESCRIPTION:
** 		Allocates (with malloc(3)) and returns a new element. The variable
**	'data' is initialized with the value of the parameter 'data'. The variables
**	'next' and 'prev' are initialized to NULL (by ft_calloc).
*/

#include "libft.h"

t_lst2	*lst2c_new(void *data)
{
	t_lst2	*new;

	new = ft_calloc(1, sizeof(t_lst2));
	if (!new)
		return (0);
	new->data = data;
	return (new);
}
