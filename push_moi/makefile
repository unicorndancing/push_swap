CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
NAME = libftpush
OBJS = $(SRCS:.c=.o)

SRCS = 	error.c \
		verif_value.c \
		initialize.c \
		lstaddback.c \
		lstnew.c \
		test.c \
		main.c 
		

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re