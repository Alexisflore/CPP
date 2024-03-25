CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = ex01
OBJS = main.cpp Span.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re