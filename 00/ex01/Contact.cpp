/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:09:00 by macbookpro        #+#    #+#             */
/*   Updated: 2024/02/27 17:04:20 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string _firstName,
                std::string _lastName,
                std::string _nickName,
                std::string _phoneNumber,
                std::string _darkestSecret)
    : firstName(_firstName),
    lastName(_lastName),
    nickName(_nickName),
    phoneNumber(_phoneNumber),
    darkestSecret(_darkestSecret)
    {
    }

bool Contact::isValidPhoneNumber(std::string phoneNumber)
{
    if (phoneNumber.length() != 10 || phoneNumber[0] != '0' || phoneNumber[1] == '0')
        return false;
    for (unsigned long i = 0; i < phoneNumber.length(); i++)
    {
        if (!std::isdigit(phoneNumber[i]))
            return false;
    }
    return true;
}

std::string Contact::getFirstName()
{
    return firstName;
}

std::string Contact::getLastName()
{
    return lastName;
}

std::string Contact::getNickName()
{
    return nickName;
}

std::string Contact::getPhoneNumber()
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret()
{
    return darkestSecret;
}

void Contact::displayContact(Contact contact)
{
    std::cout << "First Name: " << contact.firstName << std::endl;
    std::cout << "Last Name: " << contact.lastName << std::endl;
    std::cout << "Nick Name: " << contact.nickName << std::endl;
    std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << contact.darkestSecret << std::endl;
}