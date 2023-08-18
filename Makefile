CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra

LIB_DIR	= ./libft
LIB_NAME	= $(LIB_DIR)/libft.a
CFLAGS_PF = -L $(LIB_DIR) -lft

MLX_DIR		= ./minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a
LDFLAGS 	+= -L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

SRCS += get_color.c
SRCS += get_player.c
SRCS += get_textures.c
SRCS += init_sprite.c
SRCS += mallocs.c
SRCS += parsing_utils.c
SRCS += parsing.c
SRCS += state_machine.c
SRCS += check_map.c

SRCS += cub3d.c
SRCS += door.c
SRCS += exit_and_free.c
SRCS += hooks.c
SRCS += movement.c
SRCS += raycasting_utils.c
SRCS += raycasting.c
SRCS += sprite.c
SRCS += texture.c
SRCS += window.c
SRCS += init.c
SRCS += print_error.c
SRCS += check_map_char.c

SRCS += debug.c

SRCS_DIR	= srcs/
SRCS_PATH	= $(addprefix $(SRCS_DIR), $(SRCS))

B_SRCS += get_color.c
B_SRCS += get_player.c
B_SRCS += get_textures.c
B_SRCS += init_sprite.c
B_SRCS += mallocs.c
B_SRCS += parsing_utils.c
B_SRCS += parsing.c
B_SRCS += state_machine.c
B_SRCS += check_map.c
B_SRCS += check_map_char.c
B_SRCS += print_error.c

B_SRCS += hooks.c
B_SRCS += door.c
B_SRCS += movement.c

B_SRCS += minimap_utils.c
B_SRCS += minimap.c

B_SRCS += cub3d.c
B_SRCS += exit_and_free.c
B_SRCS += init.c
B_SRCS += window.c

B_SRCS += raycasting_utils.c
B_SRCS += raycasting.c
B_SRCS += sprite.c
B_SRCS += texture.c


B_SRCS += debug.c

B_SRCS_DIR	= srcs_bonus/
B_SRCS_PATH	= $(addprefix $(SRCS_B_DIR), $(B_SRCS))

NAME	=	cub3d
B_NAME	=	cub3d_bonus

DEPS	+=	cub3d.h
DEPS	+=	struct.h

INCLUDE		+= -I deps/
INCLUDE		+= -I libft/inc/
INCLUDE		+= -I minilibx-linux/

DEPS_DIR	= deps/
DEPS_PATH	= $(addprefix $(DEPS_DIR), $(DEPS))

OBJS		=	$(SRCS:.c=.o)
OBJS_DIR	=	objs/
OBJS_PATH	=	$(addprefix $(OBJS_DIR), $(OBJS))

B_OBJS		=	$(B_SRCS:.c=.o)
B_OBJS_DIR	=	bonus_objs/
B_OBJS_PATH	=	$(addprefix $(B_OBJS_DIR), $(B_OBJS))

LIBFT = ./libft/libft.a
MAKEFILE	= Makefile

all:		$(NAME)

bonus:		$(B_NAME)

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR) --no-print-directory

$(MLX):
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

$(B_NAME): $(MAKEFILE) $(MLX) $(LIBFT) $(B_OBJS_PATH) $(DEPS_PATH)
	@$(CC) $(CFLAGS) $(B_OBJS_PATH) $(CFLAGS_PF) -o $(B_NAME) -g

$(NAME): $(MAKEFILE) $(MLX) $(LIBFT) $(OBJS_PATH) $(DEPS_PATH)
	@$(CC) $(CFLAGS) $(OBJS_PATH) $(CFLAGS_PF) -o $(NAME)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c $(DEPS_PATH)
		@mkdir -p $(OBJS_DIR)
		${CC} $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(B_OBJS_DIR)%.o: $(B_SRCS_DIR)%.c $(DEPS_PATH)
		@mkdir -p $(B_OBJS_DIR)
		${CC} $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean_lib:
	@$(MAKE) clean -C $(LIB_DIR) --no-print-directory
	@$(MAKE) clean -C $(MLX_DIR) --no-print-directory

fclean_lib:
	@$(MAKE) fclean -C $(LIB_DIR) --no-print-directory

clean: clean_lib
	@$(RM) -rf ${OBJS_DIR} $(B_OBJS_DIR)

fclean:	clean fclean_lib
	@$(RM) -f ${NAME} $(NAME).vgr $(B_NAME)

re:			fclean all

.PHONY:	all bonus valgrind clean fclean re
