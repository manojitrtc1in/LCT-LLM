using ll = long long;

ll tabnums = 0;






using namespace std;

using u_counter_type = unsigned int;
using counter_type = int;
using MAIN = int;

using ll = long long;

template<typename T>
using PairOf = pair<T,T>;

using Void = tuple<>;
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
template<typename T, T(*f)(T,T)>
struct Tracker : optional<T>{
    using optional<T>::operator=;

    Tracker() : optional<T>() {};

    void update(T val){
        if(this->has_value()){
            *this = f(this->value(), val);
        }
        else{
            *this = val;
        }
    }
};

template<typename T>
T min(T a, T b){return std::min(a,b);};
template<typename T>
T max(T a, T b){return std::max(a,b);};
template<typename T>
T id5(T a, T b){return std::id5(a,b);};

template<typename T, template<typename> typename Container>
vector<PairOf<T&> > id3(Container<T>& c){
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

template<typename T>
struct LazyVector : vector<T>{
    T& operator[](counter_type i){
        if(i >= this->size()) this->resize(i+1);
        return vector<T>::operator[](i);
    }
};

template<typename K, typename T>
using AssocVector = LazyVector<T>;

template<typename T>
istream& operator>>(istream& os, optional<T>& x){
    if(x.has_value()) return os;
    else{
        T val;
        os>>val;
        x = val;
        return os;
    }
}

istream& operator>>(istream& os, Void x){
    return os;
}

template<typename T>
struct Lazy : optional<T>{

    function<T()> f;

    Lazy(function<T()> f) : f{f}, optional<T>() {};

    T value(){
        if(!this->has_value()){
            optional<T>::operator=(f());
        }
        return optional<T>::value();
    }

};



}
namespace mytl{

template<typename N, typename E, template<typename, typename> typename Container>
struct id1 : Container<N, vector<pair<E, N> > >{
    using Edge = E;
    using Node = N;
    optional<ll> n;
    id1(ll n={}) : n{n}, Container<Node, vector<pair<Edge, Node> > >() {}

    void newEdge(ll u, ll v, Edge edge=Void()){
        (*this)[u].push_back(make_pair(edge, v));
    }
    vector<Node> getNodes(){
        vector<Node> res;
        if(n.has_value()){
            for(ll i=1; i<=n.value(); i++) res.push_back(i);
        }
        else{
            for(auto& p : *this){
                res.push_back(p.first);
            }
        }
        return res;

    }
    vector<pair<Edge, Node> >& getEdges(Node node){
        return (*this)[node];
    }
    vector<Node > getNeighbours(Node node){
        vector<Node> res;
        for(auto& par : getEdges(node)){
            res.push_back(par.second);
        }
        return res;
    }

};

using NormalSimpleGraph = id1<ll, Void, AssocVector>;

template<typename T>
void id4(T& g){
    for(ll i=1; i<=g.n.value(); i++){
        ll mi;
        cin>>mi;
        for(ll j=1; j<=mi; j++){
            ll neig;
            cin>>neig;
            g.newEdge(i, neig);
        }
    }
}

template<typename T>
void id0(T& g, optional<ll> m, bool bidirectional=true){
    cin>>m;
    for(ll i=1; i<=m.value(); i++){
        ll u,v;
        typename T::Edge edge;
        cin>>u>>v>>edge;
        g.newEdge(u,v,edge);
        if(bidirectional){
            g.newEdge(v, u, edge);
        }
    }
}


template<typename G, template<typename> typename A, typename Container>
void graph_algorithm(G& g, vector<pair<typename A<G>::Info, typename G::Node> > sources, Container& tav){
    using Algo = A<G>;
    typename Algo::Queue qu;
    for(auto source : sources) qu.push(source);

    while(!qu.empty()){
        auto akt = qu.top();
        qu.pop();
        typename Algo::Node who = akt.second;
        typename Algo::Info info = akt.first;

        if(tav[who].has_value()) continue;

        tav[who] = info;

        for(auto par : g.getEdges(who)) if(!tav[par.second].has_value()){
            qu.push(make_pair(Algo::append({info, who}, par.first, par.second), par.second));
        }
    }
}

template<typename G>
struct BFS{
    using Edge = typename G::Edge;
    using Node = typename G::Edge;
    using Graph = G;

