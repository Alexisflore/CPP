#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main() {
    ScavTrap scavTrap("ScavTrap");
    scavTrap.attack("target");
    scavTrap.guardGate();
    return 0;
}