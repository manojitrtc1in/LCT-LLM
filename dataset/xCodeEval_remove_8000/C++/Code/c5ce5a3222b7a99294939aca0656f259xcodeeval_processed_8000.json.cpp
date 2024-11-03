






























bool debug_mode = false;













using namespace std;
BEGIN_NS

vector<pair<string, string>> lets{{"__debug::", ""}, {"const ", ""}, {"__cxx11::basic_string<char>", "string"}};
struct lets_add {
	lets_add($ a, $ b){
		lets.pb({a,b});
	}
};
import(__gnu_pbds);
using std::priority_queue;
using __gnu_cxx::power;
import(std);
import(experimental);
import(chrono);
import(literals);
import(placeholders)
let(lli,long long);
let(ull, unsigned long long);


struct ll {
	lli x;
	constexpr ll(long long int x_ = 0): x(x_) {}
	constexpr operator _&(){return x;}
	constexpr operator lli() co {return x;}
	

	

	
	

	

	
	constexpr ll operator-() co{return -x;}
	ll operator--(){--x; return this;}
	ll operator++(){++x; return this;}
	ll operator+=(ll b){return x += b.x;}
};




aug(+); aug(-); aug(*); aug(/);









bill(+) bill(*) bill(|) bill(&) bill(^) bill(<<) bill(>>)
constexpr ll operator/(ll co& a, ll co& b){
   lli x = lli(a)/lli(b), r = lli(a)%lli(b);
   return x-((x < 0) && r);
}
constexpr _ operator<(ll a, ll b){return lli(a) < lli(b);}
constexpr _ operator==(ll a, ll b){return lli(a) == lli(b);}
constexpr ll operator%(ll a, ll b){
	lli x = lli(a)%lli(b);
	if(lli(x) < 0){x+=lli(b);}
	return x;
}
mixll(+) mixll(/) mixll(*) mixll(<) mixll(==) mixll(%) mixll(&) mixll(>>) mixll(<<)
_& operator<<(ostream& os, ll co& a){
	return os<<a.x;
}
ll operator ""M (unsigned long long int x){
	return x;
}
_ ceil_div(ll x, ll y){
	return (x+y-1)/y;
}
END_NS
namespace std {

inh(hash){using hash<lli>::hash;};
inh(is_integral){}; inh(is_unsigned){}; inh(is_signed){}; inh(numeric_limits){};
_ operator+(_ a, ll b){return a+lli(b);}
}
BEGIN_NS

let(vl,vector<ll>);
let(ld,long double)
let(pr,pair<ll, ll>);
let(com, complex<double>);
let(pt, complex<ll>);
using bt = bitset<numeric_limits<ll>::digits>;
tm() using pq = std::priority_queue<T, vector<T>, greater<>>;
let(clock_, high_resolution_clock);
import(this_thread);
let(um,unordered_map<ll, ll>);
tm() _ type_name([[maybe_unused]] T co& v){
	string s = id2, tar = "T = ";
	_ st = s.find(tar)+tar.size();
	return s.substr(st, s.find("]", st)-st);
}
_ replace(_ s, $ a, $ b){
	ll loc;
	while((loc = s.find(a)) !=string::npos){
		s = s.substr(0, loc) + b + s.substr(loc+a.size());
	}
	return s;
}
_ simple_tp([[maybe_unused]] $ v){
	_ s = type_name(v);
	for($ p: lets){
		s = replace(s, p.first, p.second);
	}
	return s;
}
_ constexpr inf = ll(numeric_limits<ll>::max())/8;
_ co delim = ", "s;
_ constexpr tau = 2*3.1415926535897932384626433L;

struct rin {
	istream& in;
	rin(istream& in_): in(in_) {}
	_& operator<<(const char*){
		return this;
	}
	_& operator<<(string co& s){
		if(s.empty()){
			in>>const_cast<string&>(s);
		}
		return this;
	}
	rin& operator>>(_& x){
		this << x;
		return this;
	}
};
template<typename R, typename T>
_ operator<<(R& r, const T& x) -> decltype(r.in>>const_cast<T&>(x), declval<enable_if_t<is_same<R, rin>::value, rin&>>()) {
	r.in>>const_cast<T&>(x);
	return r;
}
tm() enable_if_t<is_same<T, istream>::value, rin> operator>>(T& is, _& x){
	rin r{is};
	return r>>x;
}
tm(...) _& operator<<(ostream& os, tuple<T...> t){
	apply([&](_& f, _& ... x){
		os<<f;
		((os<<delim<<x), ...);
		}, t);
	return os;
}
_ print($ arg1, $... args){
	cout<<arg1;
	(void)((cout<<" "<<args),...);
	cout<<endl;
}
END_NS
namespace std {
	tm(...) _& operator<<(ostream& os, pair<T...> co& p){
		return os<<simple_tp(p)<<"{"<<p.first<<delim<<p.second<<"}";
	}
	_ operator<<(ostream& os, $ v) -> decltype(begin(v), declval<tp(os)>()){
		_ ed = begin(v);
		_ big = v.size()>20;
		if(big){
			advance(ed, 20);
		}
		else {
			ed = end(v);
		}
		os<<simple_tp(v)<<"{";
		copy(begin(v), ed, make_ostream_joiner(os, delim));
		if(big){
			os<<delim<<"...";
		}
		return os<<"}";
	}
	_ operator<<(rin& os, $ v) -> decltype(begin(v), declval<tp(os)>()){
		for($ elem:v){
			os<<elem;
		}
		return os;
	}
	
	tm() _& operator<<(ostream& os, optional<T> co& opt){
		return opt?(os<<*opt):(os<<"nullopt");
	}
	
}

BEGIN_NS

