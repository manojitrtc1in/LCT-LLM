




















using namespace std;
typedef long long ll;

template<typename T>
inline bool chmin(T& x, T& a) {
	if (x >= a) { x = a; return true; }
	return false;
}

template<typename T>
inline bool chmax(T& x, T& a) {
	if (x <= a) { x = a; return true; }
	return false;
}








class id3 {
public:
	id3() {
		N = 0;
		parent = NULL;
		size = NULL;
	}
	~id3() {
		if (parent != NULL) {
			delete[] parent;
		}
		if (size != NULL) {
			delete[] size;
		}
	}

	void activate(int n) {

		N = n;
		parent = new int[N];
		size = new int[N];
		for (int i = 0; i < N; i++) {
			parent[i] = -1;
			size[i] = 1;
		}
	}

	int getParent(int x) {

		if (parent[x] == -1) {
			return x;
		}
		else {
			int y = getParent(parent[x]);
			parent[x] = y;
			return y;
		}
	}
	int getSize(int x) {

		x = getParent(x);
		return size[x];
	}
	bool connect(int x, int y) {

		x = getParent(x);
		y = getParent(y);
		if (x == y) { return false; }
		int xsize = getSize(x), ysize = getSize(y);
		if (xsize < ysize) {
			parent[x] = y;
			size[y] += size[x];
			size[x] = 0;
		}
		else {
			parent[y] = x;
			size[x] += size[y];
			size[y] = 0;
		}
		return true;
	}

	

	int N;

	int* parent;

	int* size;

};








class GraphClass {

public:
	GraphClass() {
		N = 0;
		M = 0;
		next = NULL;
		weight = NULL;
		id1 = false;
	}

	inline void activate(int n, bool directed = false) {

		id1 = directed;
		N = n;
		M = 0;
		edge.clear();
		edgeActiveFlag.clear();
		edgeIndexTable.clear();

		if (next != NULL) { delete[] next; }
		if (weight != NULL) { delete[] weight; }
		next = new map<int, ll>[N];
		weight = new ll[N];
		for (int i = 0; i < N; i++) { weight[i] = 1; }
	}
	inline void setNodeWeight(int n, ll weight) {

		this->weight[n] = weight;
	}

	inline ll hashForEdgeIndex(int x, int y) {
		return (((ll)x) << 32) + ((ll)y);
	}
	inline int getEdgeIndex(int x, int y) {
		if (edgeIndexTable.find(hashForEdgeIndex(x, y)) != edgeIndexTable.end()) {
			return edgeIndexTable.find(hashForEdgeIndex(x, y))->second;
		}
		return -1;
	}
	inline void addEdge(int x, int y, ll weight = 1) {

		int n = (int)edge.size();
		edge.push_back({ {x,y}, weight });
		edgeActiveFlag.push_back(true);

		next[x].insert({ y, weight });
		edgeIndexTable.insert({ hashForEdgeIndex(x,y), n });

		if (id1 == false) {
			next[y].insert({ x, weight });
			edgeIndexTable.insert({ hashForEdgeIndex(y,x), n });
		}

		M++;
	}
	inline void removeEdge(int x, int y) {

		int k = getEdgeIndex(x, y);
		if (k == -1) { return; }

		x = edge[k].first.first;
		y = edge[k].first.second;

		M--;
		edgeActiveFlag[k] = false;

		next[x].erase(next[x].find(y));
		edgeIndexTable[hashForEdgeIndex(x, y)] = -1;

		if (id1 == false) {
			next[y].erase(next[y].find(x));
			edgeIndexTable[hashForEdgeIndex(y, x)] = -1;
		}
	}

