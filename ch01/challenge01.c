#include <stdio.h>
#include <stdlib.h>

void printArr(double arr[], size_t arrSize) {

        for (size_t i = 0; i < arrSize; ++i) {
                printf("%f ", arr[i]);
        }
        printf("\n");
}

void merge(double arr[], int l, int m, int r) {
        size_t Lsize = m - l + 1;
        size_t Rsize = r - m;
        double L[Lsize];
        double R[Rsize];

        for (size_t i = 0; i < Lsize; ++i) {
                L[i] = arr[l + i];
        }

        for (size_t i = 0; i < Rsize; ++i) {
                R[i] = arr[m + i + 1];
        }

        int i, j = 0;
        int k = l;

        while (i < Lsize && j < Rsize) {
                if (L[i] <= R[j]) {
                        arr[k] = L[i];
                        i++;
                } else {
                        arr[k] = R[j];
                        j++;
                }
                k++;
        }
        while (i < Lsize) {
                arr[k] = L[i];
                i++;
                k++;
        }
        while (j < Rsize) {
                arr[k] = R[j];
                j++;
                k++;
        }
}

void mergeSort(double arr[], int l, int r) {
        if (l < r) {
                int m = l + (r - l) / 2;
                printf("l - %d\tm - %d\tr - %d\n", l, m, r);
                mergeSort(arr, l, m);
                mergeSort(arr, m + 1, r);

                merge(arr, l, m, r);
        }
}

int main(void) {
        double A[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        size_t arrSize = sizeof(A) / sizeof(A[0]);

        mergeSort(A, 0, arrSize - 1);

        for (size_t i = 0; i < sizeof(A) / sizeof(A[0]); ++i) {
                printf("%f ", A[i]);
        }
}
