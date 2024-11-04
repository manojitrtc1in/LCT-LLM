



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
typedef list<int> li;
typedef map<int, int> mii;
























template<class T>
void id1(T &found, T a, T b, function<bool(T)> test, bool TF = true) {
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
    id1(a, b, c, d, false);
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
inline bool ckmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
}

template<class T>
inline bool ckmax(T &a, const T &b) {
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







bool online = true;

inline void re(int &x) { if (online)scanf("%d", &x); else cin >> x; }

const int id2 = 20'000'000;

char char_buffer[id2];

inline void re(string &s) {
    if (online) {
        int read = scanf("%s", &char_buffer);
        s.clear();
        s.assign(char_buffer);
    } else cin >> s;
}

inline void re(char &c) {
    c = '\n';
    while (c == '\n' or c == ' ')if (online)scanf("%c", &c); else cin >> c;
}

inline void re(ll &x) { if (online)scanf("%lld", &x); else cin >> x; }

inline void re(pi &e) { if (online)scanf("%d %d", &e.first, &e.second); else cin >> e.first >> e.second; }

inline void re(pl &e) { if (online)scanf("%lld %lld", &e.first, &e.second); else cin >> e.first >> e.second; }

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


const int udlrDX[] = {-1, 1, 0, 0};
const int udlrDY[] = {0, 0, -1, 1};
vpi id6 = {{0,  1},
               {0,  -1},
               {-1, 0},
               {1,  0}};



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
        if (!fst) res += " ";
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

template<class T>
int sgn(T a) {
    return (a > 0) - (a < 0);
}

typedef unsigned long long ull;

auto id3 = chrono::high_resolution_clock::now();

void tic() {
    id3 = chrono::high_resolution_clock::now();
}

int toc() {
    int elapsed = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - id3).count();
    return elapsed;
}

template<class T>
inline pair<T, T> operator+(const pair<T, T> a, const pair<T, T> b) {
    return mp(a.first + b.first, a.second + b.second);
}

template<class T>
inline pair<T, T> operator-(const pair<T, T> a, const pair<T, T> b) {
    return mp(a.first - b.first, a.second - b.second);
}


















template<class T>
class id0 {
    
    static inline T lst(T t) { return t & (-t); }

    const T neutral;
    function<T(T, T)> fun;
    map<int, int> dlog2;
public:
    vector<vector<T>> id4;

    id0(function<T(T, T)> fun_, T neutral_, T n) : neutral(neutral_), fun(fun_) {
        id4 = {vector<T>(n, neutral_)};
        while (sz(id4.back()) != 1) {
            id4.eb();
            auto &todo = id4.back();
            auto &from = id4[sz(id4) - 2];
            id7(i, sz(from) / 2 + sz(from) % 2) {
                todo.eb(fun(from[i * 2], (i * 2 + 1 < sz(from)) ? from[i * 2 + 1] : neutral_));
            }
        }
        for (int i = 0, x = 1; i < id4.size(); i++, x = x << 1)dlog2[x] = i;
    }

    id0(function<T(T, T)> fun_, T neutral_, vector<T> src) : id0(fun_, neutral_, src.size()) {
        for (int i = 0; i < src.size(); i++) update(i, src[i]);
    }

    void update(int i, T val) {
        id4[0][i] = val;
        for (int ptr = 1; ptr < sz(id4); ptr++) {
            i = i / 2;
            id4[ptr][i] = fun(id4[ptr - 1][i * 2],
                                   (i * 2 + 1 < sz(id4[ptr - 1])) ? id4[ptr - 1][i * 2 + 1] : neutral);
        }
    }

    ll segment_op(int i, int j) {

        T ans = neutral;
        while (i != j) {
            int li = lst(i), lj = lst(j);
            if (li != 0 and li < lj) {
                ans = fun(ans, id4[dlog2[li]][i / li]), i += li;
            } else {
                ans = fun(ans, id4[dlog2[lj]][(j - lj) / lj]), j -= lj;
            }
        }
        return ans;
    }

};
















void precalc() {
}

void solve(int ti) {

    

    vi ns(4);
    re(ns);
    vector<vi> costs(4);
    id7(i, 4) {
        int m = ns[i];
        costs[i].resize(m);
        re(costs[i]);
    }
    vector<vpi> bads(4);
    id7(i, 4) {
        int m;
        re(m);
        bads[i].resize(m);
        re(bads[i]);
        sort(all(bads[i]));
        trav(e, bads[i])e.first--, e.second--;
    }
    vi cost = costs.back();
    for (int i = 2; i >= 0; i--) {
        vi newcost(ns[i], INT_MAX);
        def(mymin, int, (int && x, int && y)) {
            return min(x, y);
        };
        id0<int> bst(mymin, INT_MAX, cost);
        id7(d, ns[i]) {
            vpi todos;
            auto ptr = lower_bound(all(bads[i]), mp(d, -1));
            while (ptr != bads[i].end() and ptr->first == d)todos.eb(ptr->second, INT_MAX), ptr++;
            trav(todo, todos) {
                int temp = bst.id4[0][todo.first];
                bst.update(todo.first, todo.second);
                todo.second = temp;
            }
            newcost[d] = bst.segment_op(0, ns[i + 1]);
            if (newcost[d] != INT_MAX)newcost[d] += costs[i][d];
            trav(todo, todos) {
                bst.update(todo.first, todo.second);
            }
        }
        swap(cost, newcost);
    }
    int ans=INT_MAX;
    trav(x,cost)ckmin(ans,x);
    ps(ans==INT_MAX?-1:ans);
    

}

void load_cases() {
    int T = 1;
    {


    }
    vfor(i, 1, T + 1) {


        solve(i);
    }
    bool finished;
    finished = true;
}

int main(int argc, char *argv[]) {
    if (argc > 2)
        return 0;
    if (argc == 2)
        online = false;

    else
        online = true;
    precalc();


    if (online) {
        boost();
        load_cases();
    } else {

        string generator_inputs[] = {

        };

        string testinputs[] = {


                R"(4 3 2 1
1 2 3 4
5 6 7
8 9
10
2
1 2
1 1
2
3 1
3 2
1
1 1
)",
        };

        string testoutputs[] = {

        };


        cout << "--- generator testing ---" << endl;
        trav(testinput, generator_inputs) {
            istringstream iss(testinput);
            cin.rdbuf(iss.rdbuf());
            load_cases();
        }

        cout << "--- local testing ---" << endl;
        trav(testinput, testinputs) {
            if (testinput.back() != '\n')testinput = testinput + '\n';
            istringstream iss(testinput);
            cin.rdbuf(iss.rdbuf());
            load_cases();
        }

        cout << "--- example answers ---" << endl;
        trav(testo, testoutputs) {
            cout << testo << endl;
        }
    }
}




void id5() {
    auto x = main;

    load_cases();

    solve(1);

}