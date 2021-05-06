CC			:= gcc
CFLAGS		:= -L.
LIBS		:= ar rcs
NAME		:= libasm.a
MAIN		:= main.c
SRCS		:=	ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s
OBJS 		:= $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBS) $(NAME) $(OBJS)

.s.o:
	nasm -f elf64 $<

test: $(NAME)
	$(CC) $(CFLAGS) $(MAIN) $(NAME)
	./a.out
	@rm a.out

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re