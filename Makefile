# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcurty-g <rcurty-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 13:06:04 by rcurty-g          #+#    #+#              #
#    Updated: 2025/02/11 13:36:40 by rcurty-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                    NAMES                                     #
#==============================================================================#

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
MLXFLAGS = -L ./minilibx-linux -lmlx -lXext -lX11 -lm
INC = -I./includes
LIBFT = ./libft/libft.a
MLX = ./minilibx-linux/libmlx_Linux.a
RM = rm -rf

GENERAL = main kill init
PARSING = extension validation_1 validation_2
MAP = utils free
RENDER = render
MOVEMENTS = movement_1 movement_2

NAME = so_long

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

VPATH += src
VPATH += src/parsing
VPATH += src/map
VPATH += src/render
VPATH += src/movements

#==============================================================================#
#                                    FILES                                     #
#==============================================================================#

SRC +=	$(addsuffix .c, $(GENERAL))
SRC +=	$(addsuffix .c, $(PARSING))
SRC +=	$(addsuffix .c, $(MAP))
SRC +=	$(addsuffix .c, $(RENDER))
SRC +=	$(addsuffix .c, $(MOVEMENTS))

OBJ_DIR = obj
OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(MLX):
	$(MAKE) -C ./minilibx-linux

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(BONUS_INC)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx-linux
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./minilibx-linux
	$(RM) $(NAME) $(OBJ_DIR)

re: fclean all

download:
	@wget https://cdn.intra.42.fr/document/document/27195/minilibx-linux.tgz
	echo ola
	@tar -xzf minilibx-linux.tgz
	@rm -rf minilibx-linux.tgz
