#include<stdio.h>
#include<stdlib.h>

#define ll long long
#define ull unsigned long long
#define rep(i,m,n) for(ll (i)=(ll)(m);i<(ll)(n);i++)
#define REP(i,n) rep(i,0,n)
#define all(hoge) (hoge).begin(),(hoge).end()
typedef struct { ll first, second; } P;


#define m_pi 3.1415926535897932L
#define MOD 1000000007
#define INF (1LL << 61)
#define EPS 1e-10
typedef int bool;
#define true 1
#define false 0

typedef struct {
	int to, rev; ll cap;
} Edge;

typedef struct {
	Edge* edges;
	int size;
} Edges;

typedef struct {
	Edges* graph;
	int size;
} Graph;

void add_edge(Graph* G, int from, int to, ll cap, bool revFlag, ll revCap) {
	Edges* edges = &(G->graph[from]);
	edges->edges = (Edge*)realloc(edges->edges, (edges->size + 1) * sizeof(Edge));
	Edge edge;
	edge.to = to;
	edge.cap = cap;
	edge.rev = edges->size + (from == to);
	edges->edges[edges->size] = edge;
	edges->size++;

	if (revFlag) {
		Edges* revEdges = &(G->graph[to]);
		revEdges->edges = (Edge*)realloc(revEdges->edges, (revEdges->size + 1) * sizeof(Edge));
		Edge revEdge;
		revEdge.to = from;
		revEdge.cap = revCap;
		revEdge.rev = revEdges->size - 1;
		revEdges->edges[revEdges->size] = revEdge;
		revEdges->size++;
	}
}

