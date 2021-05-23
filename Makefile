# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 21:51:32 by apuchill          #+#    #+#              #
#    Updated: 2021/05/22 19:10:58 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

FLAGS	=
INCLUDES	= -I includes -I $(LIBFT_DIR)/includes/

LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_DIR	= libft
LFT_FLAGS	= -L $(LIBFT_DIR) -lft

CC			= clang
# CFLAGS		= -Wall -Wextra -Werror
# CFLAGS		= -g -Wall -Wextra -Werror
CFLAGS		= -g3 -fsanitize=address -Wall -Wextra -Werror
RM			= /bin/rm -f
NORM		= norminette

DIR_SRCS	= srcs
DIR_OBJS	= objs
SUBDIRS		= main errors

SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRCS		= $(foreach dir, $(SRCS_DIRS), $(wildcard $(dir)/*.c))
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
			@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:		$(NAME)

$(LIBFT):
			@make --no-print-directory -C $(LIBFT_DIR)

$(NAME):	$(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS) $(LFT_FLAGS)

clean:
			@make clean --no-print-directory -C $(LIBFT_DIR)
			@$(RM) $(OBJS)
			@$(RM) -r $(DIR_OBJS)

fclean:		clean
			@make fclean --no-print-directory -C $(LIBFT_DIR)
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

.PHONY:		reset
reset:
			@$(RM) $(OBJS) $(NAME)

.PHONY:		run
run:		reset all
			./$(NAME)

.PHONY:		norm
norm:
			@$(NORM) */*.h */*/*.c
