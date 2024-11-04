#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DAYS 100000
#define MAX_TYPES 1000

int n, m;
int arr[MAX_TYPES];
int required;
int typeDays[MAX_TYPES][MAX_DAYS];
int typeDaysCount[MAX_TYPES];

void input() {
    scanf("%d %d", &n, &m);
    required = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        required += arr[i];
    }
    
    memset(typeDaysCount, 0, sizeof(typeDaysCount));
    for (int i = 0; i < m; i++) {
        int d, typ;
        scanf("%d %d", &d, &typ);
        if (arr[typ - 1] <= 0) continue;
        typeDays[typ - 1][typeDaysCount[typ - 1]++] = d;
    }
}

bool isEnough(int day) {
    int totalCoin = day;
    int req = required;
    int ddays[MAX_DAYS + 1] = {0};

    for (int typ = 0; typ < n; typ++) {
        for (int j = 0; j < typeDaysCount[typ]; j++) {
            if (typeDays[typ][j] <= day) {
                ddays[typeDays[typ][j]] += arr[typ];
            }
        }
    }

    int removed = 0;
    for (int i = 1; i <= day; i++) {
        int coins = i - removed;
        int toRemove = (coins < ddays[i]) ? coins : ddays[i];
        removed += toRemove;
        totalCoin -= toRemove;
        req -= toRemove;
    }

    return req * 2 <= totalCoin;
}

void solver() {
    input();
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

int main() {
    solver();
    return 0;
}
