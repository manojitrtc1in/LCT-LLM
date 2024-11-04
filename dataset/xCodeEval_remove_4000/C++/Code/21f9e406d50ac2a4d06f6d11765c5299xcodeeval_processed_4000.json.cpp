





















using namespace std;



typedef std::pair<int,int> pii; typedef long long ll; typedef unsigned long long ull; typedef unsigned int ui; typedef pair<ui,ui> puu;

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.x >> p.y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template <typename T, typename U> std::ostream&operator<<(std::ostream&o, const pair<T,U>&p) {o << p.x << ' ' << p.y; return o;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {if(t.empty())o<<'\n';for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}
template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxheap = priority_queue<T, vector<T>, less<T>>;
template <typename T> bool in(T a, T b, T c) { return a <= b && b < c; }
ui logceil(int x) { return 8*sizeof(int)-__builtin_clz(x); }

namespace std { template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}}; }
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename F> double id0(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){l=m;}else{h=m;}}return (l+h)/2;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename F> double bsld(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){h=m;}else{l=m;}}return (l+h)/2;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

template<typename T>class vector2:public vector<vector<T>>{public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}};
template<typename T>class vector3:public vector<vector2<T>>{public:vector3(){} vector3(size_t a,size_t b,size_t c,T t=T()):vector<vector2<T>>(a,vector2<T>(b,c,t)){}};
template<typename T>class vector4:public vector<vector3<T>>{public:vector4(){} vector4(size_t a,size_t b,size_t c,size_t d,T t=T()):vector<vector3<T>>(a,vector3<T>(b,c,d,t)){}};
template<typename T>class vector5:public vector<vector4<T>>{public:vector5(){} vector5(size_t a,size_t b,size_t c,size_t d,size_t e,T t=T()):vector<vector4<T>>(a,vector4<T>(b,c,d,e,t)){}};



 	







template <typename T> struct id4 {
	inline id4(ui X) : A(X), B(0), s(0) {}
	inline void push(ui L, T V) { B = max(B, L); A[L].push(V); ++s; }
	inline const T &top() const { return A[B].front(); }
	inline void pop() { --s; A[B].pop(); while (B > 0 && A[B].empty()) --B; }
	inline bool empty() const { return A[B].empty(); }
	inline void clear() { s = B = 0; for (auto &a: A) a = queue<T>(); }
	inline ui size() const { return s; }
private:
	vector<queue<T>> A; ui B; int s;
};

struct 	UnionFind {
	UnionFind(size_t N) : P(N, -1), comp(N) {}
	int find(int x) { while (P[x]> 0){x = P[x]-1;}return x; }
	bool united(int x, int y) { return find(x) == find(y); }
	bool unite(int x, int y) { x=find(x);y=find(y);if(x==y){return false;}--comp;if(P[x]>P[y]){swap(x,y);}P[x]+=P[y];P[y]= x+1;return true;}
	vector<int> P;
	size_t comp;
};


ull mulull(ull a, ull z, ull mod) {

	__int128 result = ((__int128) a * (__int128) z) % (__int128) mod;
	return (ull) result;

    

	ull q = mod / a, r = mod % a;
	ull rzq = (r < q) ? r * (z/q) : mulull(r, z/q, mod);
	ull azq = a * (z % q);
	if (azq >= rzq) return azq-rzq; else return azq-rzq+mod;

}


pair<ull,ull> mulull(ull a, ull b) {

	__int128 result = (__int128) a * (__int128) b;
	return {(ull) (result >> 64), (ull) result};

	ull c = (ui)a, d = a>>32, e = (ui)b, f = b>>32, g = d*f, h = d*e, i = f*c, j = c*e, k = (j>>32)+(ui)h+(ui)i, l = g+(h>>32)+(i>>32)+(k>>32);
	return {l, ((h+i) << 32) + j};

}

bool id5(ll a, ll b, ll c, ll d) {
	if (b < 0) { b = -b; a = -a; }
	if (d < 0) { d = -d; c = -c; }
	return a < 0 && c < 0 ? mulull(-a, d) <= mulull(-c, b) : (a >= 0) && (c < 0 || mulull(a, d) >= mulull(c, b));
}

bool id5(pair<ll, ll> a, pair<ll, ll> b) {
	return id5(a.x, a.y, b.x, b.y);
}


bool id5(double a, double b, double c, double d) {
	return a/b >= c/d;
}




























namespace Envelope {
	template<typename T>
	struct Line {
		T m, b; int id;
		mutable function<const Line<T> *()> succ;

