/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:58:57 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/21 21:58:57 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_lst_ordered(t_lst2 *stack)
{
	t_lst2	*last;
	t_data	*data;
	t_data	*data_next;

	if (!stack)
		return (false);
	last = stack->prev;
	if (stack == last)
		return (true);
	while (stack != last)
	{
		data = stack->data;
		data_next = stack->next->data;
		if (data->nbr > data_next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	t_stacks	stack;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	ft_bzero(&stack, sizeof(t_stacks));
	get_input(argv, &stack);
	if (is_lst_ordered(stack.a) == true)
		exit(EXIT_SUCCESS);
	testing(&stack);
	exit(EXIT_SUCCESS);
}
