/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:30:57 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/27 21:37:58 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ROTATE ACTIONS
**
** Shift up all elements of the stack by 1; the first element becomes the last.
**
** -> ra - rotate stack a.
** -> rb - rotate stack b.
** -> ra - ra and rb at the same time.
*/

static void	rotate(t_lst2 **first)
{
	*first = (*first)->next;
}

void	action_ra(t_stacks *stack)
{
	if (!stack->a || stack->a == stack->a->next)
		return ;
	rotate(&stack->a);
}

void	action_rb(t_stacks *stack)
{
	if (!stack->b || stack->b == stack->b->next)
		return ;
	rotate(&stack->b);
}

void	action_rr(t_stacks *stack)
{
	action_ra(stack);
	action_rb(stack);
}
