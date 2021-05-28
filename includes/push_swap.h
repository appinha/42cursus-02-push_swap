/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:00:13 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/21 22:00:13 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include "libft.h"
# include "errors.h"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              MACROS
*/

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
*/
typedef struct s_lst2
{
	int				nbr;
	struct s_lst2	*prev;
	struct s_lst2	*next;
}	t_lst2;

typedef struct s_stacks
{
	t_lst2	*a;
	t_lst2	*b;
}	t_stacks;

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
bool	is_lst_ordered(t_lst2 *stack);
/*
** FILE: actions_p.c
*/
void	action_pa(t_stacks *stack);
void	action_pb(t_stacks *stack);
/*
** FILE: actions_s.c
*/
void	action_sa(t_stacks *stack);
void	action_sb(t_stacks *stack);
void	action_ss(t_stacks *stack);
/*
** FILE: actions_r.c
*/
void	action_ra(t_stacks *stack);
void	action_rb(t_stacks *stack);
void	action_rr(t_stacks *stack);
/*
** FILE: actions_rr.c
*/
void	action_rra(t_stacks *stack);
void	action_rrb(t_stacks *stack);
void	action_rrr(t_stacks *stack);
/*
** FILE: lstc2_oper.c
*/
void	lst2c_addback(t_lst2 **first, t_lst2 *new);
void	lst2c_addfront(t_lst2 **first, t_lst2 *new);
t_lst2	*lst2c_delnode(t_lst2 **first, t_lst2 *node);
void	lst2c_clear(t_lst2 **first);
/*
** FILE: utils.c
*/
bool	ft_str_isint(char *str);

// APAGAR
void	testing(t_stacks *stack);

#endif
