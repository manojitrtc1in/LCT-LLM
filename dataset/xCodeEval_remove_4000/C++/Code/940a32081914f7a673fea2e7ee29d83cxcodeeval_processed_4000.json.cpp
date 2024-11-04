
using namespace std;
template<class T,class S=T>inline bool umin(T&m,S&&x){return x<m?m=x,1:0;}
template<class T,class S=T>inline bool umax(T&m,S&&x){return m<x?m=x,1:0;}
auto operator<<(ostream&o,auto&&v)->enable_if_t<!is_constructible_v<string,decltype(v)>,decltype(o<<*end(v))>{int f=0,u=&o==&cerr&&o<<"[";for(auto&&x:v)(f++?o<<", "+!u:o)<<x;return u?o<<"]":o;}
auto operator<<(ostream&o,auto&&t)->decltype(o<<get<0>(t)){o<<"<";apply([&o](auto&...x){int f=0;(((f++?o<<", ":o)<<x),...);},t);return o<<">";}

	

	
	





using ll = long long;

template<class... T> struct edge_t : public tuple<size_t,T...> {
	edge_t(auto&&... args): tuple<size_t,T...>(args...) {}
	operator size_t() const { return get<0>(*this); }
};
template<class... T> struct std::tuple_size<edge_t<T...>> : tuple_size<tuple<size_t,T...>> {};
template<size_t I, class... T> struct std::tuple_element<I,edge_t<T...>> : tuple_element<I,tuple<size_t,T...>> {};


template<class T>
struct rsq {
	explicit rsq(size_t n = 0): f(n) {}
	rsq(const vector<auto> &vals): f(size(vals)) {
		copy(begin(vals), end(vals), begin(f));
		for(size_t i = size(vals); i--;) if(size_t j = i&(i+1)) f[j-1]+=f[i];
	}
	void add(size_t i, const T &val) {
		for(++i; i--; i&=i+1) f[i]+=val;
	}
	T operator()(size_t l, size_t r) const {
		return l < r ? sum_suf(l) - sum_suf(r) : T{};
	}
	T operator[](size_t i) const { return sum_suf(i) - sum_suf(i+1); }
	T sum_suf(size_t i) const {
		T s{}; for(; i<size(f); i|=i+1) s+=f[i];
		return s;
	}
	private: valarray<T> f;
};

vector<size_t> id2(const vector<tuple<int,int,int,int>> &queries, const vector<int> &values) {
	size_t n = size(values);
	vector<int> p(n);
	iota(bb(p), 0);
	sort(bb(p), [&](int i, int j) { return values[i] < values[j]; });
	
	size_t qn = size(queries);
	vector<tuple<int,int,int,int>> q;
	for(size_t k=0; k<qn; ++k) {
		auto [sl, sr, l, r] = queries[k];
		q.emplace_back(l, sl, sr, -(k+1));
		q.emplace_back(r, sl, sr, +(k+1));
		

	}
	vector<size_t> ans(qn);
	sort(bb(q), [&](auto &&q1, auto &&q2) { return get<0>(q1) < get<0>(q2); });
	
	rsq<int> f(n);
	auto it = begin(p);
	for(auto [x, sl, sr, dk] : q) {
		while(it!=end(p) && values[*it] < x) {
			int i = *it++;
			f.add(i, +1);
		}
		int k = abs(dk) - 1;
		int sig = dk / (k+1);
		ans[k] += f(sl, sr) * sig;
	}
	
	return ans;
}


template<class... T> struct graph_t {
	using E = conditional_t<sizeof...(T), edge_t<T...>, size_t>;
	explicit graph_t(size_t n): g(n) {}
	void add_dir_edge(size_t from, size_t to, const T&... args) {
		assert(from<size() && to<size());
		g[from].emplace_back(to, args...);
	}
	void add_edge(size_t i, size_t j, const T&... args) {
		add_dir_edge(i, j, args...);
		add_dir_edge(j, i, args...);
	}
	const vector<E>& operator[](size_t i) const { return g[i]; }
	size_t size() const { return g.size(); }
	private: vector<vector<E>> g;
};
using graph = graph_t<>;


