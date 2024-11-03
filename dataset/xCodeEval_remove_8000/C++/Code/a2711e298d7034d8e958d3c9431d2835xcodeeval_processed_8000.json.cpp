
using namespace std;
void fast() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}
void ran() {
	srand(chrono::steady_clock::now().time_since_epoch().count());
}
long long get_rand() {
	long long a = rand();
	long long b = rand();
	return a * (RAND_MAX + 1ll) + b;
}
void usaco() {
	freopen("problem.in", "r", stdin); 
	freopen("problem.out", "w", stdout);
}
template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;



const int MOD = 1000 * 1000 * 1000 + 7;






namespace socho_math {
	
	const long long id8 = 1000000000ll * 1000000000ll * 4ll + 1;
	const long long FIT_INT = 1000000000ll;
	
	vector<int> id5(int base, int upto) {
		upto = min(upto, id8);
		vector<int> result;
		if (base == 1) {
			if (1 <= upto) result.push_back(1);
		}
		else {
			for (int i=1; i<=upto; i*=base) {
				result.push_back(i);
			}
		}
		return result;
	}
	
	int gcd(int a, int b) {
		while (b > 0) {
			a %= b;
			swap(a, b);
		}
		return a;
	}
	
	int lcm(int a, int b) {
		if (a == id8 || b == id8) return id8;
		int g = gcd(a, b);
		return min(a / g * b, id8);
	}
	
	bool prime(int n) {
		if (n == 1) return false;
		if (n == 2 || n == 3) return true;
		for (int i=2; i*i<=n; i++) {
			if (n % i == 0) return false;
		}
		return true;
	}
	
	vector<bool> id12(int n) {
		vector<bool> result(n+1, true);
		result[0] = result[1] = false;
		for (int p=2; p<=n; p++) {
			if (result[p]) {
				for (int i=p*2; i<=n; i+=p) {
					result[i] = false;
				}
			}
		}
		return result;
	}
	
	vector<int> id2(int n) {
		vector<int> result(n+1, -1);
		vector<bool> x = id12(n);
		result[0] = result[1] = 1;
		for (int p=2; p<=n; p++) {
			if (x[p]) {
				for (int i=p*2; i<=n; i+=p) {
					result[i] = p;
				}
			}
		}
		return result;
	}
	
	vector<int> factors(int n) {
		vector<int> result;
		for (int i=1; i*i<=n; i++) {
			if (n % i == 0) {
				result.push_back(i);
				if (i * i != n) result.push_back(n/i);
			}
		}
		sort(result.begin(), result.end());
		return result;
	}
	
	vector<int> id20(int n, bool distinct=false) {
		vector<int> result;
		for (int i=2; i*i<=n; i++) {
			if (distinct) {
				result.push_back(i);
				while (n % i == 0) {
					n /= i;
				}
			}
			else {
				while (n % i == 0) {
					n /= i;
					result.push_back(i);
				}
			}
		}
		if (n > 1) {
			result.push_back(n);
		}
		return result;
	}
	
	int factorial(int x, int mod=MOD) {
		if (x == 0) return 1;
		return (x * factorial(x - 1)) % mod;
	}
	
	vector<int> id1(int n, int mod=MOD) {
		vector<int> result(n+1);
		result[0] = 1;
		for (int i=1; i<=n; i++) {
			result[i] = result[i-1] * i;
			result[i] %= mod;
		}
		return result;
	}
	
	int power(int b, int e, int mod=MOD) {
		if (e == 0) return 1;
		if (e == 1) return b;
		int h = power(b, e/2, mod);
		h *= h;
		h %= mod;
		if (e % 2 == 1) h *= b;
		h %= mod;
		return h;
	}
	
	int mod_inverse(int x, int mod=MOD) {
		return power(x, mod-2, mod);
	}
	
	vector<int> id14(vector<int> source, int mod=MOD) {
		vector<int> result(source.size());
		for (int i=0; i<source.size(); i++) {
			result[i] = power(source[i], mod-2, mod);
		}
		return result;
	}
	
	int ncr(int n, int r, vector<int> &factorials, vector<int> &id13, int mod=MOD) {
		if (r < 0 || r > n) return 0;
		int ans = (factorials[n] * id13[r]) % mod;
		return (ans * id13[n-r]) % mod;
	}
	
	int ways(int a, int b, vector<int> &factorials, vector<int> &id13, int mod=MOD) {
		return ncr(a - 1 + b - 1, a - 1, factorials, id13, mod);
	}
	
