#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ancestorBits holds a list of what the ancestor could be (three bits in decimal format) for a bit in the state (0 or 1) */
int ancestorBits[2][8];
int ancestorBitsCount[2];

/* Parse the automaton identifier */
void calc_ancestor_bits(int id) {
	ancestorBitsCount[0] = ancestorBitsCount[1] = 0;
	int i;
	for (i = 0; i < 8; ++i) {
		if (id & 1)
			ancestorBits[1][ancestorBitsCount[1]++] = i;
		else
			ancestorBits[0][ancestorBitsCount[0]++] = i;
		id >>= 1;
	}
}


int id, N;
char s[32], ancestor[32];

/* Returns true iff bits at pos - 1 and pos are compatible with a given ancestor value */
int possible_bit(int pos, int ancestorVal) {
	return (ancestor[pos - 1] == (ancestorVal >> 2) && ancestor[pos] == ((ancestorVal >> 1) & 1));
}

/* Returns true if the last bits of the guessed ancestor are coherent */
int possible_final_bit(int ancestorBit) {
	if (ancestor[N - 3] == (ancestorBit >> 2) && ancestor[N - 2] == ((ancestorBit >> 1) & 1) && ancestor[N - 1] == (ancestorBit & 1)) {
		int bit = s[N - 1], i, res = 0;
		for (i = 0; i < ancestorBitsCount[bit] && !res; ++i) {
			if (ancestor[N - 2] == (ancestorBits[bit][i] >> 2) && ancestor[N - 1] == ((ancestorBits[bit][i] >> 1) & 1) && ancestor[0] == (ancestorBits[bit][i] & 1))
				res = 1;
		}
		return res;
	} else {
		return 0;
	}
}

/* From the bit at position 'pos' and on, compute if there is a possible ancestor for the state */
int is_reachable(int pos) {
	int bit = s[pos], i, res = 0;
	for (i = 0; i < ancestorBitsCount[bit] && !res; ++i) {
		/* Check each possible ancestor value for the bit at pos */
		if (pos == 0) {
			ancestor[N - 1] = ancestorBits[bit][i] >> 2;
			ancestor[0] = (ancestorBits[bit][i] >> 1) & 1;
			ancestor[1] = ancestorBits[bit][i] & 1;
			res = res | is_reachable(pos + 1);
		} else if (pos == N - 2) {
			res = res | possible_final_bit(ancestorBits[bit][i]);
		} else if (possible_bit(pos, ancestorBits[bit][i])) {
			ancestor[pos + 1] = ancestorBits[bit][i] & 1;
			res = res | is_reachable(pos + 1);
		}
	}
	return res;
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int i;
	while (scanf("%d %d %s ", &id, &N, s) > 0) {
		for (i = 0; i < N; ++i)
			s[i] -= '0';
		calc_ancestor_bits(id);
		if (is_reachable(0))
			puts("REACHABLE");
		else
			puts("GARDEN OF EDEN");
	}

	return 0;
}
