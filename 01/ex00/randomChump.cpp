#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
    Zombie zombie = Zombie(name);
    zombie.announce();
}