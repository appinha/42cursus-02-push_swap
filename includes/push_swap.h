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

/*
** FILE: lstc2_oper.c
*/
t_lst2	*lst2c_last(t_lst2 *lst);
void	lst2c_addback(t_lst2 **lst, t_lst2 *new);
void	lst2c_addfront(t_lst2 **lst, t_lst2 *new);
t_lst2	*lst2c_delnode(t_lst2 **lst, t_lst2 *node);
void	lst2c_clear(t_lst2 **lst);
/*
** FILE: utils.c
*/
bool	ft_str_isint(char *str);

#endif
