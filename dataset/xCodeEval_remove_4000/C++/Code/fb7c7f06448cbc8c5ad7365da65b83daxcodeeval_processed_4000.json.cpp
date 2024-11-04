
using namespace std;











const int mod1 = 1000000007;
const int mod2 = 998244353;



typedef string str;




























template<class T> class id3 {
public: using iterator = typename T::reverse_iterator; iterator begin() { return begin_; } iterator end() { return end_; } id3(const iterator& begin, const iterator& end) : begin_(begin), end_(end) {}
private: iterator begin_; iterator end_;};
template<class T> id3<T> reversed(T& obj) {return id3<T>(obj.rbegin(), obj.rend());}







template<typename T> inline void init(vec<T>& v, deque<int> sizes) {assert(sizes.size() == 1);v = vec<T> (sizes[0]);}
template<typename T, typename C> inline void init(vec<T>& v, deque<int> sizes, C content) {assert(sizes.size() == 1);v = vec<T> (sizes[0], content);}
template<typename T> inline void init(vec<vec<T>>& v, deque<int> sizes) {v = vec<vec<T>> (sizes[0]); sizes.pop_front();if(sizes.size() == 0) return;for(auto& subv : v) init(subv, sizes);}
template<typename T, typename C> inline void init(vec<vec<T>>& v, deque<int> sizes, C content) {v = vec<vec<T>> (sizes[0]); sizes.pop_front();if(sizes.size() == 0) return;for(auto& subv : v) init(subv, sizes, content);}


void _read(str& t){cin>>t;} 

template<typename T>void _read(T&t){cin>>t;}
template<typename T1,typename T2>void _read(pair<T1,T2>&p);
template<typename T1>void _read(tuple<T1>&t);
template<typename T1,typename T2>void _read(tuple<T1,T2>&t);
template<typename T1,typename T2,typename T3>void _read(tuple<T1,T2,T3>&t);
template<typename T1,typename T2,typename T3,typename T4>void _read(tuple<T1,T2,T3,T4>&t);
template<typename T1,typename T2,typename T3,typename T4,typename T5>void _read(tuple<T1,T2,T3,T4,T5>&t);
template<template<typename>class C,typename T>void _read(C<T>&v);
template<typename T1,typename T2>void _read(pair<T1,T2>&p){_read(p.first);_read(p.second);}
template<typename T1>void _read(tuple<T1>&t){_read(fir(t));}
template<typename T1,typename T2>void _read(tuple<T1,T2>&t){_read(fir(t));_read(sec(t));}
template<typename T1,typename T2,typename T3>void _read(tuple<T1,T2,T3>&t){_read(fir(t));_read(sec(t));_read(thi(t));}
template<typename T1,typename T2,typename T3,typename T4>void _read(tuple<T1,T2,T3,T4>&t){_read(fir(t));_read(sec(t));_read(thi(t));_read(fou(t));}
template<typename T1,typename T2,typename T3,typename T4,typename T5>void _read(tuple<T1,T2,T3,T4,T5>&t){_read(fir(t));_read(sec(t));_read(thi(t));_read(fou(t));_read(fif(t));};
template<template<typename>class C,typename T>void _read(C<T>&v){for(auto&e:v)_read(e);}
void _masterread(){}
template<typename T,typename... V>void _masterread(T& t, V&... v){_read(t);_masterread(v...);}



stringstream _effout;






void _print(str&t){_stdout<<t;}

