




































const double PI = 3.1415926535897932384626433;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

struct edge{
	ll to, cost;
	edge(){}
	edge(ll a, ll b){ to = a, cost = b;}
};
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};



const int mod = 998244353;

struct mint{
	int x;
	mint(ll y = 0){if(y < 0 || y >= mod) y = (y%mod+mod)%mod; x = y;}
	mint(const mint &ope) {x = ope.x;}
	mint operator-(){return mint(-x);}
	mint operator+(const mint &ope){return mint(x) += ope;}
	mint operator-(const mint &ope){return mint(x) -= ope;}
	mint operator*(const mint &ope){return mint(x) *= ope;}
	mint operator/(const mint &ope){return mint(x) /= ope;}
	mint& operator+=(const mint &ope){x += ope.x; if(x >= mod) x -= mod; return *this;}
	mint& operator-=(const mint &ope){x += mod - ope.x; if(x >= mod) x -= mod; return *this;}
	mint& operator*=(const mint &ope){ll tmp = x; tmp *= ope.x, tmp %= mod; x = tmp; return *this;}
	mint& operator/=(const mint &ope){
		ll n = mod-2; mint mul = ope;
		while(n){if(n & 1) *this *= mul; mul *= mul; n >>= 1;}
		return *this;
	}
	mint inverse(){return mint(1) / *this;}
	bool operator ==(const mint &ope){return x == ope.x;}
	bool operator !=(const mint &ope){return x != ope.x;}
	bool operator <(const mint &ope)const{return x < ope.x;}
};
mint modpow(mint a, ll n){
	if(n == 0) return mint(1);
	if(n % 2) return a * modpow(a, n-1);
	else return modpow(a*a, n/2);
}
istream& operator >>(istream &is, mint &ope){ll t; is >> t, ope.x = t; return is;}
ostream& operator <<(ostream &os, mint &ope){return os << ope.x;}
ostream& operator <<(ostream &os, const mint &ope){return os << ope.x;}

ll modpow(ll a, ll n, ll mod){
	if(n == 0) return 1;
	if(n % 2) return ((a%mod) * (modpow(a, n-1, mod)%mod)) % mod;
	else return modpow((a*a)%mod, n/2, mod) % mod;
}

vector<mint> fact, fact_inv;
void make_fact(int n){
	fact.resize(n+1), fact_inv.resize(n+1);
	fact[0] = mint(1); rep(i, 1, n) fact[i] = fact[i-1] * mint(i);
	fact_inv[n] = fact[n].inverse(); per(i, n-1, 0) fact_inv[i] = fact_inv[i+1] * mint(i+1);
}
mint comb(int n, int k){ if(n < 0 || k < 0 || n < k) return mint(0); return fact[n] * fact_inv[k] * fact_inv[n-k];}
mint perm(int n, int k){ return comb(n, k) * fact[k]; }
template<typename T> T comb2(ll n, ll k){ T ret = 1; rep(i, 1, k) ret *= n-k+i, ret /= i; return ret;}

vector<int> prime, pvec, qrime;
void make_prime(int n){
	prime.resize(n+1);
	rep(i, 2, n){
		if(prime[i] == 0) pvec.push_back(i), prime[i] = i;
		for(auto p : pvec){ if(i*p > n || p > prime[i]) break; prime[i*p] = p;}
	}
}
void id0(int n){
	qrime.resize(n+1);
	rep(i, 2, n){int ni = i / prime[i]; if(prime[i] == prime[ni]) qrime[i] = qrime[ni] * prime[i]; else qrime[i] = prime[i];}
}

bool exceed(ll x, ll y, ll m){return y > 0 && x >= m / y + 1;}
void mark(){ cout << "*" << endl; }
void yes(){ cout << "YES" << endl; }
void no(){ cout << "NO" << endl; }
ll floor(ll a, ll b){ if(b < 0) a *= -1, b *= -1; if(a >= 0) return a/b; else return -((-a+b-1)/b); }
ll ceil(ll a, ll b){ if(b < 0) a *= -1, b *= -1; if(a >= 0) return (a+b-1)/b; else return -((-a)/b); }
ll modulo(ll a, ll b){ b = abs(b); return a - floor(a, b) * b;}
ll sgn(ll x){ if(x > 0) return 1; if(x < 0) return -1; return 0;}
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){return a/gcd(a, b)*b;}
ll arith(ll x){return x*(x+1)/2;}
ll arith(ll l, ll r){return arith(r) - arith(l-1);}
ll digitnum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret++; return ret;}
ll digitsum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret += x % b; return ret;}
string lltos(ll x, ll b = 10){string ret; for(;x;x/=b) ret += x % b + '0'; reverse(all(ret)); return ret;}
ll stoll(string &s, ll b = 10){ll ret = 0; for(auto c : s) ret *= b, ret += c - '0'; return ret;}
template<typename T> void uniq(T &vec){sort(all(vec)); vec.erase(unique(all(vec)), vec.end());}
int popcount(ull x){
	x -= ((x>>1)&0x5555555555555555ULL), x = (x & 0x3333333333333333ULL) + ((x>>2) & 0x3333333333333333ULL);
	return (((x + (x>>4)) & 0x0F0F0F0F0F0F0F0FULL) * 0x0101010101010101ULL) >> 56;
}

