#include "ClapTrap.hpp"

int main() {
    ClapTrap clapTrap("ClapTrap");
    ClapTrap clapTrap2(clapTrap);

    clapTrap2.attack("ClapTrap");
    clapTrap2.takeDamage(10);
    clapTrap2.beRepaired(5);

    return 0;
}