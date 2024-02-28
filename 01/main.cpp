#include "Zombie.hpp"

int main()
{
    Zombie zombie = Zombie("Zombie");
    zombie.announce();
    zombie.randomChump("Chump");
    Zombie* zombie2 = zombie.newZombie("Zombie2");
    zombie2->announce();
    delete zombie2;
    return 0;
}