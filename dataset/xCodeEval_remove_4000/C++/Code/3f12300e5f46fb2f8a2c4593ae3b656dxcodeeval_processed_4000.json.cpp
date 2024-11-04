



using namespace std;
using ld = long double;
const ld eps = 1e-9;








































































































































































































































































const int mod = 1000000007;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
		static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
	}
	Mod(int n) : Mod(static_cast<long long int>(n)) { ; }
	operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int  b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod mod_pow(const Mod a, const long long  int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}



Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
	return Mod(a) / b;
}
Mod operator/=(Mod &a, const Mod b) {
	return a = a / b;
}



Mod fact[id2], factinv[id2];
void init(const int amax = id2) {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < amax - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}

vector<int>primes;
void hurui(const int amax=3500) {
	static bool flag = false;
	if (flag)return;
	vector<int>sos;
	sos = vector<int>(amax + 1, true);
	sos[0] = false; sos[1] = false;
	for (int i = 2; i <= amax; ++i) {
		if (sos[i]) {
			for (int j = 2 * i; j <= amax; j += i)sos[j] = false;
		}
	}
	for (int i = 0; i <= amax; ++i) {
		if (sos[i]) {
			primes.push_back(i);
		}
	}
	flag = true;
}


struct query {
	int u;
	int v;
	map<int,int>mp;
};

map<int, int>mk_mp(const int a) {
	int rest(a);
	map<int,int>as;
	for (auto pr : primes) {
		while (rest%pr == 0) {
			as[pr]++;
			rest /= pr;
		}
	}
	if (rest!=1)as[rest]++;
	return as;
}



class Tree {
public:
	Tree(int V, int root) : V(V), root(root), cnum(V), place(V), id(V) {
		T.resize(V);
		for (int i = 0; i < MAXLOGV; i++) {
			parent[i].resize(V);
		}
		depth.resize(V);
	}
	

	

	void unite(int u, int v) {
		T[u].push_back(v);
		T[v].push_back(u);
	}
	void unite(vector<vector<int>>&e) {
		T = e;
	}
	

	

	void init() {
		dfs(root, 0, 0);
		int id = 0;
		getid(root, 0, id);
	}
	

	int lca(int u, int v) const {
		if (depth[u] > depth[v]) swap(u, v);
		for (int k = 0; k < MAXLOGV; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[k][v];
			}
		}
		if (u == v) return u;
		for (int k = MAXLOGV - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
	

	

	int dist(int u, int v) const {
		int p = lca(u, v);
		return (depth[u] - depth[p]) + (depth[v] - depth[p]);
	}
	int dfs(int v, int p, int d) {
		parent[0][v] = p;
		depth[v] = d;
		cnum[v] = 0;
		for (int i = 1; i < MAXLOGV; i++) {
			parent[i][v] = parent[i - 1][parent[i - 1][v]];
		}
		for (int next : T[v]) {
			if (next != p) cnum[v] += dfs(next, v, d + 1);
		}
		return cnum[v] + 1;
	}

	void dfs2(int v, int p, vector<vector<int>>&doubles, const vector<int>&nums) {
		for (int next : T[v]) {
			if (next != p) dfs2(next, v, doubles, nums);
		}
		doubles[0][v] = nums[v];
		for (int j = 1; j < MAXLOGV; ++j) {
			doubles[j][v] = min(doubles[j][v], doubles[j - 1][v]);
		}
		for (int j = 0; j < MAXLOGV - 1; ++j) {
			doubles[j + 1][parent[j][v]] = min(doubles[j + 1][parent[j][v]], doubles[j][v]);
		}
	}
	

	vector<vector<int>>get_doubles(const vector<int>&nums) {
		vector<vector<int>>doubles(MAXLOGV, vector<int>(V, 1e9));
		dfs2(root, -1, doubles, nums);
		return doubles;
	}

	void getid(const int v, const int p, int &nplace) {
		place[v] = nplace;
		id[nplace] = v;
		nplace++;
		for (int next : T[v]) {
			if (next != p) getid(next, v, nplace);
		}
	}
	static const int MAXLOGV = 25;
	

	vector<vector<int> > T;
	

	int V;
	

	int root;

	

	vector<int> parent[MAXLOGV];
	

	vector<int> depth;

	

	vector<int>cnum;

	

	vector<int>place;
	vector<int>id;

};

vector<int>pas;
void adfs(vector<pair<int, int>>&lrs, vector<int>&tos,const vector<vector<int>>&edges, const int now, const int from,int &id) {
	tos[now]=id;
	lrs[tos[now]].first=id++;
	for (auto e : edges[now]) {
		if (e == from) {
			pas[now] = from;
			continue;
		}
		adfs(lrs,tos,edges,e,now,id);
	}
	lrs[tos[now]].second=id;
}

vector<pair<int, int>>id1(vector<int>&tos,const vector<vector<int>>&edges, const int root) {
	pas.resize(tos.size());pas[0]=-1;
	vector<pair<int,int>>lrs(edges.size());
	int id=0;
	adfs(lrs,tos,edges,0,-1,id);
	return lrs;
}

typedef int Value1;
typedef pair<bool, int>Value2;
const Value1 Zero1(0);
const Value2 Zero2(make_pair(true, 0));

struct Node {
	Value1 sum;

