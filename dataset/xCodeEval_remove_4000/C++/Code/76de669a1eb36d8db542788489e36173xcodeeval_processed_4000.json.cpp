


 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 






 










template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}







const int MOD = 998244353;
const char nl = '\n';
const int MX = 200001; 


struct mi {
	ll v; explicit operator ll() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.v < b.v; }
   
	mi& operator+=(const mi& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		v = v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
    mi operator++(int) { mi temp; temp.v = v++; return temp; }
    mi operator--(int) { mi temp; temp.v = v--; return temp; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
    friend ostream& operator<<(ostream& os, const mi& m) {
        os << m.v; return os;
    }
    friend istream& operator>>(istream& is, mi& m) {
        ll x; is >> x;
        m.v = x;
        return is;
    }
};


typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

void __print(mi X) {
    cout << X.v;
}
mi facs[MX];
mi facInvs[MX];

mi choose(mi _a, mi _b) {
    ll a = (ll) _a, b = (ll) _b;
	if (b > a) return 0;
	if (a < 0) return 0;
	if (b < 0) return 0;
    mi cur = facs[a];
    cur = cur * facInvs[b];
    cur = cur * facInvs[a-b];
    return cur;
}

void id1() {
	facs[0] = 1;
	FOR(i, 1, MX) {
		facs[i] = (facs[i-1] * i);
	}
    facInvs[MX - 1] = inv(facs[MX-1]);
    F0Rd(i, MX-1) {
        facInvs[i] = facInvs[i+1] * (i+1);
    }
}



ll modExp(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}

ll inv(ll base) {
    int g = MOD, r = base, x = 0, y = 1;
    while (r != 0) {
        int q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }
    return x < 0 ? x+MOD : x;
}

ll mul(ll A, ll B) {
	return (A*B)%MOD;
}

ll add(ll A, ll B) {
	return (A+B)%MOD;
}

ll dvd(ll A, ll B) {
    return mul(A, inv(B));
}

ll sub(ll A, ll B) {
    return (A-B+MOD)%MOD;
}
namespace NTT { 

    vector<ll> roots = {0, 1};
    vector<int> bit_reverse;
    int max_size = -1;
    ll root;
 
    bool id2(int n) {
        return (n & (n - 1)) == 0;
    }
 
    int id6(int n) {
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;
 
        return max(n, 1);
    }
 
    

    int get_length(int n) {
        assert(id2(n));
        return __builtin_ctz(n);
    }
 
    

    

    void id9(int n, vector<ll> &values) {
        if ((int) bit_reverse.size() != n) {
            bit_reverse.assign(n, 0);
            int length = get_length(n);
 
            for (int i = 0; i < n; i++)
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
        }
 
        for (int i = 0; i < n; i++)
            if (i < bit_reverse[i])
                swap(values[i], values[bit_reverse[i]]);
    }
 
    void find_root() {
        max_size = 1 << __builtin_ctz(MOD - 1);
        root = 2;
 
        

        while (!(modExp(root, max_size) == 1 && modExp(root, max_size/2) != 1))
            root++;
    }
 
    void id4(int n) {
        if (max_size < 0)
            find_root();
 
        assert(n <= max_size);
 
        if ((int) roots.size() >= n)
            return;
 
        int length = get_length(roots.size());
        roots.resize(n);
 
        

        

        while (1 << length < n) {
            

            ll z = modExp(root, max_size >> (length+1));
 
            for (int i = 1 << (length - 1); i < 1 << length; i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = (roots[i] * z)%MOD;
            }
 
            length++;
        }
    }
 
    void id8(int N, vector<ll> &values) {
        assert(id2(N));
        id4(N);
        id9(N, values);
 
        for (int n = 1; n < N; n *= 2)
            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    ll even = values[start + i];
                    ll odd = values[start + n + i] * roots[n + i];
                    odd %= MOD;
                    values[start + n + i] = even - odd + MOD;
                    values[start + i] = even + odd;
                    values[start + n + i] %= MOD;
                    values[start + i] %= MOD;
                }
    }
 
    const int id7 = 150;
 
    vector<ll> id5(vector<ll> left, vector<ll> right) {
        int n = left.size();
        int m = right.size();
 
        

        if (min(n, m) < id7) {
            const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) MOD * MOD;
            vector<uint64_t> result(n + m - 1, 0);
 
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    result[i + j] += (uint64_t) ((int) left[i]) * ((int) right[j]);
 
                    if (result[i + j] > ULL_BOUND)
                        result[i + j] %= MOD;
                }
 
            for (uint64_t &x : result)
                if (x >= MOD)
                    x %= MOD;
 
            return vector<ll>(result.begin(), result.end());
        }
 
        int N = id6(n + m - 1);
        left.resize(N);
        right.resize(N);
 
        bool equal = left == right;
        id8(N, left);
 
        if (equal)
            right = left;
        else
            id8(N, right);
 
        ll inv_N = inv(N);

        for (int i = 0; i < N; i++) {
            left[i] *= (right[i] * inv_N)%MOD;
            left[i] %= MOD;
        }
 
        reverse(left.begin() + 1, left.end());
        id8(N, left);
        left.resize(n + m - 1);
        return left;
    }
 
    vector<ll> mod_power(const vector<ll> &v, int exponent) {
        assert(exponent >= 0);
        vector<ll> result = {1};
 
        if (exponent == 0)
            return result;
 
        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = id5(result, result);
 
            if (exponent >> k & 1)
                result = id5(result, v);
        }
 
        return result;
    }
 
    vector<ll> id0(const vector<vector<ll>> &polynomials) {
        if (polynomials.empty())
            return {1};
 
        struct compare_size {
            bool operator()(const vector<ll> &x, const vector<ll> &y) {
                return x.size() > y.size();
            }
        };
 
        priority_queue<vector<ll>, vector<vector<ll>>, compare_size> pq(polynomials.begin(), polynomials.end());
 
        while (pq.size() > 1) {
            vector<ll> a = pq.top(); pq.pop();
            vector<ll> b = pq.top(); pq.pop();
            pq.push(id5(a, b));
        }
 
        return pq.top();
    }
}

