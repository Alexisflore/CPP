CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = btc
OBJS = main.cpp BitcoinExchange.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all