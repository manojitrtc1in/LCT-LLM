#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

int l1, r1, l2, r2;
int k;

int calc(int x) {
    char s[MAX_SIZE];
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

void brute(int x, int num, int* nums, int* nums_size) {
    nums[(*nums_size)++] = num;
    if (x == 9) return;
    brute(x + 1, num * 10 + 4, nums, nums_size);
    brute(x + 1, num * 10 + 7, nums, nums_size);
}

void solve() {
    int nums[MAX_SIZE];
    int nums_size = 0;
    brute(0, 0, nums, &nums_size);
    qsort(nums, nums_size, sizeof(int), cmpfunc);
    long long tot = (r1 - l1 + 1) * (long long)(r2 - l2 + 1);

    long long ok = 0;
    for (int i = 1; i < nums_size - k + 1; i++) {
        int l = nums[i];
        int r = nums[i + k - 1];
        int pl = nums[i - 1] + 1;
        int pr = (i + k == nums_size ? INF + 7 : nums[i + k] - 1);
        if (l1 <= l && r <= r2) {
            int ll = max(l1, pl);
            int rr = min(r2, pr);
            ok += max(0, min(l, r1) - ll + 1) * (long long)(max(0, rr - max(r, l2) + 1));
        }
        if (l2 <= l && r <= r1) {
            int ll = max(l2, pl);
            int rr = min(r1, pr);
            ok += max(0, min(l, r2) - ll + 1) * (long long)(max(0, rr - max(r, l1) + 1));
        }
    }
    if (k == 1) {
        for (int i = 0; i < nums_size; i++)
            ok -= l1 <= nums[i] && nums[i] <= r1 && l2 <= nums[i] && nums[i] <= r2;
    }

    printf("%.15Lf\n", ok / (long double)tot);
}

int main() {
    while (scanf("%d%d%d%d%d", &l1, &r1, &l2, &r2, &k) == 5) {
        solve();
    }
    return 0;
}
