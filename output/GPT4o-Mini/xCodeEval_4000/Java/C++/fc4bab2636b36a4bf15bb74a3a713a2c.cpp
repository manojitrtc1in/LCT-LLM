#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int NTTPrimes[] = {1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681};
const int NTTPrimitiveRoots[] = {7, 6, 3, 5, 3, 3, 3, 3, 3, 17};

class G {
public:
    void solve() {
        int n, K;
        cin >> n >> K;
        vector<int> d(K);
        for (int i = 0; i < K; i++) {
            cin >> d[i];
        }
        
        vector<long long> f(20, 0);
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                f[10 + d[i] - d[j]]++;
            }
        }

        n /= 2;
        vector<long long> g(1, 1);
        for (int D = 17; D >= 0; D--) {
            g = clean(convoluteSimply(g, g, mod, 3));
            if (n << ~D < 0) {
                g = clean(mulnaive(g, f));
            }
        }
        cout << (n * 10 < g.size() ? g[n * 10] : 0) << endl;
    }

private:
    vector<long long> clean(vector<long long>& a) {
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] != 0) {
                if (i == a.size() - 1) return a;
                return vector<long long>(a.begin(), a.begin() + i + 1);
            }
        }
        return {};
    }

    static vector<long long> mulnaive(const vector<long long>& a, const vector<long long>& b) {
        vector<long long> c(a.size() + b.size() - 1, 0);
        long long big = 8LL * mod * mod;
        for (size_t i = 0; i < a.size(); i++) {
            for (size_t j = 0; j < b.size(); j++) {
                c[i + j] += a[i] * b[j];
                if (c[i + j] >= big) c[i + j] -= big;
            }
        }
        for (size_t i = 0; i < c.size(); i++) c[i] %= mod;
        return c;
    }

    static vector<long long> convoluteSimply(const vector<long long>& a, const vector<long long>& b, int P, int g) {
        int m = max(2, 1 << (32 - __builtin_clz(max(a.size(), b.size()) - 1) + 2));
        vector<long long> fa = nttmb(a, m, false, P, g);
        vector<long long> fb = (a == b) ? fa : nttmb(b, m, false, P, g);
        for (int i = 0; i < m; i++) {
            fa[i] = fa[i] * fb[i] % P;
        }
        return nttmb(fa, m, true, P, g);
    }

    static vector<long long> nttmb(const vector<long long>& src, int n, bool inverse, int P, int g) {
        vector<long long> dst(src.begin(), src.end());
        dst.resize(n);
        
        int h = __builtin_ctz(n);
        long long K = (1LL << (31 - __builtin_clz(P))) << 1;
        int H = __builtin_ctz(K) * 2;
        long long M = K * K / P;

        vector<int> wws(1 << (h - 1));
        long long dw = inverse ? pow(g, P - 1 - (P - 1) / n, P) : pow(g, (P - 1) / n, P);
        long long w = (1LL << 32) % P;
        for (int k = 0; k < (1 << (h - 1)); k++) {
            wws[k] = (int)w;
            w = modh(w * dw, M, H, P);
        }
        long long J = invl(P, 1LL << 32);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < (1 << i); j++) {
                for (int k = 0, s = j << (h - i), t = s | (1 << (h - i - 1)); k < (1 << (h - i - 1)); k++, s++, t++) {
                    long long u = (dst[s] - dst[t] + 2 * P) * wws[k] % P;
                    dst[s] += dst[t];
                    if (dst[s] >= 2 * P) dst[s] -= 2 * P;

                    long long Q = (u << 32) * J >> 32;
                    dst[t] = (u >> 32) - (Q * P >> 32) + P;
                }
            }
            if (i < h - 1) {
                for (int k = 0; k < (1 << (h - i - 2)); k++) wws[k] = wws[k * 2];
            }
        }
        for (int i = 0; i < n; i++) {
            if (dst[i] >= P) dst[i] -= P;
        }
        for (int i = 0; i < n; i++) {
            int rev = __builtin_bitreverse(i) >> -h;
            if (i < rev) {
                swap(dst[i], dst[rev]);
            }
        }

        if (inverse) {
            long long in = invl(n, P);
            for (int i = 0; i < n; i++) dst[i] = modh(dst[i] * in, M, H, P);
        }

        return dst;
    }

    static long long modh(long long a, long long M, int h, int mod) {
        long long r = a - ((M * (a & ((1LL << 31) - 1)) >> 31) + M * (a >> 31) >> (h - 31)) * mod);
        return r < mod ? r : r - mod;
    }

    static long long pow(long long a, long long n, long long mod) {
        long long ret = 1;
        int x = 63 - __builtin_clz(n);
        for (; x >= 0; x--) {
            ret = ret * ret % mod;
            if (n << (63 - x) < 0) ret = ret * a % mod;
        }
        return ret;
    }

    static long long invl(long long a, long long mod) {
        long long b = mod, p = 1, q = 0;
        while (b > 0) {
            long long c = a / b;
            swap(a, b);
            b = a % b;
            swap(p, q);
            q -= c * q;
        }
        return p < 0 ? p + mod : p;
    }

public:
    void run() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        solve();
    }
};

int main() {
    G g;
    g.run();
    return 0;
}
