#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 998244353;

long long pow(long long a, long long n, long long mod) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret = (ret * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
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

vector<long long> nttmb(vector<long long>& src, int n, bool inverse, int P, int g) {
    vector<long long> dst(src.begin(), src.begin() + n);

    int h = __builtin_ctz(n);
    long long K = (1LL << 32) % P;
    int H = __builtin_ctzll(K) * 2;
    long long M = K * K / P;

    vector<int> wws(1 << (h - 1));
    long long dw = inverse ? pow(g, P - 1 - (P - 1) / n, P) : pow(g, (P - 1) / n, P);
    long long w = (1LL << 32) % P;
    for (int k = 0; k < (1 << (h - 1)); k++) {
        wws[k] = w;
        w = (w * dw) % P;
    }
    long long J = invl(P, 1LL << 32);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < (1 << i); j++) {
            for (int k = 0, s = j << (h - i), t = s | (1 << (h - i - 1)); k < (1 << (h - i - 1)); k++, s++, t++) {
                long long u = (dst[s] - dst[t] + 2 * P) * wws[k];
                dst[s] += dst[t];
                if (dst[s] >= 2 * P) dst[s] -= 2 * P;

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
        if (dst[i] >= P) dst[i] -= P;
    }
    for (int i = 0; i < n; i++) {
        int rev = __builtin_bitreverse32(i) >> (32 - h);
        if (i < rev) {
            swap(dst[i], dst[rev]);
        }
    }

    if (inverse) {
        long long in = invl(n, P);
        for (int i = 0; i < n; i++) {
            dst[i] = (dst[i] * in) % P;
        }
    }

    return dst;
}

vector<long long> convolute(vector<long long>& a, vector<long long>& b) {
    int USE = 2;
    int m = max(2, (int)max(a.size(), b.size()) - 1);
    vector<vector<long long>> fs(USE);
    for (int k = 0; k < USE; k++) {
        int P = {1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681}[k];
        int g = {7, 6, 3, 5, 3, 3, 3, 3, 3, 17}[k];
        vector<long long> fa = nttmb(a, m, false, P, g);
        vector<long long> fb = (a == b) ? fa : nttmb(b, m, false, P, g);
        for (int i = 0; i < m; i++) {
            fa[i] = (fa[i] * fb[i]) % P;
        }
        fs[k] = nttmb(fa, m, true, P, g);
    }

    vector<int> mods = {1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681};
    vector<long long> gammas = garnerPrepare(mods);
    vector<int> buf(USE);
    for (int i = 0; i < fs[0].size(); i++) {
        for (int j = 0; j < USE; j++) buf[j] = (int)fs[j][i];
        vector<long long> res = garnerBatch(buf, mods, gammas);
        long long ret = 0;
        for (int j = res.size() - 1; j >= 0; j--) ret = (ret * mods[j] + res[j]) % mod;
        fs[0][i] = ret;
    }
    return fs[0];
}

vector<long long> garnerBatch(vector<int>& u, vector<int>& m, vector<long long>& gamma) {
    int n = u.size();
    vector<long long> v(n);
    v[0] = u[0];
    for (int k = 1; k < n; k++) {
        long long temp = v[k - 1];
        for (int j = k - 2; j >= 0; j--) {
            temp = (temp * m[j] + v[j]) % m[k];
        }
        v[k] = (u[k] - temp) * gamma[k] % m[k];
        if (v[k] < 0) v[k] += m[k];
    }
    return v;
}

vector<long long> garnerPrepare(vector<int>& m) {
    int n = m.size();
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

vector<long long> clean(vector<long long>& a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] != 0) {
            if (i == a.size() - 1) return a;
            return vector<long long>(a.begin(), a.begin() + i + 1);
        }
    }
    return vector<long long>();
}

vector<long long> mulnaive(vector<long long>& a, vector<long long>& b) {
    int n = a.size();
    int m = b.size();
    vector<long long> c(n + m - 1);
    long long big = 8LL * mod * mod;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i + j] += a[i] * b[j];
            if (c[i + j] >= big) c[i + j] -= big;
        }
    }
    for (int i = 0; i < c.size(); i++) c[i] %= mod;
    return c;
}

void solve() {
    int n, K;
    cin >> n >> K;
    vector<int> d(K);
    for (int i = 0; i < K; i++) {
        cin >> d[i];
    }

    vector<long long> f(20);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            f[10 + d[i] - d[j]]++;
        }
    }

    n /= 2;
    vector<long long> g = {1};
    for (int D = 17; D >= 0; D--) {
        g = clean(convolute(g, g, 3));
        if (n << ~D < 0) {
            g = clean(mulnaive(g, f));
        }
    }
    cout << (n * 10 < g.size() ? g[n * 10] : 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
