#include <stdio.h>
#include <string.h>

typedef struct {
    int i;
    int j;
} pos;

int n, k, p, c = 0;
int a[505][505];
int out[125005];
int chk[125005];
int ans, best = 0;
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
char x;
pos t;
pos q[125005];
int front = 0, rear = 0;

void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %c", &x);
            a[i][j] = (x == '.') ? (-1) : (0);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == -1) {
                c++;
                a[i][j] = c;
                q[rear].i = i;
                q[rear].j = j;
                rear++;
                while (front != rear) {
                    t = q[front];
                    for (int k = 0; k < 4; k++) {
                        if (a[t.i + di[k]][t.j + dj[k]] == -1) {
                            a[t.i + di[k]][t.j + dj[k]] = c;
                            q[rear].i = t.i + di[k];
                            q[rear].j = t.j + dj[k];
                            rear++;
                        }
                    }
                    front++;
                }
            }
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            out[a[i][j]]++;
        }
    }
    for (int addi = 0; addi <= n - k; addi++) {
        for (int i = addi + 1; i <= addi + k; i++) {
            for (int j = 0; j < k; j++) {
                out[a[i][j]]--;
            }
        }
        for (int addj = 0; addj <= n - k; addj++) {
            ans = k * k;
            for (int i = addi + 1; i <= addi + k; i++) {
                out[a[i][addj]]++;
                out[a[i][addj + k]]--;
            }
            for (int i = addi + 1; i <= addi + k; i++) {
                int p = a[i][addj];
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
            for (int j = addj + 1; j <= addj + k; j++) {
                int p = a[addi][j];
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
            for (int i = addi + 1; i <= addi + k; i++) {
                chk[a[i][addj]] = 0;
                chk[a[i][addj + k + 1]] = 0;
            }
            for (int j = addj + 1; j <= addj + k; j++) {
                chk[a[addi][j]] = 0;
                chk[a[addi + k + 1][j]] = 0;
            }
            if (ans > best) {
                best = ans;
            }
        }
        for (int i = addi + 1; i <= addi + k; i++) {
            for (int j = n - k + 1; j <= n; j++) {
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
    prep();
    solve();
    return 0;
}