tm() struct it_base {
	using value_type = T;
	using pointer = T*;
	using reference = T&;
	using difference_type = ll;
};
tm() struct int_it: it_base<T>{
	using iterator_category = random_access_iterator_tag;
	T x, m;
	int_it(_ x_, _ m_ = 1):x(x_), m(m_) {}
	int_it(_ x_):int_it(x_, 1){}
	int_it(){}
	_& operator *() co {
		static T x_stat;
		return x_stat = x;
	}
	explicit operator _() co {return x;}
	int_it operator+(ll y) co{return x+m*y;}
	int_it operator-(ll y) co{return x-m*y;}
	ll operator-(int_it<T> co& y) co{return (x-y.x)/m;}
	int_it operator ++(){return x+=m;}
	int_it operator --(){return x-=m;}
	int_it operator--(int){
		_ ret = x;
		--x;
		return ret;
	}
	int_it operator++(int){
		_ ret = x;
		++x;
		return ret;
	}
};

tm() bin(==, int_it<T>);
tm() bin(<, int_it<T>);
tm() struct range {
	T bg, ed;
	range(_ ed_):range(0LL, ed_){}
	range(T co& bg_, T co& ed_):bg(bg_),ed(max(bg,static_cast<T>(ed_))) {}
	_ begin() co{return bg;}
	_ end() co{return ed;}
	explicit operator ll(){return ed-bg;}
};
tm()
_ operator<(range<T> co& a, range<T> co& b){
	return a.bg==b.bg?a.ed>b.ed:a.bg<b.bg;
}
tm()
_ operator&(range<T> co& a, range<T> co& b){
return range<T>{max(a.bg, b.bg),min(a.ed, b.ed)};
}
_ rev($ r){
	using rev_it = reverse_iterator<tp(begin(r))>;
	return range{rev_it{end(r)}, rev_it{begin(r)}};
}
using ra = range<int_it<ll>>;
tm() int_it<T> operator +(int_it<T> co& a, int_it<T> co& b){return a.x + b.x;}
tm() int_it<T> operator -(int_it<T> co& a){return -a.x;}
enum isect {
	null, dis, over, cont, eq
};
_ intersect($ a, $ b){
	if(a == b){return isect::eq;}
	if(a[1] <= b[0]){return isect::dis;}
	if(a[0]<=b[0] && b[1] <= a[1]){return isect::cont;}
	if(a[0]<=b[0] && a[1] <= b[1]){return isect::over;}
	return isect::null;
}
tm() _ operator^(range<T> co& a, range<T> co& b){
	return max(intersect(a,b), intersect(b,a));
}
_ filter(vc<ra>& v){
	sort(al(v));
	vc<ra> sg;
	for($ p: v){
		if(sg.empty() || sg.back().ed < p.ed){
			sg.pb(p);
		}
	}
}

ll depth = -1;
_ debug($ x, $ name, source_location co& loc = source_location::current()){
	if(debug_mode){
		fo(i,depth){cerr<<"\t";}
		cerr<<loc.function_name()<<":"<<loc.line()<<" "<<name<<" = "<<x<<endl;
	}
	--depth;
	return x;
}

tm() struct mat {
	ll r,c;
	vc<T> a;
	mat(_ r_, _ c_, df(v, 0LL)): r(r_), c(c_), a(r*c, v) {assert(r>=1 && c>=1);}
	mat(_ d):r(1),c(1),a{d}{}
	mat(vc<vc<pr>> co& g):mat(g.size(),g.size(),inf) {
		fo(i,r){
			for($ p:g[i]){
				_ [x,w] = p;
				this[i][x] = w;
			}
		}
		fo(i,r){
			this[i][i]=0;
		}
	}
	_ operator[](_ i){
		return const_cast<T*>(const_cast<mat co&>(this)[i]);
	}
	_ operator[](_ i) co{
		return &a[i*c];
	}
	_ id() co{
		return this.r==1 && this.c==1 && this[0][0]==1;
	}
};
tm(...) _ operator*(mat<T...> co& a, mat<T...> co& b){
	if(a.id()){return b;}
	if(b.id()){return a;}
	assert(a.c == b.r);
	mat<T...> c{a.r, b.c};
	fo(i,c.r){
		fo(j,a.c){
			fo(k,c.c){
				c[i][k]+=a[i][j]*b[j][k];
			}
		}
	}
	return c;
}
tm(...) _& operator<<(ostream& os, mat<T...> co& m){
	os<<"mat{"<<endl;
	fo(i,m.r){
		copy(m[i], m[i]+m.c, make_ostream_joiner(os, delim));
		os<<endl;
	}
	return os<<"}";
}
template<typename T>
_ id3(vc<T> co& c, ll n){
	mat<T> m{size(c), size(c)};
	copy(al(c), m[0]);
	fo(i,1,size(c)){
		m[i][i-1] = 1;
	}
	return power(m,n)[0][0];
}


struct dsu {
	mutable vl p;
	vl s;
	explicit dsu(_ n): p(n), s(n,1) {iota(al(p),0);}
	ll operator[](ll x) co {return x==p[x]?x:p[x]=this[p[x]];}
	_ operator()(_ x, _ y){
		x = this[x]; y = this[y];
		if(x == y){return false;}
		if(s[x] > s[y]){swap(x,y);}
		s[y]+=s[x];
		p[x] = y;
		return true;
	}
};
_& operator<<(ostream& os, dsu co& d){
	os<<"dsu{";
	fo(i,d.p.size()){
		if(i){os<<delim;}
		os<<d[i];
	}
	return os<<"}";
}


