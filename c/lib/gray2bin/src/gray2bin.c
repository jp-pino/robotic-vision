#include <stdio.h>
#include <stdlib.h>
#include "gray2bin.h"

void gray2bin(FILE *in, FILE *out, int threshold) {
	unsigned char Pixel; // Pixels are 8-bits in size and are all positive

	//Read all pixel in image and convert them into binary
	Pixel = fgetc(in);
	do {
		// Binarize
		if (Pixel > threshold) {
			Pixel = 255;
		} else {
			Pixel = 0;
		}
		// Store
		fputc(Pixel, out);
		// Read Next
		Pixel = fgetc(in);
	} while (!feof(in));
}
