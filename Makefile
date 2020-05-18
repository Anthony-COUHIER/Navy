NAME	= navy

CC	= gcc

RM	= rm -f

SRCS	= ./src/main.c \
		./src/connection.c \
		./src/map.c \
		./src/check_map.c \
		./src/map_fill.c \
		./src/game.c \
		./src/check_value.c \
		./src/output.c	\
		./src/hit_or_miss.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra
CFLAGS += -g3

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -g3 ./lib/lib.a

clean:
	make -C lib/ clean
	$(RM) $(OBJS)

fclean: clean
	make -C lib/ fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
