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

int is_even_bitwise(unsigned int i) {
    return ( (i>>1)<<1 == i);
}

int main() {

    int foo = is_even(6);
    int bar = is_even(7);

    int asdf = is_even_bitwise(8);
    int hjkl = is_even_bitwise(9);

    printf("6 is even: %d\n", foo);
    printf("7 is even: %d\n", bar);
    printf("8 is even: %d\n", asdf);
    printf("9 is even: %d\n", hjkl);
    return 0;
}
