#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <random>
#include <complex>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<ld,ld>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define rrep(i,n) for(int i=(n)-1;i>=0;--i)
#define rrep1(i,n) for(int i=(n);i>0;--i)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rpi(i,a,b) for(int i=(a);i>(b);--i)
#define repa(x,y) for(auto &(x):(y))
#define repo(x,y) for(auto &(x):(y))
#define sz(x) ((int)(x).size())
#define vout(x) repa(auto t:x) cout<<t<<" "; cout<<endl;
#define pout(x) cout<<x.fi<<" "<<x.se<<endl;
#define perr(x) cout<<#x<<" = "<<x<<endl;
#define mset(a,val) memset(a,val,sizeof(a))
#define ar array
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define clock_time (clock() * 1000 / CLOCKS_PER_SEC)
#define rand rng
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod=1e9+7;
const ll inf=1e18;
const ld eps=1e-9;
const int mxn=1e5+5;
const int mxm=2e5+5;
const int logn=20;
const int base=1000*1000*1000;
const int N=1e5+5;
const int M=1e5+5;
const int dx[]={1,0,-1,0,1,-1,-1,1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
template<class T> using pq = priority_queue<T>;
template<class T> bool umin(T& a,const T& b) { return b<a?a=b,1:0; }
template<class T> bool umax(T& a,const T& b) { return a<b?a=b,1:0; }
template<class T> T gcd(T a,T b) { return b?gcd(b,a%b):a; }
template<class T> T lcm(T a,T b) { return a/gcd(a,b)*b; }
template<class T> void remdup(vector<T>& v) { sort(all(v)); v.erase(unique(all(v)),end(v)); }
template<class T> ll sum(vector<T>& v) { return accumulate(all(v),0LL); }
template<class T> void prefix_sum(vector<T>& v) { partial_sum(all(v),begin(v)); }
template<class T> void compress(vector<T>& v) { sort(all(v)); v.erase(unique(all(v)),end(v)); }
template<class T> int lwb(vector<T>& v, T val) { return lower_bound(all(v),val)-v.begin(); }
template<class T> int upb(vector<T>& v, T val) { return upper_bound(all(v),val)-v.begin(); }
template<class T> void rem(vector<T>& v, T val) { v.erase(find(all(v),val)); }
template<class T> void read(vector<T>& v,int n) { v.resize(n); rep(i,n) cin>>v[i]; }
template<class T> void read(T& x) { cin>>x; }
template<class T> void read(vector<T>& v) { repa(&x,v) read(x); }
template<class T> void write(vector<T>& v) { repa(x,v) cout<<x<<" "; cout<<endl; }
template<class T> void write(T x) { cout<<x<<endl; }
template<class T> void write(T x,int y) { cout<<x<<" "<<y<<endl; }
template<class T> void write(T x,int y,int z) { cout<<x<<" "<<y<<" "<<z<<endl; }
template<class T> void write(T x,int y,int z,int w) { cout<<x<<" "<<y<<" "<<z<<" "<<w<<endl; }
template<class T> void write(vector<vector<T>>& v) { repa(x,v) { repa(y,x) cout<<y<<" "; cout<<endl; } }
template<class T> void read(T& x,int& y) { cin>>x>>y; }
template<class T> void read(T& x,int& y,int& z) { cin>>x>>y>>z; }
template<class T> void read(T& x,int& y,int& z,int& w) { cin>>x>>y>>z>>w; }
template<class T> void write(vector<pair<T,T>>& v) { repa(x,v) cout<<x.fi<<" "<<x.se<<endl; }
template<class T> void write(set<T>& v) { repa(x,v) cout<<x<<" "; cout<<endl; }
template<class T> void write(multiset<T>& v) { repa(x,v) cout<<x<<" "; cout<<endl; }
template<class T> void write(map<T,T>& v) { repa(x,v) cout<<x.fi<<" "<<x.se<<endl; }
template<class T> void write(multimap<T,T>& v) { repa(x,v) cout<<x.fi<<" "<<x.se<<endl; }
template<class T> void print(T& x) { write(x); }
template<class T> void print(vector<T>& v) { write(v); }
template<class T> void print(T& x,int y) { write(x,y); }
template<class T> void print(T& x,int y,int z) { write(x,y,z); }
template<class T> void print(T& x,int y,int z,int w) { write(x,y,z,w); }
template<class T> void print(vector<vector<T>>& v) { write(v); }
template<class T> void print(set<T>& v) { write(v); }
template<class T> void print(multiset<T>& v) { write(v); }
template<class T> void print(map<T,T>& v) { write(v); }
template<class T> void print(multimap<T,T>& v) { write(v); }
template<class T> void print(pair<T,T>& v) { write(v); }
template<class T> void print(vector<pair<T,T>>& v) { write(v); }
template<class T> void print(complex<T>& v) { cout<<v.real()<<" "<<v.imag()<<endl; }
template<class T> void print(vector<complex<T>>& v) { repa(x,v) print(x); }
template<class T> void print(T* v,int n) { rep(i,n) cout<<v[i]<<" "; cout<<endl; }
template<class T> void print(T* v,int n,int m) { rep(i,n) print(v[i],m); }
template<class T> void print(T* v,int n,int m,int w) { rep(i,n) print(v[i],m,w); }
template<class T> void print(T* v,int n,int m,int w,int z) { rep(i,n) print(v[i],m,w,z); }
template<class T> void read(T* v,int n) { rep(i,n) read(v[i]); }
template<class T> void read(T* v,int n,int m) { rep(i,n) read(v[i],m); }
template<class T> void read(T* v,int n,int m,int w) { rep(i,n) read(v[i],m,w); }
template<class T> void read(T* v,int n,int m,int w,int z) { rep(i,n) read(v[i],m,w,z); }
template<class T> void print(T* v,int n) { rep(i,n) print(v[i]); }
template<class T> void print(T* v,int n,int m) { rep(i,n) print(v[i],m); }
template<class T> void print(T* v,int n,int m,int w) { rep(i,n) print(v[i],m,w); }
template<class T> void print(T* v,int n,int m,int w,int z) { rep(i,n) print(v[i],m,w,z); }
template<class T> void print(vector<vector<T>>& v,int n) { rep(i,n) print(v[i]); }
template<class T> void print(vector<vector<T>>& v,int n,int m) { rep(i,n) print(v[i],m); }
template<class T> void print(vector<vector<T>>& v,int n,int m,int w) { rep(i,n) print(v[i],m,w); }
template<class T> void print(vector<vector<T>>& v,int n,int m,int w,int z) { rep(i,n) print(v[i],m,w,z); }
template<class T> void print(set<T>& v,int n) { rep(i,n) print(v[i]); }
template<class T> void print(set<T>& v,int n,int m) { rep(i,n) print(v[i],m); }
template<class T> void print(set<T>& v,int n,int m,int w) { rep(i,n) print(v[i],m,w); }
template<class T> void print(set<T>& v,int n,int m,int w,int z) { rep(i,n) print(v[i],m,w,z); }
template<class T> void print(multiset<T>& v,int n) { rep(i,n) print(v[i]); }
template<class T> void print(multiset<T>& v,int n,int m) { rep(i,n) print(v[i],m); }
template<class T> void print(multiset<T>& v,int n,int m,int w) { rep(i,n) print(v[i],m,w); }
template<class T> void print(multiset<T>& v,int n,int m,int w,int z) { rep(i,n) print(v[i],m,w,z); }
template<class T> void print(map<T,T>& v,int n) { rep(i,n) print(v[i]); }
template<class T> void print(map<T,T>& v,int n,int m) { rep(i,n) print(v[i],m); }
template<class T> void print(map<T,T>& v,int n,int m,int w) { rep(i,n) print(v[i],m,w); }
template<class T> void print(map<T,T>& v,int n,int m,int w,int z) { rep(i,n) print(v[i],m,w,z); }
template<class T> void print(multimap<T,T>& v,int n) { rep(i,n) print(v[i]); }
template<class T> void print(multimap<T,T>& v,int n,int m) { rep(i,n) print(v[i],m); }
template<class T> void print(multimap<T,T>& v,int n,int m,int w) { rep(i,n) print(v[i],m,w); }
template<class T> void print(multimap<T,T>& v,int n,int m,int w,int z) { rep(i,n) print(v[i],m,w,z); }
template<class T> void print(pair<T,T>& v,int n) { rep(i,n) print(v[i]); }
template<class T> void print(pair<T,T>& v,int n,int m) { rep(i,n) print(v[i],m); }
template<class T> void print(pair<T,T>& v,int n,int m,int w) { rep(i,n) print(v[i],m,w); }
template<class T> void print(pair<T,T>& v,int n,int m,int w,int z) { rep(i,n) print(v[i],m,w,z); }
template<class T> void print(vector<pair<T,T>>& v,int n) { rep(i,n) print(v[i]); }
template<class T> void print(vector<pair<T,T>>& v,int n,int m) { rep(i,n) print(v[i],m); }
template<class T> void print(vector<pair<T,T>>& v,int n,int m,int w) { rep(i,n) print(v[i],m,w); }
template<class T> void print(vector<pair<T,T>>& v,int n,int m,int w,int z) { rep(i,n) print(v[i],m,w,z); }
template<class T> void print(complex<T>& v,int n) { rep(i,n) print(v[i]); }
template<class T> void print(complex<T>& v,int n,int m) { rep(i,n) print(v[i],m); }
template<class T> void print(complex<T>& v,int n,int m,int w) { rep(i,n) print(v[i],m,w); }
template<class T> void print(complex<T>& v,int n,int m,int w,int z) { rep(i,n) print(v[i],m,w,z); }
template<class T> void print(vector<complex<T>>& v,int n) { rep(i,n) print(v[i]); }
template<class T> void print(vector<complex<T>>& v,int n,int m) { rep(i,n) print(v[i],m); }
template<class T> void print(vector<complex<T>>& v,int n,int m,int w) { rep(i,n) print(v[i],m,w); }
template<class T> void print(vector<complex<T>>& v,int n,int m,int w,int z) { rep(i,n) print(v[i],m,w,z); }
template<class T> void print(T* v,int n) { rep(i,n) print(v[i]); }
template<class T> void print(T* v,int n,int m) { rep(i,n) print(v[i],m); }
template<class T> void print(T* v,int n,int m,int w) { rep(i,n) print(v[i],m,w); }
template<class T> void print(T* v,int n,int m,int w,int z) { rep(i,n) print(v[i],m,w,z); }
template<class T> void print(T* v,int n,int m,int w,int z,int q) { rep(i,n) print(v[i],m,w,z,q); }
template<class T> void print(vector<vector<T>>& v,int n,int m,int w,int z,int q) { rep(i,n) print(v[i],m,w,z,q); }
template<class T> void print(set<T>& v,int n,int m,int w,int z,int q) { rep(i,n) print(v[i],m,w,z,q); }
template<class T> void print(multiset<T>& v,int n,int m,int w,int z,int q) { rep(i,n) print(v[i],m,w,z,q); }
template<class T> void print(map<T,T>& v,int n,int m,int w,int z,int q) { rep(i,n) print(v[i],m,w,z,q); }
template<class T> void print(multimap<T,T>& v,int n,int m,int w,int z,int q) { rep(i,n) print(v[i],m,w,z,q); }
template<class T> void print(pair<T,T>& v,int n,int m,int w,int z,int q) { rep(i,n) print(v[i],m,w,z,q); }
template<class T> void print(vector<pair<T,T>>& v,int n,int m,int w,int z,int q) { rep(i,n) print(v[i],m,w,z,q); }
template<class T> void print(complex<T>& v,int n,int m,int w,int z,int q) { rep(i,n) print(v[i],m,w,z,q); }
template<class T> void print(vector<complex<T>>& v,int n,int m,int w,int z,int q) { rep(i,n) print(v[i],m,w,z,q); }
template<class T> void print(T* v,int n,int m,int w,int z,int q,int s) { rep(i,n) print(v[i],m,w,z,q,s); }
template<class T> void print(vector<vector<T>>& v,int n,int m,int w,int z,int q,int s) { rep(i,n) print(v[i],m,w,z,q,s); }
template<class T> void print(set<T>& v,int n,int m,int w,int z,int q,int s) { rep(i,n) print(v[i],m,w,z,q,s); }
template<class T> void print(multiset<T>& v,int n,int m,int w,int z,int q,int s) { rep(i,n) print(v[i],m,w,z,q,s); }
template<class T> void print(map<T,T>& v,int n,int m,int w,int z,int q,int s) { rep(i,n) print(v[i],m,w,z,q,s); }
template<class T> void print(multimap<T,T>& v,int n,int m,int w,int z,int q,int s) { rep(i,n) print(v[i],m,w,z,q,s); }
template<class T> void print(pair<T,T>& v,int n,int m,int w,int z,int q,int s) { rep(i,n) print(v[i],m,w,z,q,s); }
template<class T> void print(vector<pair<T,T>>& v,int n,int m,int w,int z,int q,int s) { rep(i,n) print(v[i],m,w,z,q,s); }
template<class T> void print(complex<T>& v,int n,int m,int w,int z,int q,int s) { rep(i,n) print(v[i],m,w,z,q,s); }
template<class T> void print(vector<complex<T>>& v,int n,int m,int w,int z,int q,int s) { rep(i,n) print(v[i],m,w,z,q,s); }
template<class T> void print(T* v,int n,int m,int w,int z,int q,int s,int t) { rep(i,n) print(v[i],m,w,z,q,s,t); }
template<class T> void print(vector<vector<T>>& v,int n,int m,int w,int z,int q,int s,int t) { rep(i,n) print(v[i],m,w,z,q,s,t); }
template<class T> void print(set<T>& v,int n,int m,int w,int z,int q,int s,int t) { rep(i,n) print(v[i],m,w,z,q,s,t); }
template<class T> void print(multiset<T>& v,int n,int m,int w,int z,int q,int s,int t) { rep(i,n) print(v[i],m,w,z,q,s,t); }
template<class T> void print(map<T,T>& v,int n,int m,int w,int z,int q,int s,int t) { rep(i,n) print(v[i],m,w,z,q,s,t); }
template<class T> void print(multimap<T,T>& v,int n,int m,int w,int z,int q,int s,int t) { rep(i,n) print(v[i],m,w,z,q,s,t); }
template<class T> void print(pair<T,T>& v,int n,int m,int w,int z,int q,int s,int t) { rep(i,n) print(v[i],m,w,z,q,s,t); }
template<class T> void print(vector<pair<T,T>>& v,int n,int m,int w,int z,int q,int s,int t) { rep(i,n) print(v[i],m,w,z,q,s,t); }
template<class T> void print(complex<T>& v,int n,int m,int w,int z,int q,int s,int t) { rep(i,n) print(v[i],m,w,z,q,s,t); }
template<class T> void print(vector<complex<T>>& v,int n,int m,int w,int z,int q,int s,int t) { rep(i,n) print(v[i],m,w,z,q,s,t); }
template<class T> void print(T* v,int n,int m,int w,int z,int q,int s,int t,int u) { rep(i,n) print(v[i],m,w,z,q,s,t,u); }
template<class T> void print(vector<vector<T>>& v,int n,int m,int w,int z,int q,int s,int t,int u) { rep(i,n) print(v[i],m,w,z,q,s,t,u); }
template<class T> void print(set<T>& v,int n,int m,int w,int z,int q,int s,int t,int u) { rep(i,n) print(v[i],m,w,z,q,s,t,u); }
template<class T> void print(multiset<T>& v,int n,int m,int w,int z,int q,int s,int t,int u) { rep(i,n) print(v[i],m,w,z,q,s,t,u); }
template<class T> void print(map<T,T>& v,int n,int m,int w,int z,int q,int s,int t,int u) { rep(i,n) print(v[i],m,w,z,q,s,t,u); }
template<class T> void print(multimap<T,T>& v,int n,int m,int w,int z,int q,int s,int t,int u) { rep(i,n) print(v[i],m,w,z,q,s,t,u); }
template<class T> void print(pair<T,T>& v,int n,int m,int w,int z,int q,int s,int t,int u) { rep(i,n) print(v[i],m,w,z,q,s,t,u); }
template<class T> void print(vector<pair<T,T>>& v,int n,int m,int w,int z,int q,int s,int t,int u) { rep(i,n) print(v[i],m,w,z,q,s,t,u); }
template<class T> void print(complex<T>& v,int n,int m,int w,int z,int q,int s,int t,int u,int v) { rep(i,n) print(v[i],m,w,z,q,s,t,u,v); }
template<class T> void print(vector<complex<T>>& v,int n,int m,int w,int z,int q,int s,int t,int u,int v) { rep(i,n) print(v[i],m,w,z,q,s,t,u,v); }
template<class T> void print(T* v,int n,int m,int w,int z,int q,int s,int t,int u,int v,int x) { rep(i,n) print(v[i],m,w,z,q,s,t,u,v,x); }
template<class T> void print(vector<vector<T>>& v,int n,int m,int w,int z,int q,int s,int t,int u,int v,int x) { rep(i,n) print(v[i],m,w,z,q,s,t,u,v,x); }
template<class T> void print(set<T>& v,int n,int m,int w,int z,int q,int s,int t,int u,int v,int x) { rep(i,n) print(v[i],m,w,z,q,s,t,u,v,x); }
template<class T> void print(multiset<T>& v,int n,int m,int w,int z,int q,int s,int t,int u,int v,int x) { rep(i,n) print(v[i],m,w,z,q,s,t,u,v,x); }
template<class T> void print(map<T,T>& v,int n,int m,int w,int z,int q,int s,int t,int u,int v,int x) { rep(i,n) print(v[i],m,w,z,q,s,t,u,v,x); }
template<class T> void print(multimap<T,T>& v,int n,int m,int w,int z,int q,int s,int t,int u,int v,int x) { rep(i,n) print(v[i],m,w,z,q,s,t,u,v,x); }
template<class T> void print(pair<T,T>& v,int n,int m,int w,int z,int q,int s,int t,int u,int v,int x,int y) { rep(i,n) print(v[i],m,w,z,q,s,t,u,v,x,y); }
template<class T> void print(vector<pair<T,T>>& v,int n,int m,int w,int z,int q,int s,int t,int u,int v,int x,int y) { rep(i,n) print(v[i],m,w,z,q,s,t,u,v,x,y); }
template<class T> void print(complex<T>& v,int n,int m,int w,int z,int q,int s,int t,int u,int v,int x,int y) { rep(i,n) print(v[i],m,w,z,q,s,t,u,v,x,y); }
template<class T> void print(vector<complex<T>>& v,int n,int m,int w,int z,int q,int s,int t,int u,int v,int x,int y) { rep(i,n) print(v[i],m,w,z,q,s,t,u,v,x,y); }
template<class T> void print(T* v,int n,int m,int w,int z,int q,int s,int t,int u,int v,int x,int y,int z) { rep(i,n) print(v[i],m,w,z,q,s,t,u,v,x,y,z); }
template<class T> void print(vector<vector<T>>& v,int n,int m,int w,int z,int q,int s,int t,int u,int v,int x,int y,int z) { rep(i,n) print(v[i],m,w,z,q,s,t,u,v,x,y,z); }
