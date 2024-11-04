
























using namespace std;

using ll = long long;
using ld = long double;
using db = double;
using str = string; 


using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;





tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
tcT> using PR = pair<T,T>;




























tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }









const ld PI = acos((ld)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; 

const int dxx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dyy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 





int bits(int x) { assert(x >= 0); return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id2(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 


tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } 

tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

tcTU> T fstTrue(T lo, T hi, U f) {
    hi ++; assert(lo <= hi); 

    while (lo < hi) { 

        T mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1;
    }
    return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
    lo --; assert(lo <= hi); 

    while (lo < hi) { 

        T mid = lo+(hi-lo+1)/2;
        f(mid) ? lo = mid : hi = mid-1;
    }
    return lo;
}
tcT> void remDup(vector<T>& v) { 

    sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { 

    auto it = t.find(u); assert(it != end(t));
    t.erase(it); } 





tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(V<T>& v);
tcT, size_t SZ> void re(AR<T,SZ>& a);

tcT> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }

tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.first,p.second); }
tcT> void re(V<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { trav(a,x) re(a); }
tcT> void rv(int n, V<T>& x) { x.rsz(n); re(x); }




str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) {
    
        return b ? "true" : "false";
    
        return ts((int)b);
    
}
tcT> str ts(complex<T> c) {
    stringstream ss; ss << c; return ss.str(); }
str ts(V<bool> v) {
    str res = "{"; id1(i,sz(v)) res += char('0'+v[i]);
    res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
    str res = ""; id1(i,SZ) res += char('0'+b[i]);
    return res; }
tcTU> str ts(pair<T,U> p);
tcT> str ts(T v) { 

    
        bool fst = 1; str res = "{";
        for (const auto& x: v) {
            if (!fst) res += ", ";
            fst = 0; res += ts(x);
        }
        res += "}"; return res;
    
        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += " ";
            fst = 0; res += ts(x);
        }
        return res;

    
}
tcTU> str ts(pair<T,U> p) {
    
        return "("+ts(p.first)+", "+ts(p.second)+")";
    
        return ts(p.first)+" "+ts(p.second);
    
}



tcT> void pr(T x) { cout << ts(x); }
tcTUU> void pr(const T& t, const U&... u) {
    pr(t); pr(u...); }
void ps() { pr("\n"); } 

tcTUU> void ps(const T& t, const U&... u) {
    pr(t); if (sizeof...(u)) pr(" "); ps(u...); }



void DBG() { cerr << "]" << endl; }
tcTUU> void DBG(const T& t, const U&... u) {
    cerr << ts(t); if (sizeof...(u)) cerr << ", ";
    DBG(u...); }


    
    
    
         << __FUNCTION__  << ") -> CHK FAILED: (" << 

    
    
    



void setPrec() { cout << fixed << setprecision(15); }
void id3() { cin.tie(0)->sync_with_stdio(0); }


void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void setIO(str s = "") {
    id3(); setPrec();
    

    

    

    if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

}


ifstream fin("input.txt");
ofstream fout("output.txt");





const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll INF = 1e18; 


