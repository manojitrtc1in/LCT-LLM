#include <bits/stdc++.h>
#include <random>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;








typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector<short> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<string> vst;
typedef vector<vst> vvst;
typedef pair<ld, ld> pld;
typedef complex<double> base;

#define inmin(a, b) a = min(a, (b))
#define inmax(a, b) a = max(a, (b))
#define mp(a, b) make_pair((a), (b))
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define sqr(x) ((x) * (x))
#define fori(i, n) for(int i = 0; i < int(n); ++i)
#define SZ(a) ((int)((a).size()))
#define triple(T) tuple<T, T, T>
#define quad(T) tuple<T, T, T, T>
#define watch(x) cerr << (#x) << " = " << (x) << endl;

#ifdef MAX_HOME
#define cerr cout
#else
#define cerr if (false) cerr
#endif

const double pi = 2 * acos(0.0);
#define rand shittttty_shit
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());

const string DIGITS = "0123456789";
const string ALPH = "abcdefghijklmnopqrstuvwxyz";


template <class T0, class T1>
inline ostream & operator << (ostream &out, pair<T0, T1> &a) {
    return out << "{" << a.first << ", " << a.second << "}";
}

template <class T0, class T1>
inline istream & operator >> (istream &in, pair<T0, T1> &a) {
    return in >> a.first >> a.second;
}

template <class T0, class T1, class T2>
inline ostream & operator << (ostream &out, tuple<T0, T1, T2> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << "}";
}

template <class T0, class T1, class T2, class T3>
inline ostream & operator << (ostream &out, tuple<T0, T1, T2, T3> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ", " <<  get<3>(a) << "}";
}

template<class T>
inline ostream & operator << (ostream &out, vector<T> &a) {
    out << "[";
    fori (i, a.size())
        out << a[i] << vector<string>{", ", "]  "}[i + 1 == a.size()];
    return out;
}


void smain();

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef MAX_HOME
    freopen("input.txt", "r", stdin);
    clock_t start = clock();
#endif
    cout << setprecision(12) << fixed;
    smain();
#ifdef MAX_HOME
    cout << "\n\n\n\nTOTAL EXECUTION TIME: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
    return 0;
}


const int N = 1e5 + 10;

struct edge {
    int from, to, w;
};

const int M = 1e9 + 7;

vector<edge> e;
vi g[N];


int used[N];
set<int> forbid;

int xr[N];


int root = -1;
vi sack[N];

void dfs(int v, int par) {
    used[v] = 1;

    for (int id : g[v]) {
        int to = e[id].to;
        if (to == par)
            continue;
        if (forbid.count(to) && to != root)
            continue;

        if (used[to] == 0) {
            xr[to] = xr[v] ^ e[id].w;
            dfs(to, v);
        } else if (used[to] == 1) {
            sack[root].push_back(xr[v] ^ xr[to] ^ e[id].w);
        }
    }

    used[v] = 2;
}

const int L =50;

vi norm(vi a) {
    vi na = a;
    sort(ALL(na));
    na.resize(unique(ALL(na)) - na.begin());
    if (na.size() != a.size()) {
        return {0};
    }

    int i = 0;
    int n = a.size();
    for (int j = 0; j < L; ++j) {
        bool flag = false;
        for (int k = i; k < n; ++k) {
            if ((a[k] >> j) & 1) {
                swap(a[i], a[k]);
                flag = true;
                break;
            }
        }
        if (flag) {
            i++;
            for (int k = 0; k < n; ++k) if (i - 1 != k) {
                if ((a[k] >> j) & 1) {
                    a[k] ^= a[i - 1];
                }
            }
        }
    }
    return a;
}

bool can(vi a, int mask) {
    a.push_back(mask);
    vi kek = norm(a);
    return count(ALL(kek), 0);
}

void rec(vi a, int id, set<vi> & all) {
    if (id == -1) {
        a = norm(a);
        if (!count(ALL(a), 0))
            all.insert(a);
        return;
    }
    fori (i, 32) {
        a[id] = i;
        rec(a, id - 1, all);
    }
}

void test() {
    set<vi> all;
    fori (len, 6) {
        vi a(len);
        rec(a, len - 1, all);
    }
    watch(all.size());
    cerr << "{";
    auto xlast = *all.rbegin();
    for (auto x : all) {
        cout << "{";
        for (int i = 0; i < x.size(); ++i) {
            cout << x[i] << ", "[i + 1 == x.size()];
        }
        cout << "}";
        if (x != xlast)
            cout << ",";
    }
    cerr << "};";

    exit(0);
}


