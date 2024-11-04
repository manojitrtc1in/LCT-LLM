#include <stdio.h>
#include <stdlib.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define PB push_back

int MOD = 1e9 + 7;
int MN = 1e6 + 44;
int local = 0;

typedef long long LL;
typedef long double LD;
typedef int VI;
typedef struct { int first, second; } PII;
typedef struct { int u, d, l, r; } tqaz;
typedef struct { int o; LD v; } zet_p;
typedef struct { int o, m; } frac_mod;
typedef struct { int o; } gyv;

int mpow(int b, int e) {
    int o = 1;
    while (e) {
        if (e & 1)
            o = o * 1ll * b % MOD;
        b = b * 1ll * b % MOD;
        e /= 2;
    }
    return o;
}

void backtrack(int i, int j);
void go(int num, int i, int j);

int n;
int board[4][4];
int sum = 0;
int cou[16] = {0};

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
        REP(x, 3) {
            s -= board[i][x];
        }
        go(s, i, j);
        return;
    }
    if (i == 3) {
        int s = sum;
        REP(x, 3) {
            s -= board[x][j];
        }
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
        for (int x = 0; x < 16; ++x) {
            if (x > board[0][1])
                break;
            go(x, i, j);
        }
        return;
    }
    for (int x = 0; x < 16; ++x) {
        go(x, i, j);
    }
}

void go(int num, int i, int j) {
    if (num < 0 || num >= 16 || cou[num] == 0)
        return;
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
    int nums[16];
    REP(_, n * n) {
        int x;
        scanf("%d", &x);
        cou[x]++;
        sum += x;
        nums[_] = x;
    }
    sum /= n;
    printf("%d\n", sum);
    if (n <= 3) {
        for (int i = 0; i < 16; ++i) {
            for (int j = 0; j < 16; ++j) {
                for (int k = 0; k < 16; ++k) {
                    for (int l = 0; l < 16; ++l) {
                        bool good = 1;
                        for (int a = 0; a < n; ++a) {
                            int s1 = 0, s2 = 0;
                            for (int b = 0; b < n; ++b) {
                                s1 += nums[a * n + b];
                                s2 += nums[b * n + a];
                            }
                            if (s1 != sum || s2 != sum)
                                good = 0;
                        }
                        int s1 = 0, s2 = 0;
                        for (int a = 0; a < n; ++a) {
                            s1 += nums[a * n + a];
                            s2 += nums[a * n + n - a - 1];
                        }
                        if (s1 != sum || s2 != sum)
                            good = 0;
                        if (good) {
                            for (int a = 0; a < n * n; ++a) {
                                printf("%d%c", nums[a], a % n == n - 1 ? '\n' : ' ');
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }
    backtrack(0, 0);
    return 0;
}
