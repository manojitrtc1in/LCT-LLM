




















using namespace std;



using tr1::unordered_map;
using tr1::unordered_set;






























typedef    long long        LL;
typedef    pair<int,int>    PII;
typedef    pair<LL,LL>      PLL;
typedef    vector<bool>     VB;
typedef    vector<int>      VI;
typedef    vector<LL>       VL;
typedef    vector<PII>      VII;
typedef    vector<PLL>      VLL;




template<class T>inline T _max(T a, T b) { return a > b ? a : b; }
template<class T>inline T _min(T a, T b) { return a < b ? a : b; }
template<class T>inline T _max(T a, T b, T c) { return _max(a, _max(b, c)); }
template<class T>inline T _min(T a, T b, T c) { return _min(a, _min(b, c)); }
template<class T>inline T _max(T a, T b, T c, T d) { return _max(a, _max(b, c, d)); }
template<class T>inline T _min(T a, T b, T c, T d) { return _min(a, _min(b, c, d)); }



inline char gtc() { static char bfi[Buff], *ci = bfi - 1, *cl = ci; return ci == cl && (cl = (ci = bfi - 1) + fread(bfi, 1, Buff, stdin), ci == cl) ? EOF : *++ci; }
void readbit(double &ret, double bit = 0.1) { char chr; if(chr = gtc(), isdigit(chr)) ret += (chr ^ 48) * bit, readbit(ret, bit * 0.1); }
inline bool _read(int &res, bool flag = 0, int sum = 0) { char chr; while(chr = gtc(), !(isdigit(chr) || (chr ^ '-' ? 0 : (chr = gtc(), flag = 1)))) if(chr == -1) return 0; while(isdigit(chr)) sum = ((sum + (sum << 2)) << 1) + (chr ^ 48), chr = gtc(); res = flag ? -sum : sum; return 1; }
inline bool _read(unsigned int &res) { char chr; while(chr = gtc(), !isdigit(chr)) if(chr == -1) return 0; res = 0; while(isdigit(chr))res = ((res + (res << 2)) << 1) + (chr ^ 48), chr = gtc(); return 1; }
inline bool _read(long long &res, bool flag=0, long long sum = 0) { char chr; while(chr = gtc(), !(isdigit(chr) || (chr ^ '-' ? 0 : (chr=gtc(), flag=1)))) if(chr == -1) return 0; while(isdigit(chr)) sum = ((sum + (sum << 2)) << 1) + (chr ^ 48), chr = gtc(); res = flag ? -sum : sum; return 1; }
inline bool _read(unsigned long long &res) { char chr; while(chr = gtc(), !isdigit(chr)) if(chr == -1) return 0; res = 0; while(isdigit(chr))res = ((res + (res << 2)) << 1) + (chr ^ 48),chr = gtc(); return 1; }
inline bool _read(double &ret, bool flag = 0, long long sum = 0) { char chr; while(chr = gtc(), !(isdigit(chr) || (chr ^ '-' ? 0 : (chr = gtc(), flag = 1)))) if(chr == -1) return 0; while(isdigit(chr)) sum = ((sum + (sum << 2)) << 1) + (chr ^ 48), chr = gtc(); if(ret = sum, chr == '.') readbit(ret); ret = flag ? -ret : ret; return 1; }
inline bool _read(char &ch) { while(ch = gtc(), (ch == 32) || (ch == 10) || (ch == -1)) if(ch == -1) return 0; return 1; }
inline bool _read(char *p) { char chr; while(chr = gtc(), (chr == 32) || (chr == 10) || (chr == -1)) if(chr == -1) return 0; while(chr ^ 10 && chr ^ 32 && ~chr) *p++ = chr, chr = gtc(); *p=0; return 1; }
inline bool _read(string &s) { char chr, _s[128], *be = _s, *en = _s + 127; while(chr = gtc(), (chr == 32) || (chr == 10) || (chr == -1)) if(chr == -1) return 0; *en = 0; while(chr ^ 10 && chr ^ 32 && ~chr) { *be++ = chr, be != en ? chr = gtc() : (be = _s, s += _s, chr = gtc()); } *be = 0, s += _s; return 1; }
template<class T, class U>inline bool _read(pair<T, U> &res) { return _read(res.ff), _read(res.ss); }
inline void ptc(char ch = 0) { static char bfo[Buff], *co = bfo - 1, *coe = co + Buff; !ch || (*++co=ch, co==coe) ? fwrite(bfo, 1, co-bfo+1, stdout), co = bfo - 1 : 0; }
inline void _out(bool x) { ptc(x ? '1' : '0'); }
void _out(int x) { if(x < 0) ptc('-'), x = -x; if(x > 9) _out(x / 10); ptc(x % 10 ^ '0'); }
void _out(unsigned int x) { if(x > 9) _out(x / 10); ptc(x % 10 ^ '0'); }
void _out(long long x) { if(x < 0) ptc('-'), x = -x; if(x > 9) _out(x / 10); ptc(x % 10 ^ '0'); }
void _out(unsigned long long x) { if(x > 9) _out(x / 10); ptc(x % 10 ^ '0'); }
inline void _out(double x, int n = 8) { if(x < 0) ptc('-'), x = -x; _out((LL)x), x -= (LL)x, ptc('.'); while(n--) x *= 10, _out(LL(x) % 10); }
inline void _out(const char ch) { ptc(ch); }
inline void _out(const char *p) { while(*p) ptc(*p++); }
inline void _out(const string &s) { const char *p = s.c_str(); while(*p) ptc(*p++); }
template<class T, class U>inline void _out(pair<T, U> x) { _out(x.ff), _out(' '), _out(x.ss); }
template<class T>inline void _out(vector<T> &s) { _out('['); for(auto i = s.begin(); i != s.end(); ++i) _out(i == s.begin() ? "" : ", "), _out(*i); _out(']'); }
template<class T,class U,class O>inline void _out(const map<T,U,O> &s) { _out('['); for(auto i = s.begin(); i != s.end(); ++i) _out(i == s.begin() ? "(" : ", ("), _out(i->ff), _out(" -> "), _out(i->ss), _out(')'); _out(']'); }
template<class T,class U,class O>inline void _out(const multimap<T,U,O> &s) { _out('['); for(auto i = s.begin(); i != s.end(); ++i) _out(i == s.begin() ? "(" : ", ("), _out(i->ff), _out(" -> "), _out(i->ss), _out(')'); _out(']'); }
template<class T,class U>inline void _out(const set<T,U> &s) { _out('['); for(auto i = s.begin(); i != s.end(); ++i) _out(i == s.begin() ? "" : ", "), _out(*i); _out(']'); }
template<class T,class U>inline void _out(const multiset<T,U> &s) { _out('['); for(auto i = s.begin(); i != s.end(); ++i) _out(i == s.begin() ? "" : ", "), _out(*i); _out(']'); }
template<class T,class U>inline void _out(priority_queue<T,U> s) { _out('['); while(!s.empty()) _out(s.top()),s.pop(), _out(s.empty() ? "" : ", "); _out(']'); }




