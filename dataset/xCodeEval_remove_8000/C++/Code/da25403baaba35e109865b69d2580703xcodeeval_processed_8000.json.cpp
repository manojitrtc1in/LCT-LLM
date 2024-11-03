












using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;









const int dr[4] = { 0,0,-1,1 }, dc[4] = { -1,1,0,0 };
class Dijkstra {
	int N;
	vector<vector<pair<int, int> > > E;
public:
	Dijkstra(int n) {
		N = n;
		E = vector<vector<pair<int, int> > >(N + 1);
	}
	void insert(int u, int v, int w) {
		E[u].push_back(make_pair(v, w));
	}
	vector<int> dijkstra(int start, int end) {
		vector<int> dist(N + 1, INF);
		dist[start] = 0;
		priority_queue<pair<int, int> > pq;
		pq.push(make_pair(0, start));
		while (!pq.empty()) {
			int w = -pq.top().first;
			int u = pq.top().second;
			if (u == end) return dist;
			pq.pop();
			if (dist[u] < w) continue;
			for (int i = 0; i < E[u].size(); i++) {
				int v = E[u][i].first;
				int w2 = w + E[u][i].second;
				if (dist[v] > w2) {
					dist[v] = w2;
					pq.push(make_pair(-w2, v));
				}
			}
		}
		return dist;
	}
	void g() {
		int i, n, e, s, u, v, w; vector<int> ans;
		scanf("%d%d", &n, &e);
		Dijkstra dk(n);
		scanf("%d", &s);
		for (i = 0; i < e; i++) {
			scanf("%d%d%d", &u, &v, &w);
			dk.insert(u, v, w);
		}
		ans = dk.dijkstra(s, N);
		for (i = 1; i <= n; i++) {
			if (ans[i] >= INF) printf("INF\n");
			else printf("%d\n", ans[i]);
		}
	}
};
class Prim {
	int N;
	vector<vector<pair<int, int> > > E;
public:
	Prim(int n) {
		N = n;
		E = vector<vector<pair<int, int> > >(N + 1);
	}
	void insert(int u, int v, int w) {
		E[u].push_back(make_pair(v, w));
	}
	vector<int> execute(ll &cost) {
		int k;
		vector<int> dist(N + 1, INF);
		vector<bool> selected(N + 1, false);
		dist[1] = 0; cost = 0;
		priority_queue<pair<int, int> > pq;
		pq.push(make_pair(0, 1));
		for (k = 0; k < N; k++) {
			int w = -pq.top().first;
			int u = pq.top().second;
			pq.pop();
			if (selected[u] == true) {
				k--; continue;
			}
			cost += w; selected[u] = true;
			for (int i = 0; i < E[u].size(); i++) {
				int v = E[u][i].first;
				int w2 = E[u][i].second;
				if (selected[v] == true) continue;
				if (dist[v] > w2) {
					dist[v] = w2;
					pq.push(make_pair(-w2, v));
				}
			}
		}
		return dist;
	}
	void g() {
		int i, n, e, s, u, v, w; ll cost; vector<int> ans;
		scanf("%d%d", &n, &e);
		Prim pm(n);
		scanf("%d", &s);
		for (i = 0; i < e; i++) {
			scanf("%d%d%d", &u, &v, &w);
			pm.insert(u, v, w);
		}
		ans = pm.execute(cost);
		printf("%d", cost);
	}
};
class Floyd {
	int N;
	vector<vector<int> > E;
public:
	Floyd(int n) {
		N = n;
		E = vector<vector<int> >(N + 1, vector<int>(N + 1, INF));
	}
	void setRC(int r, int c, int w) {
		E[r][c] = w;
	}
	int getRC(int r, int c) {
		return E[r][c];
	}
	void execute() {
		int i, j, k;
		for (i = 1; i <= N; ++i) E[i][i] = 0;
		for (k = 1; k <= N; ++k) for (i = 1; i <= N; ++i) for (j = 1; j <= N; ++j)
			E[i][j] = min(E[i][j], E[i][k] + E[k][j]);
	}
};
class id5 {
	vector<vector<pair<int, int> > > E; vector<int> A;
	int N;
public:
	id5(int n) {
		N = n;
		E = vector<vector<pair<int, int> > >(N + 1);
		A = vector<int>(N + 1);
	}
	void insert(int u, int v, int w) {
		E[u].push_back(make_pair(v, w));
	}
	void insert_fb(int u, int v, int w) {
		E[u].push_back(make_pair(v, w));
		E[v].push_back(make_pair(u, w));
	}
	int dfsAll(int start, int end) {
		vector<bool> visited = vector<bool>(N + 1, false);
		return dfs(start, end, visited);
	}
	int dfs(int start, int end, vector<bool> &visited) {
		if (start == end) return 1;
		visited[start] = true;
		for (int i = 0; i < E[start].size(); i++) {
			int v = E[start][i].first, c = E[start][i].second;
			if (!visited[v]) {
				if (dfs(v, end, visited)) return 1;
			}
		}
		return 0;
	}
	void setA(int a, int b) {
		A[a] = b;
	}
	int dfsAll2() {
		vector<int> visited(N + 1, 0);
		int i, j, seq = 0, ret = 0, a;
		for (i = 1; i <= N; i++) dfs2(i, visited, ++seq);
		for (i = 1; i <= N; i++) {
			for (j = a = 0; j < E[i].size(); j++) {
				a += E[i][j].second;
			}
			if (ret < a) ret = a;
		}
		return ret;
	}
	int dfs2(int start, vector<int> &visited, ll seq) {
		visited[start] = seq;
		int ret = A[start];
		for (int i = 0; i < E[start].size(); i++) {
			int v = E[start][i].first; ll c = E[start][i].second;
			if (visited[v] < seq) {
				if (E[start][i].second == -1) E[start][i].second = dfs2(v, visited, seq);
				if (ret < E[start][i].second) ret = E[start][i].second;
			}

		}
		return ret;
	}
	void g() {
		int i, j, N, m, a, b, c, a2, b2, c2, lo, hi, mid, tmp, start, end;
		scanf("%d%d", &N, &m);
		id5 dg(N);
		for (i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			dg.insert(a, b, 0);
		}
		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			if (dg.dfsAll(a, b)) c = -1;
			else if (dg.dfsAll(b, a)) c = 1;
			else c = 0;
			printf("%d\n", c);
		}
	}
};
class DFS_Map {
	vector<vector<int> > E;
	int R, C;
public:
	DFS_Map(int r, int c) {
		R = r; C = c;
		E = vector<vector<int> >(R + 2, vector<int>(C + 2, 0));
	}
	void setRC(int r, int c, int w) {
		E[r][c] = w;
	}
	int getRC(int r, int c) {
		return E[r][c];
	}
	void dfs(int rr, int cc, vector<vector<bool> > &visited) {
		int i, r, c, v;
		visited[rr][cc] = true;
		for (i = 0; i < 4; i++) {
			r = rr + dr[i]; c = cc + dc[i];
			if (E[r][c] && !visited[r][c]) {
				dfs(r, c, visited);
			}
		}
	}
	void dfsAll() {
		vector<vector<bool> > visited = vector<vector<bool> >(R + 2, vector<bool>(C + 2, 0));
		int r, c;
		for (r = 1; r <= R; r++) for (c = 1; c <= C; c++) if (!visited[r][c]) dfs(r, c, visited);
	}
};
class id7 {
	vector<vector<pair<int, int> > > E; vector<int> IN;
	int N;
public:
	int is_cycle() { 

		for (int i = 1; i <= N; i++) if (IN[i]>0) return 1;
		return 0;
	}
	id7(int n) {
		N = n;
		E.clear(); IN.clear();
		E = vector<vector<pair<int, int> > >(N + 1);
		IN = vector<int>(N + 1, 0);
	}
	void insert(int u, int v, int w) {
		E[u].push_back(make_pair(v, w));
		IN[v]++;
	}
	void insert_fb(int u, int v, int w) {
		E[u].push_back(make_pair(v, w));
		E[v].push_back(make_pair(u, w));
	}
	vector<ll> bfs(int start, int end, int min_weight) {
		vector<bool> visited = vector<bool>(N + 1, false);
		vector<ll> weight(N + 1, INF_LONG);
		queue<int> Q;
		visited[start] = true; weight[start] = 0;
		Q.push(start);
		while (!Q.empty()) {
			int u = Q.front(), w = weight[u]; if (u == end) break;
			Q.pop();
			for (int i = 0; i < E[u].size(); i++) {
				int v = E[u][i].first, c = E[u][i].second;
				if (c >= min_weight && !visited[v]) {
					Q.push(v); weight[v] = w + c;
					visited[v] = true;
				}
			}
		}
		return weight;
	}
	vector<int> topologicalSort() {
		vector<int> order;
		queue<int> Q;
		for (int i = 1; i <= N; i++) if (!IN[i]) Q.push(i);
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop(); order.push_back(u);
			for (int i = 0; i < E[u].size(); i++) {
				int v = E[u][i].first;
				if (IN[v]>0) {
					IN[v]--;
					if (!IN[v]) Q.push(v);
				}
			}
		}
		return order;
	}
	vector<int> topologicalSortPQ() {
		vector<int> order;
		priority_queue<int> pq;
		for (int i = 1; i <= N; i++) if (!IN[i]) pq.push(-i);
		while (!pq.empty()) {
			int u = -pq.top();
			pq.pop(); order.push_back(-u);
			for (int i = 0; i < E[u].size(); i++) {
				int v = E[u][i].first;
				if (IN[v]>0) {
					IN[v]--;
					if (!IN[v]) pq.push(-v);
				}
			}
		}
		return order;
	}
	int f() {
		int v, u, i; vector<int> IN2;
		for (u = 1; u <= N; u++) {
			for (i = 0; i<E[u].size(); i++) {
				v = E[u][i].first;
				if (IN[v] == 1) {
					IN2 = IN;
					IN[v]--;
					topologicalSort();
					if (!is_cycle()) return 1;
					IN = IN2;
				}
			}
		}
		return 0;
	}
	void g() {
		int i, j, N, m, a, b, c, a2, b2, c2, lo, hi, mid, tmp, start, end;
		vector <tuple<int, int, int> > X; vector<ll> y;
		scanf("%d%d", &N, &m);
		id7 bg(N); X.reserve(m);
		for (i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			if (a > b) tmp = a, a = b, b = tmp;
			X.push_back(make_tuple(a, b, -c));
		}
		scanf("%d%d", &start, &end);
		sort(X.begin(), X.end());
		bg.insert_fb(get<0>(X[0]), get<1>(X[0]), -get<2>(X[0]));
		for (i = 1; i < m; i++) {
			a = get<0>(X[i - 1]); b = get<1>(X[i - 1]); c = get<2>(X[i - 1]);
			a2 = get<0>(X[i]); b2 = get<1>(X[i]); c2 = get<2>(X[i]);
			if (a == a2 && b == b2) continue;
			bg.insert_fb(a2, b2, -c2);
		}
		lo = 1; hi = INF;
		while (lo < hi) {
			mid = (lo + hi + 1) / 2;
			y = bg.bfs(start, end, mid);
			if (y[end] < INF_LONG) {
				lo = mid;
			}
			else {
				hi = mid - 1;
			}
		}
		printf("%d", lo);
	}
};
class id4 {
	vector<vector<int> > E;
	int R, C;
public:
	id4(int r, int c) {
		R = r; C = c;
		E = vector<vector<int> >(R + 2, vector<int>(C + 2, 0));
	}
	void setRC(int r, int c, int w) {
		E[r][c] = w;
	}
	int getRC(int r, int c) {
		return E[r][c];
	}
	int bfsAll() {
		int r, c, ret = 0;
		vector<vector<int> > visited = vector<vector<int> >(R + 2, vector<int>(C + 2, 0));
		for (r = 1; r <= R; r++) {
			for (c = 1; c <= C; c++) {
				if (E[r][c] && !visited[r][c]) {
					ret++; bfs(r, c, visited);
				}
			}
		}
		return ret;
	}
	int bfsAll(vector<pair<int, int> > &Q) {
		int i, r, c, ret = 0;
		vector<vector<int> > visited = vector<vector<int> >(R + 2, vector<int>(C + 2, 0));
		for (i = 0; i < Q.size(); i++) {
			r = Q[i].first; c = Q[i].second;
			if (!visited[r][c]) {
				ret++; bfs(r, c, visited);
			}
		}
		return ret;
	}
	void bfs(int rr, int cc, vector<vector<int> > &visited) {
		int i, r, c, r2, c2;
		queue<pair<int, int> > Q;
		Q.push(make_pair(rr, cc)); visited[rr][cc] = 1;
		while (!Q.empty()) {
			r = Q.front().first;
			c = Q.front().second;
			Q.pop();
			for (i = 0; i < 4; i++) {
				r2 = r + dr[i]; c2 = c + dc[i];
				if (E[r2][c2] && !visited[r2][c2]) {
					Q.push(make_pair(r2, c2)); visited[r2][c2] = visited[r][c] + 1;
				}
			}
		}
	}
	void g() {
		int i, j, r, c, r2, c2, R, C, a, ans = 0, idx = 0; vector <pair<int, int> > Q[2]; vector<int> X;
		scanf("%d%d", &R, &C);
		id4 bm(R, C);
		X.reserve(10004); Q[0].reserve(10004); Q[1].reserve(10004);
		for (r = 1; r <= R; r++) for (c = 1; c <= C; c++) {
			scanf("%d", &a); bm.setRC(r, c, a); if (a) Q[0].push_back(make_pair(r, c));
		}
		while (1) {
			a = bm.bfsAll(Q[idx]);
			if (a > 1) break;
			else if (a == 0) {
				ans = 0; break;
			}
			ans++; X.resize(0); Q[1 - idx].resize(0);
			for (i = 0; i < Q[idx].size(); i++) {
				r = Q[idx][i].first; c = Q[idx][i].second; a = 0;
				for (j = 0; j < 4; j++) {
					r2 = r + dr[j]; c2 = c + dc[j];
					if (bm.getRC(r2, c2) == 0) a++;
				}
				X.push_back(a);
			}
			for (i = 0; i < Q[idx].size(); i++) {
				r = Q[idx][i].first; c = Q[idx][i].second; a = bm.getRC(r, c) - X[i];
				if (a <= 0) {
					a = 0;
				}
				else {
					Q[1 - idx].push_back(make_pair(r, c));
				}
				bm.setRC(r, c, a);
			}
			idx = 1 - idx;
		}
		printf("%d", ans);
	}
};
class Number {
public:
	Number() {

	}
	int getDigitNum(ull xx) {
		ull x; int ret = 0;
		for (x = 1; x <= xx; x *= 10, ret++);
		return ret;
	}
	int getDigitSum(int xx) {
		int x, a = 0;
		for (x = xx; x; x /= 10) a += (x % 10);
		return a;
	}
	int getMSB(ll xx) {
		int i;
		for (i = 0; (1ll << i) <= xx; i++);
		return i - 1;
	}
	ll convertBinaryToBase(ll x, int base) {
		if (x == 0) return 0;
		return base * convertBinaryToBase(x / 2, base) + (x % 2);
	}
	ll findFactor(ll k) {
		for (ll d = 2; d * d <= k; d++) if (k % d == 0) return d;
		return 0;
	}
};
class Palindrome {
public:
	Palindrome() {

	}
	int isPalindrome(ll xx) {
		ll x; int i, n; vector <int> v;
		for (x = xx; x > 0; x /= 10) {
			v.push_back(x % 10);
		}
		n = v.size();
		for (i = 0; i < n / 2; i++) {
			if (v[i] != v[n - i - 1]) return 0;
		}
		return 1;
	}
};
class BigNumber {
public:
	BigNumber() {

	}
	string add(string &s1, string &s2) {
		int i, j, k, n1, n2, a; string s3; vector<int> v;
		n1 = s1.size();
		n2 = s2.size();
		v.reserve(max(n1, n2) + 1);
		for (i = n1 - 1, j = n2 - 1; i >= 0 && j >= 0; i--, j--) {
			a = s1[i] - '0' + s2[j] - '0';
			v.push_back(a);
		}
		while (i >= 0) {
			a = s1[i] - '0';
			v.push_back(a);
			i--;
		}
		while (j >= 0) {
			a = s2[j] - '0';
			v.push_back(a);
			j--;
		}
		for (i = 0, a = 0; i < v.size(); i++) {
			a += v[i];
			if (a >= 10) {
				v[i] = a - 10;
				a = 1;
			}
			else {
				v[i] = a;
				a = 0;
			}
		}
		if (a) v.push_back(a);
		s3.reserve(v.size());
		for (i = v.size() - 1; i >= 0; i--) s3 += (char)(v[i] + '0');
		s3 += '\n';
		return s3;
	}
};
class PrimeNumber {
	int N; vector<int> NP, P;
	ll _powmod(ll a, ll b) {
		if (b == 0) return 1;
		if (b & 1) return a * _powmod(a, b - 1) % MOD;
		return _powmod(a * a % MOD, b / 2);
	}
public:
	PrimeNumber() {

	}
	PrimeNumber(int n) {
		N = n;
		NP.reserve(N + 4);
		P.reserve(N / 4);
		for (int i = 2; i*i <= N; i++) {
			if (NP[i]) continue;
			for (int j = i*i; j <= N; j += i) NP[i] = 1;
		}
		for (int i = 2; i <= N; i++) if (!NP[i]) P.push_back(i);
	}