_ constexpr operator-($ a, $ b){
	return a + -b;
}
_ constexpr operator!=($ a, $ b){
	return !(a==b);
}
_ operator<=($ a, $ b){
	return !(b < a);
}
_ operator>=($ a, $ b){
	return b <= a;
}
_ operator>($ a, $ b){
	return b < a;
}
tm() using uset = unordered_set<T>;
um operator+(um a, um co& b){
	for($ p:b){
		a[p.first]+=p.second;
	}
	return a;
}
tm() _ operator|(uset<T> co& a, uset<T> co& b){
	$ [sm, bg] = minmax(a, b);
	_ ret = bg;
	ret.insert(al(sm));
	return ret;
};
tm() _ operator&(uset<T> co& a, uset<T> co& b){
	$ [sm, bg] = minmax(a, b);
	uset<T> ret;
	for($ x: sm){
		if(bg.count(x)){
			ret.insert(x);
		}
	}
	return ret;
}
tm() _ sub_set(uset<T> co& a, uset<T> co& b, uset<T>& ret){
	for($ x: a){
		if(!b.count(x)){
			ret.insert(x);
		}
	}
	return ret;
}
tm() _ operator-(uset<T> co& a, uset<T> co& b){	
	uset<T> ret;
	return sub_set(a,b,ret);
}
tm() _ operator^(uset<T> co& a, uset<T> co& b){
	uset<T> ret = a-b;
	sub_set(b, a, ret);
	return ret;
}
tm() _ operator*(vc<T> a, vc<T> b){
	assert(a.size() == b.size());
	vc<T> c(a.size());
	fo(i,a.size()){
		c[i] = a[i]*b[i];
	}
	return c;
}
_ operator+(_ it, enable_if_t<!is_same<typename iterator_traits<tp(it)>::iterator_category, random_access_iterator_tag>::value, size_t> n){
	advance(it, n);
	return it;
}


struct with {
	ll old;
	ll& v;
	with(ll new_, ll& v_):old(v_), v(v_){v = new_;}
	~with(){v = old;}
};
_ fix($ func){
	

	return [=](_... args) {return func(fix(func), args...);};
}

_ maxeq(_&& x, _ co& y){
	x = max(x, y);
}
_ mineq(_&& x, _ co& y){
	x = min(x, y);
}
template<typename T>
_ cache($ f){
	T ch;
	return [=]($ arg) mutable {
		if(ch.find(arg) == end(ch)){
			ch[arg] = f(arg);
		}
		return ch[arg];
	};
}
template<typename Eq = equal_to<>, typename T = less<>>
_ uniq(_& v, Eq co& up = Eq{}, T co& sp = T{}){
	sort(al(v), sp);
	v.resize(unique(al(v), up)-begin(v));
	return v;
}
template<typename T = less<>>
_ map_args($ f, T g = T{}){
	return [&]($... args){return g(f(args)...);};
}
_ prev_less($ v){
	ll n = v.size();
	vl l(n,-1);
	stack<ll> s;
	fo(i,n){
		while(s.size() && !(s.top() < v[i])){
			s.pop();
		}
		if(s.size()){
			l[i] = s.top();
		}
		s.push(v[i]);
	}
	return l;
}
_ nx2(_ x){
	return ll(1LL)<<ll(ceil(log2(lli(x))));
}
ll next_comb(ll x){
	ll tz = __builtin_ctz(x);
	ll y = x+(ll{1}<<tz);
	return y|(y^x)>>(2+tz);
}


ll M = 1e9+7;
struct small_mod {};	
struct no_mod {};
struct md {
	ll x;
	md():x{0LL}{}
	template<typename T, typename = enable_if_t<is_integral<T>::value, void>>
	md(T x_):x(ll(x_)%M){}
	md(ll x_, small_mod):x(x_>=M?x_-M:x_){}
	md(ll x_, no_mod): x(x_) {}
	explicit operator _(){return x;}
};
md operator+(md co& a, md co& b){
	return {a.x+b.x, small_mod{}};
}
md operator++(md& a){
	return a+=1;
}
md operator-(md co& a){
	return {M-a.x, no_mod{}};
}
bin(==, md);
md operator*(md co& a, md co& b){
	ll ret = ull(a.x)*ull(b.x)-ull(M)*ull(ld(a.x)*ld(b.x)/ld(M));
	if(ret < 0){return {ret+M, no_mod{}};}
	if(ret >= M){return {ret-M, no_mod{}};}
	return {ret, no_mod{}};
}
struct id {};
md operator/(id, md co& b){
	assert(b != 0);
	return power(b, M-2);
}
_ operator/(md co& a, md co& b) {
	return a*(id{}/b);
}
_& operator<<(ostream& os, md co& m){return os<<m.x;}
END_NS
namespace std {
template<>
struct hash<md> {
	size_t operator()(md co& x) co {
		return x.x;
	}
};
}
BEGIN_NS


vl divs;
_ prime(_ n){
	assert(n>=2);
	if(n < divs.size()){
		return divs[n] == n;
	}
	with _m{n,M};
	ll tz = __builtin_ctz(n-1);
	_ b = (n-1)>>tz;
	dbg(b);
	_ prime_a = [&](md co& a){
		dbg(a);
		if(a==0){return true;}
		_ p = power(a,b);
		if(p==1){return true;}
		fo(i,tz){
			if(p == -1){return true;}
			p*=p;
		}
		return false;
	};
	vl v{2, 325, 9375, 28178, 450775, 9780504, 1795265022};
	return all_of(al(v), prime_a);
}
vl id0(ll x){
	vl v;
	fo(d,1,ll{ceil(sqrt(ld{x}))}+1){
		if(!(x%d)){
			v.pb(d);
			if(ll y = x/d; d!=y){
				v.pb(y);
			}
		}
	}
	return v;
}
_ sieve(ll n){
	vl d(n), ps;
	fo(i,2,n){
		if(d[i] == 0){ps.pb(d[i] = i);}
		for(_ p: ps){
			if(!(p<=d[i] && p*i < n)){break;}
			assert(d[p*i] == 0);
			d[p*i] = p;
		}
	}
	return d;
}
um fac(ll n){
	

	assert(n>=1);
	if(n==1){return {};};
	ll g = n;
	if(n < divs.size()){
		g = divs[n];
	}
	else if(!prime(n)) {
		with _m{n,M};
		for(md c = 0;g == n;++c){
			_ co f = [&]($ x){return x*x+x+c;};
			for(md a = 0, b = a; a = f(a), b = f(f(b)), (g = gcd(ll(a-b),n)) == 1;){}
		}
	}
	if(g == n){
		return {{n,1}};
	}
	assert(1 < g && g < n && !(n%g));
	return fac(g) + fac(n/g);
}
void egcd($ a, $ b, _& x, _& y){a?egcd(b%a, a, y, x),x-=b/a*y:(x=0,y=1);}