ll max_flow_dfs(Graph* G, ll v, ll t, ll f, bool* used) {
	if (v == t)
		return f;
	used[v] = true;
	Edges edges = G->graph[v];
	for (int i = 0; i < edges.size; ++i) {
		Edge e = edges.edges[i];
		if (!used[e.to] && e.cap > 0) {
			ll d = max_flow_dfs(G, e.to, t, f < e.cap ? f : e.cap, used);
			if (d > 0) {
				e.cap -= d;
				G->graph[e.to].edges[e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

ll max_flow(Graph* G, ll s, ll t) {
	ll flow = 0;
	for (;;) {
		bool* used = (bool*)calloc(G->size, sizeof(bool));
		ll f = max_flow_dfs(G, s, t, INF, used);
		if (f == 0) {
			return flow;
		}
		flow += f;
		free(used);
	}
}

void BellmanFord(Graph* G, ll s, ll* d, bool* negative) {
	*d = (ll*)realloc(*d, G->size * sizeof(ll));
	*negative = (bool*)realloc(*negative, G->size * sizeof(bool));
	REP(i, G->size) {
		(*d)[i] = INF;
		(*negative)[i] = false;
	}
	(*d)[s] = 0;
	REP(k, G->size - 1) {
		REP(i, G->size) {
			Edges edges = G->graph[i];
			REP(j, edges.size) {
				Edge e = edges.edges[j];
				if ((*d)[i] != INF && (*d)[e.to] > (*d)[i] + e.cap) {
					(*d)[e.to] = (*d)[i] + e.cap;
				}
			}
		}
	}
	REP(k, G->size - 1) {
		REP(i, G->size) {
			Edges edges = G->graph[i];
			REP(j, edges.size) {
				Edge e = edges.edges[j];
				if ((*d)[i] != INF && (*d)[e.to] > (*d)[i] + e.cap) {
					(*d)[e.to] = (*d)[i] + e.cap;
					(*negative)[e.to] = true;
				}
				if ((*negative)[i] == true) (*negative)[e.to] = true;
			}
		}
	}
}

void Dijkstra(Graph* G, ll s, ll* d) {
	*d = (ll*)realloc(*d, G->size * sizeof(ll));
	REP(i, G->size) {
		(*d)[i] = INF;
	}
	(*d)[s] = 0;
	P* q = (P*)malloc(sizeof(P));
	int qSize = 0;
	P a;
	a.first = 0;
	a.second = s;
	q[qSize] = a;
	qSize++;
	while (qSize > 0) {
		P a = q[0];
		qSize--;
		for (int i = 0; i < qSize; i++) {
			q[i] = q[i + 1];
		}
		if ((*d)[a.second] < a.first)continue;
		Edges edges = G->graph[a.second];
		REP(i, edges.size) {
			Edge e = edges.edges[i];
			if ((*d)[e.to] > (*d)[a.second] + e.cap) {
				(*d)[e.to] = (*d)[a.second] + e.cap;
				P b;
				b.first = (*d)[e.to];
				b.second = e.to;
				q[qSize] = b;
				qSize++;
			}
		}
	}
	free(q);
}

void WarshallFloyd(Graph* G, ll** d) {
	*d = (ll**)realloc(*d, G->size * sizeof(ll*));
	REP(i, G->size) {
		(*d)[i] = (ll*)realloc((*d)[i], G->size * sizeof(ll));
	}
	REP(i, G->size) {
		REP(j, G->size) {
			(*d)[i][j] = ((i != j) ? INF : 0);
		}
	}
	REP(i, G->size) {
		Edges edges = G->graph[i];
		REP(j, edges.size) {
			Edge e = edges.edges[j];
			if ((*d)[i][e.to] != INF && (*d)[e.to][j] > (*d)[i][j] + e.cap) {
				(*d)[i][e.to] = (*d)[i][j] + e.cap;
			}
		}
	}
	REP(i, G->size) {
		REP(j, G->size) {
			REP(k, G->size) {
				if ((*d)[j][i] != INF && (*d)[i][k] != INF) {
					if ((*d)[j][k] > (*d)[j][i] + (*d)[i][k]) {
						(*d)[j][k] = (*d)[j][i] + (*d)[i][k];
					}
				}
			}
		}
	}
}

bool tsort(Graph* graph, int* order) {
	int n = graph->size, k = 0;
	int* in = (int*)calloc(n, sizeof(int));
	REP(i, n) {
		Edges edges = graph->graph[i];
		REP(j, edges.size) {
			Edge e = edges.edges[j];
			in[e.to]++;
		}
	}
	int* que = (int*)malloc(n * sizeof(int));
	int queSize = 0;
	REP(i, n) {
		if (in[i] == 0) {
			que[queSize] = i;
			queSize++;
		}
	}
	while (queSize > 0) {
		int v = que[0];
		queSize--;
		for (int i = 0; i < queSize; i++) {
			que[i] = que[i + 1];
		}
		order[k] = v;
		k++;
		Edges edges = graph->graph[v];
		REP(i, edges.size) {
			Edge e = edges.edges[i];
			in[e.to]--;
			if (in[e.to] == 0) {
				que[queSize] = e.to;
				queSize++;
			}
		}
	}
	free(in);
	free(que);
	if (k != n) return false;
	else return true;
}

typedef struct {
	int n;
	int log2_n;
	int** parent;
	int* depth;
} Lca;

Lca* new_Lca() {
	Lca* lca = (Lca*)malloc(sizeof(Lca));
	lca->n = 0;
	lca->log2_n = 0;
	lca->parent = NULL;
	lca->depth = NULL;
	return lca;
}

void Lca_init(Lca* lca, Graph* g, int root) {
	lca->n = g->size;
	lca->log2_n = log2(lca->n) + 1;
	lca->parent = (int**)realloc(lca->parent, lca->log2_n * sizeof(int*));
	REP(k, lca->log2_n) {
		lca->parent[k] = (int*)realloc(lca->parent[k], lca->n * sizeof(int));
	}
	lca->depth = (int*)realloc(lca->depth, lca->n * sizeof(int));
	Lca_dfs(g, lca, root, -1, 0);
	REP(k, lca->log2_n - 1) {
		REP(v, g->size) {
			if (lca->parent[k][v] < 0)
				lca->parent[k + 1][v] = -1;
			else
				lca->parent[k + 1][v] = lca->parent[k][lca->parent[k][v]];
		}
	}
}

void Lca_dfs(Graph* g, Lca* lca, int v, int p, int d) {
	lca->parent[0][v] = p;
	lca->depth[v] = d;
	Edges edges = g->graph[v];
	REP(i, edges.size) {
		Edge e = edges.edges[i];
		if (e.to != p) Lca_dfs(g, lca, e.to, v, d + 1);
	}
}

int Lca_get(Lca* lca, int u, int v) {
	if (lca->depth[u] > lca->depth[v]) {
		int tmp = u;
		u = v;
		v = tmp;
	}
	REP(k, lca->log2_n) {
		if ((lca->depth[v] - lca->depth[u]) >> k & 1) {
			v = lca->parent[k][v];
		}
	}
	if (u == v) return u;
	REP(k, lca->log2_n - 1) {
		if (lca->parent[k][u] != lca->parent[k][v]) {
			u = lca->parent[k][u];
			v = lca->parent[k][v];
		}
	}
	return lca->parent[0][u];
}

typedef struct {
	int* data;
	int n;
} UnionFind;

UnionFind* new_UnionFind(int size) {
	UnionFind* uf = (UnionFind*)malloc(sizeof(UnionFind));
	uf->data = (int*)calloc(size, sizeof(int));
	uf->n = size;
	return uf;
}

bool UnionFind_merge(UnionFind* uf, int x, int y) {
	x = UnionFind_root(uf, x);
	y = UnionFind_root(uf, y);
	if (x != y) {
		if (uf->data[y] < uf->data[x]) {
			int tmp = x;
			x = y;
			y = tmp;
		}
		uf->data[x] += uf->data[y];
		uf->data[y] = x;
	}
	uf->n -= (x != y);
	return x != y;
}

bool UnionFind_same(UnionFind* uf, int x, int y) {
	return UnionFind_root(uf, x) == UnionFind_root(uf, y);
}

int UnionFind_root(UnionFind* uf, int x) {
	return uf->data[x] < 0 ? x : uf->data[x] = UnionFind_root(uf, uf->data[x]);
}

int UnionFind_size(UnionFind* uf, int x) {
	return -uf->data[UnionFind_root(uf, x)];
}

int UnionFind_num(UnionFind* uf) {
	return uf->n;
}

typedef struct {
	int n;
	int* dat;
} Array;

Array* new_Array() {
	Array* array = (Array*)malloc(sizeof(Array));
	array->n = 0;
	array->dat = NULL;
	return array;
}

void Array_push_back(Array* array, int x) {
	array->dat = (int*)realloc(array->dat, (array->n + 1) * sizeof(int));
	array->dat[array->n] = x;
	array->n++;
}

void Array_resize(Array* array, int size) {
	array->dat = (int*)realloc(array->dat, size * sizeof(int));
	array->n = size;
}

typedef struct {
	Array* data;
	int n;
} Matrix;

Matrix* new_Matrix() {
	Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
	matrix->n = 0;
	matrix->data = NULL;
	return matrix;
}

void Matrix_resize(Matrix* matrix, int size) {
	matrix->data = (Array*)realloc(matrix->data, size * sizeof(Array));
	matrix->n = size;
}

typedef struct {
	int n;
	int log2_n;
	int** parent;
	int* depth;
} Lca;

Lca* new_Lca() {
	Lca* lca = (Lca*)malloc(sizeof(Lca));
	lca->n = 0;
	lca->log2_n = 0;
	lca->parent = NULL;
	lca->depth = NULL;
	return lca;
}

void Lca_init(Lca* lca, Graph* g, int root) {
	lca->n = g->size;
	lca->log2_n = log2(lca->n) + 1;
	lca->parent = (int**)realloc(lca->parent, lca->log2_n * sizeof(int*));
	REP(k, lca->log2_n) {
		lca->parent[k] = (int*)realloc(lca->parent[k], lca->n * sizeof(int));
	}
	lca->depth = (int*)realloc(lca->depth, lca->n * sizeof(int));
	Lca_dfs(g, lca, root, -1, 0);
	REP(k, lca->log2_n - 1) {
		REP(v, g->size) {
			if (lca->parent[k][v] < 0)
				lca->parent[k + 1][v] = -1;
			else
				lca->parent[k + 1][v] = lca->parent[k][lca->parent[k][v]];
		}
	}
}

void Lca_dfs(Graph* g, Lca* lca, int v, int p, int d) {
	lca->parent[0][v] = p;
	lca->depth[v] = d;
	Edges edges = g->graph[v];
	REP(i, edges.size) {
		Edge e = edges.edges[i];
		if (e.to != p) Lca_dfs(g, lca, e.to, v, d + 1);
	}
}

int Lca_get(Lca* lca, int u, int v) {
	if (lca->depth[u] > lca->depth[v]) {
		int tmp = u;
		u = v;
		v = tmp;
	}
	REP(k, lca->log2_n) {
		if ((lca->depth[v] - lca->depth[u]) >> k & 1) {
			v = lca->parent[k][v];
		}
	}
	if (u == v) return u;
	REP(k, lca->log2_n - 1) {
		if (lca->parent[k][u] != lca->parent[k][v]) {
			u = lca->parent[k][u];
			v = lca->parent[k][v];
		}
	}
	return lca->parent[0][u];
}

typedef struct {
	int n;
	int p;
	int* data;
} FenwickTree;

FenwickTree* new_FenwickTree(int n) {
	FenwickTree* fenwickTree = (FenwickTree*)malloc(sizeof(FenwickTree));
	fenwickTree->n = n;
	fenwickTree->p = 1;
	while (fenwickTree->p < n) fenwickTree->p *= 2;
	fenwickTree->data = (int*)calloc(n + 1, sizeof(int));
	return fenwickTree;
}

int FenwickTree_sum(FenwickTree* fenwickTree, int k) {
	int ret = 0;
	for (; k > 0; k -= k & -k) ret += fenwickTree->data[k];
	return (ret);
}

int FenwickTree_sum_range(FenwickTree* fenwickTree, int a, int b) { return FenwickTree_sum(fenwickTree, b) - FenwickTree_sum(fenwickTree, a); }

void FenwickTree_add(FenwickTree* fenwickTree, int k, int x) {
	for (++k; k <= fenwickTree->n; k += k & -k) fenwickTree->data[k] += x;
}

int FenwickTree_lower_bound(FenwickTree* fenwickTree, ll w) {
	if (w <= 0) return -1;
	int x = 0;
	for (int k = fenwickTree->p / 2; k > 0; k /= 2) {
		if (x + k <= fenwickTree->n && fenwickTree->data[x + k] < w) w -= fenwickTree->data[x + k], x += k;
	}
	return x;
}

void divisor(ll n, Array* ret) {
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			Array_push_back(ret, i);
			if (i * i != n) Array_push_back(ret, n / i);
		}
	}
}

void prime_factorization(ll n, Array* ret) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			P p;
			p.first = i;
			p.second = 0;
			Array_push_back(ret, p);
			while (n % i == 0) {
				n /= i;
				ret->dat[ret->n - 1].second++;
			}
		}
	}
	if (n != 1) {
		P p;
		p.first = n;
		p.second = 1;
		Array_push_back(ret, p);
	}
}

ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

