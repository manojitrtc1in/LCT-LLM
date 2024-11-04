
using namespace std;











const int mod1 = 1000000007;
const int mod2 = 998244353;



typedef string str;




























template<class T> class id0 {
public: using iterator = typename T::reverse_iterator; iterator begin() { return begin_; } iterator end() { return end_; } id0(const iterator& begin, const iterator& end) : begin_(begin), end_(end) {}
private: iterator begin_; iterator end_;};
template<class T> id0<T> reversed(T& obj) {return id0<T>(obj.rbegin(), obj.rend());}






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
void testcase(__attribute__((unused)) signed tc){
    int a,b,c,d; re(a,b,c,d);
    string s; re(s);
    debug(a,b,c,d);
    debug(s);
    int n = sz(s);
    deque<pi> ab, ba, bb;
    auto comp = [&](const pi& p1, const pi& p2) -> bool {
        int l1 = p1.se - p1.fi;
        int l2 = p2.se - p2.fi;
        return l1 < l2;
    };
    auto revcomp = [&](const pi& p1, const pi& p2) -> bool {
        int l1 = p1.se - p1.fi;
        int l2 = p2.se - p2.fi;
        return l1 > l2;
    };
    priority_queue<pi,vec<pi>,decltype(revcomp)> aa (revcomp);
    
    int idx = 0;
    while(idx < n - 1) {
        while(idx < n - 1 && s[idx] == s[idx+1]) {
            idx++;
        }
        if(idx == n - 1) break;
        int start = idx;
        while(idx < n - 1 && s[idx] != s[idx+1]) {
            idx++;
        }
        int end = idx;
        debug(start,end);
        if(s[start] == 'A' && s[end] == 'B') {
            ab.pb({start,end});
        }
        else if(s[start] == 'B' && s[end] == 'A') {
            ba.pb({start,end});
        }
        else if(s[start] == 'A' && s[end] == 'A') {
            aa.push({start,end});
        }
        else if(s[start] == 'B' && s[end] == 'B') {
            bb.pb({start,end});
        } else {
            assert(false);
        }
    }
    fun(int, len, pi& p) {
        return p.se - p.fi + 1;
    };
    sort(all(ab), comp);
    sort(all(ba), revcomp);
    sort(all(bb), comp);

    vec<int> state (n, 0);
    while(c > 0) {
        if(sz(ab) && len(ab[0]) == 2) {
            debug(1);
            debug(ab);
            state[ab[0].fi] = 3;
            state[ab[0].se] = 3;
            ab.pop_front();
            c--;
            continue;
        }
        if(sz(ab)) {
            debug(2);
            debug(ab);
            state[ab[0].fi] = 3;
            state[ab[0].fi + 1] = 3;
            ab[0].fi += 2;
            c--;
            continue;
        }
        if(sz(bb)) {
            debug(3);
            debug(bb);
            state[bb[0].se] = 3;
            state[bb[0].se - 1] = 3;
            bb[0].se -= 2;
            if(bb[0].fi == bb[0].se) bb.pop_front();
            c--;
            continue;
        }
        if(sz(aa)) {
            debug(4);
            auto curr = aa.top(); aa.pop();
            state[curr.fi] = 3;
            state[curr.fi + 1] = 3;
            curr.fi += 2;
            if(curr.fi < curr.se) aa.push(curr);
            c--;
            continue;
        }
        while(sz(ba) && len(ba[0]) <= 2) ba.pop_front();
        if(sz(ba) && len(ba[0]) > 2) {
            debug(5);
            debug(ba);
            state[ba[0].fi + 1] = 3;
            state[ba[0].fi + 2] = 3;
            ba[0].fi += 3;
            auto curr = ba[0];
            ba.pop_front();
            if(curr.fi < curr.se) {
                aa.push(curr);
            }
            c--;
            continue;
        }
        debug(state);
        debug(c);
        prl("NO");
        return;
    }
    assert(c == 0);
    fon(i, n - 1) {
        if(d == 0) break;
        if(s[i] == 'B' && s[i+1] == 'A' && !state[i] && !state[i+1]) {
            state[i] = 4;
            state[i+1] = 4;
            d--;
        }
    }
    fon(i, n) {
        if(!state[i]) {
            if(s[i] == 'A') a--;
            else b--;
        }
    }
    debug(state);
    if(a == 0 && b == 0 && c == 0 && d == 0) {
        prl("YES");
    } else {
        prl("NO");
    }
}
