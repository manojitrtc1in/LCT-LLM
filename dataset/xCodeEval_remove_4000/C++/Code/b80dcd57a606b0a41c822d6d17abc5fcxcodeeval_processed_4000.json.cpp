























using namespace std;

































typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
typedef vector <int> vi;
typedef vector<vector <int> > vvi;
typedef vector <ll> vll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef map <char, int> mci;
typedef map <char, char> mcc;
typedef pair <char, int> pci;
typedef complex<double> cd;
typedef vector<complex<double> > vcd;

const double eps = 1e-8;
const double PI = 2 * acos(0.0);

int cc, bb; char ch; inline int F() {
	while (ch = getchar(), (ch < 48 || ch> 57) && ch != '-'); ch == '-' ? cc = bb = 0 : (cc = ch - '0', bb = 1);
	while (ch = getchar(), ch > 47 && ch < 58)cc = (cc << 1) + (cc << 3) + (ch ^ 48); return bb ? cc : -cc;
}
void write(int x) {
	int y = 10, len = 1;
	while (y <= x) { y *= 10; len++; }
	while (len--) { y /= 10; putchar(x / y + 48); x %= y; }
}
ll gcd(ll a, ll b) {
	ll r;
	if (a < 0)a = -a;
	if (b < 0)b = -b;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
ll mod_mul(ll a, ll b, ll mod) {
	ll res = 0;
	while (b) {
		if (b & 1) if ((res += a) > mod)res -= mod;
		if ((a <<= 1) > mod)a -= mod;
		b >>= 1;
	}
	return res;
}
ll pow2(ll a, ll b, ll mod) {
	ll r = 1, base = a;
	while (b) {
		if (b & 1) r = r * base % mod;
		base = base * base % mod;
		b >>= 1;
	}
	return r;
}
ll inv(ll a, ll n) {
	return pow2(a, n - 2, n);
	

}
bool id2(ll n) {
	if (n < 2)return false;
	if (n == 2)return true;
	if (!(n & 1))return false;
	ll u = n - 1;
	while (!(u & 1))u >>= 1;
	ll m = u;
	ll a[13] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
	for (int i = 0; i < 12; i++) {
		if (a[i] >= n)
			break;
		ll x = pow2(a[i], u, n);
		ll y;
		while (u < n) {
			y = pow2(x, 2, n);
			if (y == 1 && x != 1 && x != n - 1)
				return false;
			x = y;
			u <<= 1;
		}
		if (x != 1)return false;
		u = m;
	}
	return true;
}
vector<ll> prime;
ll id1(ll n, ll c) {

	ll i = 1, p = 2;
	ll x0 = rand() % (n - 1) + 1;

	ll y = x0;
	while (1) {
		i++;
		x0 = (mod_mul(x0, x0, n) + c) % n;
		ll d = gcd(y - x0, n);
		if (d != 1 && d != n) return d;
		if (y == x0) return n;
		if (i == p) {
			y = x0;
			p += p;
		}
	}
}
void find(ll n, ll c, vector<ll>& prime) {
	if (n == 1) return;
	if (id2(n)) {
		prime.push_back(n);
		return;
	}
	ll x = n, p = c;
	while (x == n) {
		x = id1(x, c--);
	}
	find(n / x, p, prime);
	find(x, p, prime);
}
ll id0(ll a, ll  b, ll& x, ll& y) {
	if (b == 0) { x = 0; y = 1; return a; };
	if (a % b == 0) {
		x = 0;
		y = 1;
		return b;
	}
	ll res = id0(b, a % b, y, x);
	y -= a / b * x;
	return res;
}
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class fenwick_tree {
public:
	int t[1007 << 2];
	int n;
	inline void add(int x, int p) {

		while (x <= n) {
			t[x] += p;
			x += x & (-x);
		}
		return;
	}
	inline int sum(int x) {

		int ans = 0;
		while (x > 0) {
			ans += t[x];
			x -= x & (-x);
		}
		return ans;
	}
	inline int query(int l, int r) {
		return(sum(r) - sum(l - 1));
	}
};
class dsu {
public:
	int n, m;
	int fa[maxn];
	int ranka[maxn];
	int find(int x) {
		if (fa[x] != x)
			fa[x] = find(fa[x]);
		return fa[x];
	}

	void init(int n) {
		for (int i = 0; i <= n; i++)
			fa[i] = i, ranka[i] = 0;
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)return;
		if (ranka[x] < ranka[y]) {
			fa[x] = y;
		}
		else {
			fa[y] = x;
			if (ranka[x] == ranka[y])ranka[x]++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};
class minheap {
public:
	int heap_size;
	pair<int, int> a[222];
	

	void heapify(int i) {

		int l = i << 1;
		int r = i << 1 | 1;
		int smallest;
		while (l <= heap_size) {
			if (a[l].first < a[i].first)
				smallest = l;
			else
				smallest = i;
			if (r <= heap_size && a[r].first < a[smallest].first)
				smallest = r;
			if (smallest != i) {
				swap(a[i], a[smallest]);
				i = smallest;
				l = i << 1;
				r = i << 1 | 1;
			}
			else
				break;
		}
	}
	void extract() {
		a[1] = a[heap_size];
		heap_size--;
		heapify(1);
	}
	void insert(pair<int, int> key) {
		heap_size++;
		int i = heap_size;
		a[i] = key;
		while (i > 1 && a[i >> 1].first > a[i].first) {
			swap(a[i], a[i >> 1]);
			i >>= 1;
		}
	}
};
class NumMatrix {
public:
	vector<vector<int> >presum;
	NumMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (!m)return;
		int n = matrix[0].size();
		presum.resize(m + 1);
		presum[0].resize(n + 1);
		for (int i = 0; i < m; i++) {
			presum[i + 1].resize(n + 1);
			for (int j = 0; j < n; j++) {
				presum[i + 1][j + 1] = presum[i + 1][j] + presum[i][j + 1] - presum[i][j] + matrix[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return presum[row2 + 1][col2 + 1] - presum[row2 + 1][col1] - presum[row1][col2 + 1] + presum[row1][col1];
	}
};
class Dijkstra {
public:
	int n, m, x;
	int d[maxn];
	struct edge {
		int u, v, w, next;
		edge() { }
		edge(int u, int v, int w, int next) :u(u), v(v), w(w), next(next) { }
	};
	struct Node {
		int d, v;
		Node(int d = 0, int v = 0) :d(d), v(v) {}
		bool operator < (const Node& n)  const {
			return d > n.d;
		}
	};
	priority_queue<Node> q;

	bool vis[maxn];
	edge g[maxm];
	int st[maxn];
	void init() {
		m = 0;
		memset(vis, 0, sizeof vis);
		memset(st, -1, sizeof st);
	}
	void addedge(int u, int v, int w) {
		g[m] = edge(u, v, w, st[u]);
		st[u] = m++;
		g[m] = edge(v, u, w, st[v]);
		st[v] = m++;
	}
	void go(int s) {
		d[s] = 0;
		q.push(Node(0, s));
		edge e;
		Node x;
		while (!q.empty()) {
			x = q.top();
			q.pop();
			int u = x.v;
			if (vis[u])continue;
			vis[u] = 1;
			for (int i = st[u]; i != -1; i = g[i].next) {
				e = g[i];
				if (d[e.v] > d[e.u] + e.w) {
					d[e.v] = d[e.u] + e.w;
					q.push(Node(d[e.v], e.v));
				}
			}
		}
	}
};
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:

	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		map<int, int> g;
		int m = mat.size();
		int n = mat[0].size();
		for (int i = 0; i < m; i++) {
			int nowr = i, nowc = 0;
			while (nowr < m && nowc < n)
				g[mat[nowr++][nowc++]]++;
			nowr = i, nowc = 0;
			auto it = g.begin();
			while (nowr < m && nowc < n) {
				if (it->second)
					mat[nowr++][nowc++] = it->first, it->second--;
				else it++;
			}
		}
		for (int i = 1; i < n; i++) {
			int nowr = 0, nowc = i;
			while (nowr < m && nowc < n)
				g[mat[nowr++][nowc++]]++;
			nowr = 0, nowc = i;
			auto it = g.begin();
			while (nowr < m && nowc < n) {
				if (it->second)
					mat[nowr++][nowc++] = it->first, it->second--;
				else it++;
			}
		}
		return mat;
	}
	class Dijkstra {
	public:
		int n, m, x;
		struct edge {
			int u, v, w, next;
			edge() { }
			edge(int u, int v, int w, int next) :u(u), v(v), w(w), next(next) { }
		};
		struct Node {
			int d, v;
			Node(int d = 0, int v = 0) :d(d), v(v) {}
			bool operator < (const Node& n)  const {
				return d > n.d;
			}
		};
		priority_queue<Node> q;

		bool vis[107];
		edge g[12007];
		int st[107];
		void init(int num) {
			n = num;
			m = 0;
			memset(vis, 0, sizeof vis);
			memset(st, -1, sizeof st);
		}
		void addedge(int u, int v, int w) {
			g[m] = edge(u, v, w, st[u]);
			st[u] = m++;
			

			

		}
		void go(int s, int d[]) {
			d[s] = 0;
			q.push(Node(0, s));
			edge e;
			Node x;
			while (!q.empty()) {
				x = q.top();
				q.pop();
				int u = x.v;
				if (vis[u])continue;
				vis[u] = 1;
				for (int i = st[u]; i != -1; i = g[i].next) {
					e = g[i];
					if (d[e.v] > d[e.u] + e.w) {
						d[e.v] = d[e.u] + e.w;
						q.push(Node(d[e.v], e.v));
					}
				}
			}
		}

	};

	int maxFrequency(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		return 0;
	}
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		int res = 0;
		vector<vector<int> > g(n);
		queue<pair<int, int> > q;
		for (int i = 0; i < n; i++)
			if (manager[i] == -1)q.push(make_pair(i, 0));
			else g[manager[i]].emplace_back(i);
		pair<int, int> tmp;
		int d[4][2] = { 1,0,-1,0,0,1,0,-1 };
		while (!q.empty()) {
			tmp = q.front();
			q.pop();
			tmp.second += informTime[tmp.first];
			res = max(res, tmp.second);
			for (int i = 0; i < g[tmp.first].size(); i++)
				q.push(make_pair(g[tmp.first][i], tmp.second));
		}
		return res;
	}
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> in(n);
		vector<vector<int>> rgraph(n);
		queue<int> q;
		vector<int> res;
		for (int i = 0; i < n; i++) {
			in[i] = graph[i].size();
			if (!in[i])q.push(i), res.emplace_back(i);
			for (int j = 0; j < graph[i].size(); j++)
				rgraph[graph[i][j]].emplace_back(i);
		}
		int tmp;
		while (!q.empty()) {
			tmp = q.front();
			q.pop();
			for (int i = 0; i < rgraph[tmp].size(); i++) {
				if (--in[rgraph[tmp][i]] == 0)
					q.push(rgraph[tmp][i]), res.emplace_back(rgraph[tmp][i]);
			}
		}
		sort(res.begin(), res.end());
		return res;
	}
	int shortestBridge(vector<vector<int>>& grid) {
		queue<pair<int, int> > q;
		queue<array<int, 3> > q2;
		int n = grid.size();
		vector<vector<int>> vis(n);
		for (int i = 0; i < n; i++)
			vis[i].resize(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					q.push(make_pair(i, j));
					q2.push(array<int, 3> { i, j, 0 });
					vis[i][j] = 1;
					grid[i][j] = 2;
					i = n;
					break;
				}
			}
		}
		pair<int, int> tmp;
		int d[4][2] = { 1,0,-1,0,0,1,0,-1 };
		while (!q.empty()) {
			tmp = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nowr = tmp.first + d[i][0], nowc = tmp.second + d[i][1];
				if (nowr >= 0 && nowr < n && nowc >= 0 && nowc < n && grid[nowr][nowc] == 1) {
					grid[nowr][nowc] = 2;
					vis[nowr][nowc] = 1;
					q.push(make_pair(nowr, nowc));
					q2.push(array<int, 3> { nowr, nowc, 0 });
				}
			}
		}
		array<int, 3> p;
		while (!q2.empty()) {
			p = q2.front();
			q2.pop();
			for (int i = 0; i < 4; i++) {
				int nowr = p[0] + d[i][0], nowc = p[1] + d[i][1];
				if (nowr >= 0 && nowr < n && nowc >= 0 && nowc < n && !vis[nowr][nowc]) {
					if (grid[nowr][nowc] == 1)return p[2] + 1;
					vis[nowr][nowc] = 1;
					q2.push(array<int, 3> { nowr, nowc, p[2] + 1 });
				}
			}
		}
		return 0;
	}
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		queue<pair<int, int> > q;
		int m = mat.size();
		int n = mat[0].size();
		vector<vector<int>> vis(m);
		vector<vector<int>> res(m);
		for (int i = 0; i < m; i++) {
			vis[i].resize(n);
			res[i].resize(n);
			iota(res[i].begin(), res[i].end(), 10007);
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] == 0) {
					vis[i][j] = 1;
					res[i][j] = 0;
					q.push(make_pair(i, j));
				}
			}
		}
		pair<int, int> tmp;
		int d[4][2] = { 1,0,-1,0,0,1,0,-1 };
		while (!q.empty()) {
			tmp = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nowr = tmp.first + d[i][0], nowc = tmp.second + d[i][1];
				if (nowr >= 0 && nowr < m && nowc >= 0 && nowc < n && !vis[nowr][nowc]) {
					vis[nowr][nowc] = 1;
					res[nowr][nowc] = d[tmp.first][tmp.second] + 1;
					q.push(make_pair(nowr, nowc));
				}
			}
		}
		return res;
	}
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		vector<vector<int>> res = image;
		int need = image[sr][sc];
		queue<pair<int, int> > q;
		q.push(make_pair(sr, sc));
		bool vis[57][57];
		memset(vis, 0, sizeof vis);
		pair<int, int> tmp;
		vis[sr][sc] = 1;
		int d[4][2] = { 1,0,-1,0,0,1,0,-1 };
		int m = image.size();
		int n = image[0].size();
		while (!q.empty()) {
			tmp = q.front();
			q.pop();
			res[tmp.first][tmp.second] = newColor;
			for (int i = 0; i < 4; i++) {
				int nowr = tmp.first + d[i][0], nowc = tmp.second + d[i][1];
				if (nowr >= 0 && nowr < m && nowc >= 0 && nowc < n && !vis[nowr][nowc] && image[nowr][nowc] == need) {
					vis[nowr][nowc] = 1;
					q.push(make_pair(nowr, nowc));
				}
			}
		}
		return res;
	}
};
void fj(ll a, vector<ll>& w) {
	for (ll i = 2; i * i <= a; i++)
		if (!(a % i)) {
			ll num = 0;
			while (!(a % i)) {
				num++;
				a /= i;
			}
			w.push_back(i);
		}
	if (a != 1)
		w.push_back(a);
}

int main() {
	

	

	

	

	

	

	

	clock_t start, end;
	start = clock();
	fastio;

	

	

	

	

	

	

	
	
	

	

	

	


	int t;
	cin >> t;
	ll n;
	ll maxxx = 2 * 1e9;
	srand(time(0));
	while (t--) {
		cin >> n;
		ll p = n;
		if (n % 2)
			cout << 2 << endl;
		else {
			ll q = 2;
			while (p % 2 == 0)
				p >>= 1, q <<= 1;
			if (p != 1) {
				

				cout << min(p, q) << endl;
				
			}
			else
				cout << -1 << endl;
		}

	}

	

	end = clock();
	cerr << (end - start) * 1000.0 / CLOCKS_PER_SEC << "ms\n";
	return 0;
}
