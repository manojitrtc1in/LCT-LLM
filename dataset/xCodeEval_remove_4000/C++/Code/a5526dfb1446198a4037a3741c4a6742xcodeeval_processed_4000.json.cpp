















 
 




 


 












 











 
using namespace std;
using namespace __gnu_pbds;
 
 
typedef long long  ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> tri;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> S_t;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct custom_Hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t id0 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id0);
    }
};
 

template<typename t> void fff(const char* x, t&& val1) { cout << x << " : " << val1 << "\n";}
template<typename t1, typename... t2> void fff(const char* x, t1&& val1, t2&&... val2){
    const char* xd = strchr(x + 1, ',');
    cout.write(x, xd - x) << " : " <<val1 << " | ";
    fff(xd + 1, val2...);
}
 
inline ll add(ll a, ll b, ll mod) { return a + b < mod? a + b : a + b - mod;}
inline ll rem(ll a, ll b, ll mod) { return a >= b? a - b: a - b + mod;}
inline ll mul(ll a, ll b, ll mod) { return (long long) a * b % mod;}
inline void Mul(ll &a, ll b, ll mod) { a = (long long) a * b % mod;}
inline ll bp(ll a, ll p, ll mod){
    ll ret;
    for(ret = 1; p; p >>= 1, Mul(a, a, mod)) (p & 1) && (Mul(ret, a, mod), 1);
    return ret;
}
 
static inline void read(ll &result) {
    bool minus = false;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' and ch <= '9') break;
        ch = getchar();
    }
    (ch == '-')? minus = true: result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' or ch > '9') break;
        result = (result<<3)+ (result<<1) + (ch - '0');
    }
    if(minus) result = -result;
}


namespace FFT{
    

    typedef complex<double> base;
    

 
    

    

 
    const double C_PI = acos(-1);
 
    inline void fft(vector <base> &a, bool invert){
        int n = sz(a);
        for(int i = 0, j = 0; i < n; ++ i) {
            if(i > j) swap(a[i], a[j]);
            for(int k = n >> 1; (j ^= k) < k; k >>= 1);
        }
        for (int len = 2; len <= n; len <<= 1){
            double ang = 2 * C_PI / len * (invert ? -1 : 1);
            base wlen(cos(ang), sin(ang));
            for (int i = 0; i < n; i += len){
                base w(1);
                for (int j = 0; j < len/2; j ++){
                    if((j & 511) == 511) w = base(cos(ang * j), sin(ang * j));
                    base u = a[i + j], v = a[i + j + len / 2] * w;
                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;
                    w *= wlen;
                }
            }
        }
        if (invert){
            for (int i = 0; i < n; i ++) a[i] /= n;
        }
    }
 
