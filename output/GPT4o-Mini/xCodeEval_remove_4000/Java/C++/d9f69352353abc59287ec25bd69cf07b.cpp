#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>

using namespace std;

class id4 {
public:
    long* keys;
    long* allocated;
    int scale = 1 << 2;
    int rscale = 1 << 1;
    int mask = scale - 1;
    int size = 0;
    static const long NG = 0;

    id4() {
        allocated = new long[scale];
        fill(allocated, allocated + scale, NG);
        keys = new long[scale];
    }

    bool containsKey(long x) {
        int pos = h(x) & mask;
        while (allocated[pos] != NG) {
            if (x == keys[pos]) return true;
            pos = (pos + 1) & mask;
        }
        return false;
    }

    long get(long x) {
        int pos = h(x) & mask;
        while (allocated[pos] != NG) {
            if (x == keys[pos]) return allocated[pos];
            pos = (pos + 1) & mask;
        }
        return NG;
    }

    long put(long x, long v) {
        int pos = h(x) & mask;
        while (allocated[pos] != NG) {
            if (x == keys[pos]) {
                long oldval = allocated[pos];
                allocated[pos] = v;
                return oldval;
            }
            pos = (pos + 1) & mask;
        }
        if (size == rscale) {
            id5(x, v);
        } else {
            keys[pos] = x;
            allocated[pos] = v;
        }
        size++;
        return 0;
    }

    void id5(long x, long v) {
        int nscale = scale << 1;
        int nrscale = rscale << 1;
        int nmask = nscale - 1;
        long* nallocated = new long[nscale];
        fill(nallocated, nallocated + nscale, NG);
        long* nkeys = new long[nscale];
        for (int i = next(0); i < scale; i = next(i + 1)) {
            long y = keys[i];
            int pos = h(y) & nmask;
            while (nallocated[pos] != NG) pos = (pos + 1) & nmask;
            nkeys[pos] = y;
            nallocated[pos] = allocated[i];
        }
        {
            int pos = h(x) & nmask;
            while (nallocated[pos] != NG) pos = (pos + 1) & nmask;
            nkeys[pos] = x;
            nallocated[pos] = v;
        }
        allocated = nallocated;
        keys = nkeys;
        scale = nscale;
        rscale = nrscale;
        mask = nmask;
    }

    int next(int itr) {
        while (itr < scale && allocated[itr] == NG) itr++;
        return itr;
    }

    int h(long x) {
        x ^= x >> 33;
        x *= 0xff51afd7ed558ccdL;
        x ^= x >> 33;
        x *= 0xc4ceb9fe1a85ec53L;
        x ^= x >> 33;
        return (int)x;
    }
};

class id7 {
public:
    vector<int> primes;
    vector<int> xcums;
    vector<long> isp;
    int cachelimit;
    id4 picache;
    id4 id1;
    bool cachePhi = false;
    vector<vector<int>> cumps;
    int FP[8] = {2, 3, 5, 7, 11, 13, 17, 19};
    int M = 8;
    int B = 100;

    id7(long n) {
        assert(n >= 4);
        picache = id4();
        id1 = id4();
        int s = (int)sqrt(n) * B;
        cachelimit = s;
        primes = id0(s);
        xcums.resize((s >> 6) + 1);
        isp.resize((s >> 6) + 1);
        for (int p : primes) isp[p >> 6] |= 1L << p;
        for (int i = 0; i < xcums.size() - 1; i++) xcums[i + 1] = xcums[i] + __builtin_popcountll(isp[i]);
        cumps.resize(M);
        vector<bool> b = {true};
        int len = 1;
        for (int i = 0; i < M; i++) {
            len *= FP[i];
            vector<bool> c(len);
            for (int j = 0; j < FP[i]; j++) {
                copy(b.begin(), b.end(), c.begin() + j * b.size());
            }
            for (int k = 0; k < len; k += FP[i]) c[k] = false;
            cumps[i].resize(len + 1);
            for (int j = 0; j < len; j++) cumps[i][j + 1] = cumps[i][j] + (c[j] ? 1 : 0);
            FP[i] = len;
            b = c;
        }
    }

    long pi(long x) {
        if (x <= cachelimit) {
            int ix = (int)x;
            return xcums[ix >> 6] + __builtin_popcountll(isp[ix >> 6] << ~ix);
        }
        if (picache.containsKey(x)) return picache.get(x);
        int A = (int)pi(sqrt(sqrt(x)));
        long ret = A + phi(x, A) - P2(x, A) - P3(x, A) - 1;
        picache.put(x, ret);
        return ret;
    }

    long phi(long x, int A) {
        if (A > 0 && A - 1 < M) {
            return cumps[A - 1][FP[A - 1]] * (x / FP[A - 1]) + cumps[A - 1][(int)(x % FP[A - 1] + 1)];
        }
        if (A > 0 && x <= (long)primes[A - 1] * primes[A - 1]) {
            return pi(x) - A + 1;
        }
        long code = x << 13 | A;
        if (id1.containsKey(code)) return id1.get(code);
        long ret = x;
        for (int i = A - 1; i >= 0; i--) ret -= phi(x / primes[i], i);
        if (cachePhi) id1.put(code, ret);
        return ret;
    }

    long P2(long x, int A) {
        int B = (int)pi(sqrt(x));
        long ret = 0;
        for (int i = A; i < B; i++) {
            ret += pi(x / primes[i]);
        }
        ret -= (long)(B - A) * (B + A - 1) / 2;
        return ret;
    }

    long P3(long x, int A) {
        int C = (int)pi(id6(x));
        long ret = 0;
        for (int i = A; i < C; i++) {
            long xi = x / primes[i];
            int B = (int)pi(sqrt(xi));
            for (int j = i; j < B; j++) {
                ret += pi(xi / primes[j]) - j;
            }
        }
        return ret;
    }

    static vector<int> id0(int n) {
        if (n <= 32) {
            vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
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

        int id3[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        for (int tp : id3) {
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

        int magic[] = {0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14};
        int h = n / 2;
        for (int i = 0; i < sup; i++) {
            for (int j = ~isnp[i]; j != 0; j &= j - 1) {
                int pp = i << 5 | magic[(j & -j) * 0x076be629 >> 27];
                int p = 2 * pp + 3;
                if (p > n) break;
                ret[pos++] = p;
                if ((long)p * p > n) continue;
                for (int q = (p * p - 3) / 2; q <= h; q += p)
                    isnp[q >> 5] |= 1 << q;
            }
        }

        return vector<int>(ret.begin(), ret.begin() + pos);
    }
};

class F3 {
public:
    vector<int> primes = id7::id0(400000);
    
    void solve() {
        long n;
        cin >> n;
        long ans = 0;
        id7 ml(n / 2);
        for (int i = 0; i < primes.size(); i++) {
            long plus = ml.pi(n / primes[i]) - (i + 1);
            if (plus <= 0) break;
            ans += plus;
        }

        for (int p : primes) {
            if ((long)p * p * p <= n) {
                ans++;
            } else {
                break;
            }
        }
        cout << ans << endl;
    }

    void run() {
        long s = clock();
        solve();
        cout << (clock() - s) / (double)CLOCKS_PER_SEC << "ms" << endl;
    }
};

int main() {
    F3().run();
    return 0;
}