template<typename T>void _print(T t){_stdout<<t;}
template<typename T1,typename T2>void _print(pair<T1,T2>&p);
template<typename T1>void _print(tuple<T1>&t);
template<typename T1,typename T2>void _print(tuple<T1,T2>&t);
template<typename T1,typename T2,typename T3>void _print(tuple<T1,T2,T3>&t);
template<typename T1,typename T2,typename T3,typename T4>void _print(tuple<T1,T2,T3,T4>&t);
template<typename T1,typename T2,typename T3,typename T4,typename T5>void _print(tuple<T1,T2,T3,T4,T5>&t);
template<template<typename>class C,typename T>void _print(C<T>&v);
template<template<typename,typename>class C,typename T1,typename T2>void _print(C<T1,T2>&v);
template<typename A>void _print(queue<A>&q);
template<typename A>void _print(priority_queue<A>&pq);
template<typename T1,typename T2>void _print(pair<T1,T2>&p){_print(p.first);_stdout<<" ";_print(p.second);}
template<typename T1>void _print(tuple<T1>&t){_print(fir(t));}
template<typename T1,typename T2>void _print(tuple<T1,T2>&t){_print(fir(t));_stdout<<" ";_print(sec(t));}
template<typename T1,typename T2,typename T3>void _print(tuple<T1,T2,T3>&t){_print(fir(t));_stdout<<" ";_print(sec(t));_stdout<<" ";_print(thi(t));}
template<typename T1,typename T2,typename T3,typename T4>void _print(tuple<T1,T2,T3,T4>&t){_print(fir(t));_stdout<<" ";_print(sec(t));_stdout<<" ";_print(thi(t));_stdout<<" ";_print(fou(t));}
template<typename T1,typename T2,typename T3,typename T4,typename T5>void _print(tuple<T1,T2,T3,T4,T5>&t){_print(fir(t));_stdout<<" ";_print(sec(t));_stdout<<" ";_print(thi(t));_stdout<<" ";_print(fou(t));_stdout<<" ";_print(fif(t));};
template<template<typename>class C,typename T>void _print(C<T>&v){bool f=1;for(auto&e:v)_stdout<<(f?"":" "),f=0,_print(e);}
template<template<typename,typename>class C,typename T1,typename T2>void _print(C<T1,T2>&v){bool f=1;for(auto&e:v)_stdout<<(f?"":" "),f=0,_print(e);}
template<typename A> void _print(queue<A>&q){queue<A>cp=q; vec<A>v;while(!cp.empty()) v.pb(cp.front()), cp.pop();_print(v);}
template<typename A> void _print(priority_queue<A>&pq){priority_queue<A>cp=pq; vec<A>v;while(!cp.empty()) v.pb(cp.top()), cp.pop();_print(v);}
void _masterprint(){}
template<typename T,typename... V>void _masterprint(T t, V... v){_print(t);if(sizeof...(v))_stdout<<" ";_masterprint(v...);}




void _debug(str&t){cerr<<t;} 

template <typename T> void _debug(T t){cerr<<t;}
template<typename T1,typename T2> void _debug(bool b);
template<typename T1,typename T2> void _debug(pair<T1,T2>p);
template<typename T1>void _debug(tuple<T1>&t);
template<typename T1,typename T2>void _debug(tuple<T1,T2>&t);
template<typename T1,typename T2,typename T3>void _debug(tuple<T1,T2,T3>&t);
template<typename T1,typename T2,typename T3,typename T4>void _debug(tuple<T1,T2,T3,T4>&t);
template<typename T1,typename T2,typename T3,typename T4,typename T5>void _debug(tuple<T1,T2,T3,T4,T5>&t);
template<template<typename>class C,typename T>void _debug(C<T>v);
template<template<typename,typename>class C,typename T1,typename T2>void _debug(C<T1,T2>v);
template<typename A>void _debug(queue<A>&q);
template<typename A>void _debug(priority_queue<A>&pq);
template<typename T1,typename T2> void _debug(bool b){cerr<<(b?"1":"0");}
template<typename T1,typename T2> void _debug(pair<T1,T2> p){cerr<<"pr{";_debug(p.first);cerr<<", ";_debug(p.second);cerr<<"}";}
template<typename T1>void _debug(tuple<T1>&t){cerr<<"tp{";_debug(fir(t));cerr<<"}";}
template<typename T1,typename T2>void _debug(tuple<T1,T2>&t){cerr<<"tp{";_debug(fir(t));_stdout<<", ";_debug(sec(t));cerr<<"}";}
template<typename T1,typename T2,typename T3>void _debug(tuple<T1,T2,T3>&t){cerr<<"tp{";_debug(fir(t));_stdout<<", ";_debug(sec(t));_stdout<<", ";_debug(thi(t));cerr<<"}";}
template<typename T1,typename T2,typename T3,typename T4>void _debug(tuple<T1,T2,T3,T4>&t){cerr<<"tp{";_debug(fir(t));_stdout<<", ";_debug(sec(t));_stdout<<", ";_debug(thi(t));_stdout<<", ";_debug(fou(t));cerr<<"}";}
template<typename T1,typename T2,typename T3,typename T4,typename T5>void _debug(tuple<T1,T2,T3,T4,T5>&t){cerr<<"tp{";_debug(fir(t));_stdout<<", ";_debug(sec(t));_stdout<<", ";_debug(thi(t));_stdout<<", ";_debug(fou(t));_stdout<<", ";_debug(fif(t));cerr<<"}";};
template<template<typename>class C,typename T>void _debug(C<T>v){bool f=1;cerr<<"(";for(auto e:v)cerr<<(f?"":", "),f=0,_debug(e);cerr << ")";}
template<template<typename,typename>class C,typename T1,typename T2>void _debug(C<T1,T2>v){bool f=1;cerr<<"(";for(auto e:v)cerr<<(f?"":", "),f=0,_debug(e);cerr << ")";}
template<typename A> void _debug(queue<A>&q){queue<A>cp=q; vec<A>v;while(!cp.empty()) v.pb(cp.front()), cp.pop();cerr<<"q";_debug(v);}
template<typename A> void _debug(priority_queue<A>&pq){priority_queue<A>cp=pq; vec<A>v;while(!cp.empty()) v.pb(cp.top()), cp.pop();cerr<<"pq";_debug(v);}
void _masterdebug(){cerr<<"]"<<endl;}
template<typename T,typename... V> void _masterdebug(T t,V... v){_debug(t);if(sizeof...(v))cerr<<", ";_masterdebug(v...);}


