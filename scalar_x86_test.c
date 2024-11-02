#include <stdio.h>

void scalar_add(float *a, float *b, float *result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = a[i] + b[i];
    }
}

int main() {
    float a[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    float b[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    float result[16];

    scalar_add(a, b, result, 16);

    for (int i = 0; i < 16; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    return 0;
}