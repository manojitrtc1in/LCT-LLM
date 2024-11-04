#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define MAXM 100005

int n, m;
int arr[MAXN];
int required;
int typeDays[MAXM][MAXN];
int typeDaysSize[MAXM];
int typeDaysCapacity[MAXM];

int sum(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
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
    for (int i = 0; i < m; i++) {
        int d, typ;
        scanf("%d %d", &d, &typ);
        if (arr[typ - 1] <= 0) {
            continue;
        }
        if (typeDaysSize[typ] == typeDaysCapacity[typ]) {
            typeDaysCapacity[typ] = typeDaysCapacity[typ] * 2 + 1;
            typeDays[typ] = realloc(typeDays[typ], typeDaysCapacity[typ] * sizeof(int));
        }
        typeDays[typ][typeDaysSize[typ]] = d;
        typeDaysSize[typ]++;
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
    for (int typ = 0; typ < MAXM; typ++) {
        int lastDay = -1;
        for (int j = 0; j < typeDaysSize[typ]; j++) {
            if (typeDays[typ][j] <= day) {
                lastDay = typeDays[typ][j];
            } else {
                break;
            }
        }
        if (lastDay != -1) {
            ddays[lastDay] += arr[typ - 1];
        }
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
