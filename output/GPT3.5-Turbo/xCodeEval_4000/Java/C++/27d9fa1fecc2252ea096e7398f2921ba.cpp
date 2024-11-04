#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const vector<int> NTTPrimes = {1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681};
const vector<int> NTTPrimitiveRoots = {7, 6, 3, 5, 3, 3, 3, 3, 3, 17};

vector<long long> convoluteSimply(vector<long long>& a, vector<long long>& b, int P, int g) {
    int m = max(2, int(pow(2, ceil(log2(max(a.size(), b.size()) - 1))) + 1));
    vector<long long> fa = nttmb(a, m, false, P, g);
    vector<long long> fb = (a == b) ? fa : nttmb(b, m, false, P, g);
    for (int i = 0; i < m; i++) {
        fa[i] = (fa[i] * fb[i]) % P;
    }
    return nttmb(fa, m, true, P, g);
}

vector<long long> convolute(vector<long long>& a, vector<long long>& b) {
    int USE = 2;
    int m = max(2, int(pow(2, ceil(log2(max(a.size(), b.size()) - 1))) + 1));
    vector<vector<long long>> fs(USE);
    for (int k = 0; k < USE; k++) {
        int P = NTTPrimes[k], g = NTTPrimitiveRoots[k];
        vector<long long> fa = nttmb(a, m, false, P, g);
        vector<long long> fb = (a == b) ? fa : nttmb(b, m, false, P, g);
        for (int i = 0; i < m; i++) {
            fa[i] = (fa[i] * fb[i]) % P;
        }
        fs[k] = nttmb(fa, m, true, P, g);
    }

    vector<int> mods(NTTPrimes.begin(), NTTPrimes.begin() + USE);
    vector<long long> gammas = garnerPrepare(mods);
    vector<int> buf(USE);
    for (int i = 0; i < fs[0].size(); i++) {
        for (int j = 0; j < USE; j++) {
            buf[j] = fs[j][i];
        }
        vector<long long> res = garnerBatch(buf, mods, gammas);
        long long ret = 0;
        for (int j = res.size() - 1; j >= 0; j--) {
            ret = (ret * mods[j] + res[j]) % mods[j];
        }
        fs[0][i] = ret;
    }
    return fs[0];
}

vector<long long> convolute1(vector<long long>& a, vector<long long>& b) {
    int m = max(2, int(pow(2, ceil(log2(max(a.size(), b.size()) - 1))) + 1));
    int P = NTTPrimes[0], g = NTTPrimitiveRoots[0];
    vector<long long> fa = nttmb(a, m, false, P, g);
    vector<long long> fb = (a == b) ? fa : nttmb(b, m, false, P, g);
    for (int i = 0; i < m; i++) {
        fa[i] = (fa[i] * fb[i]) % P;
    }
    return nttmb(fa, m, true, P, g);
}

vector<long long> multiply(vector<long long>& a, vector<long long>& b, int mod) {
    long long v = mod;
    v *= mod;
    vector<long long> ans(a.size() + b.size() - 1);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            ans[i + j] += a[i] * b[j];
            if (ans[i + j] >= v) {
                ans[i + j] -= v;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        ans[i] %= mod;
    }
    return ans;
}

vector<long long> convolute(vector<long long>& a, vector<long long>& b, int USE, int mod) {
    if (a.size() + b.size() <= 200) {
        return multiply(a, b, mod);
    }
    int m = max(2, int(pow(2, ceil(log2(max(a.size(), b.size()) - 1))) + 1));
    vector<vector<long long>> fs(USE);
    for (int k = 0; k < USE; k++) {
        int P = NTTPrimes[k], g = NTTPrimitiveRoots[k];
        vector<long long> fa = nttmb(a, m, false, P, g);
        vector<long long> fb = (a == b) ? fa : nttmb(b, m, false, P, g);
        for (int i = 0; i < m; i++) {
            fa[i] = (fa[i] * fb[i]) % P;
        }
        fs[k] = nttmb(fa, m, true, P, g);
    }

    vector<int> mods(NTTPrimes.begin(), NTTPrimes.begin() + USE);
    vector<long long> gammas = garnerPrepare(mods);
    vector<int> buf(USE);
    for (int i = 0; i < fs[0].size(); i++) {
        for (int j = 0; j < USE; j++) {
            buf[j] = fs[j][i];
        }
        vector<long long> res = garnerBatch(buf, mods, gammas);
        long long ret = 0;
        for (int j = res.size() - 1; j >= 0; j--) {
            ret = (ret * mods[j] + res[j]) % mod;
        }
        fs[0][i] = ret;
    }
    return fs[0];
}

vector<long long> nttmb(vector<long long>& src, int n, bool inverse, int P, int g) {
    vector<long long> dst(src.begin(), src.begin() + n);

    int h = __builtin_ctz(n);
    long long K = (1LL << (32 - __builtin_clz(P))) << 1;
    int H = __builtin_ctzll(K) * 2;
    long long M = K * K / P;

    vector<int> wws(1 << (h - 1));
    long long dw = inverse ? pow(g, P - 1 - (P - 1) / n, P) : pow(g, (P - 1) / n, P);
    long long w = (1LL << 32) % P;
    for (int k = 0; k < (1 << (h - 1)); k++) {
        wws[k] = w;
        w = modh(w * dw, M, H, P);
    }
    long long J = invl(P, 1LL << 32);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < (1 << i); j++) {
            for (int k = 0, s = j << (h - i), t = s | (1 << (h - i - 1)); k < (1 << (h - i - 1)); k++, s++, t++) {
                long long u = (dst[s] - dst[t] + 2 * P) * wws[k];
                dst[s] += dst[t];
                if (dst[s] >= 2 * P) {
                    dst[s] -= 2 * P;
                }

                long long Q = (u << 32) * J >> 32;
                dst[t] = (u >> 32) - (Q * P >> 32) + P;
            }
        }
        if (i < h - 1) {
            for (int k = 0; k < (1 << (h - i - 2)); k++) {
                wws[k] = wws[k * 2];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dst[i] >= P) {
            dst[i] -= P;
        }
    }
    for (int i = 0; i < n; i++) {
        int rev = __builtin_bitreverse(i) >> (32 - h);
        if (i < rev) {
            long long d = dst[i];
            dst[i] = dst[rev];
            dst[rev] = d;
        }
    }

    if (inverse) {
        long long in = invl(n, P);
        for (int i = 0; i < n; i++) {
            dst[i] = modh(dst[i] * in, M, H, P);
        }
    }

    return dst;
}