template<typename T> void _debugall(T c, string n){_debug("debugall: ");_debug(n);cerr<<endl;for(auto&_e:c){_debug("  ");_debug(_e);cerr<<endl;}} 








void prep();
void testcase(signed tc);
signed tests = 1;
signed main(){
    if(!_interactive_) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    pr(setprecision(10));
    pr(fixed);
    prep();
    if(_automulttst_) re(tests);
    foab(tc,(int)1,tests+(int)1) testcase((signed)tc);

    cout<<_effout.str();

}
void prep(){
}




template<class Int>
struct BIT { 

    

        

        

    int n;
    vector<Int> arr, values;
    Int q(int idx){
        idx++; Int s = 0;
        while(idx>0) s+=arr[idx], idx-=(idx&(-idx));
        return s;
    }
    Int q(int a, int b){
        if(a == b) return values[a];
        return q(b)-q(a-1);
    }
    void add(int idx, Int val){
        values[idx]+=val;
        idx++;
        while(idx<n) arr[idx]+=val, idx+=(idx&(-idx));
    }
    void set(int idx, Int val){
        add(idx, val - values[idx]);
    }
    void rangeadd(int a, int b, Int val){
        add(a, val);
        if(b < n - 2) add(b + 1, -val);
    }
    BIT(){}
    void setup(int _n){
        n=_n+1, arr=vector<Int>(n), values=vector<Int> (_n);
    }
    BIT(int _n){
        setup(_n);
    }
    void setupsingle(vector<Int> initial){
        for(int i = 0; i < n - 1; i++) add(i,initial[i]);
    }
    void setuprange(vector<Int> initial){
        for(int i = 0; i < n - 1; i++) rangeadd(i,i,initial[i]);
    }
};


