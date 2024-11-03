

















using namespace std;

typedef long long LL;

typedef pair<int, int> pr;

const int next_x[8] = { 0, 1, -1, 0, 1, 1, -1,-1 };
const int next_y[8] = { 1, 0, 0, -1, 1, -1,-1, 1 };

const int inf = 2147483640;
const LL long_inf = 1e15;



template<size_t size>
struct id2 

{
	int fa[size];

	void init(int n)
	{
		for (int i = 1;i <= n;i++)
			fa[i] = i;
	}

	id2() { init(size - 1); }

	int find_fa(int x){return x == fa[x] ? x : fa[x] = find_fa(x);}

	void merge(int x, int y)
	{
		x = find_fa(x), y = find_fa(y);
		if (x != y) fa[x] = y;
	}

	bool same_fa(int x, int y)
	{
		return find_fa(x) == find_fa(y);
	}
};



template<class hash_type, int mod>
struct hash_talbe
{
	int m, *a;
	hash_type s[mod + 1];

	void set_argvs(int a[], int n){ this->a = a, m = n; }

	int hash(string s)
	{
		int t = 0;
		const int &n = s.length();
		for (int i = 0;i < n;i++)
			t = t * m + a[s[i]];
		return abs(t) % mod;
	}
	
	void clear() { memset(s, 0, sizeof(s)); }

	hash_type &operator [] (string t){ return s[hash(t)]; }
};



struct edge
{
	int next, to, from;
	bool flag;
	long long w;

	edge(int a = 0, int b = 0, long long c = 0, int d = 0)
	{
		this->from = a;
		this->to = b;
		this->w = c;
		this->next = d;
	}
	bool operator < (const edge & o)
	{
		return w < o.w;
	}
};

struct graph
{
	int n, m, ecnt;
	int *pre;
	edge *e;
	
	void add_edge(int u, int v, long long w, bool two_way)
	{
		ecnt++;
		e[ecnt].next = pre[u];
		e[ecnt].from = u;
		e[ecnt].to = v;
		e[ecnt].w = w;
		pre[u] = ecnt;
		if (two_way)
			this->add_edge(v, u, w, 0);
		return;
	}

	void init(int n, int m, int p[], edge *e)
	{
		this->ecnt = 0;
		this->n    = n;
		this->m    = m;
		this->pre  = p;
		this->e    = e;
		memset(pre, 0, sizeof(int)*(n + 1));
	}

	void debug()
	{
		printf("Graph Debug info:\n");
		for (int i = 1;i <= n;i++)
			printf("pre[%d]:%d\n", i, pre[i]);
		for (int i = 1;i <= ecnt;i++)
			printf("[%d] to:%d next:%d w:%d\n", i, e[i].to, e[i].next, e[i].w);
		for (int u = 1;u <= n;u++)
			for (int i = pre[u];i;i = e[i].next)
				printf("%d->%d next:%d w:%d\n", u, e[i].to, e[i].next, e[i].w);
		printf("-----------\n");
	}

};

template<size_t size>
long long id10(graph G, id2<size> u)
{
	edge *e = G.e;
	int &n = G.n, &m = G.m;
	int *pre = G.pre;

	long long ans = 0;

	sort(e + 1, e + 1 + m);
	for (int i = 1;i <= m;i++)
	{
		int &from = e[i].from, &to = e[i].to;
		long long  &w = e[i].w;
		if (!(u.same_fa(from, to)))
			u.merge(from, to), ans += w;
	}
	return ans;
}

void dijkstra(graph G, priority_queue<pr> q, int from, int dis[], const int & inf)
{
	edge *e = G.e;
	int &n = G.n, &m = G.m;
	int *pre = G.pre;

	for (int i = 1;i <= n;i++)
		dis[i] = inf;
	dis[from] = 0;
	q.push(make_pair(0, from));
	while (!q.empty())
	{
		int u = q.top().second, dis_u = -q.top().first;
		q.pop();
		for (int i = pre[u];i;i = e[i].next)
		{
			int v = e[i].to, w = e[i].w;
			if (dis_u != dis[u]) continue;
			if (dis_u + w < dis[v])
			{
				dis[v] = dis_u + w;
				q.push(make_pair(-dis[v], v));
			}
		}
	}
	return;
}

