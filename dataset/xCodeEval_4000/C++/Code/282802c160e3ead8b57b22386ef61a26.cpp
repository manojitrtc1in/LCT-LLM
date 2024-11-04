#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read() {
    int x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

typedef long long LL;
const int MOD = 998244353;
const int G = 3;
int invG = 0;
const int MAXN = 1 << 18;
int rt[MAXN], irt[MAXN];

inline int FST(int base, int times) {
    int ret = 1;
    while (times) {
        if (times & 1) ret = (LL)ret * base % MOD;
        times >>= 1;
        base = (LL)base * base % MOD;
    }
    return ret;
}
inline int pls(const int &x, const int &y) {
    return x + y >= MOD ? x + y - MOD : x + y;
}
inline void swap(int &a, int &b) {
    if (a ^ b) a ^= b, b ^= a, a ^= b;
    return;
}

namespace P {
#define DFT(a, length) NTT(a, length, 1)
#define IDFT(a, length) NTT(a, length, -1)
    int r[MAXN];
    inline void ButterflyChange(int n, int L) {
        for (int i = 0; i < n; ++i)
            r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
        return;
    }
    inline void reset(int *a, int n) {
        for (int *end = a + n; a != end; ++a) *a = 0;
        return;
    }
    inline void copy(int *to, int *from, int n) {
        for (int *end = to + n; to != end; ++to, ++from) *to = *from;
        return;
    }
    inline void NTT(int *a, int n, int type) {
        for (int i = 0; i < n; ++i)
            if (i < r[i]) swap(a[i], a[ r[i] ]);
        for (int mid = 1; mid < n; mid <<= 1) {
            int *root = type == 1 ? &rt[mid] : &irt[mid];
            for (int R = mid << 1, j = 0; j < n; j += R) {
                for (int k = 0; k < mid; ++k) {
                    int x = a[j + k], y = (LL)root[k] * a[j + k + mid] % MOD;
                    a[j + k] = (x + y) % MOD;
                    a[j + k + mid] = (x - y + MOD) % MOD;
                }
            }
        }
        if (type == -1) {
            int inv = FST(n, MOD - 2);
            for (int i = 0; i < n; ++i) a[i] = (LL)a[i] * inv % MOD;
        }
        return;
    }
    inline void Inv(int deg, int *a, int *b) {
        static int tmp[MAXN], stack[32];
        int top = 0;
        while (deg != 1) {
            stack[top++] = deg;
            deg = (deg + 1) >> 1;
        }
        b[0] = FST(a[0], MOD - 2);
        b[1] = 0;
        int length = 1, L = 0;
        while (top) {
            deg = stack[--top];
            while (length < (deg << 1)) length <<= 1, ++L;
            reset(b + ((deg + 1) >> 1), length - ((deg + 1) >> 1));
            copy(tmp, a, deg);
            reset(tmp + deg, length - deg);
            ButterflyChange(length, L);
            DFT(tmp, length);
            DFT(b, length);
            for (int i = 0; i < length; ++i) b[i] = (LL)(2 - (LL)tmp[i] * b[i] % MOD + MOD) * (LL)b[i] % MOD;
            IDFT(b, length);
            reset(b + deg, length - deg);
        }
        return;
    }
    inline void Direv(int *a,int n) {
        for (int i = 1; i <= n; ++i) a[i - 1] = (LL)a[i] * i % MOD;
        a[n] = 0;
        return;
    }
    inline void Inter(int *a, int n) {
        for (int i = n; i >= 1; --i) a[i] = (LL)a[i - 1] * FST(i, MOD - 2) % MOD;
        a[0] = 0;
        return;
    }
    inline void Ln(int deg, int *a, int *b) {
        static int tmp[MAXN];
        int length = 1, L = 0;
        while (length < (deg << 1)) length <<= 1, ++L;
        Inv(deg, a, tmp);
        reset(tmp + deg, length - deg);
        copy(b, a, deg);
        Direv(b, deg);
        ButterflyChange(length, L);
        DFT(tmp, length);
        DFT(b, length);
        for (int i = 0; i < length; ++i) b[i] = (LL)b[i] * tmp[i] % MOD;
        IDFT(b, length);
        Inter(b, deg);
        reset(b + deg, length - deg);
        return;
    }
    
