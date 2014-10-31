#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int H, U, D, F;
	while (scanf("%d %d %d %d ", &H, &U, &D, &F) > 0 && H != 0) {
		int height = H * 100, up = U * 100, down = D * 100, fatigue = F * U, day = 0, position = 0;
		while (position >= 0) {
			day++;
			if (up > 0) position += up;
			if (position > height) break;
			position -= down;
			up -= fatigue;
		}
		if (position < 0)
			printf("failure on day %d\n", day);
		else
			printf("success on day %d\n", day);
	}
	return 0;
}
