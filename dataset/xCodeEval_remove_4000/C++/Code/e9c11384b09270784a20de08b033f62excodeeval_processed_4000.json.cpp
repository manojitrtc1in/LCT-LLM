

 




using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
 


const long long infty = 1e18;
















 
 
typedef long long ll;
typedef long long unsigned int llu;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<int> vii;
 



 
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
 
template <typename T> T pow(T a, long long b) {
    assert(b >= 0);
    T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}


using num = modnum<998244353>;




ll mod = 998244353;


const int N = 5e5+5;
ll fact[N] ,inv_fact[N];
 
long long powm(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a %mod;
        a = a * a %mod;
        b >>= 1;
    }
    return res;
}
 
void id1(){
    fact[0] = 1;
    for(int i = 1;i<N;i++){
        fact[i] = fact[i-1]*i % mod;
    }
 
    inv_fact[N-1] = powm(fact[N-1],mod-2);
 
    for(int i = N-2;i>=0;i--){
        inv_fact[i] = inv_fact[i+1]*(i+1) % mod;
        

    }
}
 
 


 




















 


























ll modInverse(ll a, ll m){
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
 
        

        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
ll gcd (ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}





















































































































































struct Matrix{
    vector<vector<ll>> a;
    ll n = 0;
    Matrix operator *(Matrix &other){
        Matrix product;
        product.n = n;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<n;j++){
                for(ll k = 0;k<n;k++){
                    product.a[i][k] += a[i][j]*other.a[j][k];
                    product.a[i][k] %= mod;
                }
            }
        }
        return product;
    }
};

struct SegTree
{
	vector<ll> tree;
	SegTree(ll N)
	{
		tree.resize(4*N+5);
	}
	ll merge(ll a, ll b)
	{
		return a + b;
	}
	void build(vector<ll> &A, ll v, ll lx, ll rx)
	{
		if(lx == rx)
		{
			tree[v] = A[lx];
			return;
		}
		ll mid = (lx + rx)/2;
		build(A, 2*v+1, lx, mid);
		build(A, 2*v+2, mid+1, rx);
		tree[v] = merge(tree[2*v+1], tree[2*v+2]);
	}

	void point_update(ll v, ll lx, ll rx, ll pos, ll val)
	{
		if(lx == rx)
		{
			tree[v] = val;
			return;
		}
		ll mid = (lx + rx)/2;
		if(pos <= mid) 
			point_update(2*v+1, lx, mid, pos, val);
		else
			point_update(2*v+2, mid+1, rx, pos, val);
 
		tree[v] = merge(tree[2*v+1], tree[2*v+2]);
	}

 	ll range_query(ll v, ll lx, ll rx, ll ql, ll qr)
	{
		

		if(lx == ql && rx == qr)
		{
			return tree[v];
		}
		ll mid = (lx + rx)/2;
 
		ll left_ans = 0, right_ans = 0;
		if(mid >= ql)
			left_ans = range_query(2*v+1, lx, mid, ql, min(qr, mid));
		if(qr > mid)
			right_ans = range_query(2*v+2, mid+1, rx, max(mid+1, ql), qr);
 
		return merge(left_ans, right_ans);
	}
};

struct id0
{
	vector<ll> tree;
	id0(ll N)
	{
		tree.resize(4*N+5);
	}
	ll merge(ll a, ll b)
	{
		return gcd(a,b);
	}
	void build(vector<ll> &A, ll v, ll lx, ll rx)
	{
		if(lx == rx)
		{
			tree[v] = A[lx];
			return;
		}
		ll mid = (lx + rx)/2;
		build(A, 2*v+1, lx, mid);
		build(A, 2*v+2, mid+1, rx);
		tree[v] = merge(tree[2*v+1], tree[2*v+2]);
	}

	void point_update(ll v, ll lx, ll rx, ll pos, ll val)
	{
		if(lx == rx)
		{
			tree[v] = val;
			return;
		}
		ll mid = (lx + rx)/2;
		if(pos <= mid) 
			point_update(2*v+1, lx, mid, pos, val);
		else
			point_update(2*v+2, mid+1, rx, pos, val);
 
		tree[v] = merge(tree[2*v+1], tree[2*v+2]);
	}

 	ll range_query(ll v, ll lx, ll rx, ll ql, ll qr)
	{
		

		if(lx == ql && rx == qr)
		{
			return tree[v];
		}
		ll mid = (lx + rx)/2;
 
		ll left_ans = 0, right_ans = 0;
		if(mid >= ql)
			left_ans = range_query(2*v+1, lx, mid, ql, min(qr, mid));
		if(qr > mid)
			right_ans = range_query(2*v+2, mid+1, rx, max(mid+1, ql), qr);
 
		return merge(left_ans, right_ans);
	}
};

void solve(){
    ll n; cin >> n;
    vector<ll>a(n);
    for(ll i = 0;i<n;i++)cin >> a[i];
    ll gc = a[0];
    id0 S2(n);
    S2.build(a,0,0,n-1);
    ll temp = 0;
    ll ans = 0;
    for(ll i = 0;i<n;i++){
        ll l = temp, r = i, best = -1;
        while(l<=r){
            ll mid = (l+r)/2;
            ll q = S2.range_query(0,0,n-1,mid,i);
            if(q < i-mid+1)l = mid+1;
            else if(q > i-mid+1)r = mid-1;
            else{
                temp = i+1;
                ans++;
                break;
            }
        }
        cout << ans << " ";
    }
    

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

 
    
        freopen("Input.txt", "r", stdin);
        freopen("Output2.txt", "w", stdout);
    
    
    

    ll t = 1; 

    while(t--){
        solve();
    }
 
}