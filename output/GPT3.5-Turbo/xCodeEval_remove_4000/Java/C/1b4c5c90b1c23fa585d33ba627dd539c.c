#include <stdio.h>
#include <stdlib.h>

typedef struct pair {
    int num;
    int v;
} pair;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int n, k, d;
        scanf("%d %d %d", &n, &k, &d);
        int *a = (int*)malloc(n * sizeof(int));
        int *occ = (int*)calloc(n + 1, sizeof(int));
        int id = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (occ[a[i]] == 0) {
                occ[a[i]] = ++id;
            }
            a[i] = occ[a[i]];
        }
        int ans = 0;
        for (int i = 0; i < d; i++) {
            occ[a[i]]++;
            if (occ[a[i]] == 1) {
                ans++;
            }
        }
        int ansl = ans;
        for (int i = d; i < n; i++) {
            int ans1 = ansl;
            occ[a[i]]++;
            if (occ[a[i]] == 1) {
                ans1++;
            }
            occ[a[i - d]]--;
            if (occ[a[i - d]] == 0) {
                ans1--;
            }
            ans = (ans < ans1) ? ans : ans1;
            ansl = ans1;
        }
        printf("%d\n", ans);
        free(a);
        free(occ);
    }
    return 0;
}
