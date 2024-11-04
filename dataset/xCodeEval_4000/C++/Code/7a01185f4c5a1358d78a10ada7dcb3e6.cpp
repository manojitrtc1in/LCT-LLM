using namespace std;

#include <bits/stdc++.h>


typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

typedef set<int> si;
typedef set<ll> sl;
typedef list<int> li;
typedef map<int, int> mii;

#define mp make_pair
#define sz(x) (int)x.size()
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define eb emplace_back
#define ep emplace
#define lb lower_bound
#define ub upper_bound

#define vfor(i, a, b) for (int i = (a); i < (b); ++i)
#define f0r(i, a) vfor(i,0,a)
#define f1r(i, a) vfor(i,1,a)
#define rof(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define r0f(i, a) rof(i,0,a)
#define trav(a, x) for (auto& a: x)
#define def(fname, rtype, args, ...) function<rtype args> fname = [__VA_ARGS__] args

#define boost() cin.tie(0),cin.sync_with_stdio(0)

template<class T>
void binstf(T &found, T a, T b, function<bool(T)> test, bool TF = true) {
    T i = a, j = b;
    bool da = test(a), db = test(b);
    if ((da != TF) or (db == TF)) {
        cerr << "---[BS: TF = " << TF << "]---" << endl;
        cerr << a << "->" << da << endl;
        cerr << b << "->" << db << endl;
    }
    while (j - i > 1) {
        T m = (i + j) / 2;
        if (test(m) == TF)
            i = m;
        else
            j = m;
    }
    found = i;
    if (not TF)
        found++;
}

template<class T>
void binsft(T &a, T b, T c, function<bool(T)> d) {
    binstf(a, b, c, d, false);
}

template<class T>
T dpow(T a, T power) {
    T result = 1;
    while (power) {
        if (power % 2)result *= a;
        power /= 2, a = a * a;
    }
    return result;
}

const ld PI = acos((ld) -1);
mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

template<class T>
bool ckmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
}

template<class T>
bool ckmax(T &a, const T &b) {
    return a < b ? a = b, 1 : 0;
}

template<class T>
bool reorder(T &a, T &b) {
    return (a > b) ? swap(a, b), 1 : 0;
}



template<class A>
void re(complex<A> &c);

template<class A, class B>
void re(pair<A, B> &p);

template<class A>
void re(vector<A> &v);

template<class A, size_t SZ>
void re(array<A, SZ> &a);

#define ore(type, x) type x;re(x);
#define ire(x) ore(int,x);
#define vire(x) ore(vi,x);
#define lre(x) ore(ll,x);


#ifndef OFFLINE

inline void re(int &x) { scanf("%d", &x); }

inline void re(char &c) {
    char c2[10];
    scanf("%s", &c2);
    c = c2[0];
}

inline void re(ll &x) { scanf("%lld", &x); }

inline void re(pi &e) { scanf("%d %d", &e.first, &e.second); }

inline void re(pl &e) { scanf("%lld %lld", &e.first, &e.second); }

inline void re(char x[10]) {
    char y[10];
    scanf("%s ", &y);
    for (int i = 0; i < 10; i++)
        if (y[i] == '\0')break;
        else x[i] = y[i];
}


#endif

template<class T>
inline void re(T &x) { cin >> x; }

inline void re(db &d) {
    str t;
    re(t);
    d = stod(t);
}

inline void re(ld &d) {
    str t;
    re(t);
    d = stold(t);
}

template<class H, class... T>
inline void re(H &h, T &... t) {
    re(h);
    re(t...);
}

template<class A>
void re(complex<A> &c) {
    A a, b;
    re(a, b);
    c = {a, b};
}

template<class A, class B>
inline void re(pair<A, B> &p) { re(p.first, p.second); }

template<class A>
inline void re(vector<A> &x) { trav(a, x) re(a); }

template<class A, size_t SZ>
void re(array<A, SZ> &x) { trav(a, x) re(a); }

template<class T>
T gcd(T a, T b) {
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    if (a * b == 0)
        return max(a, b);
    else return gcd(min(a, b), max(a, b) % min(a, b));
}


