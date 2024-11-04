
using namespace std;
 
using ll = long long;
using db = long double; 

using str = string; 


using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;





tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;



























tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }










const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

    return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id5(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 


tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } 

tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

tcTU> T fstTrue(T lo, T hi, U f) {
    hi ++; assert(lo <= hi); 

    while (lo < hi) { 

        T mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1; 
    } 
    return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
    lo --; assert(lo <= hi); 

    while (lo < hi) { 

        T mid = lo+(hi-lo+1)/2;
        f(mid) ? lo = mid : hi = mid-1;
    } 
    return lo;
}
tcT> void remDup(vector<T>& v) { 

    sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { 

    auto it = t.find(u); assert(it != end(t));
    t.erase(it); } 




inline namespace Helpers {
    

    

    

    tcT, class = void> struct is_iterable : false_type {};
    tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
                                      decltype(end(declval<T>()))
                                     >
                           > : true_type {};
    tcT> constexpr bool id8 = is_iterable<T>::value;

    

    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool id0 = is_readable<T>::value;

    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool id2 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id7 = !id0<T> && id8<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id7<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<id7<T>,void>::type re(T& i) {
        each(x,i) re(x); }
    tcTUU> void re(T& t, U&... u) { re(t); re(u...); } 


    

    void rv(size_t) {}
    tcTUU> void rv(size_t N, V<T>& t, U&... u);
    template<class...U> void rv(size_t, size_t N2, U&... u);
    tcTUU> void rv(size_t N, V<T>& t, U&... u) {
        t.rsz(N); re(t);
        rv(N,u...); }
    template<class...U> void rv(size_t, size_t N2, U&... u) {
        rv(N2,u...); }

    

    void decrement() {} 

    tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
    
    
}

inline namespace ToString {
    tcT> constexpr bool id3 = !id2<T> && id8<T>;

    

    tcT> typename enable_if<id2<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id4(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id3<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<id8<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id3<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id3<T>,vs>::type 
      id6(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id3<T>,vs>::type 
      id6(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = id6<lev-1>(t);
            res.ins(end(res),all(tmp));
        }
        id4(i,sz(res)) {
            str bef = " "; if (i == 0) bef = "{";
            res[i] = bef+res[i];
        }
        res.bk += "}";
        return res;
    }
}

inline namespace Output {
    template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
    template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
        pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
    

    template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
    

    void ps() { cout << "\n"; }
    template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
    

    template<class ...T> void dbg_out(const T&... t) {
        pr_sep(cerr," | ",t...); cerr << endl; }
    void loc_info(int line, str names) {
        cerr << "Line(" << line << ") -> [" << names << "]: "; }
    template<int lev, class T> void id10(const T& t) {
        cerr << "\n\n" << ts_sep(id6<lev>(t),"\n") << "\n" << endl; }
    
        
        
    

        
        
    

    const clock_t beg = clock();
    
}

inline namespace FileIO {
    void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
    void setOut(str s) { freopen(s.c_str(),"w",stdout); }
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0); 

        

        

        

        if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

    }
}



typedef struct snode* sn;
struct snode { 

    sn p, c[2]; 

    sn extra; 

    bool flip = 0; 

    int val, sz; 

    int sub, vsub = 0; 


    int max_val = 0;
    int lazy_add = 0;
    int label = -1;
    int lazy_label = 0;
    int id = 0;

