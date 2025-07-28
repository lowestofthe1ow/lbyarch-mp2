#include <stdio.h>

/* Returns the dot product of two n-element vectors a and b */
double c_dot_product(size_t n, double a[], double b[]) {
    double retval = 0;

    for (int i = 0; i < n; i++)
        retval += a[i] * b[i];

    return retval;
}