    inline void Exp(int deg, int *a, int *b) {
        static int tmp[MAXN], stack[32];
        int top = 0;
        while (deg != 1) {
            stack[top++] = deg;
            deg = (deg + 1) >> 1;
        }
        b[0] = 1;
        b[1] = 0;
        int length = 1, L = 0;
        while (top) {
            deg = stack[--top];
            while (length < (deg << 1)) length <<= 1, ++L;
            reset(b + ((deg + 1) >> 1), length - ((deg + 1) >> 1));
            Ln(deg, b, tmp);
            for (int i = 0; i < deg; ++i) tmp[i] = pls(a[i], MOD - tmp[i]);
            if (++tmp[0] >= MOD) tmp[0] -= MOD;
            reset(tmp + deg, length - deg);
            ButterflyChange(length, L);
            DFT(tmp, length);
            DFT(b, length);
            for (int i = 0; i < length; ++i) b[i] = (LL)b[i] * tmp[i] % MOD;
            IDFT(b, length);
            reset(b + deg, length - deg);
        }
    }
    inline int Div(int *a, int n, int *b, int m, int *c, int *r) {
        static int tmp1[MAXN], tmp2[MAXN];
        if (n < m) {
            copy(r, a, n);
            return n;
        }
        int length = 1, L = 0, t = n - m + 1;
        while (length < (t << 1)) length <<= 1, ++L;
        for (int i = 0; i < m; ++i) tmp1[m - 1 - i] = b[i];
        Inv(t, tmp1, tmp2);
        for (int i = 0; i < n; ++i) tmp1[n - 1 - i] = a[i];
        reset(tmp1 + t, length - t);
        ButterflyChange(length, L);
        DFT(tmp1, length);
        DFT(tmp2, length);
        for (int i = 0; i < length; ++i) tmp1[i] = (LL)tmp1[i] * tmp2[i] % MOD;
        IDFT(tmp1, length);
        for (int i = 0; i < t; ++i) c[i] = tmp1[t - 1 - i];

        length = 1, L = 0;
        while (length < n) length <<= 1, ++L;
        copy(tmp1, c, t);
        copy(tmp2, b, m);
        reset(tmp1 + t, length - t);
        reset(tmp2 + m, length - m);
        ButterflyChange(length, L);
        DFT(tmp1, length);
        DFT(tmp2, length);
        for (int i = 0; i < length; ++i) tmp1[i] = (LL)tmp1[i] * tmp2[i] % MOD;
        IDFT(tmp1, length);
        for (int i = 0; i < m - 1; ++i) {
            r[i] = a[i] - tmp1[i];
            if (r[i] < 0) r[i] += MOD;
        }
        reset(tmp1, length);
        reset(tmp2, length);
        return m - 1;
    }
    int *poly[MAXN + 7];
    int len[MAXN + 7];
    int cnt;
    void eva_split(int cur, int l, int r, int *x) { 

        static int tmp1[MAXN], tmp2[MAXN];
        if (l == r) {
            len[cur] = 2;
            poly[cur] = new int[2];
            poly[cur][0] = MOD -x[l], poly[cur][1] = 1;
            return;
        }
        int Lid = (cur << 1), Rid = (cur << 1) | 1; 

        eva_split(Lid, l, (l + r) >> 1, x);
        eva_split(Rid, ((l + r) >> 1) + 1, r, x);
        int n = len[Lid] + len[Rid] - 1;
                
        poly[cur] = new int[n];
        len[cur] = n;
        if (r - l > 20) {
            int length = 1, L = 0;
            while (length < n) length <<= 1, ++L;
            copy(tmp1, poly[Lid], len[Lid]);
            reset(tmp1 + len[Lid], length - len[Lid]);
            copy(tmp2, poly[Rid], len[Rid]);
            reset(tmp2 + len[Rid], length - len[Rid]);
            ButterflyChange(length, L);
            DFT(tmp1, length);
            DFT(tmp2, length);
            for (int i = 0; i < length; ++i) tmp1[i] = (LL)tmp1[i] * tmp2[i] % MOD;
            IDFT(tmp1, length);
            copy(poly[cur], tmp1, n);
        }
        else {
            reset(poly[cur], n);
            for (int i = 0; i < len[Lid]; ++i) {
                for (int j = 0; j < len[Rid]; ++j) {
                    poly[cur][i + j] += (LL)poly[Lid][i] * poly[Rid][j] % MOD;
                    if (poly[cur][i + j] >= MOD) poly[cur][i + j] -= MOD;
                }
            }
        }
        return;
    }
    void eva_cal(int l, int r, int cur, int n, int *base, int *val, int *x) {
        static int tmp[MAXN];
        if (l == r) return void(val[l] = base[0]);
        if (r - l <= 100) {
            for (int i = l; i <= r; ++i) {
                int tmp = 0;
                int X = 1;
                for (int j = 0; j < n; ++j) {
                    tmp += (LL)base[j] * X % MOD;
                    if (tmp >= MOD) tmp -= MOD;
                    else if (tmp < 0) tmp += MOD;
                    X = (LL)X * x[i] % MOD;
                }
                val[i] = tmp;
            }
            return;
        }
        int mid = (l + r) >> 1;
        int Lid = (cur << 1), Rid = (cur << 1) | 1;
        int Lsize = len[Lid], Rsize = len[Rid];
        int Llen = Div(base, n, poly[Lid], Lsize, tmp, poly[Lid]);
        int Rlen = Div(base, n, poly[Rid], Rsize, tmp, poly[Rid]);
        eva_cal(l, mid, Lid, Llen, poly[Lid], val, x);
        eva_cal(mid + 1, r, Rid, Rlen, poly[Rid], val, x);
    

    

        return;
    }
    inline void eva_solve(int deg, int *a, int m, int *x, int *val) {
        eva_split(1, 1, m, x);
        eva_cal(1, m, 1, deg, a, val, x);
        return;
    }
    inline void init(int n) {
        int lim = 1;
        while (lim < n) lim <<= 1;
        for (int mid = 1; mid < lim; mid <<= 1) {
            int Xi = FST(G, (MOD - 1) / (mid << 1));
            int iXi = FST(invG, (MOD - 1) / (mid << 1));
            rt[mid] = irt[mid] = 1;
            for (int k = 1; k < mid; ++k) rt[mid + k] = rt[mid + k - 1] * (LL)Xi % MOD, irt[mid + k] = irt[mid + k - 1] * (LL)iXi % MOD;
        }
        return;
    }
    int POW_m1, POW_m2, POW_m3;
    inline void POWread() {
        POW_m1 = POW_m2 = POW_m3 = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9') ch = getchar();
        while (ch >= '0' && ch <= '9') {
            POW_m1 = ((LL)POW_m1 * 10 + ch - '0') % MOD;
            POW_m2 = ((LL)POW_m2 * 10 + ch - '0') % (MOD - 1);
            if ((LL)POW_m3 * 10 + ch - '0' <= MOD) POW_m3 = POW_m3 * 10 + ch - '0';
            ch = getchar();
        }
        return;
    }
    inline void PFST(int deg, int *a, int *b) {
        static int tmp1[MAXN], tmp2[MAXN], tmp3[MAXN];
        int base = 0;
        while (!a[base]) ++base;
        LL xtimes = (LL)base * POW_m3;
        int poly_times = POW_m1, times = POW_m2;
        if (xtimes >= deg) {
            reset(b, deg);
            return;
        }
        reset(b, xtimes);

        int div = FST(a[base], MOD - 2);
        for (int i = 0; i < deg - xtimes; ++i) tmp1[i] = (LL)a[i + base] * div % MOD;
        Ln(deg - xtimes, tmp1, tmp2);
        for (int i = 0; i < deg - xtimes; ++i)
            tmp2[i] = (LL)tmp2[i] * poly_times % MOD;
        Exp(deg - xtimes, tmp2, tmp3);
        if (a[base] != 1) {
            int rdiv = FST(a[base], times);
            for (int i = 0; i < deg - xtimes; ++i)
                tmp3[i] = (LL)tmp3[i] * rdiv % MOD;
        }
        copy(b + xtimes, tmp3, deg - xtimes);
        return;
    }
	inline void Sqrt(int deg, int *a, int *b) {
		static int tmp1[MAXN], tmp2[MAXN], stack[32];
		int top = 0;
		while (deg != 1) {
			stack[top++] = deg;
			deg = (deg + 1) >> 1;
		}
		b[0] = 1, b[1] = 0;
		int length = 1, L = 0;
		while (top) {
			deg = stack[--top];
			while (length < (deg << 1)) length <<= 1, ++L;
			reset(b + ((deg + 1) >> 1), length - ((deg + 1) >> 1));
			Inv(deg, b, tmp1);
			reset(tmp1 + deg, length - deg);
			copy(tmp2, a, deg);
			reset(tmp2 + deg, length - deg);
			ButterflyChange(length, L);
			DFT(tmp1, length);
			DFT(tmp2, length);
			for (int i = 0; i < length; ++i) tmp1[i] = (LL)tmp1[i] * tmp2[i] % MOD;
			IDFT(tmp1, length);
			int inv2 = FST(2, MOD - 2);
			for (int i = 0; i < deg; ++i) b[i] = ((LL)tmp1[i] + b[i]) % MOD * inv2 % MOD;
			reset(b + deg, length - deg);
		}
		return;
	}
}


int g[MAXN], tmp[MAXN], tmp2[MAXN];
int main() {
	invG = FST(G, MOD - 2);
	int n = read();
	int m = read() + 1;
	for (int i = 1; i <= n; ++i) {
		int c = read();
		g[c] = MOD - 4;
	}
	g[0] = 1;
	P::init(m << 1);
	P::Sqrt(m, g, tmp);
	if (++tmp[0] >= MOD) tmp[0] -= MOD;
	P::Inv(m, tmp, tmp2);
	for (int i = 1; i < m; ++i) printf("%d\n", (LL)tmp2[i] * 2 % MOD);
	return 0;
}
