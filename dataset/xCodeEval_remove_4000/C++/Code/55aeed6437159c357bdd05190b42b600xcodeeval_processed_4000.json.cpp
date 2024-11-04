


































































using namespace std;



typedef long long _;
typedef int _0;
typedef double _D;
typedef unsigned long long u_;
typedef string str;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;



inline _ read() {
    _ x = 0, f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}

inline bool read(_ &x, v(char) tl = {'\n', EOF}) {
    x = 0;
    _ f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    x *= f;
    if(ch == '\r') ch = getchar();
    return !count(tl.begin(), tl.end(), ch);
}

inline void read(char * a, v(char) tl = {' ', '\n', '\r', '\t', '\0', EOF}, v(char) skp = {' ', '\n', '\r', '\t'}) {
    char ch = getchar();
    for(; count(skp.begin(), skp.end(), ch); ) ch = getchar();
    for(; !count(tl.begin(), tl.end(), ch); ch = getchar()) {
        *a = ch;
        ++a;
    }
    *a = '\0';
    return;
}

inline void read(str & a, v(char) tl = {' ', '\n', '\r', '\t', '\0', EOF}, v(char) skp = {' ', '\n', '\r', '\t'}) {
    a.clear();
    char ch = getchar();
    for(; count(skp.begin(), skp.end(), ch); ) ch = getchar();
    for(; !count(tl.begin(), tl.end(), ch); ch = getchar()) a += ch;
    return;
}

inline void read(vector<reference_wrapper<_> > a) {
    for(_ & i : a) i = read();
    return;
}

inline char id1() {
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar();
    return ch;
}

inline char id2() {
    char ch = getchar();
    for(; !(ch >= 'a' && ch <= 'z'); ) ch = getchar();
    return ch;
}

inline char getUp() {
    char ch = getchar();
    for(; !(ch >= 'A' && ch <= 'Z'); ) ch = getchar();
    return ch;
}

