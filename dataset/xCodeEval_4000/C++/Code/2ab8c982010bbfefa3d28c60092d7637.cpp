

#ifndef MAJK_LIB
#define MAJK_LIB

#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iomanip>
#include <set>
#include <functional>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
using namespace std;

#define x first
#define y second
typedef std::pair<int,int> pii; typedef long long ll; typedef unsigned long long ull; typedef unsigned int ui; typedef pair<ui,ui> puu;

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.x >> p.y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template <typename T, typename U> std::ostream&operator<<(std::ostream&o, const pair<T,U>&p) {o << p.x << ' ' << p.y; return o;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {if(t.empty())o<<'\n';for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}
template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxheap = priority_queue<T, vector<T>, less<T>>;
template <typename T> bool in(T a, T b, T c) { return a <= b && b < c; }
ui logceil(int x) { return 8*sizeof(int)-__builtin_clz(x); }

namespace std { template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}}; }
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename F> double bshd(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){l=m;}else{h=m;}}return (l+h)/2;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename F> double bsld(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){h=m;}else{l=m;}}return (l+h)/2;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

template<typename T>class vector2:public vector<vector<T>>{public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}};
template<typename T>class vector3:public vector<vector2<T>>{public:vector3(){} vector3(size_t a,size_t b,size_t c,T t=T()):vector<vector2<T>>(a,vector2<T>(b,c,t)){}};
template<typename T>class vector4:public vector<vector3<T>>{public:vector4(){} vector4(size_t a,size_t b,size_t c,size_t d,T t=T()):vector<vector3<T>>(a,vector3<T>(b,c,d,t)){}};
template<typename T>class vector5:public vector<vector4<T>>{public:vector5(){} vector5(size_t a,size_t b,size_t c,size_t d,size_t e,T t=T()):vector<vector4<T>>(a,vector4<T>(b,c,d,e,t)){}};


#endif
 #ifndef UTIL_H
#define UTIL_H



template <typename T> struct bounded_priority_queue {
	inline bounded_priority_queue(ui X) : A(X), B(0), s(0) {}
	inline void push(ui L, T V) { B = max(B, L); A[L].push(V); ++s; }
	inline const T &top() const { return A[B].front(); }
	inline void pop() { --s; A[B].pop(); while (B > 0 && A[B].empty()) --B; }
	inline bool empty() const { return A[B].empty(); }
	inline void clear() { s = B = 0; for (auto &a: A) a = queue<T>(); }
	inline ui size() const { return s; }
private:
	vector<queue<T>> A; ui B; int s;
};

struct 	UnionFind {
	UnionFind(size_t N) : P(N, -1), comp(N) {}
	int find(int x) { while (P[x]> 0){x = P[x]-1;}return x; }
	bool united(int x, int y) { return find(x) == find(y); }
	bool unite(int x, int y) { x=find(x);y=find(y);if(x==y){return false;}--comp;if(P[x]>P[y]){swap(x,y);}P[x]+=P[y];P[y]= x+1;return true;}
	inline ui size(int u) { return -P[find(u)]; }
	vector<int> P;
	size_t comp;
};


ull mulull(ull a, ull z, ull mod) {
#ifdef __SIZEOF_INT128__
	__int128 result = ((__int128) a * (__int128) z) % (__int128) mod;
	return (ull) result;
#else
    

	ull q = mod / a, r = mod % a;
	ull rzq = (r < q) ? r * (z/q) : mulull(r, z/q, mod);
	ull azq = a * (z % q);
	if (azq >= rzq) return azq-rzq; else return azq-rzq+mod;
#endif
}


pair<ull,ull> mulull(ull a, ull b) {
#ifdef __SIZEOF_INT128__
	__int128 result = (__int128) a * (__int128) b;
	return {(ull) (result >> 64), (ull) result};
#else
	ull c = (ui)a, d = a>>32, e = (ui)b, f = b>>32, g = d*f, h = d*e, i = f*c, j = c*e, k = (j>>32)+(ui)h+(ui)i, l = g+(h>>32)+(i>>32)+(k>>32);
	return {l, ((h+i) << 32) + j};
#endif
}

