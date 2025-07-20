#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* C implementation of dot product function */
#include "c_dot_product.c"

/* x86-64 assembly implementation of dot product function */
extern double asm_dot_product(int n, double a[], double b[]);

/* Returns a pointer to a dynamically allocated vector with n random
   double-precision values
 */
double* initialize(size_t n) {
    float x;
    double* retval = malloc(n * sizeof(double));

    for (int i = 0; i < n; i++)
        retval[i] = (float) rand() / (float) (RAND_MAX / n);

    return retval;
}

int main() {
    /* Seed the RNG */
    srand(time(NULL));

    /* Test vectors */
    double* a = initialize(3);
    double* b = initialize(3);

    double c_res, asm_res;

    clock_t begin, end;

    /* Begin timing the C implementation */
    begin = clock();
    c_res = c_dot_product(4, a, b);
    end = clock();

    printf("C: %lf (Execution time: %le seconds)\n",
        c_res, (double) (end - begin) / CLOCKS_PER_SEC);

    /* Begin timing the x86-64 assembly implementation */
    begin = clock();
    asm_res = asm_dot_product(4, a, b);
    end = clock();
    
    printf("ASM: %lf (Execution time: %le seconds)",
        asm_res,  (double) (end - begin) / CLOCKS_PER_SEC);
    
    free(a);
    free(b);

    return 0;
}