ll mod_inv(ll x, ll mod) {
	return mod_pow(x, mod - 2, mod);
}

typedef struct {
	Array* fact;
	Array* fact_inv;
	ll mod;
} Combination;

Combination* new_Combination(ll _n, ll _mod) {
	Combination* combination = (Combination*)malloc(sizeof(Combination));
	combination->mod = _mod;
	ll n = _n < _mod ? _n + 1 : _mod;
	combination->fact = new_Array();
	Array_resize(combination->fact, n);
	combination->fact->dat[0] = 1;
	REP(i, n - 1) {
		combination->fact->dat[i + 1] = (combination->fact->dat[i] * (i + 1LL)) % combination->mod;
	}
	combination->fact_inv = new_Array();
	Array_resize(combination->fact_inv, n);
	combination->fact_inv->dat[n - 1] = mod_inv(combination->fact->dat[n - 1], combination->mod);
	for (int i = n - 1; i > 0; i--) {
		combination->fact_inv->dat[i - 1] = (combination->fact_inv->dat[i] * i) % combination->mod;
	}
	return combination;
}

ll Combination_nCr(Combination* combination, ll n, ll r) {
	if (n < r) return 0;
	if (n < combination->mod) return ((combination->fact->dat[n] * combination->fact_inv->dat[r] % combination->mod) * combination->fact_inv->dat[n - r]) % combination->mod;
	ll ret = 1;
	while (n || r) {
		ll _n = n % combination->mod, _r = r % combination->mod;
		n /= combination->mod; r /= combination->mod;
		(ret *= Combination_nCr(combination, _n, _r)) %= combination->mod;
	}
	return ret;
}

