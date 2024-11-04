





using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;






typedef long long int ll;
typedef unsigned long long int ull;








































using Int = __int128;

const long double PI = acos(-1);



mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}


template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T>>;

template<class T>
using max_heap = priority_queue<T>;


template<class T> istream& operator >> (istream &is, vector<T>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}
template<class T> istream& operator >> (istream &is, pair<T,T>& V) {
    is >> V.F >> V.S;
    return is;
}
template<class T, size_t N> istream& operator >> (istream &is, array<T, N>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}


ostream& operator << (ostream &os, __int128 const& value){
    static char buffer[64];
    int index = 0;
    __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
    if (value < 0) 
        os << '-';
    else if (T == 0)
        return os << '0';
    for(; T > 0; ++index){
        buffer[index] = static_cast<char>('0' + (T % 10));
        T /= 10;
    }    
    while(index > 0)
        os << buffer[--index];
    return os;
}
istream& operator >> (istream& is, __int128& T){
    static char buffer[64];
    is >> buffer;
    size_t len = strlen(buffer), index = 0;
    T = 0; int mul = 1;
    if (buffer[index] == '-')
        ++index, mul *= -1;
    for(; index < len; ++index)
        T = T * 10 + static_cast<int>(buffer[index] - '0');
    T *= mul;    
    return is;
}

template<typename CharT, typename Traits, typename T>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, T const &val) {
    return (out << val << " ");
}
template<typename CharT, typename Traits, typename T1, typename T2>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, pair<T1, T2> const &val) {
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename CharT, typename Traits, template<typename, typename...> class TT, typename... Args>
ostream& operator << (std::basic_ostream<CharT, Traits> &out, TT<Args...> const &cont) {
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");
}
template<class L, class R> ostream& operator << (ostream& out, pair<L, R> const &val){
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename L, size_t N> ostream& operator << (ostream& out, array<L, N> const &cont){
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");    
}
template<class T> ostream& operator<<(ostream &out, ordered_set<T> const& S){
    out << "{ ";
    for(const auto& s:S) out << s << " ";
    return (out << "}");
}
template<class L, class R, class chash = std::hash<L> > ostream& operator << (ostream &out, gp_hash_table<L, R, chash> const& M) {
    out << "{ ";
    for(const auto& m: M) out << "(" << m.first << ":" << m.second << ") ";
    return (out << "}");
}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
    static priority_queue<P, Q, R> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.top() << " ", U.pop();
    return (out << "}");
}
template<class P> ostream& operator << (ostream& out, queue<P> const& M){
    static queue<P> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.front() << " ", U.pop();
    return (out << "}");
}


    
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }

    


