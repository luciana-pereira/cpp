# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 19:12:43 by lucperei          #+#    #+#              #
#    Updated: 2024/02/09 22:54:03 by lucperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = megaphone

CC     = c++
RM     = rm -rf
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS   = megaphone.cpp
OBJS   = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

memcheck: $(NAME)
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re memcheck
