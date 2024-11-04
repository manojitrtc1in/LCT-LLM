#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

typedef long long li;
typedef long double ld;

#define MAX_NUMS 100000

li nums[MAX_NUMS];
int nums_size = 0;

int l1, r1, l2, r2;
int k;

bool read() {
    return scanf("%d%d%d%d%d", &l1, &r1, &l2, &r2, &k) == 5;
}

int calc(int x) {
    char s[20];
    sprintf(s, "%d", x);
    int cur = 1 << (strlen(s) - 1);
    int ans = cur * 2 - 1;
    bool fl = true;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] > '7')
            ans += 2 * cur;
        else if (s[i] > '4')
            ans += cur;
        if (s[i] != '7' && s[i] != '4') {
            fl = false;
            break;
        }
        cur >>= 1;
    }
    ans += fl;
    return ans;
}

void brute(int x, int num) {
    nums[nums_size++] = num;
    if (x == 9) return;
    brute(x + 1, num * 10 + 4);
    brute(x + 1, num * 10 + 7);
}

void solve() {
    nums_size = 0;
    brute(0, 0);
    qsort(nums, nums_size, sizeof(li), cmpfunc);
    
    li tot = (r1 - l1 + 1) * (r2 - l2 + 1);
    li ok = 0;

    for (int i = 1; i <= nums_size - k; i++) {
        int l = nums[i];
        int r = nums[i + k - 1];
        int pl = nums[i - 1] + 1;
        int pr = (i + k == nums_size ? INT_MAX + 7 : nums[i + k] - 1);
        if (l1 <= l && r <= r2) {
            int ll = fmax(l1, pl);
            int rr = fmin(r2, pr);
            ok += fmax(0, fmin(l, r1) - ll + 1) * fmax(0, rr - fmax(r, l2) + 1);
        }
        if (l2 <= l && r <= r1) {
            int ll = fmax(l2, pl);
            int rr = fmin(r1, pr);
            ok += fmax(0, fmin(l, r2) - ll + 1) * fmax(0, rr - fmax(r, l1) + 1);
        }
    }
    if (k == 1) {
        for (int i = 0; i < nums_size; i++)
            ok -= l1 <= nums[i] && nums[i] <= r1 && l2 <= nums[i] && nums[i] <= r2;
    }

    printf("%.15Lf\n", ok / (ld)tot);
}

int cmpfunc(const void *a, const void *b) {
    return (*(li*)a - *(li*)b);
}

int main() {
    freopen("input.txt", "r", stdin);
    
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        read();
        solve();
    }
    return 0;
}
