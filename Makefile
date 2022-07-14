# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 21:10:18 by rfelicio          #+#    #+#              #
#    Updated: 2022/07/14 08:52:17 by rfelicio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# project name
NAME		:= fractol

# Flags
MLX_FLAGS	:= -lmlx -Ilmlx -lXext -lX11
LEAK_FLAGS	:= 

ifeq ($(shell uname),Darwin) # MacOS
	MLX_FLAGS	:= -lmlx -framework OpenGL -framework AppKit
	LEAK_FLAGS	:= -g3 -fsanitize=address
endif

# Libft
LIBFT_DIR		:= ./libs/libft
LIBFT_HEADERS 	:= $(LIBFT_DIR)/include
LIBFT			:= $(LIBFT_DIR)/libft.a
LIBFT_MAKE		:= make -C $(LIBFT_DIR)
LIBFT_CLEAN		:= make clean -C $(LIBFT_DIR)
LIBFT_FCLEAN	:= make fclean -C $(LIBFT_DIR)
LIBFT_RE		:= make re -C $(LIBFT_DIR)
LIBFT_FLAGS		:= -L $(LIBFT_DIR) -lft

# Fractol
HEADERS_DIR := ./includes
HEADERS     := -I $(HEADERS_DIR) -I $(LIBFT_HEADERS)

SRCS_DIR	:= ./src
SRCS		:= $(SRCS_DIR)/main.c				\
			   $(SRCS_DIR)/ft_put_errors.c		\

OBJS_DIR	:= ./obj
OBJS		:= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

# compiler configs
CC			:= gcc
CC_FLAGS	:= -Wall -Wextra -Werror

FLAGS		:= $(CC_FLAGS) $(MLX_FLAGS) $(LIBFT_FLAGS) $(LEAK_FLAGS)

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "Compilling..."
	$(CC) $(CC_FLAGS) $(HEADERS) $< -c -o $@
	@echo

$(NAME): $(OBJS_DIR) $(OBJS)
	@echo "Linking..."
	$(LIBFT_MAKE)
	$(CC) $(HEADERS) $(FLAGS) $(OBJS) -o $(NAME)
	@echo

$(OBJS_DIR):
	@mkdir -p obj

clean:
	@echo "Cleaning object files..."
	@echo
	$(LIBFT_CLEAN)
	@echo
	@rm -rf obj
	@echo "Finished cleaning object files"
	@echo

fclean: clean
	@echo "Cleaning executable: $(NAME)"
	@rm -rf $(NAME)
	@echo

re: fclean all

.PHONY: all clean fclean re
