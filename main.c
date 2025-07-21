#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* C implementation of dot product function */
#include "c_dot_product.c"

#define MAX_VAL 10
#define ELEMENT_COUNT 1000000

/* x86-64 assembly implementation of dot product function */
extern double asm_dot_product(int n, double a[], double b[]);

/* Returns a pointer to a dynamically allocated vector with n random
   double-precision values
 */
double* initialize(size_t n) {
    float x;
    double* retval = malloc(n * sizeof(double));

    for (int i = 0; i < n; i++)
        retval[i] = (float) rand() / (float) (RAND_MAX / MAX_VAL);

    return retval;
}

int main() {
    /* Seed the RNG */
    srand(time(NULL));

    /* Test vectors */
    double* a = initialize(ELEMENT_COUNT);
    double* b = initialize(ELEMENT_COUNT);

    double c_res, asm_res;

    clock_t begin, end;

    /* Begin timing the C implementation */
    begin = clock();
    c_res = c_dot_product(ELEMENT_COUNT, a, b);
    end = clock();

    printf("C: %lf (Execution time: %le seconds)\n",
        c_res, (double) (end - begin) / CLOCKS_PER_SEC);

    /* Begin timing the x86-64 assembly implementation */
    begin = clock();
    asm_res = asm_dot_product(ELEMENT_COUNT, a, b);
    end = clock();
    
    printf("ASM: %lf (Execution time: %le seconds)",
        asm_res,  (double) (end - begin) / CLOCKS_PER_SEC);
    
    free(a);
    free(b);

    return 0;
}