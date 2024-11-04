#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define nax 500044

int cou[nax];
int prev[nax];
int less[nax];

int sum(int l, int r) {
    assert(l < nax && r < nax);
    return less[r] - less[l];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        cou[x]++;
    }
    for (int i = 1; i < nax; ++i) less[i] = less[i - 1] + cou[i - 1];
    int p = 0;
    for (int i = 0; i < nax; ++i) {
        prev[i] = p;
        if (cou[i]) p = i;
    }
    long long ans = 0;
    for (int y = 2; y < nax; ++y) {
        int low = 2, high = nax - 1;
        long long all = 0;
        for (int i = 1; i * y < nax; ++i)
            all += i * 1ll * sum(i * y, (nax - 1 < i * y + y) ? nax - 1 : i * y + y);
        if (all == 0) continue;
        while (low <= high) {
            int x = (low + high) / 2;
            bool can_get = false;
            if (x % y == 0) {
                can_get = (sum(x, nax - 1) >= 2 || sum((nax - 1 < 2 * x) ? nax - 1 : 2 * x, nax - 1) >= 1) && (all - 2 * (x / y) >= x);
            }
            else {
                long long best = -1;
                if (sum(x, nax - 1) >= 2) {
                    int save = 0;
                    int small_loss = x / y;
                    assert(x > 0);
                    for (int i = 0; i < nax; i += y) {
                        int top = (nax - 1 < i + y) ? nax - 1 : i + y;
                        int g = prev[top];
                        if (g != 0 && g >= ((i > x) ? i : x) && g % y >= x % y) {
                            if (cou[g] >= 2) save += 2;
                            else {
                                save++;
                                int gg = prev[g];
                                if (gg >= ((i > x) ? i : x) && gg % y >= x % y && gg != 0) {
                                    save++;
                                }
                            }
                        }
                    }
                    best = all - small_loss * 2 - ((2 - save) > 0 ? (2 - save) : 0);
                }
                if (2 * x < nax && sum(2 * x, nax - 1) >= 1) {
                    int waste = nax;
                    for (int i = 0; i < nax; i += y) {
                        int top = (nax - 1 < i + y) ? nax - 1 : i + y;
                        int g = prev[top];
                        if (g >= 2 * x)
                            if (g / y - (g - 2 * x) / y < waste)
                                waste = g / y - (g - 2 * x) / y;
                    }
                    if (all - waste > best)
                        best = all - waste;
                }
                if (best >= x)
                    can_get = true;
            }
            if (can_get) {
                ans = (x * 1ll * y > ans) ? x * 1ll * y : ans;
                low = x + 1;
            }
            else
                high = x - 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}