ll Combination_nPr(Combination* combination, ll n, ll r) {
	return (combination->fact->dat[n] * combination->fact_inv->dat[n - r]) % combination->mod;
}

ll Combination_nHr(Combination* combination, ll n, ll r) {
	return Combination_nCr(combination, r + n - 1, r);
}

ll popcount(ll x) {
	x = (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555);
	x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333);
	x = (x & 0x0F0F0F0F0F0F0F0F) + (x >> 4 & 0x0F0F0F0F0F0F0F0F);
	x = (x & 0x00FF00FF00FF00FF) + (x >> 8 & 0x00FF00FF00FF00FF);
	x = (x & 0x0000FFFF0000FFFF) + (x >> 16 & 0x0000FFFF0000FFFF);
	x = (x & 0x00000000FFFFFFFF) + (x >> 32 & 0x00000000FFFFFFFF);
	return x;
}

ll mod = 998244353;

ll extgcd(ll a, ll b, ll* x, ll* y) {
	if (a < b) return extgcd(b, a, y, x);
	if (b > 0) {
		int g = extgcd(b, a % b, y, x);
		*y -= (a / b) * (*x);
		return g;
	}
	else {
		*x = 1, * y = 0;
		return a;
	}
}

int main() {
	ll m;
	scanf("%lld", &m);
	ll h1, a1, x1, y1;
	scanf("%lld %lld %lld %lld", &h1, &a1, &x1, &y1);
	Array* t = new_Array();
	int* used = (int*)calloc(m, sizeof(int));
	used[h1] = 1;
	Array_push_back(t, h1);
	while (1) {
		ll tmp = (t->dat[t->n - 1] * x1 + y1) % m;
		Array_push_back(t, tmp);
		if (used[tmp])break;
		used[tmp] = 1;
	}
	used = (int*)calloc(m, sizeof(int));
	ll h2, a2, x2, y2;
	scanf("%lld %lld %lld %lld", &h2, &a2, &x2, &y2);
	used[h2] = 1;
	Array* s = new_Array();
	Array_push_back(s, h2);
	while (1) {
		ll tmp = (s->dat[s->n - 1] * x2 + y2) % m;
		Array_push_back(s, tmp);
		if (used[tmp])break;
		used[tmp] = 1;
	}

	ll l1 = -1, l2 = -1;
	ll mn1 = INF, mn2 = INF;
	ll now = 0;
	while (1) {
		if (t->dat[t->n - 1] == t->dat[now]) {
			l1 = t->n - now - 1;
		}
		if (t->dat[now] == a1) {
			mn1 = now;
			break;
		}
		now++;
		if (now == t->n)break;
	}
	now = 0;
	while (1) {
		if (s->dat[s->n - 1] == s->dat[now]) {
			l2 = s->n - now - 1;
		}
		if (s->dat[now] == a2) {
			mn2 = now;
			break;
		}
		now++;
		if (now == s->n)break;
	}
	ll calc() {
		if (mn1 != INF && mn2 != INF) {
			if (mn1 == mn2)return mn1;
			if (mn1 > mn2&& l2 == -1)return -1;
			if (mn1 < mn2 && l1 == -1)return -1;
			if (l1 == -1) {
				if ((mn1 - mn2) % l2 == 0)return mn1;
				else return -1;
			}
			if (l2 == -1) {
				if ((mn2 - mn1) % l1 == 0)return mn2;
				else return -1;
			}
			if (l1 == l2) {
				if (abs(mn1 - mn2) % l1 == 0)return max(mn1, mn2);
				else return -1;
			}
			if (mn2 > mn1 && (mn2 - mn1) % l1 == 0)return mn2;
			if (mn1 > mn2 && (mn1 - mn2) % l2 == 0)return mn1;

			if (abs(mn2 - mn1) % abs(gcd(l1, l2)) != 0)return -1;
			ll x, y;
			ll g = extgcd(l1, l2, &x, &y);
			x *= (mn2 - mn1) / g;
			y *= (mn2 - mn1) / g;
			if (x * l1 + mn1 < max(mn1, mn2)) {
				x += ((max(mn1, mn2) - x * l1 + mn1 + l1 - 1) / l1 + l2 / g - 1) / (l2 / g) * (l2 / g);
			}
			if (x * l1 + mn1 >= max(mn1, mn2))x -= (x * l1 + mn1 - max(mn1, mn2)) / l1 / (l2 / g) * (l2 / g);
			return x * l1 + mn1;
		}
		else return -1;
	}
	printf("%lld\n", calc());

	return 0;
}
