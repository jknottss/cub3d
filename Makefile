NAME				:=	cub3D
NAME_BONUS			:=	
LIBFT_TOOLS_LIB		:=	libft_tools.a
LIBFT_TOOLS_PATH	:=	libft_tools

LIB_PATH			:=	./
MLX_PATH			:=	minilibx_opengl_20191021
MLX_LIB				:=	mlx

OBJ_FOLDER			:=	objs
SRC_FOLDER			:=	srcs

CC					:=	cc
HEADERFILE			:=	cube3d.h

SRC_LIB				:=	

SRCS			:=	ft_cube3d.c \
					engine/ft_engine0.c \
					engine/ft_engine1.c \
					engine/ft_lines0.c \
					engine/ft_lines1.c \
					engine/ft_math.c \
					engine/ft_pixel.c \
					engine/ft_player.c \
					engine/ft_horizontal_ray.c \
					engine/ft_vertical_ray.c \
					engine/ft_background.c \
					engine/ft_texture.c \
					engine/ft_grafic.c \
					engine/ft_geometry.c \
					engine/ft_color.c \
					engine/ft_raycasting0.c \
					engine/ft_raycasting1.c \
					keys/ft_key0.c \
					keys/ft_key1.c \
					keys/ft_key2.c \
					map/ft_file.c \
					map/ft_string.c \
					map/ft_map_array.c \
					map/ft_check_input_map0.c \
					map/ft_check_input_map1.c \
					map/ft_check_input_map2.c \
					map/ft_memory_map0.c \
					map/ft_memory_map1.c \
					errors/ft_error0.c \
					errors/ft_error1.c \
					errors/ft_error2.c \
					errors/ft_error_map.c


OBJS			:=	$(SRCS:%.c=$(OBJ_FOLDER)/%.o)

CFLAGS		:=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_PATH)
	make -C $(LIBFT_TOOLS_PATH)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_TOOLS_PATH) -lft_tools -L$(MLX_PATH) -l$(MLX_LIB) -L/usr/lib -lm -lz -framework OpenGL -framework AppKit -o $(NAME)

$(OBJS): $(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -fr $(OBJ_FOLDER)
	rm -fr $(OBJ_FOLDER_BONUS)
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_TOOLS_PATH) clean

fclean: clean
	rm -fr $(NAME)
	make -C $(LIBFT_TOOLS_PATH) fclean

re: fclean all
	make -C $(LIBFT_TOOLS_PATH) re
	make -C $(LIBFT_PRINTF_PATH) re

leaks:
	leaks --atExit -- ./$(NAME) test_maps/test.cub


.PHONY: clean fclean re