#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<set>
#include<utility>
using namespace std;
typedef long long ll;
#define INF 1000000007
#define MOD 1000000007
#define INF_LONG 1000000000000007
#define MOD_LONG 1000000000000007
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

class DFS_Graph {
	vector<vector<pair<int, int> > > E;
	int N;
public:
	DFS_Graph(int n) {
		N = n;
		E = vector<vector<pair<int, int> > >(N + 1);
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

class BFS_Graph {
	vector<vector<pair<int, int> > > E; vector<int> IN;
	int N;
public:
	BFS_Graph(int n) {
		N = n;
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
		vector<int> order(N + 1);
		queue<int> Q;
		for (int i = 1; i <= N; i++) if (!IN[i]) Q.push(i);
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop(); order.push_back(u);
			for (int i = 0; i < E[u].size(); i++) {
				int v = E[u][i].first;
				IN[v]--;
				if (!IN[v]) Q.push(v);
			}
		}
		return order;
	}
	void g() {
		int i, j, N, m, a, b, c, a2, b2, c2, lo, hi, mid, tmp, start, end;
		vector <tuple<int, int, int> > X; vector<ll> y;
		scanf("%d%d", &N, &m);
		BFS_Graph bg(N); X.reserve(m);
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

class BFSMap {
	vector<vector<int> > E;
	int R, C;
public:
	BFSMap(int r, int c) {
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
	int bfsAll(vector<pair<int,int> > &Q) {
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
		BFSMap bm(R, C);
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

class PrimeNumber {
	int N; vector<int> NP, P;
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

	int gcd(int x, int y) {
		int z;
		while (x) {
			z = y%x;
			y = x;
			x = z;
		}
		return y;
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
	vector<vector<ll> > C; int N;
public:
	Comb(int n) {
		N = n;
		C.resize(N + 4);
		for (int i = 0; i <= N; i++) C[i].resize(N + 4);
		for (int i = 0; i <= N; i++) C[i][i] = C[i][0] = 1;
		for (int i = 1; i <= N; i++) for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD_LONG;
	}
	ll get(int n, int r) {
		return C[n][r];
	}
	ll get_comb(int n, int r) {
		if (n == r || r == 0) return 1;
		if (n <= 1000) return get(n, r);
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

int main() {
	int i, j, k, a, b, c, d, e, f, x, n, m, ans=0; string X; vector<vector<char> > A;
	string name, ip;


	cin >> X; n=X.size();
	A=vector<vector<char> > (n, vector<char> (n));
	for (i=0; i<n; i++) {
		a=b=c=0;
		for (j=i+1; j<n; j+=2) {
			if (X[j-1]=='(') a++;
			else if (X[j-1]==')') b++;
			else c++;
			if (b>a+c) break;

			if (X[j]=='(') a++;
			else if (X[j]==')') b++;
			else c++;
			if (b>a+c) break;
			d=a-b; if (d<0) d=-d;

			if (c>=d) A[i][j]++;
		}
	}
	for (i=n-1; i>=0; i--) {
		a=b=c=0;
		for (j=i-1; j>=0; j-=2) {
			if (X[j+1]=='(') a++;
			else if (X[j+1]==')') b++;
			else c++;
			if (a>b+c) break;

			if (X[j]=='(') a++;
			else if (X[j]==')') b++;
			else c++;
			if (a>b+c) break;

			A[j][i]++;
		}
	}
	for (i=0; i<n; i++) for (j=i+1; j<n; j+=2) if (A[i][j]==2) ans++;
	printf("%d",ans);
}