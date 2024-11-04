

#define protected public
using iii  = int;
using yeee = iii;

#ifdef LOCAL
    const iii DEBUG = 10;
#else
    const iii DEBUG = -1;
#endif

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#if 0
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/detail/standard_policies.hpp>
    using namespace __gnu_pbds; template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; template<typename T1, typename T2> using hash_map = gp_hash_table<T1, T2>;
#endif

#define DBG(x) if(DEBUG >= x)
#define FOR(i, lo, hi) for(ll i = ll(lo); i < ll(hi); ++i)
#define ROF(i, hi, lo) for(ll i = ll(hi); i >= (ll)(lo); --i)
#define ALL(x) (x).begin(), (x).end()
#define len(x) ll((x).size())
#define PB push_back

#if 1
    #define DOUT(...) DOUTg(#__VA_ARGS__, __VA_ARGS__)
    template <typename T1> void DOUTf(ostringstream &os, int names_i, vector<string> &names, T1 &&val) { os << names[names_i] << " = " << val; } template <typename T1, typename... Ts> void DOUTf(ostringstream &os, int names_i, vector<string> &names, T1 &&val, Ts &&... vals) { os << names[names_i] << " = " << val << " | "; DOUTf(os, names_i + 1, names, vals...); } template <typename... Ts> string DOUTg(string names, Ts &&... vals) { string special = "()[]{}<>'\"\\"; vector<string> vnames; vnames.PB(""); vector<char> stak; for(char c : names) { bool inside_string = !stak.empty() && (stak.back() == '\'' || stak.back() == '\"'); if(c == '\n') c = ' '; if(c == ' ' && (vnames.back().empty() || (!inside_string && vnames.back().back() == ' '))) continue; if(stak.empty() && c == ',') { if(!vnames.back().empty() && vnames.back().back() == ' ') vnames.back().pop_back(); vnames.PB(""); continue; } vnames.back().PB(c); if(!stak.empty() && stak.back() == '\\') { stak.pop_back(); continue; } size_t p = special.find(c); bool closing = p < 8 && p % 2; if(p == string::npos) continue; if(p == special.size() - 1) { stak.PB(c); continue; } if(stak.empty()) { if(!closing) stak.PB(c); continue; } if(inside_string) { if(c == stak.back()) stak.pop_back(); continue; } if(closing) { if(stak.back() == special[p - 1]) stak.pop_back(); continue; } stak.PB(c); } ostringstream os; DOUTf(os, 0, vnames, vals...); return os.str(); }
    template <template <typename...> class Container, typename T, size_t DIMENSION> struct MultiDimensional { using internal = MultiDimensional<Container, T, DIMENSION - 1>; using type = Container<typename internal::type>; template <typename... Args> static type Generate(T def, const size_t size, Args... sizes) { return type(size, internal::Generate(def, sizes...)); } }; template <template <typename...> class Container, typename T> struct MultiDimensional<Container, T, 1> { using internal = T; using type = Container<T>; static type Generate(T def, const size_t size) { return type(size, def); } }; template <typename T, typename... Args> auto make_vector(T def, Args... sizes) -> typename MultiDimensional<std::vector, T, sizeof...(sizes)>::type { return MultiDimensional<std::vector, T, sizeof...(sizes)>::Generate( def, sizes...); }
#endif
 template <typename T> T get() { T x; cin >> x; return x; }  template <typename T1, typename T2> ostream &operator<<(ostream &out, const pair<T1, T2> &cont) { out << "(" << cont.first << ", " << cont.second << ")"; return out; }  template <typename T, typename Alloc> ostream &operator<<(ostream &out, const vector<T, Alloc> &cont) { for(auto it = cont.begin(); it != cont.end(); ++it) out << (it == cont.begin() ? "" : " ") << *it; return out; }  template <typename T, typename Alloc> ostream &operator<<(ostream &out, const deque<T, Alloc> &cont) { for(auto it = cont.begin(); it != cont.end(); ++it) out << (it == cont.begin() ? "" : " ") << *it; return out; }  template <typename T, typename Compare, typename Alloc> ostream &operator<<(ostream &out, const set<T, Compare, Alloc> &cont) { out << "{"; for(auto it = cont.begin(); it != cont.end(); ++it) out << (it == cont.begin() ? "" : ", ") << *it; out << "}"; return out; }  template <typename T, typename Compare, typename Alloc> ostream &operator<<(ostream &out, const multiset<T, Compare, Alloc> &cont) { out << "{"; for(auto it = cont.begin(); it != cont.end(); ++it) out << (it == cont.begin() ? "" : ", ") << *it; out << "}"; return out; }  template <typename Key, typename T, typename Compare, typename Alloc> ostream &operator<<(ostream &out, const map<Key, T, Compare, Alloc> &cont) { out << "{"; for(auto it = cont.begin(); it != cont.end(); ++it) out << (it == cont.begin() ? "" : ", ") << it->first << ":" << it->second; out << "}"; return out; }  template <typename Key, typename T, typename Compare, typename Alloc> ostream &operator<<(ostream &out, const multimap<Key, T, Compare, Alloc> &cont) { out << "{"; for(auto it = cont.begin(); it != cont.end(); ++it) out << (it == cont.begin() ? "" : ", ") << it->first << ":" << it->second; out << "}"; return out; }  template <typename T> ostream &operator<<(ostream &out, vector<vector<T>> cont) { for(auto it = cont.begin(); it != cont.end(); ++it) out << *it << "\n"; return out; }
