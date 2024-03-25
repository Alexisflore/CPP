#include "Span.hpp"

Span::Span() : _array(NULL), _size(0), _count(0) {}

Span::Span(unsigned int n) : _array(new unsigned int[n]), _size(n), _count(0) {}

Span::Span(Span const &src) : _array(NULL), _size(0), _count(0) {
    *this = src;
}

Span::~Span() {
    if (_array != NULL) {
        delete[] _array;
    }
}

Span &Span::operator=(Span const &rhs) {
    if (_array != NULL) {
        delete[] _array;
    }
    _size = rhs._size;
    _count = rhs._count;
    _array = new unsigned int[_size];
    for (unsigned int i = 0; i < _count; i++) {
        _array[i] = rhs._array[i];
    }
    return *this;
}

void Span::addNumber(int n) {
    if (_count >= _size) {
        throw std::out_of_range("Array is full");
    }
    _array[_count] = n;
    _count++;
}

int Span::shortestSpan() {
    if (_count <= 1) {
        throw std::out_of_range("Not enough numbers to calculate span");
    }
    int min = _array[1] - _array[0];
    if (min < 0) {
        min *= -1;
    }
    for (unsigned int i = 0; i < _count - 1; i++) {
        for (unsigned int j = i + 1; j < _count; j++) {
            int diff = _array[j] - _array[i];
            if (diff < 0) {
                diff *= -1;
            }
            if (diff < min) {
                min = diff;
            }
        }
    }
    return min;
}

int Span::longestSpan() {
    if (_count <= 1) {
        throw std::out_of_range("Not enough numbers to calculate span");
    }
    int max = _array[1] - _array[0];
    for (unsigned int i = 0; i < _count; i++) {
        for (unsigned int j = i + 1; j < _count; j++) {
            int diff = _array[j] - _array[i];
            if (diff > max) {
                max = diff;
            }
        }
    }
    return max;
}