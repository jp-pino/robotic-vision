#include <stdio.h>
#include <stdlib.h>
#include "rgb2gray.h"

void rgb2gray(FILE *in, FILE *out, unsigned char red, unsigned char green, unsigned char blue) {
	// Define local variables
	unsigned char R, G, B;

	// Read the first Pixel
	R = fgetc(in);
	G = fgetc(in);
	B = fgetc(in);

	do {
		fputc((red*R + green*G + blue*B)/(red+green+blue), out);
		R = fgetc(in);
		G = fgetc(in);
		B = fgetc(in);
	} while (!feof(in));
}
