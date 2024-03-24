#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Menu.hpp"

int main()
{
    std::cout << "Welcome to the Awesome PhoneBook!" << std::endl;
    Menu menu;
    menu.init();
    return 0;
}