inline bool _scan(int &res, bool flag = 0, int sum = 0) { char chr; while(chr = getchar(), !(isdigit(chr) || (chr ^ '-' ? 0 : (chr = getchar(), flag = 1)))) if(chr == -1) return 0; while(isdigit(chr)) sum = ((sum + (sum << 2)) << 1) + (chr ^ 48), chr = getchar(); res = flag ? -sum : sum; return 1; }
inline bool _scan(unsigned int &res) { char chr; while(chr = getchar(), !isdigit(chr)) if(chr == -1) return 0; res = 0; while(isdigit(chr))res = ((res + (res << 2)) << 1) + (chr ^ 48), chr = getchar(); return 1; }
inline bool _scan(long long &res, bool flag=0, long long sum = 0) { char chr; while(chr = getchar(), !(isdigit(chr) || (chr ^ '-' ? 0 : (chr=getchar(), flag=1)))) if(chr == -1) return 0; while(isdigit(chr)) sum = ((sum + (sum << 2)) << 1) + (chr ^ 48), chr = getchar(); res = flag ? -sum : sum; return 1; }
inline bool _scan(unsigned long long &res) { char chr; while(chr = getchar(), !isdigit(chr)) if(chr == -1) return 0; res = 0; while(isdigit(chr))res = ((res + (res << 2)) << 1) + (chr ^ 48),chr = getchar(); return 1; }
inline bool _scan(double &ret, bool flag = 0, long long sum = 0) { char chr; while(chr = getchar(), !(isdigit(chr) || (chr ^ '-' ? 0 : (chr = getchar(), flag = 1)))) if(chr == -1) return 0; while(isdigit(chr)) sum = ((sum + (sum << 2)) << 1) + (chr ^ 48), chr = getchar(); if(ret = sum, chr == '.') readbit(ret); ret = flag ? -ret : ret; return 1; }
inline bool _scan(char &ch) { while(ch = getchar(), (ch == 32) || (ch == 10) || (ch == -1)) if(ch == -1) return 0; return 1; }
inline bool _scan(char *p) { char chr; while(chr = getchar(), (chr == 32) || (chr == 10) || (chr == -1)) if(chr == -1) return 0; while(chr ^ 10 && chr ^ 32 && ~chr) *p++ = chr, chr = getchar(); *p=0; return 1; }
inline bool _scan(string &s) { char chr, _s[128], *be = _s, *en = _s + 127; while(chr = getchar(), (chr == 32) || (chr == 10) || (chr == -1)) if(chr == -1) return 0; *en = 0; while(chr ^ 10 && chr ^ 32 && ~chr) { *be++ = chr, be != en ? chr = getchar() : (be = _s, s += _s, chr = getchar()); } *be = 0, s += _s; return 1; }
template<class T, class U>inline bool _scan(pair<T, U> &res) { return _scan(res.ff), _scan(res.ss); }
inline void _debug_() {}
template<class T>void _debug(T *x) { _out(x); }
template<class T>void _debug(T &x) { _out(x); }
template<class T, class U>inline void _debug(pair<T, U> &x) { _out('('), _out(x.ff), _out(", "), _out(x.ss), _out(')'); }
template<class T, class ...U>void _debug_(T head, U ...tail) { _out(' '), _debug(head), _debug_(tail...); }
template<class ...T>inline void debug(T ...tail) { static int cnt=0; _debug_("




struct basic_read { bool lock, flag; basic_read() : lock(1) {} void tie(bool x) { lock = x; } template<class T>basic_read operator >> (T &x) { return flag = (lock ? ptc(), _read(x) : _read(x)), *this; } template<class T> basic_read operator >> (T *x) { return flag = (lock ? ptc(), _read(x) : _read(x)), *this; } operator void *() const { return flag ? (void*)this : 0; } } Read;

struct basic_read { bool flag; template<class T>basic_read operator >> (T &x) { return flag = _read(x), *this; } template<class T> basic_read operator >> (T *x) { return flag = _read(x), *this; } operator void *() const { return flag ? (void*)this : 0; } } Read;

struct basic_out { template<class T>basic_out operator << (T x) { return _out(x), *this; } } Out;


template<class T, class U>inline istream& operator >> (istream &os,pair<T, U> &p) { return os >> p.first >> p.second; }
template<class T, class U>inline pair<T, U> operator + (const pair<T, U> &p1,const pair<T, U> &p2) { return mp(p1.ff + p2.ff, p1.ss + p2.ss); }
template<class T, class U>inline pair<T, U>& operator += (pair<T, U> &p1,const pair<T, U> &p2) { p1.ff += p2.ff, p1.ss += p2.ss; return p1; }
template<class T, class U>inline pair<T, U> operator - (const pair<T, U> &p1,const pair<T, U> &p2) { return mp(p1.ff - p2.ff, p1.ss - p2.ss); }
template<class T, class U>inline pair<T, U>& operator -= (pair<T, U> &p1,const pair<T, U> &p2) { p1.ff -= p2.ff, p1.ss -= p2.ss; return p1; }



const int       primes[7] = {24443, 100271, 1000003, 1000333, 5000321, 98765431, 1000000123};
const int       dx[] = { 0, 1, 0,-1, 0, 1,-1, 1,-1};
const int       dy[] = {-1, 0, 1, 0,-1, 1,-1,-1, 1};









inline int myrand(int mod) { return ((LL)rand() << 32 ^ (LL)rand() << 16 ^ rand()) % mod; }
inline int rand(int a, int b) { return a + myrand(b - a + 1); }
inline void normmod(long long &x, long long mod) { x %= mod; if(x < 0) x += mod; }

inline long long mulmod(long long x, long long n, long long mod, long long res = 0) { for(normmod(x, mod), normmod(n, mod); n; x <<= 1, res >= mod ? res -= mod : 0, x >= mod ? x -= mod : 0, n >>= 1) n & 1 ? res += x : 0; return res; }

inline long long mulmod(long long x, long long n, long long mod) { return __int128(x) * n % mod; }

inline long long pmod(long long x, long long n, long long mod = MOD, long long res = 1) { for(normmod(x, mod); n; x = mod ? x * x % mod : x * x, n >>= 1) n & 1 ? res = mod ? res * x % mod : res * x : 0; return res; }
inline long long id0(long long x, long long n, long long mod = MOD, long long res = 1) { for(normmod(x, mod); n; x = mulmod(x, x, mod), n >>= 1) n & 1 ? res = mulmod(res, x, mod) : 0; return res; }
template<class T>inline T gcd(T a, T b) { while(b) { T t = a % b, a = b, b = t; } return a; }
template<class T>inline T lcm(T a, T b) { return a / gcd(a, b) * b; }



void teble();
int main() {

    
    
    

    ios_base::sync_with_stdio(0);
    cin.tie(0);







    

    teble();
    ptc();
    return 0;
}








const int N=1e5+5;
char a[N];
vector<string> v;
bool cmp(string i,string j) {
    if(i.size()>j.size()||i.size()==j.size()&&i>=j)return 1;
    else return 0;
}
string s;

void teble() {
    int cnt=0,ans=1;
    cin>>a+1;
    FOR(i,1,strlen(a+1)) {
        if(a[i]!='0')v.pb(s+a[i]),++cnt;
        else v[cnt-1]+=a[i];
    }
    string str=v[0];
    debug(v);
    FOR(i,1,v.size()-1) {debug(cmp(str,v[i]),str,v[i],ans);
        if(cmp(str,v[i]))++ans;
        else ans=1;
        str+=v[i];
    }
    cout<<ans<<endl;
}









