#include <stdio.h>
#include <stdlib.h>
int main(void) {
        double A[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

        for (size_t i = 0; i < sizeof(A) / sizeof(A[0]); ++i) {
                printf("%f\n", A[i]);
        }
}