    snode(int _label, int _val, int _id) {
        label = _label;
        max_val = val = _val;
        id = _id;
        p = c[0] = c[1] = extra = NULL; calc(); }
    friend int getSz(sn x) { return x?x->sz:0; }
    friend int getSub(sn x) { return x?x->sub:0; }
    friend int getLabel(sn x){return x?x->label:0; }
    friend int getMax(sn x){return x?x->max_val:-MOD; }
    friend int getVal(sn x){return x?x->val:-MOD; }
    void prop() { 

        if(flip){
            swap(c[0],c[1]); flip = 0;
            id4(i,2) if (c[i]){
                c[i]->flip ^= 1;
            }
        }

        if(lazy_add != 0){
            max_val+=lazy_add;
            val+=lazy_add;
            id4(i,2) if (c[i]){
                c[i]->lazy_add+=lazy_add;
            }
            lazy_add = 0;
        }

        if(lazy_label != 0){
            

            label = lazy_label;
            id4(i,2) if (c[i]){
                c[i]->lazy_label = lazy_label;
            }
            lazy_label = 0;
        }
        
    }
    void calc() { 

        id4(i,2) if (c[i]) c[i]->prop();

        sz = 1+getSz(c[0])+getSz(c[1]);
        sub = 1+getSub(c[0])+getSub(c[1])+vsub;
        max_val = max(val, max(getMax(c[0]), getMax(c[1])));
        if(lazy_label != 0){
            label = lazy_label;
        }
        

    }
    

    int dir() {
        if (!p) return -2;
        id4(i,2) if (p->c[i] == this) return i;
        return -1; 

    } 

    

    bool isRoot() { return dir() < 0; } 
    friend void setLink(sn x, sn y, int d) {
        if (y) y->p = x;
        if (d >= 0) x->c[d] = y; }
    void rot() { 

        assert(!isRoot()); int x = dir(); sn pa = p;
        setLink(pa->p, this, pa->dir());
        setLink(pa, c[x^1], x); setLink(this, pa, x^1);
        pa->calc();
    }
    void splay() {
        while (!isRoot() && !p->isRoot()) {
            p->p->prop(), p->prop(), prop();
            dir() == p->dir() ? p->rot() : rot();
            rot();
        }
        if (!isRoot()) p->prop(), prop(), rot();
        prop(); calc();
    }
    sn fbo(int b) { 

        prop(); int z = getSz(c[0]); 

        if (b == z) { splay(); return this; }
        return b < z ? c[0]->fbo(b) : c[1] -> fbo(b-z-1);
    }
    

    void access() { 

        for (sn v = this, pre = NULL; v; v = v->p) {
            v->splay(); 

            if (pre) v->vsub -= pre->sub;
            if (v->c[1]) v->vsub += v->c[1]->sub;
            v->c[1] = pre; v->calc(); pre = v;
        }
        splay(); assert(!c[1]); 

    }
    void makeRoot() { 
        access(); flip ^= 1; access(); assert(!c[0] && !c[1]); }
    

    friend sn lca(sn x, sn y) {
        if (x == y) return x;
        x->access(), y->access(); if (!x->p) return NULL;
        x->splay(); return x->p?:x; 

    } 

    friend bool connected(sn x, sn y) { return lca(x,y); } 
    

    int distRoot() { access(); return getSz(c[0]); } 
    sn getRoot() { 

        access(); sn a = this; 
        while (a->c[0]) a = a->c[0], a->prop();
        a->access(); return a;
    }
    sn getPar(int b) { 

        access(); b = getSz(c[0])-b; assert(b >= 0);
        return fbo(b);
    } 

    

    void set(int v) { access(); val = v; calc(); } 
    friend void link(sn x, sn y, bool force = 0) { 
        assert(!connected(x,y)); 
        if (force) y->makeRoot(); 

        else { y->access(); assert(!y->c[0]); }
        x->access(); setLink(y,x,0); y->calc();
    }
    friend void cut(sn y) { 

        y->access(); assert(y->c[0]);
        y->c[0]->p = NULL; y->c[0] = NULL; y->calc(); }
    friend void cut(sn x, sn y) { 

        x->makeRoot(); y->access(); 
        assert(y->c[0] == x && !x->c[0] && !x->c[1]); cut(y); }
};




void id9(sn a, sn b) { 

    if (connected(a,b)) a->extra = b;
    else link(b,a); }