tm() struct ar {using type = T;};
tm() using ar_t = typename ar<T>::type;
template<typename T, size_t n>
struct ar<T[n]>{using type = array<ar_t<T>,n>;};

_ perm(_ a, _ b){
	using T = tp(a);
	return accumulate(int_it<T>{a+1-b}, int_it<T>{a+1}, 1LL, multiplies<>{});
}
_ fact(_ n){
	return perm(n, n);
}
_ choose(_ a, _ b){
	

	return perm(a, b)/fact(b);
}


struct edge {
	ll w, a, b;
	_ to_tuple() co{
		return tuple{w,a,b};
	}
};
operator<(edge co& a, edge co& b){
	return a.to_tuple() < b.to_tuple();
}
_& operator<<(ostream& os, edge co& e){
	return os<<"edge{"<<e.a<<"-"<<e.w<<"->"<<e.b<<"}";
}
_ dist(_ g, _ s){
	vl d(g.size(),inf), pv(g.size(),-1);
	pq<pr> q;
	d[s] = 0;
	fo(i,d.size()){
		q.push({d[i], i});
	}
	while(q.size()){
		$ [di, a] = q.top();
		q.pop();
		if(di != d[a]){continue;}
		for($ pb: g[a]){
			$ [b,w] = pb;
			_& x = d[b];
			_ nw = di+w;
			if(nw < x){
				pv[b] = a;
				x = nw;
				q.push({x,b});
			}
		}
	}
	return array<vl,2>{d,pv};
}
_ dist(mat<ll> co& g){
	assert(g.r == g.c);
	_ n = g.r;
	_ d = g;
	fo(k,n){
		fo(i,n){
			fo(j,n){
				_& x = d[i][j];
				x = min(x, d[i][k]+d[k][j]);
			}
		}
	}
	return d;
}
_ mst(_ es){
	sort(al(es));
	_ mi = -inf;
	for($ e: es){
		mi = max(mi,max(e.a,e.b));
	}
	dsu d{mi+1};
	tp(es) ret;
	for($ e: es){
		if(d(e.a,e.b)){continue;}
		ret.pb(e);
	}
	return ret;
}
struct gsearch {
	vc<vl> co& g;
	ll n;
	vl v;
	deque<ll> q;
	vl p, d;
	gsearch($ g_): g(g_), n(size(g)), v(n), p(n,-1), d(n) {}
	virtual void operator()(ll) = 0;
	void operator()(){
		fo(i,n){if(!v[i]){this(i);}}
	}
	_ add(ll j, ll i){
		d[j] = d[i]+1;
		p[j] = i;
	}
};

struct dfs: searcher {
	v[s] = true;
	for($ j: g[s]){
		if(v[j]){continue;}
		add(j, s);
		this(j);
	}
	q.push_front(s);
}
};
struct bfs: searcher {
	q.pb(s);
	for(ll idx = 0; idx < q.size(); ++idx){
		_ i = q[idx];
		if(v[i]){continue;}
		v[i]=true;
		for($ j: g[i]){
			q.pb(j);
			add(j, i);
		}
	}
}
};
_ trans($ g){
	ll n = size(g);
	vc<vl> h(n);
	fo(i,n){
		for(ll j:g[i]){
			h[j].pb(i);
		}
	}
	return h;
}
_ scc($ g){
	

	_ h = trans(g);
	dbg(h);
	vl cm(size(g), -1);
	_ assign = fix([&]($ assign, ll u, ll c) -> void {
			dbg(u);
			if(cm[u]!=-1){return;}
			cm[u] = c;
			for(ll v: h[u]){
				assign(v,c);
			}
		});
	dfs s{g};
	s();
	dbg(s.q);
	for(ll i:s.q){
		assign(i, i);
	}
	return cm;
}
_ id6($ g){
	bfs b{g};
	b();
	_ n = size(g);
	vl s(n);
	for(_ i:b.q){
		if(_ x = b.p[i]; x!=-1){s[i] = !s[x];}
	}
	bool bi = true;
	fo(i,n){
		for(_ j:g[i]){
			bi &= s[i] != s[j];
		}
	}
	return bi?optional{s}:nullopt;
}
_ max_match($ g){
	_ s = id6(g).value();
	ll n = g.size();
	vl m(n,-1);
	for(ll md = -1; md != inf;){
		vl v(n);
		vc<vl> h(n);
		fo(i,n){
			for(ll j:g[i]){
				if((j == m[i]) == s[i]){
					h[i].pb(j);
				}
			}
		}
		bfs b{h};
		b();
		md = inf;
		fo(i,n){
			if(s[i]==1 && m[i] == -1){
				md = min(md, b.d[i]);
			}
		}
		dbg(md);
		dbg(b.d);
		dbg(m);
		dbg(s);
		auto path = fix([&]($ path, ll i) -> bool{
			dbg(i);
			if(v[i]){return false;}
			v[i] = true;
			if(s[i] == 1 && m[i] == -1 && b.d[i] == md){return true;}
			for(ll j: g[i]){
				if(b.d[j] = b.d[i]+1){
					if(dbg(path(j))){
						dbg(j);
						if(s[i] == 0){
							m[i] = j;
							m[j] = i;
						}
						return true;
					}
				}
			}
			return false;
		});
		fo(i,n){
			if(s[i]==0 && m[i] == -1){
				path(i);
			}
		}
	}
	return m;
}
_ add_edge(vc<vl>& g, ll u, ll v){
	g[u].pb(v);
	g[v].pb(u);
}
_ graph_in(vc<vl>& g, ll m){
	fo(i,0,m){
		I(u);I(v);
		add_edge(g, --u, --v);
	}
}

