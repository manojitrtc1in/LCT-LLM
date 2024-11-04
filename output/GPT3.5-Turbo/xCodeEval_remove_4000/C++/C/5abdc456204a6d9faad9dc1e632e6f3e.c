#include <stdio.h>
#include <stdlib.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()

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
    for (auto x : cou) {
        if (x.f >= limit)
            go(x.f, i, j);
    }
}
void go(int num, int i, int j) {
    auto it = cou.find(num);
    if (it == cou.end() || it -> s == 0) return;
    it -> s--;
    board[i][j] = num;
    if (j == 3)
        backtrack(i + 1, 0);
    else
        backtrack(i, j + 1);
    it -> s++;
}
int main() {
    scanf("%d", &n);
    int nums[n * n];
    int cou[1000000] = {0};
    REP(_, n * n) {
        int x;
        scanf("%d", &x);
        cou[x]++;
        sum += x;
        nums[_] = x;
    }
    assert(sum % n == 0);
    sum /= n;
    printf("%d\n", sum);
    if (n <= 3) {
        sort(ALL(nums));
        do {
            bool good = true;
            REP(i, n) {
                int s1 = 0, s2 = 0;
                REP(j, n) {
                    s1 += nums[i * n + j];
                    s2 += nums[j * n + i];
                }
                if (s1 != sum || s2 != sum)
                    good = false;
            }
            int s1 = 0, s2 = 0;
            REP(i, n) {
                s1 += nums[i * n + i];
                s2 += nums[i * n + n - i - 1];
            }
            if (s1 != sum || s2 != sum)
                good = false;
            if (good) {
                REP(i, n * n)
                    printf("%d%c", nums[i], i % n == n - 1 ? '\n' : ' ');
                return 0;
            }
        }
        while (next_permutation(ALL(nums)));
    }
    backtrack(0, 0);
    return 0;
}