template<size_t size>
void floyd(int n, int a[size][size], int dis[size][size])
{
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				dis[i][j] = dis[i][k] + a[k][j] < dis[i][j] ?
					dis[i][k] + a[k][j] : dis[i][j];
}

void spfa(graph G, queue<int> q, int from, int dis[], bool vis[], const int &inf)
{
	edge *e = G.e;
	int &n = G.n, &m = G.m;
	int *pre = G.pre;

	for (int i = 1;i <= n;i++)
		dis[i] = inf;
	dis[from] = 0;
	vis[from] = 1;
	q.push(from);
	while (!q.empty())
	{
		int u = q.front();
		for (int i = pre[u];i;i = e[i].next)
		{
			int &v = e[i].to;
			if (dis[u] + e[i].w < dis[v])
			{
				dis[v] = dis[u] + e[i].w;
				if (!vis[v]) q.push(v), vis[v] = 1;
			}
		}
		q.pop(), vis[u] = 0;
	}
	return;
}



void id8(graph G, int u, bool vis[], int bel[], int dfn[], int low[],
	stack<int> &S, int &cnt, int &bel_cnt)
{
	edge *e = G.e;
	int &n = G.n, &m = G.m;
	int *pre = G.pre;

	dfn[u] = low[u] = ++cnt;
	S.push(u), vis[u] = 1;
	for (int i = pre[u];i;i = e[i].next)
	{
		int &v = e[i].to;
		if (!dfn[v])
		{
			id8(G, v, vis, bel, dfn, low, S, cnt, bel_cnt);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u])
	{
		++bel_cnt;
		int cur;
		do{
			cur = S.top();
			bel[cur] = bel_cnt;
			vis[cur] = 0;
			S.pop();
		} while (cur != u);
	}
}



void id8(graph &G, int u, int dfn[], int low[], int fa[], int &cnt)
{
	edge *e = G.e;
	int &n = G.n, &m = G.m;
	int *pre = G.pre;

	dfn[u] = low[u] = ++cnt;
	for (int i = pre[u];i;i = e[i].next)
	{
		int &v = e[i].to;
		if (!dfn[v])
		{
			fa[v] = u;
			id8(G, v, dfn, low, fa, cnt);
			low[u] = min(low[u], low[v]);
			if (fa[u] <= 0) fa[u]--;

		}
		else if (fa[u] != v)
			low[u] = min(low[u], dfn[v]);
	}
}



int tarjan(graph &G, bool vis[], int bel[], int dfn[], int low[], stack<int> &S)
{
	edge *e = G.e;
	int &n = G.n, &m = G.m;
	int *pre = G.pre;
	
	int cnt = 0, bel_cnt = 0;
	memset(vis, 0, sizeof(bool)*(n + 1));
	memset(bel, 0, sizeof(int) *(n + 1));
	memset(low, 0, sizeof(int) *(n + 1));
	memset(dfn, 0, sizeof(int) *(n + 1));
	
	while (!S.empty()) S.pop();
	for (int i = 1;i <= n;i++)
		if (!dfn[i]) id8(
			G, i, vis, bel, dfn, low, S, cnt, bel_cnt);
	
	return bel_cnt;
}

struct id1
{
	graph *G;
	int *fa, *dfn, *low;

	void debug()
	{
		for (int i = 1;i <= G->n;i++)
			printf("[%d] fa:%d dfn:%d low:%d\n", i, fa[i], dfn[i], low[i]);
	}

	id1(int *fa, int *dfn, int *low, graph *G)
	{
		this->fa  = fa;
		this->dfn = dfn;
		this->low = low;
		this->G   = G;
	}

	set<int> count_cut_points() 

