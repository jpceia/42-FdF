NAME		= libft.a

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		:= \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_calloc.c \
			ft_strlen.c \
			ft_strcat.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strdup.c \
			ft_strndup.c \
			ft_substr.c \
			ft_strmapi.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_strwc.c \
			ft_contains.c \
			ft_strreverse.c \
			ft_straddc.c \
			ft_empty_string.c \
			ft_atoi.c \
			ft_itoa.c \
			ft_atol.c \
			ft_lltoa.c \
			ft_lltoa_base.c \
			ft_ulltoa.c \
			ft_ulltoa_base.c \
			ft_imin.c \
			ft_imax.c \
			ft_mod.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_error.c \
			ft_putstr_error.c \
			ft_putendl_error.c \
			ft_putnbr_error.c \
			ft_get_next_line.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

SRCS		:= $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I.

all:		$(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			ar rc $@ $(OBJS)

clean:
			$(RM) -r $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