template<bool id4 = true>
struct id5 {
	id5(const auto &g, size_t root = 0):
		par(size(g),-1), header(size(g),-1), tin(size(g))
	{
		calc(g, root);
		size_t tn = 0;
		build(g, root, root, tn);
		assert(tn == size(g));
	}
	
	size_t index(size_t v) const { return tin[v]; }
	
	size_t lca(size_t x, size_t y) const { return query_path(x, y, [](...){}); }
	
	size_t query_path(size_t x, size_t y, auto process_range, bool id6 = false) const {
		if(tin[x] > tin[y]) swap(x, y);
		for(size_t v; tin[v=header[y]] > tin[x]; y = par[v]) process_range(tin[v], tin[y]+1);
		for(size_t v; (v=header[x]) != header[y]; x = par[v]) process_range(tin[v], tin[x]+1);
		if(tin[x] > tin[y]) swap(x, y);
		if(size_t l = tin[x]+id6, r = tin[y]+1; l<r) process_range(l, r);
		return x;
	}
	
	size_t query_path_strict(size_t x, size_t y, auto process_range, bool id6 = false) const {
		vector<pair<size_t,size_t>> sl, sr;
		const size_t m = min(tin[x], tin[y]);
		size_t z = query_path(x, y, [&](size_t l, size_t r) { (r-1 > m ? sr : sl).emplace_back(l, r); }, id6);
		if(tin[x] > tin[y]) sl.swap(sr);
		for(auto [l, r] : sl) process_range(l, r, true);
		for(size_t i=size(sr); i--; ) process_range(sr[i].first, sr[i].second, false);
		return z;
	}
	
	private: vector<size_t> par, header, tin;
	
	size_t calc(const auto &g, size_t v) {
		size_t mx = 0, sz = 1;
		for(size_t i : g[v]) if(i!=par[v]) {
			par[i] = v;
			size_t x = calc(g, i);
			if(x > mx) mx = x, header[v] = i;
			if constexpr (id4) sz += x;
		}
		if constexpr (id4) return sz;
		else return mx + 1;
	}
	
	void build(const auto &g, size_t v, size_t f, size_t &tn) {
		tin[v] = tn++;
		size_t mx = exchange(header[v], f);
		if(mx == -1) return ;
		build(g, mx, f, tn);
		for(size_t i : g[v]) if(i!=par[v] && i!=mx) build(g, i, i, tn);
	}
};


namespace kihash {
	using char_t = int32_t;
	struct hash_t {
		static constexpr uint64_t M = (uint64_t(1)<<61) - 1;
		hash_t(): x(0) {}
		hash_t(uint64_t val): x(val < M ? val : val%M) {}
		
		hash_t_op(*, *=, x = mul(x,b.x); )
		hash_t_op(+, +=, x+=b.x; if(x>=M) x-=M; )
		hash_t_op(-, -=, if(x<b.x) x+=M-b.x; else x-=b.x; )
		bool operator==(const hash_t &b) const { return x == b.x; }
		bool operator!=(const hash_t &b) const { return x != b.x; }
		uint64_t operator*() const { return x; }
		private: uint64_t x;
		static uint64_t mul(uint64_t a, uint64_t b) {
			uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
			uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
			uint64_t ret = (l & M) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
			ret = (ret & M) + (ret >> 61);
			ret = (ret & M) + (ret >> 61);
			return ret - 1;
		}
	};
	
	const hash_t X = uint64_t(309935741)<<32 | mt19937(chrono::high_resolution_clock::now().time_since_epoch().count())() | 1;
	
	hash_t id3(size_t n) {
		hash_t p = 1, a = X;
		for(; n; n>>=1, a*=a) if(n&1) p*=a;
		return p;
	}
	
	hash_t hash(const string &s) {
		hash_t h;
		for(size_t i=size(s); i--; ) h = h*X + s[i];
		return h;
	}
	