	{
		edge *e = G->e;
		int &n = G->n, &m = G->m;
		int *pre = G->pre;

		set<int> ans;
		for (int v = 1;v <= n;v++)
		{
			int &u = fa[v];
			if (u <= -2)
				ans.insert(v);
			else if (u > 0 && fa[u] >= 0  && low[v] >= dfn[u]) 

				ans.insert(u);
		}
		return ans;
	}
	
	vector<pr> count_bridges() 

	{
		edge *e = G->e;
		int &n = G->n, &m = G->m;
		int *pre = G->pre;

		vector<pr> ans;
		for (int v = 1;v <= n;v++)
		{
			int u = fa[v];
			if (u > 0 && low[v] > dfn[u])
			{
				int cnt = 0;
				for (int i = pre[u];i;i = e[i].next)
					if (e[i].to == v) cnt++;
				
				if (cnt >= 2) continue;
				pr t = make_pair(u, v);
				ans.push_back(t);
			}
		}
		return ans;
	}
};



id1 tarjan(graph &G, int dfn[], int low[], int fa[])
{
	edge *e = G.e;
	int &n = G.n, &m = G.m;
	int *pre = G.pre;

	int cnt = 0;
	memset(fa,  0, sizeof(int)*(n + 1));
	memset(low, 0, sizeof(int)*(n + 1));
	memset(dfn, 0, sizeof(int)*(n + 1));

	for (int i = 1;i <= n;i++)
		if (!dfn[i]) id8(
			G, i, dfn, low, fa, cnt);

	return id1(fa, dfn, low, &G);
}

vector<int> id7(graph &G, int fa[]) 
{


	int &n = G.n, &m = G.m;
	vector<int> roots;
	G.init(n, m, G.pre, G.e);
	for (int i = 1;i <= n;i++)
	{
		if (fa[i] > 0) G.add_edge(fa[i], i, 0, 1);
		else roots.push_back(i);
	}
	return roots;
}

void id12(graph &G, int u, int bel[], int &bcc_cnt)
{
	edge *e = G.e;
	int &n = G.n, &m = G.m;
	int *pre = G.pre;

	bel[u] = bcc_cnt;
	for (int i = pre[u];i;i = e[i].next)
	{
		int &v = e[i].to;
		if (!e[i].flag && !bel[v])
			id12(G, v, bel, bcc_cnt);
	}
	return;
}

int id13(graph &G, vector<pr> bridges, int bel[])
{


	edge *e = G.e;
	int &n = G.n, &m = G.m;
	int *pre = G.pre;

	

	memset(bel , 0, sizeof(int) *(n + 1));

	for (vector<pr>::iterator i = bridges.begin();i != bridges.end();i++)
	{
		int u = i->first, v = i->second;
		for (int i = pre[u];i;i = e[i].next)
		{
			int to = e[i].to;
			if (to == v) e[i].flag = 1;
		}
		for (int i = pre[v];i;i = e[i].next)
		{
			int to = e[i].to;
			if (to == u) e[i].flag = 1;
		}
	}

	int bcc_cnt = 0;
	for (int i = 1;i <= n;i++)
		if (!bel[i]) bcc_cnt++, id12(G, i, bel, bcc_cnt);
	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

		
	return bcc_cnt;
}

template<int sz1, int sz2> 
struct lca
{
	

	graph *G;
	int (*f)[sz2], *deep;

	lca(graph *G, int fa[sz1][sz2], int deep[])
	{
		this->G    = G;
		this->f    = fa;
		this->deep = deep;
	}
	
	void dfs(int u, int	father)
	{
		edge *e = G->e;
		int &n = G->n, &m = G->m;
		int *pre = G->pre;

		for (int i = pre[u];i;i = e[i].next)
		{
			int &v = e[i].to;
			if (v == father) continue;
			else
			{
				deep[v] = deep[u] + 1;
				f[v][0] = u;
				dfs(v, u);
			}
		}

	}

