



















using namespace std;

using unsigned_int = unsigned int;
using need_int = int;
using counter_type = int;
using MAIN = int;

using ll = long long;

template<typename T>
using PairOf = pair<T,T>;

using Void = tuple<>;

namespace mytl{

template<typename T, typename R, typename F=function<R(T)> >
vector<R> fmap(F f, const vector<T>& t){
    vector<R> res;
    for(auto elem : t) res.push_back(f(elem));
    return res;
}

template<typename T>
vector<T> forrange(T n, T from){
    vector<T> res(n);
    iota(res.begin(), res.end(), from);
    return res;
}

template<typename F>
void repeat(need_int n, const F& callback){
    for(need_int _ : forrange(n,0)) callback();
}




}
namespace mytl{

template<typename T>
T id7(bool(*f)(T), T l, T r){
    if(!f(l)) return l;
    while(l < r){
        T pivot = (l+r+1)/2;
        if(!f(pivot)) r = pivot-1;
		else l = pivot;
    }
    return l;
}

template<typename T>
T id5(bool(*f)(T), T l, T r, need_int iterations){
    mytl::repeat(iterations,[&](){
        T pivot = (l+r)/2;
        if(f(pivot)) l = pivot;
        else r = pivot;
    });
    return l;
}
}
namespace mytl{

template<typename T>
struct LazyVector : vector<T> {
	inline typename vector<T>::reference operator[](need_int i) {
		if (i >= vector<T>::size()) vector<T>::resize(i + 1);
		return vector<T>::operator[](i);
	}
};


template<typename T>
struct optional {
	T *ptr = nullptr;

	inline optional() {}
	inline optional(T val) {
		*ptr = val;
	}

	~optional() {
		if (ptr != nullptr) delete ptr;
	}
	inline T value() {
		return *ptr;
	}
	inline bool has_value() {
		return ptr != nullptr;
	}

	inline void set(T val) {
		ptr = new T;
		*ptr = val;
	}

};

}
namespace mytl{

struct Point{
    ll x, y;

    Point(ll x, ll y) : x{x}, y{y} {};
    Point(pair<ll,ll> initPair) : x{initPair.first}, y{initPair.second} {};

    pair<ll,ll> getPair(){

        return {x,y};
    }

    

    Point operator-() const{
        return {-x, -y};
    }
    Point operator+() const{
        return {x,y};
    }

    static ll sgn(ll x){
        return (x > 0) - (x < 0);
    }

    

    Point operator*(const ll& operand) const{
        return {x*operand, y*operand};
    }

    

    Point operator+(const Point& operand) const{
        return {x+operand.x, y+operand.y};
    }
    Point operator-(const Point& operand) const{
        return {x-operand.x, y-operand.y};
    }

    ll operator*(const Point& operand){ 

        return x*operand.y - y*operand.x;
    }

