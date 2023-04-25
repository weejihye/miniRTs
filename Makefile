# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 21:10:11 by jwee              #+#    #+#              #
#    Updated: 2023/04/25 22:15:40 by jwee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=miniRT
NAME_BONUS=miniRT_bonus

CC=cc
CFLAG= -g #-Wall -Werror -Wextra
MLXFLAG=-lmlx -framework OpenGl -framework AppKit -Lmlx
LIB=-Lincludes/libft -lft
INC=-I./includes

SRCS= srcs/parsing/parsing.c srcs/parsing/init_camera.c srcs/parsing/parsing_utils.c srcs/parsing/read_file.c srcs/parsing/syntax_check.c
OBJS=$(SRCS:.c=.o)

SRCS_BONUS=includes/libft/ft_split.c
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

#

all : $(NAME)

bonus : $(NAME_BONUS)

#

$(NAME) : $(OBJS)
	@make -C includes/libft
	@make -C mlx
	@$(CC) -g -o $(NAME) $(OBJS) $(LIB) $(INC) $(MLXFLAG) $(INC)
	@echo "\033[37m****** Making miniRT is done ****"	


$(NAME_BONUS) : $(OBJS_BONUS)
	@make -C includes/libft
	@make -C mlx
	@$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIB) $(INC) $(MLXFLAG) $(INC)

.c.o :
	@$(CC) $(CFLAG) $(INC) -o $@ -c $?

#

clean :
	@$(MAKE) -C ./mlx clean
	@echo "===== mlx clean ========="
	@$(MAKE) -C includes/libft clean
	@echo "===== libft clean ======="
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo "===== minRT clean ======="

fclean : clean
	@$(MAKE) -C includes/libft fclean
	@echo "===== libft fclean ======"
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "===== miniRT fclean ====="
	@echo "===== done =============="

re : fclean all

.PHONY : all clean fclean re libft mlx bonus