	ll gcd(ll x, ll y) {
		ll z;
		while (x) {
			z = y%x;
			y = x;
			x = z;
		}
		return y;
	}

	ll powermod(ll p, ll q) {
		ll g = gcd(p, q);
		p /= g; q /= g;
		return p * _powmod(q, MOD - 2) % MOD;
	}

	vector<int> factorization(int x) {
		vector<int> ret; int i;
		if (x == 1) {
			ret.push_back(1);
			return ret;
		}
		ret.push_back(1); ret.push_back(x);
		for (i = 2; i*i < x; i++) {
			if (x%i == 0) {
				ret.push_back(i);
				ret.push_back(x / i);
			}
		}
		if (i*i == x) ret.push_back(i);
		return ret;
	}

	int factorization2(int x) {
		int ret = 0, i;
		if (x == 1) {
			return 1;
		}
		ret = 2;
		for (i = 2; i*i < x; i++) {
			if (x%i == 0) {
				ret += 2;
			}
		}
		if (i*i == x) ret++;
		return ret;
	}
	void primeFactorize(map<ll,ll> &mp, ll xx) {
		for (ll i=2; i*i<=xx; i++) {
			if (xx%i==0) {
				while(xx%i==0) {
					mp[i]++;
					xx/=i;
				}
			}
		}
		if (xx!=1) mp[xx]++;
	}
};
class BitOperation {
public:
	BitOperation() {

	}
	int getOneBitNum(int xx) {
		int a = 0, x;
		for (x = xx; x; x = x&(x - 1)) a++;
		return a;
	}
};
class Comb {
	vector<vector<ll> > C; vector<ll> F; int N;

public:
	Comb() {

	}
	Comb(int n) {
		init(n);
	}
	void init(int n) {
		N = n;
		C.resize(N + 1);
		for (int i = 0; i <= N; i++) C[i].resize(i + 1);
		for (int i = 0; i <= N; i++) C[i][i] = C[i][0] = 1;
		for (int i = 1; i <= N; i++) for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD_COMB;
		F.resize(N + 1);
		F[0] = F[1] = 1;
		for (int i = 1; i <= n; i++) F[i] = (F[i - 1] * i) % MOD_COMB;
	}
	ll getC(int n, int r) {
		return C[n][r];
	}
	ll getF(int n) {
		return F[n];
	}
	ll get_comb(int n, int r) {
		if (n == r || r == 0) return 1;
		if (n <= 1000) return getC(n, r);
		ll ret = 1; int i;
		if (r > n / 2) r = n - r;
		for (i = n; i > n - r; i--) ret *= i;
		for (i = 2; i <= r; i++) ret /= i;
		return ret;
	}
};
class Sort {
	vector<int> tmp;
	int N;
public:
	Sort(int n) {
		N = n;
		tmp.reserve(n + 4);
	}
	void merge_sort(vector<int> &x, int lo, int hi) {
		if (lo >= hi) return;
		int i, j, k, mid = (lo + hi) / 2;
		merge_sort(x, lo, mid); merge_sort(x, mid + 1, hi);
		for (i = lo, j = mid + 1, k = lo; i <= mid && j <= hi; k++) {
			if (x[i]<x[j]) tmp[k] = x[i++]; else tmp[k] = x[j++];
		}
		if (i <= mid) {
			for (; i <= mid; i++, k++) tmp[k] = x[i];
		}
		if (j <= hi) {
			for (; j <= hi; j++, k++) tmp[k] = x[j];
		}
		for (i = lo; i <= hi; i++) x[i] = tmp[i];
	}
};
class PSum {
	PSum() {

	}
	vector<int> makeSum(const vector<int> &a, int n) {
		vector<int> ret(a.size());
		ret[0] = a[0];
		for (int i = 1; i < a.size(); ++i)
			ret[i] = ret[i - 1] + a[i];
		return ret;
	}
	vector<vector<int> > makeSum(const vector<vector<int> > &a, int n, int m) {
		vector<vector<int> > ret(n, vector<int>(m));
		int i, j;
		for (i = 0; i < n; i++) ret[i][0] = a[i][0];
		for (i = 0; i < n; i++) {
			for (j = 1; j < m; j++) {
				ret[i][j] = ret[i][j - 1] + a[i][j];
			}
		}
	}
	int getSum(const vector<int>& psum, int a, int b) {
		if (a == 0) return psum[b];
		return psum[b] - psum[a - 1];
	}
	int getSum(const vector<vector<int> >&psum, int r1, int c1, int r2, int c2) {
		int ret = psum[r2][c2];
		if (r1 > 0) ret -= psum[r1 - 1][c2];
		if (c1 > 0) ret -= psum[r2][c1 - 1];
		if (r1 > 0 && c1 > 0) ret += psum[r1 - 1][c1 - 1];
		return ret;
	}
};
class id3 {
	int N;
	vector<int> P, R, A;
public:
	id3(int n) {
		N = n;
		P = vector<int>(n + 1);
		R = vector<int>(n + 1);
		A = vector<int>(n + 1);
		for (int i = 1; i <= n; i++) P[i] = i, R[i] = 0, A[i] = 1;
	}
	int getA(int x) {
		return A[x];
	}
	int find_set(int x) {
		if (P[x] == x) return x;
		int pa = find_set(P[x]);
		return P[x] = pa;
	}
	int union_set(int x, int y) {
		int px, py;
		px = find_set(x); py = find_set(y);
		if (px == py) return px;
		if (R[px]>R[py]) {
			P[py] = px;
			A[px] += A[py];
			return px;
		}
		else {
			P[px] = py;
			A[py] += A[px];
			if (R[px] == R[py]) R[py]++;
			return py;
		}
	}
};
class LIS { 