const vvi all = {{},{1 },{1,2 },{1,2,4 },{1,2,4,8 },{1,2,4,8,16 },{1,2,4,16 },{1,2,4,24 },{1,2,8 },{1,2,8,16 },{1,2,12 },{1,2,12,16 },{1,2,16 },{1,2,20 },{1,2,20,8 },{1,2,20,24 },{1,2,24 },{1,2,28 },{1,4 },{1,4,8 },{1,4,8,16 },{1,4,16 },{1,4,24 },{1,6 },{1,6,8 },{1,6,8,16 },{1,6,16 },{1,6,24 },{1,8 },{1,8,16 },{1,10 },{1,10,4 },{1,10,4,16 },{1,10,12 },{1,10,12,16 },{1,10,16 },{1,10,20 },{1,10,28 },{1,12 },{1,12,16 },{1,14 },{1,14,16 },{1,16 },{1,18 },{1,18,4 },{1,18,4,8 },{1,18,4,24 },{1,18,8 },{1,18,12 },{1,18,20 },{1,18,20,8 },{1,18,20,24 },{1,18,24 },{1,18,28 },{1,20 },{1,20,8 },{1,20,24 },{1,22 },{1,22,8 },{1,22,24 },{1,24 },{1,26 },{1,26,4 },{1,26,12 },{1,26,20 },{1,26,28 },{1,28 },{1,30 },{2 },{2,4 },{2,4,8 },{2,4,8,16 },{2,4,16 },{2,4,24 },{2,8 },{2,8,16 },{2,12 },{2,12,16 },{2,16 },{2,20 },{2,20,8 },{2,20,24 },{2,24 },{2,28 },{3 },{3,4 },{3,4,8 },{3,4,8,16 },{3,4,16 },{3,4,24 },{3,8 },{3,8,16 },{3,12 },{3,12,16 },{3,16 },{3,20 },{3,20,8 },{3,20,24 },{3,24 },{3,28 },{4 },{4,8 },{4,8,16 },{4,16 },{4,24 },{5 },{5,2 },{5,2,8 },{5,2,8,16 },{5,2,16 },{5,2,24 },{5,6 },{5,6,8 },{5,6,8,16 },{5,6,16 },{5,6,24 },{5,8 },{5,8,16 },{5,10 },{5,10,16 },{5,14 },{5,14,16 },{5,16 },{5,18 },{5,18,8 },{5,18,24 },{5,22 },{5,22,8 },{5,22,24 },{5,24 },{5,26 },{5,30 },{6 },{6,8 },{6,8,16 },{6,16 },{6,24 },{7 },{7,8 },{7,8,16 },{7,16 },{7,24 },{8 },{8,16 },{9 },{9,2 },{9,2,4 },{9,2,4,16 },{9,2,12 },{9,2,12,16 },{9,2,16 },{9,2,20 },{9,2,28 },{9,4 },{9,4,16 },{9,6 },{9,6,16 },{9,10 },{9,10,4 },{9,10,4,16 },{9,10,12 },{9,10,12,16 },{9,10,16 },{9,10,20 },{9,10,28 },{9,12 },{9,12,16 },{9,14 },{9,14,16 },{9,16 },{9,18 },{9,18,4 },{9,18,12 },{9,18,20 },{9,18,28 },{9,20 },{9,22 },{9,26 },{9,26,4 },{9,26,12 },{9,26,20 },{9,26,28 },{9,28 },{9,30 },{10 },{10,4 },{10,4,16 },{10,12 },{10,12,16 },{10,16 },{10,20 },{10,28 },{11 },{11,4 },{11,4,16 },{11,12 },{11,12,16 },{11,16 },{11,20 },{11,28 },{12 },{12,16 },{13 },{13,2 },{13,2,16 },{13,6 },{13,6,16 },{13,10 },{13,10,16 },{13,14 },{13,14,16 },{13,16 },{13,18 },{13,22 },{13,26 },{13,30 },{14 },{14,16 },{15 },{15,16 },{16 },{17 },{17,2 },{17,2,4 },{17,2,4,8 },{17,2,4,24 },{17,2,8 },{17,2,12 },{17,2,20 },{17,2,20,8 },{17,2,20,24 },{17,2,24 },{17,2,28 },{17,4 },{17,4,8 },{17,4,24 },{17,6 },{17,6,8 },{17,6,24 },{17,8 },{17,10 },{17,10,4 },{17,10,12 },{17,10,20 },{17,10,28 },{17,12 },{17,14 },{17,18 },{17,18,4 },{17,18,4,8 },{17,18,4,24 },{17,18,8 },{17,18,12 },{17,18,20 },{17,18,20,8 },{17,18,20,24 },{17,18,24 },{17,18,28 },{17,20 },{17,20,8 },{17,20,24 },{17,22 },{17,22,8 },{17,22,24 },{17,24 },{17,26 },{17,26,4 },{17,26,12 },{17,26,20 },{17,26,28 },{17,28 },{17,30 },{18 },{18,4 },{18,4,8 },{18,4,24 },{18,8 },{18,12 },{18,20 },{18,20,8 },{18,20,24 },{18,24 },{18,28 },{19 },{19,4 },{19,4,8 },{19,4,24 },{19,8 },{19,12 },{19,20 },{19,20,8 },{19,20,24 },{19,24 },{19,28 },{20 },{20,8 },{20,24 },{21 },{21,2 },{21,2,8 },{21,2,24 },{21,6 },{21,6,8 },{21,6,24 },{21,8 },{21,10 },{21,14 },{21,18 },{21,18,8 },{21,18,24 },{21,22 },{21,22,8 },{21,22,24 },{21,24 },{21,26 },{21,30 },{22 },{22,8 },{22,24 },{23 },{23,8 },{23,24 },{24 },{25 },{25,2 },{25,2,4 },{25,2,12 },{25,2,20 },{25,2,28 },{25,4 },{25,6 },{25,10 },{25,10,4 },{25,10,12 },{25,10,20 },{25,10,28 },{25,12 },{25,14 },{25,18 },{25,18,4 },{25,18,12 },{25,18,20 },{25,18,28 },{25,20 },{25,22 },{25,26 },{25,26,4 },{25,26,12 },{25,26,20 },{25,26,28 },{25,28 },{25,30 },{26 },{26,4 },{26,12 },{26,20 },{26,28 },{27 },{27,4 },{27,12 },{27,20 },{27,28 },{28 },{29 },{29,2 },{29,6 },{29,10 },{29,14 },{29,18 },{29,22 },{29,26 },{29,30 },{30 },{31 }};


