/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:46:02 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/24 13:27:21 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** PUSH ACTIONS
**
** Take the first element at the top of one stack and put it at the top of the
** other; do nothing if the origin stack is empty.
**
** -> pa - top element of stack b goes to top of stack a.
** -> pb - top element of stack a goes to top of stack b.
*/

static void	push(t_lst2 **src, t_lst2 **dst)
{
	lst2c_addfront(dst, lst2c_delnode(src, *src));
}

void	action_pa(t_stacks *stack)
{
	if (!stack->b)
		return ;
	push(&stack->b, &stack->a);
}

void	action_pb(t_stacks *stack)
{
	if (!stack->a)
		return ;
	push(&stack->a, &stack->b);
}