inline char id0() {
    char ch = getchar();
    for(; !((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')); ) ch = getchar();
    return ch;
}

inline char gc() {
    char ch = getchar();
    for(; ch == '\n' || ch == '\r' || ch == ' '; ) ch = getchar();
    return ch;
}

inline void write(_ x) {
    if(x < 0) {
        putchar('-');
        write(-x);
        return;
    }
    if(x > 9) write(x/10);
    putchar((x%10)^48);
    return;
}

inline void write(_0 x) {
    write((_)x);
    return;
}

inline void write(char const * a) {
    for(_ i = 0; a[i]; ++i) putchar(a[i]);
    return;
}

inline void write(const str a) {
    write(a.c_str());
    return;
}

inline void write(char ch) {
    putchar(ch);
    return;
}

inline void write(_p a, char const * b = " ") {
    write(a.first);
    write(b);
    write(a.second);
    return;
}

inline void clr() {
    putchar(10);
    return;
}

inline void flsh(bool nl = true) {
    if(nl) clr();
    fflush(stdout);
    return;
}

inline void spc() {
    putchar(32);
    return;
}

template <class tp>
inline void writeln(tp x) {
    write(x);
    clr();
}

inline void writeln(_p a, char const * b = " ") {
    write(a, b);
    clr();
    return;
}

template <class tp>
inline void id3(tp x) {
    write(x);
    spc();
}

inline void id3(_p a, char const * b = " ") {
    write(a);
    spc();
    return;
}

template <class tp>
inline void id4(tp x, bool nl = true) {
    write(x);
    flsh(nl);
}

inline void id4(_p a, char const * b = " ", bool nl = true) {
    write(a, b);
    flsh(nl);
    return;
}

inline void yes(_ a = 1) {
    write(a & 1 ? 'Y' : 'y');
    write(a & 2 ? 'E' : 'e');
    write(a & 4 ? 'S' : 's');
    clr();
    return;
}

inline void no(_ a = 1) {
    write(a & 1 ? 'N' : 'n');
    write(a & 2 ? 'O' : 'o');
    clr();
    return;
}



inline v_ rg(_ r, _ l = 1, _ d = 1) {
    v_ rv;
    for(_ i = l; i <= r; i += d) rv.push_back(i);
    return rv;
}

inline v_ dg(_ r, _ l = 1, _ d = -1) {
    v_ rv;
    for(_ i = r; i >= l; i += d) rv.push_back(i);
    return rv;
}

inline void AC();
int main(int argc, char * argv[]) {




    str fileN = "";
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);


    

    _ tc = read();
    for(; tc--; ) AC(); 


    AC(); 



    return 0;
}

struct hpa {
    str data = "";
    bool neg = false;
    hpa(_ x = 0) {
        if(x == 0) {
            neg = false;
            data.clear();
        } ef(x < 0) {
            neg = true;
            data = to_string(x*-1);
        } else {
            neg = false;
            data = to_string(x);
        }
        reverse(data.begin(), data.end());
    }
    inline void clear() {
        data = "";
        neg = false;
        return;
    }
    inline void read() {
        clear();
        char ch = getchar();
        for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') neg = true;
        for(; ch >= '0' && ch <= '9'; ch = getchar()) data.push_back(ch);
        reverse(data.begin(), data.end());
        for(; data.back() == '0'; ) data.pop_back();
        return;
    }
    inline void write(char b = '\0') {
        if(data.empty()) putchar('0');
        else {
            if(neg) putchar('-');
            for(_ i = data.length()-1; i >= 0; --i) putchar(data[i]);
        }
        if(b) putchar(b);
        return;
    }
    inline _ to_ll(_ md = 9223372036854775807) {
        _ x = 0;
        for(_ i = data.length()-1; i >= 0; --i) x = ((x<<3)+(x<<1)+(data[i]^48))%md;
        return neg ? x*-1 : x;
    }
    inline _ len() {
        if(data.empty()) return 1;
        return data.length();
    }
};
inline hpa operator + (hpa aa, hpa ba);
inline hpa operator - (hpa a, hpa b);
inline bool operator == (const hpa &a, const hpa &b) {
    return a.data == b.data && a.neg == b.neg;
}
inline bool operator != (const hpa &a, const hpa &b) {
    return !(a == b);
}
inline bool operator < (const hpa &a, const hpa &b) {
    if(a.neg != b.neg) return a.neg;
    if(a.data.length() != b.data.length()) return a.data.length() < b.data.length();
    for(_ i = a.data.length()-1; i >= 0; --i) if(a.data[i] != b.data[i]) return a.data[i] < b.data[i];
    return false;
}
inline bool operator > (const hpa &a, const hpa &b) {
    return !(a < b) && !(a == b);
}
inline bool operator <= (const hpa &a, const hpa &b) {
    return a < b || a == b;
}
inline bool operator >= (const hpa &a, const hpa &b) {
    return !(a < b);
}
inline hpa operator + (hpa aa, hpa ba) {
    if(aa.neg && !ba.neg) {
        aa.neg = false;
        return ba-aa;
    }
    if(!aa.neg && ba.neg) {
        ba.neg = false;
        return aa-ba;
    }
    hpa rv;
    rv.neg = aa.neg;
    str &a = aa.data, &b = ba.data;
    if(a.length() > b.length()) swap(a, b);
    _ cr = 0, al = a.length(), bl = b.length();
    for(_ i = 0; i < al; ++i) {
        _ t = (a[i]^48)+(b[i]^48)+cr;
        rv.data.push_back((t%10)^48);
        cr = t/10;
    }
    for(_ i = al; i < bl; ++i) {
        _ t = (b[i]^48)+cr;
        rv.data.push_back((t%10)^48);
        cr = t/10;
    }
    if(cr) rv.data.push_back(cr^48);
    return rv;
}
inline hpa operator - (hpa aa, hpa ba) {
    if(aa == ba) return hpa();
    if(aa.neg && !ba.neg) {
        aa.neg = false;
        hpa rv = aa+ba;
        rv.neg = true;
        return rv;
    }
    if(!aa.neg && ba.neg) {
        ba.neg = false;
        return aa+ba;
    }
    if(aa.neg) {
        aa.neg = false;
        ba.neg = false;
        return ba-aa;
    }
    hpa rv;
    str &a = aa.data, &b = ba.data;
    bool lg = false;
    if(a.length() == b.length()) for(_ i = b.length(); i >= 0; --i) if(a[i] != b[i]) {
        lg = a[i] < b[i];
        break;
    }
    if(a.length() < b.length() || lg) {
        rv.neg = true;
        swap(a, b);
    }
    _ al = a.length(), bl = b.length();
    bool tk = false;
    for(_ i = 0; i < al; ++i) {
        _ x = a[i]^48, y;
        if(i >= bl) y = 0;
        else y = b[i]^48;
        if(tk) --x;
        if(x < y) {
            tk = true;
            x += 10;
        } else tk = false;
        rv.data.push_back((x-y)^48);
    }
    for(; !rv.data.empty() && !(rv.data.back()^48); ) rv.data.pop_back();
    return rv;
}
inline hpa operator * (hpa aa, hpa ba) {
    if(aa.data.empty() || ba.data.empty()) return hpa();
    hpa rv;
    rv.neg = aa.neg ^ ba.neg;
    str &a = aa.data, &b = ba.data;
    if(a.length() < b.length()) swap(a, b);
    _ al = a.length(), bl = b.length();
    vector<int> c (al+bl, 0);
    for(_ i = 0; i < al; ++i) for(_ j = 0; j < bl; ++j) c[i+j] += (a[i]^48)*(b[j]^48);
    for(_ i = 0; i < al+bl; ++i) if(c[i] >= 10) {
        c[i+1] += c[i]/10;
        c[i] %= 10;
    }
    for(_ i = 0; i < al+bl; ++i) rv.data.push_back(c[i]^48);
    for(; !(rv.data.back()^48); ) rv.data.pop_back();
    return rv;
}
inline hpa operator / (hpa aa, _ b) {
    if(aa.data.empty()) return hpa();
    hpa rv;
    rv.neg = aa.neg ^ (b < 0);
    if(b < 0) b *= -1;
    str &a = aa.data;
    _ cr = 0, al = a.length();
    bool ok = false;
    for(_ i = 0; i < al; ++i) {
        cr = (cr<<3)+(cr<<1)+(a[al-i-1]^48);
        _ d = cr/b;
        if(d) ok = true;
        if(ok) rv.data.push_back(d^48);
        cr %= b;
    }
    reverse(rv.data.begin(), rv.data.end());
    return rv;
}
inline hpa operator % (hpa aa, _ b) {
    if(aa.data.empty()) return hpa();
    hpa rv;
    rv.neg = aa.neg;
    if(b < 0) b *= -1;
    str &a = aa.data;
    _ cr = 0;
    for(_ i = a.length()-1; i >= 0; --i) cr = ((cr<<3)+(cr<<1)+(a[i]^48))%b;
    rv.data = to_string(cr);
    reverse(rv.data.begin(), rv.data.end());
    return rv;
}
inline void operator += (hpa &a, const hpa &b) {
    a = a+b;
}
inline void operator -= (hpa &a, const hpa &b) {
    a = a-b;
}
inline void operator *= (hpa &a, const hpa &b) {
    a = a*b;
}
inline void operator /= (hpa &a, const _ &b) {
    a = a/b;
}
inline void operator %= (hpa &a, const _ &b) {
    a = a%b;
}






constant maxn = 1E3+8;
constant mod = 998244353;

_ n, m, d[maxn], a[maxn], x, y, t;
v_ g[maxn];

typedef pr(hpa, hpa) pp;

v(pp) b[maxn];
queue<_> q;

inline void AC() {
    
    read({n, m});
    rd(a, n);
    for(_ i = 1; i <= n; ++i) {
        g[i].clear();
        b[i].clear();
        if(a[i]) b[i].push_back(mp(1, a[i]));
    }
    for(; m--; ) {
        x = read();
        y = read();
        ++d[y];
        g[x].push_back(y);
    }
    for(_ i = 1; i <= n; ++i) {
        if(g[i].empty()) t = i;
        if(d[i] == 0) q.push(i);
    }
    for(; !q.empty(); q.pop()) {
        _ t = q.front();
        sort(b[t].begin(), b[t].end());
        v(pp) h;
        for(pp i : b[t]) {
            if(h.empty()) h.push_back(i);
            ef(h.back().second < i.first-1) h.push_back(i);
            else h.back().second += i.second-i.first+1;
        }
        b[t] = h;
        for(_ i : g[t]) {
            for(pp j : b[t]) b[i].push_back(mp(j.first+1, j.second+1));
            if(!--d[i]) {
                q.push(i);
            }
        }
    }
    if(b[t].empty()) writeln(0);
    else (b[t].rbegin() -> second%mod).write(10);
    
    return;
}