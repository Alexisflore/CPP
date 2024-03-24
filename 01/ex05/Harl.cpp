#include "Harl.hpp"

#include <algorithm> // Add this line to include the <algorithm> header

Harl::Harl() {}

Harl::~Harl() {}

std::string const Harl::mood[] = {"DEBUG", "INFO", "ERROR", "WARNING"};

void Harl::complain(std::string level) {
    //use pointer to member function to call the right function

    static void (Harl::*log[4])() = {&Harl::debug, &Harl::info, &Harl::error, &Harl::warning};
    //call function in one line thanks to level
    std::size_t i;
    i = 0;

    while (i < 4 && mood[i] != level) {
        i++;
    }
    if (i < 4) {
        (this->*log[i])();
    }
    else {
        std::cerr << "Unknown level" << std::endl;
    }
}

void Harl::debug() {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Harl::info() {
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::error() {
    std::cerr << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::warning() {
    std::cout << "I think i deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}