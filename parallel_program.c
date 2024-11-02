#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000

// Function to fill an array with random integers
void fill_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Loop Unrolling Example: Square each element in the array
void loop_unrolling_square(int *arr, int *result, int size) {
    int i;
    for (i = 0; i < size; i += 4) {
        result[i] = arr[i] * arr[i];
        result[i + 1] = arr[i + 1] * arr[i + 1];
        result[i + 2] = arr[i + 2] * arr[i + 2];
        result[i + 3] = arr[i + 3] * arr[i + 3];
    }
    // Handle any remaining elements if size is not a multiple of 4
    for (; i < size; i++) {
        result[i] = arr[i] * arr[i];
    }
}

int main() {
    srand(time(0));

    int *arr = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int *result = (int *)malloc(ARRAY_SIZE * sizeof(int));

    fill_array(arr, ARRAY_SIZE);

    // Apply loop unrolling to calculate squares
    loop_unrolling_square(arr, result, ARRAY_SIZE);

    // Display the first 10 results for verification
    for (int i = 0; i < 10; i++) {
        printf("result[%d] = %d\n", i, result[i]);
    }

    free(arr);
    free(result);

    return 0;
}