    inline void multiply(const vector<ll> &a,const vector<ll> &b,vector<ll> &res, const int MOD){
        vector <base> fa(all(a)), fb(all(b));
        int n = 1;
        while (n < max(sz(a), sz(b))) n <<= 1; n <<= 1;
        fa.resize(n); fb.resize(n);
        fft(fa,false); fft(fb,false);
        for (int i = 0; i < n; i ++) fa[i] *= fb[i];
        fft(fa,true);
        res.resize(n);
        for (int i = 0;i < n; i ++) res[i] = ((ll)(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5))) % MOD;
    }
 
    inline void id2(const vector<ll> &a, const vector<ll> &b, vector<ll> &res, const ll MOD){
        int n = 1;
        while (n < max(sz(a), sz(b))) n <<= 1; n <<= 1;
        vector <base> A(n), B(n);
        int L_BLOCK = 10;   

        for(int i = 0; i < n; i ++) A[i] = (i < sz(a) ? base(a[i] & ((1 << L_BLOCK) - 1), a[i] >> L_BLOCK) : base(0));
        for(int i = 0; i < n; i ++) B[i] = (i < sz(b) ? base(b[i] & ((1 << L_BLOCK) - 1), b[i] >> L_BLOCK) : base(0));
        fft(A, false); fft(B, false);
        vector <base> f1(n), f2(n), f3(n), f4(n);
        for(int i = 0; i < n; i ++) {
            int j = (n - i) & (n - 1);
            f2[i] = (A[i] + conj(A[j])) * base(0.5, 0);
            f1[i] = (A[i] - conj(A[j])) * base(0, -0.5);
            f4[i] = (B[i] + conj(B[j])) * base(0.5, 0);
            f3[i] = (B[i] - conj(B[j])) * base(0, -0.5);
        }
        for(int i = 0; i < n; i ++) {
            A[i] = f1[i] * f3[i] + f1[i] * f4[i] * base(0, 1);
            B[i] = f2[i] * f4[i] * base(0, 1) + f2[i] * f3[i];
        }
        fft(A, true); fft(B, true);
        res.resize(n);
        for(int i = 0; i < n; i ++) {
            long long g1=(ll)(A[i].real() + 0.5) % MOD;  

            long long g2=(ll)(A[i].imag() + 0.5) % MOD;
            long long g3=(ll)(B[i].real() + 0.5) % MOD;
            long long g4=(ll)(B[i].imag() + 0.5) % MOD;
            res[i] = (g4 + ((g2 + g3) << L_BLOCK) + (g1 << (L_BLOCK << 1))) % MOD;
        }
    }
    
    inline void multiply_big(vector<ll> &a, vector<ll> &b, vector <ll> &res){
        int n = 1;
        while (n < max(sz(a), sz(b))) n <<= 1; n <<= 1;
        vector <base> A(n), B(n);
        int L_BLOCK = 10;
        for(int i = 0; i < n; i++) A[i] = (i < sz(a) ? base(a[i] & ((1 << L_BLOCK) - 1), a[i] >> L_BLOCK) : base(0));
        for(int i = 0; i < n; i++) B[i] = (i < sz(b) ? base(b[i] & ((1 << L_BLOCK) - 1), b[i] >> L_BLOCK) : base(0));
        fft(A, false); fft(B, false);
        vector <base> f1(n), f2(n), f3(n), f4(n);
        for(int i = 0; i < n; i ++) {
            int j = (n - i) & (n - 1);
            f2[i] = (A[i] + conj(A[j])) * base(0.5, 0);
            f1[i] = (A[i] - conj(A[j])) * base(0, -0.5);
            f4[i] = (B[i] + conj(B[j])) * base(0.5, 0);
            f3[i] = (B[i] - conj(B[j])) * base(0, -0.5);
        }
        for(int i = 0; i < n; i ++) {
            A[i] = f1[i] * f3[i] + f1[i] * f4[i] * base(0, 1);
            B[i] = f2[i] * f4[i] * base(0, 1) + f2[i] * f3[i];
        }
        fft(A, true); fft(B, true);
        res.resize(n);
        for(int i = 0; i < n; i ++) {
            ll g1 = (ll)(A[i].real() + 0.5);
            ll g2 = (ll)(A[i].imag() + 0.5);
            ll g3 = (ll)(B[i].real() + 0.5);
            ll g4 = (ll)(B[i].imag() + 0.5);
            res[i] = (g4 + ((g2 + g3) << (L_BLOCK)) + (g1 << (L_BLOCK << 1)));
        }
    }
}

ll MOD;

inline bool is_zero(vi x) { return x.empty();}
inline vi operator * (vi a, vi b) {
    if(is_zero(a) or is_zero(b)) return {};
    vi A, B, C;
    for(auto xd : a) A.pb(xd);
    for(auto xd : b) B.pb(xd);
    FFT::id2(A, B, C, MOD);
    while(sz(C) and !C.back()) C.pop_back();
    return C;
}
inline vi operator - (vi a, vi b) {
    ll n = max(sz(a), sz(b));
    vi ans(n);
    a.resize(n, 0);
    b.resize(n, 0);
    FER(i, 0, n) ans[i] = add(a[i], b[i], MOD);
    while(sz(ans) and !ans.back()) ans.pop_back();
    return ans;
}
inline vi operator * (const vi a, const ll &x) {
    ll n =sz(a);
    vi ans(n);
    FER(i, 0, n) ans[i] = mul(ans[i], x, MOD);
    return ans;
}

ll times[1 << 19], k;

struct T {
    vi L, R; 
    ll ans, ret, sum;
    T() {}
    T(vi L, vi R, ll ans, ll ret, ll sum) : L(L), R(R), ans(ans), ret(ret), sum(sum) {}
    inline void clear() {
        vi().swap(L);
        vi().swap(R);
        ans = 0;
        ret = 0;
        sum = 0;
    }
};

ll vis[1 << 19], sum;
T wynk[1 << 19];

inline ii update_state(vi &a, vi &b, ll sum) {
    ll AA = 0, BB = 0;
    FER(i, 0, k) {
        ll x = rem(0, i, k);
        ll y = rem(sum, i, k);
        AA = add(AA, mul(a[i], b[x], MOD), MOD);
        BB = add(BB, mul(a[i], b[y], MOD), MOD);
    }
    return make_pair(AA, BB);
}

