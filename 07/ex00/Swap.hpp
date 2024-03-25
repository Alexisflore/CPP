#pragma once
#include <iostream>
#include <string>

template <typename S>
void swap(S &a, S &b) {
    S temp = a;
    a = b;
    b = temp;
}

template <typename m>
m min(m a, m b) {
    return (a < b) ? a : b;
}

template <typename M>
M max(M a, M b) {
    return (a > b) ? a : b;
}