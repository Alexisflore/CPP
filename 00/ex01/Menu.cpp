#include "Menu.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

Menu::Menu()
{
}

void Menu::displayMenu()
{
    std::cout << "Please select an option:" << std::endl;
    std::cout << "1. ADD" << std::endl;
    std::cout << "2. SEARCH" << std::endl;
    std::cout << "3. EXIT" << std::endl;
}

void Menu::init()
{
    int input;
    while (true)
    {
        displayMenu();
        input = getUserInput();
        processInput(input);
    }
}

int Menu::getUserInput()
{
    int userOption = 0;
    std::string line;

    std::cout << "Type in 1-3" << std::endl;
    std::getline(std::cin, line);
    try{
        userOption = std::stoi(line);
    }catch(const std::exception& e)
    {
    }
    return userOption;
}

void Menu::processInput(int input)
{
    if (input < 1 || input > 3)// bad input
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (input == 1)
    {
        addContact();
    }
    else if (input == 2)
    {
        searchContact();
    }
    else if (input == 3)
    {
        exit();
    }
}

void Menu::addContact()
{
    std::cout << "Add Contact" << std::endl;
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cout << "First Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Nick Name: ";
    std::getline(std::cin, nickName);
    std::cout << "Phone Number (ex: 0686357278): ";
    std::getline(std::cin, phoneNumber);
    while (Contact::isValidPhoneNumber(phoneNumber) == false)
    {
        std::cout << "Invalid phone number" << std::endl;
        std::cout << "Phone Number: ";
        std::getline(std::cin, phoneNumber);
    }
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
    Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
    contacts.addContact(newContact);
}

void Menu::searchContact()
{
    if (contacts.getContactCount() == 0)
    {
        std::cout << "No contacts available" << std::endl;
        std::cout << std::endl;
        return;
    }
    std::cout << "Here are the contacts" << std::endl;
    contacts.displayContact();
    std::cout << "Choose a contact by index" << std::endl;
    int index = -1;
    std::string line;
    getline(std::cin, line);
    try{
        index = std::stoi(line);
    }catch(const std::exception& e)
    {
    }
    if (index < 0 || index >= contacts.getContactCount())
    {
        std::cout << "Invalid choice. Enter a number between 0 and " << contacts.getContactCount() - 1 << std::endl;
        return;
    }
    std::cout << "You choose contact at index: " << index << std::endl;
    std::cout << std::endl;
    Contact::displayContact(contacts.getContact(index));
    std::cout << std::endl;
}

void Menu::exit()
{
    std::cout << "Exiting" << std::endl;
    std::exit(0);
}