#pragma once
#include <iostream>
#include <string>
#include "Weapon.hpp"


class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB( void );
        void attack(void);
        const void setType(std::string type);
        void getType(void);
        void setWeapon(Weapon& weapon);// Change reference to pointer
    private:
        std::string _name;
        // initialise a weapon reference
        Weapon* _weapon;
};
