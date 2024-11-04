
using namespace std;

	
	
	using bll = boost::multiprecision::cpp_int;
	using bdouble = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<100>>;
	using namespace boost::multiprecision;


	
	
	
	


	namespace std {
		template<typename T> class dvector : public std::vector<T> {
		public:
			dvector() : std::vector<T>() {}
			explicit dvector(size_t n, const T& value = T()) : std::vector<T>(n, value) {}
			dvector(const std::vector<T>& v) : std::vector<T>(v) {}
			dvector(const std::initializer_list<T> il) : std::vector<T>(il) {}
			dvector(const std::string::iterator first, const std::string::iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::iterator first, const typename std::vector<T>::iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::reverse_iterator first, const typename std::vector<T>::reverse_iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::const_iterator first, const typename std::vector<T>::const_iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::const_reverse_iterator first, const typename std::vector<T>::const_reverse_iterator last) : std::vector<T>(first, last) {}
			T& operator[](size_t n) {
				try { return this->at(n); } catch (const std::exception& e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; return this->at(n); }
			}
			const T& operator[](size_t n) const {
				try { return this->at(n); } catch (const std::exception& e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; return this->at(n); }
			}
		};
	}
	class dbool {
	private:
		bool boolvalue;
	public:
		dbool() : boolvalue(false) {}
		dbool(bool b) : boolvalue(b) {}
		operator bool&() { return boolvalue; }
		operator const bool&() const { return boolvalue; }
	};
	
	


	template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
		for (size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<std::vector<T>>& vv) {
		s << "\\\n"; for (size_t i = 0; i < vv.size(); ++i){ s << vv[i] << "\n"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::deque<T>& v) {
		for (size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::multiset<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template <typename T, size_t N> std::ostream& operator<<(std::ostream& s, const std::array<T, N>& a) {
		s << "{ "; for (size_t i = 0; i < N; ++i){ s << a[i] << "\t"; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
		s << "{\n"; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << "\n"; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p) {
		return s << "(" << p.first << ", " << p.second << ")"; }
	class SIGFPE_exception : std::exception {};
	class SIGSEGV_exception : std::exception {};
	void id3([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGFPE_exception(); }
	void id4([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGSEGV_exception(); }
	signed convertedmain();
	signed main() { signal(SIGFPE, id3); signal(SIGSEGV, id4); return convertedmain(); }
	
	void debug_impl() { std::cerr << '\n'; }
	template<typename Head, typename... Tail> void debug_impl(Head head, Tail... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }
	

	



using ll = long long;


constexpr ll INF = (ll)1e18;

constexpr ll MOD = (ll)1e9 + 7;
constexpr double EPS = 1e-9;
constexpr ll dx[4] = {1, 0, -1, 0};
constexpr ll dy[4] = {0, 1, 0, -1};
constexpr ll dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr ll dy8[8] = {0, 1, 0, -1, 1, -1, 1, -1};






void p() { std::cout << '\n'; }
template<typename Head, typename... Tail> void p(Head head, Tail... tail) { std::cout << head << (sizeof...(tail) ? " " : ""); p(tail...); }
template<typename T> inline void pv(std::vector<T>& v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template<typename T> inline bool chmax(T& a, T b) { return a < b && (a = b, true); }
template<typename T> inline bool chmin(T& a, T b) { return a > b && (a = b, true); }
template<typename T> inline void uniq(std::vector<T>& v) { v.erase(std::unique(v.begin(), v.end()), v.end()); }



template< typename Monoid, 
          typename OperatorMonoid = Monoid,
		  typename F = function< Monoid(Monoid, Monoid) >,
		  typename G = function< Monoid(Monoid, OperatorMonoid, ll) >,
		  typename H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >>
struct id1 {
	inline unsigned long long xor128() {
		static unsigned long long x = 123456789;
		static unsigned long long y = 362436069;
		static unsigned long long z = 521288629;
		static unsigned long long w = 88675123;
		unsigned long long t = x ^ (x << 11);
		x = y;
		y = z;
		z = w;
		return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
	}

	struct Node {
		ll cnt;
		Monoid key, sum;
		OperatorMonoid lazy;
		Node *l, *r;
		Node() = default;
		Node(const Monoid &k, const OperatorMonoid &p) : cnt(1), key(k), sum(k), lazy(p), l(nullptr), r(nullptr) {}
	};

	vector< Node > pool;
	ll ptr;
	const F f;
	const G g;
	const H h;
	const Monoid M1;
	const OperatorMonoid OM0;

	id1(ll sz, const F &f, const Monoid &M1) :
			pool(sz), ptr(0), f(f), g(G()), h(H()), M1(M1), OM0(OperatorMonoid()) {}

	id1(ll sz, const F &f, const G &g, const H &h,
								 const Monoid &M1, const OperatorMonoid &OM0) :
			pool(sz), ptr(0), f(f), g(g), h(h), M1(M1), OM0(OM0) {}

	inline Node *alloc(const Monoid &key) { return &(pool[ptr++] = Node(key, OM0)); }

	virtual Node *clone(Node *t) { return t; }

	inline ll count(const Node *t) { return t ? t->cnt : 0; }

	inline Monoid sum(const Node *t) { return t ? t->sum : M1; }

	inline Node *update(Node *t) {
		t->cnt = count(t->l) + count(t->r) + 1;
		auto tmp = f(sum(t->l), t->key);
		t->sum = f(tmp, sum(t->r));
		return t;
	}

	Node *propagate(Node *t) {
		t = clone(t);
		if(t->lazy != OM0) {
			t->key = g(t->key, t->lazy, 1);
			if(t->l) {
				t->l = clone(t->l);
				t->l->lazy = h(t->l->lazy, t->lazy);
				t->l->sum = g(t->l->sum, t->lazy, count(t->l));
			}
			if(t->r) {
				t->r = clone(t->r);
				t->r->lazy = h(t->r->lazy, t->lazy);
				t->r->sum = g(t->r->sum, t->lazy, count(t->r));
			}
			t->lazy = OM0;
		}
		return update(t);
	}

	Node *merge(Node *l, Node *r) {
		if(!l || !r) return l ? l : r;
		if(xor128() % (l->cnt + r->cnt) < (unsigned long long)l->cnt) {
			l = propagate(l);
			l->r = merge(l->r, r);
			return update(l);
		} else {
			r = propagate(r);
			r->l = merge(l, r->l);
			return update(r);
		}
	}

	pair< Node *, Node * > split(Node *t, ll k) {
		if(!t) return {t, t};
		t = propagate(t);
		if(k <= count(t->l)) {
			auto s = split(t->l, k);
			t->l = s.second;
			return {s.first, update(t)};
		} else {
			auto s = split(t->r, k - count(t->l) - 1);
			t->r = s.first;
			return {update(t), s.second};
		}
	}

	Node *build(ll l, ll r, const vector< Monoid > &v) {
		if(l + 1 >= r) return alloc(v[l]);
		return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
	}

	Node *build(const vector< Monoid > &v) {
		ptr = 0;
		return build(0, (ll) v.size(), v);
	}

	void dump(Node *r, typename vector< Monoid >::iterator &it) {
		if(!r) return;
		r = propagate(r);
		dump(r->l, it);
		*it = r->key;
		dump(r->r, ++it);
	}

	vector< Monoid > dump(Node *r) {
		vector< Monoid > v((size_t) count(r));
		auto it = begin(v);
		dump(r, it);
		return v;
	}

	string to_string(Node *r) {
		auto s = dump(r);
		string ret;
		for(ll i = 0; i < (ll)s.size(); i++) ret += std::to_string(s[i]) + ", ";
		return (ret);
	}

	void insert(Node *&t, ll k, const Monoid &v) {
		auto x = split(t, k);
		t = merge(merge(x.first, alloc(v)), x.second);
	}

	void erase(Node *&t, ll k) {
		auto x = split(t, k);
		t = merge(x.first, split(x.second, 1).second);
	}

	Monoid query(Node *&t, ll a, ll b) {
		auto x = split(t, a);
		auto y = split(x.second, b - a);
		auto ret = sum(y.first);
		t = merge(x.first, merge(y.first, y.second));
		return ret;
	}

	void set_propagate(Node *&t, ll a, ll b, const OperatorMonoid &p) {
		auto x = split(t, a);
		auto y = split(x.second, b - a);
		y.first->lazy = h(y.first->lazy, p);
		t = merge(x.first, merge(propagate(y.first), y.second));
	}

	void set_element(Node *&t, ll k, const Monoid &x) {
		t = propagate(t);
		if(k < count(t->l)) set_element(t->l, k, x);
		else if(k == count(t->l)) t->key = t->sum = x;
		else set_element(t->r, k - count(t->l) - 1, x);
		t = update(t);
	}

	ll size(Node *t) {
		return count(t);
	}

	bool empty(Node *t) {
		return !t;
	}

	Node *makeset() {
		return nullptr;
	}
};
template< typename Monoid, 
          typename OperatorMonoid = Monoid,
		  typename F = function< Monoid(Monoid, Monoid) >,
		  typename G = function< Monoid(Monoid, OperatorMonoid, ll) >,
		  typename H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >>
struct id0 : id1< Monoid, OperatorMonoid, F, G, H > {
	using RBST = id1< Monoid, OperatorMonoid, F, G, H >;
	using Node = typename RBST::Node;

	id0(ll sz) : RBST(sz, [&](Monoid x, [[maybe_unused]] Monoid y) { return x; }, Monoid()) {}
	id0(ll sz, const F &f, const Monoid &M1) : RBST(sz, f, M1) {}
	id0(ll sz, const F &f, const G &g, const H &h,
						const Monoid &M1, const OperatorMonoid &OM0) : RBST(sz, f, g, h, M1, OM0) {}

	Monoid kth_element(Node *t, ll k) {
		if(k < RBST::count(t->l)) return kth_element(t->l, k);
		if(k == RBST::count(t->l)) return t->key;
		return kth_element(t->r, k - RBST::count(t->l) - 1);
	}

	virtual void insert_key(Node *&t, const Monoid &x) {
		RBST::insert(t, lower_bound(t, x), x);
	}

	void erase_key(Node *&t, const Monoid &x) {
		if(!count(t, x)) return;
		RBST::erase(t, lower_bound(t, x));
	}

	ll count(Node *t, const Monoid &x) {
		return upper_bound(t, x) - lower_bound(t, x);
	}

	ll lower_bound(Node *t, const Monoid &x) {
		if(!t) return 0;
		if(x <= t->key) return lower_bound(t->l, x);
		return lower_bound(t->r, x) + RBST::count(t->l) + 1;
	}

	ll upper_bound(Node *t, const Monoid &x) {
		if(!t) return 0;
		if(x < t->key) return upper_bound(t->l, x);
		return upper_bound(t->r, x) + RBST::count(t->l) + 1;
	}
};
template< typename Monoid, 
          typename OperatorMonoid = Monoid,
		  typename F = function< Monoid(Monoid, Monoid) >,
		  typename G = function< Monoid(Monoid, OperatorMonoid, ll) >,
		  typename H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >>
struct OrderedSet : id0< Monoid, OperatorMonoid, F, G, H > {
	using SET = id0< Monoid, OperatorMonoid, F, G, H >;
	using RBST = typename SET::RBST;
	using Node = typename RBST::Node;

	OrderedSet(ll sz) : id0< Monoid >(sz) {}
	OrderedSet(ll sz, const F &f, const Monoid &M1) : RBST(sz, f, M1) {}
	OrderedSet(ll sz, const F &f, const G &g, const H &h,
					const Monoid &M1, const OperatorMonoid &OM0) : RBST(sz, f, g, h, M1, OM0) {}
	
	void insert_key(Node *&t, const Monoid &x) override {
		if(SET::count(t, x)) return;
		RBST::insert(t, SET::lower_bound(t, x), x);
	}
};



void solve() {
	ll N,M,K;
	cin>>N>>M>>K;
	vector<deque<pair<ll,ll>>> a(4),bk;
	rep(i,N){
		ll t,b,c;
		cin>>t>>b>>c;
		ll d=2*b+c;
		a[d].push_back({t,i+1});
	}
	rep(i,4)sort(all(a[i]));
	bk=a;

	auto F = [&](pair<ll,ll> x,pair<ll,ll> y){ return pair<ll,ll>(x.first+y.first,0); };
	id0<pair<ll,ll>,pair<ll,ll>,decltype(F)> rbst(N,F,pair<ll,ll>(0,0));
	using Node = id0<pair<ll,ll>,pair<ll,ll>,decltype(F)>::Node;
	Node* node = rbst.makeset();

	ll ans=INF,index11=-1,tmp=0;
	bool init=true;
	vector<deque<pair<ll,ll>>> b(4);
	rep(size11, min((ll)a[3].size()+1,M+1)){
		if(size11+(ll)b[1].size()+(ll)min(a[1].size(),a[2].size())<K)continue;
		if(init){
			ll nokori=M-(size11+(K-size11)*2);
			if(nokori<0)continue;
			if(nokori>N-(size11+(K-size11)*2))continue;
			init=false;
			rep(_,size11){
				tmp+=a[3].front().first;
				b[3].push_back(a[3].front());
				a[3].pop_front();
			}
			rep(_,K-size11){
				for(ll i=1;i<=2;i++){
					tmp+=a[i].front().first;
					b[i].push_back(a[i].front());
					a[i].pop_front();
				}
			}
			rep(i,4){
				for(auto&& x:a[i])rbst.insert_key(node, x);
			}
			pair<ll,ll> amarival=rbst.query(node, 0, nokori);
			ans=tmp+amarival.first;
			index11=size11;
			continue;
		}

		rbst.erase_key(node, a[3].front());
		tmp+=a[3].front().first;
		b[3].push_back(a[3].front());
		a[3].pop_front();
		if(b[1].size()>0){
			for(ll i=1;i<=2;i++){
				rbst.insert_key(node, b[i].back());
				tmp-=b[i].back().first;
				b[i].pop_back();
			}
		}

		ll nokori=M-(b[1].size()+b[2].size()+b[3].size());
		if(nokori<0)continue;
		if(nokori>rbst.size(node))continue;
		pair<ll,ll> amarival=rbst.query(node, 0, nokori);
		if(chmin(ans,tmp+amarival.first)){
			index11=size11;
		}
	}

	if(ans==INF){
		p(-1);return;
	}
	
	vector<ll> vec;
	rep(_,index11){
		vec.push_back(bk[3].front().second);
		bk[3].pop_front();
	}
	for(ll i=1;i<=2;i++)rep(_,K-index11){
		vec.push_back(bk[i].front().second);
		bk[i].pop_front();
	}
	vector<pair<ll,ll>> id2;
	rep(i,4){
		for(auto&& x:bk[i])id2.push_back(x);
	}
	sort(all(id2));
	rep(i,M-index11-(K-index11)*2){
		vec.push_back(id2[i].second);
	}
	p(ans);
	sort(vec.begin(), vec.end());
	pv(vec);
}

signed main() {
	solve();
	return 0;
}
