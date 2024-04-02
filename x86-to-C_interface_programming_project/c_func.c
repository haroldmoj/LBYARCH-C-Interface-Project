#include <stdio.h>

void c_kernel(float* X, float* Y, int n) {
    for (int i = 3; i < n - 3; i++) {
        float sum = 0.0;
        for (int j = -3; j <= 3; j++) {
            sum += X[i + j];
        }
        Y[i] = sum;
    }
}