/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:25:35 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/19 17:25:18 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: Singly Linked List
** SYNOPSIS: create new element
**
** DESCRIPTION:
** 		Allocates (with malloc(3)) and returns a new element. The variable
**	'data' is initialized with the value of the parameter 'data'. The variable
**	'next' is initialized to NULL (by ft_calloc).
*/

#include "libft.h"

t_list	*lst_new(void *data)
{
	t_list	*new;

	new = ft_calloc(1, sizeof(t_list));
	if (!new)
		return (0);
	new->data = data;
	return (new);
}