using ll = long long; using lll = long long; using ull = unsigned long long; using ld = long double; using pll = pair<ll, ll>; using vb = vector<bool>; using vvb = vector<vb>; using vll = vector<ll>; using vvll = vector<vll>; using vpll = vector<pll>; using point = complex<ld>;
ld get_time() { return ld(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()) / 1e9; } ll sign(ld x) { return (x > 0) - (x < 0); } ll fmod(ll x, ll mod) { if(!mod) return x; if(abs(x) >= mod) x %= mod; if(x < 0) x += mod; return x; } ll pow(ll x, ll exp, ll mod) { ll res = 1, y = x; while(exp) { if(!mod) { if(exp & 1) res = res * y; y = y * y; } else { if(exp & 1) res = fmod(res * y, mod); y = fmod(y * y, mod); } exp >>= 1; } return res; }
ld START_TIME = get_time(); mt19937_64 rand_mt64(chrono::steady_clock::now().time_since_epoch().count()); mt19937 rand_mt(chrono::steady_clock::now().time_since_epoch().count()); const long long INFll = ll(1.1e18) - 1; const int INFi = ll(1.1e9) - 1; ll INF = sizeof(ll) == sizeof(int) ? ll(INFi) : ll(INFll); char newl = '\n';
void main_init(string input_file = "", string output_file = "", bool fast_cio = true) { srand(unsigned(time(0))); if(fast_cio) { ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); } DBG(0 && input_file != "") freopen(input_file.c_str(), "r", stdin); DBG(0 && output_file != "") freopen(output_file.c_str(), "w", stdout); }



const ll MAX_N = 1.1e5;

struct Intervalac {
    ll N;
    vll big, big_n, big2, sum, lazy;
    vpll bound;

    Intervalac(ll n) {
        N = 1;
        while(N / 2 < n)
            N *= 2;

        big.resize(N, 0);
        big_n.resize(N, 0);
        big2.resize(N, 0);
        sum.resize(N, 0);
        lazy.resize(N, INF);
        bound.resize(N);

        FOR(i, 0, N / 2)
            bound[N / 2 + i] = {i, i + 1};
        ROF(i, N / 2 - 1, 0)
            bound[i] = {bound[i * 2].first, bound[i * 2 + 1].second};
        FOR(i, 0, N)
            big_n[i] = bound[i].second - bound[i].first;
    }

    void push_down(ll curr) {
        if(curr >= N || lazy[curr] == INF)
            return;
        if(big[curr] > lazy[curr]) {
            sum[curr] -= (big[curr] - lazy[curr]) * big_n[curr];
            big[curr] = lazy[curr];

            if(curr < N / 2) {
                FOR(i, 0, 2)
                    lazy[curr * 2 + i] = min(lazy[curr * 2 + i], lazy[curr]);
            }
        }
        lazy[curr] = INF;
    }

    void push_up(ll curr, bool recur = false) {
        FOR(i, 0, 2)
            push_down(curr * 2 + i);
        if(curr == 0 || curr >= N / 2)
            return;
        if(big[curr * 2] == big[curr * 2 + 1]) {
            big[curr] = big[curr * 2];
            big_n[curr] = big_n[curr * 2] + big_n[curr * 2 + 1];
            big2[curr] = max(big2[curr * 2], big2[curr * 2 + 1]);
        } else if(big[curr * 2] > big[curr * 2 + 1]) {
            big[curr] = big[curr * 2];
            big_n[curr] = big_n[curr * 2];
            big2[curr] = max(big2[curr * 2], big[curr * 2 + 1]);
        } else if(big[curr * 2] < big[curr * 2 + 1]) {
            big[curr] = big[curr * 2 + 1];
            big_n[curr] = big_n[curr * 2 + 1];
            big2[curr] = max(big[curr * 2], big2[curr * 2 + 1]);
        }
        sum[curr] = sum[curr * 2] + sum[curr * 2 + 1];
        if(recur)
            push_up(curr / 2, recur);
    }

    void set(ll curr, ll v) {
        curr += N / 2;
        big[curr] = v;
        big_n[curr] = 1;
        sum[curr] = v;
        lazy[curr] = INF;
        push_up(curr / 2, true);
    }

    ll get(ll curr, ll lo, ll hi) {
        push_down(curr);
        if(bound[curr].first >= hi || bound[curr].second <= lo ||
           big[curr] == INF)
            return 0;
        else if(bound[curr].first >= lo && bound[curr].second <= hi)
            return sum[curr];
        else
            return get(curr * 2, lo, hi) + get(curr * 2 + 1, lo, hi);
    }