	void init(int root)
	{
		int &n = G->n, &m = G->m;

		memset(deep, 0, sizeof(int)*(n + 1));
		memset(f,    0, sizeof(int)*(sz1)*(sz2));

		deep[root]=1, dfs(root, 0); 


		for (int j = 1;j < sz2;j++)
			for (int i = 1;i <= n;i++)
				if (f[i][j - 1]) f[i][j] = f[f[i][j - 1]][j - 1];
	}

	int get_lca(int u, int v)
	{
		if (deep[u] < deep[v])
			swap(u, v);

		int t = log2(deep[u]);
		for (int i = t;i >= 0;i--)
		{
			if (deep[f[u][i]] >= deep[v])
				u = f[u][i];
		}
		if (u == v) return u;
		
		for (int i = t;i >= 0;i--)
			if (f[v][i] && f[u][i] != f[v][i])
				u = f[u][i], v = f[v][i];

		return f[u][0];
	}
};

void id4(graph &G, bool vis[], int f[], int u, int &ans) 
{
	edge *e = G.e;
	int &n = G.n, &m = G.m;
	int *pre = G.pre;

	int a = 0, b = 0;
	vis[u] = 1;
	for (int i = pre[u];i;i = e[i].next)
	{
		int &v = e[i].to, w = e[i].w;
		if (vis[v]) continue;

		id4(G, vis, f, v, ans);

		if (f[v] + w > a) b = a, a = f[v] + w;
		else if (f[v] + w > b) b = f[v] + w;
	}
	f[u] = a, ans = max(ans, a + b);
}

int id0(graph &G, bool vis[], int f[]) 

{
	edge *e = G.e;
	int &n = G.n, &m = G.m;
	int *pre = G.pre;

	int ans = 0;
	memset(f,   0, sizeof(int )*(n + 1));
	memset(vis, 0, sizeof(bool)*(n + 1));
	
	id4(G, vis, f, 1, ans);
	return ans;
}



template<class T>
T fast_pow(T x, T k, T m) 

{
	T ans = 1;
	while (k)
	{
		if (k % 2 == 1)
			ans = ans * x % m;
		k = k / 2;
		x = x * x % m;
	}
	return ans;
}

LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a%b); } 


int id3(int a, int b, int &x, int &y) 

