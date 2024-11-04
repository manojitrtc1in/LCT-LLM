

using namespace std;














































SOMET using id6  =    array<T, 2>;
SOMET using TRIPLE  =    array<T, 3>;
SOMET using QUAD    =    array<T, 4>;
using Byte  =           unsigned char;
using LLD   =           long long;
using ULLD  =           unsigned long long;
using UINT  =           unsigned int;
using PII   =           pair<int, int>;
using VI    =           vector<int>;
using VVI   =           vector<VI>;
using VPII  =           vector<PII>;
using MII   =           map<int, int>;
using SI    =           set<int>;
using VVP   =           vector<VPII>;
using PLLD  =           pair<LLD, LLD>;
using VLLD  =           vector<LLD>;
using VVLLD =           vector<VLLD>;
using VPLLD =           vector<PLLD>;
using VB    =           vector<bool>;
using VVB   =           vector<VB>;
using VCh   =           vector<char>;
using VVCh  =           vector<VCh>;
using CI    =           id6<int>;
using TI    =           TRIPLE<int>;
using QI    =           QUAD<int>;
using VCI   =           vector<CI>;
using VTI   =           vector<TI>;
using VQI   =           vector<QI>;

template <size_t n> using INTARR = array<int, n>;
const int INF           = 2147483647 / 2;
const LLD id11        = INT64_MAX / 2;
const string alphabet   = "abcdefghijklmnopqrstuvwxyz";
const int MOD           = 1e9 + 7;















int operator~(const string& s) { return (int)(s.size()); }
char& operator^(string& s, int v) { return s[~s - 1 - v]; }
char& operator-(string &s) { return s[~s - 1]; }


TARGS void operator+=(vector<TAP> &s, T v) { s.push_back(v); }
TARGS T& operator-(vector<TAP> &s) { return s[~s - 1]; }
TARGS T& operator^(vector<TAP> &s, int v) { return s[~s - 1 - v]; }
TARGS T operator--(vector<TAP>& s) { auto k = -s; s.pop_back(); return k; }
TARGS int operator~(const vector<TAP>& s) { return (int)s.size(); }




TARGS void dedup(vector<TAP>& s) { sort(ALL(s)); s.erase(unique(ALL(s)), s.end()); }
TARGS typename vector<TAP>::iterator find(vector<TAP>& s, const T& x) {
    auto it = lower_bound(ALL(s), x); return (it != s.end() && *it == x) ? it : s.end();
}
TARGS int index(vector<TAP>& s, const T& x) {
    auto it = find(s, x); check(it != s.end() && *it == x); return it - s.begin();
}

template<typename T, size_t n> int operator~(const array<T, n>& s) { return (int)s.size(); }

TARGS void operator+=(stack<TAP>& s, T v) { s.push(v); }
TARGS T operator-(stack<TAP>& s) { return s.top(); }
TARGS T operator--(stack<TAP>& s) { auto k = -s; s.pop(); return k; }
TARGS int operator~(const stack<TAP>& s) { return (int)s.size(); }

TARGS void operator+=(queue<TAP>& s, T v) { s.push(v); }
TARGS T operator-(queue<TAP>& s) { return s.front(); }
TARGS T operator--(queue<TAP>& s) { auto k = -s; s.pop(); return k; }
TARGS int operator~(const queue<TAP>& s) { return (int)s.size(); }


TARGS void operator+=(priority_queue<TAP>& s, T v) { s.push(v); }
TARGS T operator-(priority_queue<TAP>& s) { return s.top(); }
TARGS T operator--(priority_queue<TAP>& s) { auto k = -s; s.pop(); return k; }
TARGS int operator~(const priority_queue<TAP>& s) { return (int)s.size(); }

TARGS void operator+=(set<TAP>& s, T v) { s.insert(v); }
TARGS void operator-=(set<TAP>& s, T v) { s.erase(v); }
TARGS bool operator<(T v, set<TAP>& s) { return s.find(v) != s.end(); }
TARGS bool operator>(T v, set<TAP>& s) { return s.find(v) == s.end(); }
TARGS int operator~(const set<TAP>& s) { return (int)s.size(); }

KV void operator+=(map<K, V>& s, pair<K, V> v) { s.insert(v); }
KV void operator-=(map<K, V>& s, K v) { s.erase(v); }
TARGS bool operator<(T v, const map<TAP>& s) { return s.find(v) != s.end(); }
TARGS bool operator>(T v, const map<TAP>& s) { return s.find(v) == s.end(); }
TARGS int operator~(const map<TAP>& s) { return (int)s.size(); }


SOMET void id8(const vector<T>& v) {
    stringstream id9, id7;
    id9 << "i    "; id7 << "a[i] ";
    REP(i, ~v) {
        int w = max({~TOS(v[i]), ~TOS(i), 3});
        id9 << setw(w) << TOS(i) << " ";
        id7 << setw(w) << TOS(v[i]) << " ";
    }
    cout << id9.str() << "\n" << id7.str() << "\n";
}

void id8(const string& v) {
    stringstream id9, id7;
    id9 << "i    "; id7 << "a[i] ";
    REP(i, ~v) {
        int w = max({~TOS(i), 3});
        id9 << setw(w) << TOS(i) << " ";
        id7 << setw(w) << v[i] << " ";
    }
    cout << id9.str() << "\n" << id7.str() << "\n";
}

SOMET void id10(vector<vector<T>>& v)
{ REP(i, ~v) { cout << "Row: " << i << "\n"; id8(v[i]); } }
SOMET void id12(vector<vector<T>>& v) {
    int h = ~v, w = ~v[0], z = 3;
    cout << "\n" << setw(z) << "+" << " ";
    REP(j, w) cout << setw(z) << j << " \n"[j == (w - 1)];
    REP(i, h) {
        cout << setw(z) << i << " ";
        REP(j, w) cout << setw(z) << v[i][j] << " \n"[j == (w - 1)];
    }
    cout << "\n";
}

