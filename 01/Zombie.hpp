#pragma once
#include <iostream>
#include <string>

class Zombie
{
    public:
        Zombie( std::string _name);
        ~Zombie( void );
        void		announce( void ) const;
        Zombie*     newZombie( std::string name );
        void        randomChump( std::string name );
    private:
        std::string	name;
};