vector<long long> nttsb(vector<long long>& src, int n, bool inverse, int P, int g) {
    vector<long long> dst(src.begin(), src.begin() + n);

    int h = __builtin_ctz(n);
    long long K = (1LL << (32 - __builtin_clz(P))) << 1;
    int H = __builtin_ctzll(K) * 2;
    long long M = K * K / P;

    long long dw = inverse ? pow(g, P - 1 - (P - 1) / n, P) : pow(g, (P - 1) / n, P);
    vector<long long> wws(1 << (h - 1));
    vector<long long> ws(1 << (h - 1));
    long long w = 1;
    for (int k = 0; k < (1 << (h - 1)); k++) {
        wws[k] = (w << 32) / P;
        ws[k] = w;
        w = modh(w * dw, M, H, P);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < (1 << i); j++) {
            for (int k = 0, s = j << (h - i), t = s | (1 << (h - i - 1)); k < (1 << (h - i - 1)); k++, s++, t++) {
                long long ndsts = dst[s] + dst[t];
                if (ndsts >= 2 * P) {
                    ndsts -= 2 * P;
                }
                long long T = dst[s] - dst[t] + 2 * P;
                long long Q = wws[k] * T >> 32;
                dst[s] = ndsts;
                dst[t] = ws[k] * T - Q * P & ((1LL << 32) - 1);
            }
        }

        if (i < h - 1) {
            for (int k = 0; k < (1 << (h - i - 2)); k++) {
                wws[k] = wws[k * 2];
                ws[k] = ws[k * 2];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dst[i] >= P) {
            dst[i] -= P;
        }
    }
    for (int i = 0; i < n; i++) {
        int rev = __builtin_bitreverse(i) >> (32 - h);
        if (i < rev) {
            long long d = dst[i];
            dst[i] = dst[rev];
            dst[rev] = d;
        }
    }

    if (inverse) {
        long long in = invl(n, P);
        for (int i = 0; i < n; i++) {
            dst[i] = modh(dst[i] * in, M, H, P);
        }
    }

    return dst;
}

vector<long long> garnerPrepare(vector<int>& m) {
    int n = m.size();
    assert(n == m.size());
    if (n == 0) {
        return vector<long long>();
    }
    vector<long long> gamma(n);
    for (int k = 1; k < n; k++) {
        long long prod = 1;
        for (int i = 0; i < k; i++) {
            prod = (prod * m[i]) % m[k];
        }
        gamma[k] = invl(prod, m[k]);
    }
    return gamma;
}

vector<long long> garnerBatch(vector<int>& u, vector<int>& m, vector<long long>& gamma) {
    int n = u.size();
    assert(n == m.size());
    vector<long long> v(n);
    v[0] = u[0];
    for (int k = 1; k < n; k++) {
        long long temp = v[k - 1];
        for (int j = k - 2; j >= 0; j--) {
            temp = (temp * m[j] + v[j]) % m[k];
        }
        v[k] = (u[k] - temp) * gamma[k] % m[k];
        if (v[k] < 0) {
            v[k] += m[k];
        }
    }
    return v;
}

long long pow(long long a, long long n, long long mod) {
    long long ret = 1;
    int x = 63 - __builtin_clzll(n);
    for (; x >= 0; x--) {
        ret = (ret * ret) % mod;
        if ((n << (63 - x)) < 0) {
            ret = (ret * a) % mod;
        }
    }
    return ret;
}

long long invl(long long a, long long mod) {
    long long b = mod;
    long long p = 1, q = 0;
    while (b > 0) {
        long long c = a / b;
        long long d;
        d = a;
        a = b;
        b = d % b;
        d = p;
        p = q;
        q = d - c * q;
    }
    return p < 0 ? p + mod : p;
}

long long modh(long long a, long long M, int h, int mod) {
    long long r = a - ((M * (a & ((1LL << 31) - 1)) >> 31) + M * (a >> 31) >> (h - 31)) * mod;
    return r < mod ? r : r - mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> b(10);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[x] = 1;
    }
    int mod = 998244353;
    vector<long long> ans(1, 1);
    while (n > 0) {
        if (n & 1) {
            ans = convoluteSimply(ans, b, mod, 3);
            int sz = ans.size() - 1;
            while (sz > 0 && ans[sz] == 0) {
                sz--;
            }
            if (ans.size() - sz > 100) {
                ans.resize(sz + 1);
            }
        }
        n >>= 1;
        b = convoluteSimply(b, b, mod, 3);
        int sz = b.size() - 1;
        while (sz > 0 && b[sz] == 0) {
            sz--;
        }
        if (b.size() - sz > 100) {
            b.resize(sz + 1);
        }
    }
    long long res = 0;
    for (int i = 0; i < ans.size(); i++) {
        res += (ans[i] * ans[i]);
        res %= mod;
    }
    cout << res << endl;

    return 0;
}
