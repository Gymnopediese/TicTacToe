# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 18:46:11 by albaud            #+#    #+#              #
#    Updated: 2022/07/17 23:32:54 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= $(wildcard */*.c) $(wildcard */*/*.c)
OBJS 	= ${SRCS:.c=.o}
NAME 	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o 	:
		${CC} ${CFLAGS} -I /usr/X11/include -c $< -o ${<:.c=.o}
		
all : $(NAME)

$(NAME)	: ${OBJS}
		echo ${OBJS}
		ar rcs ${NAME} ${OBJS}