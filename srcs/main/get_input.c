/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 13:59:40 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/19 19:36:52 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_nbrs_position(t_lst2 *order, t_lst2 *stack_a)
{
	t_lst2	*last;
	t_data	*data;
	int		i;

	last = lst2c_last(order);
	i = 0;
	while (order != last)
	{
		data = order->data;
		data->pos = i++;
		order = order->next;
	}
	data = order->data;
	data->pos = i;
}

static void	insert_in_order_aux(t_lst2 **first, t_lst2 *new)
{
	t_lst2	*aux;
	t_data	*data_new;
	t_data	*data_first;

	data_new = new->data;
	data_first = (*first)->data;
	aux = *first;
	while (data_new->nbr > data_first->nbr)
	{
		*first = (*first)->next;
		data_first = (*first)->data;
	}
	lst2c_add_front(first, new);
	*first = aux;
}

static void	insert_in_order(t_lst2 **first, t_lst2 *new)
{
	t_data	*data_new;
	t_data	*data_first;
	t_data	*data_last;

	if (!*first)
	{
		lst2c_add_back(first, new);
		return ;
	}
	data_new = new->data;
	data_first = (*first)->data;
	data_last = (*first)->prev->data;
	if (data_new->nbr > data_last->nbr)
		lst2c_add_back(first, new);
	else if (data_new->nbr < data_first->nbr)
	{
		lst2c_add_front(first, new);
		*first = new;
	}
	else
		insert_in_order_aux(first, new);
}

static bool	is_input_splitted(char **argv[])
{
	if (ft_strlen_2(*argv) == 2)
	{
		*argv = ft_split_ver(argv[0][1], ' ');
		return (true);
	}
	return (false);
}

void	get_input(char *argv[], t_stacks *stack, t_dict **dict_nbrs)
{
	bool	needs_free;
	int		i;
	t_lst2	*new;
	t_data	*data;

	needs_free = is_input_splitted(&argv);
	i = 0;
	if (needs_free == false)
		i++;
	*dict_nbrs = dict_create_ver(ft_strlen_2(argv));
	while (argv[i])
	{
		if (ft_str_isint(argv[i]) == false || dict_get(*dict_nbrs, argv[i]))
			error_msg_and_exit(0, INPUTERR);
		data = new_data(ft_atoi(argv[i]));
		new = lst2c_new((void *)data);
		insert_in_order(&stack->order, new);
		dict_insert_ver(*dict_nbrs, argv[i], new);
		lst2c_add_back(&stack->a, lst2c_new((void *)data));
		i++;
	}
	if (needs_free == true)
		ft_split_free(argv);
	get_nbrs_position(stack->order, stack->a);
}
