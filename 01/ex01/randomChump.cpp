#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
    Zombie zombie = Zombie();
    zombie.name = name;
    zombie.announce();
}