	bool isTree() {

		if (N <= 0 || M != N - 1) { return false; }

		bool* visited = new bool[N];
		for (int i = 0; i < N; i++) {
			visited[i] = (i == 0);
		}

		queue<int> q; q.push(0);

		while (q.size() > 0) {
			int n = q.front(); q.pop();
			visited[n] = true;

			for (auto itr = next[n].begin(); itr != next[n].end(); itr++) {
				if (visited[itr->first] == false) {
					q.push(itr->first);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			if (visited[i] == false) { delete[] visited; return false; }
		}

		delete[] visited;
		return true;
	}

	GraphClass* kruskal() {

		GraphClass* G = new GraphClass(); G->activate(N, id1);
		id3 uf; uf.activate(N);

		vector<pair<ll, pair<int, int>>> E;
		{
			int i = 0;
			for (auto itr = edge.begin(); itr != edge.end(); itr++, i++) {
				if (edgeActiveFlag[i] == false) { continue; }
				E.push_back({ itr->second, {itr->first.first, itr->first.second} });
			}
		}

		sort(E.begin(), E.end());

		for (auto itr = E.begin(); itr != E.end(); itr++) {
			int x = itr->second.first, y = itr->second.second;
			ll w = itr->first;

			if (uf.getParent(x) != uf.getParent(y)) {
				G->addEdge(x, y, w);
				uf.connect(x, y);
			}
		}

		return G;
	}

	ll* dijkstra(int n) {

		if (n < 0 || n >= N) { return NULL; }

		ll* buf = new ll[N];
		for (int i = 0; i < N; i++) {
			buf[i] = 1LL << 60;
		}

		

		set<pair<ll, int>> st;

		buf[n] = 0;
		st.insert({ 0, n });

		while (st.empty() == false) {
			pair<ll, int> p = *st.begin(); st.erase(st.begin());
			int k = p.second;

			if (p.first <= buf[k]) {
				for (auto itr = next[k].begin(); itr != next[k].end(); itr++) {
					if (buf[itr->first] > buf[k] + itr->second) {
						buf[itr->first] = buf[k] + itr->second;
						st.insert({ buf[itr->first], itr->first });
					}
				}
			}
		}

		return buf;
	}

	ll* bellmanFord(int n) {

		if (n < 0 || n >= N) { return NULL; }

		ll* buf = new ll[N];
		for (int i = 0; i < N; i++) {
			buf[i] = 1LL << 60;
		}
		buf[n] = 0;
		for (int i = 0; i < N; i++) {
			int j = 0;
			for (auto itr = edge.begin(); itr != edge.end(); itr++, j++) {
				if (edgeActiveFlag[j] == false) { continue; }
				int x = itr->first.first, y = itr->first.second;
				ll w = itr->second;

				if (buf[y] > buf[x] + w) {
					buf[y] = buf[x] + w;
					if (i == N - 1) {
						return NULL;
					}
				}
			}
		}
		return buf;
	}

	ll* getDistanceFrom(int n) {

		if (n < 0 || n >= N) { return NULL; }

		bool negativeFlag = false;
		{
			int i = 0;
			for (auto itr = edge.begin(); itr != edge.end(); itr++, i++) {
				if (edgeActiveFlag[i] == false) { continue; }
				if (itr->second < 0) {
					negativeFlag = true;
					break;
				}
			}
		}

		if (negativeFlag) {

			return bellmanFord(n);
		}
		else {

			return dijkstra(n);
		}
	}

	ll** getDistanceTable() {


		ll** buf = new ll * [N];
		for (int i = 0; i < N; i++) {
			buf[i] = new ll[N];
			for (int j = 0; j < N; j++) {
				buf[i][j] = 1LL << 60;
			}
			buf[i][i] = 0;
		}

		bool flag = true;
		{
			int i = 0;
			for (auto itr = edge.begin(); itr != edge.end(); itr++, i++) {
				if (itr->second < 0) { flag = false; break; }
			}
		}

		if (flag) {

			for (int i = 0; i < N; i++) {
				ll* d = getDistanceFrom(i);
				for (int j = 0; j < N; j++) {
					buf[i][j] = d[j];
				}
				delete[] d;
			}

		}
		else {

			for (int i = 0; i < N; i++) {
				for (auto itr = next[i].begin(); itr != next[i].end(); itr++) {
					buf[i][itr->first] = itr->second;
				}
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < N; k++) {
						buf[j][k] = min(buf[j][k], buf[j][i] + buf[i][k]);
					}
				}
			}
		}
		return buf;
	}

	void debugCout() {

		cout << endl;
		cout << "�m�[�h�̌� = " << N << "��" << endl;
		cout << "�G�b�W�̖{�� = " << M << "�{" << endl;
		cout << endl;

		for (int i = 0; i < N; i++) {
			cout << "i = " << i << " (weight = " << weight[i] << "), �ڑ��� = ";
			if (next[i].size() == 0) { cout << "�Ȃ�" << endl; continue; }
			auto itr = next[i].begin();
			cout << itr->first << "(weight = " << itr->second << ")";
			itr++;

			for (; itr != next[i].end(); itr++) {
				cout << ", " << itr->first << "(weight = " << itr->second << ")";
			}
			cout << endl;
		}
		cout << endl;
	}

	bool id1;

	int N, M;
	ll* weight;

	map<int, ll>* next;

	vector<pair<pair<int, int>, ll>> edge;

	vector<bool> edgeActiveFlag;

	unordered_map<ll, int> edgeIndexTable;

};

