#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M 100000

int n;
int m;
int arr[MAX_N];
int required;
int typeDays[MAX_M][2];
int typeDaysSize;
int lo;
int hi;
int valid;

int sum(int* arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

void solver() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    required = sum(arr, n);
    typeDaysSize = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &typeDays[i][0], &typeDays[i][1]);
        if (arr[typeDays[i][1] - 1] <= 0) {
            continue;
        }
        typeDaysSize++;
    }

    lo = required;
    hi = 2 * required;
    valid = hi;
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
        for (int j = 0; j < m; j++) {
            if (typeDays[j][1] == typ && typeDays[j][0] <= day) {
                lastDay = typeDays[j][0];
            }
        }
        if (lastDay == -1) {
            continue;
        }
        ddays[lastDay] += arr[typ - 1];
    }

    int removed = 0;
    for (int i = 1; i < day + 1; i++) {
        int coins = i - removed;
        int toRemove = coins < ddays[i] ? coins : ddays[i];
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
