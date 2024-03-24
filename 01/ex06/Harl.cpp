#include "Harl.hpp"

#include <algorithm> // Add this line to include the <algorithm> header

Harl::Harl() {
}

std::string const Harl::mood[] = {"DEBUG", "INFO", "ERROR", "WARNING"};

Harl::~Harl() {}


void Harl::complain(std::string level) {
    std::size_t i;
    i = 0;

    while (i < 4 && mood[i] != level) {
        i++;
    }
    switch (i)
    {
    case (0):
        debug();
        break;
    case (1):
        info();
        break;
    case (2):
        error();
        break;
    case (3):
        warning();
        break;
    default:
        std::cerr << "Unknown level" << std::endl;
        break;
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