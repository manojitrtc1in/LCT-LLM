
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 

typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 
























const int MOD = 1e9+7; 

const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
constexpr int pct(int x) { return __builtin_popcount(x); } 
constexpr int bits(int x) { return 31-__builtin_clz(x); } 

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 

ll half(ll x) { return fdiv(x,2); }

template<class T, class U> T fstTrue(T lo, T hi, U f) { 
	

	hi ++; assert(lo <= hi); 

	while (lo < hi) { 

		T mid = half(lo+hi);
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
template<class T, class U> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); 

	while (lo < hi) { 

		T mid = half(lo+hi+1);
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
template<class T> void remDup(vector<T>& v) { 
	sort(all(v)); v.erase(unique(all(v)),end(v)); }



template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }




str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	
		return b ? "true" : "false"; 
	
		return ts((int)b);
	
}
template<class A> str ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { 

	
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
template<class A, class B> str ts(pair<A,B> p) {
	
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	
		return ts(p.f)+" "+ts(p.s);
	
}



template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
	pr(h); pr(t...); }
void ps() { pr("\n"); } 

template<class H, class... T> void ps(const H& h, const T&... t) { 
	pr(h); if (sizeof...(t)) pr(" "); ps(t...); }



void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }


	
	
		 << __FUNCTION__  << ") -> CHK FAILED: (" << 

	
	




void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void id1() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str s = "") {
	id1();
	

	

	

	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } 

}



template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } 

	int v; explicit operator int() const { return v; } 

	mint() { v = 0; }
	mint(ll _v) { v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
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
		v = (ll)v*m.v%MOD; return *this; }
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
	FOR(i,1,SZ) F0R(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}



const int mx = 2005;
int n, k, L;

struct Stairs{
	set<pair<int, pi>> blocks; 

	mi id0 = 0;
	void init(){
		blocks.ins(mp(0, mp(0, L)));
	}
	void upd(pi corner){ 

		assert(sz(blocks) > 0);

		auto it5 = blocks.lb(mp(corner.f, mp(-5, -5)));
		if(it5 != blocks.end() && corner.s <= (*it5).s.s) return;

		if(blocks.ub(mp(corner.f, mp(L+1, L+1))) == blocks.begin()) return;

		auto it = prev(blocks.ub(mp(corner.f, mp(L+1, L+1))));
		int ybot = (*it).s.f;
		while(true){
			pair<int, pi> curblock = *it;
			auto it2 = it;
			if(it2 != blocks.begin()) it2 = prev(it2);
			if(curblock.s.s >= corner.s){
				blocks.erase(curblock);
				id0-=mi(curblock.f)*mi(curblock.s.s-curblock.s.f+1);
				if(corner.s+1 <= curblock.s.s) blocks.ins(mp(curblock.f, mp(corner.s+1, curblock.s.s)));
				id0+=mi(curblock.f)*mi(curblock.s.s-corner.s);
				blocks.ins(mp(corner.f, mp(ybot, corner.s)));
				id0+=mi(corner.f)*mi(corner.s-ybot+1);
				break;
			}
			else{
				blocks.erase(curblock);
				id0-=mi(curblock.f)*mi(curblock.s.s-curblock.s.f+1);
			}
			assert(it != it2);
			it = it2;
		}
	}
	mi getSZ(){
		return mi(L+1)*mi(L+1)-id0;
	}
};

int x[mx];
int y[mx];
int c[mx];
vpi cols[mx]; 


vpi getCorners(vpi points){
	vpi corners;
	int topy = L;
	for(auto u: points){
		corners.pb(mp(u.f+1, topy));
		topy = u.s;
	}
	return corners;
}

mi solve(int y){ 

	

	vector<pair<int, pi>> upds; 

	
	for(int i = 1; i <= k; i++){
		

		vpi points;
		points.pb(mp(L, -2));
		for(auto u: cols[i]){
			if(u.s < y) continue;
			vpi addpoints;
			while(true){
				addpoints.pb(points.bk);
				if(u.s > points.bk.s){
					break;
				}
				points.pop_back();
			}
			points.pb(u);
			vpi corners = getCorners(addpoints);
			

			for(auto x: corners){
				upds.pb(mp(u.f+1, x));
				

			}
		}
		reverse(all(points));
		vpi corners = getCorners(points);
		for(auto x: corners){
			upds.pb(mp(0, x));
			

		}
		

	}
	sort(all(upds));
	


	Stairs c;
	c.init();
	int lastx = 0;
	mi lastSZ = 0;
	mi ans = 0;

	vi id3;
	for(auto u: upds){
		id3.pb(u.f);
	}
	remDup(id3);
	int updind = 0;

	for(auto x: id3){
		while(updind < sz(upds)){
			if(upds[updind].f > x) break;
			c.upd(upds[updind].s);
			

			

			updind++;
		}

		


		

		


		ans+=mi(x-1-lastx+1)*lastSZ;
		lastSZ = c.getSZ();
		lastx = x;
	}
	

	return ans;
}

int main() {
	setIO();
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	cin >> n >> k >> L;
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i] >> c[i];
	}
	for(int i = 1; i <= n; i++){
		cols[c[i]].pb(mp(x[i], y[i]));
	}
	for(int i = 1; i <= k; i++){
		sort(cols[i].rbegin(), cols[i].rend());
	}

	vi id2;
	for(int i = 1; i <= n; i++){
		id2.pb(y[i]);
	}
	remDup(id2);

	mi ans = 0;
	int lasty = 0;
	for(auto u: id2){
		mi tans = solve(u);
		ans+=tans*mi(u-lasty+1);
		lasty = u+1;
	}

	ps(ans);

	

	

	

	

	

	


	

	

	

	

	

	

	

	


	


	

}



