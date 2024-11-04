#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUMS 100000
#define INF (int)(1e9)
#define INF64 (long long)(1e18)
#define MOD ((int)(1e9) + 7)
#define EPS 1e-9
#define PI acos(-1.0)

int l1, r1, l2, r2;
int k;
int nums[MAX_NUMS];
int num_count = 0;

int read() {
    return scanf("%d%d%d%d%d", &l1, &r1, &l2, &r2, &k) == 5;
}

int calc(int x) {
    char s[20];
    sprintf(s, "%d", x);
    int cur = 1 << (strlen(s) - 1);
    int ans = cur * 2 - 1;
    int fl = 1;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] > '7')
            ans += 2 * cur;
        else if (s[i] > '4')
            ans += cur;
        if (s[i] != '7' && s[i] != '4') {
            fl = 0;
            break;
        }
        cur >>= 1;
    }
    ans += fl;
    return ans;
}

void brute(int x, int num) {
    nums[num_count++] = num;
    if (x == 9) return;
    brute(x + 1, num * 10 + 4);
    brute(x + 1, num * 10 + 7);
}

void solve() {
    num_count = 0;
    brute(0, 0);
    qsort(nums, num_count, sizeof(int), (int (*)(const void *, const void *))strcmp);
    
    long long tot = (r1 - l1 + 1) * (long long)(r2 - l2 + 1);
    long long ok = 0;

    for (int i = 1; i <= num_count - k; i++) {
        int l = nums[i];
        int r = nums[i + k - 1];
        int pl = nums[i - 1] + 1;
        int pr = (i + k == num_count ? INF + 7 : nums[i + k] - 1);
        
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
        for (int i = 0; i < num_count; i++)
            ok -= l1 <= nums[i] && nums[i] <= r1 && l2 <= nums[i] && nums[i] <= r2;
    }
    
    printf("%.15Lf\n", ok / (long double)tot);
}

int main() {
    while (read()) {
        solve();
    }
    return 0;
}
