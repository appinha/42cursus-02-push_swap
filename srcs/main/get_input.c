/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 13:59:40 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/19 14:49:15 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_in_order(t_lst2 **first, t_lst2 *new)
{
	t_lst2	*aux;

	if (!*first || new->nbr > (*first)->prev->nbr)
		lst2c_addback(first, new);
	else if (new->nbr < (*first)->nbr)
	{
		lst2c_addfront(first, new);
		*first = new;
	}
	else
	{
		aux = *first;
		while (new->nbr > (*first)->nbr)
			*first = (*first)->next;
		lst2c_addfront(first, new);
		*first = aux;
	}
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

// TODO: trim '+' for key used in dict_insert()
// TODO: get 'pos' for each number after ordered
t_dict	*get_input(char *argv[], t_stacks *stack)
{
	bool	needs_free;
	int		i;
	t_dict	*dict_nbrs;
	t_lst2	*new;

	needs_free = is_input_splitted(&argv);
	i = 0;
	if (needs_free == false)
		i++;
	dict_nbrs = dict_create_ver(ft_strlen_2(argv));
	while (argv[i])
	{
		if (ft_str_isint(argv[i]) == false || dict_get(dict_nbrs, argv[i]))
			error_msg_and_exit(0, INPUTERR);
		new = lst2c_new(ft_atoi(argv[i]));
		insert_in_order(&stack->order, new);
		dict_insert_ver(dict_nbrs, argv[i], new);
		lst2c_addback(&stack->a, lst2c_new(ft_atoi(argv[i])));
		i++;
	}
	if (needs_free == true)
		ft_split_free(argv);
	return (dict_nbrs);
}
