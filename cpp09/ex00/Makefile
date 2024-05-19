# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 02:30:55 by lucperei          #+#    #+#              #
#    Updated: 2024/05/19 19:18:46 by lucperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = btc

CC      = c++
RM      = rm -rf
CFLAGS  = -Wall -Werror -Wextra -std=c++98

SRC_DIR = src
OBJ_DIR = obj

SRCS    = $(wildcard $(SRC_DIR)/*.cpp)
OBJS    = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

memcheck: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re memcheck