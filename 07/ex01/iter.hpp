template <typename S>

void iter(S *array, int length, void (*f)(S const &)) {
    if (array == NULL|| f == NULL) {
        return;
    }
    for (int i = 0; i < length; i++) {
        f(array[i]);
    }
}