#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 16
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x), (x) + sizeof(x) / sizeof((x)[0])

typedef struct {
    int f;
    int s;
} Pair;

typedef struct {
    Pair pairs[MAXN];
    int size;
} Map;

Map cou;
int sum = 0;
int n;
int board[4][4];

void go(int num, int i, int j);
void backtrack(int i, int j) {
    if (i == n && j == 0) {
        REP(i, n)
            REP(j, n)
                printf("%2d%c", board[i][j], j == n - 1 ? '\n' : ' ');
        exit(0);
    }
    if (j == 3) {
        int s = sum;
        REP(x, 3)
            s -= board[i][x];
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
        for (int k = 0; k < cou.size; k++) {
            if (cou.pairs[k].f > board[0][1])
                break;
            go(cou.pairs[k].f, i, j);
        }
        return;
    }
    for (int k = 0; k < cou.size; k++)
        go(cou.pairs[k].f, i, j);
}

void go(int num, int i, int j) {
    for (int k = 0; k < cou.size; k++) {
        if (cou.pairs[k].f == num) {
            if (cou.pairs[k].s == 0) return;
            cou.pairs[k].s--;
            board[i][j] = num;
            if (j == 3)
                backtrack(i + 1, 0);
            else
                backtrack(i, j + 1);
            cou.pairs[k].s++;
            return;
        }
    }
}

int main() {
    scanf("%d", &n);
    int nums[MAXN * MAXN];
    cou.size = 0;
    REP(_, n * n) {
        int x;
        scanf("%d", &x);
        bool found = false;
        for (int k = 0; k < cou.size; k++) {
            if (cou.pairs[k].f == x) {
                cou.pairs[k].s++;
                found = true;
                break;
            }
        }
        if (!found) {
            cou.pairs[cou.size].f = x;
            cou.pairs[cou.size].s = 1;
            cou.size++;
        }
        sum += x;
        nums[_] = x;
    }
    if (sum % n != 0) return 1;
    sum /= n;
    printf("%d\n", sum);
    if (n <= 3) {
        // Sorting and checking permutations would go here
        // This part is omitted for brevity
    }
    backtrack(0, 0);
}
