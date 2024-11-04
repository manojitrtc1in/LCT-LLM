#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>







using namespace std;





typedef long long ll;
typedef unsigned int ul;
typedef unsigned long long ull;
typedef vector <ll> vi;
typedef map<int, vector<int> > mvii;
typedef map<int, int> mii;
typedef queue <int> qi;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef vector<pii > vpii;





















#define MP make_pair
#define SORT(a) sort (a.begin(), a.end())
#define REVERSE(a) reverse (a.begin(), a.end())
#define ALL(a) a.begin(), a.end()
#define PI acos(-1)
#define ms(x,y) memset (x, y, sizeof (x))
#define inf 1e9
#define INF 1e16
#define pb push_back
#define MAX 100005
#define debug(a,b) cout<<a<<": "<<b<<endl
#define Debug cout<<"Reached here"<<endl
#define prnt(a) cout<<a<<"\n"
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define FORr(i,a,b) for (int i=(a); i>=(b); i--)
#define itrALL(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define lc ((node)<<1)
#define rc ((node)<<1|1)
#define VecPrnt(v) FOR(J,0,v.size()) cout<<v[J]<<" "; cout<<endl
#define endl "\n"
#define PrintPair(x) cout<<x.first<<" "<<x.second<<endl
#define EPS 1e-9
#define ArrPrint(a,st,en) for(int J=st; J<=en; J++) cout<<a[J]<<" "; cout<<endl;












template <class T> inline T bigmod(T p, T e, T M)
{
	ll ret = 1;
	for (; e > 0; e >>= 1)
	{
		if (e & 1) ret = (ret * p) % M;
		p = (p * p) % M;
	} return (T)ret;
}

template <class T> inline T gcd(T a, T b) {if (b == 0)return a; return gcd(b, a % b);}
template <class T> inline T modinverse(T a, T M) {return bigmod(a, M - 2, M);}
template <class T> inline T lcm(T a, T b) {a = abs(a); b = abs(b); return (a / gcd(a, b)) * b;}
template <class T, class X> inline bool getbit(T a, X i) { T t = 1; return ((a & (t << i)) > 0);}
template <class T, class X> inline T setbit(T a, X i) { T t = 1; return (a | (t << i)); }
template <class T, class X> inline T resetbit(T a, X i) { T t = 1; return (a & (~(t << i)));}

inline ll getnum()
{
	char c = getchar();
	ll num, sign = 1;
	for (; c < '0' || c > '9'; c = getchar())if (c == '-')sign = -1;
	for (num = 0; c >= '0' && c <= '9';)
	{
		c -= '0';
		num = num * 10 + c;
		c = getchar();
	}
	return num * sign;
}

inline ll power(ll a, ll b)
{
	ll multiply = 1;
	FOR(i, 0, b)
	{
		multiply *= a;
	}
	return multiply;
}



const int MAXN=1<<20;
namespace fft {
int len, last = -1, step = 0, rev[MAXN];
long long C[MAXN], D[MAXN], P[MAXN], Q[MAXN];

struct complx {
    long double real, img;

    inline complx() {
        real = img = 0.0;
    }

    inline complx conjugate() {
        return complx(real, -img);
    }

    inline complx(long double x) {
        real = x, img = 0.0;
    }

    inline complx(long double x, long double y) {
        real = x, img = y;
    }

    inline complx operator + (complx other) {
        return complx(real + other.real, img + other.img);
    }

    inline complx operator - (complx other) {
        return complx(real - other.real, img - other.img);
    }