	vector<vector<int>> id19(int n, int r, int mod=MOD) {
		vector<vector<int>> result(n+1, vector<int>(r+1));
		for (int i=0; i<=n; i++) {
			result[i][0] = 1;
		}
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=r; j++) {
				result[i][j] = (result[i-1][j-1] + result[i-1][j]) % mod;
			}
		}
		return result;
	} 
	
	int sum(vector<int> input, int mod=id8) {
		int result = 0;
		for (auto x: input) {
			result = (result + x) % MOD;
		}
		return result;
	}
	
	int id11(vector<int> input) {
		int result = 0;
		for (auto x: input) {
			result += x;
		}
		return result;
	}
	
	int product(vector<int> input, int mod=FIT_INT) {
		int result = 1;
		for (auto x: input) {
			result = (result * x) % MOD;
		}
		return result;
	}
	
	int id9(vector<int> input) {
		int result = 1;
		for (auto x: input) {
			result *= x;
		}
		return result;
	}
	
	int id17(int n) {
		return n * (n - 1) / 2;
	}
	
	int divup(int a, int b) {
		return (a + b - 1) / b;
	}
	
	int ceildiv(int a, int b) {
		return divup(a, b);
	}
	
	int divceil(int a, int b) {
		return divup(a, b);
	}
	
	double distance(pair<double, double> a, pair<double, double> b) {
		return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
	}
	
	int square(int x) {
		return x * x;
	}
	
	double calculate_ratio(int a, int b) {
		return ((double) a) / ((double) b);
	}
	
}
namespace socho_graph {
	
	const int id16 = 1000000000ll * 1000000000ll;
	const int MXK = 20;
	
	struct graph {
		
		bool dir=false;
		int index=1;
		int n=0, m=0;
		bool wgt=false;
		vector<vector<pair<int, pair<int, int>>>> adj; 

		vector<pair<pair<int, int>, pair<int, int>>> edges; 

		
		void set_n(int newn) {
			n = newn;
			adj.resize(n + index);
		}
		
		void read_n() {
			cin >> n;
			set_n(n);
		}
		
		void set_index(int i) {
			index = i;
			adj.resize(n + index);
		}
		
		void set_weighted(bool x) {
			wgt = x;
		}
		
		void read_m() {
			cin >> m;
		}
		
		void read_edge() {
			int i = edges.size();
			int a, b, w=1;
			if (wgt) cin >> a >> b >> w;
			else cin >> a >> b;
			edges.push_back({{w, i}, {a, b}});
			adj[a].push_back({b, {w, i}});
			if (!dir) adj[b].push_back({a, {w, i}});
		}
		
		void read_edges() {
			for (int i=0; i<m; i++) {
				read_edge();
			}
		}
		
		graph() {
			

			dir = index = n = m = 0;
			wgt = false;
		}
		
		graph(int indexing, bool weighted=false, bool directed=false) {
			

			read_n();
			read_m();
			index = indexing;
			dir = directed;
			wgt = weighted;
			adj.resize(n + indexing);
			for (int i=0; i<m; i++) {
				read_edge();
			}
		}
		
		graph(graph &copyfrom) {
			dir = copyfrom.dir;
			index = copyfrom.index;
			n = copyfrom.n;
			m = copyfrom.m;
			adj = copyfrom.adj;
			edges = copyfrom.edges;
			wgt = copyfrom.wgt;
		}
		
		graph inverse() {
			assert(dir == true); 

			graph other;
			other.dir = dir;
			other.index = index;
			other.n = n;
			other.m = m;
			other.adj.resize(n + index);
			for (int i=index; i<index+n; i++) {
				for (auto x: adj[i]) {
					int ot = x.first;
					int ow = x.second.first;
					int oi = x.second.second;
					other.adj[ot].push_back({i, {ow, oi}});
					other.edges.push_back({{ow, oi}, {ot, i}});
				}
			}
			return other;
		}
		
		void set_n(int ne, int indexing) {
			index = indexing;
			n = ne;
			adj.resize(n + index);
		}
		
		void add_edge(int a, int b, int w=1) {
			int e = edges.size();
			edges.push_back({{w, e}, {a, b}});
			m++;
			adj[a].push_back({b, {w, e}});
			if (!dir) {
				adj[b].push_back({a, {w, e}});
			}
		}
		