	int N, BI;
public:
	LIS(int n) {
		N = n;
	}
	int execute(vector<int> &A) { 

		int i, lo, hi, x, vi;
		vector<int> v = vector<int>(N, 0);
		vi = -1;
		v[++vi] = A[0];
		for (i = 1; i < N; i++) {
			if (A[i] > v[vi]) {
				v[++vi] = A[i];
				continue;
			}
			for (lo = 0, hi = vi; lo < hi; ) {
				if (v[(lo + hi) / 2] >= A[i]) hi = (lo + hi) / 2;
				else lo = (lo + hi) / 2 + 1;
			}
			v[hi] = A[i];
		}
		return vi + 1;
	}

	vector<int> execute2(vector<int> &A, int &len) { 

		vector<int> v, v1, p, ret; int i, j; 

		v.push_back(A[0]); v1.push_back(0);
		p = vector<int>(N, -1);
		for (int i = 1; i < A.size(); i++) {
			if (v.back() < A[i]) {
				p[i] = v1.back();
				v.push_back(A[i]);
				v1.push_back(i);
			}
			else {
				vector<int>::iterator itr = lower_bound(v.begin(), v.end(), A[i]);
				*itr = A[i];
				int idx = itr - v.begin();
				if (idx != 0) {
					p[i] = v1[idx - 1];
				}
				v1[idx] = i;
			}
		}
		len = v1.size();
		ret = vector<int>(len);
		for (i = v1.back(), j = len - 1; i != -1; i = p[i], j--) ret[j] = A[i];
		return ret;
	}

