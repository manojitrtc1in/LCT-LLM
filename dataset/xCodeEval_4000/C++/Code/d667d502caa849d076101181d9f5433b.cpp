

#include <iostream>
#include <fstream>

#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

#define x first
#define y second
#define ll long long
#define ld long double
#define pii pair<int,int>
#define wh(x) (x).begin(),(x).end()
#define ri(x) int x;cin>>x;
#define rii(x,y) int x,y;cin>>x>>y;
#define rl(x) ll x;cin>>x;
#define rv(v) for(auto&_cinv:v) cin>>_cinv;
#define wv(v) for(auto&_coutv:v) cout << _coutv << ' '; cout << endl;
#define ev(v) for(auto&_cerrv:v) cerr << _cerrv << ' '; cerr << endl;
#define MOD 1000000007


template <unsigned int N> class Field {
    typedef unsigned int ui;
    typedef unsigned long long ull;
    inline ui inv(ui a) {
        ll t=0,nt=1,r=N,nr=a;
        while(nr) { ll q=r/nr; t-=q*nt; swap(t,nt); r-=q*nr; swap(r,nr); }
        assert(r<=1); return (t<0) ? t+N : t;
    }
public:
    inline Field(int x = 0) : v(x) {}
    inline Field<N>&operator+=(const Field<N>&o) {if ((ll)v+o.v >= N) v = (ll)v+o.v-N; else v = v+o.v; return *this; }
    inline Field<N>&operator-=(const Field<N>&o) {if (v<o.v) v = N-o.v+v; else v=v-o.v; return *this; }
    inline Field<N>&operator*=(const Field<N>&o) {v=(ull)v*o.v % N; return *this; }
    inline Field<N>&operator/=(const Field<N>&o) { return *this*=inv(o.v); }
    inline Field<N> operator+(const Field<N>&o) {Field<N>r(*this);return r+=o;}
    inline Field<N> operator-(const Field<N>&o) {Field<N>r(*this);return r-=o;}
    inline Field<N> operator*(const Field<N>&o) {Field<N>r(*this);return r*=o;}
    inline Field<N> operator/(const Field<N>&o) {Field<N>r(*this);return r/=o;}
    inline Field<N> operator-() {return {-v};};
    inline Field<N>& operator++() { ++v; if (v==N) v=0; return *this; }
    inline Field<N> operator++(int) { Field<N>r(*this); ++*this; return r; }
    inline Field<N>& operator--() { --v; if (v==-1) v=N-1; return *this; }
    inline Field<N> operator--(int) { Field<N>r(*this); --*this; return r; }
    inline bool operator==(const Field<N>&o) { return o.v==v; }
    inline explicit operator unsigned int() const { return v; }
private: ui v;
};
template<unsigned int N>istream &operator>>(std::istream&is,Field<N>&f){unsigned int v;is>>v;f=v;return is;}
template<unsigned int N>ostream &operator<<(std::ostream&os,const Field<N>&f){return os<<(unsigned int)f;}

typedef Field<1000000007> FieldMod;

const unsigned int FFT_MAX_BITS = 25;
const unsigned int FFT_PRIME = 4194304001u;
const unsigned int OMEGA[] = {1u, 4194304000u, 809539273u, 2303415184u, 1800537630u, 1287904184u, 3915137183u, 341015394u, 418248771u, 2297133295u, 246248871u, 91156249u, 911964167u, 1905142968u, 888982599u, 3459657251u, 577736066u, 2694679249u, 779825358u, 2946902746u, 2007716871u, 4100601466u, 374757901u, 1568239201u, 39601u, 199u};
const unsigned int OMEGA_INV[] = {1u, 4194304000u, 3384764728u, 3412379098u, 1559634102u, 2633613076u, 1804313316u, 3353703883u, 103452218u, 3326307677u, 1194130126u, 176344934u, 298085440u, 2167853111u, 2564851092u, 3922803478u, 941634782u, 1390530532u, 3386056271u, 2737677338u, 3042570214u, 2405831823u, 4070788264u, 3279912072u, 2785964305u, 758768563u};
typedef Field<FFT_PRIME> F;

