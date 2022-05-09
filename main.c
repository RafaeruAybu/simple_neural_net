#include <stdio.h> // i/o
#include <math.h> // fasb and other things

#define WIDTH 20
#define HEIGHT 20

typedef float Layer[HEIGHT][WIDTH];

static inline int clamp(int x, int low, int high)
{
	if (x < low) x = low;
	if (x > high) x = high;
	return x;
}

void layer_fill_rect(Layer layer, int x, int y, int w, int h, float value)
{
	assert(w > 0);
	assert(h > 0);
	int x0 = clampi(x, 0, WIDTH-1);
	int y0 = clampi(y, 0, HEIGHT-1);
	int x1 = clampi(x0 + w - 1, 0, WIDTH-1);	
	int y1 = clampi(y0 + w - 1, 0, HEIGHT-1);

	for (int y = y0; y < y1; ++y) {
		for (int x = x0; x <= x1; ++x) { //here stopped
			layer[y][x] = value;
		}
	}
}

float feed_forward(float inputs[HEIGHT][WIDTH], float weights[HEIGHT][WIDTH])
{
	float output = 0.0f;

	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; ++x)
			output += inputs[y][x] * weights[y][x];
	return output;
}

static Layer inputs;
static Layer weights;

int main (void)
{
	float output = feed_forward(inputs, weights);
	printf("output = %f\n", output);
	return 0;
}
