

















































typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace __gnu_pbds; 

using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef vector<ll> VLL;
typedef vector<int> VI;
const ll mod = 1e9 + 7;


string to_string (string s) { return '"' + s + '"'; }

string to_string (const char *s) { return to_string ((string) s); }

string to_string (bool b) { return (b ? "true" : "false"); }

template<typename A, typename B>
string to_string (pair<A, B> p) { return "(" + to_string (p.first) + ", " + to_string (p.second) + ")"; }

template<typename A>
string to_string (A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) { res += ", "; }
        first = false;
        res += to_string (x);
    }
    res += "}";
    return res;
}

void debug_out () { cerr<<endl; }

template<typename Head, typename... Tail>
void debug_out (Head H, Tail... T) {
    cerr<<" "<<to_string (H);
    debug_out (T...);
}







template<typename T, typename S>
inline bool upmin (T &a, const S &b) { return a > b ? a = b, 1 : 0; }

template<typename T, typename S>
inline bool upmax (T &a, const S &b) { return a < b ? a = b, 1 : 0; }


ull twop (ll x) { return 1ULL<<x; }

ll MOD (ll a, ll m) {
    a %= m;
    if (a < 0)a += m;
    return a;
}

ll inverse (ll a, ll m) {
    a = MOD (a, m);
    if (a <= 1)return a;
    return MOD ((1 - inverse (m, a) * m) / a, m);
}

template<typename T>
T sqr (T x) { return x * x; }

ll gcd (ll a, ll b) {
    a = abs (a), b = abs (b);
    while (b != 0) {
        a %= b;
        swap (a, b);
    }
    return a;
}

ll fast (ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1)ans *= a;
        a *= a;
        b /= 2;
    }
    return ans;
}

