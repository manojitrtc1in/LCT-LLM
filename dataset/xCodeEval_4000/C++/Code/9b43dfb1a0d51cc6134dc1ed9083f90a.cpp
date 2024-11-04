#ifndef M_H
#define M_H
#pragma GCC optimize("O3","unroll-loops")
#include<bits/stdc++.h>
using namespace std;using uint=unsigned int;using uint32=unsigned int;using int32=int;using int64=long long;using uint64=unsigned long long;using uint128=unsigned __int128;using int128=__int128;ostream&operator<<(ostream&os,int128 a){const int64 t1=1e12;int128 t2=t1;t2*=t2;int64 p1=a/t2;if(0!=p1)os<<p1;a%=t2;if(a<0){a*=-1;if(p1==0)os<<'-';}int64 p2=a/t1;if(0!=p2)os<<p2;os<<int64(a%t1);return os;}ostream&operator<<(ostream&os,uint128 a){const uint64 t1=1e12;uint128 t2=t1;t2*=t2;uint64 p1=a/t2;if(0!=p1)os<<p1;a%=t2;uint64 p2=a/t1;if(0!=p2)os<<p2;os<<uint64(a%t1);return os;}
#define elif else if
#define fi first
#define se second
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x) 
#define mini(l,r) {auto x = r; if(l>x) l=x;}
#define maxi(l,r) {auto x = r; if(l<x) l=x;}
#define oldv(x) (x) 
template<typename T>using enable_if_integral_t=enable_if_t<is_integral_v<T>,bool>;template<typename T>using enable_if_floatingpoint_t=enable_if_t<is_floating_point_v<T>,bool>;template<class,template<class,class...>class>struct is_templatespe:public false_type{};template<class...Ts,template<class,class...>class U>struct is_templatespe<U<Ts...>,U>:public true_type{};template<typename T>using enable_if_memrelated_t=enable_if_t<is_trivially_copy_assignable_v<T>&&is_trivially_destructible_v<T>&&is_constructible_v<T>,bool>;
#define ___
template<typename T>constexpr T UNUSE=T(0);
#define GET_MACRO(_0,_1,_2,_3,_N,...) _N
#define rep(...) GET_MACRO(__VA_ARGS__,_rep4,_rep3,_rep2,_rep1)(__VA_ARGS__)
#define _rep4(i,a,b,c) for(int32 i=(a),_5=(b),_6=(c);i<_5;i+=_6)
#define _rep3(i,a,b) for(int32 i=(a),_5=(b);i<_5;++i)
#define _rep2(i,b) _rep3(i,0,b)
#define _rep1(b) _rep2(_,b)
#define rev_rep(...) GET_MACRO(__VA_ARGS__,1/0,_rev_rep3,_rev_rep2,_rev_rep1)(__VA_ARGS__)
#define _rev_rep3(i,a,b) for(int32 i=(b)-1,_5=(a);i>=_5;--i)
#define _rev_rep2(i,b) _rev_rep3(i,0,b)
#define _rev_rep1(b) _rev_rep2(_,b)
#define for_iter(i, s) for(auto i=begin(s);i!=end(s);i++)
#define pair_assign(a,b, c,d) {auto _pd=(d);a=c;b=_pd;}
#define triple_assign(a,b,c, d,e,f) {auto _pe=(e);auto _pf=(f); a=(d);b=_pe;c=_pf;}
#define floor_div(a,b) (a/b - ( (a%b) && (a^b)<0 ))
#define memset0(arr, n) memset(arr,0,sizeof(decltype(arr[0]))*n)
#if(!defined ONLINE_JUDGE&&!defined PROD_MODE)
#define DEBUG_MODE
#endif
#if __cplusplus<201703L
template<typename T>inline T gcd(T l,T r){return __gcd(l,r);}template<typename T>inline T lcm(T l,T r){return l/__gcd(l,r)*r;}template<typename T>constexpr int len(const T&t)const{return t.size();}template<typename T,int N>constexpr int len(T(&t)[N])const{return N;}
#else 
template<typename T>constexpr int len(const T&t){return size(t);}
#endif
template<typename T>inline T lowbit(T x){return x&-x;};inline constexpr int32 bit_count(int32 x){return __builtin_popcount(x);}inline constexpr int32 bit_count(uint32 x){return __builtin_popcount(x);}inline constexpr int32 bit_count(int64 x){return __builtin_popcountll(x);}inline constexpr int32 bit_count(uint64 x){return __builtin_popcountll(x);}inline constexpr int32 bit_length(uint64 x){return 64-__builtin_clzll(x);}inline constexpr int32 bit_length(int64 x){return 64-__builtin_clzll(x);}inline constexpr int32 bit_length(int32 x){return 32-__builtin_clz(x);}inline constexpr int32 bit_length(uint32 x){return 32-__builtin_clz(x);}template<class InputIter,class OutputIter>void prefix_sum(InputIter first,InputIter last,OutputIter output){typename iterator_traits<OutputIter>::value_type cs=0,tmp=0;while(first!=last){tmp=*first++;*output++=cs;cs+=tmp;}*output=cs;}template<class T,class F>T binary_search_first(T l,T r,F f){assert(l<=r);while(l<r){T m=l+((typename make_unsigned<T>::type)r-l)/2;if(f(m))r=m;else l=m+1;}return l;}template<class T,class F>T binary_search_last(T l,T r,F f){assert(l<=r);while(l<r){T m=l+((typename make_unsigned<T>::type)r-l-1)/2;if(f(m))l=m;else r=m-1;}return l;}void permutations(int n,int r,function<bool(int const*)>f){int ids[r];bool vis[n];memset0(vis,n);rep(i,r)ids[i]=i,vis[i]=1;while(1){if(!f(ids))return;int i_last=r-1;for(;i_last>=0;i_last--){int last=ids[i_last];vis[last++]=0;while(last<n and vis[last])last++;if(last<n){vis[last]=1;ids[i_last]=last;break;}}if(-1==i_last)break;i_last++;for(int i=0;i_last<r&&i<n;i++){if(!vis[i]){vis[i]=1;ids[i_last++]=i;}}}}void combinations(int n,int r,function<bool(int const*)>f){int ids[r];rep(i,r)ids[i]=i;while(1){if(!f(ids))return;int i_last;for(i_last=r-1;i_last>=0 and ids[i_last]==i_last+n-r;i_last--);if(-1==i_last)break;ids[i_last]++;rep(i,i_last+1,r)ids[i]=ids[i-1]+1;}}void product(const vector<int>&args,function<bool(int const*)>f){int n=args.size();int ids[n];memset0(ids,n);while(1){if(!f(ids))return;int i_last;for(i_last=n-1;i_last>=0 and ids[i_last]==args[i_last]-1;i_last--);if(-1==i_last)break;ids[i_last]++;rep(i,i_last+1,n)ids[i]=0;}}template<typename T,int maxn=200010>class preallocateNew{inline static T*__pool=new T[maxn];inline static int __idx;public:static void init(){__idx=0;}void*operator new(size_t count){return&__pool[__idx++];}};template<typename T,enable_if_memrelated_t<T> =0 >struct marr{T*A;typedef T*iterator;typedef T value_type;int N;int n=0;marr()=delete;marr(int N):A(new T[N]),N(N){}marr(const marr&r):A(new T[r.N]),N(r.N),n(r.n){memcpy(A,r.A,sizeof(T)*r.n);}marr(marr&&r):A(r.A),N(r.N),n(r.n){r.A=nullptr;r.N=r.n;}marr&operator=(marr&&r){if(this!=&r){delete[] A;A=r.A;N=r.N;n=r.n;r.A=nullptr;r.N=r.n;}return*this;}~marr(){delete[] A;}marr&operator=(marr&r){memcpy(A,r.A,sizeof(T)*r.n);n=r.n;return&this;}void init(int n=0){this->n=n;}void init(int n,const T&v){this->n=n;if(v==0){memset(A,0,sizeof(T)*n);}else{rep(i,n)A[i]=v;}}void init(initializer_list<T>L){n=0;for(auto&v:L)A[n++]=v;}size_t size()const{return n;}T&operator[](int i){if(i>=0)return A[i];return A[i+n];}const T&operator[](int i)const{return const_cast<marr*>(this)->operator[](i);}int lexical_cmp(const marr<T>&oth){rep(i,min(n,oth.n)){if(A[i]>oth.A[i])return 1;elif(A[i]<oth.A[i])return-1;}if(n==oth.n)return 0;return(n<oth.n)?-1:1;}bool operator==(const marr<T>&oth)const{return oth.n==n and memcmp(oth.A,A,n)==0;}bool operator!=(const marr<T>&oth)const{return!(oth==*this);}T*begin(){return&A[0];}const T*begin()const{return&A[0];}T*end(){return&A[n];}const T*end()const{return&A[n];}void append(const T&v){A[n++]=v;}T pop(){return A[--n];}T pop(int index){int ret=A[index];if(index+1<n)memmove(A+index,A+index+1,sizeof(T)*(n-(index+1)));n--;return ret;}void slice_remove(int l,int r){if(r-l<=0 or r<=0)return;if(l<0)l=0;if(r<n){memmove(A+l,A+r,sizeof(T)*(n-r));n-=r-l;}else{n=l;}}void insert(int index,const T&v){memmove(A+index+1,A+index,sizeof(T)*(n-index));n++;A[index]=v;}int find(const T&v,int start=0){return find(v,start,n);}int find(const T&v,int start,int stop){if(stop-start<=0 or stop<=0)return-1;if(start<0)start=0;rep(i,start,stop){if(A[i]==v)return i;}return n;}friend istream&operator>>(istream&in,marr&obj){rep(i,obj.n)in>>obj.A[i];return in;}friend ostream&operator<<(ostream&os,const marr&obj){rep(i,obj.n-1)os<<obj.A[i]<<' ';os<<obj.A[obj.n-1];return os;}};template<typename T>void D_(const marr<T>&A){D_(is(A,A.n));}template<typename T,enable_if_memrelated_t<T> =0 >struct marrneg{marr<T>A;int l,r;marrneg(int maxn):A(maxn){}void init(int l,int r,T v){this->l=l;this->r=r;A.init(r-l,v);}T&operator[](int i){return A.A[i-l];}};template<typename T,enable_if_memrelated_t<T> =0 >struct marr2{typedef T value_type;T*A;int N;int n,m;marr2()=delete;marr2(int N):A(new T[N]),N(N){}marr2(marr2&&r):A(r.A),N(r.N),n(r.n),m(r.m){r.A=nullptr;r.N=r.n=r.m=0;}marr2&operator=(marr2&&r){if(this!=&r){delete[] A;A=r.A;N=r.N;n=r.n;m=r.m;r.A=nullptr;r.N=r.n=r.m=0;}return*this;}marr2(const marr2&r):A(new T[r.N]),N(r.N),n(r.n),m(r.m){memcpy(A,r.A,sizeof(T)*r.n*r.m);}~marr2(){delete[] A;}marr2&operator=(marr2&r){memcpy(A,r.A,sizeof(T)*r.n*r.m);n=r.n;m=r.m;return&this;}void init(int n,int m){this->n=n;this->m=m;}void init(int n,int m,const T&v){this->n=n;this->m=m;initsequence(n*m,v);}size_t size()const{return n;}void initsequence(int n,const T&v){if(v==0){memset(A,0,sizeof(T)*n);}else{rep(i,n)A[i]=v;}}T*operator[](int i){return A+i*m;}const T*operator[](int i)const{return const_cast<marr2*>(this)->operator[](i);}};template<typename T>void D_(const marr2<T>&A){D_(is2(A,A.n,A.m));}template<class T>struct _mqueue{T*A;typedef T*iterator;typedef T value_type;int N;int l=0;int r=0;_mqueue(int N):N(N){A=new T[N];}~_mqueue(){delete[] A;}void init(initializer_list<T>L){l=r=0;for(auto&v:L)A[r++]=v;}void init(){l=r=0;}size_t size()const{return r-l;}int*begin(){return&A[l];}int*end(){return&A[r];}T&operator[](int index){if(0<=index)return A[index+l];return A[index+r];}const T&operator[](int index)const{if(0<=index)return A[index+l];return A[index+r];}void append(const T&v){if(r==N){memmove(A,A+l,(r-l)*sizeof(T));r-=l;l=0;}A[r++]=v;}T popleft(){return A[l++];}void rotate(int step=1){int sz=r-l;step=step%sz;if(step<0)step+=sz;if((sz-step)<1000+0.035*sz){rep(sz-step)append(popleft());return;}if(step<=sz/2){T buf[step];memcpy(buf,A+sz-step,step*sizeof(T));memmove(A+step,A,(sz-step)*sizeof(T));memcpy(A,buf,step*sizeof(T));}else{T buf[sz-step];memcpy(buf,A,(sz-step)*sizeof(T));memmove(A,A+sz-step,step*sizeof(T));memcpy(A+step,buf,(sz-step)*sizeof(T));}}};template<bool weighted>struct Adjll_{int n;int m=0;int*head;int*wei;int*next;int*end;Adjll_(int N,int M){head=new int[N];end=new int[M];next=new int[M];if(weighted)wei=new int[M];}void init(int n){this->n=n;memset(head,-1,sizeof(int)*n);m=0;}void add(int u,int v){end[m]=v;next[m]=head[u];head[u]=m++;}void add(int u,int v,int w){end[m]=v;next[m]=head[u];wei[m]=w;head[u]=m++;}size_t size()const{return n;}void pprint(){cout<<"Adjll\n";rep(u,n){cout<<" [";for(int eid=head[u];~eid;eid=next[eid]){int v=end[eid];if(weighted){cout<<'['<<v<<","<<wei[eid]<<']';if(~next[eid])cout<<",";}else{cout<<v;if(~next[eid])cout<<",";}}cout<<"]\n";}cout<<'\n';}};using Adjll=Adjll_<0>;using AdjllW=Adjll_<1>;void __template_adjllW_foreach(AdjllW&adj,int u,function<void(int,int)>f){for(int eid=adj.head[u];~eid;eid=adj.next[eid]){int v=adj.end[eid],w=adj.wei[eid];f(v,w);}}void __template_adjll_foreach(Adjll&adj,int u,function<void(int)>f){for(int eid=adj.head[u];~eid;eid=adj.next[eid]){int v=adj.end[eid];f(v);}}tuple<int64,int64,int64>ext_gcd(int64 a,int64 b){int64 x0=1,x1=0;int64 y0=0,y1=1;while(b){int64 q=a/b;pair_assign(a,b,b,a%b);pair_assign(x0,x1,x1,x0-q*x1);pair_assign(y0,y1,y1,y0-q*y1);}return make_tuple(a,x0,y0);}template<int32 staticmod=1000000007>struct modint{
#ifdef DYMOD
inline static int32 mod=0;static void setmod(int32 _mod){mod=_mod;};
#else 
constexpr inline static int32 mod=staticmod;
#endif
int32 v;modint():v(0){};modint(const modint&r):v(r.v){};template<typename T,enable_if_integral_t<T> =0>modint(T v_=0){v=v_%mod;if(v<0)v+=mod;}constexpr static modint raw(int32 v){modint ret;ret.v=v;return ret;}explicit operator int32()const{return v;}friend ostream&operator<<(ostream&os,const modint&obj){os<<obj.v;return os;}friend istream&operator>>(istream&in,modint&obj){int v;in>>v;obj+=v;return in;}modint&operator+=(const modint&r){v+=r.v;if(v>=mod)v-=mod;return*this;}modint&operator-=(const modint&r){v-=r.v;if(v<0)v+=mod;return*this;}modint&operator*=(const modint&r){v=1ll*v*r.v%mod;return*this;}modint&operator/=(const modint&r){return*this*=r.pow(-1);}friend modint operator*(modint l,modint r){return l*=r;}friend modint operator-(modint l,const modint&r){return l-=r;}friend modint operator+(modint l,const modint&r){return l+=r;}friend modint operator/(modint l,const modint&r){return l/=r;}friend bool operator==(const modint&l,const modint&r){return l.v==r.v;}friend bool operator!=(const modint&l,const modint&r){return l.v!=r.v;}modint&operator++(){v++;if(v==mod)v=0;return*this;}modint&operator--(){if(v==0)v=mod;v--;return*this;}modint operator++(int32){modint old=*this;++*this;return old;}modint operator--(int32){modint old=*this;--*this;return old;}modint operator+()const{return*this;}modint operator-()const{return mod-*this;}modint pow(int64 exp)const{if(exp>=0){modint ret=raw(1);for(modint bitval(*this);exp;exp>>=1){if(exp&1)ret*=bitval;bitval*=bitval;}return ret;}else{auto [g,inv,_]=ext_gcd(v,mod);if(g!=1)throw logic_error("modint don't have inv under mod "s+to_string(mod));if(inv<0)inv+=mod;if(exp==-1)return inv;return raw(inv).pow(-exp);}}};template<int seq>string to_string(const modint<seq>&i){return to_string(int32(i));}template<int32 mod>struct combTable{using mint=modint<mod>;mint*fac;mint*invfac;mint*inv;combTable(int32 maxn){inv=new mint[maxn];fac=new mint[maxn];invfac=new mint[maxn];inv[1]=1;invfac[0]=invfac[1]=fac[0]=fac[1]=1;rep(i,2,maxn){inv[i]=inv[mod%i]*mint::raw(mod-mod/i);fac[i]=fac[i-1]*mint::raw(i);invfac[i]=invfac[i-1]*inv[i];}}mint perm(int32 n,int32 r){if(r<0 or n<r)return 0;return fac[n]*invfac[n-r];}mint comb(int32 n,int32 r){return perm(n,r)*invfac[r];}};bool __mystery=[](){cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);return 0;}();void print(){cout<<'\n';}void print(int32*A,int t){rep(i,t)cout<<A[i]<<' ';cout<<'\n';}void print(int64*A,int t){rep(i,t)cout<<A[i]<<' ';cout<<'\n';}template<class T,class Al>void print(vector<T,Al>&A){for(auto v:A)cout<<v<<' ';cout<<'\n';}template<class T,class... Args>void print(const T&v,Args... args){cout<<v<<' ';print(args...);}struct __random_generator{mt19937 __prng;__random_generator():__prng(random_device()()){}template<typename T,enable_if_integral_t<T> =0 >T randint(T l=numeric_limits<T>::min(),T r=numeric_limits<T>::max()){uniform_int_distribution<T>dis(l,r);return dis(__prng);}template<typename T,enable_if_floatingpoint_t<T> =0>T randreal(T l=numeric_limits<T>::min(),T r=numeric_limits<T>::max()){uniform_real_distribution<T>dis(l,r);return dis(__prng);}void setseed(uint64 seed){__prng.seed(seed);}}prng;
#ifdef ONLINE_JUDGE
#define D(...)
#define Dtype(...)
#define Dtime(...)
#else 
#include "d.h"
#endif
#endif


const int maxn = 2e5 + 10;
#define int int64
int __t, n;
int t0,t1,t2;
int v;

void solve(){
    print(v/2+(v%2));
}

int32 main(){
    int __T=1;
    cin>>__T;
    for(__t=0; __t<__T;__t++){
        

        

            cin>>v;
        

        
        solve();
    }
    
} 
