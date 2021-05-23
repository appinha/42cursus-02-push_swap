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

static bool	is_lst_ordered(t_lst *stack_a)
{
	t_lst	*last;

	last = lstlast(stack_a);
	if (stack_a == last)
		return (true);
	while (stack_a != last)
	{
		if (stack_a->nbr > stack_a->next->nbr)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

static void	print_input(t_lst *stack_a, int len)
{
	while (len)
	{
		ft_printf("%i ", stack_a->nbr);
		stack_a = stack_a->next;
		len--;
	}
	ft_printf("\n");
}

static void	get_input(char *argv[], t_stacks *stack)
{
	t_dict	*dict_nbrs;
	t_lst	*new;
	int		i;

	dict_nbrs = dict_create(ft_strlen_2(argv));
	i = 1;
	while (argv[i])
	{
		if (ft_str_isint(argv[i]) == false || dict_get(dict_nbrs, argv[i]))
			error_msg_and_exit(0, INPUTERR);
		dict_insert(dict_nbrs, argv[i], strdup_ver(argv[i]));
		new = calloc_ver(1, sizeof(t_lst));
		new->nbr = ft_atoi(argv[i]);
		lstadd_back(&stack->a, new);
		i++;
	}
	new->next = stack->a;
	stack->a->prev = new;
	dict_destroy(dict_nbrs);
}

int	main(int argc, char *argv[])
{
	t_stacks	stack;

	ft_bzero(&stack, sizeof(t_stacks));
	if (argc == 1)
		error_msg_and_exit(0, INPUTERR);
	get_input(argv, &stack);
	print_input(stack.a, ft_strlen_2(argv));
	ft_printf("is_lst_ordered? %s\n", is_lst_ordered(stack.a) ? "yes" : "no");
	lstclear(&stack.a);
	return (EXIT_SUCCESS);
}
