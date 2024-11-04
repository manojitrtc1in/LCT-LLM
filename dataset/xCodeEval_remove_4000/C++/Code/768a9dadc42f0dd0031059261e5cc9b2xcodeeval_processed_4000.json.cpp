

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef pair<int, int> PII;






TTi T SQR(T x) { return x * x; }




































TTi T MIN(T x, T y) { return (x < y) ? x : y; }
TTi T MAX(T x, T y) { return (x > y) ? x : y; }
TTi T ABS(T x) { return (x > 0) ? x : -x; }
TTi void UPDATE_MIN(T &x, T y) {if (y < x) {x = y;}}
TTi void UPDATE_MAX(T &x, T y) {if (x < y) {x = y;}}
TTi int ARGMAX(T cont) { return max_element(cont.begin(), cont.end()) - cont.begin(); }
TTi int ARGMIN(T cont) { return min_element(cont.begin(), cont.end()) - cont.begin(); }

vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s;
    s << "[";
    FORN(i, n - 1) s << arr[i] << ",";
    s << arr[n - 1] << "]";
    return s.str();
}




    
    
    
    

    inline void id3(int line) { cerr << "
    inline void id0(vector<string>::iterator it) {cerr << endl;}

    TTi void id5(vector<T> val) {
        cerr << arrStr(val, val.size());
    }
    TTi void id5(T* val) {
        cerr << arrStr(val, 10);
    }
    TTi void id5(T val) {
        cerr << val;
    }
    template<typename T, typename... Args>
    inline void id0(vector<string>::iterator it, T a, Args... args) {
        cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
        id5(a);
        cerr << "; ";
        id0(++it, args...);
    }

    
    
    
    


template<class T> inline string TOSTR(const T & x) { stringstream ss; ss << x; return ss.str(); }

inline void PR(void) {}
inline void PR(int x) {printf("%d", x);}
inline void PR(LL x) {printf("%lld", x);}
inline void PR(char * s) {printf("%s", s);}
inline void PR(const char * s) {printf("%s", s);}
inline void PR(double f) {printf("%.10lf", f);}
inline void PR(long double f) {printf("%.10llf", f);}
inline void PR(vector<int> &vec) {for(auto x: vec){PR(x);putc(0x20,stdout);}}
TTi void PRS(T x) {PR(x);putc(0x20,stdout);}
TTi void PRN(T x) {PR(x);putc(0x0a,stdout);}
void PRN(void) {putc(0x0a,stdout);}

inline int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
inline LL gcd(LL a, LL b) { return a ? gcd(b % a, a) : b; }
inline LL powmod(LL a, LL p, LL m) { LL r = 1; while (p) { if (p & 1) r = r*a%m; p>>=1; a=a*a%m; } return r; }

struct pairhash {
    template <typename T, typename U>
    std::size_t operator() (const std::pair<T, U> &x) const {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

template <typename K, typename V>
V id8(const std::map<K,V> & m, const K & key, const V & defval ) {
    auto it = m.find(key);
    return (it == m.end()) ? defval : it->second;
}

template <typename K, typename V>
void SetDef(std::map<K,V> & m, const K & key, const V & defval ) {
    auto it = m.find(key);
    if (it == m.end()) m[key] = defval;
}

template <typename K, typename V>
V id8(const std::unordered_map<K,V> & m, const K & key, const V & defval ) {
    auto it = m.find(key);
    return (it == m.end()) ? defval : it->second;
}

template <typename K, typename V>
void SetDef(std::unordered_map<K,V> & m, const K & key, const V & defval ) {
    auto it = m.find(key);
    if (it == m.end()) m[key] = defval;
}

const int MOD = 1000 * 1000 * 1000 + 7;
const double PI = 3.1415926535897932384626433832795l;

inline void addto(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
inline int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}
inline void subto(int &a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
}
inline int sub(int a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
    return a;
}
inline void multo(int &a, int b) {
    a = (long long)a * b % MOD;
}
inline int mul(int a, int b) {
    return (long long)a * b % MOD;
}
inline int mulmod(int a, int b, int mod) {
    return (long long)a * b % mod;
}
inline int powmod(int a, int e, int mod) {
    int x;
    for(x = 1; e > 0; e >>= 1) {
        if (e & 1)
            x = mulmod(x, a, mod);
        a = mulmod(a, a, mod);
    }
    return x;
}
inline int id2(int a, int mod) {
    return powmod(a, mod - 2, mod);
}
inline LL id7(LL p){
    LL q=p;
    for(LL a=p*p;a!=1;a*=a) q*=a;
    return q;
}


typedef LL Num;

struct Point {
    Num x, y;
    inline Point operator+(const Point &other) const
    { return Point{x + other.x, y + other.y}; }

    inline Point operator-(const Point &other) const
    { return Point{x - other.x, y - other.y}; }

    inline Point operator*(const Num a) const
    { return Point{x * a, y * a}; }

    

    inline Num operator*(const Point &other) const
    { return x * other.x + y * other.y; }

    

    inline Num operator/(const Point &other) const
    { return x * other.y - y * other.x; }

    inline bool operator==(const Point &other) const
    { return x == other.x && y == other.y; }

    inline bool operator!=(const Point &other) const
    { return ! (*this == other); }

    

    inline bool operator<(const Point &other) const
    { return x < other.x || (x == other.x && y < other.y); }

    inline bool in_triangle(Point a, Point b, Point c) const {
        

        if ((b - a) / (c - a) < 0) swap(b, c);
        

        const Point &d = *this;
        return (b - a) / (d - a) >= 0 && (c - b) / (d - b) >= 0 && (a - c) / (d - c) >= 0;
    }
};

inline Num id4(const Point &p1, const Point &p2, const Point &p3){
    return abs( (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x) );
}

inline bool cw(const Point & a, const Point & b, const Point & c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

inline bool ccw(const Point & a, const Point & b, const Point & c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

vector<Point> id6(const vector<Point> & lst) {
    if (lst.size() == 1)
        return lst;
    vector<Point> a = lst;
    sort(a.begin(), a.end()); 

    Point p1 = a[0], p2 = a.back();
    vector<Point> up = {p1}, down = {p1};
    for (size_t i = 1; i < a.size(); ++i) {
        if (i == a.size()-1 || cw(p1, a[i], p2)) {
            while (up.size()>=2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size()-1 || ccw(p1, a[i], p2)) {
            while (down.size()>=2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    vector<Point> res;
    for (size_t i = 0; i < up.size(); ++i)
        res.push_back (up[i]);
    for (size_t i = down.size()-2; i > 0; --i)
        res.push_back (down[i]);
    return res;
}


array<Point, 3> id1(const vector<Point> &hull) {
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    int N = hull.size();
    assert(N >= 3);

    int i = 0, j = 1, k = 2;
    
    
    
    
    

    Num max_area = getarea(i, j, k);
    array<int, 3> best_pts = {i, j, k};
    Num area = max_area, area2;

    bool improved = 1;
    while (improved) {
        improved = 0;
        while (better_strict(i, j, inc(k))) {area = area2; k = inc(k); improved = 1;}
        while (better_strict(i, j, dec(k))) {area = area2; k = dec(k); improved = 1;}
        while (better_strict(i, inc(j), k)) {area = area2; j = inc(j); improved = 1;}
        while (better_strict(i, dec(j), k)) {area = area2; j = dec(j); improved = 1;}
        while (better_strict(inc(i), j, k)) {area = area2; i = inc(i); improved = 1;}
        while (better_strict(dec(i), j, k)) {area = area2; i = dec(i); improved = 1;}
    }
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

    

    
    
    
    return {hull[i], hull[j], hull[k]};
}










LL N, M, K, L, E, Q, S;

int main() {
    ios_base::sync_with_stdio(0);

    SCll(N, S);
    vector<Point> pts;
    FORN(i, N) {
        LL x, y;
        SCll(x, y);
        pts.push_back({x, y});
    }

    vector<Point> hull = id6(pts);
    auto ans = id1(hull);
    Point p1 = ans[0];
    Point p2 = ans[1];
    Point p3 = ans[2];

    Point P23 = p3 + (p2 - p1);
    Point P13 = p3 + (p1 - p2);
    Point P12 = p1 + (p2 - p3);
    printf("%lld %lld\n", P12.x, P12.y);
    printf("%lld %lld\n", P23.x, P23.y);
    printf("%lld %lld\n", P13.x, P13.y);
    return 0;
}
