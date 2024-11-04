#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int n;
int m;
int arr[MAX_SIZE];
int required;
int typeDays[MAX_SIZE][2];
int typeDaysSize = 0;

void solver() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    required = sum(arr, n);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &typeDays[i][0], &typeDays[i][1]);
        if (arr[typeDays[i][1] - 1] <= 0) continue;
        typeDaysSize++;
    }

    int lo = required;
    int hi = 2 * required;
    int valid = hi;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (isEnough(mid)) {
            valid = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", valid);
}

int isEnough(int day) {
    int totalCoin = day;
    int req = required;

    int ddays[day + 1];
    for (int i = 0; i < day + 1; i++) {
        ddays[i] = 0;
    }
    for (int i = 0; i < typeDaysSize; i++) {
        int typ = typeDays[i][1];
        int lastDay = -1;
        for (int j = 0; j < day + 1; j++) {
            if (typeDays[i][0] <= j) {
                lastDay = j;
            }
        }
        if (lastDay == -1) continue;
        ddays[lastDay] += arr[typ - 1];
    }

    int removed = 0;
    for (int i = 1; i < day + 1; i++) {
        int coins = i - removed;
        int toRemove = min(coins, ddays[i]);
        removed += toRemove;
        totalCoin -= toRemove;
        req -= toRemove;
    }

    return req * 2 <= totalCoin;
}

int main() {
    solver();
    return 0;
}

int sum(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}
