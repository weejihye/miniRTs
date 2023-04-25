# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 21:10:11 by jwee              #+#    #+#              #
#    Updated: 2023/04/24 21:49:34 by jwee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=cc
CFLAG=-Wall -Wextra -Werror

AR=ar
ARFLAG=crs

INCLUDES=./libft.h

SRCS=	ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c \
		ft_strlcat.c ft_strnstr.c ft_bzero.c ft_isascii.c \
		ft_memcmp.c ft_strchr.c ft_strlcpy.c ft_strrchr.c \
		ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strdup.c \
		ft_strlen.c ft_tolower.c ft_isalnum.c ft_isprint.c \
		ft_memmove.c ft_strncmp.c ft_toupper.c ft_substr.c \
		ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_itoa.c \
		ft_split.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		get_next_line.c ft_strrcmp.c \
		ft_split_spaces.c ft_isspace.c ft_strcmp.c \
		ft_isdouble.c ft_atoi_valid.c ft_stod.c

SRCS_BONUS=ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS=$(SRCS:.c=.o)

OBJS_BONUS=$(SRCS_BONUS:.c=.o)

all : $(NAME)

%.o : %.c $(INCLUDES)
	@$(CC) $(CFLAG) -c $< -o $@ -I$(INCLUDES)

clean :
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAG) $@ $^
	@echo "\033[33m****** Making libft is done *****"


bonus : $(OBJS) $(OBJS_BONUS)
	@$(AR) $(ARFLAG) $(NAME) $^

.PHONY : all clean fclean re