void fft(std::vector<F> &V, int P, bool inverse = false) {
    if (P == 0) return;
    for (int i=1, j=0; i<(1<<P); ++i) {
        int bit = (1<<(P-1));
        for (; j>=bit; bit>>=1) j -= bit;
        j += bit;
        if (i < j) std::swap(V[i],V[j]);
    }

    for (int B=1; B<=P; ++B) {
        F omega = inverse ? OMEGA_INV[B] : OMEGA[B];
        for (int i = 0; i < (1<<P); i+=(1<<B)) {
            F x = 1;
            for (int j = 0; j < (1<<(B-1)); j++) {
                F u = V[i+j], v = V[i+j+(1<<(B-1))] * x;
                V[i+j] = u + v;
                V[i+j+(1<<(B-1))] = u-v;
                x *= omega;
            }
        }
    }

    if (inverse) {
        F q = F(1) / F(1<<P);
        for (F&v:V) v *= q;
    }
}


struct Dinic {int V,E;std::vector<int>l,t,c,n,a;std::vector<ll>p;Dinic(int v):V(v),E(0),l(V,-1),t(V),c(V){}
  void AddEdge(int x,int y,ll c1=1,ll c2=0){a.push_back(y);p.push_back(c1);n.push_back(l[x]);l[x]=E++;
  a.push_back(x);p.push_back(c2);n.push_back(l[y]);l[y]=E++;}ll push(int x,int v,ll flow){if(x==v)return
  flow;for(int&e=c[x];e!=-1;e=n[e]){int y=a[e];if(p[e]&&t[x]+1==t[y])if(ll f=push(y,v,min(flow,p[e])))
  return p[e]-=f,p[e^1]+=f,f;}return 0;}ll GetMaxFlow(int u,int v){ll ret=0;while(true){for(int i=0;i<V;
  i++){c[i]=l[i];t[i]=-1;}std::queue<int>Q;Q.push(u);t[u]=0;while(!Q.empty()){int x=Q.front();Q.pop();
  for (int e=l[x];e!=-1;e=n[e]){int y=a[e];if(p[e]&&t[y]==-1){Q.push(y);t[y]=t[x]+1;}}}if(t[v]==-1)break;
  while(ll f=push(u,v,1e18))ret+=f;}return ret;}std::vector<bool>GetMinCut(int u){std::queue<int>Q;Q.push(u);
  vector<bool>R(V,false);R[u]=true;while(!Q.empty()){int x=Q.front();Q.pop();for(int e=l[x];e!=-1;e=n[e])
  {int y=a[e];if(!R[y]&&p[e]>0){Q.push(y);R[y]=true;}}}return R;}};



template<typename F>struct NoCombine {
    const int NOCOMB=-2;
    void setup(size_t){}void op(F&p,F n,size_t,size_t,size_t){p=n;}F up(F l,F r,size_t){return l==r?l:NOCOMB;}
    void down(F&u,F&l,F&r,size_t,size_t,size_t){if(u!=NOCOMB){l=r=u;}u=NOCOMB;}};
template<typename F,typename Op>struct Persistent{Op o;void setup(size_t){}void op(F&p,F n,size_t,size_t, size_t){p=n;}F up(F l, F r, size_t){return o(l,r);}void down(F&,F&,F&,size_t,size_t, size_t b) {}};

template<typename F,typename SetOp,typename CombineOp,typename PowerOp>struct LazyProp{
    void setup(size_t s){this->s=s;L=new F[s]();}
    void down(F&u,F&l,F&r,size_t i,size_t a,size_t b){op(l,L[i],2*i,a,(a+b)/2);op(r,L[i],2*i+1,(a+b)/2,b);L[i]=0;}
    void op(F&p,F n,size_t i,size_t a,size_t b){p=cop(p,pop(n,b-a));if(i<this->s)this->L[i]=sop(this->L[i],n);}
    F up(F l,F r,size_t){return cop(l,r);}SetOp sop;CombineOp cop;PowerOp pop;F*L;size_t s;
};

template <typename F> struct AddOp { F operator()(F a, F b) { return a+b; }};
template <typename F> struct MultOp { F operator()(F a, F b) { return a*b; }};
template <typename F> struct IdempOp { F operator()(F a, F b) { return a; }};
template <typename F> struct MinOp { F operator()(F a, F b) { return min(a,b); }};
template <typename F> struct MaxOp { F operator()(F a, F b) { return max(a,b); }};