void solve(){
}
int main(){
    fast_cin();
    int r;
    auto ask = [&](int a, int b, int c) {
        int d;
        cout << "? " << a << " " << b << " " << c << endl;
        cin >> d;
        return d;
    };
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        int n;
        cin >> n;
        int m = n/3;
        vector<int> f(n+1, -1);

        vector<int> result(m);
        vector<int> idx23, idx01;
        id1(i,m) {
            result[i] = ask(i*3+1, i*3+2, i*3+3);
            if (result[i] == 0) idx23.push_back(i*3+1);
            else idx01.push_back(i*3+1);
        }
        vector<int> c0, c1;

        auto test1 = [&](int a, int b) {
            r = ask(a, a+1, b);
            if (r == 0) {
                c1.push_back(b);
                c0.push_back(a+2);
            }
            else {
                r = ask(a, a+1, b+1);
                if (r == 0) {
                    c1.push_back(b+1);
                    c0.push_back(a+2);
                }
                else {
                    r = ask(a, a+1, b+2);
                    if (r == 0) {
                        c1.push_back(b+2);
                        c0.push_back(a+2);
                    }
                    else {
                        c0.push_back(a);
                        c0.push_back(a+1);

                        r = ask(a+2, b, b+1);
                        if (r == 0) {
                            r = ask(a, b, b+1);
                            if (r == 0) {
                                c1.push_back(b);
                                c1.push_back(b+1);
                            }
                            else {
                                c1.push_back(a+2);
                            }
                        }
                        else {
                            c0.push_back(a+2);
                            c1.push_back(b+2);
                        }
                    }
                }
            }
        };

        auto id0 = [&](int a, int b) {
            int r1 = ask(a+1,a+2,b);
            int r2 = ask(a+2,b,b+1);
            if (r1 == 0) {
                c0.push_back(a);
                c1.push_back(b);
            }
            else if (r2 == 0) {
                c0.push_back(a+1);
                c1.push_back(b+1);
            }
            else {
                c0.push_back(a+2);
                c1.push_back(b+2);
            }
        };

        assert(!idx01.empty());
        assert(!idx23.empty());
        id0(idx01[0], idx23[0]);

        auto test2 = [&](int x) {
            if (x < 1 || x > n || f[x] != -1) return;
            int idx = (x-1) / 3;
            int a = idx * 3 + 1;
            int b = a+1, c = a+2;
            vector<int> cnt(3);
            cnt[f[a]+1]++;
            cnt[f[b]+1]++;
            cnt[f[c]+1]++;
            if (cnt[0] == 3) return;
            if (cnt[0] == 2) {
                if (result[idx] == 1) {
                    if (cnt[2] == 1) {
                        f[x] = 0;
                        if (f[a] == -1) f[a] = 0;
                        if (f[b] == -1) f[b] = 0;
                        if (f[c] == -1) f[c] = 0;
                    }
                }
                else {
                    if (cnt[1] == 1) {
                        f[x] = 1;
                        if (f[a] == -1) f[a] = 1;
                        if (f[b] == -1) f[b] = 1;
                        if (f[c] == -1) f[c] = 1;
                    }
                }
                return;
            }
            if (result[idx] == 1) {
                if (cnt[1] < 2) {
                    f[x] = 0;
                }
            }
            else {
                if (cnt[2] < 2) {
                    f[x] = 1;
                }
            }
        };

        for (auto x: c0) f[x] = 0;
        for (auto x: c1) f[x] = 1;

        

        

        

        

        

        

        

        

        int a = c0[0], b = c1[0];
        for (int i = 0; i < m; i++) {
            int left = i * 3 + 1, right = i * 3 + 3;
            int cnt = (f[left] >= 0) + (f[left+1] >= 0) + (f[left+2] >= 0);
            if (cnt > 0) {
                for (int j = left; j <= right; j++) {
                    if (f[j] == -1) {
                        r = ask(a,b,j);
                        if (r == 0) f[j] = 1;
                        else f[j] = 0;
                    }
                }
            }
            else {
                if (result[i] == 1) {
                    r = ask(left, left+1, b);
                    if (r == 0) {
                        f[right] = 0;
                        r = ask(left, a, b);
                        if (r == 0) {
                            f[left] = 1;
                            f[left+1] = 0;
                        }
                        else {
                            f[left] = 0;
                            f[left+1] = 1;
                        }
                    }
                    else {
                        f[left] = f[left+1] = 0;
                        r = ask(right, a, b);
                        if (r == 0) f[right] = 1;
                        else f[right] = 0;
                    }
                }
                else {
                    r = ask(left, left+1, a);
                    if (r == 0) {
                        f[left] = f[left+1] = 1;
                        r = ask(a,b,right);
                        if (r == 0) f[right] = 1;
                        else f[right] = 0;
                    }
                    else {
                        f[right] = 1;
                        r = ask(left, a, b);
                        if (r == 0) f[left] = 1, f[left+1] = 0;
                        else f[left] = 0, f[left+1] = 1;
                    }
                }
            }
        }

        c0.clear();
        c1.clear();
        for (int i = 1; i <= n; i++)
            if (f[i] == 1) c1.push_back(i);
            else if (f[i] == 0) c0.push_back(i);

        cout << "! " << c1.size();
        for (auto x: c1) cout << " " << x;
        cout << endl;
    }
    return 0;
}