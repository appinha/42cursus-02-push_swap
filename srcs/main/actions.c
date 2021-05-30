/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 12:49:57 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/30 13:31:08 by apuchill         ###   ########.fr       */
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
	if (!(*src))
		return ;
	lst2c_addfront(dst, lst2c_delnode(src, *src));
}

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

	if (!(*first) || (*first) == (*first)->next)
		return ;
	second = lst2c_delnode(first, (*first)->next);
	lst2c_addfront(first, second);
}

/*
** ROTATE ACTIONS
**
** Shift up all elements of the stack by 1; the first element becomes the last.
**
** -> ra - rotate stack a.
** -> rb - rotate stack b.
** -> ra - ra and rb at the same time.
**
** REVERSE ROTATE ACTIONS
**
** Shift down all elements of the stack by 1; the last element becomes the
** first.
**
** -> rra - reverse rotate stack a.
** -> rrb - reverse rotate stack b.
** -> rrr - rra and rrb at the same time.
*/

static void	rotate(t_lst2 **first, bool is_reverse)
{
	if (!(*first) || (*first) == (*first)->next)
		return ;
	if (is_reverse == false)
		*first = (*first)->next;
	else
		*first = (*first)->prev;
}

void	run_action(t_type action, t_stacks *stack)
{
	bool	is_reverse;

	is_reverse = false;
	if (action >= RRA)
		is_reverse = true;
	if (action == PA)
		push(&stack->b, &stack->a);
	if (action == PB)
		push(&stack->a, &stack->b);
	if (action == SA || action == SS)
		swap(&stack->a);
	if (action == SB || action == SS)
		swap(&stack->b);
	if (action == RA || action == RR || action == RRA || action == RRR)
		rotate(&stack->a, is_reverse);
	if (action == RB || action == RR || action == RRB || action == RRR)
		rotate(&stack->b, is_reverse);
}
