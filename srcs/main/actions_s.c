/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:50:30 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/26 22:13:34 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** SWAP ACTIONS
**
** Swap the first 2 elements at the top of the stack; do nothing if there is
** only one or no elements.
**
** -> sa - swap stack a.
** -> sb - swap stack b.
** -> sa - sa and sb at the same time.
*/

static void	swap(t_lst2 **first)
{
	t_lst2	*second;

	second = lst2c_delnode(first, (*first)->next);
	lst2c_addfront(first, second);
}

void	action_sa(t_stacks *stack)
{
	if (!stack->a || stack->a == stack->a->next)
		return ;
	swap(&stack->a);
}

void	action_sb(t_stacks *stack)
{
	if (!stack->b || stack->b == stack->b->next)
		return ;
	swap(&stack->b);
}

void	action_ss(t_stacks *stack)
{
	action_sa(stack);
	action_sb(stack);
}
