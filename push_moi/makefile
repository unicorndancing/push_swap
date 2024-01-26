CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
NAME = push
OBJS = $(SRCS:.c=.o)

SRCS = 	error.c \
		initialize.c \
		initialize_2.c \
		verif_value.c \
		lstaddback.c \
		lstnew.c \
		test.c \
		push_swap.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		free.c \
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