# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrault <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 10:33:22 by rrault            #+#    #+#              #
#    Updated: 2023/06/01 10:33:24 by rrault           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LIBDIR = ./Mlx
MAKEFLAGS += --silent
SRC	= main \
	  map \
	  ft_split \
	  ft_strjoin \
	  ft_itoa \
	  exit_game \
	  control \
	  step_count \
	  animation \
	  enemy \
	  valid_map \
	  no_error \
	  item \
	 
SRCS_DIR = src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC)))

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC)))



CC = cc

CFLAGS	=	-Wall -Wextra -Werror -g

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
		@mkdir -p $(OBJS_DIR)
		 @$(CC) $(CFLAGS) -Iminilibx-linux Mlx/libmlx_Linux.a -lXext -lX11 -lm -lz -c $< -o $@ 
	
$(NAME): ${OBJS}
		cd ./Mlx && ./configure && $(MAKE)
		$(CC) ${OBJS} -Iminilibx-linux Mlx/libmlx_Linux.a -lXext -lX11 -lm -lz -o $(NAME)

all:	${NAME}

clean:
		rm -rf ${OBJS_DIR}

fclean:	clean
		rm -rf ${NAME}
		
re:	fclean all

.PHONY: all clean fclean re
