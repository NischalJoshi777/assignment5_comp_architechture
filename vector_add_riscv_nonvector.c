#include <stdio.h>
#include <stdlib.h>

void weighted_sum(int * restrict a, int *restrict b, int *restrict out, int weight_a, int weight_b, int n) {
    for (int i = 0; i < n; i++) {
        out[i] = weight_a * a[i] + weight_b * b[i];
    }
}

#define N 10

int main() {
    // Allocate memory for arrays
    int *a = (int*)malloc(N * sizeof(int));
    int *b = (int*)malloc(N * sizeof(int));
    int *out = (int*)malloc(N * sizeof(int));

    // Initialize input arrays
    for (int i = 0; i < N; i++) {
        a[i] = i;
        b[i] = i * 2;
    }

    // Set weights
    int weight_a = 2;
    int weight_b = 3;

    // Perform weighted sum
    weighted_sum(a, b, out, weight_a, weight_b, N);

    // Print results
    printf("Results of weighted sum:\n");
    for (int i = 0; i < N; i++) {
        printf("%d * %d + %d * %d = %d\n", weight_a, a[i], weight_b, b[i], out[i]);
    }

    // Free allocated memory
    free(a);
    free(b);
    free(out);

    return 0;
}