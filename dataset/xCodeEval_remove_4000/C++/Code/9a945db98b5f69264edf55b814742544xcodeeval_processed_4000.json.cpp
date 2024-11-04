


using namespace std;
typedef long long ll;



namespace Template {
	ll ksm(ll b, ll e, ll mod) {
		ll r = 1;
		while (e) {
			if (e & 1) {
				r *= b;
				r %= mod;
			}
			b *= b;
			b %= mod;
			e >>= 1;
		}
		return r;
	}

	ll gcd(ll x, ll y) {
		return x == 0 ? y : gcd(y % x, x);
	}

	

	

	class segTree {
		

		int size;
		

		vector<ll>val, lazy;



		void push_down(int p, int l, int r) {
			int mid = (l + r) / 2;
			val[lson(p)] += lazy[p] * (mid - l + 1); lazy[lson(p)] += lazy[p];
			val[rson(p)] += lazy[p] * (r - mid); lazy[rson(p)] += lazy[p];
			lazy[p] = 0;
		}

		void build(int l, int r, int p, vector<int>* arr) {
			if (l == r) {
				val[p] = (*arr)[l];
			}
			else {
				int mid = (l + r) / 2;
				build(l, mid, lson(p), arr);
				build(mid + 1, r, rson(p), arr);
				val[p] = val[lson(p)] + val[rson(p)];
			}
		}

		void update(int l, int r, int p, int lll, int rrr, ll value) {
			if (l >= lll && r <= rrr) {
				val[p] += value * (r - l + 1);
				lazy[p] += value;
			}
			else {
				int ll = max(l, lll);
				int rr = min(r, rrr);
				val[p] += (rr - ll + 1) * value;
				int mid = (l + r) / 2;
				push_down(p, l, r);
				if (mid >= lll) {
					update(l, mid, lson(p), lll, rrr, value);
				}
				if (mid + 1 <= rrr) {
					update(mid + 1, r, rson(p), lll, rrr, value);
				}
			}
		}

		ll query(int l, int r, int p, int lll, int rrr) {
			if (l >= lll && r <= rrr) {
				return val[p];
			}
			else {
				int mid = (l + r) / 2;
				push_down(p, l, r);
				ll ans = 0;
				if (mid >= lll) {
					ans = query(l, mid, lson(p), lll, rrr);
				}
				if (mid + 1 <= rrr) {
					ans += query(mid + 1, r, rson(p), lll, rrr);
				}
				return ans;
			}
		}

	public:
		segTree(int n) {
			size = n;
			val.resize((n + 1) << 1);
			lazy.resize((n + 1) << 1);
		}

		void build(vector<int>* arr) {
			build(1, size, 1, arr);
		}

		void update(int lpos, int rpos, ll val) {
			update(1, size, 1, lpos, rpos, val);
		}

		ll query(int lpos, int rpos) {
			return query(1, size, 1, lpos, rpos);
		}
	};

	

	

	class id1 {
		vector<ll>val;
		int sz;

		inline int lowbit(int x) {
			return x & (-x);
		}

		ll query(int x) {
			ll res = 0;
			for (; x; x -= lowbit(x))
				res += val[x];
			return res;
		}
	public:
		id1(int n) {
			val.resize(n + 100, 0);
			sz = n;
		}

		void build(vector<int>* arr) {
			for (int i = 1; i <= sz; ++i) {
				val[i] += (*arr)[i];
				int j = i + lowbit(i);
				if (j <= sz) val[j] += val[i];
			}
		}

		void update(int pos, int value) {
			for (; pos <= sz; pos += lowbit(pos))
				val[pos] += value;
		}

		ll query(int lpos, int rpos) {
			return query(rpos) - query(lpos - 1);
		}
	};

	

	class trie {
		

	};

	

	class AC_automaton {

	};

	

	class SA {
		vector<int>sa, rk, id, rkb, cnt, px;
		static const int MAX = 300;
		int n, sz = MAX, lsz, i;
		bool cmp(int x, int y, int w) {
			return rkb[x] == rkb[y] && rkb[x + w] == rkb[y + w];
		}
	public:
		vector<int> solve(string s) {
			n = s.size();
			cnt.resize(100100, 0);
			sa.resize(n + 1000, 0);
			rk.resize(n + 1000, 0);
			id.resize(n + 1000, 0);
			rkb.resize(n + 1000, 0);
			px.resize(n + 1000, 0);
			for (i = 0, sz = MAX; i <= sz; i++)cnt[i] = 0;
			for (i = 1; i <= n; i++)cnt[rk[i] = s[i - 1]]++;
			for (i = 1; i < sz; i++)cnt[i] += cnt[i - 1];
			for (i = n; i >= 1; i--)sa[cnt[rk[i]]--] = i;
			for (int l = 1;; l <<= 1, sz = lsz) {
				for (i = 0; i <= sz; i++)cnt[i] = 0;
				for (lsz = 0, i = n; i > n - l; --i) id[++lsz] = i;
				for (i = 1; i <= n; ++i)if (sa[i] > l) id[++lsz] = sa[i] - l;
				for (i = 0; i <= sz; i++)cnt[i] = 0;
				for (i = 1; i <= n; i++)cnt[px[i] = rk[id[i]]]++;
				for (i = 1; i <= sz; i++)cnt[i] += cnt[i - 1];
				for (i = n; i >= 1; i--)sa[cnt[px[i]]--] = id[i];
				for (i = n; i >= 1; i--) rkb[i] = rk[i];
				for (lsz = 0, i = 1; i <= n; i++) rk[sa[i]] = (cmp(sa[i], sa[i - 1], l) ? lsz : ++lsz);
				if (lsz == n)break;
			}
			return sa;
		}
		

	};

	

