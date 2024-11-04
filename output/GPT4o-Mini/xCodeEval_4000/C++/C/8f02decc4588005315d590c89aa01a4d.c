#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAXN 4
#define MAX_SUM 1000000

typedef struct {
    int f;
    int s;
} Pair;

Pair cou[MAX_SUM];
int sum = 0;
int n;
int board[MAXN][MAXN];

void go(int num, int i, int j);
void backtrack(int i, int j) {
    if (i == 3 && j == 0) {
        for (int x = 0; x < n; x++)
            for (int y = 0; y < n; y++)
                printf("%2d%c", board[x][y], y == n - 1 ? '\n' : ' ');
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
        assert(0);
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
        for (int x = 0; x < MAX_SUM; x++) {
            if (cou[x].f > board[0][1])
                break;
            go(cou[x].f, i, j);
        }
        return;
    }
    for (int x = 0; x < MAX_SUM; x++)
        go(cou[x].f, i, j);
}

void go(int num, int i, int j) {
    Pair *it = NULL;
    for (int x = 0; x < MAX_SUM; x++) {
        if (cou[x].f == num) {
            it = &cou[x];
            break;
        }
    }
    if (it == NULL || it->s == 0) return;
    int under = -1;
    if (i == 2) {
        under = sum - board[0][j] - board[1][j] - num;
        if (under == num) {
            if (it->s < 2) return;
            it->s--;
        } else {
            Pair *it2 = NULL;
            for (int x = 0; x < MAX_SUM; x++) {
                if (cou[x].f == under) {
                    it2 = &cou[x];
                    break;
                }
            }
            if (it2 == NULL || it2->s == 0) return;
            it2->s--;
        }
        board[3][j] = under;
    }
    it->s--;
    board[i][j] = num;
    if (j == 3)
        backtrack(i + 1, 0);
    else
        backtrack(i, j + 1);
    it->s++;
    if (i == 2) {
        assert(cou[under].f);
        cou[under].s++;
    }
}

int main() {
    scanf("%d", &n);
    int nums[MAXN * MAXN];
    memset(cou, 0, sizeof(cou));
    for (int i = 0; i < n * n; i++) {
        int x;
        scanf("%d", &x);
        cou[x].f = x;
        cou[x].s++;
        sum += x;
        nums[i] = x;
    }
    assert(sum % n == 0);
    sum /= n;
    printf("%d\n", sum);
    if (n <= 3) {
        qsort(nums, n * n, sizeof(int), cmp);
        do {
            int good = 1;
            for (int i = 0; i < n; i++) {
                int s1 = 0, s2 = 0;
                for (int j = 0; j < n; j++) {
                    s1 += nums[i * n + j];
                    s2 += nums[j * n + i];
                }
                if (s1 != sum || s2 != sum)
                    good = 0;
            }
            int s1 = 0, s2 = 0;
            for (int i = 0; i < n; i++) {
                s1 += nums[i * n + i];
                s2 += nums[i * n + n - i - 1];
            }
            if (s1 != sum || s2 != sum)
                good = 0;
            if (good) {
                for (int i = 0; i < n * n; i++)
                    printf("%d%c", nums[i], i % n == n - 1 ? '\n' : ' ');
                return 0;
            }
        } while (next_permutation(nums, nums + n * n));
    }
    backtrack(0, 0);
}