    void update(ll curr, ll lo, ll hi, ll d) {
        push_down(curr);
        if(bound[curr].first >= hi || bound[curr].second <= lo ||
           big[curr] <= d)
            return;
        else if(bound[curr].first >= lo && bound[curr].second <= hi &&
                big2[curr] <= d) {
            lazy[curr] = d;
            push_down(curr);
        } else {
            update(curr * 2, lo, hi, d);
            update(curr * 2 + 1, lo, hi, d);
        }
        push_up(curr);
    }
};

struct IntervalacB {
    ll N, M;
    vvll val;
    vpll bound;

    IntervalacB(ll n, ll m) {
        M = m;
        N = 1;
        while(N / 2 < n)
            N *= 2;

        val.resize(N, vll(M, 0));
        bound.resize(N);
        FOR(i, 0, N / 2)
            bound[N / 2 + i] = {i, i + 1};
        ROF(i, N / 2 - 1, 0)
            bound[i] = {bound[i * 2].first, bound[i * 2 + 1].second};
    }

    void update(ll curr, ll t, ll d) {
        curr += N / 2;
        while(curr) {
            val[curr][t] += d;
            curr /= 2;
        }
    }

    ll find(ll curr, ll lo, ll hi, ll d) {
        if(bound[curr].first >= hi || bound[curr].second <= lo ||
           val[curr][d] == 0)
            return -1;
        if(bound[curr].second - bound[curr].first == 1)
            return bound[curr].first;
        ll res = -1;
        ROF(i, 1, 0)
            if((res = find(curr * 2 + i, lo, hi, d)) != -1)
                return res;
        return res;
    }
};

struct IntervalacM {
    ll N;
    vll val, lazy;
    vpll bound;

    IntervalacM(ll n) {
        N = 1;
        while(N / 2 < n)
            N *= 2;

        val.resize(N, INF);
        lazy.resize(N, INF);
        bound.resize(N);
        FOR(i, 0, N / 2)
            bound[N / 2 + i] = {i, i + 1};
        ROF(i, N / 2 - 1, 0)
            bound[i] = {bound[i * 2].first, bound[i * 2 + 1].second};
    }

    void push_down(ll curr) {
        if(lazy[curr] == INF)
            return;
        val[curr] = min(val[curr], lazy[curr]);
        if(curr < N / 2) {
            FOR(i, 0, 2)
                lazy[curr * 2 + i] = min(lazy[curr * 2 + 1], lazy[curr]);
        }
        lazy[curr] = INF;
    }

    void push_up(ll curr) {
        push_down(curr);
        if(curr < N / 2) {
            push_down(curr * 2);
            push_down(curr * 2 + 1);
            val[curr] = min(val[curr * 2], val[curr * 2 + 1]);
        }
    }

    void update(ll curr, ll lo, ll hi, ll d) {
        push_down(curr);
        if(bound[curr].first >= hi || bound[curr].second <= lo)
            return;
        else if(bound[curr].first >= lo && bound[curr].second <= hi)
            lazy[curr] = d;
        else {
            FOR(i, 0, 2)
                update(curr * 2 + i, lo, hi, d);
        }
        push_up(curr);
    }

    ll get(ll curr, ll lo, ll hi) {
        push_down(curr);
        if(bound[curr].first >= hi || bound[curr].second <= lo)
            return INF;
        else if(bound[curr].first >= lo && bound[curr].second <= hi)
            return val[curr];
        else
            return min(get(curr * 2, lo, hi), get(curr * 2 + 1, lo, hi));
    }
};

yeee main() {
    main_init();
    


    ll TC;
    cin >> TC;

    vector<Intervalac> I(2, Intervalac(MAX_N));
    vector<IntervalacM> Im(2, IntervalacM(MAX_N));
    IntervalacB Ib(MAX_N, 4);
    FOR(i, 0, Ib.N / 2)
        Ib.update(i, 0, 1);

    while(TC--) {
        ll qt, lo, hi;
        cin >> qt >> lo >> hi;

        if(qt == 2) {
            cout << I[0].get(1, lo, hi) + I[1].get(1, lo, hi) << newl;
        } else {
            ll y;
            cin >> y;

            ll t = y > 0;
            y = abs(y);
            Im[t].update(1, lo, hi, y);

            for(ll f : vll{0, 1 << (!t)}) {
                ll f2 = f + (1 << t);
                ll fi;
                while((fi = Ib.find(1, lo, hi, f)) != -1) {
                    Ib.update(fi, f, -1);
                    Ib.update(fi, f2, 1);
                    if(f2 == 3) {
                        FOR(i, 0, 2)
                            I[i].set(fi, Im[i].get(1, fi, fi + 1));
                    }
                }
            }
            I[t].update(1, lo, hi, y);
        }
    }
}
