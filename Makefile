# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcurty-g <rcurty-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 13:06:04 by rcurty-g          #+#    #+#              #
#    Updated: 2025/02/13 14:16:06 by rcurty-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  SETTINGS                                    #
#==============================================================================#

NAME = so_long
CC       = cc
CFLAGS   = -g -Wall -Wextra -Werror
MLXFLAGS = -L ./minilibx-linux -lmlx -lXext -lX11 -lm
INC      = -I./includes
LIBFT    = ./libft/libft.a
MLX      = ./minilibx-linux/libmlx_Linux.a
RM       = rm -rf

#==============================================================================#
#                                   SOURCES                                    #
#==============================================================================#

SRC_DIR  = src
OBJ_DIR  = obj

SRC      = main kill init render utils free \
           validate_extension validate_borders validate_collectibles \
           movement_utils movement_handler

VPATH    = $(SRC_DIR) $(SRC_DIR)/parsing $(SRC_DIR)/movements
OBJS     = $(addprefix $(OBJ_DIR)/, $(SRC:=.o))

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MLX):
	@$(MAKE) -C ./minilibx-linux

$(OBJ_DIR):
	@mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo "Compilation completed successfully!"

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS)
	@echo "Cleanup completed."

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(NAME) $(OBJ_DIR)
	@echo "Everything is clean!"

re: fclean all

download:
	@wget https://cdn.intra.42.fr/document/document/27195/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz
	@rm -rf minilibx-linux.tgz
	@echo "MiniLibX download and extraction completed successfully!"