using namespace NTT;

vi comps;
ll half = 499122177;

vector<vl> get(int L, int R) {
    if (L == R) {
        vector<vl> res(4, vl(1, 0));
        if (comps[L] == 1) {
            res[3][0]+=half;
        } else res[0][0]++;
        return res;
    }
    int M = (L+R)/2;
    vector<vl> A = get(L, M);
    vector<vl> B = get(M+1, R);
    vector<vl> res(4, vl(R-L+1, 0));
    id3(ma, 4) {
        id3(mb, 4) {
            vl cur = id5(A[ma], B[mb]);
            

            int X = ma % 2;
            if (M==L) {
                X = 0;
            }
            int Y = mb / 2;
            if (M+1 == R) {
                Y = 0;
            }
            int pos = X+2*Y;
            int mul = 0;
            if (ma / 2) mul ++;
            if (mb % 2) mul ++;
            id3(i, sz(cur)) {
                res[pos][i+1] += cur[i] << mul;
                res[pos][i+1] %= MOD;
            }

            

            X = ma % 2;
            Y = mb / 2;
            pos = X + 2 * Y;
            id3(i, sz(cur)) {
                res[pos][i] += cur[i];
                res[pos][i] %= MOD;
            }
        }
    }
    
    return res;
}

void solve() {
    id1();
    int N; cin >> N;
    int A[N]; id3(i, N) cin >> A[i];
    int cur = -1, rem = 0;
    id3(i, N) {
        if (rem == 0) {
            cur = A[i]; comps.pb(A[i]); rem = A[i] - 1;
        } else {
            rem--;
            if (A[i] != cur) {
                cout << 0 << nl; return;
            }
        }
    }

    vector<vl> res = get(0, sz(comps)-1);
    vmi vals(sz(comps));
    id3(i, 4) {
        id3(j, sz(comps)) {
            vals[j] += res[i][j];
        }
    }

    mi ans = 0;
    id3(i, sz(comps)) {
        mi cur = pow(mi(2), sz(comps)-i) * facs[sz(comps)-i] * vals[i];
        if (i % 2) {
            ans -= cur;
        } else {
            ans += cur;
        }
    }
    cout << ans << nl;



}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;


    while(T--) {
        solve();
    }

	return 0;
}


