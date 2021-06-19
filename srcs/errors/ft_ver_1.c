/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ver_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:58:06 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/19 19:39:44 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	*calloc_ver(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (ptr == NULL)
		error_msg_and_exit("ft_calloc", SYSERR);
	return (ptr);
}

char	**ft_split_ver(const char *s, char c)
{
	char	**ptr;

	ptr = ft_split(s, c);
	if (ptr == NULL)
		error_msg_and_exit("ft_split", SYSERR);
	return (ptr);
}
