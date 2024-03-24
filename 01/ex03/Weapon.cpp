#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon( void )
{
}

std::string const &Weapon::getType( void ) const
{
    return _type;
}

const void Weapon::setType(std::string type)
{
    _type = type;
}
// Path: ex03/main.cpp