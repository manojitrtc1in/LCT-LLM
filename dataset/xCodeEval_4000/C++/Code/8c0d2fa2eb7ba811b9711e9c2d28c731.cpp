#include<bits/stdc++.h>
using namespace std;



#define _automulttst_ 1
#define _interactive_ 0
#define int long long
#define mod mod1



const int mod1 = 1000000007;
const int mod2 = 998244353;


#define vec vector
typedef string str;
#define tup tuple
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define pi pair<int,int>
#define vi vec<int>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ll long long
#define fun(ret,x,...) function<ret(__VA_ARGS__)> x;x=[&](__VA_ARGS__)->ret
#define Void(x,...) fun(void,x,__VA_ARGS__)
#define mp make_pair
#define sz(x) ((int)((x).size()))
#define fir(t) get<0>(t)
#define sec(t) get<1>(t)
#define thi(t) get<2>(t)
#define fou(t) get<3>(t)
#define fif(t) get<4>(t)


#define foabc(i,a,b,c) for (int i = (a); i < (b); i+=(c))
#define cbaof(i,a,b,c) for (int i = ((int)(b))-1; i >= (a); i-=(c))
#define foab(i,a,b) for (int i = (a); i < (b); i++)
#define baof(i,a,b) for (int i = ((int)(b))-1; i >= (a); i--)
#define fon(i,n) for(int i = 0; i < n; i++)
#define nof(i,n) for(int i = ((int)(n)) - 1; i >= 0; i--)
#define foe(e,a) for(auto& e : a)
template<class T> class ReversedProxy {
public: using iterator = typename T::reverse_iterator; iterator begin() { return begin_; } iterator end() { return end_; } ReversedProxy(const iterator& begin, const iterator& end) : begin_(begin), end_(end) {}
private: iterator begin_; iterator end_;};
template<class T> ReversedProxy<T> reversed(T& obj) {return ReversedProxy<T>(obj.rbegin(), obj.rend());}
#define eof(e,a) for(auto e : reversed(a)) 

#define rep(n) for(int _ = 0; _ < n; _++)
#define once for(int _=1;_--;) 



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
#define re(...)_masterread(__VA_ARGS__)


stringstream _effout;
#if defined(__local__) || (_interactive_ == 1)
#define _stdout cout
#else
#define _stdout _effout
#define endl '\n'
#endif
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
#define pr(...)_masterprint(__VA_ARGS__)
#define prl(...) (_masterprint(__VA_ARGS__),_stdout<<endl)


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
#ifdef __local__
#define debug(...)(cerr<<"["<<#__VA_ARGS__<<"] = [",_masterdebug(__VA_ARGS__))
template<typename T> void _debugall(T c, string n){_debug("debugall: ");_debug(n);cerr<<endl;for(auto&_e:c){_debug("  ");_debug(_e);cerr<<endl;}} 

#define debugall(c)(_debugall(c,#c))
#else
#define debug(...)
#define debugall(c)
#endif


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
#ifndef __local__
    cout<<_effout.str();
#endif
}
void prep(){
}
void testcase(__attribute__((unused)) signed tc){
    int mx = 2e9 + 10000;
    int add = mx / 2;
    int n, m; re(n,m);
    vec<pi> a (n); re(a);
    vec<pair<pi,pi>> intervals (n);
    set<int> tpoints; 
    fon(i, n) {
        tpoints.insert(a[i].fi);
    }
    vi points;
    map<int,int> idx;
    foe(e, tpoints) {
        idx[e] = sz(points);
        points.pb(e);
    }
    int k = sz(points);
    sort(all(points));
    vec<pi> start (k), ends (k);
    vi test (k);
    fun(void, update, int a, int b, pi upt) {
        if(a > b) return;
        int l = lower_bound(all(points), a) - points.begin();
        int r = (upper_bound(all(points), b) - points.begin()) - 1;
        debug(a,b,l,r,upt);
        debug(points);
        if(l > r) return;
        start[l].fi += upt.fi + (points[l] - a) * upt.se;
        start[l].se += upt.se;
        ends[r].fi -= upt.fi + (points[r] - a) * upt.se;
        ends[r].se -= upt.se;
    };
    debug("setup");
    fon(i, n) {
        ll x = a[i].fi;
        ll p = a[i].se;
        update(x-p,x,{0,1});
        update(x+1,x+p,{p-1,-1});
    }
    pi upt = {0,0};
    int pre = -100;
    vi vals (k);
    fon(i, k) {
        upt.fi += (points[i] - pre) * upt.se;
        upt.fi += start[i].fi;
        upt.se += start[i].se;
        debug(upt);
        vals[i] = upt.fi;
        upt.fi += ends[i].fi;
        upt.se += ends[i].se;
        pre = points[i];
    }
    debug(points);
    debug(vals);
    debug(test);
    debug(start);
    debug(ends);
    ll mnl = LLONG_MAX, mxr = LLONG_MIN;
    fon(i, n) {
        ll x = a[i].fi;
        ll v = vals[idx[x]] - m;
        if(v > 0) {
            ll l = x - v;
            ll r = x + v;
            mnl = min(mnl, l);
            mxr = max(mxr, r);
        }
    }
    debug(mnl,mxr);
    debug("queries");
    string res (n, '?');
    fon(i, n) {
        ll x = a[i].fi;
        ll p = a[i].se;
        ll l = x - p;
        ll r = x + p;
        if(l <= mnl && mxr <= r) {
            res[i] = '1';
        } else {
            res[i] = '0';
        }
    }
    prl(res);
}



















