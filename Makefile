NAME=myfdf

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

SRC		= main.c parser.c
OBJ		= $(SRC:%.c=%.o)

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I$(LIBFTDIR) -g #-I/usr/include -Imlx_linux -O3
LFLAGS		= -g #-Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $^ $(LFLAGS) -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:		all clean fclean re
