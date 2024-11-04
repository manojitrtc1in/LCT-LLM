#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 202020
#define MAX_M 100
#define INF 1000000007

int a[MAX_N];
int sum[MAX_M][MAX_N];
int mp[404040];

void chmax(int *a, int b) {
    if (*a < b) *a = b;
}

int find(int n) {
    int mx = 0, ret = -1;
    for (int i = 0; i < MAX_M; i++) {
        if (mx < sum[i][n]) {
            mx = sum[i][n];
            ret = i;
        }
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }

    int b[MAX_M][MAX_N] = {0}; // 2D array for storing indices
    for (int i = 0; i < n; i++) {
        sum[a[i]][i + 1]++;
        b[a[i]][sum[a[i]][i + 1]] = i + 1; // Store the index
    }

    for (int i = 0; i < MAX_M; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j + 1] += sum[i][j];
        }
    }

    int i = find(n);
    int ans = 0;
    for (int j = 0; j < 404040; j++) {
        mp[j] = -1;
    }

    for (int j = 0; j < MAX_M; j++) {
        if (i == j) continue;
        if (b[i][0] == 0 || b[j][0] == 0) continue;

        int x = 0, y = 0;
        int now = 202020;
        mp[202020] = 0;
        int era[404040]; // Temporary storage for eras
        int era_count = 0;

        while (true) {
            int tmp_x = (x < sum[i][0]) ? b[i][x] : INF;
            int tmp_y = (y < sum[j][0]) ? b[j][y] : INF;

            int tmp;
            if (tmp_x != INF && tmp_y != INF) {
                if (tmp_x < tmp_y) {
                    tmp = 1;
                } else {
                    tmp = -1;
                }
            } else if (tmp_x != INF) {
                tmp = 1;
            } else if (tmp_y != INF) {
                tmp = -1;
            } else {
                break;
            }

            if (tmp == 1) x++;
            else y++;

            now += tmp;
            if (mp[now] != -1) {
                if (tmp == 1) {
                    tmp_x = (x < sum[i][0]) ? b[i][x] : INF;
                    if (tmp_x == INF) {
                        chmax(&ans, n - mp[now]);
                    } else {
                        chmax(&ans, tmp_x - mp[now]);
                    }
                }
            } else {
                mp[now] = (tmp == 1) ? b[i][x - 1] + 1 : b[j][y - 1] + 1;
                era[era_count++] = now;
            }
        }

        for (int k = 0; k < era_count; k++) {
            mp[era[k]] = -1;
        }
    }

    printf("%d\n", ans);
    return 0;
}
