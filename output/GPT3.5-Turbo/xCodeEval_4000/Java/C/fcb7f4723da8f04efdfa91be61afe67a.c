#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

typedef struct {
    int count;
    long cost;
} Count;

int k;

void solver() {
    int n;
    scanf("%d", &n);
    scanf("%d", &k);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    Count* counts = (Count*)malloc((MAX_SIZE + 1) * sizeof(Count));
    counts[0].count = 0;
    counts[0].cost = 0;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int cost = 0;
        while (num > 0) {
            if (counts[num].count == 0) {
                counts[num].count = 0;
                counts[num].cost = 0;
            }
            counts[num].count++;
            counts[num].cost += cost;
            num = num / 2;
            cost++;
        }
        counts[0].count++;
        counts[0].cost += cost;
    }
    long ans = LONG_MAX;
    for (int i = 0; i <= MAX_SIZE; i++) {
        if (counts[i].count >= k) {
            ans = min(ans, counts[i].cost);
        }
    }
    printf("%ld\n", ans);
}

int main() {
    solver();
    return 0;
}
