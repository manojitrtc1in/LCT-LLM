#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long a;
    long long b;
} Fraction;

typedef struct {
    Fraction first;
    Fraction second;
} Pair;

int gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int compare(Fraction lhs, Fraction rhs) {
    return lhs.a * rhs.b < rhs.a * lhs.b;
}

void solve() {
    int n, w;
    scanf("%d %d", &n, &w);
    Pair *FI = (Pair *)malloc(n * sizeof(Pair));
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        Fraction left = { -a, b - w };
        Fraction right = { -a, b + w };
        int hoge = gcd(abs(left.a), abs(left.b));
        left.a /= hoge;
        left.b /= hoge;
        if (left.b < 0) {
            left.a *= -1;
            left.b *= -1;
        }
        hoge = gcd(abs(right.a), abs(right.b));
        right.a /= hoge;
        right.b /= hoge;
        if (right.b < 0) {
            right.a *= -1;
            right.b *= -1;
        }
        right.a *= -1;
        FI[i].first = left;
        FI[i].second = right;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (compare(FI[i].first, FI[j].first)) {
                Pair temp = FI[i];
                FI[i] = FI[j];
                FI[j] = temp;
            }
        }
    }
    int ans = 0;
    int *zip = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        FI[i].second.a *= -1;
        zip[i] = FI[i].second.b;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (zip[i] > zip[j]) {
                int temp = zip[i];
                zip[i] = zip[j];
                zip[j] = temp;
            }
        }
    }
    int *seg = (int *)malloc(2 * n * sizeof(int));
    for (int i = 0; i < 2 * n; i++) {
        seg[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int hoge = zip[i];
        ans += seg[hoge];
        seg[hoge]++;
    }
    printf("%d\n", ans);
    free(FI);
    free(zip);
    free(seg);
}

int main() {
    solve();
    return 0;
}
