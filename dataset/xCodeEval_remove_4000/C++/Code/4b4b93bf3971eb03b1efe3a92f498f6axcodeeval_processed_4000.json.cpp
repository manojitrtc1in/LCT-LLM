



























using namespace std;










using namespace tr1;


































double __begin;



typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef int itn;

template<class T1, class T2, class T3>
struct triple{ T1 a; T2 b; T3 c; triple() : a(T1()), b(T2()), c(T3()) {}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };
template<class T1, class T2, class T3>
bool operator<(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a<t2.a;else if(t1.b!=t2.b)return t1.b<t2.b;else return t1.c<t2.c;}
template<class T1, class T2, class T3>
bool operator>(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a>t2.a;else if(t1.b!=t2.b)return t1.b>t2.b;else return t1.c>t2.c;}





















inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int bits_count(ll v){int t=v>>32;int p=(v& ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<class T>
inline int sign(T x){ return x > 0 ? 1 : x < 0 ? -1 : 0; }
inline bool id0(int x){ return (x != 0 && (x&(x - 1)) == 0); }






TT1T2 inline ostream& operator << (ostream& os, const pair<T1, T2>& p);
TT1 inline ostream& operator << (ostream& os, const vector<T>& v);
TT1T2 inline ostream& operator << (ostream& os, const set<T1, T2>&v);
TT1T2 inline ostream& operator << (ostream& os, const multiset<T1, T2>&v);
TT1T2 inline ostream& operator << (ostream& os, priority_queue<T1, T2> v);
TT1T2T3 inline ostream& operator << (ostream& os, const map<T1, T2, T3>& v);
TT1T2T3 inline ostream& operator << (ostream& os, const multimap<T1, T2, T3>& v);
TT1T2T3 inline ostream& operator << (ostream& os, const triple<T1, T2, T3>& t);
TT1T2 inline ostream& operator << (ostream& os, const pair<T1, T2>& p){ return os <<"("<<p.first<<", "<< p.second<<")"; }
TT1 inline ostream& operator << (ostream& os, const vector<T>& v){ bool fi = 1; os << "["; for (int i = 0; i<v.size(); i++){ if (!fi)os << ", "; os << v[i]; fi = 0; }return os << "]"; }
TT1T2 inline ostream& operator << (ostream& os, const set<T1, T2>&v){ bool fi = 1; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!fi)os << ", "; os << *ii; fi = 0; }return os << "]"; }
TT1T2 inline ostream& operator << (ostream& os, const multiset<T1, T2>&v){ bool fi = 1; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!fi)os << ", "; os << *ii; fi = 0; }return os << "]"; }
TT1T2T3 inline ostream& operator << (ostream& os, const map<T1, T2, T3>& v){ bool fi = 1; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!fi)os << ", "; os << "(" << ii->first << " -> " << ii->second << ") "; fi = 0; }return os << "]"; }
TT1T2 inline ostream& operator << (ostream& os, const multimap<T1, T2>& v){ bool fi = 1; os << "["; for (auto ii = v.begin(); ii != v.end(); ++ii){ if (!fi)os << ", "; os << "(" << ii->first << " -> " << ii->second << ") "; fi = 0; }return os << "]"; }
TT1T2 inline ostream& operator << (ostream& os, priority_queue<T1, T2> v) { bool fi = 1; os << "["; while (!v.empty()) { auto x = v.top(); v.pop(); if (!fi) os << ", "; fi = 0; os << x; } return os << "]"; }
TT1T2T3 inline ostream& operator << (ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }
TT1T2 void printarray(T1 a[], T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }



TT1T2T3 inline istream& operator >> (istream& os, triple<T1, T2, T3>& t);
TT1T2 inline istream& operator >> (istream& os, pair<T1, T2>& p) { return os >> p.first >> p.second; }
TT1 inline istream& operator >> (istream& os, vector<T>& v) {
    if (v.size()) for (T& t : v) os >> t; else {
        string s; T obj; while (s.empty()) {getline(os, s); if (!os) return os;}
        stringstream ss(s); while (ss >> obj) v.push_back(obj);
    }
    return os;
}
TT1T2T3 inline istream& operator >> (istream& os, triple<T1, T2, T3>& t) { return os >> t.a >> t.b >> t.c; }




TT1T2 inline PT1T2 operator+(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first + p2.first, p1.second + p2.second); }
TT1T2 inline PT1T2 operator-(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first - p2.first, p1.second - p2.second); }