const int S = 374;
int trans[S][S];
int dp[S][2];

int insum(int & a, int b) {
    a = (a + b) % M;
}


void smain() {


    fori (i, S) {
        fori (j, S) {
            trans[i][j] = -1;
        }
    }
    for (int i = 0; i < all.size(); ++i) {
        auto x = all[i];
        for (int j = 0; j < all.size(); ++j) {
            auto y = all[j];
            vi kek = x;
            kek.insert(kek.end(), ALL(y));
            kek = norm(kek);
            if (!count(ALL(kek), 0)) {
                trans[i][j] = lower_bound(ALL(all), kek) - all.begin();
            }
        }
    }

    int n, m;
    cin >> n >> m;

    fori (i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(e.size());
        e.push_back({u, v, w});
        g[v].push_back(e.size());
        e.push_back({v, u, w});
    }


    for (auto id : g[1]) {
        forbid.insert(e[id].to);
    }
    forbid.insert(1);

    for (int id : g[1]) {
        int to = e[id].to;
        root = to;
        xr[to] = e[id].w;
        dfs(to, -1);
        sack[root] = norm(sack[root]);
    }

    set<int> did;
    int pr = 0, cr = 1;
    dp[0][0] = 1;

    for (int id : g[1]) {
        int v = e[id].to;
        if (did.count(v))
            continue;
        int u = -1;
        int mid;
        for (int id2 : g[v]) {
            int to = e[id2].to;
            if (forbid.count(to) && to != 1) {
                assert(u == -1);
                u = to;
                mid = e[id2].w;
            }
        }
        did.insert(v);
        if (u == -1) {
            fori (i, S) {
                dp[i][cr] = dp[i][pr];
            }
            if (!count(ALL(sack[v]), 0)) {
                int j = lower_bound(ALL(all), sack[v]) - all.begin();
                fori (i, S) {
                    if (trans[i][j] != -1) {
                        insum(dp[trans[i][j]][cr], dp[i][pr]);
                    }
                }
            }
            fori (i, S) {
                dp[i][pr] = 0;
            }
            swap(pr, cr);
            continue;
        }
        assert(!did.count(u));
        did.insert(u);
        vi kek = sack[v];
        kek.insert(kek.end(), ALL(sack[u]));
        kek = norm(kek);
        if (count(ALL(kek), 0)) {
            continue;
        }
        

        int j = lower_bound(ALL(all), kek) - all.begin();
        fori (i, S) {
            insum(dp[i][cr], dp[i][pr]);
            if (trans[i][j] != -1) {
                insum(dp[trans[i][j]][cr], dp[i][pr] * 2LL % M);
            }
        }
        kek.push_back(xr[u] ^ xr[v] ^ mid);
        kek = norm(kek);
        if (!count(ALL(kek), 0)) {
            j = lower_bound(ALL(all), kek) - all.begin();
            fori (i, S) {
                pii key = {i, j};
                if (trans[i][j] != -1) {
                    insum(dp[trans[i][j]][cr], dp[i][pr]);
                }
            }
        }
        fori (i, S){
            dp[i][pr] = 0;
        }
        swap(pr, cr);
    }
    int ans = 0;
    fori (i, S) {
        insum(ans, dp[i][pr]);
    }
    cout << ans;
}