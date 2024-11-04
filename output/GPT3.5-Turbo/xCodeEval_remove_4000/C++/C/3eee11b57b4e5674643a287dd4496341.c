#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 202020
#define MAX_M 100
#define MAX_SUM 404040

int a[MAX_N];
int sum[MAX_M][MAX_N];
int mp[MAX_SUM];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    int b[MAX_M][MAX_N];
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++) {
        sum[a[i]][i + 1]++;
        b[a[i]][i + 1] = i;
    }
    for (int i = 0; i < MAX_M; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j + 1] += sum[i][j];
        }
    }
    int find() {
        int mx = 0, ret = -1;
        for (int i = 0; i < MAX_M; i++) {
            if (mx < sum[i][n]) {
                mx = sum[i][n];
                ret = i;
            }
        }
        return ret;
    }
    int i = find();
    int ans = 0;
    memset(mp, -1, sizeof(mp));
    for (int j = 0; j < MAX_M; j++) {
        if (i == j) {
            continue;
        }
        if (b[i][0] == 0 || b[j][0] == 0) {
            continue;
        }
        int x = 0, y = 0;
        int now = 202020;
        mp[202020] = 0;
        while (1) {
            int nex(int x, int y) {
                if (x != b[i][0] && y != b[j][0]) {
                    if (b[i][x] < b[j][y]) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else if (x != b[i][0]) {
                    return 1;
                } else if (y != b[j][0]) {
                    return -1;
                } else {
                    return -2;
                }
            }
            int tmp = nex(x, y);
            if (tmp == -2) {
                break;
            }
            if (tmp == 1) {
                x++;
            } else {
                y++;
            }
            now += tmp;
            if (mp[now] != -1) {
                tmp = nex(x, y);
                if (tmp == -2) {
                    if (ans < n - mp[now]) {
                        ans = n - mp[now];
                    }
                } else {
                    if (ans < tmp - mp[now]) {
                        ans = tmp - mp[now];
                    }
                }
            } else {
                mp[now] = tmp + 1;
            }
        }
        memset(mp, -1, sizeof(mp));
    }
    printf("%d\n", ans);
    return 0;
}