bool fractionGreaterOrEqual(ll a, ll b, ll c, ll d) {
	if (b < 0) { b = -b; a = -a; }
	if (d < 0) { d = -d; c = -c; }
	return a < 0 && c < 0 ? mulull(-a, d) <= mulull(-c, b) : (a >= 0) && (c < 0 || mulull(a, d) >= mulull(c, b));
}

bool fractionGreaterOrEqual(pair<ll, ll> a, pair<ll, ll> b) {
	return fractionGreaterOrEqual(a.x, a.y, b.x, b.y);
}


bool fractionGreaterOrEqual(double a, double b, double c, double d) {
	return a/b >= c/d;
}




























namespace Envelope {
	template<typename T>
	struct Line {
		T m, b; int id;
		mutable function<const Line<T> *()> succ;

		bool operator<(const Line &rhs) const {
			if (rhs.b != numeric_limits<T>::min()) return m < rhs.m;
			const Line *s = succ();
			if (!s) return 0;
			return b - s->b < (s->m - m) * rhs.m;
		}
	};

	template<typename T>
	struct Upper : public multiset<Envelope::Line<T>> {
		using parent = multiset<Line<T>>;

		bool bad(typename parent::iterator y) {
			auto z = next(y);
			if (y == parent::begin()) {
				return z != parent::end() && y->m == z->m && y->b <= z->b;
			} else {
				auto x = prev(y);
				if (z == parent::end()) {
					return y->m == x->m && y->b <= x->b;
				} else {
					return fractionGreaterOrEqual(x->b - y->b, y->m - x->m, y->b - z->b, z->m - y->m);
				}
			}
		}

		void insert_line(T m, T b, int i = 0) {
			auto y = parent::insert({m, b, i});
			y->succ = [=] { return next(y) == parent::end() ? 0 : &*next(y); };
			if (bad(y)) { parent::erase(y); return; }
			while (next(y) != parent::end() && bad(next(y))) parent::erase(next(y));
			while (y != parent::begin() && bad(prev(y))) parent::erase(prev(y));
		}

		T operator[](T x) const {
			auto l = parent::lower_bound({x, numeric_limits<T>::min()});
			return l == parent::end() ? numeric_limits<T>::min() : l->m * x + l->b;
		}

		int best(T x) const {
			auto l = parent::lower_bound({x, numeric_limits<T>::min()});
			return l == parent::end() ? -1 : l->id;
		}
	};

	

	template<typename T>
	struct Lower : public Upper<T> {
		void insert_line(T m, T b, int i = 0) { Upper<T>::insert_line(-m, -b, i); }
		T operator[](T x) const { return -Upper<T>::operator[](x); }
	};
}


namespace LinearEnvelope {
	template<typename T> struct Line { T m, b; int id; };

	template <typename T>
	struct Upper : public vector<Line<T>> {
		using parent = vector<Line<T>>;
		using parent::at; using parent::back; using parent::size;

		T t; int i;

		Upper() : t(0), i(0) {}

		void clear() {
		    parent::clear();
		    i = 0;
		    t = 0;
		}

		void insert_line(T m, T b, int i = 0) {
			assert(t == 0);
			if (size() > 0 && back().m == m && back().b >= b) return;
			while (size() > 0 && ((back().b < b) || (back().b == b && back().m < m))) parent::pop_back();
			while (size() >= 2 && fractionGreaterOrEqual(at(size()-2).b - back().b, back().m - at(size()-2).m, back().b - b, m - back().m)) parent::pop_back();
			parent::push_back({m,b,i});
		}

		pair<T,int> advance(T x) {
			assert(x >= 0);
			t += x;
			while (i+1 < size() && at(i).m * t + at(i).b < at(i+1).m * t + at(i+1).b) ++i;
			return {at(i).m * t + at(i).b, at(i).id};
		}
	};};

#endif

#ifndef MAJK_DINIC
#define MAJK_DINIC




