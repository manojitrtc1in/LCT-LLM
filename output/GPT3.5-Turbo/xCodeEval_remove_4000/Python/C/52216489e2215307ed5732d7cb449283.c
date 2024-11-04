#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int countGreater(int arr[], int n, int k) {
    int l = 0;
    int r = n - 1;

    int leftGreater = n;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] >= k) {
            leftGreater = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return (n - leftGreater);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int cnt[MAX_SIZE + 1] = {0};
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        cnt[a - 1]++;
        cnt[b]--;
    }

    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
    }

    int l[MAX_SIZE] = {0};
    int l1[MAX_SIZE] = {0};
    int ind[MAX_SIZE + 1] = {0};
    int s[MAX_SIZE] = {0};
    int s1[MAX_SIZE] = {0};
    int cou[MAX_SIZE] = {0};
    int cur = 0;
    int cur1 = 0;
    int fi[MAX_SIZE] = {0};

    for (int i = 0; i < m; i++) {
        int mw = s[ind[i]] + 1;

        l[ind[i]] = mw;
        fi[i] = mw;
        cur1 = max(cur1, mw);
        s[ind[i]] = mw;
    }

    for (int i = m - 1; i >= 0; i--) {
        int mw = s1[ind[i]] + 1;

        fi[i] += mw;
        l1[ind[i]] = mw;
        s1[ind[i]] = mw;
    }

    int result = cur1 - 1;
    printf("%d\n", result);

    return 0;
}
