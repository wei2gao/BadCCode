#include <stdio.h>


/**
    Detects if a non-negative integer is even.
    \param i integer to check
    \return Whether the argument is even
*/
int is_even(unsigned int i) {
    if (i == 0) return 1;
    return !is_even(i-1);
}

int main() {

    int foo = is_even(6);
    int bar = is_even(7);

    printf("6 is even: %d\n", foo);
    printf("7 is even: %d\n", bar);
    return 0;
}