ll id0(ll a, ll b, ll *x, ll *y){
    if(a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = id0(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
 
ll modInverse(ll a, ll m){
    ll x, y;
    ll g = id0(a, m, &x, &y);
        ll res = (x%m + m) % m;
        return res;
}

ll binary_Search(vector<ll>&arr,ll key){
    ll l=0,r=arr.size()-1;
    ll ans;
    while(l<=r){
        ll mid=(l+r)/2;
        ll value=arr[mid];
        if(value>key){
            r=mid-1;
        }else if(value==key){
            return mid;
        }else{
            l=mid+1;
        }
    }
    return -1;
}
 
ll power(ll x,ll y,ll p){
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0){  
        if (y & 1){
            res=(res*x)%p;
        }
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}



























const ll MAX=1e18+5;
const int N=1e5+5;
vector<int> pr;

























































const ll mod=1e9+7;
const ll mod1=998244353;

const int inf = 1e9;
const ll INF=1e18;



void precompute(){
    
}

const int MOD=1e9+7;

struct Mint {
    int val;
 
    Mint(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        } 
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const {
        return val;
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           
                return x % m;
           
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const {
        return mod_inv(val);
    }
    Mint power(long long p) const {
        assert(p >= 0);
        if(p>=MOD){
            p%=(MOD-1);
        }
        Mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Mint &m) {
        return stream>>m.val;   
    }
};

struct my_node{
    Mint mn;

    my_node(){}
    my_node(Mint val){
        mn = val;
        

    }
    void merge(const my_node &l,const my_node &r){
        mn=l.mn+r.mn;
    }
};
 




 


 
struct my_update{
    Mint v = 1; 

    my_update(){}
    my_update(Mint val){
        v = val; 

    }
    
    void combine(my_update &other,const int32_t &tl,const int32_t &tr){
        v+=other.v;
    }
    
    void apply(my_node &x,const int32_t &tl,const int32_t &tr){
        x.mn+=v;
    }
};
 
template<typename node,typename update>
struct id3{
    int len;
    vector<node> t;
    vector<update> u;
    vector<bool> lazy;
    node identity_element;
    update id1;
    id3(int l){
        len = l;
        t.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node();
        id1 = update();
    }
 
    void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr){
        if(!lazy[v]) return;
        int32_t tm = (tl + tr) >> 1;
        apply(v<<1,tl,tm,u[v]);
        apply(v<<1|1,tm+1,tr,u[v]);
        u[v] = id1;
        lazy[v] = 0;
    }
 
    void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd){
        if(tl != tr){
            lazy[v] = 1;
            u[v].combine(upd,tl,tr);
        }
        upd.apply(t[v],tl,tr);
    }
 
    template<typename T>
    void build(const T &arr,const int32_t &v, const int32_t &tl, const int32_t &tr){
        if(tl == tr){
            t[v] = arr[tl];
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr,v<<1,tl,tm);
        build(arr,v<<1|1,tm+1,tr);
        t[v].merge(t[v<<1],t[v<<1|1]);
    }
 
    node query(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r){
        if(l > tr || r < tl){
            return identity_element;
        }
        if(tl >= l && tr <= r){
            return t[v];
        }
        pushdown(v,tl,tr);
        int32_t tm = (tl + tr) >> 1;
        node a = query(v<<1,tl,tm,l,r),b = query(v<<1|1,tm+1,tr,l,r),ans;
        ans.merge(a,b);
        return ans;
    }
 
    

    void rupd(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,const update &upd){
        if(l > tr || r < tl){
            return;
        }
        if(tl >= l && tr <= r){
            apply(v,tl,tr,upd);
            return;
        }
        pushdown(v,tl,tr);
        int32_t tm = (tl + tr) >> 1;
        rupd(v<<1,tl,tm,l,r,upd);
        rupd(v<<1|1,tm+1,tr,l,r,upd);
        t[v].merge(t[v<<1],t[v<<1|1]);
    }

    void query1(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,Mint &r){
        if(tl==tr){
            t[v]=r;
            return;
        }
        pushdown(v,tl,tr);
        int32_t tm = (tl + tr) >> 1;
        if(tm>=l) query1(v<<1,tl,tm,l,r);
        else query1(v<<1|1,tm+1,tr,l,r);
        t[v].merge(t[v<<1],t[v<<1|1]);
    }
 
    public:
    template<typename T>
    void build(const T &arr){
        build(arr,1,0,len-1);
    }
    node query(const int32_t &l,const int32_t &r){
        return query(1,0,len-1,l,r);
    }

    void query1(const int32_t &l,Mint &r){
         query1(1,0,len-1,l,r);
    }

    void rupd(const int32_t &l,const int32_t &r,const update &upd){
        rupd(1,0,len-1,l,r,upd);
    }
};



struct compare {
    bool operator()(const pii &l,const pii &r) const {
        return (l.F*r.S)<(l.S*r.F);
    }
};

const int N1=2*1e5+5;

void trans(vi &v){
    int n=v.size();
    set<int> s;
    for(auto i:v){
        s.insert(i);
    }
    int cur=0;
    map<int,int> m;
    for(auto i:s){
        m[i]=cur++;
    }
    for(auto &i:v){
        i=m[i];
    }
}

struct frac {
    ll p, q;
 
    void simplify() {
        if(q < 0){
            p *= -1;
            q *= -1;
        }
        ll g = __gcd(p < 0 ? -p : p, q);
        if(g) {
            p /= g;
            q /= g;
        }
    }
    template<typename T=ll>
    frac(T p = 0, T q = 1) : p(p), q(q) { simplify(); }
 
    bool operator <(const frac &other) const { return (Int) p * other.q < (Int) q * other.p; }
    bool operator >(const frac &other) const { return  (Int) p * other.q > (Int) q * other.p; }
    bool operator ==(const frac &other) const { return (Int) p * other.q == (Int) q * other.p; }
    bool operator <=(const frac &other) const { return *this < other || *this == other; }
    bool operator >=(const frac &other) const { return *this > other || *this == other; }
    bool operator !=(const frac& other) const { return (Int) p * other.q != (Int) q * other.p; }

    template <class T> bool operator <(const T &other) const { return *this < frac(other); }
    template <class T> bool operator >(const T &other) const { return *this > frac(other); }
    template <class T> bool operator ==(const T &other) const { return *this == frac(other); }
    template <class T> bool operator >=(const T &other) const { return *this >= frac(other); }
    template <class T> bool operator <=(const T &other) const { return *this <= frac(other); }
    template <class T> bool operator !=(const T &other) const { return *this != frac(other); }
 
    frac &operator +=(const frac &r) {
        int g = __gcd(q, r.q);
        p = r.q / g * p + q / g * r.p;
        q = q / g * r.q;
        (*this).simplify();
        return *this;
    }
     
    frac &operator -=(const frac &r) {
        int g = __gcd(q, r.q);
        p = r.q / g * p - q / g * r.p;
        q = q / g * r.q;
        (*this).simplify();
        return *this;
    }
 
    frac &operator *=(const frac &r) {
        p *= r.p;
        q *= r.q;
        (*this).simplify();
        return *this;
    }
 
    frac &operator /=(const frac &r) {
        p *= r.q;
        q *= r.p;
        (*this).simplify();
        return *this;
    }

    void reci() { assert(p != 0); swap(p, q); }

    void scan() {
        cin >> p >> q;
    }
    void print() const {
        cout << p << " " << q << endl;
    }
    void eprint() const {
        cout << p << "/" << q << endl;
    }
 
    frac operator +(const frac r) const { return frac(p, q) += r; }
    frac operator -(const frac r) const { return frac(p, q) -= r; }
    frac operator *(const frac r) const { return frac(p, q) *= r; }
    frac operator /(const frac r) const { return frac(p, q) /= r; }
};

istream& operator>>(std::istream& is,frac &f){   
    is >> f.p >> f.q;
    return is;
}

ostream& operator<<(std::ostream& os, frac &f){
    return os << f.p << "/" << f.q << '\n';
}

void TEST_CASE(){
    int n,m;
    cin >> n >> m;
    vector<vector<ll>> st(m);
    vector<frac> teach(n);
    vector<pair<frac,ll>> avg(m);
    vector<vi> ans(m);
    for(int i=0 ; i<n ; i++){
        ll x;
        cin >> x;
        teach[i]=frac(x);
    }
    for(int i=0 ; i<m ; i++){
        ll len;
        cin >> len;
        ans[i].resize(len);
        ll tot=0;
        for(int j=0 ; j<len ; j++){
            ll x;
            cin >> x;
            tot+=x;
            st[i].pb(x);
        }
        avg[i]={frac(tot,len),i};
    }
    sort(all(avg),greater<pair<frac,ll>>());
    sort(all(teach),greater<frac>());
    while(teach.size()>m) teach.pop_back();
    reverse(all(teach));
    reverse(all(avg));
    vector<int> pref(m+2),suf(m+2),pref1(m+2),id2(m+2);
    for(int i=0 ; i<m ; i++){
        if(teach[i]>=avg[i].F){
            pref[i]=suf[i]=1;
        }else{
            pref[i]=suf[i]=0;
        }
        if(i<m-1){
            if(avg[i+1].F<=teach[i]){
                id2[i]=1;
            }else{
                id2[i]=0;
            }
        }else{
            id2[i]=1;
        }
        if(i>0){
            if(avg[i-1].F<=teach[i]){
                pref1[i]=1;
            }else{
                pref1[i]=0;
            }
        }else{
            pref1[i]=1;
        }
    }
    for(int i=1 ; i<m ; i++){
        pref[i]+=pref[i-1];
        pref1[i]+=pref1[i-1];
        id2[i]+=id2[i-1];
    }
    for(int i=m-2 ; i>=0 ; i--){
        suf[i]+=suf[i+1];
    }
    for(int ind=0 ; ind<m ; ind++){
        int i=avg[ind].S;
        ll tot=0;
        ll siz=st[i].size();
        for(auto j:st[i]){
            tot+=j;
        }
        for(int j=0 ; j<st[i].size() ; j++){
            frac new_avg = frac(tot-st[i][j],siz-1);
            if(new_avg==avg[ind].F){
                ans[i][j]=(pref[m-1]==m);
            }else if(new_avg>avg[ind].F){
                int l=ind,r=m-1,mid,pos=m-1;
                while(l<=r){
                    mid=(l+r)/2;
                    if(avg[mid].F<=new_avg){
                        pos=mid;
                        l=mid+1;
                    }else{
                        r=mid-1;
                    }
                }
                if(pos==ind){
                    if(new_avg>teach[ind] || (ind>0 && pref[ind-1]!=ind) || (ind<m-1 && suf[ind+1]!=(m-ind-1))){
                        ans[i][j]=0;
                    }else{
                        ans[i][j]=1;
                    }
                    continue;
                }
                int ok;
                if(ind==0){
                    ok=1;
                    ok&=(id2[pos-1]==pos);
                    ok&=(teach[pos]>=new_avg);
                    if(pos<m-1){
                        ok&=(suf[pos+1]==(m-pos-1));
                    }
                }else{
                    ok=(pref[ind-1]==ind);
                    ok&=((id2[pos-1]-id2[ind-1])==(pos-ind));
                    ok&=(teach[pos]>=new_avg);
                    if(pos<m-1){
                        ok&=(suf[pos+1]==(m-pos-1));
                    }
                }
                ans[i][j]=ok;
            }else{
                int l=0,r=ind,mid,pos=0;
                while(l<=r){
                    mid=(l+r)/2;
                    if(avg[mid].F<=new_avg){
                        l=mid+1;
                    }else{
                        pos=mid;
                        r=mid-1;
                    }
                }
                if(pos==ind){
                    if(new_avg>teach[ind] || (ind>0 && pref[ind-1]!=ind) || (ind<m-1 && suf[ind+1]!=m-ind-1)){
                        ans[i][j]=0;
                    }else{
                        ans[i][j]=1;
                    }
                    continue;
                }
                int ok;
                if(ind==m-1){
                    ok=1;
                    ok&=(pref1[ind]-pref1[pos]==ind-pos);
                    ok&=(teach[pos]>=new_avg);
                    if(pos>0){
                        ok&=(pref[pos-1]==pos);
                    }
                }else{
                    ok=(suf[ind+1]==m-ind-1);
                    ok&=(pref1[ind]-pref1[pos]==ind-pos);
                    ok&=(teach[pos]>=new_avg);
                    if(pos>0){
                        ok&=(pref[pos-1]==pos);
                    }
                }
                ans[i][j]=ok;
            }
        }
    }
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<ans[i].size() ; j++){
            cout << ans[i][j];
        }
    }
    cout << endl;
}

signed main(){
    fast;
    

    

    int test=1,TEST=1;
    auto start = std::chrono::high_resolution_clock::now();
    precompute();
    cin >> test;
    while(test--){
        

        TEST_CASE();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    

    return 0;
}