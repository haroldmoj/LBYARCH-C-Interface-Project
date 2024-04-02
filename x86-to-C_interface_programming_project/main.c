// Mojica, Harold C. | Yung Cheng, Adrian U. | S15

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

extern void c_kernel();
extern void asm_kernel();

void copy_array(float* source, float* destination, int size) {
	for (int i = 0; i < size; i++) {
		destination[i] = source[i];
	}
}

int main() {
	// Initialize n
	//int n = 1048576; // 2^20
	//const char* n_string = "2^20";
	//int n = 16777216; // 2^24
	//const char* n_string = "2^24";
	int n = 67108864; // 2^26
	const char* n_string = "2^26";

	// Initialize vector X
	float* X;
	float* X_copy;
	X = (float*)malloc(n * sizeof(float));
	X_copy = (float*)malloc(n * sizeof(float));
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		X[i] = ((float)rand() / RAND_MAX) * 10;
	}

	// Declare vector Y
	float* Y_c;
	float* Y_asm;
	Y_c = (float*)malloc(n * sizeof(float));
	Y_asm = (float*)malloc(n * sizeof(float));

	// Process the input using C Kernel 30 times while calculating the average time
	clock_t sum_c = 0;
	for (int i = 0; i < 30; i++) {
		clock_t start_c = clock();
		c_kernel(n, X, Y_c);
		clock_t end_c = clock();
		sum_c += (end_c - start_c);
	}

	// Process the input using C Kernel
	clock_t sum_asm = 0;
	for (int i = 0; i < 30; i++) {
		copy_array(X, X_copy, n);
		clock_t start_asm = clock();
		asm_kernel(X_copy, Y_asm, n);
		clock_t end_asm = clock();
		sum_asm += (end_asm - start_asm);
	}

	// Display the n and Vector X
	printf("Length of the Vector: %s (%d)\n\n", n_string, n);
	printf("Vector X:\n");
	printf("%1.2f", X[0]);
	for (int i = 1; i < n; i++) {
		if (i > 15) {
			printf("...");
			break;
		}
		printf(", %1.2f", X[i]);
	}
	printf("\n\n");

	// Display Vector Y of C Kernel
	printf("Vector Y (C Kernel):\n");
	if (n >= 4) {
		printf("%1.2f", Y_c[0]);
	}
	for (int i = 1; i < n; i++) {
		if (i > 9) {
			printf("...");
			break;
		}
		printf(", %1.2f", Y_c[i]);
	}
	printf("\n\n");

	// Display Vector Y of ASM Kernel
	printf("Vector Y (ASM Kernel):\n");
	if (n >= 4) {
		printf("%1.2f", Y_asm[0]);
	}
	for (int i = 1; i < n; i++) {
		if (i > 9) {
			printf("...");
			break;
		}
		printf(", %1.2f", Y_asm[i]);
	}
	printf("\n\n");
	
	// Error checking
	int cnt = 0;
	for (int i = 0; i < n-6; i++) {
		if (Y_c[i] != Y_asm[i]) {
			cnt++;
			printf("C: %.2f -- mismatch with -- ASM: %.2f\n", Y_c[i], Y_asm[i]);
		}
	}
	printf("Result Disparity Count: %d\n\n", cnt);

	// Display elapsed time for each kernel
	double average_time_c = ((double)sum_c) / CLOCKS_PER_SEC / 30.0;
	double average_time_asm = ((double)sum_asm) / CLOCKS_PER_SEC / 30.0;
	printf("Average Time (C Kernel): %.6f seconds\n", average_time_c);
	printf("Average Time (ASM Kernel): %.6f seconds\n", average_time_asm);

	return 0;
}