	int execute3(vector<int> &A) { 

		int i, j, ret = 0;
		vector<int> v = vector<int>(N, 0);
		for (i = 0; i<A.size(); i++) {
			for (j = 0; j<i; j++) if (A[j]<A[i] && v[i]<v[j]) v[i] = v[j];
			v[i]++;
		}
		for (i = 0; i<v.size(); i++) if (v[i]>ret) ret = v[i];
		return ret;
	}
};
class id1 {
	vector<ll> ST; vector<int> A; int N;

	ll _init(vector<int>&a, int left, int right, int node) {
		if (left == right) return ST[node] = a[left];
		int mid = (left + right) / 2;
		ll lv = _init(a, left, mid, node * 2), rv = _init(a, mid + 1, right, node * 2 + 1);
		return ST[node] = lv + rv;
	}

	ll _query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right<nodeLeft || nodeRight<left) return 0;
		if (left <= nodeLeft && nodeRight <= right) return ST[node];
		int mid = (nodeLeft + nodeRight) / 2;
		ll lv = _query(left, right, node * 2, nodeLeft, mid), rv = _query(left, right, node * 2 + 1, mid + 1, nodeRight);
		return lv + rv;
	}

	ll _update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
		if (index<nodeLeft || nodeRight<index) return ST[node];
		if (nodeLeft == nodeRight) return ST[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		ll lv = _update(index, newValue, node * 2, nodeLeft, mid), rv = _update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
		return ST[node] = lv + rv;
	}

