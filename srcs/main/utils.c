/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:32:34 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/22 19:32:34 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_str_isint(char *str)
{
	long long	nbr;
	int			i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == false)
			return (false);
		i++;
	}
	nbr = ft_atoll(str);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (false);
	return (true);
}

t_data	*new_data(int nbr)
{
	t_data	*data;

	data = calloc_ver(1, sizeof(t_data));
	data->nbr = nbr;
	return (data);
}

int	get_pos_of_nbr(t_dict *dict_nbrs, int nbr)
{
	char	*key;
	t_lst2	*node;
	t_data	*data;

	key = ft_itoa(nbr);
	node = (t_lst2 *)dict_get(dict_nbrs, key);
	free(key);
	data = node->data;
	return (data->pos);
}
