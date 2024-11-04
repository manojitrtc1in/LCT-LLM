



typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class T>
using ordered_greater_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;























template<class T> bool umin(T& a, const T& b) {return b<a?a=b, 1:0;}
template<class T> bool umax(T& a, const T& b) {return a<b?a=b, 1:0;}
ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb)/2;
        f(mb)?rb=mb:lb=mb+1;
    }
    return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb+1)/2;
        f(mb)?lb=mb:rb=mb-1;
    }
    return lb;
}
struct Point {
    double x, y;
    Point(double x=0, double y=0):x(x),y(y) { }
};
template<class A> void read(vt<A>& v);
template<class A> void read(Point& v);
template<class A, size_t S> void read(array<A, S>& a);
template<class H, class T> void read(pair<H,T>&c);
template<class H, class T> void read(Point &c);
template<class T> void read(T& x) {cin >> x;}
void read(double& d) {string t;read(t);d=stod(t);}
void read(long double& d) {string t;read(t);d=stold(t);}
void read(Point &c){read(c.x);read(c.y);}
template<class H, class T> void read(pair<H,T>&c){read(c.first);read(c.second);}
template<class H, class... T> void read(H& h, T&... t) {read(h);read(t...);}
template<class A> void read(vector<A>& x) {EACH(a, x)read(a);}
template<class A, size_t S> void read(array<A, S>& x) {EACH(a, x)read(a);}
template <class T> string to_string(T v);
template<class T,class U> string to_string(pair<T,U> a);
string to_string(char c) {return string(1, c);}
string to_string(bool b) {return b?"true":"false";}
string to_string(const char* s) {return string(s);}
string to_string(string s) {return s;}
string to_string(Point c) {return to_string(c.x)+":"+to_string(c.y);}
string to_string(vector<bool> v) {
    string res;
    FOR(sz(v))res+=char('0'+v[i]);
    return res;
}
template<size_t S> string to_string(bitset<S> b) {
    string res;
    FOR(S)res+=char('0'+b[i]);
    return res;
}

template <class T> string to_string(T v) {
    char c=' ';int brace=0;
    if constexpr (std::is_same_v<T, vt<vt<int>>>) c='\n';
    if constexpr (std::is_same_v<T, vt<vt<vt<int>>>>) c='\n';
    if constexpr (std::is_same_v<T, vt<vt<ll>>>) c='\n';
    if constexpr (std::is_same_v<T, vt<vt<vt<ll>>>>) c='\n';
    if constexpr (std::is_same_v<T, vt<vt<double>>>) c='\n';
    if constexpr (std::is_same_v<T, vt<vt<vt<double>>>>) c='\n';
    if(c=='\n')brace=1;
    bool f=1;
    string res;
    EACH(x, v) {
        if(!f)res+=c;
        f=0;
        if(brace)res+="["+ to_string(x)+"]";
        else res+=to_string(x);
    }
    return res;
}
template<class T,class U> string to_string(pair<T,U> a){return to_string(a.first)+":"+to_string(a.second);}

template<class A> void write(A x) {cout << to_string(x);}
template<class H, class... T> void write(const H& h, const T&... t) {write(h);write(t...);}
template<class H, class... T> void print(const H& h, const T&... t);
void print() {write("\n");}
template<class H, class... T> void print(const H& h, const T&... t) {
    write(h);
    if(sizeof...(t))write(' ');
    print(t...);
}
void DBG() {cout << "]" << endl;}
template<class H, class... T> void DBG(H h, T... t) {
    cout << to_string(h);
    if(sizeof...(t))
        cout << ", ";
    DBG(t...);
}







template<class T> void offset(ll o, T& x) {x+=o;}
template<class T> void offset(ll o, vt<T>& x) {
    EACH(a, x)offset(o, a);
}
template<class T, size_t S> void offset(ll o, array<T, S>& x) {
    EACH(a, x)offset(o, a);
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = id4,long long r = id0){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
struct custom_hash { 

    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t id1 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id1);
    }
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t id1 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + id1);
    }
};
template<class T, class U> void vtini(vt<T> &v, U x, size_t n) {v=vt<T>(n, x);}
template<class T, class U> void vtini(vt<T> &v, U x, size_t n, size_t m...) {
    v=vt<T>(n);
    EACH(a, v)vtini(a, x, m);
}

const int id2 = 18;


ll const MOD=1e9+7;

