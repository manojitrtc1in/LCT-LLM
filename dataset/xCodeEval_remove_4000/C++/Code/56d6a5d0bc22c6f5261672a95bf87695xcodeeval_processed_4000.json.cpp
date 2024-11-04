

 



 
 



 


using namespace std;
 


typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef map<int,int> m32;
typedef map<ll,ll> m64;
 
 
double eps = 1e-12;
 
double pi = acos(-1);
 














 


 

 
template<typename T>
void __p(T a) {
    cout<<a;
}
template<typename T, typename F>
void __p(pair<T, F> a) {
    cout<<"{";
    __p(a.first);
    cout<<",";
    __p(a.second);
    cout<<"}";
}
template<typename T>
void __p(std::vector<T> a) {
    cout<<"{";
    for(auto it=a.begin(); it<a.end(); it++)
        __p(*it),cout<<",}"[it+1==a.end()];
}
template<typename T>
void __p(std::set<T> a) {
    cout<<"{";
    for(auto it=a.begin(); it!=a.end();){
        __p(*it);
        cout<<",}"[++it==a.end()];
    }
 
}
template<typename T>
void __p(std::multiset<T> a) {
    cout<<"{";
    for(auto it=a.begin(); it!=a.end();){
        __p(*it);
        cout<<",}"[++it==a.end()];
    }
}
template<typename T, typename F>
void __p(std::map<T,F> a) {
    cout<<"{\n";
    for(auto it=a.begin(); it!=a.end();++it)
    {
        __p(it->first);
        cout << ": ";
        __p(it->second);
        cout<<"\n";
    }
    cout << "}\n";
}
 
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
    __p(a1);
    __p(a...);
}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout<<name<<" : ";
    __p(arg1);
    cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket=0,i=0;
    for(;; i++)
        if(names[i]==','&&bracket==0)
            break;
        else if(names[i]=='(')
            bracket++;
        else if(names[i]==')')
            bracket--;
    const char *comma=names+i;
    cout.write(names,comma-names)<<" : ";
    __p(arg1);
    cout<<" | ";
    __f(comma+1,args...);
}







 
template<const int &MOD>
struct _m_int {
    int val;
 
    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _m_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _m_int(int v) : _m_int(int64_t(v)) {}
    _m_int(unsigned v) : _m_int(uint64_t(v)) {}
 
    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }
 
    _m_int& operator+=(const _m_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    _m_int& operator-=(const _m_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {

        return unsigned(x % m);

        

        

        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }
 
    _m_int& operator*=(const _m_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }
 
    _m_int& operator/=(const _m_int &other) {
        return *this *= other.inv();
    }
 
    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }
 
    _m_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    _m_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    _m_int operator++(int) { _m_int before = *this; ++*this; return before; }
    _m_int operator--(int) { _m_int before = *this; --*this; return before; }
 
    _m_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
    friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
    friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
    friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
    friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }
 
    static const int SAVE_INV = int(1e6) + 5;
    static _m_int save_inv[SAVE_INV];
 
    static void prepare_inv() {
        

        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);
 
        save_inv[0] = 0;
        save_inv[1] = 1;
 
        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }
 
    _m_int inv() const {
        if (save_inv[1] == 0)
            prepare_inv();
 
        if (val < SAVE_INV)
            return save_inv[val];
 
        _m_int product = 1;
        int v = val;
 
        while (v >= SAVE_INV) {
            product *= MOD - MOD / v;
            v = MOD % v;
        }
 
        return product * save_inv[v];
    }
 
    _m_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);
 
        _m_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            p >>= 1;
 
            if (p > 0)
                a *= a;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &os, const _m_int &m) {
        return os << m.val;
    }
};
 
template<const int &MOD> _m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];
 
const int MOD = 998244353;
const int mod = 1000000007;
using mod_int = _m_int<MOD>;
 
 
vector<mod_int> _factorial = {1, 1}, id0 = {1, 1};
 
void id2(int64_t maximum) {
    static int64_t id3 = 1;
 
    if (maximum <= id3)
        return;
 
    

    maximum += maximum / 64;
    _factorial.resize(maximum + 1);
    id0.resize(maximum + 1);
 
    for (int64_t i = id3 + 1; i <= maximum; i++)
        _factorial[i] = i * _factorial[i - 1];
 
    id0[maximum] = _factorial[maximum].inv();
 
    for (int64_t i = maximum - 1; i > id3; i--)
        id0[i] = (i + 1) * id0[i + 1];
 
    id3 = maximum;
}
 
mod_int factorial(int64_t n) {
    if (n < 0) return 0;
    id2(n);
    return _factorial[n];
}
 
mod_int id4(int64_t n) {
    if (n < 0) return 0;
    id2(n);
    return id0[n];
}
 
mod_int choose(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    id2(n);
    return _factorial[n] * id0[r] * id0[n - r];
}
 
mod_int permute(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    id2(n);
    return _factorial[n] * id0[n - r];
}
 
mod_int inv_choose(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    id2(n);
    return id0[n] * _factorial[r] * _factorial[n - r];
}
 
mod_int id1(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    id2(n);
    return id0[n] * _factorial[n - r];
}
 


 



















































 


 
void solve(int it)
{
    int n,q;
    cin>>n>>q;
    int a[n+1];
    map<int,int> m;
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        m[i] = a[i];
        sum += a[i];
    }
    int y = 0;
    for(int j=0;j<q;j++)
    {
        int b;
        cin>>b;
        if(b==1)
        {
            int i,x;
            cin>>i>>x;
            if(m[i]==0)
            {
                sum += (x-y);
            }
            else
            {
                sum += (x-m[i]);
            }
            m[i] = x;
        }
        else
        {
            int x;
            cin>>x;
            m.clear();
            y = x;
            sum = n*y;
        }
        cout<<sum<<nl;
    }
}
signed main()
{
    fast_cin();
    

    

    

    ll t=1;
    

    for(int it=1;it<=t;it++)
    {
        solve(it);
    }
    cerr<<"time taken : "<<(float)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
    return 0;
}


















 




































 
















 




 






 




 
























 






    




    


















 








































































































 


















































































    





    



