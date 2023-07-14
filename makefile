#______________________________________________________________________________#
############################### Target Names ###################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# Name
NAME	= ./cub3d
PROJECT_NAME = cub3d

#______________________________________________________________________________#
############################### Compiler #######################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# Compiler
CC = cc

# Compiler Flags
CFLAGS = -Wall -Wextra -Werror -g

#______________________________________________________________________________#
############################### Libraries ######################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# Libft
LIB_DIR		= ./libft
LIBFT		= $(LIB_DIR)/libft.a
LDFLAGS 	+= -L $(LIB_DIR) -lft

# MinilibX
MLX_DIR		= ./minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a
LDFLAGS 	+= -L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

#______________________________________________________________________________#
############################### Print Variables ################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# Reset
NC = \033[0m

# Colors
YELLOW = \033[0;33m
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
BLACK = \033[0;30
WHITE = \033[0;37m

# Colors
BYELLOW = \033[1;33m
BGREEN = \033[1;32m
BBLUE = \033[1;34m
BRED = \033[1;31m
BPURPLE = \033[1;35m
BCYAN = \033[1;36m
BBLACK = \033[1;30m
BWHITE = \033[1;37m

# One Line Output
OL =\e[1A\r\033[K
CLEAR = \033[2K

#______________________________________________________________________________#
############################### Dependencies ###################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

DEPS_DIR = ./deps
DEPS += -I $(DEPS_DIR)

# Libft
DEPS += -I $(LIB_DIR)/inc

# MinilibX
DEPS += -I $(MLX_DIR)

#______________________________________________________________________________#
############################### Headers ########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

HEADER += cub3d.h
HEADER += mlx.h
HEADER += libft.h

vpath %.h $(DEPS_DIR)

#______________________________________________________________________________#
############################### Path Sources ###################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

SRCS_DIR += ./srcs
SRCS_DIR += ./srcs/parsing
SRCS_DIR += ./srcs/debug
SRCS_DIR += ./srcs/raycasting

PATH_SRCS = $(SRCS_DIR)

#______________________________________________________________________________#
############################### Sources ########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

SRCS += cub3d.c
SRCS += hooks.c
SRCS += parsing.c
SRCS += mallocs.c
SRCS += get_color.c
SRCS += get_textures.c
SRCS += get_player.c
SRCS += exit_and_free.c
SRCS += parsing_utils.c
SRCS += debug.c
SRCS += raycasting.c

#______________________________________________________________________________#
############################### Attribution ####################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

vpath %.c $(PATH_SRCS)

#______________________________________________________________________________#
############################### Objects ########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

OBJS_DIR = ./objs
OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))
CHK_OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(CHK_SRCS))

#______________________________________________________________________________#
############################### Build ##########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

BUILD_DIR = ./build
BUILD = $(addprefix $(BUILD_DIR)/, $(notdir $(OBJS:.o=.d)))

#______________________________________________________________________________#
############################### Progress Bar ###################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# PROGRESS BAR
NB_OBJ = ${words ${OBJS}}
COUNTER = 1
PROGRESS = 0
DONE = 100
SPACE = 0
FILL = 0
EMPTY = 0

define PROGRESS_BAR
	$(eval PROGRESS=$(shell echo $$(($(COUNTER) * 100 / $(NB_OBJ)))))
	$(eval DONE=$(shell echo $$(($(PROGRESS) * 30 / 100))))
	$(eval SPACE=$(shell echo $$((30 - $(DONE)))))
	$(eval FILL=$(shell printf "%*s" ${DONE} | sed 's/ /◼/g'))
	$(eval EMPTY=$(shell printf "%*s" ${SPACE} | sed 's/ /◼/g'))
	printf "\r${CLEAR}$(BCYAN)Compile : $(GREEN)${FILL}$(RED)${EMPTY} $(BWHITE)%3d%%$(END) $(CYAN)%s.c " ${PROGRESS} $1
	$(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))
endef

#______________________________________________________________________________#
############################### Rules ##########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

#_____Build_____#
all: $(MLX) $(LIBFT) $(NAME)
	@echo "--▶ $(BGREEN)all\t$(GREEN)done$(NC)"
	@echo "--------------------------------------------------"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) $(DEPS) -o $@
    #-----Output-----#
	@echo "$(WHITE)\n▶$(BGREEN)$(NAME)\t$(GREEN)Executable created$(NC)"

$(OBJS): $(OBJS_DIR)/%.o: %.c | $(MLX) $(LIBFT) dir where
	@$(CC) $(CFLAGS) -MMD $(DEPS) -c $< -o $@
	@mv $(basename $@).d $(BUILD_DIR)/$(notdir $(basename $@)).d
    #-----Output-----#
	@$(call PROGRESS_BAR, $(basename $(notdir $<)))

# Libraries
$(LIBFT):
	@make --no-print-directory all -C $(LIB_DIR)

$(MLX):
	@printf "$(OL)$(BCYAN)Compiling MinilibX...$(NC)\n"
	@make -s -C $(MLX_DIR)
	@printf "$(BGREEN)MinilibX\t$(GREEN) ready!$(NC)\n"

-include $(BUILD)

# Directories
dir: $(OBJS_DIR) $(BUILD_DIR)

$(OBJS_DIR):
	@mkdir $@

$(BUILD_DIR):
	@mkdir $@

bonus: all

#_____Clean_____#
clean: where_c lclean
	@rm -rf $(OBJS_DIR)
	@rm -rf $(BUILD_DIR)
    #-----Output-----#
	@echo "▶ $(BYELLOW)clean $(YELLOW)Object files removed from $(PROJECT_NAME)$(NC)"
	@echo "▶ \t$(YELLOW)Dependencies files removed from $(PROJECT_NAME)$(NC)"
	@echo "--▶ $(BYELLOW)clean$(YELLOW) done$(NC)"

# Libraries Clean
lclean:
	@make --no-print-directory clean -C $(LIB_DIR)
	@make --no-print-directory clean -sC $(MLX_DIR)

fclean: clean#
	@rm -f $(LIBFT)
	@rm -f $(MLX)
	@rm -f $(NAME)
    #-----Output-----#
	@echo "▶ $(BRED)fclean $(RED)libft.a removed$(NC)"
	@echo "▶ $(BRED)fclean $(RED)libmlx.a removed$(NC)"
	@echo "\t$(RED)$(NAME) removed$(NC)"
	@echo "--▶ $(BRED)fclean$(RED) done$(NC)"

# Current Make
where_c:
	@echo "$(BBLACK)>$(PROJECT_NAME)$(NC)"

where:
	@echo "$(BBLACK)>$(PROJECT_NAME)$(NC)"

re: fclean all

debug:
	$(eval CFLAGS := $(CFLAGS) -g -v)
	@echo $(CFLAGS)
	$(MAKE) fclean --no-print-directory
	$(MAKE) all --no-print-directory

.PHONY: all clean fclean re debug where where_c lclean dir bonus
