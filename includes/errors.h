/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:56:35 by apuchill          #+#    #+#             */
/*   Updated: 2021/05/22 19:06:58 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "libft.h"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              MACROS
*/
# define SYSERR		"System error\n"
# define INPUTERR	"Error\n"

# define C_END		"\033[0m"
# define C_BOLD		"\033[1m"
# define C_RED		"\033[1;31m"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
/*
** FILE: errors.c
*/
void	error_msg_and_exit(char *function, char *msg);
/*
** FILE: ft_ver_1.c
*/
ssize_t	read_ver(int fd, void *buf, size_t nbytes);
void	*calloc_ver(size_t count, size_t size);
void	free_null(void **ptr);
char	*strdup_ver(const char *str);
char	**ft_split_ver(const char *s, char c);

#endif
