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

static bool	is_lst_ordered(t_lst2 *stack)
{
	t_lst2	*last;

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

static void	print_input(t_lst2 *stack)
{
	t_lst2	*first;
	int len;

	if (!stack)
		return ;
	first = stack;
	len = 1;
	while (stack->next != first)
	{
		stack = stack->next;
		len++;
	}
	stack = first;
	while (len--)
	{
		ft_printf("%i ", stack->nbr);
		stack = stack->next;
	}
	ft_printf("(%i)\n", stack->nbr);
}

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
	ft_printf("stack a: ");
	print_input(stack.a);
	ft_printf("is_lst_ordered? %s\n", is_lst_ordered(stack.a) ? "yes" : "no");
	lst2c_clear(&stack.a);
	return (EXIT_SUCCESS);
}
