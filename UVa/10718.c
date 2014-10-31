#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	unsigned int N, L, U, M;
	int bitsN[32], bitsL[32], bitsU[32], size;
	int lower, greater, i;
	while (scanf("%u %u %u ", &N, &L, &U) > 0) {
		size = 0;
		/* Store the bits of the input numbers */
		while (U) {
			bitsN[size] = N & 1;
			bitsL[size] = L & 1;
			bitsU[size] = U & 1;
			size++;
			N >>= 1;
			L >>= 1;
			U >>= 1;
		}
		/* Build the maximum M */
		M = lower = greater = 0;
		/* Take the opposite of the bit in N while it still holds L <= M <= U */
		/* lower = 1 if it's guaranteed that M <= U. Same for greater and L <= M */
		for (i = size - 1; i >= 0; i--) {
			if (bitsN[i] == 0) {
				/* Try to set bit to 1 */
				if (bitsU[i] || lower) {
					M |= 1 << i;
					if (!bitsL[i])
						greater = 1;
				}
			} else {
				/* Leave the bit to 0 */
				if (bitsL[i] && !greater) {
					M |= 1 << i;
				} else if (bitsU[i]) {
					lower = 1;
				}
			}
		}
		printf("%u\n", M);
	}

	return 0;
}