{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	int d = id3(b, a%b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
	return d;
}

bool id9(int a, int b, int &x, int &y, int c)
{
	int g = id3(a, b, x, y);
	int _a = a / g, _b = b / g;
	if (c%g != 0) return 0;
	

	while (x <= 0)
		x += _a, y += _b;
	x *= c / g, y *= c / g;
	return 1;
}











template<class T >
T id11(T a[], int n) 

{
	T ans = a[1];
	for (int i = 2;i <= n;i++)
		ans = gcd(ans, a[i]);
	return ans;
}

LL lcm(LL a, LL b) { return a / gcd(a, b)*b; } 


template<size_t row_size, size_t col_size>
void gauss(int a[row_size][col_size], int n, int m) 

{
}

void init_prime(bool not_prime[], int prime[], int &head, int n) 

{
	not_prime[1] = 1;
	for (int i = 2;i <= n;i++)
	{
		if (!not_prime[i])
			prime[++head] = i;
		for (int j = 1;j <= head && (LL)prime[j] * i <= n;j++)
		{
			not_prime[prime[j] * i] = 1;
			if (i%prime[j] == 0) break;
		}
	}
}








bool is_prime(int x)
{
	int t = sqrt(x);
	for (int i = 2;i <= t;i++)
		if (x%i == 0) return 0;
	return 1;
}

int crt(int n, int a[], int m[])

{
	int d = 1, x, y, ans = 0;
	for (int i = 1;i <= n;i++) d = d * m[i];
	for (int i = 1;i <= n;i++)
	{
		int M = d / m[i];
		id3(M, m[i], x, y);
		ans = (ans + M * x*a[i]) % d;
	}
	if (ans < 0) ans += d;
	return ans;
}

int get_phi(int n) 

{
	int ans = n, t = sqrt(n);
	for (int i = 2;i <= t;i++)
	{
		if (n%i == 0)
		{
			ans -= ans / i;
			while (n%i == 0)
				n /= i;
		}
	}
	if (n > 1)
		ans -= ans / n;
	return ans;
}

int init_phi()
{
	return -1;
}

LL euler(LL a, string b, LL m) 

{
	bool flag = 0;
	LL t = 0, phi_m = get_phi(m);
	for (string::iterator p = b.begin();p != b.end();p++)
	{
		t = t * 10 + (*p) - '0';
		if (t >= phi_m) 

			t %= phi_m, flag = 1;
	}
	return flag ? fast_pow(a, t % phi_m + phi_m, m) : fast_pow(a, t, m);
}






struct id6
{
	int cnt;
	int tag;
	id6 *(nx[26]); 


	id6()
	{
		tag = cnt = 0;
		memset(nx, 0, sizeof(nx));
	}

	void create(char c){nx[c - 'a'] = new id6;}

	bool have_next(char c){return nx[c - 'a'] == NULL;}

	id6 * next(char c){return nx[c - 'a'];}

	void release() 

	{
		for (int i = 0;i < 26;i++)
			if (nx[i] != NULL)
				nx[i]->release();
		delete this;
	}

	void remove_sons() 

	{
		for (int i = 0;i < 26;i++)
			if (nx[i] != NULL)
				nx[i]->release(), nx[i] = NULL;
		return;
	}

	void update()
	{
		cnt = tag;
		for (int i = 0;i < 26;i++)
			if (nx[i] != NULL)
				cnt += nx[i]->cnt;
		return;
	}
};

template<bool repeat_count>
struct tire
{ 

	id6 *root;

	tire(){root = new id6;}
	
	void init()
	{
		root->remove_sons(); 
		delete root;
		root = new id6;
	}
	
	void insert_work(id6 *cur, const string &s, int index)
	{
		if (index == s.length())
		{	
			if(repeat_count) cur->tag++;
			else cur->tag = 1;
			cur->update();
			return;
		}
		else
		{
			if (cur->next(s[index]) == NULL)
				cur->create(s[index]);
			insert_work(cur->next(s[index]), s, index + 1);
			cur->update();
		}
	}

	void insert(string s){insert_work(root, s, 0);}

	void del_work(id6 *cur, const string &s, int index) 

	{
		if (index == s.length())
		{
			cur->remove_sons();
			cur->tag = cur->cnt = 0;
			return;
		}
		else
		{
			if (cur->next(s[index]) == NULL) return;
			else del_work(cur->next(s[index]), s, index + 1), cur->update();
		}
		return;
	}

	void del(string s){del_work(root, s, 0);}
	
	int count(string s)
	{
		id6 *cur = root;
		for (string::iterator p = s.begin();p != s.end();p++)
		{
			char t = *p;
			if (cur->next(t) == NULL)
				return 0;
			cur = cur->next(t);
		}
		return cur->cnt;
	}

	bool search(string s){return count(s) > 0;}
};

template<size_t size>
struct KMP
{
	string s;
	int *a, len;
	int nx[size];

	

	void init() { memset(nx, 0, sizeof(size)); }
	
	KMP() { init(); }
	
	void build_next(int a[], int n) 

	{
		int k = 0;
		nx[0] = nx[1] = 0;
		for(int i=1;i<n;i++)
		{
			while (k&&a[i] != a[k]) k = nx[k];
			if (a[i] == a[k]) k++;
			nx[i + 1] = k;
		}
		this->a = a, this->len = n;
	}

	void build_next(string a)
	{
		int k = 0, n = a.length();
		nx[0] = nx[1] = 0;
		for (int i = 1;i < n;i++)
		{
			while (k&&a[i] != a[k]) k = nx[k];
			if (a[i] == a[k]) k++;
			nx[i + 1] = k;
		}
		this->s = a, this->len = a.length();
	}

	int match(int b[], int m)
	{
		int k = 0;
		for (int j = 0;j < m;j++)
		{
			while (k&&b[j] != a[k]) k = nx[k];
			if (b[j] == a[k]) k++;
			if (k == len) return j - len + 1;
		}
		return -1;
	}

	bool match(string b)
	{
		int k = 0, m = b.length();
		for (int j = 0;j < m;j++)
		{
			while (k&&b[j] != s[k]) k = nx[k];
			if (b[j] == s[k]) k++;
			if (k == len) return j - len + 1;
		}
		return -1;
	}

	

	int get_min_loop_seq(int length)  {return length % (length - nx[length]) == 0 ? length / (length - nx[length]) : 0; }

	void debug()
	{
		for (int i = 0;i <= len;i++)
			printf("nx[%d] = %d\n", i, nx[i]);
	}
};


struct ACM
{

};



typedef bool(*checker)(int mid);

int id5(int l, int r, checker func) 

{
	int mid, ans = l;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (func(mid))
			ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

struct bign
{
	int mod; 

	vector<int> s;

	bign(string str = "0", int mod = 10)
	{
		for (auto i = str.rbegin();i != str.rend();i++)
			s.push_back((*i) - '0');
		this->mod = mod;
	}

	bign(int a[], int n, int mod = 10) 

	{
		for (int i = n;i;i--)
			s.push_back(a[i]);
		this->mod = mod;
	}

	bign & print()
	{
		for (auto i = s.rbegin();i != s.rend();i++)
		{
			int &t = *i;
			if (t < 10) printf("%d", t);
			else printf("%d", t - 10 + 'A');
		}
		printf("\n");
		return *this;
	}

	void carry()

	{
		for (auto i = s.begin();i != s.end() - 1;i++)
			*(i + 1) += (*i) / mod, (*i) %= mod;
			
		while (*(s.end() - 1) >= mod)
		{
			int t = *(s.end() - 1) / mod;
			*(s.end() - 1) %= mod;
			s.push_back(t);
		}
	}

	bign operator + (const bign & other)
	{
		bign res;
		if (this->s.size() > other.s.size())
		{
			res = *this;
			for (int i = 0;i < other.s.size();i++)
				res.s[i] += other.s[i];
				
		}
		else
		{
			res = other;
			for (int i = 0;i < this->s.size();i++)
				res.s[i] += this->s[i];
		}
		res.carry();
		return res;
	}

	bign operator += (const bign & other)
	{
		*this = *this + other;
		return *this;
	}

	bign operator / (const int & other)
	{
		int t = 0;
		bign res = *this;
		for (auto i = res.s.rbegin();i != res.s.rend();i++)
		{
			t = t * mod + (*i);
			*i = t / other;
			t %= other;
		}
		while (*(res.s.end() - 1) == 0 && res.s.end() - 1 != res.s.begin())
			res.s.pop_back();
		return res;
	}

	bign operator /= (const int & other)
	{
		*this = *this / other;
		return *this;
	}

	bign operator * (const int &other)
	{
		for (auto i = s.begin();i != s.end();i++)
			(*i) *= other;
		this->carry();
		return *this;
	}

	bign operator *= (const int &other)
	{
		*this = (*this) * other;
		return *this;
	}
};


int readin()
{
	int t = 0, f = 1; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-')f = -1;ch = getchar(); }
	while (ch >= '0'&&ch <= '9') { t = t * 10 + ch - '0';ch = getchar(); }
	return t * f;
}






















extern const int MAXN = 300005;
extern const int N = 8000;




int n;
LL h, a[MAXN];
void work()
{
	scanf("%d%lld", &n, &h);
	for (int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	
	int k;
	for (k = 1;k <= n;k++)
	{
		LL s = 0;
		sort(a + 1, a + 1 + k);
		if (k & 1)
		{
			s += a[1];
			for (int i = 3;i <= k;i += 2)
				s += a[i];
		}
		else
		{
			for (int i = 2;i <= k;i += 2)
				s += a[i];
		}
		if (s > h) break;
	}
	printf("%d\n", k - 1);
}

int main()
{
	ios::sync_with_stdio(false);

	freopen( "input.txt", "r", stdin );
	


	work();

	freopen("CON", "r", stdin);
	system("pause");

	return 0;
}