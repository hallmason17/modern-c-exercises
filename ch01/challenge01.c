#include <stdio.h>
#include <stdlib.h>

void merge(double arr[], int l, int m, int r) {
        size_t Lsize = m - l + 1;
        size_t Rsize = r - m;
        double L[Lsize];
        double R[Rsize];

        for (size_t i = 0; i < Lsize; i++) {
                L[i] = arr[l + i];
        }
        for (size_t j = 0; j < Rsize; j++) {
                R[j] = arr[m + 1 + j];
        }

        int i = 0;
        int j = 0;
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
                mergeSort(arr, l, m);
                mergeSort(arr, m + 1, r);

                merge(arr, l, m, r);
        }
}

int partition(double arr[], int l, int r) {
        int pivot = arr[r];
        int i = l - 1;

        for (size_t j = l; j < r; ++j) {
                if (arr[j] <= pivot) {
                        i++;
                        double tmp = 0;
                        tmp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = tmp;
                }
        }
        double temp = 0;
        temp = arr[i + 1];
        arr[i + 1] = arr[r];
        arr[r] = temp;
        return i + 1;
}

void quickSort(double arr[], int l, int r) {
        if (l < r) {
                int partIndex = partition(arr, l, r);
                quickSort(arr, l, partIndex - 1);
                quickSort(arr, partIndex + 1, r);
        }
}

int isSorted(double arr[], size_t arrSize) {
        for (size_t i = 1; i < arrSize; ++i) {
                if (arr[i - 1] > arr[i]) {
                        return 0;
                }
        }
        return 1;
}

int main(void) {
        double A[10] = {10, 9, 9, 7, 6, 5, 4, 3, 2, 1};
        double B[10] = {10, 9, 9, 7, 6, 5, 4, 3, 2, 1};
        size_t arrSizeA = sizeof(A) / sizeof(A[0]);
        size_t arrSizeB = sizeof(B) / sizeof(B[0]);

        mergeSort(A, 0, arrSizeA - 1);
        quickSort(B, 0, arrSizeB - 1);
        if (isSorted(A, arrSizeA)) {
                printf("Array A sorted with merge sort!\n");
        } else if (!isSorted(A, arrSizeA)) {
                printf("Array A not sorted\n");
        }
        if (isSorted(B, arrSizeB)) {
                printf("Array B sorted with quick sort!\n");
        } else if (!isSorted(B, arrSizeB)) {
                printf("Array B not sorted\n");
        }
}
