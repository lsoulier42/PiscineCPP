NAME= calepin
SRCS= Calepin.cpp Contact.cpp main.cpp Program.cpp
OBJS= $(SRCS:.cpp=.o)
CC= clang++
CFLAGS= -Wall -Wextra -Werror

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all	
.PHONY: all clean fclean re
