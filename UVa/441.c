#include <stdio.h>
#include <stdlib.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int k, a, b, c, d, e, f, t = 0;
	while (scanf("%d ", &k) > 0 && k > 0) {
		int S[k];
		for (a = 0; a < k; ++a)
			scanf("%d ", &S[a]);

		if (t) puts("");
		t++;
		for (a = 0; a < k - 5; ++a)
			for (b = a + 1; b < k - 4; ++b)
				for (c = b + 1; c < k - 3; ++c)
					for (d = c + 1; d < k - 2; ++d)
						for (e = d + 1; e < k - 1; ++e)
							for (f = e + 1; f < k; ++f)
								printf("%d %d %d %d %d %d\n", S[a], S[b], S[c], S[d], S[e], S[f]);
	}

	return 0;
}
