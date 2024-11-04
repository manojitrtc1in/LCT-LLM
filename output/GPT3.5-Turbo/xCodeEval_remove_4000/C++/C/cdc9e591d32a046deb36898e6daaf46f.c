#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int int64;
typedef unsigned long long int uint64;

#define STR(x) #x
#define DEBUG(x) printf("%s: %lld\n", #x, (long long)x)

void b303() {
    int64 n, m, x, y, a, b;
    scanf("%lld %lld %lld %lld %lld %lld", &n, &m, &x, &y, &a, &b);

    int64 g = gcd(a, b);
    a /= g;
    b /= g;

    DEBUG(g);
    DEBUG(a);
    DEBUG(b);

    int64 k = min(m / b, n / a);
    int64 width = k * a;
    int64 height = k * b;

    DEBUG(k);
    DEBUG(width);
    DEBUG(height);

    int64 x1 = max(x - (width + 1) / 2, 0LL);
    int64 x2 = min(x1 + width, n);
    x1 = x2 - width;

    int64 y1 = max(y - (height + 1) / 2, 0LL);
    int64 y2 = min(y1 + height, m);
    y1 = y2 - height;

    printf("%lld %lld %lld %lld\n", x1, y1, x2, y2);
}

int main() {
    b303();

    return 0;
}
