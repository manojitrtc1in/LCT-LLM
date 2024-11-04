
































































































































using namespace std;
 
using ll = long long;
using db = long double; 

using str = string; 




using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;








tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;



















tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }










const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

	return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id12(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 


tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } 

tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } 


tcTU> T fstTrue(T lo, T hi, U f) {
	++hi; assert(lo <= hi); 

	while (lo < hi) { 

		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	--lo; assert(lo <= hi); 

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




inline namespace Helpers {
	

	

	

	tcT, class = void> struct is_iterable : false_type {};
	tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
	                                  decltype(end(declval<T>()))
	                                 >
	                       > : true_type {};
	tcT> constexpr bool id22 = is_iterable<T>::value;

	

	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id3 = is_readable<T>::value;

	

	

	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id6 = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool id20 = !id3<T> && id22<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id3<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id20<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id20<T>,void>::type re(T& i) {
		each(x,i) re(x); }
	tcTUU> void re(T& t, U&... u) { re(t); re(u...); } 


	

	void rv(size_t) {}
	tcTUU> void rv(size_t N, V<T>& t, U&... u);
	template<class...U> void rv(size_t, size_t N2, U&... u);
	tcTUU> void rv(size_t N, V<T>& t, U&... u) {
		t.rsz(N); re(t);
		rv(N,u...); }
	template<class...U> void rv(size_t, size_t N2, U&... u) {
		rv(N2,u...); }

	

	void decrement() {} 

	tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
	
	
}

inline namespace ToString {
	tcT> constexpr bool id10 = !id6<T> && id22<T>;

	

	tcT> typename enable_if<id6<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	tcT> str bit_vec(T t) { 

		str res = "{"; id11(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

	tcTU> str ts(pair<T,U> p); 

	tcT> typename enable_if<id10<T>,str>::type ts(T v); 

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<id22<T>,str>::type ts_sep(T v, str sep) {
		

		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<id10<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	

	template<int, class T> typename enable_if<!id10<T>,vs>::type 
	  id13(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<id10<T>,vs>::type 
	  id13(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = id13<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		id11(i,sz(res)) {
			str bef = " "; if (i == 0) bef = "{";
			res[i] = bef+res[i];
		}
		res.bk += "}";
		return res;
	}
}

inline namespace Output {
	template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
	template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
		pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
	

	template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
	

	void ps() { cout << "\n"; }
	template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
	

	template<class ...T> void dbg_out(const T&... t) {
		pr_sep(cerr," | ",t...); cerr << endl; }
	void loc_info(int line, str names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template<int lev, class T> void id25(const T& t) {
		cerr << "\n\n" << ts_sep(id13<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	

	const clock_t beg = clock();
	
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

	}
}




template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } 

	int v; explicit operator int() const { return v; } 

	mint():v(0) {}
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	bool operator==(const mint& o) const {
		return v == o.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	friend void re(mint& a) { ll x; re(x); a = mint(x); }
	friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& o) { 
		if ((v -= o.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& o) { 
		v = int((ll)v*o.v%MOD); return *this; }
	mint& operator/=(const mint& o) { return (*this) *= inv(o); }
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

using mi = mint<MOD,5>; 

using vmi = V<mi>;
using pmi = pair<mi,mi>;
using vpmi = V<pmi>;

V<vmi> scmb; 

void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	FOR(i,1,SZ) id11(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}


const int mx = 605;
int n, k;
vi poses;
vi negs;
mi tpow[mx];


void id23(){
	tpow[0] = mi(1);
	for(int i = 1; i < mx; i++){
		tpow[i] = tpow[i-1]*mi(2);
	}
}


vector<vmi> id4(vi nums){ 

	vector<vmi> res(sz(nums)+1);
	for(int i = sz(nums); i >= 0; i--){
		if(i == sz(nums)){
			res[sz(nums)] = vmi(k+1, mi(0));
			res[sz(nums)][0] = mi(1);
			continue;
		}
		res[i] = vmi(k+1, mi(0));
		for(int j = 0; j <= k; j++){
			

			res[i][j]+=res[i+1][j];
			

			if(j-1 >= 0){
				res[i][j]+=res[i+1][j-1]*mi(nums[i]);
			}
		}
	}
	return res;
}

vi id19, id2;

void id16(){
	vector<pair<int, pair<int, int>>> sorted_abs; 

	for(int i = 0; i < sz(poses); i++){
		sorted_abs.pb(mp(abs(poses[i]), mp(poses[i], i)));
	}
	for(int i = 0; i < sz(negs); i++){
		sorted_abs.pb(mp(abs(negs[i]), mp(negs[i], i)));
	}
	sor(sorted_abs);
	assert(sz(sorted_abs) == n);
	id19 = vi(sz(poses), 0);
	id2 = vi(sz(negs), 0);
	for(int i = 0; i < n; i++){
		if(sorted_abs[i].s.f >= 0){
			id19[sorted_abs[i].s.s] = i;
		}
		else{
			id2[sorted_abs[i].s.s] = i;
		}
	}
}

mi id21(){ 

	vi all_nums = poses;
	for(auto u: negs){
		all_nums.pb(u);
	}
	vector<vmi> prods = id4(all_nums);
	return prods[0][k];
}


mi id7(){
	vector<vmi> prods = id4(poses);
	dbg(prods);
	mi res = 0;
	for(int i = 0; i < sz(poses); i++){
		res+=(tpow[id19[i]]-1)*mi(poses[i])*prods[i+1][k-1];
	}
	return res;
}

mi id9(){
	vector<vmi> prods = id4(negs);
	mi res = 0;
	for(int i = 0; i < sz(negs); i++){
		res+=(tpow[id2[i]]-1)*mi(negs[i])*prods[i+1][k-1];
	}
	return res;
}

mi id24(){
	vector<vmi> prods = id4(negs);
	mi res = 0;
	for(int neg_ind = 0; neg_ind < sz(negs); neg_ind++){
		for(int pos_lo = 0; pos_lo < sz(poses); pos_lo++){
			dbg("HI", neg_ind, pos_lo);
			if(id19[pos_lo] >= id2[neg_ind]) continue;
			dbg("HI2", neg_ind, pos_lo);
			int id15 = pos_lo+neg_ind;
			res+=poses[pos_lo]*prods[neg_ind+1][k-1]*tpow[id15];
		}
	}
	return res;
}

mi id5(){
	dbg("HI3");
	vi id8 = negs;
	if(k % 2 == 1){
		reverse(all(id8));
	}

	vector<vmi> prods = id4(id8);
	mi res = 0;
	for(int i = 0; i < sz(id8); i++){ 

		res+=(tpow[i]-1)*mi(id8[i])*prods[i+1][k-1];
	}
	dbg(res);
	return res;
}

mi id14(){
	if(k % 2 == 1){
		return id24()+id5();
	}
	return id9();
}

bool id17(int pos_ind, int neg_ind, int pos_lo, int neg_lo){
	bool id18 = false;
	if(pos_lo == -1){
		id18 = true;
	}
	else if(neg_lo == -1){
		id18 = false;
	}
	else{
		

		if(ll(negs[neg_lo])*ll(negs[neg_ind]) > ll(poses[pos_lo])*ll(poses[pos_ind])){
			id18 = true;
		}
		else{
			id18 = false;
		}
	}
	return id18;
}

int main() {
	setIO();
	id23();
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		int v;
		cin >> v;
		if(v >= 0){
			poses.pb(v);
		}
		else{
			negs.pb(v);
		}
	}
	sort(all(poses));
	sort(negs.rbegin(), negs.rend());
	id16();

	mi k_ans = id21();
	mi pos_ans = id7();
	mi neg_ans = id14();
	
	mi ans = 0;

	vector<vmi> pos_prod = id4(poses);
	vector<vmi> neg_prod = id4(negs);

	for(int take_pos = 1; take_pos <= min(k-1, sz(poses)); take_pos++){ 

		int take_neg = k-take_pos;
		assert(1 <= take_pos && 1 <= take_neg);
		for(int pos_ind = 0; pos_ind < sz(poses); pos_ind++){ 

			for(int neg_ind = 0; neg_ind < sz(negs); neg_ind++){ 

				if(take_neg % 2 == 0){
					

					int id15 = min(id19[pos_ind], id2[neg_ind]);
					ans+=mi(poses[pos_ind])*mi(negs[neg_ind])*pos_prod[pos_ind+1][take_pos-1]*neg_prod[neg_ind+1][take_neg-1]*(tpow[id15]-1);
					continue;
				}
			}
		}
	}


	int BLOCK = 5;
	vector<vector<vmi>> csum(2, vector<vmi>(n+5+BLOCK, vmi(n+5+BLOCK, mi(0))));

	for(int pos_lo = -1; pos_lo < sz(poses); pos_lo++){
		for(int neg_lo = -1; neg_lo < sz(negs); neg_lo++){
			int id15 = ((pos_lo <= 0) ? 0 : pos_lo) + ((neg_lo <= 0) ? 0 : neg_lo);
			if(pos_lo == -1 && neg_lo == -1) continue;

			dbg(pos_lo, neg_lo);

			dbg(pos_lo+BLOCK, neg_lo+BLOCK);

			dbg(sz(csum));
			dbg(sz(csum[1][pos_lo+BLOCK]));
			if(neg_lo >= 0){
				dbg("HI2");
				csum[1][pos_lo+BLOCK][neg_lo+BLOCK]+=mi(negs[neg_lo])*tpow[id15];
				dbg("HI36");
			}
			if(pos_lo >= 0){
				csum[0][pos_lo+BLOCK][neg_lo+BLOCK]+=mi(poses[pos_lo])*tpow[id15];
			}
			dbg(pos_lo, neg_lo);
			csum[1][pos_lo+BLOCK][neg_lo+BLOCK]+=csum[1][pos_lo+BLOCK][neg_lo+BLOCK-1];
			csum[0][pos_lo+BLOCK][neg_lo+BLOCK]+=csum[0][pos_lo+BLOCK][neg_lo+BLOCK-1];
		}
	}
	dbg("HI");

	

	for(int pos_ind = 0; pos_ind < sz(poses); pos_ind++){ 

		for(int neg_ind = 0; neg_ind < sz(negs); neg_ind++){ 

			mi first_sum = 0;
			mi second_sum = 0;

			int id0 = -2;
			int id1 = -2;
			for(int pos_lo = -1; pos_lo < pos_ind; pos_lo++){
				if(pos_lo != -1 && id19[pos_lo] >= id2[neg_ind]) break;
				id0 = pos_lo;
			}
			for(int neg_lo = -1; neg_lo < neg_ind; neg_lo++){
				if(neg_lo != -1 && id2[neg_lo] >= id19[pos_ind]) break;
				id1 = neg_lo;
			}


			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			


			int first_true = 0;
			for(int pos_lo = -1; pos_lo <= id0; pos_lo++){
				while(first_true <= id1){
					if(!id17(pos_ind, neg_ind, pos_lo, first_true)){
						first_true++;
					}
					else{
						break;
					}
				}
				first_sum+=csum[1][pos_lo+BLOCK][id1+BLOCK]-csum[1][pos_lo+BLOCK][first_true-1+BLOCK];
				second_sum+=csum[0][pos_lo+BLOCK][first_true-1+BLOCK];
			}

			

			

			


			

					
			

			

			

			

			

			

			

			

			

			

			

			mi prod2 = first_sum*negs[neg_ind]+second_sum*poses[pos_ind];

			mi prod1 = 0;
			for(int take_pos = 1; take_pos <= min(k-1, sz(poses)); take_pos++){
				int take_neg = k-take_pos;
				if(take_neg % 2 == 1){
					prod1+=pos_prod[pos_ind+1][take_pos-1]*neg_prod[neg_ind+1][take_neg-1];
				}
				
			}
			ans+=prod1*prod2;
		}

		
	}
	

	

	ps((k_ans+neg_ans+pos_ans+ans).v);

	

}


