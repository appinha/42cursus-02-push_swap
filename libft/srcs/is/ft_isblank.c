/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:42:00 by apuchill          #+#    #+#             */
/*   Updated: 2021/03/28 13:14:47 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <ctype.h>
** SYNOPSIS: space or tab character test
**
** DESCRIPTION:
** 		The isblank() function tests for a space or tab character.
*/

int	ft_isblank(int c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
