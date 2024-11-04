




using namespace std;







const int INF = 0x3f3f3f3f;
const long long INF64 = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

typedef long long ll;
typedef double db;
typedef complex<double> cb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef std::priority_queue<int, vector<int>, greater<int>> small_pq; 

typedef std::priority_queue<int, vector<int>, less<int>> big_pq;      


template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() {}
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << " " << H;
    if (sizeof...(T) > 0)
        cerr << " ,";
    dbg_out(T...);
}

void dbg_name(const string &s)
{
    string ss = s;
    replace(ss.begin(), ss.end(), ',', ' ');
    cerr << "  ( " << ss << " )  ";
}



    cerr << "\t\t\t";                               \
    cerr << __func__ << "_" << __LINE__ << " ->\t"; \
    dbg_name(
    cerr << "[";                                    \
    dbg_out(__VA_ARGS__);                           \
    cerr << " ]" << endl;



















template <typename T>
inline void setmin(T &a, const T &b)
{
    if (b < a)
        a = b;
}
template <typename T>
inline void setmax(T &a, const T &b)
{
    if (b > a)
        a = b;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t id0 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id0);
    }
};

unordered_map<long long, int, custom_hash> safe_map;


mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnd64(chrono::steady_clock::now().time_since_epoch().count());





const int MOD = 1e9 + 7;

inline int mul(int x, int y) { return 1ll * x * y % MOD; }
inline int add(int x, int y) { return (x + y >= MOD) ? x + y - MOD : x + y; }
inline int sub(int x, int y) { return ((x - y) % MOD + MOD) % MOD; }
inline int qpow(int a, int b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = mul(ans, a);
        a = mul(a, a);
        b /= 2;
    }
    return ans;
}


const int N = 2e3 + 5;

const int N = 1e5 + 5;


int inv[N];

namespace Polynomial
{
    typedef vector<int> Poly;

    namespace FFT
    {
        const int N = 50;
        int pos[N];
        cb W[2][N];

        void dft(cb *a, int k, int flag)
        {
            rep(i, 0, k - 1) if (i < pos[i])
                swap(a[i], a[pos[i]]);
            

            for (int h = 2, t = k >> 1; h <= k; h <<= 1, t >>= 1)
            {
                

                for (int i = 0; i < k; i += h)
                {
                    cb *w = W[flag];
                    

                    for (int j = i; j < i + h / 2; j++, w += t)
                    {
                        cb u = a[j], v = *w * a[j + h / 2];
                        a[j] = u + v;
                        a[j + h / 2] = u - v;
                    }
                }
            }
        }

        int init(int len)
        {
            int k = 1, l = 0;
            while (k <= len)
                k *= 2, l++;
            rep(i, 0, k - 1) pos[i] = (pos[i >> 1] >> 1 | (i & 1) << (l - 1));

            

            rep(i, 0, k - 1)
                W[0][i] = W[1][(k - i) & (k - 1)] = cb(cos(2 * PI * i / k), sin(2 * PI * i / k));

            return k;
        }

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        


        

        

        

        


        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        

        


        

        

        

        


        

        Poly mtt(const Poly &a, const Poly &b)
        {
            int len = a.size() + b.size() - 1;
            int k = init(len);

            static cb A[N], B[N], C[N], D[N];
            rep(i, 0, a.size() - 1) A[i] = cb(a[i] & 32767, a[i] >> 15);
            fill(A + a.size(), A + k, 0);
            rep(i, 0, b.size() - 1) B[i] = cb(b[i] & 32767, b[i] >> 15);
            fill(B + b.size(), B + k, 0);

            dft(A, k, 0), dft(B, k, 0);
            rep(i, 0, k - 1)
            {
                int j = (k - i) & (k - 1);
                C[i] = (A[i] + conj(A[j])) * 0.5 * B[i];
                D[i] = cb(A[i].imag() + A[j].imag(), A[j].real() - A[i].real()) * 0.5 * B[i];
            }
            dft(C, k, 1), dft(D, k, 1);

            Poly ans(len);
            rep(i, 0, len - 1)
            {
                ll u = llround(C[i].real() / k) % MOD, v = llround(C[i].imag() / k) % MOD;
                ll x = llround(D[i].real() / k) % MOD, y = llround(D[i].imag() / k) % MOD;
                ans[i] = (u + ((v + x) << 15) % MOD + (y << 30)) % MOD;
            }
            return ans;
        }

    };

    namespace NTT
    {
        const int N = 50;
        const int g1 = 3;
        int pos[N];
        int g[N];

        void dft(int *a, int k)
        {
            rep(i, 0, k - 1) if (i < pos[i])
                swap(a[i], a[pos[i]]);
            for (int h = 1; h < k; h <<= 1)
            {
                for (int i = 0; i < k; i += h * 2)
                {
                    for (int j = i; j < i + h; j++)
                    {
                        int u = a[j], v = mul(g[j + h - i], a[j + h]);
                        a[j] = add(u, v);
                        a[j + h] = sub(u, v);
                    }
                }
            }
        }

        void idft(int *a, int k)
        {
            reverse(a + 1, a + k);
            dft(a, k);
            int invk = qpow(k, MOD - 2);
            rep(i, 0, k - 1) a[i] = mul(a[i], invk);
        }

