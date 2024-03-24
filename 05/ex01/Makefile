CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = Bureaucrat
OBJS = Bureaucrat.cpp main.cpp Form.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re