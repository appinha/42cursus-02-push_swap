/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:29:28 by apuchill          #+#    #+#             */
/*   Updated: 2021/06/19 17:24:07 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "dict.h"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
*/
typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

typedef struct s_lst2
{
	void			*data;
	struct s_lst2	*prev;
	struct s_lst2	*next;
}	t_lst2;

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isspace(int c);
int				ft_isblank(int c);
int				ft_isxdigit(int c);
int				ft_iscntrl(int c);
int				ft_isgraph(int c);
int				ft_ispunct(int c);
int				ft_islower(int c);
int				ft_isupper(int c);

int				ft_tolower(int c);
int				ft_toupper(int c);

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);
void			*ft_calloc(size_t count, size_t size);

void			ft_free_null(void **ptr);
void			ft_split_free(char **s);

size_t			ft_strlen(const char *s);
size_t			ft_strlen_2(char **s);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnrcmp(const char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putendl(char *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

void			ft_swap(int *a, int *b);
int				ft_atoi(const char *str);
long long		ft_atoll(const char *str);
double			ft_atof(const char *str);
char			*ft_itoa(int n);
double			ft_sqrt(double x);
long double		ft_pow(long double n, unsigned int pow);

t_list			*lst_new(void *data);
t_list			*lst_last(t_list *lst);
int				lst_size(t_list *lst);
void			lst_add_front(t_list **lst, t_list *new);
void			lst_add_back(t_list **lst, t_list *new);
void			lst_del_node(t_list *lst, void (*del)(void *));
void			lst_clear(t_list **lst, void (*del)(void*));
void			lst_iter(t_list *lst, void (*f)(void *));
t_list			*lst_map(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_lst2			*lst2c_new(void *data);
t_lst2			*lst2c_last(t_lst2 *first);
int				lst2c_size(t_lst2 *first);
void			lst2c_add_front(t_lst2 **first, t_lst2 *new);
void			lst2c_add_back(t_lst2 **first, t_lst2 *new);
t_lst2			*lst2c_pop_node(t_lst2 **first, t_lst2 *node);
void			lst2c_del_node(t_lst2 *node, void (*del)(void *));
void			lst2c_clear(t_lst2 **first, void (*del)(void*));

#endif