template<class S, class T> pair<S, T>& operator+=(pair<S, T> &s, const pair<S, T> &t){s.first += t.first, s.second += t.second; return s;}
template<class S, class T> pair<S, T>& operator-=(pair<S, T> &s, const pair<S, T> &t){s.first -= t.first, s.second -= t.second; return s;}
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t){return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t){return pair<S,T>(s.first-t.first, s.second-t.second);}
template<class T> T dot(const pair<T, T> &s, const pair<T, T> &t){return s.first*t.first + s.second*t.second;}
template<class T> T cross(const pair<T, T> &s, const pair<T, T> &t){return s.first*t.second - s.second*t.first;}
template<class T> T mdist(pair<T, T> s, pair<T, T> t){return abs(s.first-t.first) + abs(s.second-t.second);}
template<class T> T cdist(pair<T, T> s, pair<T, T> t){return max(abs(s.first-t.first), abs(s.second-t.second));}
template<class T> T id2(pair<T, T> s, pair<T, T> t){return (s.first-t.first)*(s.first-t.first) + (s.second-t.second)*(s.second-t.second);}

template<typename T> ostream& operator << (ostream& os, vector<T>& vec){reps(i, vec) os << vec[i] << " "; return os;}
template<typename T> ostream& operator << (ostream& os, const vector<T>& vec){reps(i, vec) os << vec[i] << " "; return os;}
template<typename T> ostream& operator << (ostream& os, list<T>& ls){for(auto x : ls) os << x << " "; return os;}
template<typename T> ostream& operator << (ostream& os, const list<T>& ls){for(auto x : ls) os << x << " "; return os;}
template<typename T> ostream& operator << (ostream& os, deque<T>& deq){reps(i,  deq) os << deq[i] << " "; return os;}
template<typename T, typename U> ostream& operator << (ostream& os, pair<T, U>& ope){ os << "(" << ope.first << ", " << ope.second << ")"; return os;}
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& ope){ os << "(" << ope.first << ", " << ope.second << ")"; return os;}
template<typename T, typename U> ostream& operator << (ostream& os, map<T, U>& ope){ for(auto p : ope) os << "(" << p.first << ", " << p.second << "),";return os;}
template<typename T> ostream& operator << (ostream& os, set<T>& ope){for(auto x : ope) os << x << " "; return os;}
template<typename T> ostream& operator << (ostream& os, multiset<T>& ope){for(auto x : ope) os << x << " "; return os;}
template<typename T> void outa(T a[], ll s, ll t){rep(i, s, t){ cout << a[i]; if(i < t) cout << " ";} cout << endl;}
template<typename T, size_t N> ostream& operator << (ostream& os, array<T, N>& arr){reps(i, arr) os << arr[i] << " "; return os;}
template<typename T, size_t N> ostream& operator << (ostream& os, const array<T, N>& arr){reps(i, arr) os << arr[i] << " "; return os;}
void dump_func(){cout << endl;}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail){cout << head; if(sizeof...(Tail) > 0) cout << " "; dump_func(std::move(tail)...);}


struct id1{
	typedef ll SEG;
	typedef ll DELAY;
	
	int size;
	vector<SEG> seg;
	vector<DELAY> delay;
	
	id1(){}
	id1(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		delay.resize(1<<(size+1));
	}
	
	SEG Ident(){ 

		return inf;
	}
	SEG ope(SEG a, SEG b){ 

		return min(a, b);
	}
	DELAY NoDelay(){ 

		return inf;
	}
	DELAY merge(DELAY a, DELAY b){ 

		return min(a, b);
	}
	SEG act(SEG a, DELAY d, int l, int r){ 

		return min(a, d);
	}
	