tm() using bin_op = T(*)(T,T);

constexpr ll identity(bin_op<ll co&> co& f){
	ret(max<ll>, -inf);
	ret(min<ll>, inf);
	abort();
}
constexpr ll identity(bin_op<ll> co& f){
	ret(gcd<ll>, 0);
	abort();
}

struct first_cmp {
	operator()(_ a, _ b) co{
		return a.first < b.first;
	}
};
_ tim = 0LL;
tm()
struct pers {
	using event = pair<ll, T>;
	set<event, first_cmp> s;
	_ operator =($ v){
		event e{tim,v};
		s.erase(e);
		s.insert(e);
	}
	operator _() co{
		return (*--s.upper_bound({tim, T{}})).second;
	}
};
tm() _& operator<<(ostream& os, pers<T> co& p){
	return os<<static_cast<T>(p);
}


struct timer {
	tp(clock_::now()) t1;
	timer(): t1(clock_::now()){}
	~timer(){
		cerr<<"Time duration: "<<duration<ld>(clock_::now()-t1).count()<<" s"<<endl;
	}
};
_ bench(_ a){
	timer _t;
	dbg(ll(-5)/ll(3));
	dbg(tp(a)(-5)/tp(a)(3));
	dbg(tp(a)(-6)/tp(a)(3));
	tp(a) ans = 0;
	for(tp(a) i = 0; i < a; ++i){
		for(tp(a) j = 1; j < a; ++j){
			ans+=((-i)%(j));
		}
	}
	dbg(ans);
}





_ fft(_ v){
	_ n = nx2(v.size());
	if(n == 1){return v;}
	v.resize(n);
	vc<vc<com>> vs(2, vc<com>(n/2));
	fo(i,n){
		vs[i%2][i/2] = v[i];
	}
	for(_& x: vs){
		x = fft(x);
	}
	vc<com> f(n);
	fo(i2,n){
		_ i = i2%(n/2);
		f[i2] = vs[0][i]+exp(-com{0, double{tau}*double{i2/n}})*vs[1][i];
		

	}
	return f;
}
_ ifft(_ v){
	reverse(begin(v)+1, end(v));
	_ r = fft(v);
	for(_& x: r){
		x/=com{v.size()};
	}
	return r;
}

_ conv($ a, $ b){
	return ifft(fft(a)*fft(b));
}


struct bigint {
	vc<ull> v;
	explicit bigint($ v_): v(v_) {}
	_ operator[](size_t i) co{
		return i<v.size()?v[i]:0;
	}
};
_& operator<<(ostream& os, bigint co& a){
	return os<<a.v;
}
















ll coro(ll a){
	cobegin
	coreturn(404);
	for(static ll i=0;i<a;i++){
		coreturn(i*i);
	}
	coreturn(-1);
	coend
}


ll co sz = 30;
tm() struct no {
	vector<no*> p;
	T v;
	no(T co& v_, no* pa = nullptr): p(sz), v(v_){
		if(!pa){pa = &this;}
		fo(i,sz){
			p[i] = pa;
			pa = pa->p[i];
		}
	}
	_ gt(ll h){
		bt b(h);
		_ x = &this;
		fo(i,sz){
			if(b[i]){
				x = x->p[i];
			}
		}
		return x;
	}
	operator bool(){
		return p[0] != &this;
	}
	_ dp(){
		bt b;
		_ x = this;
		for($ i:rev(ra{sz})){
			if(*x.p[i]){
				x = *x.p[i];
				b[i] = 1;
			}
		}
		return ll(b.to_ullong())+1;
	}
};
tm() _ lca(no<T>* a, no<T>* b){
	ll da = a->dp(), db = b->dp();
	if(da > db){swap(a,b);}
	b = b->gt(db-da);
	if(a == b){return a;}
	for($ i:rev(ra{sz})){
		if(a->p[i] != b->p[i]){
			a = a->p[i];
			b = b->p[i];
		}
	}
	dbg(a->v); dbg(b->v);
	assert(a->p[0] == b->p[0]);
	return a->p[0];
}


namespace std {
_ operator<(pt co& a, pt co& b){
	return map_args([](_ x){return tuple{real(x), imag(x)};})(a,b);
}
}
_ dot(pt co& a, pt co& b){
	return real(conj(a)*b);
}
_ wedge(pt co& a, pt co& b){
	return imag(conj(a)*b);
}
_ area(_ a, _ b, _ c){
	return wedge(b-a, c-a);
}
_ ccw(pt a, pt b, pt c){
	ll w = area(a,b,c);
	if(!(a == b || a == c || b == c || w)){
		throw invalid_argument{"Points are collinear."};
	}
	return w > 0;
}
_ hull(_& v, df(do_sort, true)){
	if(do_sort){
		_ p = *min_element(al(v), map_args([](pt a){return tuple{imag(a), real(a)};}));
		sort(al(v), bind(ccw, p, _1, _2));
	}
	vc<pt> h;
	for(_ x:v){
		while(h.size()>=2 && !ccw(h[h.size()-2], h.back(), x)){
			h.pop_back();
		}
		h.push_back(x);
	}
	return h;
}
_ id4($ r, $ f){
	return *partition_point(al(r), [&](_ i){return !(f(i) < f(i+1));});
}
struct cht {
	vc<pt> h;
	cht(_& v){
		uniq(v, map_args(lambda(imag), equal_to{}),map_args(lambda(conj)));
		h = dbg(hull(v, false));
	}
	_ min($ x){
		_ co eval = [&]($ i){return real(h[i])*x+imag(h[i]);};
		return eval(id4(ra{size(h)-1}, eval));
	}
};