void bfs(GraphClass& G, int root) {

	int N = G.N;
	bool* visited = new bool[N];
	for (int i = 0; i < N; i++) {
		visited[i] = (i == root);
	}

	queue<int> q; q.push(root);

	while (q.size() > 0) {
		int n = q.front(); q.pop();
		visited[n] = true;

		


		for (auto itr = G.next[n].begin(); itr != G.next[n].end(); itr++) {

			


			if (visited[itr->first] == false) {

				q.push(itr->first);
			}
		}
	}

	delete[] visited;
}

int db[5001][15];
int depth[5001];

bool* id2 = NULL;
void id0(GraphClass& G, int n, int _depth) {
	depth[n] = _depth;

	for (auto itr = G.next[n].begin(); itr != G.next[n].end(); itr++) {
		if (id2[itr->first] == false) {
			id2[itr->first] = true;

			db[itr->first][0] = n;

			id0(G, itr->first, _depth + 1);
			id2[itr->first] = false;
		}
	}
}
void dfs(GraphClass& G, int root) {
	int N = G.N;
	id2 = new bool[N];
	for (int i = 0; i < N; i++) { id2[i] = false; }

	id2[root] = true;
	id0(G, root, 0);

	delete[] id2;
	id2 = NULL;
}

int main() {
	int n; cin >> n;
	GraphClass G;
	G.activate(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y;
		G.addEdge(x - 1, y - 1, 1);
	}

	for (int j = 0; j < 15; j++) {
		for (int i = 0; i < n; i++) {
			db[i][j] = -1;
			depth[i] = 0;
		}
	}

	dfs(G, 0);
	for (int j = 0; j < 13; j++) {
		for (int i = 0; i < n; i++) {
			if (db[i][j] == -1) {
				db[i][j + 1] = -1;
			}
			else {
				db[i][j + 1] = db[db[i][j]][j];
			}
		}
	}


	vector <pair<pair<int, int>, ll>> v;
	int M; cin >> M;
	for (int q = 0; q < M; q++) {
		int a, b; ll g; cin >> a >> b >> g;
		a--; b--;
		v.push_back({ {a,b},g });
		int a0 = a, b0 = b;

		int k = min(depth[a], depth[b]);
		int x = depth[a] - k;
		for (int i = 0; i < 13; i++) {
			if (x & (1 << i)) {
				a = db[a][i];
			}
		}
		x = depth[b] - k;
		for (int i = 0; i < 13; i++) {
			if (x & (1 << i)) {
				b = db[b][i];
			}
		}
		for (int i = 12; i >= 0; i--) {
			if (db[a][i] == -1) { continue; }
			if (db[a][i] != db[b][i]) {
				a = db[a][i];
				b = db[b][i];
			}
		}
		ll c;
		if (a == b) {
			c = a;
		}
		else {
			c = db[a][0];
		}

		while (a0 != c) {
			int k = G.getEdgeIndex(a0, db[a0][0]);
			G.edge[k].second = max(g, G.edge[k].second);
			a0 = db[a0][0];
		}
		while (b0 != c) {
			int k = G.getEdgeIndex(b0, db[b0][0]);
			G.edge[k].second = max(g, G.edge[k].second);
			b0 = db[b0][0];
		}
	}

	for (auto itr = v.begin(); itr != v.end(); itr++) {
		int a, b; ll g;
		a = itr->first.first;
		b = itr->first.second;
		g = itr->second;

		int a0 = a, b0 = b;

		int k = min(depth[a], depth[b]);
		int x = depth[a] - k;
		for (int i = 0; i < 13; i++) {
			if (x & (1 << i)) {
				a = db[a][i];
			}
		}
		x = depth[b] - k;
		for (int i = 0; i < 13; i++) {
			if (x & (1 << i)) {
				b = db[b][i];
			}
		}
		for (int i = 12; i >= 0; i--) {
			if (db[a][i] == -1) { continue; }
			if (db[a][i] != db[b][i]) {
				a = db[a][i];
				b = db[b][i];
			}
		}
		int c;
		if (a == b) {
			c = a;
		}
		else {
			c = db[a][0];
		}

		ll m = 100000000;

		while (a0 != c) {
			int k = G.getEdgeIndex(a0, db[a0][0]);
			m = min(m, G.edge[k].second);
			a0 = db[a0][0];
		}
		while (b0 != c) {
			int k = G.getEdgeIndex(b0, db[b0][0]);
			m = min(m, G.edge[k].second);
			b0 = db[b0][0];
		}
		if (m != g) {
			cout << -1 << endl;
			return 0;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		cout << G.edge[i].second << " ";
	}

	return 0;
}