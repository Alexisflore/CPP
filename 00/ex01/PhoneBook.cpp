#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    contactCount = 0;

}

void PhoneBook::addContact(Contact contact)
{
    if (contactCount < 8)
    {
        contacts.push_back(contact);
        contactCount++;
    }
    else
    {
        contacts.push_back(contact);
        for (int i = 0; i < 7; i++)
        {
            contacts[i] = contacts[i + 1];
        }
        contacts[0] = contact;
    }
}
int PhoneBook::getContactCount()
{
    return contactCount;
}

void PhoneBook::displayContact()
{
    unsigned int i = 0;
    while (i < contactCount)
    {
        std::cout << i << " | ";
        if (contacts.at(i).getFirstName().length() > 10)
        {
            std::cout << contacts.at(i).getFirstName().substr(0, 9) << ".";
        }
        else
        {
            std::cout << contacts.at(i).getFirstName();
        }
        std::cout << " | ";
        if (contacts.at(i).getLastName().length() > 10)
        {
            std::cout << contacts.at(i).getLastName().substr(0, 9) << ".";
        }
        else
        {
            std::cout << contacts.at(i).getLastName();
        }
        std::cout << " | ";
        if (contacts.at(i).getNickName().length() > 10)
        {
            std::cout << contacts.at(i).getNickName().substr(0, 9) << ".";
        }
        else
        {
            std::cout << contacts.at(i).getNickName();
        }
        std::cout << std::endl;
        i++;
    }
}

Contact PhoneBook::getContact(int index)
{
    return contacts.at(index);
}