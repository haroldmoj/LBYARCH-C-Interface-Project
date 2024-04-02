#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern void c_kernel();
// TODO: extern void asm_kernel();

int main() {
	// Initialize inputs
	float X[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };
	float Y[10];
	int n = sizeof(X) / sizeof(X[0]);

	// Call the kernels to get Y
	c_kernel(X, Y, n);
	// TODO: asm_kernel();

	// Display inputs and outputs
	printf("Length of the Vector: %d\n", n);

	printf("Vector X: ");
	for (int i = 0; i < n; i++) {
		printf("%1.2f ", X[i]);
	}
	printf("\n");

	printf("Vector Y: ");
	for (int i = 3; i < n - 3; i++) {
		printf("%1.2f ", Y[i]);
	}
	printf("\n");

	return 0;
}