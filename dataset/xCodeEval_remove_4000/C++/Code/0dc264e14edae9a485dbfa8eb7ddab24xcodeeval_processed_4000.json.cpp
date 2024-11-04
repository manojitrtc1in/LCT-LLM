



















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
T id10(bool(*f)(T), T l, T r){
    if(!f(l)) return l;
    while(l < r){
        T pivot = (l+r+1)/2;
        if(!f(pivot)) r = pivot-1;
		else l = pivot;
    }
    return l;
}

template<typename T>
T id7(bool(*f)(T), T l, T r, need_int iterations){
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

ll id1(const Point& a, const Point& b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

typedef vector<Point> Poly;

bool inside(const Poly& poly, const Point& point, bool strict){ 

    ll prevdir = -2;
    for(ll i=0; i<poly.size(); i++){
        ll id2 = (i+1)%poly.size();
        ll dir = poly[i].direction(poly[id2], point);
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
function<R(Arg)> id9(R(*fn)(Arg)) {
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
	return id9<C<Arg, optional<R> >, Arg, R>(fn);
}

template<typename R>
function<R (ll) > id5(R(*fn)(ll)) {
	return id9<LazyVector<optional<R> >, ll, R>(fn);
}

template<typename R>
function<R(ll, ll)> id5(R(*fn)(ll, ll)) {
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
struct IntervalTree : Op::Range {
	using Range = typename Op::Range;
	using T = typename Op::T;
	using Change = typename Op::Change;
	using Range::singleton;
	using Range::inside;
	using Range::intersect;
	using Range::leftHalf;
	using Range::rightHalf;

	IntervalTree *left_child = NULL, *right_child = NULL;

	T partial;
	Change pending = Op::identity();

	IntervalTree(Range range) : Range(range), partial{ Op::initial(range) } {};

	T query(Range range, Change change) {
		return query_(range, change).first;
	}

	void add(Change change) {
		pending = Op::push(pending, change);
	}

	void prepare() {
		if (!singleton()) {
			if (left_child == NULL) left_child = (new IntervalTree(leftHalf()));
			if (right_child == NULL) right_child = (new IntervalTree(rightHalf()));
			left_child->add(pending);
			right_child->add(pending);
		}
		partial = Op::apply(*this, partial, pending);
		pending = Op::identity();
	}

	pair<T, T> query_(Range range, Change change) {
		

		prepare();
		if (inside(range)) {
			add(change);
			prepare();
			return { partial, Op::zero() };
		}
		if (!intersect(range)) {
			

			return { Op::zero(), partial };
		}

		auto from_left = left_child->query_(range, change);
		auto from_right = right_child->query_(range, change);
		

		auto needed = Op::reduce(from_left.first, from_right.first), rest = Op::reduce(from_left.second, from_right.second);
		partial = Op::reduce(needed, rest);
		return { needed, rest };
	}

	T build_from(const function<T(ll)>& getter) {
		prepare();
		pending = Op::identity();
		if (singleton()) partial = getter(this->l);
		else partial = Op::reduce(left_child->build_from(getter), right_child->build_from(getter));
		return partial;
	}

};


template<typename Op>
class SegmentTree {
public:
	const pair<ll, ll> range;
private:
	vector<typename Op::T> t;
	vector<typename Op::Change> d;
	ll n;
	ll h;

	void __calc(ll p, ll k) {
		t[p] = Op::apply(k, Op::reduce(t[p * 2], t[p * 2 + 1]), d[p]);
	}

	void __apply(ll p, typename Op::Change value, ll k) {
		t[p] = Op::apply(k, t[p], value);
		if (p < n) d[p] = Op::push(d[p], value);
	}

	void __build(ll l, ll r) {
		ll k = 2;
		l += n;
		r += n - 1;
		for (; l > 1; k *= 2) {
			l /= 2;
			r /= 2;
			for (ll i = r; i >= l; i--) __calc(i, k);
		}
	}

	void __push(ll l, ll r) {
		ll s = h;
		ll k = 1 << (h - 1);

		l += n;
		r += n - 1;
		for (; s > 0; s--, k /= 2) {
			for (ll i = l >> s; i <= r >> s; i++) {
				__apply(i * 2, d[i], k);
				__apply(i * 2 + 1, d[i], k);
				d[i] = Op::identity();
			}
		}
	}

	void __modify(ll l, ll r, typename Op::Change value) {
		__push(l, l + 1);
		__push(r - 1, r);
		ll l0 = l, r0 = r, k = 1;

		l += n;
		r += n;
		for (; l < r; l /= 2, r /= 2, k *= 2) {
			if (l & 1) __apply(l++, value, l);
			if (r & 1) __apply(--r, value, k);
		}
		__build(l0, l0 + 1);
		__build(r0 - 1, r0);
	}

	typename Op::T __query(ll l, ll r) {
		__push(l, l + 1);
		__push(r - 1, r);
		typename Op::T resl = Op::zero(), resr = Op::zero();

		l += n;
		r += n;

		for (; l < r; l /= 2, r /= 2) {
			if (l & 1)  resl = Op::reduce(resl, t[l++]);
			if (r & 1) resr = Op::reduce(t[--r], resr);
		}
		return Op::reduce(resl, resr);

	}

public:

	SegmentTree(pair<ll, ll> range, const function<typename Op::T(ll)>& getter) : range{ range } {
		n = range.second - range.first + 1;
		t.resize(n * 2);
		d.resize(n, Op::identity());
		for (ll i = 0; i < n; i++) {
			t[i + n] = getter(i);
		}
		for (ll i = n - 1; i > 0; i--) t[i] = t[i * 2] + t[i * 2 + 1];
		h = 0;
		ll new_n = n;
		while (new_n > 0) {
			h++;
			new_n /= 2;
		}

	}

	typename Op::T query(pair<ll, ll> query_range) {
		return __query(query_range.first - range.first, query_range.second - range.first + 1);
	}
	void modify(pair<ll, ll> modify_range, typename Op::Change value) {
		__modify(modify_range.first - range.first, modify_range.second - range.first + 1, value);
	}

};


template<typename T_, typename Range_>
struct Add_Sum {
	using Range = Range_;
	using T = T_;
	using Change = T_;

	static Change identity() {
		return 0;
	}

	static T zero() {
		return 0;
	}

	static T initial(Range r) {
		return zero();
	}

	static T reduce(T a, T b) {
		return a + b;
	}

	static T apply(Range r, T a, Change c) {
		return a + r.span()*c;
	}

	static Change push(Change a, Change b) {
		return a + b;
	}
};

template<typename T_, typename Range_>
struct Multiply_Sum {
	using Range = Range_;
	using T = T_;
	using Change = T_;

	static Change identity() {
		return 1;
	}

	static T zero() {
		return 0;
	}

	static T initial(Range r) {
		return r.span() * 1;
	}

	static T reduce(T a, T b) {
		return a + b;
	}

	static T apply(Range r, T a, Change c) {
		return a * c;
	}

	static Change push(Change a, Change b) {
		return a * b;
	}
};



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
T id6(T a, T b){return std::id6(a,b);}

}



ll n,m;
vector<tuple<ll,ll,ll> > hor;
vector<ll> ver;



MAIN main(){
    cin>>n>>m;
    ver = mytl::readValues<ll>(n);
    hor = mytl::readValues<tuple<ll,ll,ll>, ll,ll,ll >(m);
    map<ll,ll> id0;
    sort(begin(hor), end(hor));

    for(auto [l,r,height] : hor){
        if(id0[height] + 1 == l) id0[height] = r;
    }

    vector<ll> id3;
    ll adka = 0;
    for(auto elem : id0){
        if(elem.second == 1000000000LL){
            adka++;
            continue;
        }
        if(elem.second != 0) id3.push_back(elem.second);
    }

    sort(id3.begin(), id3.end());
    sort(ver.begin(), ver.end());

    ll ans = ver.size();

    ll id8 = -1;
   

    for(ll id4 = -1; id4+1 < ver.size(); id4++){
        
        while(id8+1 < id3.size() && id3[id8+1] < ver[id4+1]) id8++;
        


        ans = min(ans, (ll)(id3.size()-id8-1+id4+1));
    }

    cout<<ans+adka<<endl;
    
}