using ull = unsigned long long ;

struct hash_str {
	static _ constexpr id1 = (1ULL<<62)-57;
	const char* st;
	vc<md> h, p;
	explicit hash_str($ s): st(s.data()), h(s.size()+1), p(s.size()) {
		with _w{id1,M};
		md g = 1;
		fo(i,0,s.size()){
			g*=md{0x51a3e995948c0deULL};
			

			

			

			h[i+1] = md{s[i]}*g;
		}
		

		partial_sum(al(h), begin(h));		
		_ co inv = md{1}/md{0x51a3e995948c0deULL};
		md x = 1;
		fo(i,0,p.size()){
			p[i] = x;
			x*=md{inv};
		}
	}
	size_t operator()(string_view co& v){
		with _w{id1,M};
		ll l = v.data()-st;
		

		

		

		

		

		return ll((h[l+v.size()]-h[l]) * p[l]);
	}
};
struct bytehash {
	_ operator()($ x) co{
		return hash<string_view>{}(string_view{reinterpret_cast<const char*>(&x), sizeof(x)});
	}
};
vl prefix(string co& s){
	ll n = s.size();
	vl p(n);	
	fo(i,1,n){
		for(ll j = p[i-1]; ; j = p[j-1]){
			if(s[j] == s[i]){p[i] = j+1;break;}
			if(!j){break;}
		}
	}
	dbg(p);
	return p;
}
_ search_all(string co& t, string co& s){
	_ p = prefix(s+'\0'+t);
	vl v;
	fo(i,t.size()){
		if(p[s.size()+1+i] == s.size()){
			v.pb(i);
		}
	}
	return v;
}
string empstr = "";
struct search_it: it_base<ll> {
	using iterator_category = input_iterator_tag;
	string co& t, s;
	const ll n, ed;
	vl p;
	ll i=0, o=0;
	search_it(string co& t_, string co& s_): t(t_), s(s_), n(s.size()), ed(n+1+t.size()), p(n) {++this;}
	explicit search_it():search_it(empstr, empstr){}
	_ operator*(){
		assert(n);
		return i-(n+1);
	}
	void operator++(){
		for(++i;i < ed;++i){
			_ cur = i <= n?s.c_str()[i]:t[*this];
		 	for(ll j = o; ; j = p[j-1]){
				if(s[j] == cur){o = j+1; break;}
				if(!j){o = 0;break;}
			}
			if(i<n){
				p[i] = o;
			}
			dbg(i);dbg(o);
			if(o == n){
				break;
			}
		}
	}
};
_ operator==(search_it co& a, search_it co& b){
	bool sa = a.n, sb = b.n;
	if(sa ^ sb){return a.i == b.i;}
	if(sa){return a.i == a.ed;}
	if(sb){return b.ed == b.i;}
}
_ operator<(search_it co& a, search_it co& b){
	bool sa = a.n, sb = b.n;
	if(sa ^ sb){return a.i < b.i;}
	if(sa){return a.i < a.ed;}
	if(sb){return b.ed < b.i;}
}
_ search_ra($... args){
	return range{search_it(args...), search_it()};
}

END_NS

void main2();
extern co bool multitest;





_& in = cin;

int main(int argc, char *argv[]){
	


	fo(i,argc){
		if(argv[i] == "-q"s){
			debug_mode = false;
		}
	}
	ios::sync_with_stdio(false);
	if(!debug_mode){cerr.rdbuf(nullptr);}
	for(ios& os: initializer_list<reference_wrapper<ios>>{in, cout, cerr, clog}){
		fixed(os);
		if(os.rdbuf()){os.exceptions(ios::failbit | ios::badbit | ios::eofbit);}
		os.precision(false?numeric_limits<ld>::max_digits10:5);
	}
	cout.precision(numeric_limits<ld>::max_digits10);
	timer _t;
	ll t = 1;
	if(multitest){cin>>t;}
	fo(i,t){
		main2();
	}
}

BEGIN_NS
template<typename T, typename V = null_type>
using omap = tree<T, V, less<>, rb_tree_tag, tree_order_statistics_node_update>;
END_NS
BEGIN_NS

template<_ op, lli id_ = identity(op)>
struct seg {
	using T = tp(identity(op));
	static constexpr T id = id_;
	ll co n;
	mutable vc<T> a, z;
	seg(_ v): n(nx2(v.size())), a(2*n, id), z(2*n){
		copy(al(v), begin(a)+n);
		for(_ i:rev(ra{n})){
			dbg(i);
			a[i] = op(a[2*i],a[2*i+1]);
		}
	}
	co static _ def = -1LL;
	_ fix(_ l, _& r, _ nl, _& nr) co{
		if(r == def){r = l+1;}
		if(nr == def){nr = n;}
		return make_tuple((nl+nr)/2, r<=nl || nr<=l, l<=nl && nr<=r);
	}
	_ down(_ i) co{
		a[i]+=z[i];
		if(i<n){
			fo(j,2){z[2*i+j]+=z[i];}
		}
		z[i] = 0;
	}
	
