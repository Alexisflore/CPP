#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap name constructor" << std::endl;
    this->_hitPoints = 100; 
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const & src) {
    std::cout << "FragTrap copy constructor" << std::endl;
    *this = src;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
    std::cout << "FragTrap copy assignment operator" << std::endl;
    if (this != &rhs) {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << this->_name << " requests a high five" << std::endl;
}

void FragTrap::attack(std::string const & target) {
    if (this->_hitPoints == 0) {
        std::cout << "FragTrap " << this->_name << " is dead and cannot attack" << std::endl;
        return;
    }
    if (this->_energyPoints == 0) {
        std::cout << "FragTrap " << this->_name << " is out of energy and cannot attack" << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
}

