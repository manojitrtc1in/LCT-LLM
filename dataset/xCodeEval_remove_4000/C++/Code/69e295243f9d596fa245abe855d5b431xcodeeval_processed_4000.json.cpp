





































using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef float ff;
typedef double lf;
typedef long double llf;

typedef complex<ull> cull;
typedef complex<ff> cff;


typedef complex<lf> cllf;

const double eps = 1e-6;
const int int_inf = 2 * 1e9;
const ll ll_inf = 8 * 1e18;
const llf PI = acosl(-1.0);













template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

istream& operator >> (istream& in, pii& i) {
    in >> i.first >> i.second;
    return in;
}

template<class T>
istream& operator >> (istream& in, vector<T>& a) {
    for (auto& i : a) {
        in >> i;
    }
    return in;
}

template<class T>
ostream& operator << (ostream& out, vector<T>& a) {
    for (auto i : a) {
        out << i << " ";
    }
    return out;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
    return (ull)rng() % B;
}

template<typename T>
int64_t merge_sort(T* v, T* aux, int l, int r) {
    if (r <= l + 1) return 0;
    int m = (l + r) / 2;
    int64_t res = merge_sort(v, aux, l, m) + merge_sort(v, aux, m, r);
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        aux[k++] = v[i] <= v[j] ? v[i++] : (res += m - i, v[j++]);
    }
    while (i < m) aux[k++] = v[i++];
    while (j < r) aux[k++] = v[j++];
    while (l < r) {
        v[l] = aux[l];
        ++l;
    }
    return res;
}
template<typename T>
int64_t id4(std::vector<T> v) {
    std::vector<T> aux(v.size());
    return merge_sort(v.data(), aux.data(), 0, v.size());
}

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(llf t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }




ll gcd(ll a, ll b) { if (b > a) { return gcd(b, a); } if (b == 0) { return a; } return gcd(b, a % b); }
ll expo(ll a, ll b, ll mod) { ll res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }
void id2(ll a, ll b, ll* v) { if (b == 0) { v[0] = 1; v[1] = 0; v[2] = a; return; } id2(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return; } 

ll id3(ll a, ll b) { ll arr[3]; id2(a, b, arr); return arr[0]; } 

ll id1(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
void swap(int& x, int& y) { int temp = x; x = y; y = temp; }
ll combination(ll n, ll r, ll m, ll* fact, ll* ifact) { ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m; }
void google(int t) { std::cout << "Case 
vector<int> sieve(int n) { int* arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) { vect.push_back(i); for (ll j = (ll(i) * ll(i)); j <= n; j += i)arr[j] = 1; } return vect; }
ll mod_add(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
ll mod_div(ll a, ll b, ll m) { a = a % m; b = b % m; return (mod_mul(a, id1(b, m), m) + m) % m; }  

ll phin(ll n) { ll number = n; if (n % 2 == 0) { number /= 2; while (n % 2 == 0) n /= 2; } for (ll i = 3; i * i <= n; i += 2) { if (n % i == 0) { while (n % i == 0)n /= i; number = (number / i * (i - 1)); } } if (n > 1)number = (number / n * (n - 1)); return number; } 













ll fact[35];

ll powmod(ll a, ll b, ll p) {
    a %= p;
    if (a == 0) return 0;
    ll product = 1;
    while (b > 0) {
        if (b & 1) {    

            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2;    

    }
    return product;
}

ll inv(ll a, ll p) {
    return powmod(a, p - 2, p);
}

ll id0(ll n, ll k, ll p) {
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n - k], p)) % p;
}






const int MAXN = 1e5 * 5 + 1337;

struct event {
    int type;
    int x;
    int y;
    event(int a, int b, int c) {
        type = a;
        x = b;
        y = c;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> arr(MAXN);
    for (int i = 0; i < MAXN; ++i) {
        arr[i] = i;
    }
    vector<event> q;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 1) {
            int a;
            cin >> a;
            q.push_back(event(x, a, 0));
        }
        else {
            int a, b;
            cin >> a >> b;
            q.push_back(event(x, a, b));
        }
    }

    reverse(all(q));

    vector<int> ans;
    for (int i = 0; i < q.size(); ++i) {
        if (q[i].type == 1) {
            ans.pb(arr[q[i].x]);
        }
        else {
            arr[q[i].x] = arr[q[i].y];
        }
    }
    reverse(all(ans));
    cout << ans;
    cout << '\n';
    return;
}

signed main() {
    

    

    

    

    

    int tt = 1;
    

    while (tt--)
    {
        solve();
    }
    return 0;
}