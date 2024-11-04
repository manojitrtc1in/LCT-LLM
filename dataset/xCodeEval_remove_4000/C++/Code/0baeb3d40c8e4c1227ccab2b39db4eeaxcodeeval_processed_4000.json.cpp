






using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;
 
using ll = long long;
using db = long double; 

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









const int MOD = 998244353; 

const int MX = 2e5+5;
const ll INF = 1e18; 

const int IINF = 1e9;
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

	return x == 0 ? 0 : 31-__builtin_clz(x); } 

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
void re(double& d) { str t; re(t); d = stod(t); }
void re(long double& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }

tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(V<T>& x) { each(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { each(a,x) re(a); }
tcT> void rv(int n, V<T>& x) { x.rsz(n); re(x); }




str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	

	

	

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
	
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	
		return ts(p.f)+" "+ts(p.s);
	
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t id0 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id0);
    }
};



template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } 

	int v; explicit operator int() const { return v; } 

	mint() { v = 0; }
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	friend bool operator==(const mint& a, const mint& b) {
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) {
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) {
		return a.v < b.v; }
	friend void re(mint& a) { ll x; re(x); a = mint(x); }
	friend str ts(mint a) { return ts(a.v); }

	mint& operator+=(const mint& m) {
		if ((v += m.v) >= MOD) v -= MOD;
		return *this; }
	mint& operator-=(const mint& m) {
		if ((v -= m.v) < 0) v += MOD;
		return *this; }
	mint& operator*=(const mint& m) {
		v = int((ll)v*m.v%MOD); return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0);
		return pow(a,MOD-2); }

	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

typedef mint<MOD,5> mi; 

typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

vector<vmi> scmb; 

void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	FOR(i,1,SZ) id1(j,i+1)
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}

typedef vector<mi> vec;
typedef vector<vec> mat;

mat zeros(int n, int m) {
	return mat(n, vec(m));
}

mat id(int n) {
	mat ret = zeros(n, n);
	for (int i = 0; i < n; i++)
		ret[i][i] = 1;
	return ret;
}

mat add(mat a, const mat& b) {
	int n = a.size(), m = a[0].size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = (a[i][j] + b[i][j]);
	return a;
}

mat mul(const mat& a, const mat& b) {
	int n = a.size(), m = a[0].size(), k = b[0].size();
	mat ret = zeros(n, k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			for (int p = 0; p < m; p++)
				ret[i][j] = (ret[i][j] + a[i][p] * b[p][j]);
	return ret;
}

mat pow(const mat& a, ll p) {
	if (p == 0) return id(a.size());
	mat ret = pow(mul(a, a), p >> 1);
	if (p % 2) ret = mul(ret, a);
	return ret;
}

int main() {
	setIO();
	int n;
	cin >> n;
	ll x;
	cin >> x;
	vl d(n);
	re(d);
	vl D;
	id1(a, n){
		if(d[a] == 0)
			continue;
		if(sz(D) == 0 || ((D.back() > 0) != (d[a] > 0)))
			D.pb(d[a]);
		else
			D.back() += d[a];
	}
	n = sz(D);
	if(n == 0){
		cout << "1 1" << endl;
		return 0;
	}
	if(n == 1 && D[0] < 0){
		cout << "1 " << mi(-D[0] + 1).v << endl;
		return 0;
	}
	vector<pl> peak; 

	peak.pb({0, 0});
	each(a, D)
		peak.pb(mp(peak.back().f + a, peak.back().f + a / abs(a)));
	n++;
	ll mxlen = 0;
	map<pl, pi> Q;
	id1(a, n){
		id1(b, a){
			if(mxlen == peak[a].f - peak[b].f + 1){
				if(Q.count(mp(peak[b].f, peak[a].f))){
					ckmax(Q[mp(peak[b].f, peak[a].f)].s, a);
					ckmin(Q[mp(peak[b].f, peak[a].f)].f, b);
				}
				else{
					Q[mp(peak[b].f, peak[a].f)] = mp(b, a);
				}
			}
			else if(ckmax(mxlen, peak[a].f - peak[b].f + 1)){
				Q.clear();
				Q[mp(peak[b].f, peak[a].f)] = mp(b, a);
			}
		}
	}
	mi ans = 0;
	each(q, Q){
		int st = q.s.f, en = q.s.s;
		ll h = q.f.f;
		int SZ = en - st + 1;
		mat cnt = zeros(1, SZ);
		FOR(b, st, en + 1)
			if(min(peak[b].f, peak[b].s) <= h && h <= max(peak[b].f, peak[b].s))
				cnt[0][b - st] += 1;
		set<ll> s;
		FOR(b, st, en + 1)
			s.insert(peak[b].f);
		s.erase(h);
		each(H, s){
			mat	tran = zeros(SZ, SZ);
			FOR(a, st, en + 1)
				FOR(b, st, en + 1){
					if(min(peak[a].f, peak[a].s) <= h && h <= max(peak[a].f, peak[a].s)){
						if(min(peak[b].f, peak[b].s) <= h + 1 && h + 1 <= max(peak[b].f, peak[b].s)){
							if(a == b){
								assert(a != 0);
								if(peak[a - 1].f < peak[a].s)
									tran[a - st][a - st] += 1;
							}
							else{
								if(b > a)
									tran[a - st][b - st] += 1;
							}
						}
					}
				}
			cnt = mul(cnt, tran);
			h++;
			if(h < H - 1){
				tran = zeros(SZ, SZ);
				FOR(a, st, en + 1)
					FOR(b, st, en + 1){
						if(min(peak[a].f, peak[a].s) <= h && h <= max(peak[a].f, peak[a].s)){
							if(min(peak[b].f, peak[b].s) <= h + 1 && h + 1 <= max(peak[b].f, peak[b].s)){
								if(a == b){
									assert(a != 0);
									if(peak[a - 1].f < peak[a].s)
										tran[a - st][a - st] += 1;
								}
								else{
									if(b > a)
										tran[a - st][b - st] += 1;
								}
							}
						}
					}
				mat res = pow(tran, H - 1 - h);
				cnt = mul(cnt, res);
				h = H - 1;
			}
			if(h < H){
				tran = zeros(SZ, SZ);
				FOR(a, st, en + 1)
					FOR(b, st, en + 1){
						if(min(peak[a].f, peak[a].s) <= h && h <= max(peak[a].f, peak[a].s)){
							if(min(peak[b].f, peak[b].s) <= h + 1 && h + 1 <= max(peak[b].f, peak[b].s)){
								if(a == b){
									assert(a != 0);
									if(peak[a - 1].f < peak[a].s)
										tran[a - st][a - st] += 1;
								}
								else{
									if(b > a)
										tran[a - st][b - st] += 1;
								}
							}
						}
					}
				cnt = mul(cnt, tran);
				h = H;
			}
		}
		each(a, cnt[0])
			ans += a;
	}
	cout << mxlen << " " << ans.v << endl;
	

}


