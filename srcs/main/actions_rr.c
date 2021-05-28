/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:30:57 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/27 21:50:07 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** REVERSE ROTATE ACTIONS
**
** Shift down all elements of the stack by 1; the last element becomes the
** first.
**
** -> rra - reverse rotate stack a.
** -> rrb - reverse rotate stack b.
** -> rrr - rra and rrb at the same time.
*/

static void	reverse_rotate(t_lst2 **first)
{
	*first = (*first)->prev;
}

void	action_rra(t_stacks *stack)
{
	if (!stack->a || stack->a == stack->a->next)
		return ;
	reverse_rotate(&stack->a);
}

void	action_rrb(t_stacks *stack)
{
	if (!stack->b || stack->b == stack->b->next)
		return ;
	reverse_rotate(&stack->b);
}

void	action_rrr(t_stacks *stack)
{
	action_rra(stack);
	action_rrb(stack);
}
