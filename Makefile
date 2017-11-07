# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 09:01:25 by dvdovenk          #+#    #+#              #
#    Updated: 2017/10/30 09:01:27 by dvdovenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

N_INC = Enemy.hpp Game.hpp Object.hpp Obstacle.hpp Player.hpp Stars.hpp

N_SRCS +=	Enemy.cpp \
			Game.cpp \
			Object.cpp \
			Obstacle.cpp \
			Player.cpp \
			Stars.cpp \
			main.cpp

CC = clang++
CC_FLAGS = -Wall -Werror -Wextra

P_SRCS = ./srcs/
P_OBJ = ./obj/

I_INC = ./includes

NOC=\033[0m
OKC=\033[32;05m
ERC=\033[31m
WAC=\033[33m

SRC = $(addprefix $(P_SRCS),$(N_SRCS))
OBJ = $(addprefix $(P_OBJ),$(OBJ_NAME))

OBJ_NAME = $(N_SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(OKC)$(NAME): Compiling $(NAME)$(NOC)"
	@$(CC) $(CC_FLAGS) -o $(NAME) $(OBJ) -I $(I_INC) -lncurses
	@echo "$(OKC)$(NAME): Compilation success!$(NOC)"

$(P_OBJ)%.o: $(P_SRCS)%.cpp
	@mkdir -p $(P_OBJ) $(ADD)
	@$(CC) $(CC_FLAGS) -o $@ -c $^ -I $(I_INC)

clean:
	@rm -rf $(P_OBJ)
	@echo "$(WAC)$(NAME): Removing $(NAME) ./obj/$(NOC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(WAC)$(NAME): Removing executable$(NOC)"

re: fclean all