    inline complx operator * (complx other) {
        return complx((real * other.real) - (img * other.img), (real * other.img) + (img * other.real));
    }
} u[MAXN], v[MAXN], f[MAXN], g[MAXN], dp[MAXN], inv[MAXN];



void build(int& a, long long* A, int& b, long long* B) {
    while (a > 1 && A[a - 1] == 0) a--;
    while (b > 1 && B[b - 1] == 0) b--;

    len = 1 << (32 - __builtin_clz(a + b) - (__builtin_popcount(a + b) == 1));
    for (int i = a; i < len; i++) A[i] = 0;
    for (int i = b; i < len; i++) B[i] = 0;

    if (!step++) {
        dp[1] = inv[1] = complx(1);
        for (int i = 1; (1 << i) < MAXN; i++) {
            double theta = (2.0 * acos(0.0)) / (1 << i);
            complx mul = complx(cos(theta), sin(theta));
            complx inv_mul = complx(cos(-theta), sin(-theta));

            int lim = 1 << i;
            for (int j = lim >> 1; j < lim; j++) {
                dp[2 * j] = dp[j], inv[2 * j] = inv[j];
                inv[2 * j + 1] = inv[j] * inv_mul;
                dp[2 * j + 1] = dp[j] * mul;
            }
        }
    }

    if (last != len) {
        last = len;
        int bit = (32 - __builtin_clz(len) - (__builtin_popcount(len) == 1));
        for (int i = 0; i < len; i++) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (bit - 1));
    }
}



void transform(complx *in, complx *out, complx* ar) {
    for (int i = 0; i < len; i++) out[i] = in[rev[i]];
    for (int k = 1; k < len; k <<= 1) {
        for (int i = 0; i < len; i += (k << 1)) {
            for (int j = 0; j < k; j++) {
                complx z = out[i + j + k] * ar[j + k];
                out[i + j + k] = out[i + j] - z;
                out[i + j] = out[i + j] + z;
            }
        }
    }
}



void transform_unrolled(complx *in, complx *out, complx* ar) {
    for (int i = 0; i < len; i++) out[i] = in[rev[i]];
    for (int k = 1; k < len; k <<= 1) {
        for (int i = 0; i < len; i += (k << 1)) {
            complx z, *a = out + i, *b = out + i + k, *c = ar + k;
            if (k == 1) {
                z = (*b) * (*c);
                *b = *a - z, *a = *a + z;
            }

            for (int j = 0; j < k && k > 1; j += 2, a++, b++, c++) {
                z = (*b) * (*c);
                *b = *a - z, *a = *a + z;
                a++, b++, c++;
                z = (*b) * (*c);
                *b = *a - z, *a = *a + z;
            }
        }
    }
}

bool equals(int a, long long* A, int b, long long* B) {
    if (a != b) return false;
    for (a = 0; a < b && A[a] == B[a]; a++) {}
    return (a == b);
}



int square(int a, long long* A) {
    build(a, A, a, A);
    for (int i = 0; i < len; i++) u[i] = complx(A[i], 0);
    transform_unrolled(u, f, dp);
    for (int i = 0; i < len; i++) u[i] = f[i] * f[i];
    transform_unrolled(u, f, inv);
    for (int i = 0; i < len; i++) A[i] = (f[i].real / (long double)len) + 0.5;
    return a + a - 1;
}





int multiply(int a, long long* A, int b, long long* B) {
    if (equals(a, A, b, B)) return square(a, A); 


    build(a, A, b, B);
    for (int i = 0; i < len; i++) u[i] = complx(A[i], B[i]);
    transform_unrolled(u, f, dp);
    for (int i = 0; i < len; i++) {
        int j = (len - 1) & (len - i);
        u[i] = (f[j] * f[j] - f[i].conjugate() * f[i].conjugate()) * complx(0, -0.25 / len);
    }
    transform_unrolled(u, f, dp);
    for (int i = 0; i < len; i++) A[i] = f[i].real + 0.5;
    return a + b - 1;
}



