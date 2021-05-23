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

t_lst	*lstlast(t_lst *lst)
{
	t_lst	*first;

	if (!lst)
		return (0);
	first = lst;
	while (lst->next && lst->next != first)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = lstlast(*lst);
	last->next = new;
	new->prev = last;
	new->next = *lst;
	(*lst)->prev = new;
}

void	lstclear(t_lst **lst)
{
	t_lst	*aux;

	if (!*lst)
		return ;
	aux = lstlast(*lst);
	aux->next = NULL;
	while (*lst)
	{
		aux = (*lst)->next;
		free_null((void **)lst);
		*lst = aux;
	}
	*lst = 0;
}