public:
	id1(int n) {
		N = n;
		ST = vector<ll>(n * 4 + 4);
		A = vector<int>(n + 4);
	}

	void setA(int x, int y) {
		A[x] = y;
	}

	void init() {
		_init(A, 1, N, 1);
	}

	ll query(int left, int right) {
		return _query(left, right, 1, 1, N);
	}

	ll update(int index, int newValue) {
		return _update(index, newValue, 1, 1, N);
	}
};
class id6 {
	vector<ll> ST; vector<int> A; int N;

	ll _init(vector<int>&a, int left, int right, int node) {
		if (left == right) return ST[node] = a[left];
		int mid = (left + right) / 2;
		ll lv = _init(a, left, mid, node * 2), rv = _init(a, mid + 1, right, node * 2 + 1);
		return ST[node] = min(lv, rv);
	}

	ll _query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right<nodeLeft || nodeRight<left) return INF;
		if (left <= nodeLeft && nodeRight <= right) return ST[node];
		int mid = (nodeLeft + nodeRight) / 2;
		ll lv = _query(left, right, node * 2, nodeLeft, mid), rv = _query(left, right, node * 2 + 1, mid + 1, nodeRight);
		return min(lv, rv);
	}

	ll _update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
		if (index<nodeLeft || nodeRight<index) return ST[node];
		if (nodeLeft == nodeRight) return ST[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		ll lv = _update(index, newValue, node * 2, nodeLeft, mid), rv = _update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
		return ST[node] = min(lv, rv);
	}

