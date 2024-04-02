#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern void c_kernel();
// extern void asm_kernel();

int main() {
	// Initialize
	float X[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };
	float Y_c[10];
	// float Y_asm[10];
	int n = sizeof(X) / sizeof(X[0]);

	// Get Y
	c_kernel(X, Y_c, n);
	// asm_kernel(X, Y_asm, n);

	// Display inputs
	printf("Length of the Vector: %d\n", n);

	printf("Vector X: ");
	for (int i = 0; i < n; i++) {
		printf("%1.2f ", X[i]);
	}
	printf("\n");

	// Display output of C Kernel
	printf("Vector Y (C Kernel): ");
	for (int i = 3; i < n - 3; i++) {
		printf("%1.2f ", Y_c[i]);
	}
	printf("\n");

	/* // Display output of ASM Kernel
	printf("Vector Y (ASM Kernel): ");
	for (int i = 3; i < n - 3; i++) {
		printf("%1.2f ", Y_asm[i]);
	}
	printf("\n");
	*/

	return 0;
}