const int MODE107 = 1000000007;

template<class T>
T modop(T a, T mode = MODE107) {
    a = a % mode;
    if (a < 0)a += mode;
    return a;
}

template<class T>
T inv(T a, T mode = MODE107) {
    T coefa = 1, coefb = 0;
    T aa = a, bb = mode;
    while (aa != 1) {
        if (aa > bb)swap(coefa, coefb), swap(aa, bb);
        T cc = bb / aa;
        bb -= cc * aa, coefb -= cc * coefa;
        swap(coefa, coefb), swap(aa, bb);
    }
    return coefa;
}


const int uplrDX[] = {-1, 1, 0, 0};
const int uplrDY[] = {0, 0, -1, 1};

#define ts to_string

str ts(char c) { return str(1, c); }

str ts(bool b) { return b ? "true" : "false"; }

str ts(const char *s) { return (str) s; }

str ts(str s) { return s; }

template<class A>
str ts(complex<A> c) {
    stringstream ss;
    ss << c;
    return ss.str();
}

str ts(vector<bool> v) {
    str res = "{";
    f0r(i, sz(v)) res += char('0' + v[i]);
    res += "}";
    return res;
}

template<size_t SZ>
str ts(bitset<SZ> b) {
    str res = "";
    f0r(i, SZ) res += char('0' + b[i]);
    return res;
}

template<class A, class B>
str ts(pair<A, B> p);

template<class T>
str ts(T v) { 

    bool fst = 1;
    str res = "{";
    for (const auto &x: v) {
        if (!fst) res += ", ";
        fst = 0;
        res += ts(x);
    }
    res += "}";
    return res;
}

template<class A, class B>
str ts(pair<A, B> p) {
    return "(" + ts(p.first) + ", " + ts(p.second) + ")";
}



template<class A>
void pr(A x) { cout << ts(x); }

template<class H, class... T>
void pr(const H &h, const T &... t) {
    pr(h);
    pr(t...);
}

void ps() { pr("\n"); } 

template<class H, class... T>
void ps(const H &h, const T &... t) {
    pr(h);
    if (sizeof...(t)) pr(" ");
    ps(t...);
}



void DBG() { cerr << "]" << endl; }

template<class H, class... T>
void DBG(H h, T... t) {
    cerr << ts(h);
    if (sizeof...(t)) cerr << ", ";
    DBG(t...);
}

#ifdef LOCAL 

#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif







typedef int T;

int sgn(T a) { return (a > 0) - (a < 0); }

T sq(T a) { return a * a; }




typedef unsigned long long ull;

class trie {
public:
    map<char, trie> l;

    void add(string t) {
        if (t.length() > 0) {
            l[t[0]].add(t.substr(1));
        }
    }

    bool contains(string t) {
        if (not l.count(t[0]))
            return false;
        return l[t[0]].contains(t.substr(1));
    }
};

template<class T>
class rq {
    
    vector<vector<T>> content;
    function<T(T, T)> op;

public:
    rq(vector<T> &orig, function<T(T, T)> operation) {
        op = operation;
        int size = 1;
        content.emplace_back(orig);
        while (size < orig.size()) {
            size *= 2;
            content.emplace_back(0);
            auto &todo = content.back(), &from = content[content.size() - 2];
            f0r(i, sz(from) - size / 2) {
                todo.eb(op(from[i], from[i + size / 2]));

            }
        }
    }

    T query(int i, int j) {

        if (j <= i or j > content[0].size() or i < 0 or i >= content[0].size()) {
            cerr << "i=" << i << endl;
            cerr << "j=" << j << endl;
            throw "bad i j";
        }
        tie(i, j) = mp(min(i, j), max(i, j));
        int size = 1, pow = 0;
        while (size * 2 < j - i) {
            size *= 2, pow++;
        }
        assert(pow < content.size());
        auto &c = content[pow];
        assert(i < c.size() and i >= 0);
        assert(j - size < c.size() and j - size >= 0);
        T dbg = op(content[pow][i], content[pow][j - size]);
        return dbg;
    }
};

