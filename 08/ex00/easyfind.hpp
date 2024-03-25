#include <string>
#include <iostream>
#include <stdexcept>

template <typename T>

typename T::iterator easyfind(T &container, int n) {
    for (typename T::iterator it = container.begin(); it != container.end(); it++) {
        if (*it == n) {
            return it;
        }
    }
    throw std::out_of_range("Element not found");
}
