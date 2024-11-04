





using namespace std;

using u_counter_type = unsigned int;
using counter_type = int;
using MAIN = int;

using ll = long long;

template<typename T>
using PairOf = pair<T,T>;
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
    template<ll MOD>
    struct TSModulo{
    private:
        ll val;

    public:
        static TSModulo inverse(TSModulo x){

            return power(x, MOD-2);
        };
        TSModulo(ll initVal){
            initVal %= MOD;
            if(val < 0) initVal += MOD;
            val = initVal;
        };
        TSModulo() : TSModulo(0) {}
        TSModulo& operator=(const TSModulo&) = default;

        ll get() const{ 

            return val;
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
namespace mytl{
    template<class Q>
    struct Maybe{
        using T = typename Q::T;
        T *val=nullptr;
        void update(T operand){
            if(val == nullptr){
                val = new T;
                *val = operand;
            }
            else{
                *val = Q::reduce(*val, operand);
            }
        }
        T get(){
            return *val;
        }
        static Maybe<Q> nothing(){
            return Maybe<Q>();
        }
        static Maybe<Q> just(T value){
            Maybe<Q> res;
            res.val = new T(value);
            return res;
        }
    };
}
namespace mytl{
    template <typename R, typename... Args>
    function<R (Args...)> memo(R (*fn)(Args...)) {
        map<tuple<Args...>, R> table;
        return [fn, table](Args... args) mutable -> R {
            auto argt = make_tuple(args...);
            auto memoized = table.find(argt);
            if(memoized == table.end()) {
                auto result = fn(args...);
                table[argt] = result;
                return result;
            } else {
                return memoized->second;
            }
        };
    }

    template <typename R, typename Arg>
    function<R (Arg)> id1(R (*fn)(Arg)) {
        unordered_map<Arg, R> table;
        return [fn, table](Arg arg) mutable -> R {
            auto memoized = table.find(arg);
            if(memoized == table.end()) {
                auto result = fn(arg);
                table[arg] = result;
                return result;
            } else {
                return memoized->second;
            }
        };
    }

    template <typename R, typename Arg>
    function<R (Arg)> id2(R (*fn)(Arg)) {
        vector<pair<bool, R> > table;
        return [fn, table](Arg arg) mutable -> R {
            if(table.size() <= arg) table.resize(arg+1, {false, R()});
            if(!table[arg].first) {
                table[arg] = {true, fn(arg)};
            }
            return table[arg].second;
        };
    }
}
namespace mytl{

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

        bool refresh(){
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

namespace mytl{
template<class Q>
    struct Offline{
        using Query = typename Q::Query;
        using T = typename Q::T;
        typedef pair<Query, function<void(T)> > Tie;
        vector<Tie> queries;
        Offline(){};

        void query(Query question, function<void(T)> callback){
            queries.push_back({question, callback});
        }

        void process(){
            sort(begin(queries), end(queries), [](Tie a, Tie b){return Q::comp(a.first, b.first);});
            for(Tie query : queries){
                query.second(Q::query_function(query.first));
            }
        }
    };
}

namespace mytl{
template<typename T>
struct Tracker : optional<T>{
    using optional<T>::operator=;
    function<T(T,T)> f;

    Tracker(function<T(T,T)> f) : f{f} {};

    void update(T val){
        if(this->has_value()){
            *this = f(this->value(), val);
        }
        else{
            *this = val;
        }
    }
};

template<typename T, typename Container>
vector<PairOf<T&> > id3(Container& c){
    vector<PairOf<T&> > res;
    optional<T*> prev_elem;
    for(auto& elem : c){
        if(prev_elem.has_value()){
            res.push_back({*prev_elem.value(), elem});
        }
        prev_elem = &elem;
    }
    return res;
}

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

typedef vector<Point> Poly;

bool inside(const Poly& poly, const Point& point, bool strict){ 

    ll prevdir = -2;
    for(ll i=0; i<poly.size(); i++){
        ll id5 = (i+1)%poly.size();
        ll dir = poly[i].direction(poly[id5], point);
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
namespace mytl{
template<class Op>
struct Node : Op::Range{
    using Range = typename Op::Range;
    using T = typename Op::T;
    using Change = typename Op::Change;
    using Range::singleton;
    using Range::inside;
    using Range::intersect;
    using Range::leftHalf;
    using Range::rightHalf;

    Node *left_child=NULL, *right_child=NULL;

    T partial;
    Change pending = Op::identity();

    Node(Range range) : Range(range), partial{Op::initial(range)} {};

    T query(Range range, Change change){
        return query_(range, change).first;
    }

    void add(Change change){
        pending = Op::push(pending, change);
    }

    void prepare(){
        if(!singleton()){
            if(left_child == NULL) left_child = (new Node(leftHalf()));
            if(right_child == NULL) right_child = (new Node(rightHalf()));
            left_child->add(pending);
            right_child->add(pending);
        }
        partial = Op::apply(*this, partial, pending);
        pending = Op::identity();
    }

    pair<T,T> query_(Range range, Change change){
        

        prepare();
        if(inside(range)){
            add(change);
            prepare();
            return {partial, Op::zero()};
        }
        if(!intersect(range)){
            

            return {Op::zero(), partial};
        }

        auto from_left = left_child->query_(range, change);
        auto from_right = right_child->query_(range, change);
        

        auto needed = Op::reduce(from_left.first, from_right.first), rest = Op::reduce(from_left.second, from_right.second);
        partial = Op::reduce(needed, rest);
        return {needed, rest};
    }

    T build_from(const function<T(ll)>& getter){
        prepare();
        pending = Op::identity();
        if(singleton()) partial = getter(this->first);
        else partial = Op::reduce(left_child->build_from(getter), right_child->build_from(getter));
        return partial;
    }

};

struct Range1D : PairOf<ll>{
    using PairOf<ll>::pair;

    ll span() const {
        return second-first+1;
    }
    bool singleton() const {
        return span() == 1;
    }
    Range1D leftHalf() const {
        return Range1D(first, (first+second)/2);
    }
    Range1D rightHalf() const {
        return Range1D((first + second)/2 + 1, second);
    }
    bool inside(const Range1D& other) const {
        return other.first <= first && second <= other.second;
    }
    bool intersect(const Range1D& other) const {

        return other.inside(*this)
             ||(other.first <= first && first <= other.second)
             ||(other.first <= second && second <= other.second);
    }
};


}

namespace mytl{
template<typename T_>
struct Add_Sum{
    using Range = Range1D;
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
    using Range = Range1D;
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


using namespace mytl;




MAIN main(){
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    map<ll, Resetter<Mod107 >::Variable > id4;

    id4[0] = 1;
    id4[1000000000LL] = 0;

    for(ll i=1; i<=n; i++){
        string szo;
        ll val;
        cin>>szo>>val;
        if(szo == "ADD"){
            id4[val] = 0;
            id4[val] = prev(id4.find(val))->second.get();

            

        }
        else{
            auto id0 = prev(id4.find(val));
            id0->second = id0->second.get() + id4[val].get();
            global_resetter<Mod107>->reset(0);
            id0->second.survive();
            id4.erase(val);

        }
        

        

        

        

    }
    {
    Mod107 res = 0;
    for(auto &par : id4){
        res = res + par.second.get();
    }
    cout<<res.get()<<endl;
    }


}

