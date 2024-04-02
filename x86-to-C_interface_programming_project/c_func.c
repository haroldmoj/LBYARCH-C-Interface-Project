// Mojica, Harold C. | Yung Cheng, Adrian U. | S15

#include <stdio.h>

void c_kernel(int n, float* X, float* Y) {
    for (int i = 3; i < n - 3; i++) {
        float sum = 0.0;
        for (int j = -3; j <= 3; j++) {
            sum += X[i + j];
        }
        Y[i] = sum;
    }
}