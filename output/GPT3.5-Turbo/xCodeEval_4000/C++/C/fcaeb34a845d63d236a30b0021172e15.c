#include <stdio.h>
#include <stdlib.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

int cou[1000001];
int sum = 0;
int n;
int board[4][4];

void go(int num, int i, int j);
void backtrack(int i, int j);

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

void backtrack(int i, int j) {
    if (i == n && j == 0) {
        REP(i, n) {
            REP(j, n) {
                printf("%2d%c", board[i][j], j == n - 1 ? '\n' : ' ');
            }
        }
        exit(0);
    }
    if (j == 3) {
        int s = sum;
        REP(x, 3)
            s -= board[i][x];
        if (i == 0 && s < board[0][0])
            return;
        go(s, i, j);
        return;
    }
    if (i == 3) {
        int s = sum;
        REP(x, 3)
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
    for (int x = 0; x <= 1000000; ++x) {
        if (cou[x] > 0 && x >= limit)
            go(x, i, j);
    }
}

int main() {
    scanf("%d", &n);
    int nums[16];
    REP(_, n * n) {
        int x;
        scanf("%d", &x);
        cou[x]++;
        sum += x;
        nums[_] = x;
    }
    if (sum % n != 0) {
        printf("No solution\n");
        return 0;
    }
    sum /= n;
    printf("%d\n", sum);
    if (n <= 3) {
        int temp[16];
        REP(i, n * n) {
            temp[i] = nums[i];
        }
        do {
            int good = 1;
            REP(i, n) {
                int s1 = 0, s2 = 0;
                REP(j, n) {
                    s1 += temp[i * n + j];
                    s2 += temp[j * n + i];
                }
                if (s1 != sum || s2 != sum)
                    good = 0;
            }
            int s1 = 0, s2 = 0;
            REP(i, n) {
                s1 += temp[i * n + i];
                s2 += temp[i * n + n - i - 1];
            }
            if (s1 != sum || s2 != sum)
                good = 0;
            if (good) {
                REP(i, n * n)
                    printf("%d%c", temp[i], i % n == n - 1 ? '\n' : ' ');
                return 0;
            }
        } while (next_permutation(temp, temp + n * n));
    }
    backtrack(0, 0);
    printf("No solution\n");
    return 0;
}
