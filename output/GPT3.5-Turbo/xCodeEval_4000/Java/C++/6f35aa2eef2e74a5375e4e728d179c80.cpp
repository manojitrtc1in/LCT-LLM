#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> sieveEratosthenes(int n) {
    if (n <= 32) {
        vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
        for (int i = 0; i < primes.size(); i++) {
            if (n < primes[i]) {
                return vector<int>(primes.begin(), primes.begin() + i);
            }
        }
        return primes;
    }

    int u = n + 32;
    double lu = log(u);
    vector<int> ret((int)(u / lu + u / lu / lu * 1.5));
    ret[0] = 2;
    int pos = 1;

    vector<int> isnp((n + 1) / 32 / 2 + 1);
    int sup = (n + 1) / 32 / 2 + 1;

    vector<int> tprimes = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    for (int tp : tprimes) {
        ret[pos++] = tp;
        vector<int> ptn(tp);
        for (int i = (tp - 3) / 2; i < tp << 5; i += tp)
            ptn[i >> 5] |= 1 << (i & 31);
        for (int j = 0; j < sup; j += tp) {
            for (int i = 0; i < tp && i + j < sup; i++) {
                isnp[j + i] |= ptn[i];
            }
        }
    }

    vector<int> magic = { 0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17,
            9, 6, 16, 5, 15, 14 };
    int h = n / 2;
    for (int i = 0; i < sup; i++) {
        for (int j = ~isnp[i]; j != 0; j &= j - 1) {
            int pp = i << 5 | magic[(j & -j) * 0x076be629 >> 27];
            int p = 2 * pp + 3;
            if (p > n)
                break;
            ret[pos++] = p;
            if ((long) p * p > n)
                continue;
            for (int q = (p * p - 3) / 2; q <= h; q += p)
                isnp[q >> 5] |= 1 << q;
        }
    }

    return vector<int>(ret.begin(), ret.begin() + pos);
}

class MeisselLehmer2 {
    vector<int> primes;
    vector<int> xcums;
    unordered_map<long long, long long> picache;
    unordered_map<long long, long long> phicache;
    bool cachePhi = true;

    int M;
    int B;

    vector<int> FP;
    vector<vector<int>> cumps;

    long long sqrt(long long n) {
        long long i = max(0LL, (long long)sqrt(n) - 2);
        while (i * i <= n)
            i++;
        return i - 1;
    }

    long long cbrt(long long n) {
        long long i = max(0LL, (long long)cbrt(n) - 2);
        while (i * i * i <= n)
            i++;
        return i - 1;
    }

public:
    MeisselLehmer2(long long n) {
        assert(n >= 4);

        picache.clear();
        phicache.clear();

        int s = (int)sqrt(n) * B;

        int cachelimit = s;
        primes = sieveEratosthenes(s);
        xcums.resize((s >> 6) + 1);
        vector<int> isp((s >> 6) + 1);
        for (int p : primes)
            isp[p >> 6] |= 1LL << p;
        for (int i = 0; i < xcums.size() - 1; i++)
            xcums[i + 1] = xcums[i] + __builtin_popcount(isp[i]);

        cumps.resize(M);
        vector<bool> b = { true };
        int len = 1;
        for (int i = 0; i < M; i++) {
            len *= FP[i];
            vector<bool> c(len);
            for (int j = 0; j < FP[i]; j++) {
                copy(b.begin(), b.end(), c.begin() + j * b.size());
            }
            for (int k = 0; k < len; k += FP[i])
                c[k] = false;
            cumps[i].resize(len + 1);
            for (int j = 0; j < len; j++)
                cumps[i][j + 1] = cumps[i][j] + (c[j] ? 1 : 0);
            FP[i] = len;
            b = c;
        }
    }

    long long pi(long long x) {
        if (x <= cachelimit) {
            int ix = (int)x;
            return xcums[ix >> 6] + __builtin_popcountll(isp[ix >> 6] << ~ix);
        }
        if (picache.count(x))
            return picache[x];

        int A = (int)pi(sqrt(sqrt(x)));
        long long ret = A + phi(x, A) - P2(x, A) - P3(x, A) - 1;
        picache[x] = ret;
        return ret;
    }

    long long phi(long long x, int A) {
        if (A > 0 && A - 1 < M) {
            return cumps[A - 1][FP[A - 1]] * (x / FP[A - 1]) + cumps[A - 1][(int)(x % FP[A - 1] + 1)];
        }
        if (A > 0 && x <= (long long)primes[A - 1] * primes[A - 1]) {
            return pi(x) - A + 1;
        }
        long long code = x << 13 | A;
        if (phicache.count(code))
            return phicache[code];

        long long ret = x;
        for (int i = A - 1; i >= 0; i--)
            ret -= phi(x / primes[i], i);

        if (cachePhi)
            phicache[code] = ret;
        return ret;
    }

    long long P2(long long x, int A) {
        int B = (int)pi(sqrt(x));
        long long ret = 0;
        for (int i = A; i < B; i++) {
            ret += pi(x / primes[i]);
        }
        ret -= (long long)(B - A) * (B + A - 1) / 2;
        return ret;
    }

    long long P3(long long x, int A) {
        int C = (int)pi(cbrt(x));
        long long ret = 0;
        for (int i = A; i < C; i++) {
            long long xi = x / primes[i];
            int B = (int)pi(sqrt(xi));
            for (int j = i; j < B; j++) {
                ret += pi(xi / primes[j]) - j;
            }
        }
        return ret;
    }
};

void solve() {
    long long n;
    cin >> n;
    long long ans = 0;
    MeisselLehmer2 ml(n / 2);
    vector<int> primes = sieveEratosthenes(400000);
    for (int i = 0; i < primes.size(); i++) {
        long long plus = ml.pi(n / primes[i]) - (i + 1);
        if (plus <= 0)
            break;
        ans += plus;
    }

    for (int p : primes) {
        if ((long long)p * p * p <= n) {
            ans++;
        } else {
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
