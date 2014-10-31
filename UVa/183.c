#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define div2_floor(n) ((n + 1) >> 1)

char bitmap[200][200];
int output_line;

void compress(int row, int column, int width, int height) {
	if (width == 0 || height == 0) return;
	/* Check if it is all 1 or all 0 */
	int i, j;
	char c = bitmap[row][column];
	for (i = 0; i < height && c; ++i)
		for (j = 0; j < width && c; ++j)
			if (bitmap[row + i][column + j] != c)
				c = 0;
	/* Output the corresponding character for this bit map piece */
	putchar(c ? c : 'D');
	output_line++;
	if (output_line == 50) {
		putchar('\n');
		output_line = 0;
	}
	/* Recursively process if needed */
	if (!c) {
		compress(row, column, div2_floor(width), div2_floor(height));
		compress(row, column + div2_floor(width), width >> 1, div2_floor(height));
		compress(row + div2_floor(height), column, div2_floor(width), height >> 1);
		compress(row + div2_floor(height), column + div2_floor(width), width >> 1, height >> 1);
	}
}

void decompress(int row, int column, int width, int height) {
	if (width == 0 || height == 0) return;
	int i, j;
	char c = getchar();
	while (c != 'D' && c != '0' && c != '1') c = getchar();
	if (c != 'D') {
		/* Fill with zeroes or ones */
		for (i = 0; i < height; ++i)
			for (j = 0; j < width; ++j)
				bitmap[row + i][column + j] = c;
	} else {
		/* Process recursively */
		decompress(row, column, div2_floor(width), div2_floor(height));
		decompress(row, column + div2_floor(width), width >> 1, div2_floor(height));
		decompress(row + div2_floor(height), column, div2_floor(width), height >> 1);
		decompress(row + div2_floor(height), column + div2_floor(width), width >> 1, height >> 1);
	}
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int width, height;
	char type, line[51];
	int i, j, k;
	scanf("%c ", &type);
	while (type != '#') {
		scanf("%d %d ", &height, &width);
		if (type == 'B') {

			i = j = 0;
			while (i < height)  {
				/* Read line by line and fill the bitmap array */
				fgets(line, 51, stdin);
				for (k = 0; line[k] != '\n' && line[k] != 0; ++k) {
					bitmap[i][j] = line[k];
					j++;
					if (j == width) {
						j = 0;
						i++;
					}
				}
			}
			/* Covert bitmap to encoded style */
			printf("D%4d%4d\n", height, width);
			output_line = 0;
			compress(0, 0, width, height);
			if (output_line != 0)
				putchar('\n');

		} else {

			/* Read the encoded style and fill the bitmap array */
			decompress(0, 0, width, height);
			/* Output the result */
			printf("B%4d%4d\n", height, width);
			output_line = 0;
			for (i = 0; i < height; ++i) {
				for (j = 0; j < width; ++j) {
					putchar(bitmap[i][j]);
					output_line++;
					if (output_line == 50) {
						putchar('\n');
						output_line = 0;
					}
				}
			}
			if (output_line != 0)
				putchar('\n');

		}

		scanf(" %c ", &type);
	}

	return 0;
}
