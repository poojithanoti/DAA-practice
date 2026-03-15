#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}
int main() {
    int n, W, i, w;
    int weight[20], value[20];
    int K[20][20];
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &weight[i]);
    printf("Enter values:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &value[i]);
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);
    for(i = 0; i <= n; i++) {
        for(w = 0; w <= W; w++) {
            if(i == 0 || w == 0)
                K[i][w] = 0;
            else if(weight[i] <= w)
                K[i][w] = max(value[i] + K[i-1][w-weight[i]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    printf("Maximum profit = %d", K[n][W]);
    return 0;
}
