#include <stdio.h>
#include "collatzLib/collatz.h"

int main() {
    int number, iterations;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Enter max number of iterations: ");
    scanf("%d", &iterations);
    printf("Collatz conjecture for %d: %d\n", number, collatz_conjecture(number));
    printf("Collatz convergence for %d: %d\n", number, test_collatz_convergence(number, iterations));
}