inline T solve(ll l, ll r) {
    if(vis[r - l]) return wynk[r - l];
    ll mid = (l + r) >> 1;
    auto xL = solve(l, mid);
    auto xR = solve(mid, r);
    T A;
    A.ans = add(xL.ans, xR.ans, MOD);
    A.ret = add(xL.ret, xR.ret, MOD);
    auto [AA, BB] = update_state(xL.R, xR.L, sum);
    A.ans = add(AA, A.ans, MOD);
    A.ret = add(BB, A.ret, MOD);
    A.L = xL.L;
    A.R = xR.R;
    FER(i, 0, k) {
        auto idL = add(i, xL.sum, k);
        auto idR = add(i, xR.sum, k);
        A.L[idL] = add(A.L[idL], xR.L[i], MOD);
        A.R[idR] = add(A.R[idR], xL.R[i], MOD);
    }
    A.sum = add(xL.sum, xR.sum, k);
    vis[r - l] ++;
    return wynk[r - l] = A;
}

int main() {
    fastio;
    ll n, m; cin >> n >> m >> k;
    MOD = 1000000007;
    vi ar(n);
    for(auto &xd : ar) cin >> xd, xd %= k;
    if(k == 1) {
        auto x = (1LL * n * m) % MOD;
        auto id1 = x * (x - 1) + 1;
        cout << id1 % MOD << "\n";
        return 0;
    }
    vi L(k, 0), R(k, 0), vt(k, 0);
    function<ll(ll, ll, ll)> dfs = [&](ll l, ll r, ll x) {
        if(l + 1 == r) return ll((ar[l] % k) == x);
        ll mid = (l + r) >> 1, acum = 0, rpta = 0;
        vi tnt;
        IFR(i, mid - 1, l) {
        	acum = add(acum, ar[i], k);
            tnt.pb(acum);
            vt[acum] = 0;
            L[acum] = 0;
            ll need = rem(x, acum, k);
			R[need] = 0;
        }
        acum = 0;
        IFR(i, mid - 1, l) {
        	acum = add(acum, ar[i], k);
            L[acum] ++;
        }
        acum = 0;
        FER(i, mid, r) {
	    	acum = add(acum, ar[i], k);
            R[acum] = 0;
        }
        acum = 0;
        FER(i, mid, r) {
        	acum = add(acum, ar[i], k);
            R[acum] ++;
        }
        for(auto xd : tnt) {
            if(vt[xd]) continue;
            vt[xd] ++;
            ll need = rem(x, xd, k);
            rpta = add(rpta, mul(L[xd], R[need], MOD), MOD);
        }
        auto X = dfs(l, mid, x);
        auto Y = dfs(mid, r, x);
        return add(add(X, Y, MOD), rpta, MOD);
    };
    auto process = [&](vi ar) {
        FER(i, 0, k + 1)  vis[i] = 0;
        for(auto &xd : ar) xd %= k, sum += xd;
        wynk[1].clear();
        sum %= k;
        wynk[1].sum = sum;
        sum = (1LL * sum * m) % k;
        auto G = [&](vi &vec) {
            vi acum;
            ll ans = 0;
            for(auto xd : vec) {
                ans = add(xd, ans, k);
                acum.pb(ans);
            }
            vi resp(k, 0);
            for(auto xd : acum) resp[xd] ++;
            return resp;
        };
        wynk[1].ret = dfs(0, n, sum);
        vis[1] ++;
        wynk[1].L = G(ar);
        reverse(all(ar));
        wynk[1].R = G(ar);
        vi tot(k, 0);
        ll ret = 0;
        for(auto xd : ar) {
            ret = add(ret, xd, k);
            tot[ret] ++;
        }
        for(auto xd : tot) {
            long long kt = (1LL * xd * (xd - 1)) / 2;
            wynk[1].ans = add(wynk[1].ans, kt % MOD, MOD);
        }
        wynk[1].ans = add(wynk[1].ans % MOD, tot[0], MOD);
        auto Sara = solve(0, m); 
        return Sara;
    };
    auto P = process(ar);
    auto X = P.L[sum];
    auto Y = P.R[sum];
    ll adder = P.ret - X - Y + 1;
    ll id1 = ((adder + P.ans) % MOD + MOD) % MOD;
    cout << id1 << "\n";
    return 0;
}