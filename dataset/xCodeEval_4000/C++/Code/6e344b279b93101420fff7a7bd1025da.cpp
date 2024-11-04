#include <iostream>
#include <queue>
#include <map>
#include <bitset>
#include <string>
#include <set>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <stack>
#include <cstdlib>
#include <numeric>
#include <cassert>
#include <complex>
#include <iterator>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <array>
#include <regex>
#include <functional>
using namespace std;
#define maxn 200007
#define maxm 500007
#define maxq 1000007
#define maxl 1234
#define modn 998244353 
#define scan(a) scanf("%d",&a)
#define scanl(a) scanf("%lld",&a)
#define scanl2(a,b) scanf("%lld%lld",&a,&b)
#define scans(a) scanf("%s",a)
#define scans2(a,b) scanf("%s%s",a,b)
#define scand(a) scanf("%lf",&a)
#define scan2(a,b) scanf("%d%d",&a,&b)
#define scand2(a,b) scanf("%lf%lf",&a,&b)
#define scan3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scan4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define scan5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define print(a) printf("%d\n",a);
#define print2(a,b) printf("%d %d\n",a,b);
#define printl(a) printf("%lld\n",a);
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,a,b) for(int i=a;i>= b;i--)
#define fscan(a) fscanf(stream,"%d", &a);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
#define mp      make_pair	
#define pb      push_back
#define eb      emplace_back
#define mm(a,b) memset(a,b,sizeof a)
#define log2(n) (double)(log(n) / log(2.0))
#define _crt_disable_perfcrit_locks
#define bll __int128
#pragma warning(disable:4996)
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
bool MillerRabin(ll n) {
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
ll find_factorplus(ll n, ll c) {

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
	if (MillerRabin(n)) {
		prime.push_back(n);
		return;
	}
	ll x = n, p = c;
	while (x == n) {
		x = find_factorplus(x, c--);
	}
	find(n / x, p, prime);
	find(x, p, prime);
}
ll extend_gcd(ll a, ll  b, ll& x, ll& y) {
	if (b == 0) { x = 0; y = 1; return a; };
	if (a % b == 0) {
		x = 0;
		y = 1;
		return b;
	}
	ll res = extend_gcd(b, a % b, y, x);
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

class NestedInteger {
public:
	

	NestedInteger();

	

	NestedInteger(int value);

	

	bool isInteger() const;

	

	

	int getInteger() const;

	

	void setInteger(int value);

	

	void add(const NestedInteger& ni);

	

	

	const vector<NestedInteger>& getList() const;
};
class Solution {

public:


	class dsu {
	public:
		int n, m;
		int fa[100007];
		int num[100007];
		int ranka[100007];
		string name[100007];
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
				num[y] += num[x];
				name[y] = min(name[x], name[y]);
			}
			else {
				fa[y] = x;
				num[x] += num[y];
				name[x] = min(name[x], name[y]);
				if (ranka[x] == ranka[y])ranka[x]++;
			}
		}
		bool same(int x, int y) {
			return find(x) == find(y);
		}
	};


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
	class Dijkstra {
	public:
		int n, m, x;
		struct edge {
			int u, v, next, w;
			edge() { }
			edge(int u, int v, int next, int w) :u(u), v(v), next(next), w(w) { }
		};
		struct Node {
			int d, v, charge;
			Node(int d = 0, int v = 0, int charge = 0) :d(d), v(v), charge(charge) {}
			bool operator < (const Node& n)  const {
				return d > n.d;
			}
		};
		priority_queue<Node> q;

		bool vis[107][107];
		edge g[407];
		int st[407];
		int d[107][107];
		void init(int num) {
			n = num;
			m = 0;
			memset(st, -1, sizeof st);
		}
		void addedge(int u, int v, int w) {
			g[m] = edge(u, v, st[u], w);
			st[u] = m++;
			g[m] = edge(v, u, st[v], w);
			st[v] = m++;
		}
		void go(int s, int& cnt, vector<int>& charge) {
			memset(d, 0x3f, sizeof d);
			memset(vis, 0, sizeof vis);
			d[s][0] = 0;
			q.emplace(0, s, 0);
			edge e;
			Node x;
			int u, power;
			while (!q.empty()) {
				x = q.top();
				q.pop();
				u = x.v, power = x.charge;
				if (vis[u][power])continue;
				vis[u][power] = 1;
				if (power < cnt && d[u][power + 1] > d[u][power] + charge[u]) {
					d[u][power + 1] = d[u][power] + charge[u];
					q.emplace(d[u][power + 1], u, power + 1);
				}
				for (int i = st[u]; i != -1; i = g[i].next) {
					e = g[i];
					if (power >= e.w && d[e.v][power - e.w] > d[u][power] + e.w) {
						d[e.v][power - e.w] = d[u][power] + e.w;
						q.emplace(d[e.v][power - e.w], e.v, power - e.w);
					}
				}
			}
		}

	};

};
int main() {
	

	

	

	

	

	

	

	fastio;
	clock_t start, end;
	start = clock();

	

	

	

	

	

	

	

	
	
	

	

	

	

	

	

	

	


	int t;
	cin >> t;
	int n, m;
	string ss[1007];
	bool dp[1007];
	array<int, 3> seg[2][1007];
	string s;
	vector< array<int, 3>> res(500);
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> ss[i];
		cin >> s;
		unordered_map<int, bool> dp2, dp3;
		int num;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j++) {
				num = (ss[i][j] - '0') + (ss[i][j - 1] - '0') * 10;
				dp2[num] = 1;
				seg[0][num] = array<int, 3>{j, j + 1, i + 1};
				if (j > 1) {
					dp3[num + (ss[i][j - 2] - '0') * 100] = 1;
					seg[1][num + (ss[i][j - 2] - '0') * 100] = array<int, 3>{j - 1, j + 1, i + 1};
				}
			}
		}
		dp[0] = true;
		dp[2] = dp2[(s[1] - '0') + (s[0] - '0') * 10];
		for (int i = 3; i <= m; i++)
			dp[i] = (dp[i - 2] && dp2[(s[i - 1] - '0') + (s[i - 2] - '0') * 10]) || (dp[i - 3] && dp3[(s[i - 1] - '0') + (s[i - 2] - '0') * 10 + (s[i - 3] - '0') * 100]);
		if (!dp[s.length()])
			cout << -1 << endl;
		else {
			int now = m;
			int ans = 0;
			while (now) {
				if (dp[now - 2] && dp2[(s[now - 1] - '0') + (s[now - 2] - '0') * 10]) {
					res[ans++] = seg[0][(s[now - 1] - '0') + (s[now - 2] - '0') * 10];
					now -= 2;
				}
				else {
					res[ans++] = seg[1][(s[now - 1] - '0') + (s[now - 2] - '0') * 10 + (s[now - 3] - '0') * 100];
					now -= 3;
				}
			}
			cout << ans << endl;
			for (int i = ans - 1; i >= 0; i--)
				cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;

		}
	}
	

	end = clock();
	cerr << (end - start) * 1000.0 / CLOCKS_PER_SEC << "ms\n";
	return 0;
}