    ll direction(const Point& a, const Point& b) const{
        return sgn((a - *this) * (b - *this));
    };
};

ll distance_squared(const Point& a, const Point& b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

double distance(const Point& a, const Point& b){
    return sqrt(distance_squared(a, b));
}

ll id0(const Point& a, const Point& b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

typedef vector<Point> Poly;

bool inside(const Poly& poly, const Point& point, bool strict){ 

    ll prevdir = -2;
    for(ll i=0; i<poly.size(); i++){
        ll id1 = (i+1)%poly.size();
        ll dir = poly[i].direction(poly[id1], point);
        if(dir == 0){
            if(strict) return false;
        }
        else{
            if(dir != prevdir && prevdir != -2) return false;
            prevdir = dir;
        }

    }
    return true;
}

}
namespace mytl {

template<class T>
struct Resetter;

template<class T>
Resetter<T>* global_resetter = new Resetter<T>;

template<class T>
struct Resetter {

    using State = pair<counter_type, T>;

    State* state = new State{0, T()};

    Resetter(){}
    Resetter(T value){
        state = new State{0, value};
    }

    void activate(){
        global_resetter<T> = this;
    }

    void reset(T value){
        *state = State{state->first+1, value};
    }

    struct Variable{

        State state;
        State& parent = *global_resetter<T>->state;

        Variable() : state{*global_resetter<T>->state} {}
        Variable(T value) : state{global_resetter<T>->state->first, value} {}
        Variable(State st) : state{st} {}
        Variable(T value, State& parent) : state{parent->first, value} {};

        bool fresh(){
            return state.first >= parent.first;
        }

        void overwrite(){
            state = parent;
        }

        void refresh(){
            if(!fresh()) overwrite();
        }

        T get(){
            refresh();
            return state.second;
        }

        void survive(){
            state.first = parent.first;
        }

        void operator=(T new_value){
            state.second = new_value;
            survive();
        }

    };

};
}

namespace std{


istream& operator>>(istream& is, Void& x){
    return is;
}

template<typename P, typename Q>
istream& operator>>(istream& is, pair<P,Q> x){
    return is>>x.first>>x.second;
}


template<typename P, typename Q>
ostream& operator<<(ostream& os, const pair<P,Q>& x){
    os<<"("<<x.first<<", "<<x.second<<")";
    return os;
}

template<typename T, template<typename, typename...> typename Container>
ostream& operator<<(ostream& os, const Container<T>& x){
    os<<"{";
    bool first = true;
    for(const auto& elem : x){
        if(!first) os<<", ";
        os<<elem;
        first = false;
    }
    os<<"}";
    return os;
}

}

namespace mytl{

template<typename T, typename P=T>
T read(istream& is=cin){
    P a;
    is>>a;
    return T(a);
}

template<typename T, typename P, typename Q>
T read(istream& is=cin){
    P a;
    Q b;
    is>>a>>b;
    return T(a,b);
}

template<typename T, typename P, typename Q, typename R>
T read(istream& is=cin){
    P a;
    Q b;
    R c;
    is>>a>>b>>c;
    return T(a,b,c);
}


template<typename T, typename... Q, typename Container=vector<T>>
vector<T> readValues(ll n, istream& is=cin){
    vector<T> res;
    repeat(n, [&res](){
        res.push_back(read<T,Q...>());
    });
    return Container(res.begin(), res.end());
}

}


namespace mytl{


template<typename T>
void print(const T& x, ostream& os=cout){
    os<<x;
}

}
namespace mytl{
template<typename T>
T power(T base, ll exponential, T unit=1){
    T res = unit;
    while(exponential > 0){
        if(exponential%2 == 1) res = res * base;
        base = base * base;
        exponential = exponential / 2;
    }
    return res;
}
}
namespace mytl{
    struct Modulo{
        static ll global_mod;
    private:
        ll val;
    public:
        const ll MOD;
        Modulo(ll initMOD, ll initVal) : MOD{initMOD}, val{initVal} {
            val %= MOD;
            if(val < 0) val += MOD;
        };
        Modulo() : Modulo(global_mod, 0) {};

        static Modulo inverse(Modulo x){

            return power(x, x.MOD-2, x.unit());
        };
        Modulo unit() const{
            return Modulo(MOD, 1);
        }
        Modulo& operator=(const Modulo& operand){
            val = operand.val;
            return *this;
        };

        ll get() const{ 

            return val;
        }

        

        Modulo operator-() const{
            return Modulo(MOD, -val);
        };
        Modulo operator+() const{
            return Modulo(MOD, +val);
        };

        

        Modulo operator-(const ll& operand) const{
            return Modulo(MOD, val-operand);
        };
        Modulo operator+(const ll& operand) const{
            return Modulo(MOD, val+operand);
        };
        Modulo operator*(const ll& operand) const{
            return Modulo(MOD, val*operand);
        };
        Modulo operator/(const ll& operand) const{ 

            return Modulo(MOD, val * inverse(Modulo(MOD, operand)).get());
        };

        

        Modulo operator-(const Modulo& operand) const{
            return Modulo(MOD, val-operand.get());
        };
        Modulo operator+(const Modulo& operand) const{
            return Modulo(MOD, val+operand.get());
        };
        Modulo operator*(const Modulo& operand) const{
            return Modulo(MOD, val*operand.get());
        };
        Modulo operator/(const Modulo& operand) const{ 

            return Modulo(MOD, val * inverse(operand).get());
        };

    };

    ll Modulo::global_mod = 1000000007LL;

    Modulo mod107(ll x){
        return Modulo(1000000007LL, x);
    }
    ostream& operator<<(ostream& os, Modulo x){
        return os<<"("<<x.get()<<"%"<<x.MOD<<")";
    }


}
namespace mytl{
    template<ll MOD>
    struct TSModulo{
    private:
        ll val;

    public:
        static TSModulo inverse(TSModulo x){

            return power(x, MOD-2);
        };
		TSModulo(ll initVal) {
			if (-MOD < initVal && initVal < MOD) {
				val = initVal;
			}
			else {
				val = initVal % MOD;
			}
		}
        TSModulo() : TSModulo(0) {}
        TSModulo& operator=(const TSModulo&) = default;

        ll get() const{ 

			if (val >= 0) return val;
			else return val + MOD;
        }

        

        TSModulo operator-() const{
            return TSModulo(-val);
        };
        TSModulo operator+() const{
            return TSModulo(+val);
        };

        

        TSModulo operator-(const ll& operand) const{
            return TSModulo(val-operand);
        };
        TSModulo operator+(const ll& operand) const{
            return TSModulo(val+operand);
        };
        TSModulo operator*(const ll& operand) const{
            return TSModulo(val*operand);
        };
        TSModulo operator/(const ll& operand) const{ 

            return TSModulo(inverse(operand) * val);
        };

        

        TSModulo operator-(const TSModulo& operand) const{
            return TSModulo(val-operand.get());
        };
        TSModulo operator+(const TSModulo& operand) const{
            return TSModulo(val+operand.get());
        };
        TSModulo operator*(const TSModulo& operand) const{
            return TSModulo(val*operand.get());
        };
        TSModulo operator/(const TSModulo& operand) const{ 

            return TSModulo(val * inverse(operand));
        };
    };

    using Mod107 = TSModulo<1000000007LL>;

    template<ll MOD>
    ostream& operator<<(ostream& os, TSModulo<MOD> x){
        return os<<"("<<x.get()<<"%"<<MOD<<")";
    }


}
namespace mytl {

template <typename C, typename Arg, typename R>
function<R(Arg)> id6(R(*fn)(Arg)) {
	C table;
	return [fn, table](Arg arg) mutable -> R {
		optional<R>& res = table[arg];
		if (!res.has_value()) {
			res.set(fn(arg));
		}
		return res.value();
	};
}

template<template<typename, typename, typename...> typename C, typename Arg, typename R>
function<R(Arg)> memoize(R(*fn)(Arg)) {
	return id6<C<Arg, optional<R> >, Arg, R>(fn);
}

template<typename R>
function<R (ll) > id2(R(*fn)(ll)) {
	return id6<LazyVector<optional<R> >, ll, R>(fn);
}

template<typename R>
function<R(ll, ll)> id2(R(*fn)(ll, ll)) {
	LazyVector< LazyVector<optional<R> > > table;
	return [fn, table](ll p1, ll p2) mutable -> R {
		optional<R>& res = table[p1][p2];
		if (!res.has_value()) {
			res.set(fn(p1, p2));
		}
		return res.value();
	};
}


}
namespace mytl{


template<class Op>
struct id3 {
	using Range = typename Op::Range;
	using T = typename Op::T;
	using Change = typename Op::Change;


	struct Node {
		ll node;
		Range range;
		Node(ll node, Range range) : node{ node }, range{ range } {};

		Node left_child() {
			return Node(node * 2 + 1, range.leftHalf());
		}
		Node right_child() {
			return Node(node * 2 + 2, range.rightHalf());
		}

		T& partial(id3 *par) {
			return par->partial[node];
		}

		Change& pending(id3 *par) {
			return par->pending[node];
		}

		bool leaf() {
			return range.singleton();
		}

	};

	vector<T> partial;
	vector<Change> pending;
	Node root;
	
	ll left_child(ll node) {
		return node * 2 + 1;
	}
	ll right_child(ll node) {
		return node * 2 + 2;
	}

	T build_from(Node node, T(*getter)(ll)) {
		if (node.leaf()) {
			node.partial(this) = getter(node.range.l);
		}
		else {
			node.partial(this) = Op::reduce(build_from(node.left_child(), getter), build_from(node.right_child(), getter));
		}
		node.pending(this) = Op::identity();
		return node.partial(this);
	}

	id3(Range range, T(*getter)(ll)) : root(0, range) {
		partial = vector<T>(range.span() * 4, Op::zero());
		pending = vector<Change>(range.span() * 4, Op::identity());
		build_from(root, getter);
	}

	void add(Node node, Change change) {
		node.pending(this) = Op::push(node.pending(this), change);
	}

	void prepare(Node node) {
		if (!node.leaf()) {
			add(node.left_child(), node.pending(this));
			add(node.right_child(), node.pending(this));
		}
		node.partial(this) = Op::apply(node.range, node.partial(this), node.pending(this));
		node.pending(this) = Op::identity();
	}


	pair<T, T> query_(Node node, Range range, Change change) {
		

		prepare(node);
		if (node.range.inside(range)) {
			add(node, change);
			prepare(node);
			return { node.partial(this), Op::zero() };
		}
		if (!node.range.intersect(range)) {
			

			return { Op::zero(), node.partial(this) };
		}

		auto from_left = query_(node.left_child(), range, change);
		auto from_right = query_(node.right_child(), range, change);
		

		auto needed = Op::reduce(from_left.first, from_right.first), rest = Op::reduce(from_left.second, from_right.second);
		node.partial(this) = Op::reduce(needed, rest);
		return { needed, rest };
	}

	T query(Range range, Change change) {
		return query_(root, range, change).first;
	}

};


struct id8{

    ll l, r;

    id8(ll l, ll r): l{l}, r{r} {}

    ll span() const {
        return r-l+1;
    }
    bool singleton() const {
        return span() == 1;
    }
    id8 leftHalf() const {
        return id8(l, (l+r)/2);
    }
    id8 rightHalf() const {
        return id8((l + r)/2 + 1, r);
    }
    bool inside(const id8& other) const {
        return other.l <= l && r <= other.r;
    }
    bool intersect(const id8& other) const {

        return other.inside(*this)
             ||(other.l <= l && l <= other.r)
             ||(other.l <= r && r <= other.r);
    }
};


}

namespace mytl{
template<typename T_>
struct Add_Sum{
    using Range = id8;
    using T = T_;
    using Change = T_;

    static Change identity(){
        return 0;
    }

    static T zero(){
        return 0;
    }

    static T initial(Range r){
        return zero();
    }

    static T reduce(T a, T b){
        return a + b;
    }

    static T apply(Range r, T a, Change c){
        return a + r.span()*c;
    }

    static Change push(Change a, Change b){
        return a + b;
    }
};

template<typename T_>
struct Multiply_Sum{
    using Range = id8;
    using T = T_;
    using Change = T_;

    static Change identity(){
        return 1;
    }

    static T zero(){
        return 0;
    }

    static T initial(Range r){
        return r.span()*1;
    }

    static T reduce(T a, T b){
        return a + b;
    }

    static T apply(Range r, T a, Change c){
        return a*c;
    }

    static Change push(Change a, Change b){
        return a*b;
    }
};


}

namespace mytl{


}
namespace mytl{

template<typename T, T(*f)(T,T)>
struct Tracker {

	T* val = nullptr;

    void update(T x){
        if(val != nullptr){
            *val = f(*val, x);
        }
        else{
			val = new T;
			*val = x;
        }
    }

	T value() {
		return *val;
	}
};

template<typename T>
T min(T a, T b){return std::min(a,b);}
template<typename T>
T max(T a, T b){return std::max(a,b);}
template<typename T>
T id4(T a, T b){return std::id4(a,b);}

}



using ll = long long;
using Par = pair<ll, ll>;
using ParPar = pair<Par, Par>;

ll M = 1000000007;

Par operator+(Par a, Par b) {
	Par res = { (a.first + b.first), a.second + b.second };
	return { res.first%M, res.second%M };
}
Par operator*(Par a, ParPar b) {
	Par res = { b.first.first*a.first + b.first.second*a.second, b.second.first*a.first + b.second.second*a.second };
	return { res.first%M, res.second%M };
}
ParPar operator*(ParPar a_, ParPar b_) {
	ll a = a_.first.first,
		b = a_.first.second,
		c = a_.second.first,
		d = a_.second.second,
		e = b_.first.first,
		f = b_.first.second,
		g = b_.second.first,
		h = b_.second.second;
	ParPar res = { { e*a + f * c, e*b + f * d },{ g*a + h * c, g*b + h * d } };
	return { { res.first.first%M, res.first.second%M },{ res.second.first%M, res.second.second%M } };
}

struct Custom_Op {
	using Range = mytl::id8;
	using T = Par;
	using Change = ParPar;

	static Change identity() {
		return { { 1, 0 },{ 0,1 } };
	}
	static T zero() {
		return { 0, 0 };
	}

	static T initial(Range r) {
		Par res = { r.span() % M, r.span() % M };
		return res;
	}

	static T reduce(T a, T b) {
		T res = a + b;
		return res;
	}

	static T apply(Range r, T a, Change c) {
		T res = a * c;
		return res;
	}

	static Change push(Change a, Change b) {
		Change res = a * b;
		return res;
	}
};


ll n, m;

ParPar hatv(ll kitevo) {
	ParPar res = Custom_Op::identity();
	ParPar alap = { { 0,1 },{ 1,1 } };
	while (kitevo > 0) {
		if (kitevo % 2 == 1) res = res * alap;
		alap = alap * alap;
		kitevo /= 2;
	}
	return res;
}

vector<ll> be(200001);

typename Custom_Op::T kaka(ll index) {
	return Par{ 1,1 } *hatv(be[index] - 1);
}


MAIN main() {
	

	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> be[i];
	}
	mytl::id3<Custom_Op> node({ 1,n }, kaka);
	
	for (ll i = 1; i <= m; i++) {
		ll mode;
		cin >> mode;
		if (mode == 1) {
			ll l, r, x;
			cin >> l >> r >> x;
			node.query({ l,r }, hatv(x));
		}
		else {
			ll l, r;
			cin >> l >> r;
			cout << node.query({ l,r }, Custom_Op::identity()).first << endl;
		}
	}
	return 0;
}
