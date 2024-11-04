#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long a;
    long long b;
} Fraction;

Fraction createFraction(long long c, long long d) {
    Fraction f;
    int hoge = gcd(abs(c), abs(d));
    c /= hoge;
    d /= hoge;
    if (d < 0) {
        d *= -1;
        c *= -1;
    }
    f.a = c;
    f.b = d;
    return f;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n, w;
    scanf("%d %d", &n, &w);
    Fraction FI[n];
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        Fraction Left = createFraction(-a, b - w);
        Fraction Right = createFraction(-a, b + w);
        Right.a *= -1;
        FI[i] = {Left, Right};
    }
    qsort(FI, n, sizeof(Fraction), compareFractions);
    int ans = 0;
    int zip[n];
    for (int i = 0; i < n; i++) {
        FI[i].second.a *= -1;
        zip[i] = FI[i].second;
    }
    int seg[2 * n];
    memset(seg, 0, sizeof(seg));
    for (int i = 0; i < n; i++) {
        int hoge = zip[i];
        ans += query(seg, hoge, 2 * n);
        int tmp = seg[hoge];
        update(seg, hoge, tmp + 1);
    }
    printf("%d\n", ans);
    return 0;
}
