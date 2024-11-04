#include<stdio.h>
#include<stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    int b[100][n+1];
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j <= n; j++) {
            b[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        b[a[i]][i+1]++;
    }
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < n; j++) {
            b[i][j+1] += b[i][j];
        }
    }
    int find() {
        int mx = 0, ret = -1;
        for(int i = 0; i < 100; i++) {
            if(mx < b[i][n]) {
                mx = b[i][n];
                ret = i;
            }
        }
        return ret;
    }
    int i = find();
    int ans = 0;
    int mp[404040];
    for(int i = 0; i < 404040; i++) {
        mp[i] = -1;
    }
    for(int j = 0; j < 100; j++) {
        if(i == j) {
            continue;
        }
        if(b[i][0] == 0 || b[j][0] == 0) {
            continue;
        }
        int x = 0, y = 0;
        int now = 202020;
        mp[202020] = 0;
        while(1) {
            int nex(int x, int y) {
                if(x != b[i][n] && y != b[j][n]) {
                    if(b[i][x] < b[j][y]) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else if(x != b[i][n]) {
                    return 1;
                } else if(y != b[j][n]) {
                    return -1;
                } else {
                    return -2;
                }
            }
            int tmp = nex(x, y);
            if(tmp == -2) {
                break;
            }
            if(tmp == 1) {
                x++;
            } else {
                y++;
            }
            now += tmp;
            if(mp[now] != -1) {
                tmp = nex(x, y);
                if(tmp == -2) {
                    ans = max(ans, n - mp[now]);
                } else {
                    ans = max(ans, tmp - mp[now]);
                }
            } else {
                mp[now] = tmp + 1;
            }
        }
        for(int i = 0; i < 404040; i++) {
            mp[i] = -1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
