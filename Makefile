# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pji <pji@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 21:10:11 by jwee              #+#    #+#              #
#    Updated: 2023/05/08 15:58:17 by pji              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		miniRT

CC=			cc
CFLAG=		-Wall -Werror -Wextra
MLXFLAG=	-lmlx -framework OpenGl -framework AppKit -Lmlx
LIB=		-Lincludes/libft -lft
INC=		-I./includes
#
SRCS=		srcs/main/minirt.c srcs/main/mlx_utils.c srcs/main/mlx_move_rotate.c\
			srcs/parsing/init_camera.c srcs/parsing/init_objects.c \
			srcs/parsing/list_utils.c srcs/parsing/parsing_utils.c srcs/parsing/parsing.c \
			srcs/parsing/read_file.c srcs/parsing/syntax_check.c \
			\
			srcs/object/cylinder_hit.c srcs/object/cylinder_light.c srcs/object/plane_hit.c \
			srcs/object/sphere_hit.c srcs/object/util.c\
			\
			srcs/vector/point_cal.c srcs/vector/vector_cal.c srcs/vector/vector_pro.c \
			\
			srcs/color/color.c srcs/object/draw.c
		
OBJS=		$(SRCS:.c=.o)
HEAD=		includes/minirt.h includes/point.h

#

all : $(NAME)

#

$(NAME) : $(OBJS) $(HEAD)
	@make -C includes/libft
	@make -C mlx
	@$(CC) $(CFLAG) -o $(NAME) $(OBJS) $(LIB) $(INC) $(MLXFLAG) $(INC)
	@echo "\033[37m****** Making miniRT is done ****"


$(NAME_BONUS) : $(OBJS_BONUS)
	@make -C includes/libft
	@make -C mlx
	@$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIB) $(INC) $(MLXFLAG) $(INC)

%.o : %.c $(HEAD)
	$(CC) $(CFLAG) $(INC) -o $@ -c $<

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

`.PHONY : all clean fclean re libft mlx bonus