	T gt(sig) co {
		$ [m, dis, over] = fix(l, r, nl, nr);
		down(i);
		return dis?id:over?a[i]:op(gt(l, r, 2*i, nl, m), gt(l, r, 2*i+1, m, nr));
	}
	_ up(_ v, sig){
		$ [m, dis, over] = fix(l, r, nl, nr);
		if(dis||over){
			if(over){
				z[i]+=v;
			}
			down(i);
			return;
		}
		up(v, l, r, 2*i, nl, m);
		up(v, l, r, 2*i+1, m, nr);
		a[i] = op(a[2*i], a[2*i+1]);
	}
};
template<_... args>
 _& operator<<(ostream& os, seg<args...> co& sg){
	os<<"seg{vl{";
	fo(i,sg.n){
		if(i){os<<delim;}
		os<<sg.gt(i);
	}
	return os<<"}}";
}
tm() struct lazy_ptr {
	mutable T* ptr;
	_ operator->() co{
		if(!ptr){
			ptr = new T{};
		}
		return ptr;
	}
	lazy_ptr(): ptr{nullptr} {}
	_& operator*() co{
		return *(this.operator->());
	}
	operator bool() co{
		return ptr;
	}
};
tm() struct pers_ptr {
	mutable T* ptr;
	_ operator->() co {
		if(ptr){
			dbg("creatin");
			ptr = new T{*ptr};
		}
		else {
			dbg("null");
			ptr = new T{};
		}
		return ptr;
	}
	pers_ptr(): ptr{nullptr} {}
	_& operator*() co{
		return *(this.operator->());
	}
	operator bool() co{
		return ptr;
	}
};
_ up_inv($ s, $ i){
	s.v(i).a = s.op(s.v(gl(i)).a,s.v(gr(i)).a);
}
tm() struct no_v {
	T a,z;
	no_v(): a{}, z{} {};
};
template<typename T, template<typename> typename Ptr>
struct id5 {
	T v;
	Ptr<id5> l_, r_;
	id5(): v{}, l_{}, r_{} {}
	id5(id5 co& oth): v{oth.v}, l_{}, r_{} {
		dbg("copying,,,");
		l_.ptr = oth.l_.ptr;
		r_.ptr = oth.r_.ptr;
	}
};
template<typename T>
using mypers = pers_ptr<id5<T, pers_ptr>>;
template<typename T>
using mylazy = lazy_ptr<id5<T, lazy_ptr>>;
_& gl($ ptr){
	return ptr->l_;
}
_& gr($ ptr){
	return ptr->r_;
}
tm() struct seg_base {
	_& v(T co& x) co{
		return x->v;
	}
	bool ok(T co& x) co{
		return true;
	}
	seg_base($ n, $ id){}
};
tm() struct no_impl {
	ll i;
	no_impl(ll i_ = 1): i(i_) {}
};
tm() no_impl<T> gl(no_impl<T> co& x) {return ll(x.i)<<ll(1);}
tm() no_impl<T> gr(no_impl<T> co& x) {return gl(x).i|ll(1);}
tm() struct seg_base<no_impl<T>> {
	mutable vc<T> v_;
	_& v(no_impl<T> x) co{
		return v_[x.i];
	}
	_ ok(no_impl<T> x) co{
		return x.i < v_.size();
	}
	seg_base($ n, $ id): v_(2*n){
		
	}
};
ll identity(plus<ll>){
	return 0;
}
template<typename Op = plus<ll>, template<typename> typename No_T = mypers, typename T = tp(identity(Op{})), typename No = No_T<no_v<T>>>
struct seg2: seg_base<No> {
	Op op;
	T id;
	ll co n;
	No ro;
	vc<No> h;
	
	seg2(ll n_): seg_base<No>(nx2(n_), 0LL), n{nx2(n_)}, id{identity(op)}, ro{} {}
	co static _ def = -1LL;
	ll l, r;
	_ mid(ll nl, ll nr) co {
		return ll(nl+nr)>>ll(1);
	}
	_ dis(ll nl, ll nr) co {
		return r<=nl || nr<=l;
	}
	_ over(ll nl, ll nr) co {
		return l<=nl && nr<=r;
	}
	_ down(No co& i, bool d) co{
		v(i).a+=v(i).z;
		

		
		do_lazy(gl(i));
		do_lazy(gr(i));
		v(i).z = 0;
	}
	
	T gt(sig) co {
		dbg(nl);dbg(nr);dbg(v(i).a);
		_ m = mid(nl, nr);
		down(i,nr-nl!=1);
		return dis(nl, nr)?id:over(nl, nr)?v(i).a:op(gt(gl(i), nl, m), gt(gr(i), m, nr));
	}
	_ gt(ll l_, ll r_){
		l = l_; r = r_;
		return gt(ro, 0, n);
	}
	_ gt(ll l){
		return gt(l, l+1);
	}
	_ up(T co& val, sig){
		

		

		_ m = mid(nl, nr);
		if(over(nl,nr)){
			dbg(nl);dbg(nr);
			v(i).z+=val;
		}
		down(i,nr-nl!=1);
		if(dis(nl,nr)||over(nl,nr)){
			return;
		}
		dbg("recursing...");
		up(val, gl(i), nl, m);
		up(val, gr(i), m, nr);
		up_inv(this, i);
		

	}
	_ up(_ val, ll l_, ll r_){
		l = l_; r = r_;
		h.pb(ro);
		up(val, ro, 0, n);
	}
	_ up(_ val, ll l){
		up(val, l, l+1);
	}
};

struct mymax {
	_ operator()(ll x, ll y) co{
		return max(x,y);
	};
};
_ identity(mymax){
	return -inf;
}

END_NS
co bool multitest = false;
struct random_device_patch { 

	unsigned int operator()(){
		return clock_::now().time_since_epoch().count(); 

	}
	double entropy() {
		return 0.0;
	}
};
using default_random_device = random_device_patch;
default_random_engine reng{default_random_device{}()};

template<typename Key, typename Data>
struct treap {
	treap *l{}, *r{}; 

