#include <stdio.h>

int main(int argc, char** argv) {
    int n, i, bet;
    long long int max_profit, profit;
    while (scanf("%d ", &n) > 0 && n != 0) {
        max_profit = -1;
        profit = 0;
        for (i = 0; i < n; ++i) {
            scanf("%d ", &bet);
            profit += bet;
            if (profit < 0) { /* Fin de la racha */
                profit = 0;
            } else if (profit > max_profit) { /* Mejora lo anterior */
                max_profit = profit;
            }
        }
        
        if (max_profit <= 0)
            puts("Losing streak.");
        else
            printf("The maximum winning streak is %d.\n", max_profit);
    }
    return 0;
}
