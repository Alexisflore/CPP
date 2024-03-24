#include "Zombie.hpp"

int main()
{
    Zombie *zombies;
    zombies = Zombie::zombieHorde(10, "Pierre");
    for (int i = 0; i < 10; i++)
    {
        zombies[i].announce();
    }
    delete [] zombies;
}