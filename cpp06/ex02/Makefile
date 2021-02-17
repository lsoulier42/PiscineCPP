NAME= dynamic
SRCS= main.cpp A.cpp B.cpp C.cpp Base.cpp utils.cpp
OBJS= $(SRCS:.cpp=.o)
CC= clang++
CFLAGS= -Wall -Wextra -Werror -std=c++98

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