ll fast (ll a, ll b, ll mod) {
    if (b < 0)a = inverse (a, mod), b = -b;
    ll ans = 1;
    while (b) {
        if (b & 1)ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans % mod;
}

namespace fft {
    const int N = 1<<20, M = 31768;
    
    struct Complex {
        double x, y;
        
        Complex () { x = y = 0; }
        
        Complex (double _x, double _y) { x = _x, y = _y; }
        
        Complex operator+ (const Complex &r) const {
            return Complex (x + r.x, y + r.y);
        }
        
        Complex operator- (const Complex &r) const {
            return Complex (x - r.x, y - r.y);
        }
        
        Complex operator* (const double k) const {
            return Complex (x * k, y * k);
        }
        
        Complex operator/ (const double k) const {
            return Complex (x / k, y / k);
        }
        
        Complex operator* (const Complex &r) const {
            return Complex (x * r.x - y * r.y, x * r.y + y * r.x);
        }
        
        int operator= (const int a) {
            *this = Complex (a, 0);
            return a;
        }
        
        Complex conj () const {
            return Complex (x, -y);
        }
    };
    
    const double pi = acos (-1.0);
    Complex w[N];
    int rev[N];
    
    void init (int L) {
        int n = 1<<L;
        for (int i = 0; i < n; ++i) {
            double ang = 2 * pi * i / n;
            w[i] = Complex (cos (ang), sin (ang));
            rev[i] = (rev[i>>1]>>1) | ((i & 1)<<(L - 1));
        }
    }
    
    void trans (Complex P[], int n, int oper) {
        for (int i = 0; i < n; i++) {
            if (i < rev[i]) {
                std::swap (P[i], P[rev[i]]);
            }
        }
        for (int d = 0; (1<<d) < n; d++) {
            int m = 1<<d, m2 = m * 2, rm = n / m2;
            for (int i = 0; i < n; i += m2) {
                for (int j = 0; j < m; j++) {
                    Complex &P1 = P[i + j + m], &P2 = P[i + j];
                    Complex t = w[rm * j] * P1;
                    P1 = P2 - t;
                    P2 = P2 + t;
                }
            }
        }
        if (oper == -1) {
            for (int i = 0; i < n; ++i) {
                P[i] = P[i] / n;
            }
        }
    }
    
    Complex A[N], B[N], C1[N], C2[N];
    
    std::vector<ll> conv (const std::vector<int> &a, const std::vector<int> &b) {
        int n = a.size (), m = b.size (), L = 0, s = 1;
        while (s <= n + m - 2) s <<= 1, ++L;
        init (L);
        for (int i = 0; i < s; ++i) {
            A[i] = i < n ? Complex (a[i], 0) : Complex ();
            B[i] = i < m ? Complex (b[i], 0) : Complex ();
        }
        trans (A, s, 1);
        trans (B, s, 1);
        for (int i = 0; i < s; ++i) {
            A[i] = A[i] * B[i];
        }
        for (int i = 0; i < s; ++i) {
            w[i] = w[i].conj ();
        }
        trans (A, s, -1);
        std::vector<ll> res (n + m - 1);
        for (int i = 0; i < n + m - 1; ++i) {
            res[i] = (ll) (A[i].x + 0.5);
        }
        return res;
    }
    
    std::vector<ll> fast_conv (const std::vector<int> &a, const std::vector<int> &b) {
        int n = a.size (), m = b.size (), L = 0, s = 1;
        for (; s <= n + m - 2; s <<= 1, ++L);
        s >>= 1, --L;
        init (L);
        for (int i = 0; i < s; ++i) {
            A[i].x = (i<<1) < n ? a[i<<1] : 0;
            B[i].x = (i<<1) < m ? b[i<<1] : 0;
            A[i].y = (i<<1 | 1) < n ? a[i<<1 | 1] : 0;
            B[i].y = (i<<1 | 1) < m ? b[i<<1 | 1] : 0;
        }
        trans (A, s, 1);
        trans (B, s, 1);
        for (int i = 0; i < s; ++i) {
            int j = (s - i) & (s - 1);
            C1[i] = (Complex (4, 0) * (A[j] * B[j]).conj () -
                     (A[j].conj () - A[i]) * (B[j].conj () - B[i]) * (w[i] + Complex (1, 0))) * Complex (0, 0.25);
        }
        std::reverse (w + 1, w + s);
        trans (C1, s, -1);
        std::vector<ll> res (n + m);
        for (int i = 0; i <= (n + m - 1) / 2; ++i) {
            res[i<<1] = ll (C1[i].y + 0.5);
            res[i<<1 | 1] = ll (C1[i].x + 0.5);
        }
        res.resize (n + m - 1);
        return res;
    }
    
    

    void conv (int a[], int b[], int n, int m, int mod, int res[]) {
        int s = 1, L = 0;
        while (s <= n + m - 2) s <<= 1, ++L;
        init (L);
        for (int i = 0; i < s; ++i) {
            A[i] = i < n ? Complex (a[i] / M, a[i] % M) : Complex ();
            B[i] = i < m ? Complex (b[i] / M, b[i] % M) : Complex ();
        }
        trans (A, s, 1);
        trans (B, s, 1);
        for (int i = 0; i < s; ++i) {
            int j = i ? s - i : i;
            Complex a1 = (A[i] + A[j].conj ()) * Complex (0.5, 0);
            Complex a2 = (A[i] - A[j].conj ()) * Complex (0, -0.5);
            Complex b1 = (B[i] + B[j].conj ()) * Complex (0.5, 0);
            Complex b2 = (B[i] - B[j].conj ()) * Complex (0, -0.5);
            Complex c11 = a1 * b1, c12 = a1 * b2;
            Complex c21 = a2 * b1, c22 = a2 * b2;
            C1[j] = c11 + c12 * Complex (0, 1);
            C2[j] = c21 + c22 * Complex (0, 1);
        }
        trans (C1, s, -1);
        trans (C2, s, -1);
        for (int i = 0; i < n + m - 1; ++i) {
            int x = ll (C1[i].x + 0.5) % mod;
            int y1 = ll (C1[i].y + 0.5) % mod;
            int y2 = ll (C2[i].x + 0.5) % mod;
            int z = ll (C2[i].y + 0.5) % mod;
            res[i] = ((ll) x * M * M + (ll) (y1 + y2) * M + z) % mod;
        }
    }
}
using fft::N;






namespace Poly {
    int tmp1[N], tmp2[N], tmp3[N], mod = 998244353;
    int iv[N];
    
    void init () {
        iv[1] = 1;
        for (int i = 2; i < N; ++i) {
            iv[i] = (mod - (ll) mod / i * iv[mod % i] % mod);
        }
    }
    
    

    void inv (int poly[], int res[], int n) {
        int deg = n - 1;
        std::vector<int> degs;
        while (deg > 0) {
            degs.push_back (deg);
            deg >>= 1;
        }
        std::reverse (degs.begin (), degs.end ());
        res[0] = inverse (poly[0], mod);
        deg = 1;
        for (int t: degs) {
            fft::conv (poly, res, t + 1, deg, mod, tmp1);
            fft::conv (res, tmp1 + deg, t + 1 - deg, t + 1 - deg, mod, tmp1);
            for (int i = 0; i < t + 1 - deg; ++i) {
                res[i + deg] = mod - tmp1[i];
            }
            deg = t + 1;
        }
    }
    
    

    void log (int poly[], int res[], int n) {
        assert(poly[0] == 1);
        inv (poly, tmp2, n);
        for (int i = 0; i < n - 1; ++i) {
            res[i] = (ll) poly[i + 1] * (i + 1) % mod;
        }
        fft::conv (res, tmp2, n - 1, n, mod, res);
        for (int i = n - 1; i >= 1; --i) {
            res[i] = (ll) res[i - 1] * iv[i] % mod;
        }
        res[0] = 0;
    }
    
    

    void exp (int poly[], int res[], int n) {
        assert(poly[0] == 0);
        while (n & n - 1)n += lowbit(n);
        if (n == 1) {
            res[0] = 1;
            return;
        }
        exp (poly, res, n>>1);
        log (res, tmp3, n);
        for (int i = 0; i < n; ++i) {
            tmp3[i] = poly[i] - tmp3[i];
            if (tmp3[i] < 0) tmp3[i] += mod;
        }
        if (++tmp3[0] == mod) tmp3[0] = 0;
        fft::conv (tmp3, res, n, n, mod, res);
        memset (res + n, 0, sizeof (*res) * n);
    }
    
    

    void sqrt (int poly[], int res[], int n) {
        assert(poly[0] == 1);
        while (n & (n - 1)) n += n & (-n);
        if (n == 1) {
            res[0] = 1;
            return;
        }
        sqrt (poly, res, n>>1);
        fill (tmp2 + n / 2, tmp2 + n, 0);
        fill (res + n / 2, res + n, 0);
        inv (res, tmp2, n);
        
        fft::conv (poly, tmp2, n, n, mod, tmp1);
        for (int i = 0; i < n; i++) {
            res[i] = (ll) iv[2] * ((res[i] + tmp1[i]) % mod) % mod;
        }
    }
}

namespace SOLVE {
    const int N = 1000100;
    
    int c[N], y[N], root[N], inv[N], tmp[N];
    int n, m;
    const ll mod = 998244353;
    
    void main () {
        Poly::init ();
        cin>>n>>m;
        REP(i, 0, n) {
            int c;
            cin>>c;
            y[c]++;
        }
        m++;
        REP(i, 0, m)tmp[i] = -4 * y[i];
        tmp[0]++;
        REP(i, 0, m)tmp[i] = MOD (tmp[i], mod);
        Poly::sqrt (tmp, root, m);
        root[0]++;
        REP(i, 0, m)tmp[i] = root[i];
        Poly::inv (tmp, inv, m);
        REP(i, 1, m) {
            cout<<inv[i]*2%mod<<"\n";
        }
    }
}


signed main () {

    fr("/Users/zhangqingchuan/Desktop/cp/cp/input.txt");
    fw("/Users/zhangqingchuan/Desktop/cp/cp/output.txt");

    
    
    int t = 1;


    for (int i = 1; i <= t; i++) {


        SOLVE::main ();
        
    }
















    
    
    
    
    
    
    return 0;
}
