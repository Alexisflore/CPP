/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:19 by alfloren          #+#    #+#             */
/*   Updated: 2024/02/27 16:32:00 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Create a class Contact with a private section containing first name,
//last name, phone number and darkest secret.
#pragma once
#include <iostream>
#include <string>

class Contact
{
    public:
       Contact(std::string _firstName = "", std::string _lastName = "", std::string _nickName = "", std::string _phoneNumber = "", std::string _darkestSecret = "");
        static bool isValidPhoneNumber(std::string phoneNumber);
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
        static void displayContact(Contact contact);
    private:
        std::string	firstName;
        std::string	lastName;
        std::string	nickName;
        std::string	phoneNumber;
        std::string	darkestSecret;
};