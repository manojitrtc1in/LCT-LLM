#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define i64 long long
#define ld long double

#define endl '\n'
#define rsz resize
#define pub push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);

i64 n, m;

i64 modPow(i64 a, i64 b, i64 M) {
    if (b == 0) return 1;
    i64 tmp = modPow(a, b/2, M);
    if (b % 2 == 0) return ((tmp * tmp) % M);
    return ((((tmp * tmp) % M) * a) % M);
}

void Input() {
    scanf("%lld %lld", &n, &m);
}

void Solve() {
    i64 A = (modPow(3, n, m) + m - 1) % m;
    printf("%lld", A);
}

int main() {
    Input();
    Solve();
    return 0;
}
