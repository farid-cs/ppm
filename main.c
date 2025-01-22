#include <stdio.h>

typedef struct {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
} Color;

static const char IMAGE_PATH[] = "image.ppm";
static const int IMAGE_WIDTH = 800;
static const int IMAGE_HEIGHT = 800;
static const Color BLACK = { .red = 0, .green = 0, .blue = 0 };

int
main(void)
{
	Color image[IMAGE_HEIGHT*IMAGE_WIDTH];
	FILE *file;

	for (int j = 0; j != IMAGE_HEIGHT; j++)
		for (int i = 0; i != IMAGE_WIDTH; i++)
			image[IMAGE_WIDTH*j+i] = BLACK;

	file = fopen(IMAGE_PATH, "wb");

	fprintf(file, "P6\n%d %d\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);
	fwrite(image, sizeof(Color), IMAGE_HEIGHT*IMAGE_WIDTH, file);

	fclose(file);

	return 0;
}