	ll pri{}; 

	Key key{}; 

	Data data{};
	bool rev{};
	treap(Key co& key_): pri{reng()}, key{key_} {
		update_data(&this);
	}	
};
template<typename Key, template<typename> typename Data_Temp>
using treap_t = treap<Key, Data_Temp<Key>>;
template<typename Key>
struct size_data {
	ll size{};
};
template<typename Key>
size_data<Key> operator+(size_data<Key> co& l, size_data<Key> co& r){
	

	return size_data<Key>{l.size+r.size+1};
}
template<typename Key>
ostream& operator<<(ostream& os, size_data<Key> co& data){
	return os<<"size = "<<data.size<<endl;
}
template<typename Key, typename Data>
Data get_data(treap<Key, Data>* trp){
	return trp?trp->data:Data{};
}
void update_data(_* trp){
	if(!trp){return;}
	trp->data = get_data(trp->l)+get_data(trp->r);
}
void split(_* trp, _ co& key, _*& l, _*& r){
	

	if(!trp){l=r=nullptr;}
	else if(key < trp->key){
		split(trp->l, key, l, trp->l);
		r = trp;
	}
	else {
		split(trp->r, key, trp->r, r);
		l = trp;
	}
	update_data(trp);
}
template<typename Trp>
[[nodiscard]] Trp* join(Trp* l, Trp* r){
	

	down(l); down(r);
	_ ret = [&](){
		if(!l){return r;}
		else if(!r){return l;}
		else if(l->pri < r->pri){
			r->l = join(l, r->l);
			return r;
		}
		else {
			l->r = join(l->r, r);
			return l;
		}
	}();
	update_data(ret);
	return ret;
}
template<typename Trp>
void insert(Trp*& trp, Trp* x){
	if(!trp){trp=x;}
	else if (trp->pri < x->pri){
		split(trp, x->key, x->l, x->r), trp = x;
	}
	else{
		insert(x->key<trp->key ?trp->l :trp->r, x);
	}
	update_data(trp);
}
template<typename Trp>
_ insert(Trp*& trp, _ co& key){
	return insert(trp, new Trp{key});
}
void erase(_*& trp, const _& key){
	if(trp->key == key){
		trp = join(trp->l, trp->r);
	}
	else {
		erase(key < trp->key ?trp->l :trp->r, key);
	}
	update_data(trp);
}


void down(_* trp){
	if(!(trp && trp->rev)){return;}
	swap(trp->l, trp->r);
	
	flip(l)
	flip(r)
	
	trp->rev=0;
}
void split_imp(_* trp, ll pos, _*& l, _*& r, ll sum = 0){
	

	if(!trp){
		l=r=nullptr;
		return;
	}
	down(trp);
	ll cur = sum + get_data(trp->l).size;
	if(pos <= cur){
		split_imp(trp->l, pos, l, trp->l, sum);
		r = trp;
	}
	else {
		split_imp(trp->r, pos, trp->r, r, cur+1);
		l = trp;
	}
	update_data(trp);
}
template<typename Trp>
void insert_imp(Trp*& trp, Trp* x, ll pos){
	Trp *l, *r;
	split_imp(trp, pos, l, r);
	l = join(l, x);
	trp = join(l, r);
}
template<typename Trp>
void erase_imp(Trp*& trp, ll pos){
	Trp *l, *r, *x, *nr;
	split_imp(trp, pos, l, r);
	split_imp(r, 1, x, nr);
	trp = join(l, nr);
}
template<typename Trp>
auto get_imp(Trp*& trp, ll pos){
	Trp *l, *r, *x, *nr;
	split_imp(trp, pos, l, r);
	split_imp(r, 1, x, nr);
	trp = join(join(l, x), nr);
	return x->key;
}
template<typename Trp>
_ insert_imp(Trp*& trp, _ co& key, ll pos){
	return insert_imp(trp, new Trp{key}, pos);
}
template<typename T, typename... Ts>
T& operator<<(T& os, treap<Ts...>* trp){
	static ll lvl = -1;
	with _w{lvl+1, lvl};
	string tab(lvl, ' ');
	if(trp){
	os<<tab<<"key = "<<trp->key<<" "<<"priority = "<<trp->pri<<" "<<trp->data<<endl;
	os<<tab<<"Left"<<endl<<trp->l<<tab<<"Right"<<endl<<trp->r;
	}
	else{
		os<<tab<<"null"<<endl;
	}
	return os;
}
template<typename Key, typename Data>
void to_array(treap<Key, Data>* trp, vector<Key>& out){
	if(!trp){return;}
	to_array(trp->l, out);
	out.pb(trp->key);
	to_array(trp->r, out);
}
template<typename Key, typename Data>
vector<Key> to_array(treap<Key, Data>* trp){
	

	vector<Key> out;
	to_array(trp, out);
	return out;
}


void main2(){
	using trp = treap_t<ll, size_data>;
	trp* t{};
	I(n);I(q);I(m);
	vl a(n);
	cin>>a;
	fo(i,0,n){
		insert_imp(t, a[i], i);
	}
	fo(i,0,q){
		I(typ);I(l);I(r);
		--l;--r;
		if(typ==1){
			ll x = get_imp(t, r);
			dbg(x);dbg(r);
			dbg(t);
			erase_imp(t, r);
			dbg(t);
			insert_imp(t, x, l);
		}
		if(typ==2){
			trp *a{}, *b{}, *c{}, *d{};
			split_imp(t, l, a, b);
			split_imp(b, r-l+1, c, d);
			if(c){c->rev^=1;}
			t = join(join(a,c),d);
		}
		dbg(t);
	}
	fo(i,0,m){
		I(b);
		--b;
		cout<<get_imp(t, b)<<" ";
	}
	cout<<endl;
}
