// Mojica, Harold C. | Yung Cheng, Adrian U. | S15

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern void c_kernel();
// extern void asm_kernel();

int main() {
	// Initialize the values
	int n = 8;
	float X[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };
	float Y_c[10];
	// float Y_asm[10];
	
	// Call the kernels
	c_kernel(n, X, Y_c);
	// asm_kernel(n, X, Y_asm);

	// Display the inputs
	printf("Length of the Vector: %d\n", n);
	printf("Vector X: ");
	printf("%1.2f", X[0]);
	for (int i = 1; i < n; i++) {
		printf(", %1.2f", X[i]);
	}
	printf("\n");

	// Display the output of C Kernel
	printf("Vector Y (C Kernel): ");
	if (n >= 7) {
		printf("%1.2f", Y_c[3]);
	}
	for (int i = 4; i < n - 3; i++) {
		printf(", %1.2f", Y_c[i]);
	}
	printf("\n");

	/*/ Display the output of ASM Kernel
	printf("Vector Y (ASM Kernel): ");
	if (n >= 7) {
		printf("%1.2f", Y_asm[3]);
	}
	for (int i = 4; i < n - 3; i++) {
		printf(", %1.2f", Y_asm[i]);
	}
	printf("\n");
	*/

	return 0;
}