		vector<int> distances(int from) {
			vector<int> dist(n+index, id16);
			min_pq<pair<int, int>> proc;
			proc.push({0, from});
			while (!proc.empty()) {
				auto x = proc.top(); proc.pop();
				int di = x.first, no = x.second;
				if (dist[no] < di) continue;
				dist[no] = di;
				for (auto x: adj[no]) {
					int ot = x.first;
					int od = x.second.first + di;
					if (dist[ot] > od) {
						dist[ot] = od;
						proc.push({od, ot});
					}
				}
			}
			return dist;
		}
		
		int distance(int x, int y) {
			return distances(x)[y];
		}
		
		vector<int> get_path(int from, int to) {
			vector<int> d1 = distances(from);
			vector<int> d2 = distances(to);
			if (d1[to] == id16) {
				return vector<int>();
			}
			vector<pair<int, int>> nodes;
			vector<int> result;
			for (int i=index; i<index+n; i++) {
				if (d1[i] + d2[i] == d1[to]) {
					nodes.push_back({d1[i], i});
				}
			}
			sort(nodes.begin(), nodes.end());
			for (auto x: nodes) {
				result.push_back(x.second);
			}
			return result;
		}
		
		vector<vector<int>> distances_all() {
			vector<vector<int>> dist(n+index);
			for (int k=index; k<index+n; k++) {
				dist[k] = distances(k);
			}
			return dist;
		}
		
	};
	
	struct tree: graph {
		
		int tree_root=0;
		
		tree() {
			

			dir = index = n = m = tree_root = 0;
		}
		
		void read_n() {
			cin >> n;
			m = n - 1;
			set_n(n);
		}
		
		void set_index(int i) {
			index = i;
			tree_root = index;
			adj.resize(n + index);
		}
		
		tree(int indexing, bool weighted=false, bool directed=false) {
			

			index = indexing;
			read_n();
			m = n-1;
			dir = directed;
			tree_root = indexing;
			adj.resize(n + indexing);
			for (int i=0; i<m; i++) {
				read_edge();
			}
		}
		
		void set_root(int newroot) {
			tree_root = newroot;
		}
		
		vector<int> parents;
		vector<vector<int>> distance_util;
		vector<int> depths;
		
		void dfs_distance_setup(int node, int par, int depth) {
			depths[node] = depth;
			distance_util[node][0] = par;
			for (int i=1; i<MXK; i++) {
				distance_util[node][i] = distance_util[distance_util[node][i-1]][i-1];
			}
			for (auto x: adj[node]) {
				if (x.first == par) continue;
				dfs_distance_setup(x.first, node, depth+x.second.first);
			}
		}
		
		void setup_distances(int root) {
			tree_root = root;
			distance_util.resize(n+index, vector<int>(MXK, root));
			parents.resize(n+index, index);
			depths.resize(n+index, 0);
			dfs_distance_setup(root, root, 0);
		}
		
		int kth(int n, int k) {
			if (distance_util.empty()) setup_distances(tree_root);
			for (int i=0; i<MXK; i++) {
				if (k & (1 << i)) {
					n = distance_util[n][i];
				}
			}
			return n;
		}
		
		int lca(int a, int b) {
			if (distance_util.empty()) setup_distances(tree_root);
			if (depths[a] > depths[b]) swap(a, b);
			b = kth(b, depths[b] - depths[a]);
			for (int i=MXK-1; i>=0; i--) {
				if (distance_util[a][i] != distance_util[b][i]) {
					a = distance_util[a][i];
					b = distance_util[b][i];
				}
			}
			return distance_util[a][0];
		}
		
		int distance(int a, int b) {
			if (distance_util.empty()) setup_distances(tree_root);
			int l = lca(a, b);
			int m = 0;
			if (l != tree_root) m = depths[parents[l]];
			return depths[a] + depths[b] - depths[l] - m;
		}
		
		pair<int, pair<int, int>> find_diameter() {
			vector<int> dists = distances(tree_root);
			int far = tree_root;
			for (int i=index; i<index+n; i++) {
				if (dists[i] > dists[far]) {
					far = i;
				}
			}
			dists = distances(far);
			int sec = far;
			for (int i=index; i<index+n; i++) {
				if (dists[i] > dists[sec]) {
					sec = i;
				}
			}
			return {dists[sec], {far, sec}};
		}
		
		int diameter() {
			return find_diameter().first;
		}
		
		vector<int> markings;
		
		void mark(int node, int parent=-1, int with=0) {
			if (markings.empty()) markings = vector<int>(n+index, -1);
			markings[node] = with;
			for (auto x: adj[node]) {
				if (x.first == parent) continue;
				mark(x.first, node, with);
			}
		}
		
	};
	
	struct ufds {
		
