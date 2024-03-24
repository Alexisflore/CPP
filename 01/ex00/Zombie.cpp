#include "Zombie.hpp"

Zombie::Zombie( std::string _name) : name(_name)
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