	class KMP {
		

	};

	class FFT {
		

	};

	class NTT {
		

	};

	class LP {
		

	};

	

	class Dinic {
		static const int maxn = 1001;
		const ll INF = 0x3f3f3f3f3f3f3f3f;
		struct Edge {
			ll from, to, cap, flow;

			Edge(ll u, ll v, ll c, ll f) : from(u), to(v), cap(c), flow(f) {}
		};
		int n, m, s, t;
		vector<Edge> edges;
		vector<int> G[maxn];
		int d[maxn], cur[maxn];
		bool vis[maxn];

	public:
		Dinic(int n) {
			init(n);
		}

		void init(int n) {
			for (int i = 0; i < n; i++) G[i].clear();
			edges.clear();
		}

		void AddEdge(int from, int to, ll cap) {
			edges.push_back(Edge(from, to, cap, 0));
			edges.push_back(Edge(to, from, 0, 0));
			m = edges.size();
			G[from].push_back(m - 2);
			G[to].push_back(m - 1);
		}

		bool BFS() {
			memset(vis, 0, sizeof(vis));
			queue<int> Q;
			Q.push(s);
			d[s] = 0;
			vis[s] = 1;
			while (!Q.empty()) {
				int x = Q.front();
				Q.pop();
				for (int i = 0; i < G[x].size(); i++) {
					Edge& e = edges[G[x][i]];
					if (!vis[e.to] && e.cap > e.flow) {
						vis[e.to] = 1;
						d[e.to] = d[x] + 1;
						Q.push(e.to);
					}
				}
			}
			return vis[t];
		}

		ll DFS(int x, ll a) {
			if (x == t || a == 0) return a;
			ll flow = 0, f;
			for (int& i = cur[x]; i < G[x].size(); i++) {
				Edge& e = edges[G[x][i]];
				if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
					e.flow += f;
					edges[G[x][i] ^ 1].flow -= f;
					flow += f;
					a -= f;
					if (a == 0) break;
				}
			}
			return flow;
		}

