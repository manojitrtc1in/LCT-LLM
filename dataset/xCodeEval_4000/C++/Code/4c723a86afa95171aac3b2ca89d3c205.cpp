

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
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cmath>
#include <string>
#include <queue>
#include <array>
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
ui logceil(ll x) { return x?8*sizeof(ll)-__builtin_clzll(x):0; }

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


struct Graph {
    explicit Graph(const vector<vector<int>> &E):E(E),N(E.size()) {}

    void prep_dfs(){D=P=vector<int>(N,0);T=0;}
    void bridges(vector<pii>&br){prep_dfs();for(int i=0;i<N;i++)if(!D[i])_bridge_dfs(br,i);}
    int _bridge_dfs(vector<pii>&br,int u){
        int top=D[u]=++T;
        for(int v:E[u]) {
            if(!D[v]){
                P[v]=u;
                int up=_bridge_dfs(br, v);
                top=min(top,up);
                if(up>D[u])br.push_back({u,v});
            }else if(P[u]!=v)top=min(top, D[v]);
        }
        return top;
    }

    bool bicon(const function<bool(vector<pii>::iterator,vector<pii>::iterator)> &f) {
        prep_dfs();vector<pii> s;
        for(int i=0;i<N;i++) {
            if(D[i])continue;
            if (_bicon_dfs(i,s,f)==-1) return true;
            if(!s.empty()){
                if (f(s.begin(),s.end())) return true;
                s.erase(s.begin(),s.end());
            }
        }
        return false;
    }
    int _bicon_dfs(int u,vector<pii>&s,const function<bool(vector<pii>::iterator,vector<pii>::iterator)> &f){
        int c=0,top=D[u]=++T;
        for(int v:E[u]) {
            if(!D[v]){
                P[v]=u;
                int r = s.size();
                s.push_back({u,v});
                int up=_bicon_dfs(v, s, f);
                if (up == -1) return -1;
                top=min(top,up);
                if((D[u]==1&&++c>1)||(D[u]!=1&&up>=D[u])){
                    if(f(s.begin()+r,s.end())) return -1;
                    s.erase(s.begin()+r,s.end());
                }
            }else if(P[u]!=v){top=min(top,D[v]);if(D[v]<D[u])s.push_back({u,v});}
        }
        return top;
    }

    void artic(vector<bool>&art){prep_dfs();for(int i=0;i<N;i++)if(!D[i])_artic_dfs(art,i);}
    int _artic_dfs(vector<bool>&art,int u){
        int top=D[u]=++T,c=0;art[u]=false;
        for(int v:E[u]) {
            if(!D[v]){
                P[v]=u;
                int up=_artic_dfs(art, v);
                top=min(top,up);
                if((D[u]==1&&++c>1)||(D[u]!=-1&&up>=D[u]))art[u]=true;
            }else if(P[u]!=v)top=min(top,D[v]);
        }
        return top;
    }
    const vector<vector<int>>&E;int N,T;
    vector<int>P,D;
};


struct TreeX {
	explicit TreeX(int N=1) : N(N), logN(logceil(N)), _root(0), E(N) {}
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

template <typename EdgeType>
class DFSOrder {
public:
    DFSOrder(const vector<vector<EdgeType>> &_E) : T(0), N(_E.size()), E(_E), RevEnter(N), Enter(N), Exit(N) {
        dfs(0, -1);
    }

    vector<vector<EdgeType>> linearize() {
        vector<vector<EdgeType>> F(N);
        for (int i = 0; i < N; ++i) {
            for (auto v:E[i]) {
                F[conv(i)].push_back(conv(v));
            }
        }
        return F;
    }

    void dfs(int u, int p) {
        RevEnter[T] = u;
        Enter[u] = T++;
        for (auto v:E[u]) if (t(v) != p) dfs(t(v), u);
        Exit[u] = T;
    }

    inline int t(const int&e) const { return e; }
    template <typename U> inline int t(const pair<int, U>&e) const { return e.x; }

    inline int conv(const int&e) const { return Enter[e]; }
    template <typename U> inline pair<int, U> conv(const pair<int, U>&e) const { return {Enter[e.x], e.y}; }

    const vector<int> &revEnter() const { return RevEnter; }
    const vector<int> &enter() const { return Enter; }
    const vector<int> &exit() const { return Exit; }

    int T, N;
    const vector<vector<EdgeType>> &E;
    vector<int> Enter, Exit, RevEnter;
};


template <typename EdgeType>
class CentroidDecomposition {
public:
    CentroidDecomposition(const vector<vector<EdgeType>> &E) : E(E) {}

    const vector<int>& findCentroids() {
        DFSOrder<EdgeType> DFS(E);
        auto EF = DFS.linearize();

        N = E.size(); U.assign(N, -1);
        int L = 0;

        for (int j = 0; j < N; ) {
            for (int i = N-1; i >= 0; --i) {
                if (U[i] >= 0) continue;

                U[i] = -1;
                bool root = true;
                for (auto v:EF[i]) {
                    if (U[t(v)]<0) {
                        if (t(v) > i) U[i] += U[t(v)];
                        else root = false;
                    }
                }

                if (root) {
                    int n = -U[i], u = i, p = -1;
                    while (true) {
                        int s = n + U[u];
                        for (auto v:EF[u]) if (t(v)!=p && U[t(v)] < 0) s = max(s, -U[t(v)]);
                        if (2 * s <= n) { U[u] = j++; break; }
                        else { for (auto v:EF[u]) if (t(v)!=p && -U[t(v)] > n / 2) { p = u;u = t(v);break; } }
                    }
                }
            }
        }
        vector<int> Ans(N);
        for (int i = 0; i < N; ++i) Ans[i] = U[DFS.enter()[i]];
        swap(Ans, U);
        return U;
    }