		int n=0, index=0;
		int components=0;
		vector<int> parents;
		
		ufds() {
			index = 0;
			n = 0;
			components = 0;
		}
		
		ufds(graph a) {
			index = a.index;
			set_n(a.n);
			for (auto edge: a.edges) {
				int a = edge.second.first;
				int b = edge.second.second;
				connect(a, b);
			}
		}
		
		void set_n(int newn) {
			n = newn;
			parents.resize(n+index);
			components = n;
			for (int i=0; i<n+index; i++) parents[i] = i;
		}
		
		int parent(int n) {
			if (parents[n] == n) return n;
			return parents[n] = parent(parents[n]);
		}
		
		bool connect(int a, int b) {
			a = parent(a);
			b = parent(b);
			if (a == b) return false;
			parents[a] = b;
			components--;
			return true;
		}
		
		bool are_connected(int a, int b) {
			return parent(a) == parent(b);
		}
		
		vector<vector<int>> get_components() {
			vector<vector<int>> v(n+index);
			vector<vector<int>> results;
			for (int i=index; i<n+index; i++) {
				v[parent(i)].push_back(i);
			}
			for (auto x: v) {
				if (!x.empty()) results.push_back(x);
			}
			return results;
		}
		
		vector<int> get_fingerprints() {
			vector<int> result(n+index);
			for (int i=index; i<n+index; i++) {
				result[i] = parent(i);
			}
			return result;
		}
		
	};
	
	graph mst(graph a) {
		graph e;
		e.set_n(a.n);
		e.set_index(a.index);
		vector<pair<pair<int, int>, pair<int, int>>> ed;
		for (auto x: a.edges) {
			ed.push_back(x);
		}
		sort(ed.begin(), ed.end());
		ufds t;
		t.index = a.index;
		t.set_n(a.n);
		for (auto x: ed) {
			int w = x.first.first;
			int a = x.second.first;
			int b = x.second.second;
			if (t.connect(a, b)) {
				e.add_edge(a, b, w);
			}
		}
		return e;
	}
	
}
namespace socho_utils {
	
	template<typename T>
	int count(vector<T> items, T item) {
		int a = 0;
		for (auto x: items) {
			if (x == item) a++;
		}
		return a;
	}
	
	int count(vector<int> items, signed item) {
		int a = 0;
		for (auto x: items) {
			if (x == item) a++;
		}
		return a;
	}
	
	int max(int a, signed b) {
		if (a > b) return a;
		return b;
	}
	
	int max(signed a, int b) {
		if (a > b) return a;
		return b;
	}
	
	template<typename T>
	T max(T a, T b, T c) {
		if (a > b && a > c) return a;
		if (b > c) return b;
		return c;
	}
	
	int min(int a, signed b) {
		if (a < b) return a;
		return b;
	}
	
	int min(signed a, int b) {
		if (a < b) return a;
		return b;
	}
	
	template<typename T>
	T min(T a, T b, T c) {
		if (a < b && a < c) return a;
		if (b < c) return b;
		return c;
	}
	
	template<typename T>
	int id6(vector<T> s) {
		set<T> e;
		for (auto x: s) e.insert(x);
		return e.size();
	}
	
	int id6(string s) {
		set<char> e;
		for (auto x: s) e.insert(x);
		return e.size();
	}
	
	void printif(bool e, string yes="Yes", string no="No") {
		if (e) cout << yes << endl;
		else cout << no << endl;
	}
	
	vector<int> digits(int x) {
		assert(x >= 0);
		vector<int> result;
		while (x > 0) {
			result.push_back(x % 10);
			x /= 10;
		}
		reverse(result.begin(), result.end());
		return result;
	}
	
	int in_range(int a, int b) {
		if (a > b) return 0;
		return b - a + 1;
	}
	
	bool endswith(string a, string b) {
		if (a.size() < b.size()) return false;
		int x = b.size();
		for (int i=0; i<b.size(); i++) {
			if (a[a.size()-x] != b[i]) return false;
			x--;
		}
		return true;
	}
	
	void doubleprint(int precision=10) {
		cout << fixed << setprecision(precision);
	}
	
	string pad_left(string x, int len, char c='0') {
		string s = x;
		reverse(s.begin(), s.end());
		while (s.length() < len) s += c;
		reverse(s.begin(), s.end());
		return s;
	}
	
	
	
	
	template<typename T>
	vector<T> vector_input(int n, T x) {
		vector<T> t;
		for (int i=0; i<n; i++) {
			T x;
			cin >> x;
			t.push_back(x);
		}
		return t;
	}
	