template<class T> bool isPrime(T x) { if (x < 2) return 0; for (T i = 2; i * i <= x; ++i) if (x % i == 0) return 0; return 1; }
inline void normmod(ll &x, ll m) { x %= m; if (x < 0) x += m; }
inline ll id4(ll x, ll y, ll m) { ll res = x + y; if (res >= m) res -= m; return res; }
inline int id4(int x, int y, int m) { int res = x + y; if (res >= m) res -= m; return res; }
inline void id3(ll &x, ll y, ll m) { x += y; if (x >= m) x -= m; }
inline void id3(int &x, int y, int m) { x += y; if (x >= m) x -= m; }
inline void id2(ll &x, ll y, ll m) { x -= y; if (x < 0) x += m; }
inline void id2(int &x, int y, int m) { x -= y; if (x < 0) x += m; }
inline ll mulmod(ll x, ll n, ll m){ ll res = 0; normmod(x, m); normmod(n, m); while (n){ if (n & 1) res = id4(res, x, m); x = id4(x, x, m); n >>= 1; } return res; }
inline ll powmod(ll x, ll n, ll m){ ll res = 1; while (n){ if (n & 1)res = (res*x) % m; x = (x*x) % m; n >>= 1; }return res; }
inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }
ll id1(ll a, ll b, ll& x, ll& y) {
    if (!a) { x = 0; y = 1; return b; }
    ll y1;
    ll d = id1(b % a, a, y, y1);
    x = y1 - (b / a) * y;
    return d;
}


















char s[55][55];
char t[55][55];
char ss[55][55];
char tt[55][55];
int n, m;
bool canh(int x, int y) {
    if (x < 0 || y < 0 || x + 1 >= n || y + 1 >= m) return false;
    return s[x][y] == 'L' && s[x][y + 1] == 'R' && s[x + 1][y] == 'L' && s[x + 1][y + 1] == 'R';
}
bool canv(int x, int y) {
    if (x < 0 || y < 0 || x + 1 >= n || y + 1 >= m) return false;
    return s[x][y] == 'U' && s[x][y + 1] == 'U' && s[x + 1][y] == 'D' && s[x + 1][y + 1] == 'D';
}
void rot(int x, int y) {
    if (s[x][y] == 'L') {
        s[x][y] = 'U';
        s[x + 1][y] = 'D';
        s[x][y + 1] = 'U';
        s[x + 1][y + 1] = 'D';
    } else {
        s[x][y] = 'L';
        s[x + 1][y] = 'L';
        s[x][y + 1] = 'R';
        s[x + 1][y + 1] = 'R';
    }
}
vector<pii> solve() {
    vector<pii> res;
    while (true) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m - 1; ++j) {
                if (canh(i, j)) {
                    res.push_back({i, j});
                    rot(i, j);
                    goto next_step;
                }
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m - 1; ++j) {
                if (canv(i, j)) {
                    rot(i, j);
                    for (int x = i - 1; x <= i; ++x) {
                        for (int y = j - 1; y <= j + 1; ++y) {
                            if (x == i && y == j) continue;
                            if (canh(x, y)) {
                                res.push_back({i, j});
                                res.push_back({x, y});
                                rot(x, y);
                                goto  next_step;
                            }
                        }
                    }
                    rot(i, j);
                }
            }
        }
        break;
    next_step:;
    }
    
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    FREIN("input.txt");

    cin >> n >> m;
    FI(n) {
        cin >> s[i];
        FJ(m) {
            ss[i][j] = s[i][j];
        }
    }
    FI(n) {
        cin >> t[i];
        FJ(m) {
            tt[i][j] = t[i][j];
        }
    }
    auto sw = [](char c) {
        if (c == 'U') {
            return 'L';
        } else if (c == 'D') {
            return 'R';
        } else if (c == 'L') {
            return 'U';
        } else {
            return 'D';
        }
    };
    bool rot = false;
    if (n % 2) {
        rot = true;
        char tmp[55][55];
        FI(n) {
            FJ(m) {
                tmp[i][j] = s[i][j];
            }
        }
        FI(m) {
            FJ(n) {
                s[i][j] = sw(tmp[j][i]);
            }
            s[i][n] = 0;
        }
        FI(n) {
            FJ(m) {
                tmp[i][j] = t[i][j];
            }
        }
        FI(m) {
            FJ(n) {
                t[i][j] = sw(tmp[j][i]);
            }
            t[i][n] = 0;
        }
        swap(n, m);
    }
    auto res1 = solve();












    FI(n) {
        FJ(m) {
            s[i][j] = t[i][j];
        }
    }
    auto res2 = solve();














    std::reverse(res2.begin(), res2.end());
    for (auto p : res2) {
        res1.push_back(p);
    }
    if (rot) {
        swap(n, m);
        for (auto& p : res1) {
            swap(p.first, p.second);
        }
    }
    cout << res1.size() << endl;
    for (auto p : res1) {
        cout << p.first + 1 << ' ' << p.second + 1 << endl;
    }
    

    FI(n) {
        FJ(m) {
            s[i][j] = ss[i][j];
        }
    }
    for (auto p : res1) {
        assert(canv(p.first, p.second) || canh(p.first, p.second));
        ::rot(p.first, p.second);
    }
    FI(n) {
        FJ(m) {
            cout << s[i][j];
        }
        cout << endl;
    }

    
    return 0;
}