template <int MOD_> struct modnum {
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");
private:
    using ll = long long;
    int v;
    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }
public:
    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
    friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
    friend string to_string(modnum& n){return to_string(n.v);}
    friend void read(int &n){cin>>n;}
    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum inv() const {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    friend modnum inv(const modnum& m) { return m.inv(); }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD-v : 0;
        return res;
    }
    friend modnum neg(const modnum& m) { return m.neg(); }

    modnum operator- () const {
        return neg();
    }
    modnum operator+ () const {
        return modnum(*this);
    }

    modnum& operator ++ () {
        v ++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator -- () {
        if (v == 0) v = MOD;
        v --;
        return *this;
    }
    modnum& operator += (const modnum& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    modnum& operator -= (const modnum& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    modnum& operator *= (const modnum& o) {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum& operator /= (const modnum& o) {
        return *this *= o.inv();
    }
    friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
    friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

template <typename T,typename U>
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {
    return {l.first+r.first,l.second+r.second};
}
template <typename T,typename U>
std::pair<T,U> operator+(const std::pair<T,U> & l,T &r) {return l+mp(r,r);}
template <typename T,typename U>
std::pair<T,U> operator- (const std::pair<T,U> & l) {return mp(-l.first,-l.second);}
template <typename T,typename U>
std::pair<T,U> operator-(const std::pair<T,U> & l,const std::pair<T,U> & r) {return l+(-r);}
template <typename T,typename U>
std::pair<T,U> operator-(const std::pair<T,U> & l,T &r) {return l-mp(r,r);}
template <typename T,typename U>
std::pair<T,U> operator*(const std::pair<T,U> & l,const std::pair<T,U> & r) {return {l.first*r.first,l.second*r.second};}
template <typename T,typename U>
std::pair<T,U> operator*(const std::pair<T,U> & l,T &r) {return l*mp(r,r);}
template <typename T,typename U>
bool id3(const std::pair<T,U> & l,T lx0,T lx1, U ly0, U ly1){
    return l.first>=lx0 && l.first<lx1 && l.second>=ly0 && l.second<ly1;
};
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const pair<int,int> pairdir[]={{0,1},{0,-1},{1,0},{-1,0}};
inline bool inboard(int y,int x,int n,int m){return y>=0 && x >=0 && y<n && x<m;}
template<class F>
struct fHelper:F{
    explicit fHelper(F&& f):F(forward<F>(f)){}
    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const{
        return F::operator()(*this,forward<Args>(args)...);
    }
};
template<class F>
inline decltype(auto) Recur(F&&f){return fHelper<F>{forward<F>(f)};}






using mint = modnum<MOD>;
const int MAXN = 2e5+20;
using pii=pair<int,int>;

void solve(){
    ll s0,d0,n0,s1,d1,n1;
    read(s0,d0,n0,s1,d1,n1);
    auto setp=[&](ll i){return i>=s0 &&(i-s0)%d0==0 && (i-s0)/d0<n0;};

    vt<ll> v0={s1,min(s1+d1,s1+d1*(n1-1)),s1+d1*(n1-1)};
    vt<ll> v1={s1-d1,s1+d1*n1};








    FOR(i,3)if(!setp(v0[i])){ print("0");return;}
    FOR(i,2)if(!setp(v1[i])){ print("-1");return;}
    if(d1==1 || !setp(s1-d1) || !setp(s1+d1*n1)){ print("-1");}

    auto primes=[&](ll num){
        vt<ll>p;
        p.clear();
        for(ll i=2; i*i<=num; i++){
            if(num%i==0){
                p.push_back((ll)i);
                while(num%i==0) num/=i;
            }
        }
        if(num>1)
            p.push_back((ll)num);
        return p;
    };
    vt<ll>pb=primes(d0);






    mint ans=1;
    EACH(p, pb){
        mint cur=1;
        int cnt0=0,cnt1=0;
        while(d0%p==0)cnt0++,d0/=p;
        while(d1%p==0)cnt1++,d1/=p;
        

        if(cnt0!=cnt1)continue;

        mint curp=p;
        for (int i = 0; i < cnt1; i++,curp*=p) {
            cur+=curp*curp;
        }


        ans*=cur;
    }
    print(ans);
}
int main() {








    int t=1, i=1;
    read(t);
    while(t--) {
        

        solve();
        ++i;
    }
    return 0;
}