	vector<int> vector_input(int n) {
		vector<int> t;
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			t.push_back(x);
		}
		return t;
	}
	
	bool id0(char x) {
		return 'A' <= x && x <= 'Z';
	}
	
	bool id10(char x) {
		return 'a' <= x && x <= 'z';
	}
	
	template<typename T>
	map<T, int> frequency(vector<T> x) {
		map<T, int> s;
		for (auto a: x) {
			s[a]++;
		}
		return s;
	}
	
	template<typename T>
	map<T, int> inverse(vector<T> x, int indexing=0, bool first=false) {
		map<T, int> s;
		int j = indexing;
		for (auto a: x) {
			if (first) {
				if (s.find(a) != s.end()) {}
				else s[a] = j;
			}
			else {
				s[a] = j;
			}
			j++;
		}
		return s;
	}
	
	template<typename T>
	map<T, vector<int>> id13(vector<T> x, int indexing=0) {
		map<T, vector<int>> s;
		int j = indexing;
		for (auto a: x) {
			s[a].push_back(j);
			j++;
		}
		return s;
	}
	
	template<typename T>
	vector<T> in_any(vector<T> a, vector<T> b) {
		for (auto x: b) a.push_back(x);
		auto r = frequency(a);
		vector<T> res;
		for (auto x: r) {
			res.push_back(x.first);
		}
		return res;
	}
	
	template<typename T>
	vector<T> id4(vector<T> a, vector<T> b) {
		auto r = frequency(a);
		vector<T> j;
		for (auto x: b) {
			if (r[x]) j.push_back(x);
		}
		return j;
	}
	
	int xor_all(vector<int> e) {
		int a = 0;
		for (auto x: e) a ^= x;
		return a;
	}
	
	string copies(string x, int copy) {
		string r = "";
		for (int i=0; i<copy; i++) r += x;
		return r;
	}
	
	bool substring(string x, string y) {
		for (int i=0; i<x.size(); i++) {
			bool ok = true;
			for (int j=0; j<y.size(); j++) {
				if (i + j >= x.size()) ok = false;
				else if (x[i + j] != y[j]) ok = false;
			}
			if (ok) return true;
		}
		return false;
	}
	
	template<typename T>
	T min(vector<T> a) {
		if (a.empty()) return T();
		T x = a[0];
		for (auto y: a) {
			if (y < x) x = y;
		}
		return x;
	}
	
	template<typename T>
	T max(vector<T> a) {
		if (a.empty()) return T();
		T x = a[0];
		for (auto y: a) {
			if (y > x) x = y;
		}
		return x;
	}
	
	template<typename T>
	T max_key(map<T, int> a) {
		T Tx;
		int e = id18;
		for (auto x: a) {
			if (x.second > e) {
				Tx = x.first;
				e = x.second;
			}
		}
		return Tx;
	}
	
	vector<int> id7(string s) {
		vector<int> result(26, 0);
		for (auto x: s) {
			if (x >= 'a' && x <= 'z') result[x - 'a']++;
			else if (x >= 'A' && x <= 'Z') result[x - 'A']++;
		}
		return result;
	}
	
	map<char, int> frequency(string s) {
		map<char, int> r;
		for (auto x: s) r[x]++;
		return r;
	}
	
	int mex(vector<int> items, int from=0) {
		auto r = frequency(items);
		while (true) {
			if (r[from] == 0) {
				return from;
			}
			from++;
		}
	}
	
	bool id3(vector<int> a, vector<int> b) {
		auto r = frequency(a), s = frequency(b);
		for (auto x: s) {
			if (r[x.first] < x.second) return false;
		}
		return true;
	}
	
	bool is_subset(vector<int> a, vector<int> b) {
		return id3(b, a);
	}
	
	void sort(string &s) {
		sort(s.begin(), s.end());
	}
	
	template<typename T>
	void sort(vector<T> &s) {
		sort(s.begin(), s.end());
	}
	
	vector<pair<int, int>> interval_union(vector<pair<int, int>> intervals) {
		int op = 0, c = 0;
		vector<pair<int, int>> eve, res;
		for (auto x: intervals) {
			eve.push_back({x.first, -1});
			eve.push_back({x.second, 1});
		}
		sort(eve);
		for (auto x: eve) {
			x.second *= -1;
			if (c > 0 && c + x.second == 0) {
				res.push_back({op, x.first});
			}
			else if (c == 0 && c + x.second == 1) {
				op = x.first;
			}
			c += x.second;
		}
		return res;
	}
	
	char to_upper(char a) {
		if (a >= 'a' && a <= 'z') a += 'A' - 'a';
		return a;
	}
	
	string to_upper(string a) {
		string x = "";
		for (auto b: a) x += to_upper(b);
		return x;
	}
	
	char to_lower(char a) {
		if (a >= 'A' && a <= 'Z') a += 'a' - 'A';
		return a;
	}
	
	string to_lower(string a) {
		string x = "";
		for (auto b: a) x += to_lower(b);
		return x;
	}
	
}

