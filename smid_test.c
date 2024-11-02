#include <emmintrin.h>
#include <stdio.h>

void simd_add(float *a, float *b, float *result, int size) {
    for (int i = 0; i < size; i += 4) {
        __m128 va = _mm_loadu_ps(&a[i]);
        __m128 vb = _mm_loadu_ps(&b[i]);
        __m128 vr = _mm_add_ps(va, vb);
        _mm_storeu_ps(&result[i], vr);
    }
}

int main() {
    float a[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    float b[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    float result[16];

    simd_add(a, b, result, 16);

    for (int i = 0; i < 16; i++) {
        printf("%f ", result[i], "\n");
        printf("\n");
    }


    return 0;
}