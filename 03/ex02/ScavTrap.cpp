#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap name constructor" << std::endl;
    this->_hitPoints = 100; 
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & src) {
    std::cout << "ScavTrap copy constructor" << std::endl;
    *this = src;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
    std::cout << "ScavTrap copy assignment operator" << std::endl;
    if (this != &rhs) {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

void ScavTrap::attack(std::string const & target) {
    if (this->_hitPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " is dead and cannot attack" << std::endl;
        return;
    }
    if (this->_energyPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " is out of energy and cannot attack" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl;
}