template <typename F, typename Combine> struct Tree {
    void setup(size_t s, F def) {
        size = 1; while (size < s) size *= 2;
        T = new F[2*size];
        for (size_t i = size; i < 2*size; i++) T[i] = def;
        for (size_t i = size-1; i > 0; i--) T[i] = op.up(T[2*i],T[2*i+1], i);
        op.setup(2*size);
    }

    void setup(vector<F> & data) {
        size = 1; while (size < data.size()) size *= 2;
        T = new F[2*size];
        for (size_t i = size; i < 2*size; i++) T[i] = data[i-size];
        for (size_t i = size-1; i > 0; i--) T[i] = op.up(T[2*i],T[2*i+1], i);
        op.setup(2*size);
    }

    inline void put(size_t x, F n) { put(x, x, n); }
    inline void put(size_t from, size_t to, F n) { put2(from, to+1, n, 1, 0, size); }
    inline F get(size_t x) { return get(x, x); }
    inline F get(size_t from, size_t to) { return get2(from, to+1, 1, 0, size); }

    void put2(size_t from, size_t to, F n, size_t i, size_t a, size_t b) {
        if (from <= a && to >= b) { op.op(T[i], n, i, a, b); return; }
        if (from >= b || to <= a) { return; }
        op.down(T[i], T[2*i], T[2*i+1], i, a, b);
        put2(from, to, n, 2*i, a, (a+b)/2);
        put2(from, to, n, 2*i+1, (a+b)/2, b);
        T[i] = op.up(T[2*i], T[2*i+1], i);
    }

    F get2(size_t from, size_t to, size_t i, size_t a, size_t b) {
        if (from <= a && to >= b) { return T[i]; }
        op.down(T[i], T[2*i], T[2*i+1], i, a, b);
        if (to <= (a+b)/2) { return get2(from, to, 2*i, a, (a+b)/2); }
        else if (from >= (a+b)/2) { return get2(from, to, 2*i+1, (a+b)/2, b); }
        else return op.up(get2(from, to, 2*i, a, (a+b)/2), get2(from, to, 2*i+1, (a+b)/2, b), i);
    }

    size_t size; F * T; Combine op;
};

typedef Tree<int, NoCombine<int>> SetGetTree;
typedef Tree<int, LazyProp<int, AddOp<int>, AddOp<int>, MultOp<int>>> AddSumTree;
typedef Tree<int, Persistent<int, MinOp<int>>> SetMinTree;
typedef Tree<int, Persistent<int, MaxOp<int>>> SetMaxTree;



#define V vector
template<class T>struct Edge{int u,v;T c,f;size_t i;};
template<class T>struct PushRelabel{int n;V<V<Edge<T>>>d;V<T>x;V<int>l,c;V<bool>a;V<V<int>>B;int b;PushRelabel(int n):n(n),d(n){}void AddEdge(int u,int v,T c=1)
{d[u].push_back({u,v,c,0,d[v].size()});if(u==v)d[u].back().i++;d[v].push_back({v,u,0,0,d[u].size()-1});}void q(int v){if(!a[v]&&x[v]>0&&l[v]<n){a[v]=true;
B[l[v]].push_back(v);b=max(b,l[v]);}}void z(Edge<T>&e){T m=min(x[e.u],e.c-e.f);if(l[e.u]==l[e.v]+1&&m>T(0)){e.f+=m;d[e.v][e.i].f-=m;x[e.v]+=m;x[e.u]-=m;
q(e.v);}}inline void s(int v, int n) {--c[l[v]];l[v] = n;++c[l[v]];q(v);}void g(int k){for(int v=0;v<n;v++)if(l[v]>=k)s(v,max(l[v],n));}void r(int v){int nl=n;
for(auto&e:d[v]){if(e.c-e.f>0)nl=min(nl,l[e.v]+1);}s(v,nl);}void h(int v){for(auto&e:d[v]){z(e);if(x[v]<=0)return;}if(c[l[v]]==1)g(l[v]);else r(v);}T GetMaxFlow
(int s, int t){l=V<int>(n,0),x=V<T>(n,0),c=V<int>(n+1,0),a=V<bool>(n,false),B=V<V<int>>(n),b=0;for(auto&e:d[s])x[s]+=e.c;c[0]=n;q(s);a[t]=true;while(b>=0){if(!B[b]
.empty()){int v=B[b].back();B[b].pop_back();a[v]=false;h(v);}else b--;}return x[t];}};
#undef V

namespace std {
    template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }


class TaskA {
public:
	void solve(std::istream& in, std::ostream& out) {
		int N, M; in >> N >> M;
		int L = N;
		for (int i = 0; i < M; ++i) {
			int u, v; in >> u >> v;
			L = min(L, v-u+1);
		}


		

		


		out << L << endl;
		for (int j = 0; j < N; ++j) {
			out << j % L << ' ';
		}
		out << endl;
	}
};



int main() {
	ios_base::sync_with_stdio(false);
	TaskA solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}