	Value2 lazy;	

	Node() :sum(Zero1) {
		lazy = Zero2;
	}
};
struct id0 {
	int N;
	vector<Node>dat;
	id0(int n) :N(1) {
		while (N < n) N *= 2;
		dat.resize(2 * N);
	}

	Value2 lazy_connect(const Value2 l, const Value2 r) {
		int n=l.first*r.first;
		int m=l.second*r.first+r.second;
		return make_pair(n,m);
	}

	void lazy_func(const int k, const int a, const int b) {
		if (!dat[k].lazy.first)dat[k].sum = dat[k].lazy.second;
		else {
			dat[k].sum += dat[k].lazy.second*(b - a);
		}
	}

	Value1 connect(const Value1 l, const Value1 r) {
		return l + r;

	}

	

	inline void lazy_evaluate_node(int k, int a, int b) {
		lazy_func(k, a, b);
		if (k < N) { 

			dat[2 * k].lazy = lazy_connect(dat[2 * k].lazy, dat[k].lazy);	

			dat[2 * k + 1].lazy = lazy_connect(dat[2 * k + 1].lazy, dat[k].lazy);
		}
		dat[k].lazy = Zero2;
	}

	inline void update_node(int k) { 

		dat[k].sum = connect(dat[2 * k].sum, dat[2 * k + 1].sum);

	}

	

	void update(int l, int r, Value2 v, int k = 1, int a = 0, int b = -1) {
		if (b == -1)b = N;
		if (l < 0 || r < 0)assert(false);
		lazy_evaluate_node(k, a, b); 	


		if (b <= l || r <= a) 

			return;
		if (l <= a && b <= r) { 

			dat[k].lazy = lazy_connect(dat[k].lazy, v);
			lazy_evaluate_node(k, a, b); 

			return;
		}

		int m = (a + b) / 2;
		update(l, r, v, 2 * k, a, m);
		update(l, r, v, 2 * k + 1, m, b);
		update_node(k);
	}
	

	Value1 get(int l, int r, int k = 1, int a = 0, int b = -1) {
		if (b == -1)b = N;

		if (l < 0 || r<0)assert(false);
		lazy_evaluate_node(k, a, b); 


		if (b <= l || r <= a) 

			return Zero1;

		if (l <= a && b <= r) { 

			return dat[k].sum;
		}

		int m = (a + b) / 2;
		Value1 vl = get(l, r, 2 * k, a, m);
		Value1 vr = get(l, r, 2 * k + 1, m, b);
		update_node(k);
		return connect(vl, vr);
	}
};

int main()
{
	hurui();
	int N;cin>>N;
	vector<vector<int>>edges(N);
	for (int i = 0; i < N - 1; ++i) {
		int a,b;scanf("%d %d",&a,&b);
		a--;b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	vector<int>tos(N);
	
	vector<pair<int,int>>lrs(N);
	lrs=id1(tos,edges,0);
	vector<map<int,int>>as(N);

	map<int, vector<vector<pair<bool, int>>>>id3;

	for (int i = 0; i < N; ++i) {
		int a;scanf("%d",&a);
		as[i]=mk_mp(a);
		auto x=as[i];
		for (auto m : x) {
			id3[m.first].resize(30);
			for (int k = 1; k <= m.second; ++k) {
				id3[m.first][k].push_back(make_pair(false, i));
			}
		}
	}
	Tree tree(N,0);
	tree.unite(edges);
	tree.init();
	int Q;cin>>Q;
	vector<query>qs(Q);

	for (int i = 0; i < Q; ++i) {
		int u,v,w;scanf("%d %d %d",&u,&v,&w);
		u--;v--;
		auto x=mk_mp(w);
		for (auto m : x) {
			id3[m.first].resize(30);
			for (int k = m.second; k <= m.second; ++k) {
				id3[m.first][k].push_back(make_pair(true,i));
			}
		}
		qs[i] = query{ u,v,mk_mp(w) };
	}

	vector<Mod>anss(Q,1);

	id0 seg(N);

	for (auto& m : id3) {
		seg.update(0,N,make_pair(false,0));
		const int prime=m.first;
		for (int k = 1; k < 30; ++k) {
			auto v(m.second[k]);
			sort(v.begin(), v.end());
			for (auto n : v) {
				bool  is_q=n.first;
				int id=n.second;

				if (is_q) {
					int u=qs[id].u;

					int v=qs[id].v;

					int t=tree.lca(u,v);
					int num=seg.get(tos[u],tos[u]+1)+seg.get(tos[v],tos[v]+1)-seg.get(tos[t],tos[t]+1);
					if (pas[t] == -1) {
						
					}
					else {
						num-=seg.get(tos[pas[t]],tos[pas[t]]+1);
					}
					anss[id]=anss[id]*mod_pow(m.first,num);
				}
				else {
					int l=lrs[tos[id]].first;
					int r=lrs[tos[id]].second;
					seg.update(l,r,make_pair(true,1));
				}
			}
		}
	}
	for (int i = 0; i < Q; ++i) {
		cout<<anss[i].num<<endl;
	}
	return 0;
}