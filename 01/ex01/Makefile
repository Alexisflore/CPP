CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = Zombie
OBJS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp ZombieHorde.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re