	void init(){
		for(int i = 0; i < (1<<(size+1)); i++){
			seg[i] = Ident();
			delay[i] = NoDelay();
		}
	}
	void set(int i, SEG x){
		seg[i+(1<<size)] = x;
	}
	void setup(){
		for(int i = (1<<size)-1; i >= 1; i--) seg[i] = ope(seg[i*2], seg[i*2+1]);
	}
	
	void eval(int l, int r, int k){
		if(delay[k] != NoDelay()){
			seg[k] = act(seg[k], delay[k], l, r);
			if(l < r){
				delay[k*2] = merge(delay[k*2], delay[k]);
				delay[k*2+1] = merge(delay[k*2+1], delay[k]);
			}
			delay[k] = NoDelay();
		}
	}
	
	void update(int i, SEG val){
		int l = 0, r = (1<<size)-1, k = 1;
		
		eval(l, r, k);
		for(int j = size-1; j >= 0; j--){
			k <<= 1;
			if(i & (1<<j)){
				k++;
				l = (l+r)/2+1;
			}
			else r = (l+r)/2;
			eval(l, r, k);
		}
		
		seg[i+(1<<size)] = val;
		
		l = i, r = i, k = i+(1<<size);
		for(int j = 0; j < size; j++){
			k /= 2, l &= ~(1<<j), r |= 1<<j;
			eval(l, (l+r)/2, k*2), eval((l+r)/2+1, r, k*2+1);
			seg[k] = ope(seg[k*2], seg[k*2+1]);
		}
	}
	
	void add(int a, int b, int k, int l, int r, DELAY val){
		eval(l, r, k);
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			delay[k] = merge(delay[k], val); 
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val);
		add(a, b, k*2+1, (l+r)/2+1, r, val);
		seg[k] = ope(seg[k*2], seg[k*2+1]);
	}
	void add(int a, int b, DELAY val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}
 
	SEG query(int a, int b, int k, int l, int r){
		eval(l, r, k);
		if(b < l || r < a) return Ident();
		if(a <= l && r <= b) return seg[k];
		SEG lval = query(a, b, k*2, l, (l+r)/2);
		SEG rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return ope(lval, rval);
	}
	SEG query(int a, int b){
		if(a > b) return Ident();
		return query(a, b, 1, 0, (1<<size)-1);
	}
};


ll n, T;
ll g[200005], c[200005], d[200005];
ll l[200005], r[200005];
ll L[200005], R[200005];
ll dp[200005];
vector<ll> comp;
id1 seg(21);

ll get(ll id, ll p)
{
	if(id > n) return 0;
	return dp[id] + modulo(r[id]-p, T);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> T;
	rep(i, 1, n) cin >> g[i] >> c[i];
	rep(i, 1, n-1) cin >> d[i];
	
	rep(i, 1, n){
		l[i] = g[i], r[i] = 0;
		l[i] = modulo(l[i]-c[i], T), r[i] = modulo(r[i]-c[i], T);
	}
	
	ll ans = 0;
	rep(i, 2, n){
		ans += d[i-1];
		l[i] = modulo(l[i]-ans, T);
		r[i] = modulo(r[i]-ans, T);
	}
	
	rep(i, 1, n){
		comp.pb(l[i]), comp.pb(l[i]+1), comp.pb(l[i]-1);
		comp.pb(r[i]), comp.pb(r[i]+1), comp.pb(r[i]-1);
	}
	comp.pb(0), comp.pb(T-1);
	uniq(comp);
	rep(i, 1, n){
		L[i] = lower_bound(all(comp), l[i]) - comp.begin();
		R[i] = lower_bound(all(comp), r[i]) - comp.begin();
	}
	ll C = sz(comp);
	
	seg.init();
	per(i, n, 1){
		dp[i] = get(seg.query(R[i], R[i]), r[i]);
		if(L[i] <= R[i]) seg.add(L[i], R[i], i);
		else seg.add(0, R[i], i), seg.add(L[i], C-1, i);
	}
	
	vector<ll> vec;
	rep(i, 1, n) vec.pb(modulo(l[i]-1, T)), vec.pb(r[i]);
	uniq(vec);
	
	ll tmp = inf;
	for(auto p : vec){
		ll P = lower_bound(all(comp), p) - comp.begin();
		chmin(tmp, get(seg.query(P, P), p));
	}
	ans += tmp;
	outl(ans);
	
	
	return 0;
}