		bool operator<(const Line &rhs) const {
			if (rhs.b != numeric_limits<T>::min()) return m < rhs.m;
			const Line *s = succ();
			if (!s) return 0;
			return b - s->b < (s->m - m) * rhs.m;
		}
	};

	template<typename T>
	struct Upper : public multiset<Envelope::Line<T>> {
		using parent = multiset<Line<T>>;

		bool bad(typename parent::iterator y) {
			auto z = next(y);
			if (y == parent::begin()) {
				return z != parent::end() && y->m == z->m && y->b <= z->b;
			} else {
				auto x = prev(y);
				if (z == parent::end()) {
					return y->m == x->m && y->b <= x->b;
				} else {
					return id5(x->b - y->b, y->m - x->m, y->b - z->b, z->m - y->m);
				}
			}
		}

		void insert_line(T m, T b, int i = 0) {
			auto y = parent::insert({m, b, i});
			y->succ = [=] { return next(y) == parent::end() ? 0 : &*next(y); };
			if (bad(y)) { parent::erase(y); return; }
			while (next(y) != parent::end() && bad(next(y))) parent::erase(next(y));
			while (y != parent::begin() && bad(prev(y))) parent::erase(prev(y));
		}

		T operator[](T x) const {
			auto l = parent::lower_bound({x, numeric_limits<T>::min()});
			return l == parent::end() ? numeric_limits<T>::min() : l->m * x + l->b;
		}

		int best(T x) const {
			auto l = parent::lower_bound({x, numeric_limits<T>::min()});
			return l == parent::end() ? -1 : l->id;
		}
	};

	

	template<typename T>
	struct Lower : public Upper<T> {
		void insert_line(T m, T b, int i = 0) { Upper<T>::insert_line(-m, -b, i); }
		T operator[](T x) const { return -Upper<T>::operator[](x); }
	};
}


namespace LinearEnvelope {
	template<typename T> struct Line { T m, b; int id; };

	template <typename T>
	struct Upper : public vector<Line<T>> {
		using parent = vector<Line<T>>;
		using parent::at; using parent::back; using parent::size;

		T t; int i;

		Upper() : t(0), i(0) {}

		void insert_line(T m, T b, int i = 0) {
			assert(t == 0);
			while (size() > 0 && ((back().b < b) || (back().b == b && back().m < m))) parent::pop_back();
			while (size() >= 2 && id5(at(size()-2).b - back().b, back().m - at(size()-2).m, back().b - b, m - back().m)) parent::pop_back();
			parent::push_back({m,b,i});
		}

		pair<T,int> advance(T x) {
			assert(x >= 0);
			t += x;
			while (i+1 < size() && at(i).m * t + at(i).b < at(i+1).m * t + at(i+1).b) ++i;
			return {at(i).m * t + at(i).b, at(i).id};
		}
	};};



struct Sieve : public std::vector<bool> {
    

	explicit Sieve(ui n) : vector<bool>(n+1, true), n(n) {
		at(0) = false;
		if (n!=0) at(1) = false;
		for (ui i = 2; i*i <= n; ++i) {
			if (at(i)) for (int j = i*i; j <= n; j+=i) (*this)[j] = false;
		}
	}

	vector<int> primes() const {
		vector<int> ans;
		for (int i=2; i<=n; ++i) if (at(i)) ans.push_back(i);
		return ans;
	}

private:
	int n;
};

struct id3 : public std::vector<std::pair<int, int>> {
	explicit id3(ui n) : id3(n, Sieve{n}.primes()) {}

	id3(ui n, const vector<int>& primes) {
		search(-1, 1, 1, n, primes);
		std::sort(begin(), end());
	}
private:
	void search(int i, int x, int y, int n, const vector<int>&primes) {
		push_back({x,y});
		while (++i < primes.size() && (ll)x * primes[i] <= n) search(i, x*primes[i], -y, n, primes);
	}
};



