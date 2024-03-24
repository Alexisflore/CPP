#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ScavTrap scavTrap("ScavTrap");
    scavTrap.attack("target");
    scavTrap.guardGate();
    FragTrap fragTrap("FragTrap");
    fragTrap.attack("target");
    fragTrap.highFivesGuys();
    return 0;
}