/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:40:55 by alfloren          #+#    #+#             */
/*   Updated: 2024/02/21 16:29:35 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Function that find the last character in a string that is not a whitespace
int findLastNonWhitespaceCharacter(const std::string& str) {
    unsigned long i = str.length() - 1;
    while (i >= 0 && std::isspace(str[i])) {
        i--;
    }
    return i;
}

// Function that find the first character in a string that is not a whitespace
int findFirstNonWhitespaceCharacter(const std::string& str) {
    unsigned long i = 0;
    while (i < str.length() && std::isspace(str[i])) {
        i++;
    }
    return i;
}

int main(int argc, char* argv[]) {
    // Check if an argument is provided
    if (argc < 2) {
        std::cout << "*LOUD AND UNBEARABLE FEEDBACK NOISE" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        std::string inputString = argv[i];
        if (inputString.length() == 0) {
            continue;
        }
        unsigned long last = findLastNonWhitespaceCharacter(inputString);
        unsigned long first = findFirstNonWhitespaceCharacter(inputString);
        for (unsigned long i = first; i <= last; i++) {
            char& c = inputString[i];
            c = std::toupper(c);
            std::cout << c;
        }
        if (i != argc - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}
