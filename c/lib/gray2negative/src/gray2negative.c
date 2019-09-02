#include <stdio.h>
#include <stdlib.h>
#include "gray2negative.h"

void gray2negative(FILE *in, FILE *out) {
	unsigned char Pixel; // Pixels are 8-bits in size and are all positive

	//Read all pixel in image and convert them into binary
	Pixel = fgetc(in);
	do {
		// Negate
		Pixel = ~Pixel;
		// Store
		fputc(Pixel, out);
		// Read Next
		Pixel = fgetc(in);
	} while (!feof(in));
}
