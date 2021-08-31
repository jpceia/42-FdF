NAME=myfdf

SRC		= main.c
OBJ		= $(SRC:%.c=%.o)

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3
LFLAGS		= -Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(CLFAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $^ $(LFLAGS) -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:		all clean fclean re