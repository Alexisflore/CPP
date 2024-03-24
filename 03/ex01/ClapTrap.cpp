#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(100), _energyPoints(100), _attackDamage(10) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(100), _energyPoints(100), _attackDamage(10) {
    std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(std::string const & target) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " is dead and cannot attack" << std::endl;
        return;
    }
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " is out of energy and cannot attack" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
        return;
    }
    if (amount > this->_hitPoints) {
        std::cout << "ClapTrap " << this->_name << " takes " << this->_hitPoints << " points of damage and dies!" << std::endl;
        this->_hitPoints = 0;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
    this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " is out of energy and cannot be repaired" << std::endl;
        return;
    }
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " is dead and cannot be repaired" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points!" << std::endl;
    this->_hitPoints += amount;
    this->_energyPoints -= 1;
}

