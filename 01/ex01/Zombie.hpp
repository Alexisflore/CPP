#pragma once
#include <iostream>
#include <string>

class Zombie
{
    public:
        Zombie();
        ~Zombie( void );
        void            announce( void ) const;
        Zombie*         newZombie( std::string name );
        void            randomChump( std::string name );
        static Zombie   *zombieHorde(int N, std::string name);
    private:
        std::string	name;
};