template<class T>
class maxflow {
public:
    typedef T unit;
    int src, drn;

    vector<vi> adj, radj;
    map<pi, unit> lims;
    map<pi, unit> rlims;

    void genradj() {
        radj.resize(sz(adj));
        f0r(from, sz(adj)) {
            trav(to, adj[from]) {
                radj[to].emplace_back(from);
            }
        }
    }

    unit solve() {
        while (true) {
            map<int, pair<pi, unit>> backtrack;
            bool found = false;
            set<int> seen;

            queue <pair<int, unit>> todo;
            todo.emplace(src, -1);
            while (not todo.empty()) {
                int from = todo.front().first;
                unit bottleneck = todo.front().second;
                todo.pop();
                if (from == drn) {
                    found = true;
                    break;
                }
                trav(to, adj[from]) {
                    pi edge = mp(from, to);
                    unit bn = min(bottleneck, lims[edge]);
                    if (bn and not seen.count(to)) {
                        seen.emplace(to);
                        todo.emplace(to, bn);
                        backtrack[to] = mp(edge, bn);
                    }
                }

                trav(to, radj[from]) {
                    pi edge = mp(to, from);
                    unit bn = min(bottleneck, rlims[edge]);
                    if (bn and not seen.count(to)) {
                        seen.emplace(to);
                        todo.emplace(to, bn);
                        backtrack[to] = mp(edge, bn);
                    }
                }
            }
            if (not found)
                break;
            else {
                list <pi> edges;
                int to = drn;
                unit flow = backtrack[to].second;
                while (to != src) {
                    pi edge = backtrack[to].first;
                    int from = edge.first + edge.second - to;
                    edges.emplace_front(edge);
                    to = from;
                }
                int from = src;
                trav(e, edges) {
                    if (e.first == from)
                        rlims[e] += flow, lims[e] -= flow;
                    else
                        rlims[e] -= flow, lims[e] += flow;
                    from = e.first + e.second - from;
                }
            }
        }
        unit res = 0;
        trav(to, adj[src])res += rlims[mp(src, to)];
        return res;
    }

};

template<class T>
class SuffArr {
public:
    vector<vi> pow2ranks;
    int loop;
    int n;

    SuffArr() {}

    SuffArr(vector<T> &in, int loop_) {
        reset(in, loop_);
    }

    SuffArr(string &in, int loop_) {
        vector <T> cached;
        trav(c, in)cached.emplace_back(c);
        reset(cached, loop_);
    }

    void reset(string &in, int loop_) {
        vector <T> cached;
        trav(c, in)cached.emplace_back(c);
        reset(cached, loop_);
    }

    void reset(vector<T> &in, int loop_) {

        loop = loop_, n = in.size();
        pow2ranks.clear();
        {
            vector <pair<T, int>> initial;
            map <T, queue<int>> shelf;
            f0r(i, n)shelf[in[i]].emplace(i);

            for (pair<const T, queue < int>> &kv:shelf) {
                auto &block = kv.second;
                while (not block.empty())
                    initial.emplace_back(kv.first, block.front()), block.pop();
            }
            int uid = 0, val = initial[0].first;
            pow2ranks.emplace_back(), pow2ranks.back().resize(n);
            trav(e, initial) {

                if (val < e.first)uid++;
                pow2ranks[0][e.second] = uid, val = e.first;
            }
        }
        int pow = 0, sz = 1;
        vector < queue < pair < pi, int>>> shelf(n);

        while (sz < n) {

            int newpow = pow + 1, newsz = sz * 2;
            pow2ranks.emplace_back(), pow2ranks.back().resize(n);
            auto &oldrank = pow2ranks[pow], &newrank = pow2ranks[newpow];
            vector <pair<pi, int>> tobesorted;
            f0r(i, n) { 

                int j = sanitize(i + sz);
                tobesorted.emplace_back(mp(mp(oldrank[i], oldrank[j]), i));
            }
            trav(e, tobesorted) shelf[e.first.second].emplace(e);

            tobesorted.clear();
            trav(block, shelf)while (not block.empty()) {
                    auto e = block.front();
                    block.pop();
                    tobesorted.emplace_back(e);
                }
            trav(e, tobesorted) shelf[e.first.first].emplace(e);

            tobesorted.clear();
            trav(block, shelf)while (not block.empty()) {
                    auto e = block.front();
                    block.pop();
                    tobesorted.emplace_back(e);
                }
            int uid = 0;
            pi val = tobesorted[0].first;
            trav(e, tobesorted) {
                if (val < e.first)uid++;
                newrank[e.second] = uid, val = e.first;
            }
            pow = newpow, sz = newsz;
        }
    }

