/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:40:55 by alfloren          #+#    #+#             */
/*   Updated: 2024/02/27 12:03:09 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char* argv[]) {
    // Check if an argument is provided
    if (argc < 2) {
        std::cout << "*LOUD AND UNBEARABLE FEEDBACK NOISE" << std::endl;
        return 0;
    }
    unsigned long i = 0;
    while (argv[++i]) {
        std::string arg = argv[i];
        for (unsigned long j = 0; j < arg.length(); j++) {
            char c = arg[j];
            std::cout << (char)std::toupper(c);
        }
    }
    std::cout << std::endl;
    return 0;
}
