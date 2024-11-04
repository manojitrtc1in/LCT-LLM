#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 1000
#define MOD 1000000007

int cou[MAXN] = {0};
int sum = 0;
int n;
int board[4][4];

void go(int num, int i, int j);
void backtrack(int i, int j) {
    if (i == n && j == 0) {
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
        if (i == 0 && s < board[0][0])
            return;
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
        int v = board[0][0] + board[1][0] + board[2][0] - board[1][2] - board[0][3];
        if (v >= board[0][0])
            go(v, i, j);
        return;
    }
    if (i == 2 && j == 2) {
        int o = board[0][3] + board[1][3] + sum - board[2][0] - board[2][1] - board[0][0] - board[1][1];
        if (o % 2 == 0 && o / 2 >= board[0][0])
            go(o / 2, i, j);
        return;
    }
    int limit = -1e9;
    if ((i == 0 && j == 2) || ((i == 1 || i == 2) && (j == 0)))
        limit = board[0][1];
    else if ((i == j || i + j == 3) && (i || j))
        limit = board[0][0];
    
    for (int x = 0; x < MAXN; x++) {
        if (cou[x] >= limit)
            go(x, i, j);
    }
}

void go(int num, int i, int j) {
    if (cou[num] == 0) return;
    cou[num]--;
    board[i][j] = num;
    if (j == 3)
        backtrack(i + 1, 0);
    else
        backtrack(i, j + 1);
    cou[num]++;
}

int main() {
    scanf("%d", &n);
    int nums[MAXN];
    for (int i = 0; i < n * n; i++) {
        int x;
        scanf("%d", &x);
        cou[x]++;
        sum += x;
        nums[i] = x;
    }
    if (sum % n != 0) {
        return 0;
    }
    sum /= n;
    printf("%d\n", sum);
    
    if (n <= 3) {
        qsort(nums, n * n, sizeof(int), cmpfunc);
        do {
            bool good = true;
            for (int i = 0; i < n; i++) {
                int s1 = 0, s2 = 0;
                for (int j = 0; j < n; j++) {
                    s1 += nums[i * n + j];
                    s2 += nums[j * n + i];
                }
                if (s1 != sum || s2 != sum)
                    good = false;
            }
            int s1 = 0, s2 = 0;
            for (int i = 0; i < n; i++) {
                s1 += nums[i * n + i];
                s2 += nums[i * n + n - i - 1];
            }
            if (s1 != sum || s2 != sum)
                good = false;
            if (good) {
                for (int i = 0; i < n * n; i++)
                    printf("%d%c", nums[i], i % n == n - 1 ? '\n' : ' ');
                return 0;
            }
        } while (next_permutation(nums, nums + n * n));
    }
    backtrack(0, 0);
}