using namespace socho_math;
using namespace socho_graph;
using namespace socho_utils;



int n, m, q;
const int MXN = 200005;
vector<pair<int, int>> adj[MXN];
int par[MXN][20];
int mxw[MXN][20];
int dis[MXN][20];
int depth[MXN];

void dfs(int node, int parent, int dep, int tre=0) {
	depth[node] = dep;
	par[node][0] = parent;
	mxw[node][0] = tre;
	for (int i=1; i<MXK; i++) {
		par[node][i] = par[par[node][i-1]][i - 1];
		mxw[node][i] = max(mxw[node][i-1], mxw[par[node][i-1]][i-1]);
	}
	for (auto x: adj[node]) {
		if (x.first == parent) continue;
		dfs(x.first, node, dep+1, x.second);
	}
}

int kth(int n, int k) {
	for (int i=0; i<MXK; i++) {
		if (k & (1 << i)) n = par[n][i];
	}
	return n;
}

int lca(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	b = kth(b, depth[b] - depth[a]);
	if (a == b) return a;
	for (int i=MXK-1; i>=0; i--) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}

int id15(int n, int k) {
	int e = 0;
	for (int i=0; i<MXK; i++) {
		if (k & (1 << i)) {
			e = max(e, mxw[n][i]);
			n = par[n][i];
		}
	}
	return e;
}

int pathq(int a, int b) {
	int l = lca(a, b);
	int e = id15(a, depth[a] - depth[l]);
	int f = id15(b, depth[b] - depth[l]);
	return max(e, f);
}

int seg[MXN * 4];

void upd(int ind, int l, int r, int p, int to) {
	if (l == r) {
		seg[ind] = to;
		return;
	}
	int m = (l + r) / 2;
	if (p <= m) upd(ind*2, l, m, p, to);
	else upd(ind*2+1, m+1, r, p, to);
	seg[ind] = max(seg[ind*2], seg[ind*2+1]);
}

int qry(int ind, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return seg[ind];
	if (ql > r || qr < l) return 0;
	int m = (l + r) / 2;
	return max(qry(ind*2, l, m, ql, qr), qry(ind*2+1, m+1, r, ql, qr));
}

vector<pair<int, pair<int, int>>> mst_find(graph g) {
	ufds u;
	u.index = 1;
	u.set_n(n);
	auto x = g.edges;
	sort(x);
	vector<pair<int, pair<int, int>>> edges;
	for (auto e: x) {
		int w = e.first.first;
		int a = e.second.first, b = e.second.second;
		if (u.are_connected(a, b)) {
			

		}
		else {
			u.connect(a, b);
			edges.push_back({w, {a, b}});
		}
	}
	assert(edges.size() == n - 1);
	return edges;
}

void solve() {
	cin >> n >> m >> q;
	graph t;
	t.set_index(1);
	t.set_n(n);
	t.m = m;
	for (int i=1; i<=m; i++) {
		int a, b;
		cin >> a >> b;
		t.add_edge(a, b, i);
	}
	auto r = mst_find(t);
	for (auto x: r) {
		int a = x.second.first, b = x.second.second;
		int w = x.first;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	
	for (int i=0; i<=n; i++) for (int j=0; j<MXK; j++) par[i][j] = mxw[i][j] = 0;
	
	dfs(1, 0, 0);
	
	for (int i=0; i<=4*n; i++) seg[i] = 0;
	
	for (int i=1; i<n; i++) {
		

		upd(1, 1, n-1, i, pathq(i, i+1));
	}
	
	for (int i=0; i<q; i++) {
		int a, b;
		cin >> a >> b;
		if (a == b) {
			cout << 0 << ' ';
		}
		else {
			cout << qry(1, 1, n-1, a, b-1) << ' ';
		}
	}
	cout << endl;
	
	for (int i=1; i<=n; i++) {
		adj[i].clear();
	}
}

signed main() {
 
	ran(); fast(); doubleprint();
	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	
}