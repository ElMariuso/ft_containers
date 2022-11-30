# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 23:47:43 by root              #+#    #+#              #
#    Updated: 2022/11/30 19:44:00 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  ft_containers_tester

# Variables *****************************************************************  #
# Sources
SRCS_DIR = ./srcs/
SRCS =  main.cpp \
		algorithm_test.cpp \
		iterator_test.cpp \
		type_traits.cpp \
		utility_test.cpp

# Objects
OBJ_DIR = $(SRCS_DIR)objs
OBJS_F	= $(SRCS:.cpp=.o)
OBJS	= $(addprefix $(OBJ_DIR)/,$(OBJS_F))

# Includes
# INCLUDE = /

# Compilation
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

# Rules *********************************************************************  #
# Base
all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.cpp
	$(CPP) -c $(FLAGS) $?

# Clean
clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

# Others
re:	fclean all

.PHONY:	all clean fclean re