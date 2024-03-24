#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie( void )
{
    std::cout << name << " is dead" << std::endl;
}
void	Zombie::announce( void ) const
{
    std::cout << name << ": " <<  "BraiiiiiiinnnzzzZ..." << std::endl;
}