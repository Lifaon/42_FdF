# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 20:02:57 by mlantonn          #+#    #+#              #
#    Updated: 2018/02/22 17:59:14 by mlantonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
MAG = \033[35m
CYA = \033[36m
EOC = \033[37m

NAME = FdF
DIR_NAME = FdF
LIBFT_DIR = libft
MLX_DIR = mlx_macOS

CFLAGS = -Wall -Wextra -Werror
FMWKS = -framework OpenGL -framework AppKit

LIBS = $(LIBFT) $(LIBMLX)
LIBFT = -L $(LIBFT_DIR) -lft
LIBMLX = -L $(MLX_DIR) -lmlx

INCS = $(INC) $(INCMLX)
INC = -I includes -I $(LIBFT_DIR)/includes
INCMLX = -I $(MLX_DIR)

OBJS = $(SRCS:.c=.o)
OBJS_DIR = objs
OBJS_SUB_DIRS = draw init events
OBJS_PRE = $(addprefix $(OBJS_DIR)/, $(OBJS))

SRCS_DIR = srcs
SRCS =	draw/color_pixel.c \
		draw/draw_image.c \
		draw/draw_options.c \
		draw/draw_segment.c \
		draw/write_options.c \
		events/altitude.c \
		events/color.c \
		events/move.c \
		events/reset.c \
		events/zoom.c \
		init/arr_init.c \
		init/data_init.c \
		init/get_origins.c \
		init/img_init.c \
		init/mlx_init.c \
		init/var_init.c \
		free_data.c \
		main.c

.PHONY = all $(OBJS_DIR) $(NAME) clean del fclean re

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "gcc $(CFLAGS) $(INCS) -c $^ -o $(CYA)$@$(EOC)"
	@gcc $(CFLAGS) $(INCS) -c $^ -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(addprefix $(OBJS_DIR)/, $(OBJS_SUB_DIRS))

$(NAME): $(OBJS_DIR) $(OBJS_PRE)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@echo "gcc $(CFLAGS) $(OBJS_PRE) $(LIBS) $(FMWKS) -o $(MAG)$(NAME)$(EOC)"
	@gcc $(CFLAGS) $(OBJS_PRE) $(LIBS) $(FMWKS) -o $(NAME)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@echo "$(RED)rm -rf$(EOC) $(OBJS_DIR) from $(DIR_NAME)"
	@rm -rf $(OBJS_DIR)

del:
	@make del -C $(LIBFT_DIR)
	@make del -C $(MLX_DIR)
	@echo "$(RED)rm -rf$(EOC) $(NAME)"
	@rm -rf $(NAME)

fclean: clean del

re: fclean all
