# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 23:47:43 by root              #+#    #+#              #
#    Updated: 2022/11/30 21:18:54 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_containers_tester

CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC_DIR	=	src
SRC 	=	main.cpp \
			algorithm_test.cpp \
			iterator_test.cpp \
			type_traits_test.cpp \
			utility_test.cpp