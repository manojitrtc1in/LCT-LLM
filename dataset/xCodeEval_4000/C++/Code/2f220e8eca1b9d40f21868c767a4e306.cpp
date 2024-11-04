#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_N = 1000000 + 5;
const int MAX_M = 1 << 16;
const int BS = 30000;
int m, p, Mod, a[MAX_N], n;

namespace Zero{
    const int MAX_M = 10000000  + 5;
    int inv[MAX_M], f[MAX_M];
    
    void solve(const int n, const int m) {
        const int P = Mod;
        inv[1] = 1;
        for (int i = 2; i <= m; i ++) inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
        for (register int i = 1; i < m; i ++)
            f[i + 1] = (((n - 1ll) * m % P * inv[m - i] - n + 2 + P) % P * f[i] - (n - 1ll) * i % P * inv[m - i] % P * (f[i - 1] + 1ll) + 1ll * P * P) % P;
        int ans = P - f[m];
        for (int i = 1; i <= n; i ++)
            if ((ans += f[a[i]]) >= P) ans -= P;
        printf("%d\n", ans);
    }
}

namespace Inverse{
    int inv[MAX_M], invf[MAX_M];
    
    int power(int a, int n, const int P = Mod) {
        int ans = 1;
        while (n) {
            if (n & 1) ans = 1ll * ans * a % P;
            a = 1ll * a * a % P; n >>= 1;
        }
        return ans;
    }
    
    void exgcd(int a, int b, int &x, int &y) {
        if (!b) {x = 1; y = 0; return ;}
        exgcd(b, a % b, y, x); y -= a / b * x;
    }
    
    int getinv(int n, const int P = Mod) {
        int x, y;
        exgcd(n, P, x, y);
        return x < 0 ? x + P : x;
    }
    
    void init_inv(const int P = Mod) {
        inv[1] = 1;
        for (int i = 2; i < MAX_M; i ++) inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
        invf[0] = 1;
        for (int i = 1; i < MAX_M; i ++) invf[i] = 1ll * invf[i - 1] * inv[i] % P;
    }
}
using namespace Inverse;

namespace Linear_recurrence{
    const int Lim = 500000;
    int f[1 << 19];
    
    void recurrence(const int c = p - 1, const int P = Mod) {
        return ;
        f[1] = P - p;
        const int invc = getinv(c);
        for (int i = 1; i < n && i < Lim; i ++)
            f[i + 1] = ((2ll * c * (n - i) + n) % P * f[i] - (1ll * c * (n - i) + n) % P * f[i - 1] + 1ll * P * P) % P * invc % P * getinv(n - i) % P;
    }
}
using namespace Linear_recurrence;

namespace NTT{
    const int S = 31596;
    const int P = 998244353;
    int p1[S + 1], p2[S + 1];
    
    void init_p() {
        for (int i = p1[0] = 1; i <= S; i ++) p1[i] = 3ll * p1[i - 1] % P;
        for (int i = p2[0] = 1; i <= S; i ++) p2[i] = 1ll * p2[i - 1] * p1[S] % P;
    }
    
    void exgcd(int a, int b, int &x, int &y) {
        if (!b) {x = 1; y = 0; return ;}
        exgcd(b, a % b, y, x); y -= a / b * x;
    }
    
    int Inv(const int &n) {
        int x, y;
        exgcd(n, P, x, y);
        return x < 0 ? x + P : x;
    }
    
    int power(const int &n) {
        return 1ll * p1[n % S] * p2[n / S] % P;
    }
    
    int power(int a, int n) {
        int ans = 1;
        while (n) {
            if (n & 1) ans = 1ll * ans * a % P;
            a = 1ll * a * a % P; n >>= 1;
        }
        return ans;
    }
    
    const int* init_w(const int &n) {
        static int *w[MAX_N];
        if (w[n] == NULL) {
            register int *wn = new int[n];
            register int w0 = power((P - 1) / (n << 1));
            wn[0] = 1;
            if (n > 1) {
                const register int *wm = init_w(n >> 1);
                for (int i = 0; i < n; i += 2)
                    wn[i + 1] = 1ll * (wn[i] = wm[i >> 1]) * w0 % P;
            }
            w[n] = wn;
        }
        return w[n];
    }
    
