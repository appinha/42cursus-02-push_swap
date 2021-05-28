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

	if (!stack)
		return (false);
	last = stack->prev;
	if (stack == last)
		return (true);
	while (stack != last)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

// TODO: caso do input via variável de ambiente (string)
static void	get_input(char *argv[], t_stacks *stack)
{
	t_dict	*dict_nbrs;
	t_lst2	*new;
	int		i;

	dict_nbrs = dict_create(ft_strlen_2(argv));
	i = 1;
	while (argv[i])
	{
		if (ft_str_isint(argv[i]) == false || dict_get(dict_nbrs, argv[i]))
			error_msg_and_exit(0, INPUTERR);
		dict_insert(dict_nbrs, argv[i], strdup_ver(argv[i]));
		new = calloc_ver(1, sizeof(t_lst2));
		new->nbr = ft_atoi(argv[i]);
		lst2c_addback(&stack->a, new);
		i++;
	}
	dict_destroy(dict_nbrs);
}

int	main(int argc, char *argv[])
{
	t_stacks	stack;

	ft_bzero(&stack, sizeof(t_stacks));
	if (argc == 1)
		error_msg_and_exit(0, INPUTERR);
	get_input(argv, &stack);
	testing(&stack);
	lst2c_clear(&stack.a);
	lst2c_clear(&stack.b);
	return (EXIT_SUCCESS);
}
