# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 18:29:52 by lucperei          #+#    #+#              #
#    Updated: 2024/02/09 22:31:00 by lucperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CC = c++
RM     = rm -rf
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(wildcard *.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):cd ex
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

memcheck: $(NAME)
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re memcheck
