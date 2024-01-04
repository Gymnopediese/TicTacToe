# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 14:57:19 by albaud            #+#    #+#              #
#    Updated: 2024/01/04 02:43:09 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= tictactoe
MAIN 		= ft_tictactoe.c  win.c randbot.c minmax.c modes.c textures.c reset.c
LIB 		= srcs/libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MINILIBX	= -I /Library/Developer/CommandLineTools/SDKs/MacOSX12.1.sdk/usr/include -I  /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

.c.o 	:
		${CC} ${CFLAGS} -I /usr/X11/include -c $< -o ${<:.c=.o}

all		: ${NAME}

$(NAME)	: ${LIB}
		${CC} ${CFLAGS} ${MINILIBX} -o ${NAME} ${MAIN} ${LIB}

$(LIB)	: 
		make -C srcs

clean	:
		rm -f ${OBJS}
fclean	:	clean
		rm -f ${NAME} ${LIB}
re:		fclean all