    inline int t(const int&e) const { return e; }
    template <typename U> inline int t(const pair<int, U>&e) const { return e.x; }

    int N;
    const vector<vector<EdgeType>> &E;
    vector<int> U;
};




struct Bipartite {
	explicit Bipartite(ui A, ui B) : A(A), B(B), N(A+B), ms(-1), H(N,-1), used(A) {}
	void addEdge(int u,int v){G.push_back(v);P.push_back(H[u]);H[u]=(ui)G.size()-1;}
	ui matchingSize(){calcMatching();return ms;}
	int matched(int v){calcMatching();return M[v];}
	vector<int>cover(){calcCover();vector<int>C;for(int i=0;i<N;++i){if(Z[i]!=(i<A))C.push_back(i);}return C;}
	vector<int>indep(){calcCover();vector<int>I;for(int i=0;i<N;++i){if(Z[i]==(i<A))I.push_back(i);}return I;}


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
	int N;
	vector<int> val; vector<char> valid;
	vector<vector<int>> G;

	TwoSat(int N) : N(N), val(2*N), G(2*N) {}
	void addImplication(int a, bool w, int b, bool x) { G[2*a+w].push_back(2*b+x); }
	void addOr(int a, bool w, int b, bool x) { addImplication(a, !w, b, x); addImplication(b, !x, a, w); }
	void addTrue(int x) { addImplication(x, false, x, true); }
    void addFalse(int x) { addImplication(x, true, x, false); }
	int time() { return valid.size()-1; }
	bool dfs(int x) {
		if(valid[abs(val[x])]) return val[x]>0;
		val[x] = time();
		val[x^1] = -time();
		for(int e:G[x]) if(!dfs(e)) return false;
		return true;
	}

	bool value(int i) const { return val[2*i]<0; }

	bool solve() {
		fill(val.begin(), val.end(), 0);
		valid.assign(1, 0);
		for(int i=0; i<val.size(); i+=2) {
			if(!valid[abs(val[i])]) {
				valid.push_back(1);
				if(!dfs(i)) {
					valid.back()=0;
					valid.push_back(1);
					if(!dfs(i+1)) return false;
				}
			}
		}
		return true;
	}
};

class EHappyCactus {
public:
    vector<vector<int>> cycles(vector<vector<int>> &E) {
        int N = E.size();
        vector<int> Processed(N, 0);
        vector<bool> Active(N, false);
        vector<vector<int>> Ans;
        for (int i = 0; i < N; ++i) {
            if (Processed[i] == E[i].size()) continue;
            vector<int> Stack{i};
            Active[i] = true;
            while (!Stack.empty()) {
                int u = Stack.back();
                if (Processed[u] == E[u].size()) {
                    Active[u] = false;
                    Stack.pop_back();
                } else {
                    int v = E[u][Processed[u]];
                    Processed[u]++;
                    if (Active[v]) {
                        if (Stack[Stack.size()-2] == v) continue;

                        Ans.push_back({v});
                        while (Stack.back() != v) {
                            Ans.back().push_back(Stack.back());
                            Active[Stack.back()] = false;
                            Stack.pop_back();
                        }
                    } else {
                        Stack.push_back(v);
                        Active[v] = true;
                    }
                }
            }
        }
        return Ans;
    }

    pii ed(int a, int b) { return {min(a,b), max(a,b)}; }

    void solve(istream& cin, ostream& cout) {
        int N, M; cin >> N >> M;
        vector<pii> E(M); cin >> E;
        vector<vector<int>> F(N);
        for (pii &e:E) {
            e.x--;
            e.y--;
            if (e.x > e.y) swap(e.x, e.y);
            F[e.x].push_back(e.y);
            F[e.y].push_back(e.x);
        }

        auto Cyc = cycles(F);

        map<pii, int> ID;
        for (int i = 0; i < M; ++i) ID[E[i]] = i;

        vector<bool> Visited(N, false);
        vector<int> OppositeEdge(M, -1);
        for (auto&cyc: Cyc) {
            int W = cyc.size();
            pii lo = {ID[ed(cyc[0],cyc[W-1])], W-1};
            for (int i = 0; i < W-1; ++i) {
                lo = min(lo, {ID[ed(cyc[i],cyc[i+1])], i});
            }

            auto search = [&](int u, int diff, int edgeId) {
                while (true) {
                    int v = u+diff;
                    v = v==W?0:v;
                    v = v==-1?W-1:v;
                    int a = cyc[u], b = cyc[v];
                    if (ID[ed(a,b)] > edgeId) {
                        edgeId = ID[ed(a,b)];
                        u = v;
                    } else return edgeId;
                }
            };
            auto first = search(lo.y, -1, lo.x);
            auto second = search((lo.y+1)%W, 1, lo.x);

            if (first == second) OppositeEdge[lo.x] = first;
        }

        vector<int> H(N, 1), Sum(M, 0);
        for (int i = M-1; i >= 0; --i) {
            int a = E[i].x, b = E[i].y;
            int q = H[a] + H[b];
            if (OppositeEdge[i] != -1) q -= Sum[OppositeEdge[i]];
            H[a] = H[b] = Sum[i] = q;
        }

        for (int &h: H) --h;
        cout << H;
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	EHappyCactus solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}