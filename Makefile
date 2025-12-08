# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 12:33:09 by anomourn          #+#    #+#              #
#    Updated: 2024/10/24 13:00:18 by sdell-er         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -O3

NAME = miniRT

SRCS =

all: $(NAME)

SRCS =	./get_next_line/get_next_line.c \
				./get_next_line/get_next_line_utils.c \
				srcs/main_bonus.c \
				srcs/parsing/parsing_bonus.c \
				srcs/parsing/read_check_assign_bonus.c \
				srcs/parsing/get_number_of_elements_bonus.c \
				srcs/parsing/read_check_utils_bonus.c \
				srcs/parsing/utils_checks_bonus.c \
				srcs/parsing/ft_atof_bonus.c \
				srcs/parsing/Ambient_bonus.c \
				srcs/parsing/Camera_bonus.c \
				srcs/parsing/Light_bonus.c \
				srcs/parsing/Sphere_bonus.c \
				srcs/parsing/Plane_bonus.c \
				srcs/parsing/Cylinder_bonus.c \
				srcs/parsing/extras_for_bonus.c \
				srcs/parsing/paraboloid_bonus.c \
				srcs/vectors/vect_operations_bonus.c \
				srcs/vectors/vect_properties_bonus.c \
				srcs/vectors/vect_creation_bonus.c \
				srcs/user_interface/change_properties_bonus.c \
				srcs/user_interface/display_properties_bonus.c \
				srcs/user_interface/display_h_p_bonus.c \
				srcs/user_interface/change_h_p_bonus.c \
				srcs/user_interface/display_ambient_bonus.c \
				srcs/user_interface/display_shapes_bonus.c \
				srcs/user_interface/handle_input_bonus.c \
				srcs/user_interface/mlx_hooks_bonus.c \
				srcs/raytracing/create_lighting_bonus.c \
				srcs/raytracing/obj_intersection_bonus.c \
				srcs/raytracing/hyperbolic_paraboloid_intersection_bonus.c \
				srcs/raytracing/h_p_intersection_utils_bonus.c \
				srcs/raytracing/obj_intersection_utils_bonus.c \
				srcs/raytracing/trace_rays_bonus.c \
				srcs/raytracing/color_operations_bonus.c \
				srcs/minirt_utils_bonus.c \
				srcs/bmp.c \
				srcs/init_bonus.c

MAKE_LIBFT = make -C libft
MAKE_MLX = make -C minilibx-linux > /dev/null 2>&1

OBJS = $(SRCS:.c=.o)

RM = rm -f

.SILENT: $(OBJS)





all: $(NAME)

$(NAME): $(OBJS)
		@echo "\e[0;33mCompiling...\e[0;m"
		@$(MAKE_LIBFT) > /dev/null
		@$(MAKE_MLX) > /dev/null
		@$(CC) $(CC_FLAGS) $(OBJS) -Lmlx_linux ./libft/libft.a ./minilibx-linux/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)
		@echo "\e[0;32mCompleted! 🤠\e[0;m"
		
clean:
		@echo "Cleaning up..."
		@$(MAKE) clean -C ./libft > /dev/null
		$(RM) $(OBJS)
		@echo "\e[0;31mCleaned! 🧹\e[0;m"

fclean:
		@echo "\e[0;32mWait ...\e[0;m"
		@$(MAKE) fclean -C ./libft > /dev/null
		$(RM) $(OBJS) $(NAME)
		@$(MAKE) clean -C ./minilibx-linux > /dev/null
		@echo "\e[0;32mCleaned! 🧹\e[0;m"

re: fclean all

.PHONY: all clean fclean re