public:
	id6(int n) {
		N = n;
		ST = vector<ll>(n * 4 + 4);
		A = vector<int>(n + 4);
	}

	void setA(int x, int y) {
		A[x] = y;
	}

	void init() {
		_init(A, 1, N, 1);
	}

	ll query(int left, int right) {
		return _query(left, right, 1, 1, N);
	}

	ll update(int index, int newValue) {
		return _update(index, newValue, 1, 1, N);
	}
};
class id0 {
	vector<ll> ST; vector<int> A; int N;

	ll _init(vector<int>&a, int left, int right, int node) {
		if (left == right) return ST[node] = a[left];
		int mid = (left + right) / 2;
		ll lv = _init(a, left, mid, node * 2), rv = _init(a, mid + 1, right, node * 2 + 1);
		return ST[node] = max(lv, rv);
	}

	ll _query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right<nodeLeft || nodeRight<left) return 0;
		if (left <= nodeLeft && nodeRight <= right) return ST[node];
		int mid = (nodeLeft + nodeRight) / 2;
		ll lv = _query(left, right, node * 2, nodeLeft, mid), rv = _query(left, right, node * 2 + 1, mid + 1, nodeRight);
		return max(lv, rv);
	}

	ll _update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
		if (index<nodeLeft || nodeRight<index) return ST[node];
		if (nodeLeft == nodeRight) return ST[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		ll lv = _update(index, newValue, node * 2, nodeLeft, mid), rv = _update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
		return ST[node] = max(lv, rv);
	}

