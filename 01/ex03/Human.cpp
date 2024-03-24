#include "HumanA.hpp"
#include "HumanB.hpp"


HumanB::HumanB(std::string name)
: _name(name)
{
}

void HumanB::setWeapon(Weapon& we)
{
    _weapon = &we; // Fix: Assign the weapon using the copy constructor.
}

void HumanB::attack(void)
{
    std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

HumanB::~HumanB( void )
{
    std::cout << _name << " is dead" << std::endl;
}

const void HumanB::setType(std::string type)
{
    _weapon->setType(type);
}

void HumanB::getType(void)
{
    _weapon->getType();
}

const void HumanA::setType(std::string type)
{
    _weapon.setType(type);
}

void HumanA::getType(void)
{
    _weapon.getType();
}

HumanA::HumanA(std::string name, Weapon& weapon)
: _name(name), _weapon(weapon)
{
}

void HumanA::setWeapon(Weapon weapon)
{
    _weapon = weapon;
}

void HumanA::attack(void)
{
    std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}

HumanA::~HumanA( void )
{
    std::cout << _name << " is dead" << std::endl;
}