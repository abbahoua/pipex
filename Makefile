# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 11:19:04 by abbahoua          #+#    #+#              #
#    Updated: 2022/05/24 11:32:24 by abbahoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = pipex.c\
	  ft_split.c\
	  pipex_utils.c\
	  env.c\
	  ft_strjoin.c\

OBJS = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = pipex

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all
	
.PHONY: all clean fclean re