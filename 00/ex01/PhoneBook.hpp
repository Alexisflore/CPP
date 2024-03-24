/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:35:36 by alfloren          #+#    #+#             */
/*   Updated: 2024/02/27 16:45:22 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Create a class PhoneBook with a private section containing 8 instances maximum of the Contact class.
// If a nineth contact is created, this contact replace the older one without dynamic memory allocation.
#pragma once
#include "Contact.hpp"
#include <vector>

class PhoneBook
{
    public:
        PhoneBook();
        void    addContact(Contact contact);
        void    displayContact();
        int    getContactCount();
        Contact getContact(int index);
    private:
        std::vector<Contact> contacts;
        unsigned int     contactCount;
};
