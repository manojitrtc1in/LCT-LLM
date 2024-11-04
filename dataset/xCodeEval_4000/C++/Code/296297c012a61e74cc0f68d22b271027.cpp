#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <cstring>
#include <unordered_map>
#include <bitset>
#include <functional>
#include <set>
#include <queue>
#include <map>
#include <list>

using namespace std;

const long long linf = numeric_limits<long long>::max();
const int inf = numeric_limits<int>::max();

template<typename T>
inline void read(T &x) {
    T w = 1;
    char c = getchar();
    x = 0;
    while (c < '0' || c > '9') {
        if (c == '-')
            w = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x *= 10;
        x += c - '0';
        c = getchar();
    }
    x *= w;
}

template<>
inline void read(string &x) {
    cin >> x;
}

template<>
inline void read(double &x) { scanf("%lf", &x); }

template<typename T, typename... Args>
inline void read(T &t, Args &...args) {
    read(t);
    read(args...);
}

template<typename T>
inline void write(T x) {
    static int sta[40];
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    int cnt = -1;
    do {
        sta[++cnt] = x % 10;
        x /= 10;
    } while (x > 0);
    while (cnt >= 0)
        putchar(sta[cnt--] + '0');
}

template<>
inline void write(double x) { printf("%lf", x); }

template<>
inline void write(char x) { putchar(x); }

template<>
inline void write(const char *x) { printf("%s", x); }

template<>
inline void write(string x) { printf("%s", x.c_str()); }

template<>
inline void write(const string &x) { printf("%s", x.c_str()); }

template<>
inline void write(const string &&x) { printf("%s", x.c_str()); }

template<typename T, typename... Args>
inline void write(T a, Args... args) {
    write(a);
    write(args...);
}

template<typename... Args>
inline void writeLn(Args... x) {
    write(x...);
    putchar('\n');
}

bool isPrime(long long x) {
    for (int i = 2; i != ceil(sqrt(x)); ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int euler_phi(int n) {
    int ans = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        ans = ans / n * (n - 1);
    return ans;
}

int qpow(int a, int b, int m) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res % m;
}

template<typename T>
inline T sgn(T x) {
    if (x < 0) return -1;
    if (x) return 1;
    return 0;
}



long cover(long x) {
    int c = 1;
    while (c <= x) c <<= 1;
    return c - 1;
}

long higher(long x) {
    int c = 1;
    while (c <= x) c <<= 1;
    return c;
}

long long complement(long long bits, long long x) {
    return x ^ (bits - 1);
}










int main(void) {
    int t;
    read(t);
    while (t--) {


























































































































































































































































































































































































































































































































































































































































































































#define long long long
        long n, k;
        read(n, k);
        if (k > n - 1) {
            writeLn(-1);
            continue;
        }
        if (k == 0) {
            for (long i = 0; i < n >> 1; ++i) {
                long ci = complement(n, i);
                writeLn(i, ' ', ci);
            }
        } else if (k > 0 && k < n - 1) {
            if (k < complement(n,k)) {
                writeLn(0, ' ', complement(n, k));
                for (long i = 1; i < n >> 1; ++i) {
                    long ci = complement(n, i);
                    if (i == k) {
                        writeLn(k, ' ', n - 1);
                    } else {
                        writeLn(i, ' ', ci);
                    }
                }
            } else {
                long index = complement(n, k);
                writeLn(0, ' ', index);
                for (long i = 1; i < n >> 1; ++i) {
                    if (i == index) {
                        writeLn(n - 1, ' ', k);
                    } else {
                        writeLn(i, ' ', complement(n, i));
                    }
                }
            }
        } else if (k == n - 1) {
            if (n == 4) {
                writeLn(-1);
                continue;
            }
            writeLn(n-2, ' ', n-1);
            writeLn(1, ' ', n-3);
            writeLn(0, ' ', 2);
            set<long> vis;
            for (long i = 3; i < n - 3; ++i) {
                long xx = complement(n, i);
                if (vis.contains(i) || vis.contains(xx)) continue;
                if (xx == 0 || xx == 1 || xx == 2 || xx == n - 1 || xx == n - 2 || xx == n - 3) continue;




                vis.insert(i);
                vis.insert(xx);
                writeLn(i, ' ', xx);
            }
        }
    }
    return 0;
}