public:
	id0(int n) {
		N = n;
		ST = vector<ll>(n * 4 + 4);
		A = vector<int>(n + 4);
	}

	void setA(int x, int y) {
		A[x] = y;
	}

	void init() {
		_init(A, 1, N, 1);
	}

	ll query(int left, int right) {
		return _query(left, right, 1, 1, N);
	}

	ll update(int index, int newValue) {
		return _update(index, newValue, 1, 1, N);
	}
};
struct Point {
	int x, y, mx;
	Point() {}
	Point(int x, int y, int mx) : x(x), y(y), mx(mx) {}
	bool operator < (const Point& other) const {
		return mx < other.mx;
	}
};
class id8 { 

	vector<vector<int> > P; 

	int N, M;
	vector<Point> T;

public:
	id8(int n, int m) {
		N = n; M = m;
		P = vector<vector<int> >(n + 1, vector<int>(m + 1));
		T = vector<Point>(n * m * 2);
		init();
		build(1, 1, 1, n, m);
	}
	void init() {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				scanf("%d", &P[i][j]);
	}
	

	Point build(int node, int a1, int b1, int a2, int b2) {
		if (a1 > a2 || b1 > b2) 

			return def();

		

		if (a1 == a2 && b1 == b2)
			return T[node] = Point(a1, b1, P[a1][b1]);

		

		T[node] = def();
		T[node] = maxNode(T[node], build(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2));
		T[node] = maxNode(T[node], build(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2));
		T[node] = maxNode(T[node], build(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2));
		T[node] = maxNode(T[node], build(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2));
		return T[node];
	}
	

