# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 11:41:33 by cmartino          #+#    #+#              #
#    Updated: 2024/02/20 14:38:53 by cmartino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsp

FILES	= main \
			bsp \
			Fixed \
			Point

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