template<typename T> struct Dinic {
	ui V, E;
	std::vector<ui> LastEdge, EdgeToProcess, BfsDistance, PrevEdge, EdgeTarget;
	std::vector<T> Capacity, Residual;

	Dinic(ui v, ui e = 0) : V(v), E(0), LastEdge(V, ui(-1)), BfsDistance(V), EdgeToProcess(V) {
		Capacity.reserve(2*e);
		Residual.reserve(2*e);
		EdgeTarget.reserve(2*e);
		PrevEdge.reserve(2*e);
	}

	void AddEdge(ui x, ui y, T c1 = 1, T c2 = 0) {


		EdgeTarget.push_back(y);
		Capacity.push_back(c1);
		Residual.push_back(c1);
		PrevEdge.push_back(LastEdge[x]);
		LastEdge[x] = E++;
		EdgeTarget.push_back(x);
		Capacity.push_back(c2);
		Residual.push_back(c2);
		PrevEdge.push_back(LastEdge[y]);
		LastEdge[y] = E++;
	}

	T push(int x, int v, T flow) {
		if (x == v) return flow;
		for (ui &e = EdgeToProcess[x]; e != -1; e = PrevEdge[e]) {
			ui y = EdgeTarget[e];
			if (Residual[e] && BfsDistance[x] + 1 == BfsDistance[y]) {
				if (T f = push(y, v, min(flow, Residual[e]))) {
					Residual[e] -= f;
					Residual[e ^ 1] += f;
					return f;
				}
			}
		}
		return 0;
	}

	T GetMaxFlow(int u, int v) {
		T ret = 0;
		while (true) {
			fill(BfsDistance.begin(), BfsDistance.end(), (ui)-1);
			BfsDistance[u] = 0;
			std::queue<int> Q{{u}};
			while (!Q.empty()) {
				int x = Q.front(); Q.pop();
				for (int e = LastEdge[x]; e != ui(-1); e = PrevEdge[e]) {
					ui y = EdgeTarget[e];
					if (Residual[e] && BfsDistance[y] == ui(-1)) {
						Q.push(y);
						BfsDistance[y] = BfsDistance[x] + 1;
					}
				}

			}

			if (BfsDistance[v] == ui(-1)) break;
			copy(LastEdge.begin(), LastEdge.end(), EdgeToProcess.begin());
			while (T f = push(u, v, std::numeric_limits<T>::max())) ret += f;
		}

		return ret;
	}

	std::vector<bool> GetMinCut(int u) {
		std::queue<int> Q;
		Q.push(u);
		vector<bool> R(V, false);
		R[u] = true;
		while (!Q.empty()) {
			int x = Q.front();
			Q.pop();
			for (int e = LastEdge[x]; e != -1; e = PrevEdge[e]) {
				int y = EdgeTarget[e];
				if (!R[y] && Residual[e] > 0) {
					Q.push(y);
					R[y] = true;
				}
			}
		}
		return R;
	}

	vector<std::tuple<ui, ui, T>> GetEdgesWithFlow() {
		vector<std::tuple<ui, ui, T>> Ans;
		for (ui u = 0; u < V; ++u) {
			for (ui e = LastEdge[u]; e != ui(-1); e = PrevEdge[e]) {
				if (Residual[e] < Capacity[e]) {
					Ans.push_back({u, EdgeTarget[e], Capacity[e] - Residual[e]});
				}
			}
		}
		return Ans;
	};
};


#endif



struct Tree {
	explicit Tree(int N=1) : N(N), logN(logceil(N)), _root(0), E(N) {}
	void addEdge(int u,int v){E[u].push_back(v);E[v].push_back(u);}
	int la(int u, int depth){return _la(u,depth);}
	inline int lca(int u, int v){return _lca(u,v);}
	int parent(int u) { return P[u]; }
	void setRoot(int r) { _root = r; }
	int root() { return _root; }
	const vector<int>& neighbors(int u) const { return E[u]; }
    int depth(int u) { return D[u]; }
	bool isAncestor(int top, int bottom) { return lca(top, bottom) == top; }
	bool sameBranch(int top, int bottom) { int l = lca(top, bottom); return l == top || l == bottom; }