struct id2 : public vector<int> {
	id2():vector<int>{7,9,21,33,87,93,97,103,123,181,207,223,241,271,289,297,321,349,363,403,409,411,427,433,439,447,453,459,483,513,531,579,607,613,637,663,711,753,787,801,829,861,871,891,901,919,931,933,993,1011,1021,1053,1087,1099,1137,1161,1203,1213,1237,1263,1269,1273, 1279,1311,1329,1333,1351,1371,1393,1413,1447,1449,1491,1501,1531,1537,1539,1581,1617, 1621,1633,1647,1663,1677,1699,1759,1773,1789,1791,1801,1803,1819,1857,1887,1917,1927, 1957,1963,1969,2043,2089,2103,2139,2149,2161,2173,2187,2193,2233,2239,2277,2307,2359, 2361,2431,2449,2457,2499,2571,2581,2607,2631,2637,2649,2667,2727,2791,2803,2821,2823, 2827,2907,2937,2989,3009,3013,3051,3057,3097,3111,3133,3153,3157,3163,3211,3241,3247,3253,3267,3271,3273,3283,3309,3337,3351,3357,3373,3379,3397,3469,3471,3513,3519,3559,3577,3579,3601,3621,3643,3651,3663,3679,3709,3747,3751,3769,3777,3787,3793,3843,3853,3871,3889,3891,3909,3919,3931,3951,3957,3967,3987,3999,4023,4059,4099,4119,4123,4207,4233,4249,4251,4263,4321,4329,4381,4389,4437,4449,4459,4497,4507,4519,4539,4567,4569,4581,4609,4611,4627,4633,4647,4693,4699,4717,4771,4777,4783,4791,4807,4839,4843,4849,4857,4867,4869,4891,4893,4897,4927,4933,4977,4981,5001,5029,5053,5067,5103,5133,5187,5197,5203,5233,5277,5287,5299,5317,5329,5341,5353,5361,5403,5407,5437,5443,5449,5451,5469,5491,5527,5541,5547,5583,5631,5647,5683,5731,5737,5751,5763,5791,5823,5827,5833,5847,5863,5899,5907,5947,5953,5959,5971,5973,5991,5997,6019,6027,6037,6039,6061,6093,6099,6127,6129,6177,6193,6211,6223,6229,6307,6313,6331,6349,6379,6393,6417,6421,6457,6459,6477,6541,6571,6577,6583,6607,6621,6661,6663,6697,6717,6751,6781,6837,6867,6901,6957,6961,6967,6981,7003,7023,7027,7089,7117,7137,7147,7159,7191,7209,7237,7243,7257,7279,7321,7347,7383,7389,7417,7429,7447,7453,7467,7479,7497,7513,7521,7531,7537,7557,7633,7647,7651,7653,7681,7707,7719,7741,7759,7773,7803,7819,7837,7873,7887,7909,7923,7927,7929,7941,8041,8083,8089,8101,8109,8127,8173,8181,8223,8257,8259,8271,8277,8311,8313,8343,8349,8397,8403,8419,8431,8439,8487,8511,8557,8593,8617,8637,8649,8661,8671,8679,8719,8727,8761,8773,8791,8797,8803,8811,8829,8853,8899,8917,8937,8967,9009,9013,9063,9081,9093,9099,9123,9133,9163,9183,9211,9223,9259,9277,9279,9289,9301,9321,9331,9363,9399,9403,9421,9441,9457,9469,9487,9519,9529,9531,9541,9559,9561,9567,9573,9579,9597,9601,9609,9631,9651,9667,9679,9711,9733,9739,9757,9789,9831,9859,9867,9961,9999,10029,10051,10069,10101,10153,10173,10189,10197,10233,10243,10251,10267,10281,10303,10321,10327,10351,10357,10381,10449,10467,10483,10503,10513,10549,10593,10597,10611,10633,10659,10699,10707,10723,10747,10749,10761,10773,10777,10801,10833,10903,10953,10969,10971,10981,10987,11007,11011,11071,11083,11091,11107,11109,11137,11149,11161,11223,11239,11253,11269,11277,11283,11289,11301,11317,11329,11371,11377,11391,11421,11479,11487,11497,11517,11533,11539,11559,11583,11601,11619,11631,11659,11673,11679,11707,11763,11767,11769,11773,11799,11811,11821,11823,11847,11869,11967,11983,11989,12019,12037,12121,12157,12177,12187,12217,12219,12231,12241,12253,12297,12309,12333,12337,12339,12361,12367,12399,12411,12459,12463,12483,12501,12513,12523,12547,12553,12577,12609,12631,12649,12679,12681,12703,12723,12733,12747,12753,12759,12799,12847,12877,12891,12901,12903,12927,12939,12963,13011,13017,13029,13039,13081,13087,13089,13101,13107,13137,13141,13143,13153,13191,13207,13213,13237,13323,13369,13419,13437,13447,13477,13519,13537,13561,13563,13587,13591,13723,13741,13759,13789,13801,13857,13881,13897,13921,13923,13939,13999,14011,14073,14077,14083,14097,14121,14131,14143,14157,14161,14167,14181,14193,14209,14241,14259,14271,14293,14361,14391,14397,14437,14529,14551,14581,14583,14599,14607,14611,14643,14727,14761,14773,14779,14791,14823,14853,14881,14889,14901,14931,14937,14997,15031,15043,15057,15063,15069,15097,15103,15109,15117,15141,15147,15187,15199,15217,15231,15253,15271,15279,15283,15307,15339,15349,15351,15363,15369,15409,15427,15447,15477,15487,15553,15579,15591,15649,15651,15673,15693,15703,15717,15727,15747,15799,15811,15823,15859,15889,15963,15981,16009,16021,16029,16047,16063,16089,16093,16107,16153,16167,16191,16201,16231,16233,16261,16267,16273,16317,16323,16411,16419,16431,16489,16491,16513,16539,16617,16621,16623,16627,16651,16659,16671,16711} { for (int&i:*this)i+=1000000000; }
};