	Point query(int x1, int y1, int x2, int y2) {
		return _query(1, 1, 1, N, M, x1, y1, x2, y2);
	}
	

	Point _query(int node, int a1, int b1, int a2, int b2, int x1, int y1, int x2, int y2) {
		

		if (x1 > a2 || y1 > b2 || x2 < a1 || y2 < b1 || a1 > a2 || b1 > b2)
			return def();

		

		if (x1 <= a1 && y1 <= b1 && a2 <= x2 && b2 <= y2)
			return T[node];

		

		Point mx = def();
		mx = maxNode(mx, _query(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x1, y1, x2, y2));
		mx = maxNode(mx, _query(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x1, y1, x2, y2));
		mx = maxNode(mx, _query(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x1, y1, x2, y2));
		mx = maxNode(mx, _query(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x1, y1, x2, y2));

		

		return mx;
	}
	

	Point _update(int node, int a1, int b1, int a2, int b2, int x, int y, int value) {
		if (a1 > a2 || b1 > b2)
			return def();

		if (x > a2 || y > b2 || x < a1 || y < b1)
			return T[node];

		if (x == a1 && y == b1 && x == a2 && y == b2)
			return T[node] = Point(x, y, value);

		Point mx = def();
		mx = maxNode(mx, _update(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x, y, value));
		mx = maxNode(mx, _update(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x, y, value));
		mx = maxNode(mx, _update(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x, y, value));
		mx = maxNode(mx, _update(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x, y, value));
		return T[node] = mx;
	}

	

	Point update(int x, int y, int value) {
		return _update(1, 1, 1, N, M, x, y, value);
	}

	

	virtual Point maxNode(Point a, Point b) {
		return max(a, b);
	}

	

	virtual Point def() {
		return Point(0, 0, -INF);
	}

	void g() {
		int n, m;
		scanf("%d %d", &n, &m);

		id8 Tmax(n, m);

		

		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("(%d,%d,%d,%d)=%d\n", x1, y1, x2, y2, Tmax.query(x1, y1, x2, y2).mx);

		

		int x, y, v;
		scanf("%d %d %d", &x, &y, &v);
		Tmax.update(x, y, v);

		

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("(%d,%d,%d,%d)=%d\n", x1, y1, x2, y2, Tmax.query(x1, y1, x2, y2).mx);
	}
};
class id2 {
public:
	id2() {

	}
	

	

	vector<pair<int, int> > make(char *str, int &root) {
		int i, cur = 1;
		vector<pair<int, int> > E(10000);
		stack<int> S;
		for (i = 0; str[i]; i++) {
			char cc = str[i];
			if (cc >= '1' && cc <= '9') {
				E[cur].first = cc - '0';
				E[cur].second = 0;
				S.push(cur);
				cur++;
			}
			else if (cc == ')') {
				int a, b;
				a = S.top(); S.pop();
				b = S.top(); S.pop();
				E[cur].first = a; E[cur].second = b;
				S.push(cur);
				cur++;
			}
		}
		root = cur - 1;
		return E;
	}
};


int main() {
	int i, j, k, r, c;
	

	map <int,int> A; int n;
	scanf("%d",&n); int a, b, ans=0;
	for (int i=0; i<2*n; i++) {
		scanf("%d",&a);
		b=A.count(a);
		if (b==0) {
			A[a]++;
			if (A.size()>ans) ans=A.size();
		} else {
			A.erase(a);
		}
	}
	printf("%d",ans);
}