	int _la(int u, int d)const{for(int i=0;i<logN&&u!=-1;++i){if(d&(1<<i))u=PP[i][u];}return u;}
	int _lca(int u, int v) { if(D[u]<D[v]){swap(u,v);} u=_la(u,D[u]-D[v]);
		for(int i=logN-1;i>=0;--i)if(PP[i][u]!=PP[i][v]){u=PP[i][u];v=PP[i][v];}
		return u==v?u:PP[0][v];
	}
	inline void calcParents(){if(P.size()==0){P.resize(N);D.resize(N);dfs(_root,-1,0);}}
	void dfs(int u,int v,int d){P[u]=v;D[u]=d;for(int w:E[u])if(v!=w)dfs(w,u,d+1);}
	inline void calcLA(){calcParents();if(PP.size()==0){PP=vector2<int>(logN,N,-1);for(int i=0;i<N;++i){PP[0][i]=P[i];}
			for(int i=1;i<logN;++i)for(int j=0;j<N;++j)if(PP[i-1][j]!=-1)PP[i][j]=PP[i-1][PP[i-1][j]];}}
	int N,logN,_root; vector<vector<int>> E;vector<int> P,D;vector2<int>PP;
};



struct Bipartite {
	explicit Bipartite(ui A, ui B) : A(A), B(B), N(A+B), ms(-1), H(N,-1), used(A) {}
	void addEdge(int u,int v){G.push_back(v);P.push_back(H[u]);H[u]=(ui)G.size()-1;}
	ui matchingSize(){calcMatching();return ms;}
	int matched(int v){calcMatching();return M[v];}
	vector<int>cover(){calcCover();vector<int>C;for(int i=0;i<N;++i){if(Z[i]!=(i<A))C.push_back(i);}return C;}
	vector<int>indep(){calcCover();vector<int>I;for(int i=0;i<N;++i){if(Z[i]==(i<A))I.push_back(i);}return I;}
private:
	void konigDfs(int u){
        if(Z[u]){return;}
        Z[u]=true;
        if(u<A){
            for (ui p = H[u]; p != -1; p = P[p]) {
                ui v = G[p];
                if (v != M[u])konigDfs(v);
            }
        }
        else if(M[u]!=-1)
            konigDfs(M[u]);
    }
    bool matchingDfs(int u) {
        if (used[u]) return false;
        used[u] = true;

        for (ui p = H[u]; p != -1; p = P[p]) {
            ui v = G[p];
            if (M[v]==-1) { M[u] = v; M[v] = u; ++ms; return true; }
        }

        for (ui p = H[u]; p != -1; p = P[p]) {
            ui v = G[p];
            if (matchingDfs(M[v])) { M[u] = v; M[v] = u; return true; }
        }
        return false;

    }
	inline void calcMatching(){
        if(ms!=-1){return;}
        M = vector<ui>(N,-1);
        size_t cur; ms = 0;
        do {
            cur = ms;
            for(int i=0;i<A;++i) used[i] = false;
            for(int i=0;i<A;++i) if(M[i]==-1) matchingDfs(i);
        } while(cur != ms);
    }
	inline void calcCover(){if(Z.size()==N){return;}calcMatching();Z=vector<bool>(N,false);for(int i=0;i<A;++i)if(M[i]==-1)konigDfs(i);}
	ui N,A,B,ms;vector<ui>M,H,G,P;vector<bool>Z,used;
};

struct DirectedGraph {
	explicit DirectedGraph(int N) : N(N), E(N) {}
	void addEdge(int u,int v){E[u].push_back({v});}
	int stronglyConnectedComponent(int v){calcStronglyConnectedComponents();return SCC[v];}
	bool stronglyConnected(int u,int v){calcStronglyConnectedComponents();return SCC[u]==SCC[v];}
	const vector<int>& stronglyConnectedPermutation() {calcStronglyConnectedComponents(); return O;}


