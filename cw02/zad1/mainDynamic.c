#include <stdio.h>
#include <dlfcn.h>

int main() {
    int (*collatz_conjecture)(int input);
    int (*test_collatz_convergence)(int input, int max_iter);

    void* handle = dlopen("collatzlib/build/libcollatz_shared.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    collatz_conjecture = dlsym(handle, "collatz_conjecture");
    test_collatz_convergence = dlsym(handle, "test_collatz_convergence");
    int number, iterations;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Enter max number of iterations: ");
    scanf("%d", &iterations);
    printf("Collatz conjecture for %d: %d\n", number, collatz_conjecture(number));
    printf("Collatz convergence for %d: %d\n", number, test_collatz_convergence(number, iterations));

    dlclose(handle);
}