    using Info = ll;
    struct Queue : queue<pair<Info, Node> >{
        pair<Info, Node> top(){
            return this->front();
        }
    };
    static Info append(pair<Info,Node> from, Edge e, Node to){
        return from.first + 1;
    }
};

template<typename G>
struct Dijkstra{
    using Edge = typename G::Edge;
    using Node = typename G::Node;
    using Graph = G;

    using Info = Edge;
    using Queue = priority_queue<pair<Info, Node>, vector<pair<Info, Node> >, greater<pair<Info, Node> > >;

    static Info append(pair<Info,Node> from, Edge e, Node to){
        return from.first + e;
    }

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
namespace mytl{

template <template<typename, typename> typename Q, typename Arg, typename R>
function<R (Arg)> memoize(R (*fn)(Arg)) {
    Q<Arg, optional<R> > table;
    return [fn, table](Arg arg) mutable -> R {
        optional<R>& res = table[arg];
        if(!res.has_value()){
            res = fn(arg);
        }
        return res.value();
    };
}

template<typename Arg, typename R>
using MemoVector = LazyVector<R>;

}


 

using ll = long long;
using Par = pair<ll, ll>;
using ParPar = pair<Par, Par>;

ll M = 1000000007;

Par operator+(Par a, Par b){
    Par res = {(a.first+b.first), a.second + b.second};
    return {res.first%M, res.second%M};
}
Par operator*(Par a, ParPar b){
    Par res = {b.first.first*a.first + b.first.second*a.second, b.second.first*a.first + b.second.second*a.second};
    return {res.first%M, res.second%M};
}
ParPar operator*(ParPar a_, ParPar b_){
    ll a = a_.first.first,
         b = a_.first.second,
         c = a_.second.first,
         d = a_.second.second,
         e = b_.first.first,
         f = b_.first.second,
         g = b_.second.first,
         h = b_.second.second;
    ParPar res = {{e*a+f*c, e*b+f*d}, {g*a + h*c, g*b + h*d}};
    return {{res.first.first%M, res.first.second%M}, {res.second.first%M, res.second.second%M}};
}

struct Custom_Op{
    using Range = mytl::Range1D;
    using T = Par;
    using Change = ParPar;

    static Change identity(){
        return {{1, 0}, {0,1}};
    }
    static T zero(){
        return {0, 0};
    }

    static T initial(Range r){
        Par res = {r.span()%M, r.span()%M};
        return res;
    }

    static T reduce(T a, T b){
        T res = a + b;
        return res;
    }

    static T apply(Range r, T a, Change c){
        T res = a * c;
        return res;
    }

    static Change push(Change a, Change b){
        Change res = a * b;
        return res;
    }
};


ll n,m;

ParPar hatv(ll kitevo){
    ParPar res = Custom_Op::identity();
    ParPar alap = {{0,1}, {1,1}};
    while(kitevo > 0){
        if(kitevo%2 == 1) res = res*alap;
        alap = alap*alap;
        kitevo /= 2;
    }
    return res;
}

MAIN main() {
    

    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    mytl::Node<Custom_Op> node({1,n});
    vector<ll> be(n+1);
    for(ll i=1; i<=n; i++){
        cin>>be[i];
    }
    node.build_from([&be](ll index){return Par{1,1} * hatv(be[index]-1);});
    for(ll i=1; i<=m; i++){
        ll mode;
        cin>>mode;
        if(mode == 1){
            ll l,r,x;
            cin>>l>>r>>x;
            node.query({l,r}, hatv(x));
        }
        else{
            ll l,r;
            cin>>l>>r;
            cout<<node.query({l,r}, Custom_Op::identity()).first<<endl;
        }
    }

}
