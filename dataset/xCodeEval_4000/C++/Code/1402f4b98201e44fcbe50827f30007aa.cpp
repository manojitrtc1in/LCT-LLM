

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ret return
#define gc getchar
#define gcu getchar_unlocked
#define pc putchar
#define pcu putchar_unlocked
#define mp make_pair
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define emb emplace_back
#define em emplace
#define lb lower_bound
#define ub upper_bound
#define obk order_by_key
#define kby key_by_order
#define clr clear
#define ins insert
#define ct continue
#define br break
#define elif else if
#define endl "\n"
#define space " "
#define tab "\t"
#define newl cout << endl
#define deb(x) cerr << __FILE__ << ":" << __LINE__ << ": " << #x << " = " << x << endl
#define ff first
#define ss second
#define mod 1000000007
#define pr(a, b) pair<a, b>
#define ll long long
#define ld long double
#define itr iterator
#define ctr constant_iterator
#define SS stringstream
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) ((int)(a).size())
#define mlt(cntnr) multi##cntnr
#define fitr(u, d) for (auto u = (d).begin(); u != (d).end(); u++)
#define ritr(u, d) for (auto u = (d).rbegin(); u != (d).rend(); u++)
#define afor(u, v) for (auto &u : v)
#define from(T, i, a, b) for (T i = a; (a <= b) ? (i < b) : (i > b); (a <= b) ? (i++) : (i--))
#define inRange(a, b, c) (a <= b && b <= c)
#define usn(t) unsigned t
#define pbds(t) tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>
#define set_bits(x) __builtin_popcount(x)
#define set_bits_ll(x) __builtin_popcountll(x)
#define zro_bits_trail __builtin_ctz(x)
#define zro_bits_lead __builtin_clz(x)
#define zro_bits_trail_ll __builtin_ctzll(x)
#define zro_bits_lead_ll __builtin_clzll(x)
#define bit_set(a, b) ((a) |= (1ULL << (b)))
#define bit_clr(a, b) ((a) &= ~(1ULL << (b)))
#define bit_flp(a, b) ((a) ^= (1ULL << (b)))
#define bit_chk(a, b) (!!((a) & (1ULL << (b))))
#define bitmask_set(x, mask) ((x) |= (mask))
#define bitmask_clr(x, mask) ((x) &= ~(mask))
#define bitmask_flp(x, mask) ((x) ^= (mask))
#define bitmask_chk_all(x, mask) (!(~(x) & (mask)))
#define bitmask_chk_any(x, mask) ((x) & (mask))
#define sqr(x) (x) * (x)
#define amax(a, b) a = max(a, b)
#define amin(a, b) a = min(a, b)
#define rite(x) freopen(x, 'w', stdout)
#define read(x) freopen(x, 'r', stdin)
#define ten(n, T) (T)1e##n
#define unq(x) sort(all(x)), (x).erase(unique(all(x)), (x).end())
#define here cerr << "*************************************" << endl;

