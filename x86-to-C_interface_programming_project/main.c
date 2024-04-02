// Mojica, Harold C. | Yung Cheng, Adrian U. | S15

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

extern void c_kernel();
//extern void asm_kernel();

int main() {
	// Example given 
	//int n = 8;
	//float X[] = { 1,2,3,4,5,6,7,8 };

	// Initialize n
	//int n = 1048576; // 2^20
	//int n = 16777216; // 2^24
	//int n = 268435456; // 2^28
	int n = 536870912; // 2^29
	//int n = 1073741824; // 2^30

	// Initialize vector X
	float* X;
	X = (float*)malloc(n * sizeof(float));
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		X[i] = ((float)rand() / RAND_MAX) * 10;
	}

	// Declare vector Y
	float* Y_c;
	float* Y_asm;
	Y_c = (float*)malloc(n * sizeof(float));
	//Y_asm = (float*)malloc(n * sizeof(float));

	// Process the input using C Kernel
	clock_t start_c = clock();
	c_kernel(n, X, Y_c);
	clock_t end_c = clock();

	/*
	// Process the input using C Kernel
	clock_t start_asm = clock();
	asm_kernel(n, X, Y_asm);
	clock_t end_asm = clock();
	*/

	// Display the input
	printf("Length of the Vector: %d\n\n", n);
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

	// Display the output of C Kernel
	printf("Vector Y (C Kernel):\n");
	if (n >= 7) {
		printf("%1.2f", Y_c[3]);
	}
	for (int i = 4; i < n - 3; i++) {
		if (i > 12) {
			printf("...");
			break;
		}
		printf(", %1.2f", Y_c[i]);
	}
	printf("\n\n");

	/*
	// Display the output of ASM Kernel
	printf("Vector Y (ASM Kernel):\n");
	if (n >= 7) {
		printf("%1.2f", Y_asm[3]);
	}
	for (int i = 4; i < n - 3; i++) {
		if (i > 12) {
			printf("...");
			break;
		}
		printf(", %1.2f", Y_asm[i]);
	}
	printf("\n\n");
	*/

	// Display elapsed time for each kernel
	double elapsed_time_c = ((double)(end_c - start_c)) / CLOCKS_PER_SEC;
	//double elapsed_time_asm = ((double)(end_asm - start_asm)) / CLOCKS_PER_SEC;
	printf("Time (C Kernel): %.6f seconds\n", elapsed_time_c);
	//printf("Time (ASM Kernel): %.6f seconds\n");

	return 0;
}
