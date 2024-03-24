#pragma once
#include <iostream>
#include <string>
#include "Weapon.hpp"


class HumanA
{   
    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA( void );
        void attack(void);
        const void setType(std::string type);
        void getType(void);
        void setWeapon(Weapon weapon);
    private:
        std::string _name;
        Weapon& _weapon;
};