vector<int> id1{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257};


bool isPrime(ll n) {
    for (int p:id1)
        if (p<n&&n%p==0) return false;
	ll d = n-1, r = 0;
	while (d%2==0) { d/=2; r += 1; }
	auto composite = [=](int a) {
		ll x = 1, p = a, e = d;
		while(e>0) { if(e%2>0){x=mulull(x,p,n);} e/=2; p=mulull(p,p,n); }
		if (x == 1 || x == n-1) return false;
        for (int i=1;i<r;++i) {
            x=mulull(x,x,n);
            if (x==1) return true;
			if (x==n-1) return false;
		}
        return true;
	};

	return !(composite(2))
		   && (n<2047 || !composite(3))
		   && (n<1373653 || !composite(5))
		   && (n<25326001 || !composite(7))
		   && (n<3215031751LL || !composite(11))
		   && (n<2152302898747LL || !composite(13))
		   && (n<3474749660383LL || !composite(17))
		   && (n<341550071728321LL || (!composite(19) && !composite(23)))
		   && (n<3825123056546413051LL || (!composite(29) && !composite(31) && !composite(37)));
}






class Fraction {
    friend ostream& operator<<(ostream& os, const Fraction& f);
public:
    Fraction(ll u = 0, ll v = 1) : u(u), v(v) { norm(); }
    bool operator==(const Fraction & o) const { return u == o.u && v == o.v; }
    bool operator!=(const Fraction & o) const { return u != o.u || v != o.v; }
    bool operator<(const Fraction &o) const { return u*o.v < o.u*v; }
    bool operator<=(const Fraction &o) const { return u*o.v <= o.u*v; }
    bool operator>(const Fraction &o) const { return u*o.v > o.u*v; }
    bool operator>=(const Fraction &o) const { return u*o.v >= o.u*v; }
    Fraction operator-(const Fraction& o) { return Fraction(-u, v); }
    Fraction& operator+=(const Fraction& o) { u = u * o.v + v * o.u; v *= o.v; return norm(); }
    Fraction& operator-=(const Fraction& o) { u = u * o.v - v * o.u; v *= o.v; return norm(); }
    Fraction& operator/=(const Fraction& o) { u = u * o.v; v = o.u * v; return norm(); }
    Fraction& operator*=(const Fraction& o) { u *= o.u; v *= o.v; return norm(); }
    Fraction operator+(const Fraction& o) const { Fraction f(*this); return f += o; }
    Fraction operator-(const Fraction& o) const { Fraction f(*this); return f -= o; }
    Fraction operator*(const Fraction& o) const { Fraction f(*this); return f *= o; }
    Fraction operator/(const Fraction& o) const { Fraction f(*this); return f /= o; }

private:
    Fraction& norm() {
        ll g = gcd(abs(u),abs(v));
        u /= g;
        v /= g;
        return *this;
    }

    ll u,v;
};


ostream& operator<<(ostream& os, const Fraction& f) {
    os << f.u << '/' << f.v;
    return os;
}

class TaskB {
public:
void solve(istream& cin, ostream& cout) {
    int T; cin >> T;
    for (int t = 0; t < T; ++t) {
        int a; cin >> a;
        if (a == 2) cout << "1/6\n";
        else if (a == 3) cout << "7/30\n";
        else {
            ll b = a+1;
            while (!isPrime(b)) ++b;
            ll c = a;
            while (!isPrime(c)) --c;
            ll num = c*(b-2) - 2*(b-a-1);
            ll den = 2*b*c;
            cout << Fraction{num, den} << '\n';
        }
    }
}
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	TaskB solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}