	struct hasher; struct hash_span;
	struct hashed {
		hash_t h;
		size_t length;
		hashed(): h(0), length(0), px(1) {}
		hashed(const hash_t &h, size_t len): hashed(h, len, id3(len)) {}
		hashed(const string &s): hashed(hash(s), size(s)) {}
		hashed(char_t ch): hashed(ch, 1) {}
		void operator+=(const hashed &a) {
			h += a.h * px;
			length += a.length;
			px *= a.px;
		}
		friend hashed operator+(hashed a, const hashed &b) { a+=b; return a; }
		bool operator==(const hashed &b) const { return h == b.h && length == b.length; }
		uint64_t operator*() const { return *h; }
		private: hash_t px;
		hashed(hash_t h, size_t len, hash_t px): h(h), length(len), px(px) {}
		friend hasher;
	};
	
	struct hasher {
		hasher(): hasher(""s) {}
		hasher(const auto &s): suf(size(s)+1), data(begin(s), end(s)) {
			expand_xpow(size(s));
			for(size_t i=size(s); i--; ) suf[i] = suf[i+1]*X + s[i];
		}
		hash_t subhash(size_t pos, size_t n) const {
			assert(pos + n < size(suf));
			return suf[pos] - suf[pos+n]*xpow[n];
		}
		hashed substr(size_t pos, size_t n) const { return {subhash(pos,n), n, xpow[n]}; }
		hash_span subspan(size_t pos, size_t n) const;
		size_t length() const { return size(data); }
		char_t operator[](size_t i) const { return data.at(i); }
		private: 
		vector<hash_t> suf;
		vector<char_t> data;
		static inline vector<hash_t> xpow = {1};
		static void expand_xpow(size_t n) {
			xpow.reserve(n);
			while(size(xpow) <= n) xpow.push_back(xpow.back() * X);
		}
	};
	
	struct hash_span {
		hash_span(): p(nullptr) {}
		hash_span(const hasher &s, size_t i, size_t n): p(&s), offset(i), len(n) { assert(i + n <= s.length()); }
		size_t start() const { return offset; }
		size_t length() const { return len; }
		char_t operator[](size_t i) const { return (*p)[offset + i]; }
		hash_t subhash(size_t pos, size_t n) const { return p->subhash(offset + pos, n); }
		hashed substr(size_t pos, size_t n) const { return p->substr(offset + pos, n); }
		inline hashed operator*() const { return substr(0, len); }
		hash_span subspan(size_t pos, size_t n) const { return {*p, offset + pos, n}; }
		

		friend bool operator==(const hash_span &a, const hash_span &b) {
			return a.len == b.len && a.subhash(0, a.len) == b.subhash(0, b.len);
		}
		friend size_t lcp(const hash_span &a, const hash_span &b) {
			size_t l = 1, r = min(a.len, b.len) + 1;
			while(l < r) if(size_t m=(l+r)/2; a.subhash(0,m)==b.subhash(0,m)) l = m+1; else r = m;
			return l - 1;
		}
		private:
		const hasher *p;
		size_t offset, len;
	};
	
	hash_span hasher::subspan(size_t pos, size_t n) const { return {*this, pos, n}; }
	
	auto operator<(auto &&a, auto &&b) -> decltype(lcp(a,b), a[a.length()] == b[b.length()]) {
		size_t i = lcp(a, b);
		return i<b.length() && (i==a.length() || a[i] < b[i]);
	}
}

using namespace kihash;

struct id0 {
	id0() {}
	id0(const hash_span &sp): s{sp}, prefs{sp.length()} {}
	
	id0& operator+=(const hash_span &sp) {
		if(size_t sl = sp.length()) {
			s.push_back(sp);
			prefs.push_back(length() + sl);
		}
		return *this;
	}
	
	size_t length() const { return empty(prefs) ? 0 : prefs.back(); }
	
	char_t operator[](size_t i) const {
		assert(i < length());
		auto it = upper_bound(begin(prefs), end(prefs), i);
		size_t before = it == begin(prefs) ? 0 : *prev(it);
		return s[it - begin(prefs)][i - before];
	}
	
