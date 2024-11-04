
using namespace std;
 
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










const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll INF = 1e18; 

const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; 

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




inline namespace Helpers {
	

	

	

	tcT, class = void> struct is_iterable : false_type {};
	tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
	                                  decltype(end(declval<T>()))
	                                 >
	                       > : true_type {};
	tcT> constexpr bool id15 = is_iterable<T>::value;

	

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
	tcT> constexpr bool id14 = !id0<T> && id15<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id14<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id14<T>,void>::type re(T& i) {
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
	tcT> constexpr bool id4 = !id3<T> && id15<T>;

	

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
	tcT> typename enable_if<id15<T>,str>::type ts_sep(T v, str sep) {
		

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
	  id8(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<id4<T>,vs>::type 
	  id8(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = id8<lev-1>(t);
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
	template<int lev, class T> void id17(const T& t) {
		cerr << "\n\n" << ts_sep(id8<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

	}
}

int N,M;

vi A,B,C;

struct Query {
	int type, index, val;
};

str ts(const Query& q) {
	return ts(vi{q.type,q.index,q.val});
}

V<Query> queries;
AR<vl,8> smart, dumb;
vb dynamic;



vi brute() {
	vi tmp = A;
	id5(q,sz(queries)) {
		const auto& t = queries[q];
		if (t.type == 1) {
			tmp[t.index] = t.val;
		} else {
			

			

			

		}
	}
	return tmp;
}

void smart01() { 

	vl ans_right(N),  dp_two(N);
	vi dp_one(N);
	id5(r,N) {
		if (r) ans_right[r] = ans_right[r-1];
		if (!dynamic[r]) {
			ans_right[r] += dp_two[C[A[r]]];
			dp_two[A[r]] += dp_one[A[r]];
			++dp_one[B[A[r]]];
		} else { 

			int cur_val = A[r];
			id5(q,sz(queries)) {
				const auto& t = queries[q];
				if (t.type == 1) {
					if (t.index == r) cur_val = t.val;
				} else {
					if (t.index > r) {
						smart.at(1).at(q) += dp_two[C[cur_val]];
					}
				}
			}
		}
	}
	id5(q,sz(queries)) {
		const auto& t = queries[q];
		if (t.type == 2) smart.at(0).at(q) = ans_right[t.index-1];
	}
}

vi rlabel, label; 

V<vi> partials;
V<vi> id10, id2; 





void gen_label() {
	label = vi(N,-1); rlabel = {};
	id5(r,N) if (dynamic[r]) {
		label[r] = sz(rlabel);
		rlabel.pb(r);
	}
	partials = {};
	vi partial; each(i,rlabel) partial.pb(A[i]);
	id5(q,sz(queries)) {
		const auto& t = queries[q];
		partials.eb();
		if (t.type == 1) {
			partial[label[t.index]] = t.val;
		} else {
			id5(i,sz(rlabel)) if (rlabel[i] < t.index) partials.bk.pb(partial[i]);
		}
	}
	id10 = id2 = V<vi>(sz(queries));
	vi pref_y(N);
	id5(r,N) {
		if (dynamic[r]) {
			int pos = label[r];
			id5(q,sz(queries)) if (sz(partials[q]) > pos) {
				int v = partials[q][pos];
				id10[q].pb(pref_y[B[v]]);
				id2[q].pb(pref_y[C[v]]);
			}
		} else {
			++pref_y.at(A[r]);
		}
	}
}

void smart7() { 

	vl dp_two(N);
	vi dp_one(N);
	vi partial; for (int r: rlabel) partial.pb(A[r]);
	id5(q,sz(queries)) {
		const auto& t = queries[q];
		if (t.type == 1) {
			partial[label[t.index]] = t.val;
		} else {
			for (int ind = 0; ind < sz(rlabel) && rlabel[ind] < t.index; ++ind) {
				int v = partial[ind];
				smart.at(7).at(q) += dp_two[C[v]];
				dp_two[v] += dp_one[v];
				++dp_one[B[v]];
			}
			for (int v: partial) {
				dp_one[B[v]] = 0;
				dp_two[v] = 0;
			}
		}
	}
}

void smart6() { 

	vl dp_one(N);
	vi partial; for (int r: rlabel) partial.pb(A[r]);
	V<V<tuple<ll,ll,int>>> contrib(N+1);
	id5(q,sz(queries)) {
		const auto& t = queries[q];
		if (t.type == 1) {
			partial[label[t.index]] = t.val;
		} else {
			for (int ind = 0; ind < sz(rlabel) && rlabel[ind] < t.index; ++ind) {
				int v = partial[ind];
				ll two = dp_one[v];
				contrib.at(t.index).pb({v,two,q});
				contrib.at(rlabel[ind]+1).pb({v,-two,q});
				++dp_one[B[v]];
				

			}
			for (int v: partial) dp_one[B[v]] = 0;
		}
	}
	vl num_oc(N);
	id5(r,N) {
		if (!dynamic[r]) ++num_oc[C[A[r]]];
		each(t,contrib[r+1]) {
			auto [v,mul,q] = t;
			smart.at(6).at(q) += mul*num_oc[v];
		}
	}
}

void smart3() { 

	vl dp_one(N);
	vi partial; for (int r: rlabel) partial.pb(A[r]);
	V<V<tuple<ll,ll,int>>> contrib(N+1);
	id5(q,sz(queries)) {
		const auto& t = queries[q];
		if (t.type == 1) {
			partial[label[t.index]] = t.val;
		} else {
			int ind = 0;
			for (; ind < sz(rlabel) && rlabel[ind] < t.index; ++ind);
			while (ind--) {
				int v = partial[ind];
				ll two = dp_one[v];
				contrib.at(rlabel[ind]).pb({v,two,q});
				++dp_one[C[v]];
				

			}
			for (int v: partial) dp_one[C[v]] = 0;
		}
	}
	vl num_oc(N);
	id5(r,N) { 

		if (!dynamic[r]) ++num_oc[B[A[r]]];
		each(t,contrib[r+1]) {
			auto [v,mul,q] = t;
			smart.at(3).at(q) += mul*num_oc[v];
		}
	}
}

void smart2() { 

	


	


	

	

	vi pref_B(N), pref_C(N);
	V<vi> B_before(sz(queries));
	V<vi> C_after(sz(queries));
	V<vi> right_query(N+1);
	id5(q,sz(queries)) {
		const auto& t = queries[q];
		if (t.type == 2) right_query.at(t.index).pb(q);
	}
	id5(r,N) {
		if (dynamic[r]) {
			int pos = label.at(r);
			id5(q,sz(queries)) if (pos < sz(partials[q])) {
				int v = partials.at(q).at(pos);
				B_before[q].pb(pref_B[v]);
				C_after[q].pb(-pref_C[v]);
			}
		} else {
			++pref_B[B[A[r]]];
			++pref_C[C[A[r]]];
		}
		each(q,right_query[r+1]) {
			assert(sz(C_after[q]) == sz(partials[q]));
			id5(pos,sz(partials[q])) {
				int v = partials.at(q).at(pos);
				C_after.at(q).at(pos) += pref_C[v];
			}
		}
	}
	id5(q,sz(queries)) {
		id5(ind,sz(partials[q])) {
			smart.at(2).at(q) += (ll)B_before.at(q).at(ind)*C_after.at(q).at(ind);
		}
	}
}

void smart5() { 

	


	vi id1(N), id16(N); 
	id5(q,sz(queries)) {
		const auto& t = queries[q];
		if (t.type == 2) {
			id5(pos,sz(partials[q])) {
				int x = partials[q][pos];
				int z = x;
				smart.at(5).at(q) += (ll)id1.at(C[z])*id2[q][pos]-id16.at(C[z]);
				int Bx = B[x];
				++id1.at(Bx);
				id16.at(Bx) += id10.at(q).at(pos);
			}
			for (int x: partials[q]) {
				int Bx = B[x];
				id1[Bx] = id16[Bx] = 0;
			}
		}
	}
}

void smart4() { 

	

	

	


	


	

	V<V<tuple<int,int,int>>> query_after(N+1);
	V<vi> id11(N+1);
	id5(q,sz(queries)) {
		const auto& t = queries[q];
		if (t.type == 2) {
			id11.at(t.index).pb(q);
			id5(pos,sz(partials[q])) {
				int x = partials[q][pos];
				

				query_after.at(t.index).pb({B[x],q,1});
				

				query_after.at(rlabel[pos]).pb({B[x],q,-1});
			}
		}
	}

	vl id9(N); 

	vi pref_y(N), id7(N); 

	V<vi> id12(sz(queries)); 

	id5(q,sz(id12)) id12[q].resize(sz(partials[q]));
	id5(r,N) {
		if (!dynamic[r]) {
			int y = A[r], Cz = C[y];
			id9.at(Cz) += pref_y.at(Cz);
			++pref_y.at(y);
			++id7.at(Cz);
		} else { 

			int pos = label.at(r);
			id5(q,sz(queries)) if (pos < sz(partials[q])) {
				int x = partials[q][pos], Bx = B[x];
				

				id12.at(q).at(pos) -= id7.at(Bx);
			}
		}
		each(t,query_after[r+1]) {
			auto [Bx,q,mul] = t;
			smart.at(4).at(q) += mul*id9.at(Bx);
		}
		each(q,id11[r+1]) {
			id5(pos,sz(partials[q])) {
				int x = partials[q][pos], Bx = B[x];
				id12.at(q).at(pos) += id7.at(Bx);
			}
		}
	}

	

	id5(q,sz(queries)) if (sz(partials[q])) {
		id5(pos,sz(partials[q])) {
			smart.at(4).at(q) -= (ll)id10.at(q).at(pos)*id12.at(q).at(pos);
		}
	}
}

void id13() {
	gen_label();
	smart01();
	smart7();
	smart2();
	smart3();
	smart4();
	smart5();
	smart6();
}

ll sum(AR<ll,8> a) {
	ll ans = 0;
	each(t,a) ans += t;
	return ans;
}

void process() {
	

	dynamic = vb(N);
	id5(i,8) {
		dumb[i] = vl(sz(queries));
		smart[i] = vl(sz(queries));
	}
	id5(q,sz(queries)) {
		const auto& t = queries[q];
		if (t.type == 1) dynamic[t.index] = 1;
	}
	vi tmp = brute();
	id13();
	

	

	vl anses(sz(queries));
	

	id5(i,8) {
		id5(q,sz(queries)) {
			anses.at(q) += smart.at(i).at(q);
			

			

			

			

		}
	}
	

	id5(q,sz(queries)) {
		const auto& t = queries[q];
		if (t.type == 2) {
			ps(anses[q]);
		}
	}
	

	queries.clear();
	A = tmp;
}

int main() {
	setIO(); re(N,M);
	A.rsz(N), B.rsz(N), C.rsz(N); re(A,B,C);
	each(t,A) --t;
	each(t,B) --t;
	each(t,C) --t;
	const int BLOCK = sqrt(N);
	rep(M) {
		ints(t);
		if (t == 1) {
			ints(k,x); --k, --x;
			queries.pb({t,k,x});
		} else {
			ints(r);
			queries.pb({t,r,-1});
		}
		if (sz(queries) >= BLOCK) process();
	}
	process();
	

}


