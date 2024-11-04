
































































































































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
constexpr int id6(int x) { return p2(x)-1; }

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
	tcT> constexpr bool id13 = is_iterable<T>::value;

	

	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id0 = is_readable<T>::value;

	

	

	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id3 = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool id12 = !id0<T> && id13<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id12<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id12<T>,void>::type re(T& i) {
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
	tcT> constexpr bool id4 = !id3<T> && id13<T>;

	

	tcT> typename enable_if<id3<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	tcT> str bit_vec(T t) { 

		str res = "{"; id5(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

	tcTU> str ts(pair<T,U> p); 

	tcT> typename enable_if<id4<T>,str>::type ts(T v); 

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<id13<T>,str>::type ts_sep(T v, str sep) {
		

		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<id4<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	

	template<int, class T> typename enable_if<!id4<T>,vs>::type 
	  id7(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<id4<T>,vs>::type 
	  id7(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = id7<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		id5(i,sz(res)) {
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
	template<int lev, class T> void id14(const T& t) {
		cerr << "\n\n" << ts_sep(id7<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	

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






struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { 

		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};




const int mx = 600005;

int n;
int x[mx];
int y[mx];
vi adj[mx];

vector<vpi> RES;
vi t_adj[mx];

vpi extra[mx];
pi single_extra[mx];

void dfs(int node, int p = -1){
	dbg(node, p);
	for(auto u: t_adj[node]){
		if(u == p) continue;
		dfs(u, node);
	}

	while(sz(extra[node]) >= 2){
		pi ed1 = extra[node].bk; extra[node].pop_back();
		pi ed2 = extra[node].bk; extra[node].pop_back();

		RES.pb(vpi{mp(ed2.s, ed2.f), ed1});
	}

	if(sz(extra[node]) == 0){
		if(p != -1){
			extra[p].pb(mp(p, node));
		}	
	}
	else{
		pi extra_ed = extra[node][0];
		if(p == -1){
			RES.pb(vpi{mp(extra_ed.s, extra_ed.f)});
		}
		else{
			dbg(extra_ed, mp(node, p));
			RES.pb(vpi{mp(extra_ed.s, extra_ed.f), mp(node, p)});
		}
	}
}

vector<vpi> getPaths(vpi adj_list){
	DSU dsu;
	dsu.init(mx);

	vpi tree_edges;
	vpi id2;
	for(auto u: adj_list){
		if(dsu.unite(u.f, u.s)){
			tree_edges.pb(u);
		}
		else{
			id2.pb(u);
		}
	}

	
	vector<vpi> id15(mx);
	vector<vpi> id8(mx);
	vi tot_num(mx, 0);
	vi deg(mx, 0);

	for(auto u: adj_list){
		tot_num[dsu.get(u.f)]++;
	}
	for(auto u: tree_edges){
		id8[dsu.get(u.f)].pb(u);
	}
	for(auto u: id2){
		id15[dsu.get(u.f)].pb(u);
	}
	for(auto u: adj_list){
		deg[u.f]++;
		deg[u.s]++;
	}

	vi actual_root(mx, 0);
	

	for(int i = 1; i <= 2*n; i++){
		if(dsu.get(i) == i){
			if(tot_num[i] % 2 == 0){
				actual_root[i] = i;
				for(auto u: id8[i]){
					t_adj[u.f].pb(u.s);
					t_adj[u.s].pb(u.f);
				}
				for(auto u: id15[i]){
					extra[u.f].pb(u);
				}
				continue;
			}

			

			if(sz(id15[i])){
				for(auto u: id8[i]){
					t_adj[u.f].pb(u.s);
					t_adj[u.s].pb(u.f);
				}
				int ROOT = id15[i][0].f;

				single_extra[ROOT] = id15[i][0];
				actual_root[i] = ROOT;

				for(int j = 1; j < sz(id15[i]); j++){
					pi ED = id15[i][j];
					extra[ED.f].pb(ED);
				}
			}
			else{
				


				int leaf_ind = -1;
				for(int j = 0; j < sz(id8[i]); j++){
					int nodef = id8[i][j].f;
					int nodes = id8[i][j].s;
					if(deg[nodef] == 1){
						leaf_ind = j;
						break;
					}
					else if(deg[nodes] == 1){
						swap(id8[i][j].f, id8[i][j].s);
						leaf_ind = j;
						break;
					}
				}
				assert(leaf_ind != -1);
				pi leaf_edge = id8[i][leaf_ind];
				for(int j = 0; j < sz(id8[i]); j++){
					if(j == leaf_ind) continue;
					pi ED = id8[i][j];

					t_adj[ED.f].pb(ED.s);
					t_adj[ED.s].pb(ED.f);
				}
				single_extra[leaf_edge.s] = mp(leaf_edge.s, leaf_edge.f);
				actual_root[i] = leaf_edge.s;

				

			}
		}
	}

	dbg(t_adj[13]);
	dbg(t_adj[14]);
	dbg(t_adj[15]);
	dbg(t_adj[16]);
	dbg(single_extra[9]);

	for(int i = 1; i <= 2*n; i++){
		if(dsu.get(i) == i){
			int ROOT = actual_root[i];
			dbg(ROOT);
			dfs(ROOT);
			if(single_extra[ROOT] != mp(0, 0)){
				if(sz(RES) == 0){
					ps(-1);
					exit(0);
				}
				if(sz(RES.bk) == 2){
					if(single_extra[ROOT].f == RES.bk[1].s){
						RES.bk.pb(single_extra[ROOT]);
					}
					else if(single_extra[ROOT].f == RES.bk[0].s && single_extra[ROOT].f == RES.bk[1].f){
						swap(RES.bk[0].f, RES.bk[0].s);
						RES.bk.pb(single_extra[ROOT]);
					}
					else if(single_extra[ROOT].f == RES.bk[0].f && single_extra[ROOT].f == RES.bk[1].f){
						RES.bk.pb(single_extra[ROOT]);
					}
					else{
						ps(-1);
						exit(0);
					}
				}
				else{
					RES.bk.pb(single_extra[ROOT]);
				}
				
			}
		}
	}
	return RES;
}


bool isStar(vpi path){
	return sz(path) == 3 && path[0].f == path[1].f && path[0].f == path[2].f;
}

bool isPath(vpi path){
	if(sz(path) <= 1 || sz(path) >= 4) return false;
	for(int i = 0; i+1 < sz(path); i++){
		if(path[i].s != path[i+1].f){
			return false;
		}
	}
	return true;
}



int main() {
	setIO();
	
	cin >> n;
	dbg(n);
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
	}
	vpi adj_list;
	for(int i = 1; i <= n; i++){
		adj_list.pb(mp(x[i], y[i]));
	}

	vector<vpi> paths = getPaths(adj_list);


	dbg(paths);
	string id10;
	string id11;

	string id1;
	string id9;

	vi ans_top;
	vi ans_bot;

	for(auto path: paths){
		if(!isStar(path) && !isPath(path)){
			dbg(path);
			ps(-1);
			exit(0);
		}
		if(isStar(path)){
			vi nums;
			for(auto u: path){ 

				nums.pb(u.s);
			}
			int root = path[0].f;

			assert(sz(nums) == 3);

			id10+="LRU";
			id11+="LRD";

			id1+="ULR";
			id9+="DLR";

			ans_top.pb(root);
			ans_top.pb(nums[2]);
			ans_top.pb(root);

			ans_bot.pb(nums[0]);
			ans_bot.pb(root);
			ans_bot.pb(nums[1]);
		}
		else{
			assert(isPath(path));
			assert(sz(path) == 2 || sz(path) == 3);

			

			vi nums;
			for(int i = 0; i < sz(path); i++){
				nums.pb(path[i].f);
				if(i == sz(path)-1){
					nums.pb(path[i].s);
				}
			}

			
			

			if(sz(path) == 2){
				assert(sz(nums) == 3);
				id10+="UU";
				id11+="DD";

				id1+="LR";
				id9+="LR";

				ans_top.pb(nums[1]);
				ans_top.pb(nums[2]);
				ans_bot.pb(nums[0]);
				ans_bot.pb(nums[1]);
			}
			else if(sz(path) == 3){
				assert(sz(nums) == 4);
				id10+="LRU";
				id11+="LRD";

				id1+="ULR";
				id9+="DLR";

				ans_top.pb(nums[0]);
				ans_top.pb(nums[1]);
				ans_top.pb(nums[2]);
				ans_bot.pb(nums[1]);
				ans_bot.pb(nums[2]);
				ans_bot.pb(nums[3]);
			}
		}
	}

	ps(2, n);
	for(int i = 0; i < sz(ans_top); i++){
		cout << ans_top[i];
		if(i+1 < sz(ans_top)){
			cout << " ";
		}
	}
	cout << "\n";

	for(int i = 0; i < sz(ans_bot); i++){
		cout << ans_bot[i];
		if(i+1 < sz(ans_bot)){
			cout << " ";
		}
	}

	cout << "\n";

	cout << "\n";
	ps(id10);
	ps(id11);

	cout << "\n";
	ps(id1);
	ps(id9);

	

}