    void ntt(int *a, int n, int ty) {
        for (int i = 0, j = 0; i < n; i ++) {
            if (i < j) swap(a[i], a[j]);
            for (int k = n >> 1; (j ^= k) < k; k >>= 1);
        }
        for (int i = 1; i < n; i <<= 1) {
            const int *w = init_w(i);
            for (int j = 0; j < n; j += i << 1)
                for (int k = j; k < j + i; k ++) {
                    const int t1 = a[k], t2 = 1ll * a[k + i] * w[k - j] % P;
                    a[k] = t1 + t2 < P ? t1 + t2 : t1 + t2 - P;
                    a[k + i] = t1 < t2 ? t1 - t2 + P : t1 - t2;
                }
        }
        if (ty == 1) return ;
        reverse(a + 1, a + n);
        const int inv = Inv(n);
        for (int i = 0; i < n; i ++) a[i] = 1ll * inv * a[i] % P;
    }
    
    void mul(int *a, int *b, int *res, int n, int m, int len) {
        static int c[MAX_N], d[MAX_N];
        for (int i = 0; i < n; i ++) c[i] = a[i];
        for (int i = 0; i < m; i ++) d[i] = b[i];
        ntt(c, len, 1); ntt(d, len, 1);
        for (int i = 0; i < len; i ++) {
            c[i] = 1ll * c[i] * d[i] % P; d[i] = 0;
        }
        ntt(c, len, -1);
        for (int i = 0; i < n + m; i ++) res[i] = c[i];
        for (int i = 0; i < len; i ++) c[i] = 0;
    }
}
using NTT :: init_p;
using NTT :: mul;














































































































































namespace Poly{
    void shifting_evaluation(int *a, int *res, int n, int d) {
        static int len;
        for (len = 1; len < n + n; len <<= 1);
        static int b[MAX_M], c[MAX_M];
        static int num[MAX_M], prod[MAX_M], invprod[MAX_M];
        const int P = Mod, Invforall = power(BS, P - n);
        for (int i = 0; i < n; i ++) {
            b[i] = 1ll * a[i] * Invforall % P * invf[i] % P * invf[n - i - 1] % P;
            if (~ (n - i) & 1) b[i] = P - b[i];
        }
        for (int i = 1; i < (n << 1); i ++) num[i] = (1ll * (i - n) * BS + d + P) % P;
        prod[0] = 1;
        for (int i = 1; i < (n << 1); i ++) prod[i] = 1ll * prod[i - 1] * num[i] % P;
        invprod[n * 2 - 1] = getinv(prod[n * 2 - 1]);
        for (int i = n * 2 - 1; i > 0; i --) invprod[i - 1] = 1ll * invprod[i] * num[i] % P;
        for (int i = 1; i < (n << 1); i ++) c[i] = 1ll * invprod[i] * prod[i - 1] % P;
        mul(b, c, b, n, n << 1, len);
        for (int i = 0; i < n; i ++) res[i] = 1ll * b[i + n] * prod[i + n] % P * invprod[i] % P;
        for (int i = 0; i < len; i ++) b[i] = c[i] = 0;
    }
    