		ll Maxflow(int s, int t) {
			this->s = s;
			this->t = t;
			ll flow = 0;
			while (BFS()) {
				memset(cur, 0, sizeof(cur));
				flow += DFS(s, INF);
			}
			return flow;
		}
	};

	

	class Dijkstra {
		vector<vector<pair<ll, int>>>gra;
		vector<ll>dis;
	public:
		const ll inf = 0x3f3f3f3f3f3f3f3f;
	public:
		Dijkstra(int n) {
			gra = vector<vector<pair<ll, int>>>(n + 1);
			dis = vector<ll>(n + 1, inf);
		}

		void add(int u, int v, ll w) {
			gra[u].push_back({ w,v });
		}

		vector<ll> solve(int s) {
			dis[s] = 0;
			priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
			pq.push({ 0, s });
			while (!pq.empty()) {
				pair<ll, int> p = pq.top(); pq.pop();
				ll dist = p.first;
				int from = p.second;
				if (dis[from] < dist)continue;
				for (auto& p : gra[from])if (dist + p.first < dis[p.second])pq.push({ dis[p.second] = dist + p.first,p.second });
			}
			return dis;
		}
	};

	class directed_graph {
		static const ll inf = LLONG_MAX / 2;
	public:
		class Dij {
			int n, m, s = 1;
			typedef pair<ll, ll> pi;
			

			int cnt = 0;
			vector<ll>d;
			vector<int>nxt, head, w, to;
			priority_queue<pi, vector<pi>, greater<pi> >heap;
			

		public:
			void dijkstra() {
				int i, x;
				for (i = 1; i <= n; i++)d[i] = inf;
				heap.push(pi(d[s] = 0, s));
				while (!heap.empty()) {
					pi t = heap.top(); heap.pop();
					if (d[x = t.second] < t.first)continue;
					for (i = head[x]; i; i = nxt[i])if (d[x] + w[i] < d[to[i]])heap.push(pi(d[to[i]] = d[x] + w[i], to[i]));
				}
			}
			void out() {
				for (int i = 1; i <= n; i++) {
					if (d[i] == inf) {
						cout << -1 << " ";
					}
					else {
						cout << d[i] << " ";
					}
				}
			}

			void add(int x, int y, int z) {
				cnt++;
				nxt[cnt] = head[x];
				head[x] = cnt;
				to[cnt] = y;
				w[cnt] = z;
			}

			Dij(int n, int m) {
				

				this->n = n;
				this->m = m;
				d = vector<long long>(n + 1);
				head = vector<int>(n + 1);
				nxt = vector<int>(m + 1);
				w = nxt;
				to = nxt;
				for (int i = 1; i <= m; i++) {

				}
			}
		};
		class SPFA {
			int q[66000]; unsigned short h, t;
			int n, m, s = 1;
			typedef pair<int, int> pi;
			int cnt = 0;
			vector<long long>d;
			vector<int>nxt, g, w, v;
			vector<bool>in;
			void add(int x, int y) {
				if (y >= d[x])return;
				d[x] = y;
				if (!in[x]) {
					in[x] = 1;
					if (y < d[q[h]])q[--h] = x; else q[++t] = x;
				}
			}
		public:
			void spfa() {
				int i, x;
				for (i = h = 1; i <= n; i++)d[i] = inf, in[i] = 0;
				add(s, t = 0);
				while (h != t + 1)for (i = g[x = q[h++]], in[x] = 0; i; i = nxt[i])add(v[i], d[x] + w[i]);
			}
			void out() {
				for (int i = 1; i <= n; i++) {
					cout << d[i] << " ";
				}
			}
			SPFA() {
				

				cin >> n >> m >> s;
				d = vector<long long>(n + 1);
				g = vector<int>(n + 1);
				nxt = vector<int>(m + 1);
				w = nxt;
				v = nxt;
				in = vector<bool>(n + 1, 0);
				for (int i = 1; i <= m; i++) {
					int x, y, z;
					cin >> x >> y >> z;
					nxt[i] = g[x];
					g[x] = i;
					v[i] = y;
					w[i] = z;
				}
			}
		};
	};

	class Union_find {
		vector<int>f;
	public:
		Union_find(int n) {
			f.resize(n + 1);
			for (int i = 0; i <= n; i++) {
				f[i] = i;
			}
		}
		int find(int x) {
			return f[x] == x ? x : f[x] = find(f[x]);
		}
		void merge(int x, int y) {
			if (find(x) > find(y)) {
				f[find(x)] = find(y);
			}
			else {
				f[find(y)] = find(x);
			}
		}
	};

	

	class MST {
	protected:
		typedef pair<ll, pair<ll, ll>>edge;
		vector<edge>edg;
		int n;
	public:
		const ll UNCONNECT = -1;
		MST(int n) {
			this->n = n;
		}

		void add(int u, int v, int w) {
			edg.push_back({ w,{u,v} });
		}
	};

	class id0 :public MST {
	protected:
		Union_find a;
	public:
		id0(int n) : MST(n), a(n) {}
		ll solve() {
			priority_queue<edge, vector<edge>, greater<edge>>pq;
			for (int i = 0; i < (int)edg.size(); i++) {
				pq.push(edg[i]);
			}
			ll ans = 0;
			while (!pq.empty()) {
				edge e = pq.top(); pq.pop();
				ll u = e.second.first, v = e.second.second, w = e.first;
				if (a.find(u) == a.find(v))continue;
				ans += w;
				a.merge(u, v);
			}
			for (int i = 2; i <= n; i++) {
				if (a.find(i) == i)return UNCONNECT;
			}
			return ans;
		}
	};

}
using namespace Template;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = a + c + d;
	int B = b + c + d;
	string s;
	cin >> s;
	int As = 0, Bs = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') {
			As++;
		}
		else {
			Bs++;
		}
	}
	int len1 = 0;
	vector<int> len2, len3;
	char first = s[0];
	char last = s[0];
	int len = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == last) {
			if (len & 1) {
				len1+=len>>1;
			}
			else {
				if (first == 'A') {
					len2.push_back(len>>1);
				}
				else {
					len3.push_back(len>>1);
				}
			}
			len = 1;
			first = last = s[i];
		}
		else {
			last = s[i];
			len++;
		}
	}
	if (len & 1) {
		len1 += len >> 1;
	}
	else {
		if (first == 'A') {
			len2.push_back(len >> 1);
		}
		else {
			len3.push_back(len >> 1);
		}
	}
	if (As != A || Bs != B) {
		cout << "NO" << endl;
		return;
	}
	sort(len2.begin(), len2.end());
	sort(len3.begin(), len3.end());
	for (int i = 0; i < len2.size(); i++) {
		if ((len2[i]) <= c) {
			c -= len2[i];
		}
		else {
			len2[i] -=  c;
			c = 0;
			len1 += len2[i] - 1;
		}
	}
	for (int i = 0; i < len3.size(); i++) {
		if (len3[i] <= d) {
			d -= len3[i];
		}
		else {
			len3[i] -= d;
			d = 0;
			len1 += len3[i] - 1;
		}
	}
	if (c + d <= len1) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	

	

	

}

int main() {
	init();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}

