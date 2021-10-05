NAME		= fdf

LIBFT_DIR	= ./libft

INC_DIR		= headers

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= $(shell find $(SRC_DIR) -name *.c -type f)
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC			= gcc
RM			= rm -f

FLAGS_WARN	= -Wall -Wextra -Werror
FLAGS_INC	= -I$(INC_DIR) -I$(LIBFT_DIR) -I/usr/local/include -Imlx_linux
FLAGS_DEBUG	= -g
FLAGS_LIBFT =  -L$(LIBFT_DIR) -lft
FLAGS_MLX	= -L/usr/local/lib -Lmlx_Linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

CFLAGS		= $(FLAGS_WARN) $(FLAGS_INC)
LFLAGS		= $(FLAGS_LIBFT) $(FLAGS_MLX)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $^ -o $@ $(LFLAGS)

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re:	fclean all

# Debugging functions

debug:		CFLAGS += $(FLAGS_DEBUG)
debug:		LFLAGS += $(FLAGS_DEBUG)
debug:		re

.PHONY:		all clean fclean re