void id11(sn a) { 

    auto t = a->getRoot();
    if (t == a) { t->extra = NULL; return; }
    cut(a); assert(t->extra);
    if (!connected(t,t->extra)) 
        link(t->extra,t), t->extra = NULL; 
}
sn getPar(sn a, int b) { 

    int d = a->distRoot(); if (b <= d) return a->getPar(b);
    b -= d+1; auto r = a->getRoot()->extra; assert(r);
    d = r->distRoot()+1; return r->getPar(b%d);
}


const int mx = 750005;

struct Eff{

int N, M;
int U[mx];
int V[mx];
sn LCT[mx];

void solve(){
    cin >> N >> M;

    

    for(int i = 1; i <= M; i++){
        cin >> U[i] >> V[i];
    }

    for(int i = 1; i <= N+M; i++){
        if(i <= M){
            LCT[i] = new snode(-1, 0, i); 

        }
        else{
            LCT[i] = new snode(-1, -MOD, i); 

        }
    }


    int cur_R = M;
    ll ans = 0;

    for(int i = M; i >= 1; i--){
        


        

        while(true){
            int next_a = M+U[i];
            int next_b = M+V[i];
            if(!connected(LCT[next_a], LCT[next_b])){
                break;
            }
            LCT[next_a]->makeRoot();
            LCT[next_b]->access();
            
            int id1 = getMax(LCT[next_b]);

            assert(id1 <= 1);
            if(id1 == 1){
                

                

                int a = M+U[cur_R];
                int b = M+V[cur_R];

                if(!connected(LCT[a], LCT[cur_R])){ 

                    LCT[a]->makeRoot();
                    LCT[b]->access();

                    LCT[b]->lazy_label = -1;
                    LCT[b]->lazy_add -= 1;
                    LCT[b]->access();
                }
                else{ 

                    LCT[a]->makeRoot();
                    LCT[b]->access();

                    int label = getLabel(LCT[cur_R]);

                    




                    if(label == -1){
                        cut(LCT[cur_R], LCT[a]);
                        cut(LCT[cur_R], LCT[b]);
                        assert(LCT[cur_R]->max_val == 0);
                    }
                    else{
                        int label_a = M+U[label];
                        int label_b = M+V[label];

                        assert(!connected(LCT[label_a], LCT[label]));
                        LCT[label_a]->makeRoot();
                        LCT[label_b]->access();

                        LCT[label_b]->lazy_label = -1;
                        LCT[label_b]->lazy_add -= 1;
                        LCT[label_b]->access();

                        dbg("CUTTING", cur_R);
                        cut(LCT[cur_R], LCT[a]);
                        cut(LCT[cur_R], LCT[b]);

                        

                        dbg(label);
                        dbg("LABEL LINK BEGIN");
                        link(LCT[label_a], LCT[label], 1);
                        dbg("LABEL LINK BEGIN2");
                        link(LCT[label_b], LCT[label], 1);
                        dbg("LABEL LINK END");
                        

                    }
                }

                

                
                cur_R--;
                

                

            }
            else{
                break;
            }
        }

        



        int a = M+U[i];
        int b = M+V[i];

        if(connected(LCT[a], LCT[b])){
            LCT[a]->makeRoot();
            LCT[b]->access();

            LCT[b]->lazy_label = i;
            dbg("ASSIGN LABEL", b, i);
            LCT[b]->lazy_add += 1;
            LCT[b]->access(); 




            dbg(a, b);

            

            

            

            

            

            

            

            

        }
        else{
            dbg("ACTUALLY ADDING", i);
            dbg("LCT LINK BEGIN");
            link(LCT[a], LCT[i], 1);
            link(LCT[b], LCT[i], 1);
            dbg("LCT LINK END");
        }
        
        


        
        


        dbg(i, cur_R);
        ans+=ll(cur_R-i+1);
    }

    ps(ans);

}

};

int main() {
    setIO();
    Eff e;
    e.solve();

    

}