mt19937 ring(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
#define SHUF(v) shuffle(all(v), ring);
template <typename T>
T rng(T lim) {
    uniform_int_distribution<T> uid(0, lim - 1);
    ret uid(rang);
}

template <typename T>
void dbg_out(T last) { cerr << last; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << H << ", ";
    dbg_out(T...);
}

#define dbg(...) cerr << "{ " << #__VA_ARGS__ << " } = { ", dbg_out(__VA_ARGS__), cerr << " }" << endl

template <typename T>
bool isPow2(T num) {
    if (num < 1)
        ret false;
    ret(num & (num - 1)) == 0;
}

template <typename T>
T binpow(T base, T pow, T m = mod) {
    T res = 1;
    base %= m;
    while (pow) {
        if (pow & 1) {
            res = (res * base) % m;
        }
        base = (base * base) % m;
        pow >>= 1;
    }
    ret res;
}

template <typename T>
T gcd(T a, T b) { ret(b ? __gcd(a, b) : a); }

template <typename T>
T lcm(T a, T b) { ret(a * b) / gcd(a, b); }

int add(int a, int b, int c = mod) {
    ll res = (ll)a + (ll)b;
    ret(int)(res % c);
}

int mod_neg(int a, int b, int c = mod) {
    ll res = (ll)a - (ll)b;
    ret(int)(((res % c) + c) % c);
}

int mul(int a, int b, int c = mod) {
    ll res = a * 1LL * b;
    ret(int)(res % c);
}

int muln(int a, int b, int c = mod) {
    ll res = a * 1LL * b;
    ret(int)(((res % c) + c) % c);
}

ll mulmod(ll a, ll b, ll m = mod) {
    a %= m;
    b %= m;
    ret(((a * b) % m + m) % m);
}

template <typename T>
T extended_euclid(T a, T b, T &x, T &y) {
    T xx = 0, yy = 1;
    x = 1, y = 0;
    while (b) {
        T q = a / b, t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    ret a;
}

template <typename T>
T mod_inv(T a, T n = mod) {
    T x, y, z = 0;
    T d = extended_euclid(a, n, x, y);
    ret(d > 1 ? -1 : mod_neg(x, z, n));
}

const int NN = 1e5 + 10;
vector<int> fact(0);
vector<int> ifact(0);

template <typename T>
void build_facts(T m = mod) {
    fact = vector<int>(NN, 1);
    ifact = vector<int>(NN, 1);
    fact[0] = 1;
    from(int, i, 1, NN) fact[i] = mul(i, fact[i - 1], m);
    ifact[NN - 1] = mod_inv(fact[NN - 1], m);
    from(int, i, NN - 1, -1) ifact[i] = mul(i + 1, fact[i + 1], m);
}

int ncr(usn(int) n, usn(int) r, int m = mod) { ret mul(mul(ifact[r], ifact[n - r], m), fact[n], m); }

set<int> primes;
vector<bool> isPrime(0);

void sieve() {
    isPrime = vector<bool>(NN, true);
    isPrime[1] = false;
    from(int, i, 2, NN) {
        if (isPrime[i]) {
            primes.insert(i);
            for (int j = 2; j * i < NN; j++)
                isPrime[i * j] = false;
        }
    }
}

const int nprime = sz(primes);

template <typename T>
bool miller_rabin(T p, T itt) {
    if (p < 2)
        ret 0;
    if (p == 2)
        ret 1;
    if (!(p & 1))
        ret 0;
    usn(ll) s = p - 1;
    while (!(s & 1))
        s /= 2;
    while (itt--) {
        usn(ll) a = rand() % (p - 1) + p, tmp = s;
        usn(ll) m = binpow(a, tmp, (usn(ll))p);
        while (m != 1 && m != p - 1 && tmp != p - 1) {
            m = mulmod(m, m, (usn(ll))p);
            tmp *= 2;
        }
        if (!(tmp & 1) && m != p - 1)
            ret 0;
    }
    ret 1;
}

template <typename T>
T PrimeFactors(T n) {
    if (n < 1)
        ret 0;
    if (n > 0 && n < NN && isPrime[n])
        ret 2;
    ll cnt = 0, sum = 1;
    afor(p, primes) {
        if (p > n)
            br;
        cnt = 0;
        while (n % p == 0) {
            cnt++;
            n /= p;
        }
        sum *= cnt + 1;
    }
    if (n > 1)
        sum *= 2;
    ret sum;
}

template <typename T>
class Point {
public:
    T x, y, z;
    Point() {
        this->x = this->y = this->z = 0;
    }
    T pointDistanceAxial(const Point<T> p) { ret abs(x - p.x) + abs(y - p.y) + abs(z - p.z); }
    T pointDistanceDgnal(const Point<T> p) { ret sqrt(sqr(x - p.x) + sqr(y - p.y) + sqr(z - p.z)); }
    T PointDistanceMinmm(const Point<T> p) { ret max(abs(x - p.x), abs(y - p.y), abs(z - p.z)); }
};

const int d4[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const int d8[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
const int dh[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

vector<string> split(const string &str, char delim) {
    vector<string> res(0);
    SS sss(str);
    string tmp = "";
    while (getline(sss, tmp, delim))
        res.pub(tmp);
    ret res;
}

template <typename T>
void extract(string data, T &ret_data) {
    SS sss(data);
    sss >> ret_data;
}

template <typename T>
string toString(T data) {
    SS sss;
    sss << data;
    ret sss.str();
}

string operator*(string str, usn(int) n) {
    string res = "";
    while (n) {
        if (n & 1)
            res += str;
        str += str;
        n >>= 1;
    }
    ret res;
}

template <typename U, typename V>
ostream &operator<<(ostream &os, const pr(U, V) & p) { ret os << "(" << p.ff << ", " << p.ss << ")"; }

template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    string sep = "";
    for (const T &u : v)
        os << sep << u, sep = " ";
    ret os;
}

void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
}

void __attribute__((constructor)) startup() {
    

}

void __attribute__((destructor)) shutdown() {
    

}

struct ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int v = 0) {
        val = v;
        next = nullptr;
    }
};

class LinkedList {
public:
    ListNode head;
    ListNode *tail;

    LinkedList() {
        head.val = -1;
        head.next = nullptr;
        tail = &head;
    }
    void insert(int v) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    void merge(LinkedList lst) {
        tail->next = lst.head.next;
        tail = lst.tail;
    }
    void print() {
        ListNode *tmp = head.next;
        while (tmp != nullptr)
            cout << (tmp->val) << " ", tmp = tmp->next;
    }
};

void solve() {
    int q;
    unordered_map<int, LinkedList> val_indx;
    cin >> q;
    int sz = 0;
    while (q--) {
        int t, x, y;
        cin >> t;
        if (t == 1) {
            cin >> x;
            val_indx[x].insert(sz++);
        } else {
            cin >> x >> y;
            if (x != y && val_indx.count(x)) {
                val_indx[y].merge(val_indx[x]);
                val_indx.erase(val_indx.find(x));
            }
        }
    }
    vector<int> res(sz, 0);
    for (auto val : val_indx) {
        ListNode *tmp = val.second.head.next;
        while (tmp != nullptr)
            res[tmp->val] = val.first, tmp = tmp->next;
    }
    cout << res << endl;
}

int main() {
    fastIO();
    int t = 1;
    

    while (t--)
        solve();
    ret 0;
}