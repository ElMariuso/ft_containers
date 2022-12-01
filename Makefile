# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 23:47:43 by root              #+#    #+#              #
#    Updated: 2022/12/01 14:53:55 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program
NAME	=	ft_containers_tester

# Colors
PURPLE	=	\033[1;95m
YELLOW	=	\033[1;33m
RED		=	\033[1;31m
WHITE	=	\033[0;97m
GREEN	=	\033[0;32m
GREENB	=	\033[1;32m
RESET	=	\033[0m

# Compiler, Flags and Commands
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
RMF		=	rm -rf

# Directories
INC_DIR	=	inc
SRC_DIR	=	src
OBJ_DIR =	obj

# Includes
INC		=	-I/$(INC_DIR)

# Sources and Objects
SRC 	=	main.cpp \
			algorithm_test.cpp \
			iterator_test.cpp \
			type_traits_test.cpp \
			utility_test.cpp \
			vector_test.cpp \
			stack_test.cpp \
			map_test.cpp

OBJ		=	$(SRC:.cpp=.o)
OBJS	=	$(addprefix $(OBJ_DIR)/, $(OBJ))

# Default Make
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< $(INC) -o $@

$(NAME): $(OBJS)
	@echo "$(GREEN)Objects created!$(RESET)"
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Tester compiled!$(RESET)"

all: $(NAME)

# Clean Only Objects
clean:
	@$(RMF) $(OBJ)
	@echo "$(RED)Objects deleted!$(RESET)"
	@$(RMF) $(OBJ_DIR)
	@echo "$(RED)Objects directory deleted!$(RESET)"

# Full Clean, Objects and Binaries
fclean: clean
	@$(RMF) $(NAME)
	@echo "$(RED)Tester deleted!$(RESET)"

# Remake
re: fclean all

# Non-File Targets
.PHONY: fclean clean re all dir