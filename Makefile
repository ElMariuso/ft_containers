# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 23:47:43 by root              #+#    #+#              #
#    Updated: 2022/11/30 21:43:00 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program
NAME	=	ft_containers_tester

# Compiler, Flags and Commands
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
RMF		=	rm -rf

# Directories
INC_DIR	=	inc
SRC_DIR	=	src
OBJ_DIR =	obj

# Includes
INC		=	-I$(INC_DIR)

# Sources and Objects
SRC 	=	main.cpp \
			algorithm_test.cpp \
			iterator_test.cpp \
			type_traits_test.cpp \
			utility_test.cpp

OBJ		=	$(SRC:.cpp=.o)
OBJS	=	$(addprefix $(OBJ_DIR)/, $(OBJ))

# Default Make
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp  dir
	$(CC) $(FLAGS) -c -o $@ $< $(INC)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all: $(NAME)

# Make the Directories
dir:
	mkdir -p $(OBJ_DIR)

# Clean Only Objects
clean:
	$(RMF) $(OBJ_DIR)
	$(RMF) $(OBJ)

# Full Clean, Objects and Binaries
fclean: clean
	$(RMF) $(NAME)

# Remake
re: fclean all

# Non-File Targets
.PHONY: fclean clean re all