#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BIG 1000000007

long count[100][100][100][100]; // Adjust size as needed

void add(int p1, int p2, int c1, int c2, long count, long result[100][100][100][100]) {
    if (p1 >= 0 && p2 >= 0 && c1 >= 0 && c2 >= 0 && count > 0) {
        if (p1 < 100 && p2 < 100 && c1 < 100 && c2 < 100) {
            result[p1][p2][c1][c2] += count;
        }
    }
}

void addPrevious(int p1, int p2, int c1, int c2, long count, long result[100][100][100][100]) {
    add(p1 - 1, p2, c1, c2, p1 * count, result);
    add(p1 + 1, p2 - 1, c1, c2, p2 * count, result);
}

void next(int d, long count, int p1, int p2, int c1, int c2, long result[100][100][100][100]) {
    if (p1 == 0 && p2 == 0) {
        if (d == 2) {
            addPrevious(c1, c2, 1, 0, count, result);
        } else {
            addPrevious(c1, c2, 0, 1, count, result);
        }
    }

    if (d == 2) {
        addPrevious(p1, p2, c1 + 1, c2, count, result);
        addPrevious(p1, p2, c1 - 1, c2, c1 * count, result);
        addPrevious(p1, p2, c1 + 1, c2 - 1, c2 * count, result);
    } else {
        addPrevious(p1, p2, c1, c2 + 1, count, result);
        addPrevious(p1, p2, c1, c2, c1 * count, result);
        addPrevious(p1, p2, c1 + 2, c2 - 1, c2 * count, result);
        addPrevious(p1, p2, c1 - 2, c2, c1 * (c1 - 1) / 2 * count, result);
        addPrevious(p1, p2, c1, c2 - 1, c1 * c2 * count, result);
        addPrevious(p1, p2, c1 + 2, c2 - 2, c2 * (c2 - 1) / 2 * count, result);
    }
}

long solve(int d[], int n) {
    long count[100][100][100][100] = {0}; // Adjust size as needed
    if (d[0] == 2) {
        if (d[1] == 2) {
            count[1][0][1][0] = 1;
        } else {
            count[1][0][0][1] = 1;
        }
    } else {
        if (d[1] == 2) {
            count[0][1][1][0] = 1;
        } else {
            count[0][1][0][1] = 1;
        }
    }
    for (int u = 2; u < n; u++) {
        long countNext[100][100][100][100] = {0}; // Adjust size as needed
        for (int p1 = 0; p1 <= n / 2; p1++) {
            for (int p2 = 0; p2 <= n / 2 && p1 + p2 < n; p2++) {
                for (int c1 = 0; c1 <= n / 2 && p1 + p2 + c1 < n; c1++) {
                    for (int c2 = 0; c2 <= n / 2 && p1 + p2 + c1 + c2 < n; c2++) {
                        next(d[u], count[p1][p2][c1][c2] % BIG, p1, p2, c1, c2, countNext);
                    }
                }
            }
        }
        memcpy(count, countNext, sizeof(countNext));
    }
    return count[0][0][0][0] % BIG;
}

int main() {
    int n;
    scanf("%d", &n);
    int d[100]; // Adjust size as needed
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }
    printf("%ld\n", solve(d, n));
    return 0;
}
