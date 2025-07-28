#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* C implementation of dot product function */
#include "c_dot_product.c"

#define MAX_VAL 10

/* x86-64 assembly implementation of dot product function */
extern double asm_dot_product(size_t n, double a[], double b[], double *sdot);

/* Returns a pointer to a dynamically allocated vector with n random
   double-precision values (must be freed manually)
 */
double* initialize(size_t n) {
    float x;
    double* retval = malloc(n * sizeof(double));

    for (int i = 0; i < n; i++)
        retval[i] = (float) rand() / (float) (RAND_MAX / MAX_VAL);

    return retval;
}

/* Prints a 1D array of doubles */
void print_vec(size_t n, double vec[]) {
    printf("[ ");

    for (int i = 0; i < n; i++)
        printf("%2.2lf ", vec[i]);

    printf("]\n");
}

int main() {    
    size_t n;            // Input vector size
    clock_t begin, end;  // Clock
    double *a, *b;       // Input vectors
    double sdot;         // Result variable
    char temp;           // Holds user input

    /* Seed the RNG */
    srand(time(NULL));

    printf("Enter vector size: ");
    scanf(" %zu", &n);

    a = initialize(n);
    b = initialize(n);

    printf("Print input vectors? (y/n): ");
    scanf(" %c", &temp);

    if (temp == 'y' || temp == 'Y') {
        print_vec(n, a);
        print_vec(n, b);
    }

    /* Begin timing the C implementation */
    begin = clock();
    c_dot_product(n, a, b, &sdot);
    end = clock();

    printf("C: %lf (Execution time: %le seconds)\n",
        sdot, (double) (end - begin) / CLOCKS_PER_SEC);

    /* Begin timing the x86-64 assembly implementation */
    begin = clock();
    asm_dot_product(n, a, b, &sdot);
    end = clock();
    
    printf("ASM: %lf (Execution time: %le seconds)",
        sdot,  (double) (end - begin) / CLOCKS_PER_SEC);
    
    /* Free allocated memory */
    free(a);
    free(b);

    return 0;
}