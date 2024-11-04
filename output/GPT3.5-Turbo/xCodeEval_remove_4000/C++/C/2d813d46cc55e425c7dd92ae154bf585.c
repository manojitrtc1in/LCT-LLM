#include <stdio.h>
#include <stdlib.h>

#define s(n, m) scanf("%d%d", &n, &m)
#define f(i, a, b) for(int i = a; i <= b; i++)
#define max_set(a, b) if(b > a) a = b
#define USEFILE 0
#define TESTCASE 0
#define SPLITCASE 0
#define PRINTCASE 0

int n, k, p, c = 0, a[505][505], out[125005], chk[125005], ans, best = 0;
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
char x;

typedef struct {
    int i, j;
} pos;

pos t;
pos q[125005];
int front = 0, rear = -1;

void push(pos p) {
    q[++rear] = p;
}

pos pop() {
    return q[front++];
}

void solve() {
    s(n, k);
    f(i, 1, n) {
        f(j, 1, n) {
            scanf(" %c", &x);
            a[i][j] = (x == '.') ? (-1) : (0);
        }
    }
    f(i, 1, n) {
        f(j, 1, n) {
            if (a[i][j] == -1) {
                c++;
                a[i][j] = c;
                push((pos){i, j});
                while (front <= rear) {
                    t = pop();
                    f(k, 0, 3) {
                        if (a[t.i + di[k]][t.j + dj[k]] == -1) {
                            a[t.i + di[k]][t.j + dj[k]] = c;
                            push((pos){t.i + di[k], t.j + dj[k]});
                        }
                    }
                }
            }
        }
    }
    f(i, 0, n + 1) {
        f(j, 0, n + 1) {
            out[a[i][j]]++;
        }
    }
    f(addi, 0, n - k) {
        f(i, addi + 1, addi + k) {
            f(j, 0, k - 1) {
                out[a[i][j]]--;
            }
        }
        f(addj, 0, n - k) {
            ans = k * k;
            f(i, addi + 1, addi + k) {
                out[a[i][addj]]++;
                out[a[i][addj + k]]--;
            }
            f(i, addi + 1, addi + k) {
                p = a[i][addj];
                if (p && !chk[p]) {
                    chk[p] = 1;
                    ans += out[p];
                }
                p = a[i][addj + k + 1];
                if (p && !chk[p]) {
                    chk[p] = 1;
                    ans += out[p];
                }
            }
            f(j, addj + 1, addj + k) {
                p = a[addi][j];
                if (p && !chk[p]) {
                    chk[p] = 1;
                    ans += out[p];
                }
                p = a[addi + k + 1][j];
                if (p && !chk[p]) {
                    chk[p] = 1;
                    ans += out[p];
                }
            }
            f(i, addi + 1, addi + k) {
                chk[a[i][addj]] = 0;
                chk[a[i][addj + k + 1]] = 0;
            }
            f(j, addj + 1, addj + k) {
                chk[a[addi][j]] = 0;
                chk[a[addi + k + 1][j]] = 0;
            }
            max_set(best, ans);
        }
        f(i, addi + 1, addi + k) {
            f(j, n - k + 1, n) {
                out[a[i][j]]++;
            }
        }
    }
    printf("%d\n", best);
    return;
}

void prep() {
    return;
}

int main() {
    if (USEFILE) {
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
    prep();
    if (TESTCASE) {
        int test_num;
        scanf("%d", &test_num);
        for (int test_count = 1; test_count <= test_num; test_count++) {
            if (SPLITCASE) {
                fprintf(stderr, "\n>>>>> Test %d <<<<<\n", test_count);
            }
            if (PRINTCASE) {
                printf("Case %d: ", test_count);
            }
            solve();
        }
    } else {
        solve();
    }
    return 0;
}
