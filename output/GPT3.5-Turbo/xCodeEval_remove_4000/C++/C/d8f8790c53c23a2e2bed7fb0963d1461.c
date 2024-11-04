#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long a;
    long long b;
} Fraction;

int gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int compare(Fraction f1, Fraction f2) {
    return f1.a * f2.b < f2.a * f1.b;
}

void solve() {
    int n, w;
    scanf("%d %d", &n, &w);
    Fraction FI[n];
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        Fraction Left = { -a, b - w };
        Fraction Right = { -a, b + w };
        int hoge = gcd(abs(Left.a), abs(Left.b));
        Left.a /= hoge;
        Left.b /= hoge;
        if (Left.b < 0) {
            Left.a *= -1;
            Left.b *= -1;
        }
        hoge = gcd(abs(Right.a), abs(Right.b));
        Right.a /= hoge;
        Right.b /= hoge;
        if (Right.b < 0) {
            Right.a *= -1;
            Right.b *= -1;
        }
        Right.a *= -1;
        FI[i] = Left;
    }
    qsort(FI, n, sizeof(Fraction), compare);
    int ans = 0;
    long long zip[n];
    for (int i = 0; i < n; i++) {
        zip[i] = FI[i].b;
    }
    int compressed[n];
    int uncompressed[n];
    int zip_size = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < zip_size; j++) {
            if (zip[i] == zip[j]) {
                found = 1;
                compressed[i] = j;
                break;
            }
        }
        if (!found) {
            compressed[i] = zip_size;
            uncompressed[zip_size] = zip[i];
            zip_size++;
        }
    }
    int seg[2 * n];
    for (int i = 0; i < 2 * n; i++) {
        seg[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int hoge = compressed[i];
        ans += seg[hoge];
        seg[hoge]++;
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}
