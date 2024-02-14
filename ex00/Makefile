# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 10:09:13 by cmartino          #+#    #+#              #
#    Updated: 2024/02/14 11:20:23 by cmartino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= a.out

FILES	= main \
			Fixed

SRCS	= $(addsuffix .cpp, $(FILES))

OBJS	= ${SRCS:.cpp=.o}

CC		= c++

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
