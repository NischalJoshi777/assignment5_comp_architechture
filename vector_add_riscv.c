#include <stdio.h>
#include <stdlib.h>
#include <riscv_vector.h>

void weighted_sum(int * restrict a, int *restrict b, int *restrict out, int weight_a, int weight_b, int n) {
    size_t vl;
    for (size_t i = 0; i < n; i += vl) {
        vl = __riscv_vsetvl_e32m8(n - i);
        
        vint32m8_t va = __riscv_vle32_v_i32m8(a + i, vl);
        vint32m8_t vb = __riscv_vle32_v_i32m8(b + i, vl);
        
        vint32m8_t vwa = __riscv_vmul_vx_i32m8(va, weight_a, vl);
        vint32m8_t vwb = __riscv_vmul_vx_i32m8(vb, weight_b, vl);
        
        vint32m8_t vresult = __riscv_vadd_vv_i32m8(vwa, vwb, vl);
        
        __riscv_vse32_v_i32m8(out + i, vresult, vl);
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