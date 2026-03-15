#include <stdio.h>
int main() {
    int n, i, j;
    float weight[20], value[20], ratio[20];
    float capacity, total = 0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights and values:\n");
    for(i = 0; i < n; i++) {
        scanf("%f %f", &weight[i], &value[i]);
        ratio[i] = value[i] / weight[i];
    }
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(ratio[i] < ratio[j]) {
                float temp;
                temp = ratio[i]; ratio[i] = ratio[j]; ratio[j] = temp;
                temp = weight[i]; weight[i] = weight[j]; weight[j] = temp;
                temp = value[i]; value[i] = value[j]; value[j] = temp;
            }
        }
    }
    for(i = 0; i < n; i++) {
        if(weight[i] <= capacity) {
            total += value[i];
            capacity -= weight[i];
        }
        else {
            total += value[i] * (capacity / weight[i]);
            break;
        }
    }
    printf("Maximum value = %.2f", total);
    return 0;
}
