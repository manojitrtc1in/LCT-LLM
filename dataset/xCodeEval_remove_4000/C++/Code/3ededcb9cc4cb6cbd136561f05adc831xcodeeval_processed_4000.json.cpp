using ll = long long;

ll tabnums = 0;




using namespace std;

using u_counter_type = unsigned int;
using need_int = int;
using counter_type = int;
using MAIN = int;

using ll = long long;

template<typename T>
using PairOf = pair<T,T>;

using Void = tuple<>;

struct BasicInitialization{
    BasicInitialization(){
        ios_base::sync_with_stdio(false);
    }
};
BasicInitialization id13;
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


template<typename T, template<typename, typename...> typename Container>
vector<PairOf<T&> > id5(Container<T>& c){
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

template<typename T>
T id11(function<bool(T)> f, T l, T r){
    if(!f(l)) return l;
    while(l < r){
        T pivot = (l+r)/2;
        if(!f(pivot)) r = pivot-1;
        else if(!f(pivot+1)) l = r = pivot;
        else l = pivot+1;
    }
    return l;
}

template<typename T>
T id10(function<bool(T)> f, T l, T r, need_int iterations){
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
struct LazyVector : vector<T>{
    typename vector<T>::reference operator[](counter_type i){
        if(i >= this->size()) this->resize(i+1);
        return vector<T>::operator[](i);
    }
};

template<typename K, typename T>
struct AssocVector : LazyVector<T>{
    LazyVector<bool> exists;
    typename vector<T>::reference operator[](counter_type i){
        exists[i] = true;
        return LazyVector<T>::operator[](i);
    }
    typename vector<T>::iterator find(counter_type i){
        if(!exists[i]) return this->end();
        else return this->begin() + i;
    }
};

template<template<typename, typename, typename...> typename Container, typename Key, typename Value>
bool has_key(Container<Key, Value>& container, Key key){
    return container.find(key) != container.end();
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
        ll id4 = (i+1)%poly.size();
        ll dir = poly[i].direction(poly[id4], point);
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

namespace std{

template<typename T>
istream& operator>>(istream& is, optional<T>& x){
    if(!x.has_value()){
        T x_;
        is>>x_;
        x = x_;
    }
    return is;
}

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



template<typename N, typename E, template<typename, typename, typename...> typename C>
struct id3{
    template<typename A, typename B>
    using Container = C<A,B>;
    using Edge = E;
    using Node = N;
    struct Arm{
        Edge edge;
        Node node;
    };

    Container<Node,  vector<Arm> > container;

    optional<ll> n;
    id3(ll n={}) : n{n}, container() {}

    void newEdge(Node u, Node v, Edge edge=Void()){
        container[u].push_back({edge, v});
    }
    vector<Node> getNodes(){
        vector<Node> res;
        if(n.has_value()){
            for(ll i=1; i<=n.value(); i++) res.push_back(i);
        }
        else{
            for(auto& p : container){
                res.push_back(p.first);
            }
        }
        return res;

    }
    vector<Arm >& getEdges(Node node){
        return container[node];
    }
    vector<Node > getNeighbours(Node node){
        vector<Node> res;
        for(auto& arm : getEdges(node)){
            res.push_back(arm.node);
        }
        return res;
    }

};

using NormalSimpleGraph = id3<ll, Void, AssocVector>;

template<typename G>
void id8(G& g, ll indexing=1){
    for(ll i : forrange(g.n.size(), indexing)){
        for(ll neig : readValues<ll>(read<ll>())){
            g.new_edge(i, neig);
        }
    }
}

template<typename G>
void id0(G& g, ll m, bool bidirectional=true){
    using Node = typename G::Node;
    using Edge = typename G::Edge;
    for(auto elem : readValues<tuple<Node, Node, Edge>, Node, Node, Edge >(m)){
        Node u, v;
        Edge edge;
        tie(u, v, edge) = elem;
        g.newEdge(u,v,edge);
        if(bidirectional) g.newEdge(v, u, edge);
    }
}

template<typename G, template<typename> typename Path>
struct Reaching{
    typename Path<G>::Info info;
    typename G::Node node;
    bool operator<(const Reaching& other) const {
        return info > other.info;
    }
};

template<
    typename G,
    template<typename> typename QP,
    template<typename> typename P,
    typename F=void(*)(typename P<G>::Info, typename G::Node)
>
typename G::template Container<typename G::Node, typename P<G>::Info> id6(
    G& g,
    vector<Reaching<G,P> > sources,
    F id7=[](typename P<G>::Info, typename G::Node){})
{

    using Path = P<G>;
    using Edge = typename G::Edge;
    using Node = typename G::Node;
    using Info = typename Path::Info;
    

    using R = Reaching<G,P>;
    using QueuePolicy = QP<R>;
    using Queue = typename QueuePolicy::Queue;

    Queue q;
    for(R source : sources) QueuePolicy::push(q, source);
    typename G::template Container<Node, Info> d;
    while(!q.empty()){
        R akt = QueuePolicy::consume(q);

        if(has_key(d, akt.node)) continue;

        d[akt.node] = akt.info;

        id7(akt.info, akt.node);
        for(auto arm : g.getEdges(akt.node)) if(!has_key(d, arm.node)){
            QueuePolicy::push(q, {Path::append(akt.info, akt.node, arm.edge, arm.node), arm.node});
        }
    }
    return d;
}

template<
        typename G,
        template<typename> typename QP,
        template<typename> typename P,
        typename F=void(*)(typename P<G>::Info, typename G::Node)
>
typename G::template Container<typename G::Node, typename P<G>::Info> id2(
        G& g,
        typename P<G>::Info info,
        typename G::Node node,
        F id7=[](typename P<G>::Info, typename G::Node){})
{
    return id6<G,QP,P,F>(g, {{info,node}},id7);
}



template<typename T>
struct Priority{
    using Queue = priority_queue<T>;
    static T consume(Queue& q){
        auto res = q.top();
        q.pop();
        return res;
    }
    static void push(Queue& q, T new_option){
        q.push(new_option);
    }
};


template<typename T>
struct FIFO{
    using Queue = queue<T>;
    static T consume(Queue& q){
        auto res = q.front();
        q.pop();
        return res;
    }
    static void push(Queue& q, T new_option){
        q.push(new_option);
    }
};

template<typename T>
struct FILO{
    using Queue = stack<T>;
    static T consume(Queue& q){
        auto res = q.top();
        q.pop();
        return res;
    }
    static void push(Queue& q, T new_option){
        q.pop();
    }
};

template<typename G>
struct JustLength{
    using Info = typename G::Edge;
    static Info append(Info old_info, typename G::Node old_node, typename G::Edge e, typename G::Node n){
        return old_info + e;
    }
};

template<typename G>
struct SimpleJustLength{
    using Info = ll;
    static Info append(Info old_info, typename G::Node old_node, typename G::Edge e, typename G::Node n){
        return old_info + 1;
    }
};


template<typename G>
struct LengthAndLastNode{
    using Info = pair<ll, typename G::Node>;
    static Info append(Info old_info, typename G::Node old_node, typename G::Edge e, typename G::Node n){
        return {old_info + e, old_node};
    }
};

template<typename G>
struct SimpleLengthAndLastNode{
    using Info = pair<typename G::Edge, typename G::Node>;
    static Info append(Info old_info, typename G::Node old_node, typename G::Edge e, typename G::Node n){
        return {old_info + 1, old_node};
    }
};

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


template<typename T>
struct Lazy : optional<T>{

    function<T()> f;

    Lazy(function<T()> f) : f{f}, optional<T>() {};

    T& value(){
        if(!this->has_value()){
            optional<T>::operator=(f());
        }
        return optional<T>::value();
    }

};




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
        TSModulo(ll initVal) : val{(MOD + initVal%MOD)%MOD} {};
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

template <template<typename, typename, typename...> typename C, typename Arg, typename R>
function<R (Arg)> memoize(R (*fn)(Arg)) {
    C<Arg, optional<R> > table;
    return [fn, table](Arg arg) mutable -> R {
        optional<R>& res = table[arg];
        if(!res.has_value()){
            res = fn(arg);
        }
        return res.value();
    };
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
        if(singleton()) partial = getter(this->l);
        else partial = Op::reduce(left_child->build_from(getter), right_child->build_from(getter));
        return partial;
    }

};

struct id12{

    ll l, r;

    id12(ll l, ll r): l{l}, r{r} {}

    ll span() const {
        return r-l+1;
    }
    bool singleton() const {
        return span() == 1;
    }
    id12 leftHalf() const {
        return id12(l, (l+r)/2);
    }
    id12 rightHalf() const {
        return id12((l + r)/2 + 1, r);
    }
    bool inside(const id12& other) const {
        return other.l <= l && r <= other.r;
    }
    bool intersect(const id12& other) const {

        return other.inside(*this)
             ||(other.l <= l && l <= other.r)
             ||(other.l <= r && r <= other.r);
    }
};


}

namespace mytl{
template<typename T_>
struct Add_Sum{
    using Range = id12;
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
    using Range = id12;
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
struct Tracker : optional<T>{

    Tracker() : optional<T>() {};

    void update(T val){
        if(this->has_value()){
            optional<T>::operator=(f(this->value(), val));
        }
        else{
            optional<T>::operator=(val);
        }
    }
};

template<typename T>
T min(T a, T b){return std::min(a,b);}
template<typename T>
T max(T a, T b){return std::max(a,b);}
template<typename T>
T id9(T a, T b){return std::id9(a,b);}

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
    using Range = mytl::id12;
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