    inline int sanitize(int i) {
        int excess = max(i - n + 1, 0);
        i -= ((excess % loop > 0) + (excess / loop)) * loop;
        return i;
    }

    inline pair<int, int> query(int i, int len = -1) {

        i = sanitize(i);
        if (len == -1) {
            return mp(pow2ranks.back()[i], pow2ranks.back()[i]);
        }
        if (len == 0) {
            return mp(0, 0);
        } else {
            int sz = 1, pow = 0;
            while ((sz << 1) < len)sz = sz << 1, pow++;

            int j = sanitize(i + len - sz);
            return mp(pow2ranks[pow][i], pow2ranks[pow][j]);
        }
    }
};


auto __tic__ = chrono::high_resolution_clock::now();

void tic() {
    __tic__ = chrono::high_resolution_clock::now();
}

int toc() {
    int elapsed = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - __tic__).count();
    return elapsed;
}

void precalc() {
    

}






void solve(int ti) {
    

    int n;
    re(n);
    vl as(n);
    re(as);
    sort(all(as));
    vi prev(n, 0);
    f0r(i, n) {
        def(temp, bool, (int j), &) {
            if (j == n) return false;
            bool ans = j - 1 < 0 or 2 * as[j - 1] <= as[i];
            return ans;
        };
        binstf(prev[i], 0, n, temp);
    }
    vl fac = {1};
    vl ifac = {1};
    ll prime = 998244353;
    while (sz(fac) != n + 1) {
        fac.eb(modop(fac.back() * sz(fac), prime));
        ifac.eb(inv(fac.back(), prime));
    }
    vl cs = {1};
    vector <vl> bss(1, {1});
    f0r(i, n) {
        vl &bs = bss[prev[i]];
        vl nextbs = bss[i];
        vl nextcs = {0};
        if (sz(nextbs) != i + 2)
            nextbs.resize(i + 2);
        for (int s = 1; s <= i + 1; s++) {
            ll c_s = modop(nextcs.back() * (prev[i] + 2 - s) + ((s - 1 < sz(bs)) ? bs[s - 1] : 0), prime);
            nextbs[s] += c_s;
            nextcs.eb(c_s);
        }
        bss.eb(move(nextbs));
        swap(nextcs, cs);
    }
    ps(cs.back());

}

int main() {
    precalc();
    bool online = true;
#ifdef OFFLINE
    online = false;
    if (online)
        boost();
    string testinputs[] = {
            R"(51
410302106 708701895 820706056 319931052 87747886 427597767 380552276 441953043 627914953 659947840 374682702 32848823 733202611 778681308 386357954 194288786 550477660 271692803 659482338 843663264 766955734 740521063 625128385 445902179 406562646 306581113 777253591 335751008 653724087 196164337 107364480 605885600 953592822 341251658 213009532 18475568 302548407 127161667 282013297 361588641 228056767 593913695 407864420 508454792 126564216 262582118 867640132 551470079 89634672 597318626 168202079

)",












    };

    trav(testinput, testinputs) {
        istringstream iss(testinput);
        cout << "---local mode---" << endl;
        cin.rdbuf(iss.rdbuf());
#endif
        

        int T = 1;
        {


        }
        vfor(i, 1, T + 1) {


            solve(i);
        }

#ifdef OFFLINE
    }
#endif
}