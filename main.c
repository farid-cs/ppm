#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define HEIGHT 800
#define WIDTH  800

typedef struct Color Color;
struct Color {
	char red;
	char green;
	char blue;
};

typedef struct Vec2 Vec2;
struct Vec2 {
	int x;
	int y;
};

const Color RED   = { .red = 255, .green = 0,   .blue = 0   };
const Color GREEN = { .red = 0,   .green = 255, .blue = 0   };
const Color BLUE  = { .red = 0,   .green = 0,   .blue = 255 };
const Color WHITE = { .red = 255, .green = 255, .blue = 255 };

void fill_with_color(Color* image, Color color, int width, int height)
{
	for (int j = 0; j != height; j++)
	for (int i = 0; i != width; i++) {
		image[j*width+i] = color;
	}
}

void draw_line(Color* image, Vec2 pos, int len)
{
	for (int i = 0; i != len; i++) {
		image[pos.y*WIDTH+pos.x+i] = RED;
	}
}

void draw_rectangle(Color* image, Vec2 corner, Vec2 dimensions)
{
	Vec2 row = corner;

	for (int j = 0; j != dimensions.y; j++) {
		draw_line(image, row, dimensions.x);
		row.y++;
	}
}

void draw_circle(Color* image, Vec2 center, int radius)
{
	const int steps = 10000000;
	const double step_size = M_PI/steps;

	double teta = step_size;

	for (int i = 1; teta < M_PI; i++) {
		teta = step_size * i;
		Vec2 pos = {
			.x = center.x - sin(teta) * radius,
			.y = center.y - cos(teta) * radius,
		};
		int len = abs((int)(2 * sin(teta) * radius));

		draw_line(image, pos, len);
	}
}

void dump_image_to_file(const char* file_name, Color* image, int height, int width)
{
	FILE* file = fopen(file_name, "wb");

	fprintf(file, "P6\n%d %d\n255\n", width, height);
	fwrite(image, 1, height*width*sizeof(Color), file);

	fclose(file);
}

int main(void)
{
	Color image[HEIGHT*WIDTH] = {0};

	fill_with_color(image, WHITE, HEIGHT, WIDTH);
	draw_circle(image, (Vec2){.x = WIDTH/2, .y = HEIGHT/2}, 300);
	dump_image_to_file("image.ppm", image, HEIGHT, WIDTH);

	return 0;
}