void testcase(__attribute__((unused)) signed tc){
    int n; re(n);
    vec<str> a (3); re(a);
    vec<vec<bool>> done; init(done, {3, n});
    vec<pi> dirs = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1},
    };
    vec<bool> lefttop (n), leftbot (n);;
    vec<bool> righttop (n), rightbot (n);;
    vi id2 (n), id1 (n), id0 (n);
    id2[0] = a[1][0] == '0';
    foab(i, 1, n) {
        id2[i] = id2[i-1] + (a[1][i] == '0');
    }
    id1[0] = a[0][0] == '1';
    foab(i, 1, n) {
        id1[i] = id1[i-1] + (a[0][i] == '1');
    }
    id0[0] = a[2][0] == '1';
    foab(i, 1, n) {
        id0[i] = id0[i-1] + (a[2][i] == '1');
    }
    nof(i, n) {
        if(
            (i == n - 1 || a[0][i+1] == '0') &&
            (a[1][i] == '0')
          ) {
            lefttop[i] = true;
        } else if(i < n - 1 && a[1][i] == '0' && lefttop[i+1]) {
            lefttop[i] = true;
        }
    }
    nof(i, n) {
        if(
            (i == n - 1 || a[2][i+1] == '0') &&
            (a[1][i] == '0')
          ) {
            leftbot[i] = true;
        } else if(i < n - 1 && a[1][i] == '0' && leftbot[i+1]) {
            leftbot[i] = true;
        }
    }
    fon(i, n) {
        if(
            (i == 0 || a[0][i-1] == '0') &&
            (a[1][i] == '0')
          ) {
            righttop[i] = true;
        } else if(i > 0 && a[1][i] == '0' && righttop[i-1]) {
            righttop[i] = true;
        }
    }
    fon(i, n) {
        if(
            (i == 0 || a[2][i-1] == '0') &&
            (a[1][i] == '0')
          ) {
            rightbot[i] = true;
        } else if(i > 0 && a[1][i] == '0' && rightbot[i-1]) {
            rightbot[i] = true;
        }
    }
    BIT<int> start (n), end (n);
    int total = 0;
    vec<vi> comp; init(comp, {3, n});
    fon(i, 3) fon(j, n) {
        if(done[i][j]) continue;
        if(a[i][j] == '0') continue;
        queue<pi> q;
        q.push({i,j});
        vec<pi> seen;
        while(!q.empty()) {
            auto pos = q.front(); q.pop();
            if(done[pos.fi][pos.se]) continue;
            done[pos.fi][pos.se] = true;
            seen.pb(pos);
            foe(dir, dirs) {
                pi npos = {
                    pos.fi + dir.fi,
                    pos.se + dir.se,
                };
                if(
                    0 <= npos.fi && npos.fi < 3 && 0 <= npos.se && npos.se < n &&
                    a[npos.fi][npos.se] == '1'
                ) {
                    q.push(npos);
                }
            }
        }
        int mn = n - 1;
        int mx = 0;
        foe(e, seen) {
            mn = min(mn, e.se);
            mx = max(mx, e.se);
        }
        start.add(mn, 1);
        end.add(mx, 1);
        total++;
        foe(e, seen) {
            comp[e.fi][e.se] = total;
        }
    }
    debugall(comp);
    debug(lefttop);
    debug(leftbot);
    debug(righttop);
    debug(rightbot);
    int q; re(q);
    rep(q) {
        int l,r; re(l,r); l--,r--;
        if(l == r) {
            if(a[1][l] == '1') {
                prl(1);
            } else {
                int ans = a[0][l] == '1';
                ans += a[2][l] == '1';
                prl(ans);
            }
            continue;
        }
        int ans = total;
        ans -= end.q(0,l-1);
        ans -= start.q(r + 1, n - 1);
        int o0 = id1[r] - (l == 0 ? 0 : id1[l - 1]);;
        int z1 = id2[r] - (l == 0 ? 0 : id2[l - 1]);;
        int o2 = id0[r] - (l == 0 ? 0 : id0[l - 1]);;
        int len  = r - l + 1;
        if(o0 == len && o2 == len) {
            if(z1 == len) {
                ans = 2;
            } else {
                ans = 1;
            }
        } else if(o0 == len) {
            if(comp[0][l] && comp[2][l] && comp[0][l] == comp[2][l] && leftbot[l]) {
                ans++;
            }
            if(comp[0][r] && comp[2][r] && comp[0][r] == comp[2][r] && rightbot[r]) {
                ans++;
            }
        } else if(o2 == len) {
            if(comp[0][l] && comp[2][l] && comp[0][l] == comp[2][l] && lefttop[l]) {
                ans++;
            }
            if(comp[0][r] && comp[2][r] && comp[0][r] == comp[2][r] && righttop[r]) {
                ans++;
            }
        } else {
            if(comp[0][l] && comp[2][l] && comp[0][l] == comp[2][l] && (lefttop[l] || leftbot[l])) {
                ans++;
            }
            if(comp[0][r] && comp[2][r] && comp[0][r] == comp[2][r] && (righttop[r] || rightbot[r])) {
                ans++;
            }
        }
        prl(ans);
    }
}