    int P[MAX_N], Q[MAX_N], R[MAX_N];
    int Pd[MAX_N], Qd[MAX_N], Rd[MAX_N];
    int fac;
    void solve(int d) {
        if (d == 1) {
            P[0] = (1ll * p * n - 1) % Mod;
            P[1] = (1ll * p * n - BS - 1) % Mod;
            Q[0] = ((p - 1ll) * n - 1) % Mod;
            Q[1] = ((p - 1ll) * n - BS - 1) % Mod;
            R[0] = P[0]; R[1] = P[1];
            return ;
        }
        const int D = d >> 1; solve(D);
        
        shifting_evaluation(P, Pd, D + 1, (D + 1) * BS);
        for (int i = 0; i < D; i ++) P[i + D + 1] = Pd[i];
        shifting_evaluation(P, Pd, D << 1 | 1, D);
        
        shifting_evaluation(Q, Qd, D + 1, (D + 1) * BS);
        for (int i = 0; i < D; i ++) Q[i + D + 1] = Qd[i];
        shifting_evaluation(Q, Qd, D << 1 | 1, D);
        
        shifting_evaluation(R, Rd, D + 1, (D + 1) * BS);
        for (int i = 0; i < D; i ++) R[i + D + 1] = Rd[i];
        shifting_evaluation(R, Rd, D << 1 | 1, D);
        
        for (int i = 0; i <= (D << 1); i ++) {
            R[i] = (1ll * R[i] * Qd[i] + 1ll * P[i] * Rd[i]) % Mod;
            P[i] = 1ll * P[i] * Pd[i] % Mod; Q[i] = 1ll * Q[i] * Qd[i] % Mod;
        }
        
        if (d & 1) {
            for (int i = 0; i < d; i ++) {
                P[i] = 1ll * P[i] * ((1ll * p * n - i * BS - d + Mod) % Mod) % Mod;
                Q[i] = 1ll * Q[i] * (((p - 1ll) * n - i * BS - d + Mod) % Mod) % Mod;
                R[i] = (1ll * R[i] * (((p - 1ll) * n - i * BS - d + Mod) % Mod) + P[i]) % Mod;
            }
            P[d] = 1; R[d] = 0; Rd[d + 1] = 1;
            for (int i = d; i > 0; i --) Rd[i] = ((p - 1ll) * n - d * BS - i + Mod) % Mod * Rd[i + 1] % Mod;
            for (int i = 1; i <= d; i ++) {
                P[d] = (1ll * p * n - d * BS - i + Mod) % Mod * P[d] % Mod;
                R[d] = (R[d] + 1ll * P[d] * Rd[i + 1]) % Mod;
            }
            Q[d] = Rd[1];
        }
    }
    
    void block_init() {
        solve(BS);
        fac = 1;
        for (int i = 0; i < (n - 1) / BS; i ++) fac = 1ll * fac * Q[i] % Mod;
        for (int i = (n - 1) / BS * BS + 1; i < n; i ++) fac = 1ll * fac * (n - i) % Mod;
        int pre = 1;
        for (int i = 0; i <= BS; i ++) {
            R[i] = 1ll * R[i] * pre % Mod;
            pre = 1ll * pre * P[i] % Mod;
        }
        pre = 1;
        for (int i = 0; i <= BS; i ++) {
            pre = 1ll * pre * Q[i] % Mod;
            R[i] = 1ll * R[i] * fac % Mod * getinv(pre) % Mod;
        }
    }
    
    int query(int x) {


        int sum = fac, facP = 1, facQ = 1;
        for (int i = 0; i < (x - 1) / BS; i ++) {
            if ((sum += R[i]) >= Mod) sum -= Mod;
            facP = 1ll * facP * P[i] % Mod;
            facQ = 1ll * facQ * Q[i] % Mod;
        }
        int l = (x - 1) / BS * BS, r = min(l + BS, x - 1), tmp = 0;
        Rd[r - l + 1] = 1;
        for (int i = r; i > l; i --) Rd[i - l] = 1ll * Rd[i - l + 1] * (n - i) % Mod;
        for (int i = l + 1; i <= r; i ++) {
            facP = (1ll * p * n - i) % Mod * facP % Mod;
            tmp = (tmp + 1ll * facP * Rd[i - l + 1]) % Mod;
            facQ = ((p - 1ll) * n - i) % Mod * facQ % Mod;
        }
        sum = (sum + 1ll * tmp * fac % Mod * getinv(facQ)) % Mod;
        return 1ll * (Mod - p) * sum % Mod;
    }
}
using Poly :: block_init;
using Poly :: query;

int main() {
    init_p();






    scanf("%d", &m); p = 2; Mod = 998244353;
    for (int i = 1; i <= m; i ++) {
        scanf("%d", a + i); n += a[i];
    }
    if (!p) {
        Zero :: solve(m, n);
        return 0;
    }
    init_inv();
    recurrence();
    block_init();
    const int P = Mod;
    int ans = P - query(n);
    for (int i = 1; i <= m; i ++)
        if ((ans += query(a[i])) >= P) ans -= P;
    printf("%lld\n", 1ll * ans * getinv(Poly :: fac) % P);
    return 0;
}