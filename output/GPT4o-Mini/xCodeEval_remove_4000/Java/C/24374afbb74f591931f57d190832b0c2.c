#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MOD 998244353
#define MAX_LENGTH 100005

long dp[MAX_LENGTH][25][11];
long bit[MAX_LENGTH], bit1[MAX_LENGTH];
int map[MAX_LENGTH];

void fill(long dp[], int size) {
    for (int i = 0; i < size; i++) {
        dp[i] = -1;
    }
}

void fill2(long dp[][25][11], int size1, int size2, int size3) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            for (int k = 0; k < size3; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
}

long go(char A[], int i, int pv, int v) {
    if (i == strlen(A)) {
        return pv == 0 ? 1 : 0;
    }
    if (dp[i][pv][v] != -1) {
        return dp[i][pv][v];
    }
    long ans = 0;
    if (A[i] == '_') {
        for (int j = 0; j < 10; j++) {
            if (i == 0 && j == 0) continue;
            int y = (pv * 10 + j) % 25;
            ans += go(A, i + 1, y, v);
        }
    } else if (A[i] == 'X') {
        if (v != 10) {
            ans += go(A, i + 1, (pv * 10 + v) % 25, v);
        } else {
            for (int j = 0; j < 10; j++) {
                if (i == 0 && j == 0) continue;
                int y = (pv * 10 + j) % 25;
                ans += go(A, i + 1, y, j);
            }
        }
    } else {
        ans += go(A, i + 1, (pv * 10 + (A[i] - '0')) % 25, v);
    }
    return dp[i][pv][v] = ans;
}

int main() {
    char A[MAX_LENGTH];
    scanf("%s", A);
    
    if (strlen(A) == 1 && A[0] == '0') {
        printf("1\n");
        return 0;
    }
    if (A[0] == '0') {
        printf("0\n");
        return 0;
    }
    if (strlen(A) == 1) {
        if (A[0] == 'X' || A[0] == '_') {
            printf("1\n");
            return 0;
        }
    }
    
    fill2(dp, strlen(A) + 1, 25, 11);
    printf("%ld\n", go(A, 0, 0, 10));
    
    return 0;
}
