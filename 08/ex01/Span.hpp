#include <string>
#include <iostream>
#include <stdexcept>

class Span {
    public:
        Span();
        Span(unsigned int n);
        Span(Span const &src);
        ~Span();
        Span &operator=(Span const &rhs);
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
    private:
        unsigned int *_array;
        unsigned int _size;
        unsigned int _count;
};