SOMET void id8(T& v) {}
SOMET void id10(T& v) {}
SOMET void id12(T& v) {}


KV void read(pair<K, V>& p);
SOMET void read(vector<T>& v);
KV void read(pair<K, V>& p) { read(p._0, p._1); }
SOMET void read(vector<T>& v) { REP(i, ~v) cin >> v[i]; }
SOMET void read(T& x) { cin >> x; }
TARGS void read(T& head, Args&... rest) { read(head); read(rest...); }















const char* __sep__[2] = {", ", " "};
ARGS ostream& operator<<(ostream& os, const vector<EXP>& v) {
    os << "[ ";
    REP(i, ~v) {os << v[i] << __sep__[i + 1 == ~v];}
    return os << "]";
}
template<typename T, size_t n>
ostream& operator<<(ostream& os, const array<T, n>& v) {
    os << "[ ";
    REP(i, ~v) {os << v[i] << __sep__[i + 1 == ~v];}
    return os << "]";
}
ARGS ostream& operator<<(ostream& os, const set<EXP>& v) {
    os << "{ ";
    ITER(it, v) os << *it << __sep__[next(it) == v.end()];
    return os << "}";
}
KV ostream& operator<<(ostream& os, const map<K, V>& v) {
    os << "{ ";
    ITER(it, v) os << it->first << ": " << it->second
                   << __sep__[next(it) == v.end()];
    return os <<  "}";
}
KV ostream &operator<<(ostream &os, const pair<K, V> &v) {
    return os << "(" << v.first << __sep__[0] << v.second << ")";
}
KV ostream &operator<<(ostream &os, const tuple<K, V> &v) {
    return os << "(" << tget(v, 0) << __sep__[0] << tget(v, 1) << ")";
}
KVT ostream &operator<<(ostream &os, const tuple<K, V, T> &v) {
    return os << "(" << tget(v, 0) << __sep__[0] << tget(v, 1)
           << __sep__[0] << tget(v, 2) << ")";
}

SOMET void id13(const char* sep, const T& x) { cout << x << sep; }
TARGS void id13(const char* sep, const T& x, const Args&... a) { cout << x << sep; id13(sep, a...); }

ARGS void writeln(const Args&... a) { id13("\n", a...); }
void writeln() { cout << "\n"; }

ARGS void writes(const Args&... a) { id13(" ", a...); }
ARGS void writesln(const Args&... a) { id13(" ", a...); writeln();}
ARGS void write(const Args&... a) { id13("", a...); }

TARGS void mkmax(T& a, Args&&... z) { a = max({a, z...}); }
TARGS void mkmin(T& a, Args&&... z) { a = min({a, z...}); }
TARGS bool ckmax(T& a, Args&&... z) { auto t = a; mkmax(a, z...); return (a != t);  }
TARGS bool ckmin(T& a, Args&&... z) { auto t = a; mkmin(a, z...); return (a != t);  }

int id0(UINT n) { return 31 - CLZ(n); }
int id1(UINT n) { return id0(n) + !!(n & (n - 1)); }
int id3(ULLD n) { return 63 - CLZLL(n); }
int id4(ULLD n) { return id3(n) + !!(n & (n - 1ULL)); }
template<size_t n> bitset<n> id2(const bitset<n>& x)
{ auto y = x.to_string(); reverse(ALL(y)); return bitset<n>(y); }



class Rng {
    mt19937 mtgen;
    uniform_int_distribution<int> dist_;

  public:
    Rng(int min, int max, size_t seed = random_device()())
        : mtgen(seed), dist_(min, max) {}
    int operator()() { return dist_(mtgen); }
};

VI randomvec(int sz) {
    Rng rg(0, 10);
    VI s;
    REP(i, sz) s += rg();
    return s;
}

string randomstring(int sz) {
    Rng rg((int)'a', (int)'z');
    string s;
    REP(i, sz) s += (char)rg();
    return s;
}



    {                                                                          \
        cout << '
        writes(__VA_ARGS__);                                                   \
        cout << "\n" << flush;                                                 \
    }

    { write(__VA_ARGS__); }

    { writesln(__VA_ARGS__), cout << flush; }

    {                                                                          \
        cout << '
        cout << flush;                                                         \
    }

    {                                                                          \
        cout << '
        cout << flush;                                                         \
    }

    {                                                                          \
        cout << '
        cout << flush;                                                         \
    }

    { cout << '














void measure(const string &name, function<void()> func) {
    auto start_time = chrono::high_resolution_clock::now();
    func();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(
        chrono::high_resolution_clock::now() - start_time);
    putsln(name, static_cast<double>(duration.count()) * 0.000001, "ms");
}



void soln(int id5, int __tc) {
    RESTRING(s);
    LLD evenans = 0, oddans = 0;
    int odda = 0, oddb = 0, evena = 0, evenb = 0;
    for (int i = 0; i < ~s; ++i) {
        if (i % 2 == 1) {
            if (s[i] == 'a') {
                odda += 1;
                oddans += (odda);
                evenans += (evena);
            } else {
                oddb += 1;
                oddans += (oddb);
                evenans += (evenb);
            }
        } else {
            if (s[i] == 'a') {
                evena += 1;
                evenans += (odda);
                oddans += (evena);
            } else {
                evenb += 1;
                evenans += (oddb);
                oddans += (evenb);
            }
        }
    }
    writesln(evenans, oddans);
}





int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    soln(1, 1);

    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        putsln("Test case = ", i + 1);
        soln(tc, i + 1);
    }

}