int mod_multiply(int a, long long* A, int b, long long* B, int mod) {
    build(a, A, b, B);
    int flag = equals(a, A, b, B);
    for (int i = 0; i < len; i++) A[i] %= mod, B[i] %= mod;
    for (int i = 0; i < len; i++) u[i] = complx(A[i] & 32767, A[i] >> 15);
    for (int i = 0; i < len; i++) v[i] = complx(B[i] & 32767, B[i] >> 15);

    transform_unrolled(u, f, dp);
    for (int i = 0; i < len; i++) g[i] = f[i];
    if (!flag) transform_unrolled(v, g, dp);

    for (int i = 0; i < len; i++) {
        int j = (len - 1) & (len - i);
        complx c1 = f[j].conjugate(), c2 = g[j].conjugate();

        complx a1 = (f[i] + c1) * complx(0.5, 0);
        complx a2 = (f[i] - c1) * complx(0, -0.5);
        complx b1 = (g[i] + c2) * complx(0.5 / len, 0);
        complx b2 = (g[i] - c2) * complx(0, -0.5 / len);
        v[j] = a1 * b2 + a2 * b1;
        u[j] = a1 * b1 + a2 * b2 * complx(0, 1);
    }
    transform_unrolled(u, f, dp);
    transform_unrolled(v, g, dp);

    long long x, y, z;
    for (int i = 0; i < len; i++) {
        x = f[i].real + 0.5, y = g[i].real + 0.5, z = f[i].img + 0.5;
        A[i] = (x + ((y % mod) << 15) + ((z % mod) << 30)) % mod;
    }
    return a + b - 1;
}



int long_multiply(int a, long long* A, int b, long long* B) {
    int mod1 = 1.5e9;
    int mod2 = mod1 + 1;
    for (int i = 0; i < a; i++) C[i] = A[i];
    for (int i = 0; i < b; i++) D[i] = B[i];

    mod_multiply(a, A, b, B, mod1);
    mod_multiply(a, C, b, D, mod2);
    for (int i = 0; i < len; i++) {
        A[i] = A[i] + (C[i] - A[i] + (long long)mod2) * (long long)mod1 % mod2 * mod1;
    }
    return a + b - 1;
}

int build_convolution(int n, long long* A, long long* B) {
    int i, m, d = 0;
    for (i = 0; i < n; i++) Q[i] = Q[i + n] = B[i];
    for (i = 0; i < n; i++) P[i] = A[i], P[i + n] = 0;
    n *= 2, m = 1 << (32 - __builtin_clz(n) - (__builtin_popcount(n) == 1));
    for (i = n; i < m; i++) P[i] = Q[i] = 0;
    return n;
}





void convolution(int n, long long* A, long long* B) {
    int len = build_convolution(n, A, B);
    multiply(len, P, len, Q);
    for (int i = 0; i < n; i++) A[i] = P[i + n];
}



void mod_convolution(int n, long long* A, long long* B, int mod) {
    int len = build_convolution(n, A, B);
    mod_multiply(len, P, len, Q, mod);
    for (int i = 0; i < n; i++) A[i] = P[i + n];
}



void long_convolution(int n, long long* A, long long* B) {
    int len = build_convolution(n, A, B);
    long_multiply(len, P, len, Q);
    for (int i = 0; i < n; i++) A[i] = P[i + n];
}
}

const int mod=1009;
ll p1[MAXN], p2[MAXN];

vi multiply(vi &a, vi &b)
{
	int sa=a.size(), sb=b.size();
	FOR(i,0,sa) p1[i]=a[i];
	FOR(i,0,sb) p2[i]=b[i];
	int sz=fft::mod_multiply(sa,p1,sb,p2,mod);
	vi ret=vector<ll>(p1,p1+sz);
	return ret;
}

int n, m, x, k, cnt[2 * MAX];

vi go(int l, int r)
{
	vi curr;
	if (l == r)
	{
		FOR(j, 0, cnt[l] + 1)
		curr.pb(1);
		

		return curr;
	}

	int mid = (l + r) / 2;

	vi ls = go(l, mid);
	vi rs = go(mid + 1, r);
	vi ret = multiply(ls, rs);

	return ret;
}

int main()
{
	

	

	


	int test, cases = 1;

	scanf("%d%d%d", &n, &m, &k);

	FOR(i, 1, n + 1)
	{
		scanf("%d", &x);
		cnt[x]++;
	}

	vi out = go(1, m);
	prnt(out[k]);

	return 0;
}





