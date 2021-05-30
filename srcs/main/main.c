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

static bool	is_input_splitted(char **argv[])
{
	if (ft_strlen_2(*argv) == 2)
	{
		*argv = ft_split(argv[0][1], ' ');
		return (true);
	}
	return (false);
}

static void	get_input(char *argv[], t_stacks *stack)
{
	int		i;
	bool	needs_free;
	t_dict	*dict_nbrs;
	t_lst2	*new;

	i = 0;
	needs_free = is_input_splitted(&argv);
	if (needs_free == false)
		i++;
	dict_nbrs = dict_create(ft_strlen_2(argv));
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
	if (needs_free == true)
		ft_split_free(argv);
	dict_destroy(dict_nbrs);
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
