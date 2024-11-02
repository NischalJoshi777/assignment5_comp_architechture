#include <stdio.h>
#include <immintrin.h>

int main() {
    float data1[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    float data2[4] = {5.0f, 6.0f, 7.0f, 8.0f};
    float output[4];

    __m128 vec1 = _mm_loadu_ps(data1);
    __m128 vec2 = _mm_loadu_ps(data2);
    __m128 result = _mm_add_ps(vec1, vec2);

    _mm_storeu_ps(output, result);

    printf("Result: %.1f %.1f %.1f %.1f\n", 
           output[0], output[1], output[2], output[3]);

    return 0;
}