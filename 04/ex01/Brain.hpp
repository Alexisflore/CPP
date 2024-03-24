#pragma once
#include <string>
#include <iostream>

class Brain {
    public:
        Brain();
        Brain(const Brain &other);
        ~Brain();
        Brain &operator=(const Brain &other);
        std::string getIdea(int index) const;
        void setIdea(int index, std::string idea);
    private:
        std::string *ideas;
};