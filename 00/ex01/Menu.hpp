#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <vector>

class Menu
{
    public:
        Menu();
        void init();
    private:
        void displayMenu();
        void addContact();
        void searchContact();
        int getUserInput();
        void processInput(int input);
        void exit();
        PhoneBook contacts;
};