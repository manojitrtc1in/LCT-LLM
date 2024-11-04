
























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
bool id1(ll n) {
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
ll id0(ll n, ll c) {

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
	if (id1(n)) {
		prime.push_back(n);
		return;
	}
	ll x = n, p = c;
	while (x == n) {
		x = id0(x, c--);
	}
	find(n / x, p, prime);
	find(x, p, prime);
}
ll id2(ll a, ll  b, ll& x, ll& y) {
	if (b == 0) { x = 0; y = 1; return a; };
	if (a % b == 0) {
		x = 0;
		y = 1;
		return b;
	}
	ll res = id2(b, a % b, y, x);
	y -= a / b * x;
	return res;
}
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	ull cnt;
	TreeNode() : val(0), left(nullptr), right(nullptr), cnt(0) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr), cnt(0) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right), cnt(0) {}
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
	int t[500007 << 2];
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
	int n;
	int fa[maxn << 1];
	int ranka[maxn << 1];
	int size[maxn << 1];
	int find(int x) {
		if (fa[x] != x)
			fa[x] = find(fa[x]);
		return fa[x];
	}

	void init(int n) {
		for (int i = 0; i <= n; i++)
			fa[i] = i, size[i] = 1;
		memset(ranka, 0, (n + 1) << 2);
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)return;
		if (ranka[x] < ranka[y]) {
			size[y] += size[x];
			fa[x] = y;
		}
		else {
			size[x] += size[y];
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


class Solution {

public:
	class mat {
	public:
		int row, col;
		vector<vector<ll> > matrix;
		mat(int r, int c) :row(r), col(c) {
			matrix.resize(r);
			for (int i = 0; i < r; i++)matrix[i].resize(c);
		};
		mat() {}
	};
	friend mat operator *(const mat& a, const mat& b) {
		mat p(a.row, b.col);
		for (int i = 0; i < a.row; i++) {
			for (int k = 0; k < a.col; k++) {
				if (!a.matrix[i][k])continue;
				for (int j = 0; j < b.col; j++) {
					if (!b.matrix[k][j])continue;
					p.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
					p.matrix[i][j] %= 1000000007;
				};
			}
		}
		return p;
	}
	mat pow2(mat& a, ll b) {
		int size = a.row;
		mat r(size, size), base = a;
		for (int i = 0; i < size; i++)
			r.matrix[i][i] = 1;
		while (b != 0) {
			if (b & 1) r = r * base;
			base = base * base;
			b >>= 1;
		}
		return r;
	}

	class dsu {
	public:
		int n, m;
		int fa[100007];
		int ranka[100007];
		int size[100007];
		int find(int x) {
			if (fa[x] != x)
				fa[x] = find(fa[x]);
			return fa[x];
		}
		void init(int n) {
			for (int i = 0; i <= n; i++)
				fa[i] = i, size[i] = 1;
			memset(ranka, 0, (n + 1) << 2);
		}
		void unite(int x, int y) {
			x = find(x);
			y = find(y);
			if (x == y)return;
			if (ranka[x] < ranka[y]) {
				size[y] += size[x];
				fa[x] = y;
			}
			else {
				fa[y] = x;
				size[x] += size[y];
				if (ranka[x] == ranka[y])ranka[x]++;
			}
		}
		bool same(int x, int y) {
			return find(x) == find(y);
		}
	};

	class fenwick_tree {
	public:
		int t[100007 << 2];
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


	bool splitArraySameAverage(vector<int>& nums) {
		int n = nums.size();
		int total = 0;
		for (int i = 0; i < n; i++)
			total += nums[i];
		int dp[20][1];
		for (int i = 1; i <= n / 2; i++) {
			if (i * total % n == 0) {

			}
		}
		return 0;
	}
};

int reverseint(ll n, int x) {
	int res = 0;
	for (int i = 0; i < x && n > 0; i++) {
		res |= (n & 1) << (x - 1 - i);
		n >>= 1;
	}
	return res;
}
void fj(int a, vector<ll>& w) {
	for (int i = 1; i * i <= a; i++) {
		if (!(a % i)) {
			w.emplace_back(i);
			if (a / i != i)
				w.emplace_back(a / i);
		}
	}
}


int main() {
	

	

	

	

	

	

	

	fastio;
	clock_t start, end;
	start = clock();

	

	

	

	

	

	

	

	


	
		


		

		

		

		

		

		

		

		


	int n, m;
	cin >> n >> m;
	int a[255];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	

	

	int pre[255];
	int pancakes[255];
	int now = 1;
	pancakes[0] = 0;
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + a[i];
		for (int j = 0; j < a[i]; j++) {
			pancakes[now++] = i;
			pancakes[now - 1] += pancakes[now - 2];
		}
	}
	int dp[255][255][255];
	memset(dp, 0x3f, sizeof dp);
	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int l = 0; i * l <= j && l <= j; l++) {

				int now = 0;
				for (int sum = j; sum <= m && (sum <= j + l || i == 0 && j == 0); sum++) {
					if (pre[i + 1] >= sum) 

						now = pre[i + 1] - sum;
					else {

						int tmp = sum - max(j, pre[i + 1]);
						now = pancakes[sum] - pancakes[sum - tmp] - i * tmp;
						
					}
					dp[i + 1][sum][sum - j] = min(dp[i + 1][sum][sum - j], dp[i][j][l] + now);
				}
			}
		}
	}
	int res = inf;
	for (int i = 0; i <= m; i++)
		res = min(res, dp[n][m][i]);
	cout << res << endl;
	

	

	end = clock();
	cerr << (end - start) * 1000.0 / CLOCKS_PER_SEC << "ms\n";
	return 0;
}
