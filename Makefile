NAME = libft.a

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
OBJECT_FILES =  ft_strjoin.o ft_strlen.o ft_strjoin.o ft_split.o

all: my

my: $(OBJECT_FILES)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT_FILES)

fclean: clean 
	rm -f $(NAME)

re: fclean all