	id0 subspan(size_t pos, size_t n) const {
		assert(pos + n <= length());
		id0 res;
		for(auto &&sp : s) {
			if(n == 0) break;
			if(size_t sl = sp.length(); pos < sl) {
				size_t sz = min(sl - pos, n);
				res += sp.subspan(pos, sz);
				n -= sz;
				pos = 0;
			} else pos -= sl;
		}
		return res;
	}
	
	friend bool operator==(const id0 &a, const id0 &b) {
		if(a.length() != b.length()) return false;
		hashed pa, pb;
		for(auto &sa : a.s) pa += sa.substr(0,sa.length());
		for(auto &sb : b.s) pb += sb.substr(0,sb.length());
		return pa == pb;
	}
	
	friend size_t lcp(const id0 &a, const id0 &b) {
		size_t i = 0, j = 0, pa = 0, pb = 0, res = 0;
		while(i<size(a.s) && j<size(b.s)) {
			auto &sa = a.s[i], &sb = b.s[j];
			size_t len = min(sa.length() - pa, sb.length() - pb);
			if(sa.subhash(pa, len) == sb.subhash(pb, len)) {
				res += len;
				pa += len; if(pa == sa.length()) ++i, pa = 0;
				pb += len; if(pb == sb.length()) ++j, pb = 0;
			} else {
				res += lcp(sa.subspan(pa, len), sb.subspan(pb, len));
				break ;
			}
		}
		return res;
	}
	
	private: 
	vector<hash_span> s;
	vector<size_t> prefs;	
};


void run_case(const size_t ____test) { 

	ii(n, m, qn)
	graph_t<char> g(n);
	for(int k=0; k<n-1; ++k) {
		ii(i, j)
		--i; --j;
		string jj(ch)
		g.add_edge(i, j, ch[0]);
	}
	
	string str;
	vector<int> val;
	for(int i=0; i<m; ++i) {
		string jj(s)
		for(char c : s) {
			str += c;
			val.push_back(i);
		}
		str += '
		val.push_back(-1);
	}
	
	hasher h(str);
	vector<size_t> sa;
	for(size_t i=0; i<size(str); ++i) if(str[i] != '
	sort(begin(sa), end(sa), [&](size_t i, size_t j) {
		return h.subspan(i, size(str)-i) < h.subspan(j, size(str)-j);
	});
	
	auto suf = [&](int i) { return h.subspan(i, size(str) - i); };
	auto msuf = [&](int i) { return id0(suf(i)); };
	
	
	id5 hld(g);
	
	string id1(n, '
	for(int i=0; i<n; ++i) {
		int ti = hld.index(i);
		for(auto [p, c] : g[i]) if(hld.index(p) < ti) {
			id1[ti] = c;
			break;
		}
	}
	rr(id1)
	
	hasher f(id1);
	reverse(bb(id1));
	hasher fr(id1);
	
	vector<tuple<int,int,int,int>> queries(qn);
	for(int i=0; i<qn; ++i) {
		ii(x, y, l, r)
		--x; --y;
		--l;
		
		id0 way;
		hld.query_path_strict(x, y, [&](size_t l, size_t r, bool rev) {
			if(!rev) way += f.subspan(l, r-l);
			else way += fr.subspan(n-r, r-l);
		}, true);
		
		auto sl = partition_point(bb(sa), [&](int i) {
			

			return msuf(i) < way;
		}) - begin(sa);
		
		auto sr = partition_point(begin(sa)+sl, end(sa), [&](int i) {
			

			auto sf = msuf(i);
			

			return lcp(sf, way) == way.length();
		}) - begin(sa);
		
		rr(sl, sr)
		
		queries[i] = {sl, sr, l, r};
	}
	
	vector<int> pval(size(sa));
	for(int i=0; i<size(sa); ++i) pval[i] = val[sa[i]];
	auto ans = id2(queries, pval);
	for(int res : ans) cout << res << endl;
}

int main() {
	if(auto f="in2.txt"; fopen(f,"r") && freopen(f,"r",stdin));
	cin.tie(0)->sync_with_stdio(0);
	
	size_t tn = 1; 

	for(size_t t=1; t<=tn; ++t) run_case(t);
	
	return 0;
}