        int init(int len)
        {
            int k = 1, l = 0;
            while (k <= len)
                k *= 2, l++;

            rep(i, 0, k - 1) pos[i] = (pos[i >> 1] >> 1 | (i & 1) << (l - 1));

            

            int gv = qpow(g1, (MOD - 1) / k);
            g[k >> 1] = 1;
            for (int i = (k >> 1) + 1; i <= k; i++)
                g[i] = mul(g[i - 1], gv);
            for (int i = (k >> 1) - 1; i; i--)
                g[i] = g[i << 1];
            return k;
        }

        Poly ntt(const Poly &a, const Poly &b)
        {
            if (min(a.size(), b.size()) < 128)
            {
                Poly c(a.size() + b.size() - 1);
                rep(i, 0, a.size() - 1) rep(j, 0, b.size() - 1) c[i + j] = add(c[i + j], mul(a[i], b[j]));
                return c;
            }

            int len = (a.size() + b.size() - 1);
            int k = init(len);

            static int A[N], B[N];
            copy_n(a.begin(), a.size(), A);
            fill(A + a.size(), A + k, 0);
            copy_n(b.begin(), b.size(), B);
            fill(B + b.size(), B + k, 0);

            dft(A, k);
            dft(B, k);
            rep(i, 0, k - 1) A[i] = mul(A[i], B[i]);
            idft(A, k);

            Poly ans(len);
            copy_n(A, len, ans.begin());
            return ans;
        }
    };

    Poly operator*(const Poly &a, const Poly &b)
    {
        Poly ans = FFT::mtt(a, b);
        return ans;
    }

    void Div_fft(Poly &a, const Poly &b, int l, int r)
    {
        if (l == r)
            return;

        int mid = (l + r) >> 1;
        Div_fft(a, b, l, mid);

        

        

        Poly A(mid - l + 1), B(r - l + 1);
        rep(i, l, mid) A[i - l] = a[i];
        rep(i, 0, r - l) B[i] = b[i];
        Poly C = A * B;
        rep(i, mid + 1, r) a[i] = add(a[i], mul(inv[i], C[i - l]));
        Div_fft(a, b, mid + 1, r);
    }

    Poly operator+(const Poly &a, const Poly &b)
    {
        Poly ans(max(a.size(), b.size()));
        rep(i, 0, a.size() - 1)
            ans[i] = a[i];
        rep(i, 0, b.size() - 1)
            ans[i] = add(ans[i], b[i]);
        return ans;
    }

    Poly operator-(const Poly &a, const Poly &b)
    {
        Poly ans(max(a.size(), b.size()));
        rep(i, 0, a.size() - 1)
            ans[i] = a[i];
        rep(i, 0, b.size() - 1)
            ans[i] = sub(ans[i], b[i]);
        dbg(a);
        dbg(b);
        return ans;
    }

}

namespace Polynomial
{
    Poly Inverse(const Poly &a)
    {
        Poly b(1, qpow(a[0], MOD - 2));
        int n = a.size() << 1;
        dbg(a);
        for (int i = 2; i < n; i <<= 1)
        {
            

            Poly c(a);
            c.resize(i);
            b = (Poly(1, 2) - c * b) * b;
            b.resize(i);
        }
        b.resize(a.size());
        dbg(b);
        return b;
    }

    Poly Deriv(const Poly &a)
    {
        Poly ans(a.size());
        rep(i, 0, a.size() - 2)
            ans[i] = mul(a[i + 1], i + 1);
        return ans;
    }

    Poly Integral(const Poly &a)
    {
        Poly ans(a.size());
        rep(i, 1, a.size() - 1)
            ans[i] = mul(a[i - 1], qpow(i, MOD - 2));
        return ans;
    }

    pair<Poly, Poly> operator/(const Poly &a, const Poly &b)
    {
        assert(a.size() >= b.size());

        Poly A(a), B(b);
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        dbg(A, B);
        int len = a.size() - b.size() + 1; 

        A.resize(len), B.resize(len);

        Poly Q = A * Inverse(B);
        Q.resize(len);
        reverse(Q.begin(), Q.end());

        Poly R = a - b * Q;
        R.resize(b.size() - 1);

        return {Q, R};
    }
}

using namespace Polynomial;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> fac(3 * n + 4);
    fac[0] = 1;
    rep(i, 1, 3 * n + 3) fac[i] = mul(fac[i - 1], i);
    vector<int> inv(3 * n + 4);
    inv[3 * n + 3] = qpow(fac[3 * n + 3], MOD - 2);
    per(i, 3 * n + 2, 0) inv[i] = mul(inv[i + 1], i + 1);

    Poly f(3 * n + 4), g(4);

    g[1] = 3, g[2] = 3, g[3] = 1;

    auto C = [&](int n, int m)
    {
        return mul(fac[n], mul(inv[m], inv[n - m]));
    };

    rep(i, 0, 3 * n + 3)
    {
        f[i] = C(3 * n + 3, i);
    }
    f[0] -= 1;
    dbg(f);

    Poly Q(f.size() - g.size() + 1);

    per(i, f.size() - 1, 3)
    {
        int k = f[i];
        Q[i - 3] = k;
        f[i - 1] = sub(f[i - 1], 1ll * 3 * k % MOD);
        f[i - 2] = sub(f[i - 2], 1ll * 3 * k % MOD);
    }

    rep(i, 1, q)
    {
        int x;
        cin >> x;
        cout << Q[x] << endl;
    }
}

int main()
{

    

    

    int st_cl = clock();


    ios::sync_with_stdio(false);
    cin.tie(0);


    solve();


    LOG("Time: %dms\n", int((clock() - st_cl) / (double)CLOCKS_PER_SEC * 1000));

    return 0;
}