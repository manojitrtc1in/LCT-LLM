





















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



 class RField {
    typedef unsigned int ui;
    typedef unsigned long long ull;
    inline ui pow(ui a, ui p){ui r=1,e=a;while(p){if(p&1){r=((ull)r*e)%N;}e=((ull)e*e)%N;p>>=1;}return r;}
    
    inline ui inv(ui a){return pow(a,N-2);}
public:
    inline RField(ui x = 0, ui N = 0) : N(N), v(x) {}
    inline RField pow(int p){return (*this)^p; }
    inline RField operator^(int p){return {pow(v,(ui)p),N};}
    inline RField&operator+=(const RField&o) {checkMod(o);if ((ll)v+o.v >= N) v = (ll)v+o.v-N; else v = v+o.v; return *this; }
    inline RField&operator-=(const RField&o) {checkMod(o);if (v<o.v) v = N-o.v+v; else v=v-o.v; return *this; }
    inline RField&operator*=(const RField&o) {checkMod(o);v=(ull)v*o.v % N; return *this; }
    inline RField&operator/=(const RField&o) {checkMod(o); return *this*={inv(o.v),N}; }
    inline RField operator+(const RField&o) const {RField r{*this};return r+=o;}
    inline RField operator-(const RField&o) const {RField r{*this};return r-=o;}
    inline RField operator*(const RField&o) const {RField r{*this};return r*=o;}
    inline RField operator/(const RField&o) const {RField r{*this};return r/=o;}
    inline RField operator-() {if(v) return {N-v,N}; else return {0,N};};
    inline RField& operator++() { ++v; if (v==N) v=0; return *this; }
    inline RField operator++(int) { RField r{*this}; ++*this; return r; }
    inline RField& operator--() { --v; if (v==-1) v=N-1; return *this; }
    inline RField operator--(int) { RField r{*this}; --*this; return r; }
    inline bool operator==(const RField&o) const { return o.v==v; }
    inline bool operator!=(const RField&o) const { return o.v!=v; }
    inline explicit operator ui() const { return v; }
    void checkMod(const RField&o) {
        if (N == 0 && o.N == 0) {
            throw std::runtime_error("No modulus set");
        } else if (N == 0) {
            N = o.N;
        } else if (o.N != 0 && N != o.N) {
            cerr << N << ' ' << o.N << endl;
            throw std::runtime_error("Different moduli");
        }
    }




private:
    ui v; ui N;
};


ostream &operator<<(std::ostream&os,const RField&f){return os<<(unsigned int)f;}
RField operator+(int i,const RField&f){return i+f;}
RField operator-(int i,const RField&f){return i-f;}
RField operator*(int i,const RField&f){return i*f;}
RField operator/(int i,const RField&f){return i/f;}



template <typename T> struct id1 {
	inline id1(ui X) : A(X), B(0), s(0) {}
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
	int find(int x) { while (P[x]>=0){x = P[x];}return x; }
	bool united(int x, int y) { return find(x) == find(y); }
	bool unite(int x, int y) { x=find(x);y=find(y);if(x==y){return false;}--comp;if(P[x]>P[y]){swap(x,y);}P[x]+=P[y];P[y]=x;return true;}
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

bool id2(ll a, ll b, ll c, ll d) {
	if (b < 0) { b = -b; a = -a; }
	if (d < 0) { d = -d; c = -c; }
	return a < 0 && c < 0 ? mulull(-a, d) <= mulull(-c, b) : (a >= 0) && (c < 0 || mulull(a, d) >= mulull(c, b));
}

bool id2(pair<ll, ll> a, pair<ll, ll> b) {
	return id2(a.x, a.y, b.x, b.y);
}


bool id2(double a, double b, double c, double d) {
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
					return id2(x->b - y->b, y->m - x->m, y->b - z->b, z->m - y->m);
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
			while (size() >= 2 && id2(at(size()-2).b - back().b, back().m - at(size()-2).m, back().b - b, m - back().m)) parent::pop_back();
			parent::push_back({m,b,i});
		}

		pair<T,int> advance(T x) {
			assert(x >= 0);
			t += x;
			while (i+1 < size() && at(i).m * t + at(i).b < at(i+1).m * t + at(i+1).b) ++i;
			return {at(i).m * t + at(i).b, at(i).id};
		}
	};};

class clues {
public:
    void solve(istream& cin, ostream& cout) {
        ui N, M, K; cin >> N >> M >> K;
        UnionFind UF(N);
        for (int i = 0; i < M; ++i) {
            int a,b; cin >> a >> b;
            --a; --b;
            UF.unite(a,b);
        }

        RField RF{1, K};
        int c = 0;
        for (int j = 0; j < N; ++j) {
            if (UF.P[j] < 0) {
                RF *= {ui(-UF.P[j]),K};
                if (++c > 2) RF *= {N, K};
            }
        }
        cout << (c==1 ? 1%K : RF)  << endl;
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	clues solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}