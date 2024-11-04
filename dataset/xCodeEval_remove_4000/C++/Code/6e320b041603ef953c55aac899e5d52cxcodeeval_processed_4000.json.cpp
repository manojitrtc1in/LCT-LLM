

using namespace std;

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
typedef map<int, int> mii;




























template<class T>
void id0(T &found, T a, T b, function<bool(T)> test, bool TF = true) {
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






template<class T>
void re(T &x) { cin >> x; }

void re(db &d) {
    str t;
    re(t);
    d = stod(t);
}

void re(ld &d) {
    str t;
    re(t);
    d = stold(t);
}

template<class H, class... T>
void re(H &h, T &... t) {
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
void re(pair<A, B> &p) { re(p.first, p.second); }

template<class A>
void re(vector<A> &x) { trav(a, x) re(a); }

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
    id7(i, sz(v)) res += char('0' + v[i]);
    res += "}";
    return res;
}

template<size_t SZ>
str ts(bitset<SZ> b) {
    str res = "";
    id7(i, SZ) res += char('0' + b[i]);
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
            id7(i, sz(from) - size / 2) {
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
        id7(from, sz(adj)) {
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

            queue<pair<int, unit>> todo;
            todo.emplace(src, -1);
            while (not todo.empty()) {
                int from = todo.front().first;
                unit id2 = todo.front().second;
                todo.pop();
                if (from == drn) {
                    found = true;
                    break;
                }
                trav(to, adj[from]) {
                    pi edge = mp(from, to);
                    unit bn = min(id2, lims[edge]);
                    if (bn and not seen.count(to)) {
                        seen.emplace(to);
                        todo.emplace(to, bn);
                        backtrack[to] = mp(edge, bn);
                    }
                }

                trav(to, radj[from]) {
                    pi edge = mp(to, from);
                    unit bn = min(id2, rlims[edge]);
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
                list<pi> edges;
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
class id6 {
public:
    vector<vi> pow2ranks;
    int loop;
    int n;

    id6() {}

    id6(vector<T> &in, int loop_) {
        reset(in, loop_);
    }

    id6(string &in, int loop_) {
        vector<T> cached;
        trav(c, in)cached.emplace_back(c);
        reset(cached, loop_);
    }

    void reset(string &in, int loop_) {
        vector<T> cached;
        trav(c, in)cached.emplace_back(c);
        reset(cached, loop_);
    }

    void reset(vector<T> &in, int loop_) {
        loop = loop_, n = in.size();
        pow2ranks.clear();
        {
            vector<pair<T, int>> initial;
            map<T, queue<int>> shelf;
            id7(i, n)shelf[in[i]].emplace(i);
            for (pair<const T, queue<int>> &kv:shelf) {
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
        vector<queue<pair<pi, int>>> shelf(n);
        while (sz < n) {
            int newpow = pow + 1, newsz = sz * 2;
            pow2ranks.emplace_back(), pow2ranks.back().resize(n);
            auto &oldrank = pow2ranks[pow], &newrank = pow2ranks[newpow];
            vector<pair<pi, int>> id4;
            id7(i, n) {
                int j = i + sz, excess = max(j - n + 1, 0);
                j -= ((excess % loop > 0) + (excess / loop)) * loop;
                id4.emplace_back(mp(mp(oldrank[i], oldrank[j]), i));
            }
            trav(e, id4) shelf[e.first.second].emplace(e);
            id4.clear();
            trav(block, shelf)while (not block.empty()) {
                    auto e = block.front();
                    block.pop();
                    id4.emplace_back(e);
                }
            trav(e, id4) shelf[e.first.first].emplace(e);
            id4.clear();
            trav(block, shelf)while (not block.empty()) {
                    auto e = block.front();
                    block.pop();
                    id4.emplace_back(e);
                }
            int uid = 0;
            pi val = id4[0].first;
            trav(e, id4) {
                if (val < e.first)uid++;
                newrank[e.second] = uid, val = e.first;
            }
            pow = newpow, sz = newsz;
        }
    }

    int sanitize(int i) {
        int excess = max(i - n + 1, 0);
        i -= ((excess % loop > 0) + (excess / loop)) * loop;
        return i;
    }

    pair<int, int> query(int i, int len = -1) {
        i = sanitize(i);
        if (len == -1) {
            return mp(pow2ranks.back()[i], pow2ranks.back()[i]);
        }
        if (len == 0) {
            return mp(0, 0);
        }
        else {
            int sz = 1, pow = 0;
            while (sz * 2 < len)sz *= 2, pow++;
            int j = sanitize(i + len - sz);
            return mp(pow2ranks[pow][i], pow2ranks[pow][j]);
        }
    }
};


auto id3 = chrono::high_resolution_clock::now();

void tic() {
    id3 = chrono::high_resolution_clock::now();
}

void toc() {
    ps(chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - id3).count(), "us");
    cout << endl;
}

void precalc() {
    

}




void solve(int ti) {
    

    int n;
    re(n);
    id6<char> id5;
    vi startat(n, 0);
    vector<string> id1;

    def(cmp, bool, (pi & a, pi & b), &) {
        int pa = startat[a.first], pb = startat[b.first];
        int lena = id1[a.first].length() - 1, lenb = id1[b.first].length() - 1;
        set<int> kill;
        if (a.second != -1)kill.emplace(a.second), lena--;
        if (b.second != -1)kill.emplace(b.second), lenb--;
        int len = max(lena, lenb);
        int last = 0;
        string &dbg1 = id1[a.first], &dbg2 = id1[b.first];
        while (not kill.empty()) {
            int next = *kill.begin();
            kill.erase(next);
            auto qa = id5.query(pa, next - last), qb = id5.query(pb, next - last);
            int result;
            if (qa == qb)result = 0;
            if (qa < qb)result = 1;
            if (qa > qb)result = -1;
            len -= next - last;
            if (result != 0)
                return result > 0;
            else {
                pa += next - last + (a.second == next);
                pb += next - last + (b.second == next);
                last = next;
            }
        }
        auto qa = id5.query(pa, len), qb = id5.query(pb, len);
        return qa < qb;
    };
    
    vector<vpi> premerge;

    id7(i, n) {
        string s;
        re(s);
        s += CHAR_MIN;
        id1.emplace_back(s);

        id5.reset(s, s.length());

        premerge.emplace_back();
        id7(j, s.length()) {
            premerge.back().emplace_back(i, j - 1);
        }
        auto &block = premerge.back();
        sort(all(block), cmp);


    }


    vl possible(id1.back().length(),1);
    r0f(i, n - 1) {
        string mergedin = id1[i];
        startat[i] = 0, startat[i + 1] = mergedin.size();
        mergedin += id1[i + 1];
        id5.reset(mergedin, mergedin.size());
        vl next_possible(id1[i].length());
        vpi &left = premerge[i], &right = premerge[i + 1];
        vector<pi> merged;

        auto ptrl = left.begin(), ptrr = right.begin();
        while (ptrl != left.end() or ptrr != right.end()) {
            bool chooseright = false;
            if (ptrl == left.end())chooseright = true;
            if (not chooseright and ptrl != left.end() and ptrr != right.end() and cmp(*ptrr, *ptrl))
                chooseright = true;
            if (chooseright)
                merged.emplace_back(*ptrr), ptrr++;
            else
                merged.emplace_back(*ptrl), ptrl++;
        }

        

        ll accum = 0;
        r0f(j, merged.size()) {
            auto e = merged[j];
            int idx = modop(e.second, (int) id1[e.first].length());
            if (e.first == i + 1)
                accum = modop(accum + (i == n - 2 ? 1 : possible[idx]));
            else
                next_possible[idx] = accum;
        }
        

        swap(possible, next_possible);
    }
    ll ans = 0;
    trav(e, possible)ans = modop(ans + e);
    ps(ans);
}

int main() {
    precalc();
    bool online = true;

    online = false;
    if (online)
        boost();
    string testinputs[] = {
            R"(
1
aaaaaa
)",












    };

    trav(testinput, testinputs) {
        istringstream iss(testinput);
        cout << "---local mode---" << endl;
        cin.rdbuf(iss.rdbuf());

        

        int T = 1;
        {


        }
        vfor(i, 1, T + 1) {


            solve(i);
        }


    }

}