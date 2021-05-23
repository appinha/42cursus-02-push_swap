/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ver_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:58:06 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/22 19:06:33 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

ssize_t	read_ver(int fd, void *buf, size_t nbytes)
{
	ssize_t	ret;

	ret = read(fd, buf, nbytes);
	if (ret < 0)
		error_msg_and_exit("read", SYSERR);
	return (ret);
}

void	*calloc_ver(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (ptr == NULL)
		error_msg_and_exit("ft_calloc", SYSERR);
	return (ptr);
}

void	free_null(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = 0;
}

char	*strdup_ver(const char *s1)
{
	void	*ptr;

	ptr = ft_strdup(s1);
	if (ptr == NULL)
		error_msg_and_exit("ft_strdup", SYSERR);
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
