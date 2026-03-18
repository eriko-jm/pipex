
NAME = pipex
BONUS_NAME = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -fr

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =	src/pipex.c \
		src/processes.c \
		src/path.c \
		src/parse.c \
		

OBJS = $(SRC:.c=.o)

BONUS =	bonus/pipex_bonus.c \
		bonus/processes_bonus.c \
		bonus/path_bonus.c \
		bonus/parse_bonus.c \


BONUS_O = $(BONUS:.c=.o)

INCLUDES = -Iincludes -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_O) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_O) $(LIBFT) -o $(BONUS_NAME)


$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


src/%.o: src/%.c includes/pipex.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus/%.o: bonus/%.c includes/pipex_bonus.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_O)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
