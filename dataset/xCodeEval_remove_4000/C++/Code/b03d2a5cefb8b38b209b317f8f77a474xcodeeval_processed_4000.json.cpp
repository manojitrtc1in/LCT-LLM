



using namespace std;
typedef long long ll;
typedef long long ull;
typedef long double lb;



using LL = long long;
using LB = long double;
const int N = 500 + 10;


ll MOD;
int delta = 2e5;

LL fix( const LL a ) { return ( a % MOD + MOD ) % MOD; }
LL mul( const LL a, const LL b, const LL MOD) { return fix( a * b - ( LL ) ( ( LB ) a / MOD * b ) * MOD ); }

vector<int> rev, roots{0, 1};
int qpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = mul(a, a, MOD))
        if (b & 1)
            res = mul(res, a, MOD);
    return res;
}
void dft(vector<int> &a) {
    

    int n = a.size();
    if ((int)(rev.size()) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; ++i)
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
    }
    for (int i = 0; i < n; ++i)
        if (rev[i] < i)
            swap(a[i], a[rev[i]]);
    if ((int)(roots.size()) < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            int e = qpow(3, (MOD - 1) >> (k + 1));
            for (int i = 1 << (k - 1); i < (1 << k); ++i) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = 1ll * roots[i] * e % MOD;
            }
            ++k;
        }
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; ++j) {
                int u = a[i + j];
                int v = 1ll * a[i + j + k] * roots[k + j] % MOD;
                int x = u + v;
                if (x >= MOD)
                    x -= MOD;
                a[i + j] = x;
                x = u - v;
                if (x < 0)
                    x += MOD;
                a[i + j + k] = x;
            }
        }
    }
}
void idft(vector<int> &a) {
    int n = a.size();
    reverse(a.begin() + 1, a.end()); 

    dft(a);
    int inv = qpow(n, MOD - 2);
    for (int i = 0; i < n; ++i)
        a[i] = 1ll * a[i] * inv % MOD;
}
using poly = vector<int>;















































































































































































































































































































































































namespace FFTComplex {
const double PI = acos(-1.0);
struct C {
    double x, y;
    C(double x = 0, double y = 0) : x(x), y(y) {}
    C operator!() const { return C(x, -y); }
};
inline C operator*(C a, C b) {
    return C(a.x * b.x - a.y * b.y, a.y * b.x + b.y * a.x);
}
inline C operator+(C a, C b) {
    return C(a.x + b.x, a.y + b.y);
}
inline C operator-(C a, C b) {
    return C(a.x - b.x, a.y - b.y);
}
constexpr int L = (1 << 20);
C w[L];
int r[L << 1], _ = []{
    for (int i = 0; i < L / 2; i++) w[i + L / 2] = C(cos(2 * PI * i / L), sin(2 * PI * i / L));
    for (int i = L / 2 - 1; i; i--) w[i] = w[i << 1];
    for (int i = 1; i <= L; i <<= 1) {
        for (int j = 0; j < i; j++) {
            r[i + j] = r[i + j >> 1] | (i >> 1) * (j & 1);
        }
    }
    return 0;
}();
void dft(C *a, int n) {
    for (int k = n >> 1; k; k >>= 1) {
        for (int i = 0; i < n; i += k << 1) {
            for (int j = 0; j < k; j++) {
                C x = a[i + j], y = a[i + j + k];
                a[i + j + k] = (x - y) * w[k + j];
                a[i + j] = x + y;
            }
        }
    }
}
void idft(C *a, int n) {
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += k << 1) {
            for (int j = 0; j < k; j++) {
                C &x = a[i + j], y = a[i + j + k] * w[k + j];
                a[i + j + k] = x - y, x = x + y;
            }
        }
    }
    for (int i = 0; i < n; i++) a[i].x /= n, a[i].y /= n;
    std::reverse(a + 1, a + n);
}
} 

using namespace FFTComplex;





    








































































void id0(int a[], int len, int type)
{
	

    

    

	int i, j, k, x, y;
	for (i = 1; i <= __lg(len); i++) {
        int gap = (1 << i - 1);
		for (j = 0; j < len; j += gap << 1) {
			for (k = 0; k < gap; k++){
                int t1 = a[j | k], t2 = a[j | k | gap];
				a[j | k]       = (1LL * t1 +  t2) % MOD,
				a[j | k | gap] = fix(t1 - t2) % MOD;
			}
        }
    }
    
    if (type == -1) {
		for (int i = 0; i < len; i++) a[i] /= len;
    }
}

namespace CombinatorialMath {
    const int N = 1e6 + 10;
    ll fac[N], ifac[N]; 
    void init(){
        fac[0] = ifac[0] = 1;
        for (int i = 1; i < N; i++) {
            fac[i] = fac[i - 1] * i % MOD;
        }
        ifac[N - 1] = qpow(fac[N - 1], MOD - 2);
        for (int i = N - 2; i >= 1; i--) {
            ifac[i] = ifac[i + 1] * (i + 1) % MOD;
        }
    };
    ll C(ll n, ll k) {
        if (k > n || k < 0) return 0;
        return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
    }
    ll A(ll n, ll k) {
        return fac[n] * ifac[n - k] % MOD;
    }
}
using CombinatorialMath::C;
ll f[2][N * N], sum[2][N * N], g[N];
void add(ll &x, int y) {
    if ( (x += y) >= MOD ) x -= MOD;
}
ll mi[N];
void solve() {
    int n;
    cin >> n >> MOD;

    f[0][0 + delta] = sum[0][0 + delta] = 1;
    for (int i = 1; i <= 10; i++) sum[0][i + delta] = 1;
    for (int i = 1; i <= n; i++) {
        

        int ii = i & 1;
        for (int j = delta - i * (i - 1) / 2; j <= delta + i * (i - 1) / 2; j++) {
            f[ii][j] = f[ii][j-1] + (sum[ii^1][i+j-1] - sum[ii^1][j-1])
                    - (sum[ii^1][j-1] - sum[ii^1][j-i-1]);
            f[ii][j] = ( f[ii][j] % MOD + MOD ) % MOD;

            

            

        }
        for (int j = delta - i * (i - 1) / 2; j <= delta + (i + 2) * (i + 1) / 2; j++) {
            sum[ii][j] = (sum[ii][j-1] + f[ii][j]) % MOD;
        }
        for (int j = 1; j <= i; j++) {
            for (int k = j + 1; k <= i; k++) {
                add(g[i], sum[ii^1][delta - (k - j + 1)]);
            }
        }
    }
    

	vector<ll> A(n + 1);
    A[0] = 1;
    for (int i = 1; i <= n; i++) {
        A[i] = A[i - 1] * (n - i + 1) % MOD;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        add(ans, A[i - 1] * g[n - i + 1] % MOD);
    }
    cout << ans << endl;
}
signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    


    while (t--) solve();

    return 0; 
} 