	inline void calcReverseEdges(){if(ER.size()==N){return;}ER.resize(N);for(int i=0;i<N;++i)for(int u:E[i])ER[u].push_back(i);}
	inline void calcStronglyConnectedComponents(){
		if(SCC.size()==N){return;}SCC.resize(N);O.resize(N);calcReverseEdges();
		vector<bool>V(N,false);vector<int>F(N,0);int t=0;for(int i=N-1;i>=0;i--){if(!V[i]){dfsReverse(i,V,F,t);}O[N-1-F[i]] = i;}
		fill(V.begin(),V.end(),false);for(int i=0;i<N;i++){if(!V[O[i]])dfsForward(O[i],O[i],V);}
	}
	void dfsForward(int i,int p,vector<bool>&V){V[i]=true;SCC[i]=p;for(int v:E[i])if(!V[v])dfsForward(v,p,V);}
	void dfsReverse(int i,vector<bool>&V,vector<int>&F,int&t){V[i]=true;for(int v:ER[i]){if(!V[v])dfsReverse(v,V,F,t);}F[i] = t++;}
	int N; vector<vector<int>>E,ER;vector<int>SCC,O;
};

struct TwoSat {
	explicit TwoSat(int N=0) : N(N), G(2*N) {}
	void forbid(int u,bool w){G.addEdge(u+N*(1-w),u+N*w);}
	void addClause(int u,bool w,int v,bool x){G.addEdge(u+N*w,v+N*(1-x));G.addEdge(v+N*x,u+N*(1-w));}
	bool satisfiable() {calculateAssignment();return ok;}
	const vector<int>& assignment() {calculateAssignment();return A;}


	inline void calculateAssignment(){if(A.size()==N){return;}A.resize(N);ok=true;map<int,bool>Q;
		for(int u:G.stronglyConnectedPermutation()){
			int c1=G.stronglyConnectedComponent(u),c2=G.stronglyConnectedComponent((u+N)%(2*N));
			if(c1==c2){ok=false;return;}if(Q.find(c1)==Q.end()){Q[c1]=true;Q[c2]=false;}}
		for(int i=0;i<N;++i){A[i]=Q[G.stronglyConnectedComponent(i)];}
	}
	int N; DirectedGraph G;vector<int>A;bool ok;
};

class TaskF {
public:
    Tree T;
    vector<vector<int>> W;
    unordered_set<pii> Bad;
    bool inf;

    ll calc(int u, map<int,int> &cur) {
        ll ans = 0;
        for (int v:T.E[u]) {
            if (v != T.P[u]) {
                map<int,int> Z;
                ans += calc(v, Z);
                if (Z.size() > cur.size()) swap(Z, cur);
                for (pii z:Z) cur[z.x] += z.y;
            }
        }

        for (int w:W[u]) {
            if (w > 0) {
                cur[w]++;
            } else {
                auto it = cur.find(-w);
                it->y -= 2;
                if (it->y == 0) cur.erase(it);
            }
        }


        if (u != 0 && Bad.find({u,T.P[u]}) == Bad.end()) {
            if (cur.empty()) inf = true;
            else ans += cur.begin()->x;
        }
        return ans;
    }

void solve(istream& cin, ostream& cout) {
    int N, M, K; cin >> N >> K >> M;

    W.resize(N);
    T = Tree(N);

    UnionFind UT(N);
    for (int i = 0; i < K; ++i) {
        int a,b; cin >> a >> b;
        --a; --b;
        UT.unite(a,b);
        T.addEdge(a,b);
    }

    vector<pair<pii,int>> E(M);
    for (int i = 0; i < M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a;
        --b;
        if (UT.unite(a, b)) {
            T.addEdge(a, b);
            

            Bad.insert({b,a});
            Bad.insert({a,b});
        }
        E[i] = {{a,b}, w};
    };

    T.calcLA();
    UnionFind UF(N);
    for (int i = 0; i < M; ++i) {
        int a = E[i].x.x;
        int b = E[i].x.y;
        int w = E[i].y;
        if (UF.unite(a,b) && Bad.find({a,b}) == Bad.end()) {
            W[a].push_back(w);
            W[b].push_back(w);
            W[T.lca(a,b)].push_back(-w);
        }
    }

    inf = false;
    map<int,int> Q;
    ll ans = calc(0, Q);
    if (inf) cout << -1 << '\n'; else cout << ans << '\n';
}
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	TaskF solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}