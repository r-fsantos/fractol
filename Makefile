# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 21:10:18 by rfelicio          #+#    #+#              #
#    Updated: 2022/07/05 08:44:27 by rfelicio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# project name
NAME		:= fractol


# mlx specs
MLX_FLAGS	:= -lmlx -Ilmlx -lXext -lX11

# add Linux Leak flags
LEAK_FLAGS	:= -g3 -fsanitize=address

ifeq ($(shell uname),Darwin) # MacOS
	MLX_FLAGS	:= -lmlx -framework OpenGL -framework AppKit
	LEAK_FLAGS	:= -g3 -fsanitize=address
endif

# compiler configs
CC			:= clang
CC_FLAGS	:= -Wall -Wextra -Werror
# CC_FLAGS	= 

# FLAGS		:= $(MLX_FLAGS) $(CC_FLAGS) $(LEAK_FLAGS)
FLAGS		:= $(MLX_FLAGS) $(LEAK_FLAGS)

SRCS_DIR	:= ./src
SRCS		:= $(SRCS_DIR)/main.c

OBJS_DIR	:= ./obj
OBJS		:= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(FLAGS) $< -c -o $@

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR):
	@mkdir -p obj

clean:
	@echo "Cleaning object files..."
	@echo
	rm -rf obj
	@echo
	@echo "Finished cleaning object files"
	@echo

fclean: clean
	@echo "Cleaning executable: $(NAME)"
	rm -rf $(NAME)
	@echo

re: fclean all

.PHONY: all clean fclean re
