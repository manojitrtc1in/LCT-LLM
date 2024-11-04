#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 16
#define MOD 1000000007

int cou[MAXN];
int sum = 0;
int n;
int board[4][4];

void go(int num, int i, int j);
void backtrack(int i, int j) {
    if (i == 3 && j == 0) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                printf("%2d%c", board[x][y], y == n - 1 ? '\n' : ' ');
            }
        }
        exit(0);
    }
    if (j == 3) {
        int s = sum;
        for (int x = 0; x < 3; x++)
            s -= board[i][x];
        go(s, i, j);
        return;
    }
    if (i == 3) {
        int s = sum;
        for (int x = 0; x < 3; x++)
            s -= board[x][j];
        go(s, i, j);
        return;
    }
    if (i == 2 && j == 1) {
        go(board[0][0] + board[1][0] + board[2][0] - board[1][2] - board[0][3], i, j);
        return;
    }
    if (i == 2 && j == 2) {
        int o = board[0][3] + board[1][3] + sum - board[2][0] - board[2][1] - board[0][0] - board[1][1];
        if (o % 2 == 0)
            go(o / 2, i, j);
        return;
    }
    if (i == 1 && j == 0) {
        for (int x = 0; x < MAXN; x++) {
            if (cou[x] > board[0][1])
                break;
            go(x, i, j);
        }
        return;
    }
    for (int x = 0; x < MAXN; x++)
        go(x, i, j);
}

void go(int num, int i, int j) {
    if (cou[num] == 0) return;
    int under = -1;
    if (i == 2) {
        under = sum - board[0][j] - board[1][j] - num;
        if (under == num) {
            if (cou[num] < 2) return;
            cou[num]--;
        } else {
            if (cou[under] == 0) return;
            cou[under]--;
        }
        board[3][j] = under;
    }
    cou[num]--;
    board[i][j] = num;
    if (j == 3)
        backtrack(i + 1, 0);
    else
        backtrack(i, j + 1);
    cou[num]++;
    if (i == 2) {
        cou[under]++;
    }
}

int main() {
    scanf("%d", &n);
    int nums[MAXN * MAXN];
    for (int i = 0; i < n * n; i++) {
        int x;
        scanf("%d", &x);
        cou[x]++;
        sum += x;
        nums[i] = x;
    }
    if (sum % n != 0) return 0;
    sum /= n;
    printf("%d\n", sum);
    if (n <= 3) {
        // Sorting and permutation logic would go here
    }
    backtrack(0, 0);
}
