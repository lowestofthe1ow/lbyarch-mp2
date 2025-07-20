#include <stdio.h>
#include <time.h>

/* C implementation of dot product function */
#include "c_dot_product.c"

/* x86-64 assembly implementation of dot product function */
extern double asm_dot_product(int n, double a[], double b[]);

int main() {
    /* Test vectors */
    double a[] = {1.0, 22.0, 3.0, 4.0};
    double b[] = {1.0, 3.0, 4.0, 15.0};

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

    return 0;
}