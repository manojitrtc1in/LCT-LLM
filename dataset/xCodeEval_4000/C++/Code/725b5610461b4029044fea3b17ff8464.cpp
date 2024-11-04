#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
using std::cout;
using std::cin;



#define val(x) ;

#ifdef __linux__
char leftUp[] = {'\t', 0};
char leftDown[] = "\xe2\x94\x82\t";
char rightUp[] = "\xe2\x94\x82\t";
char rightDown[] = {'\t', 0};
char Up[] = "\xe2\x94\x8c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80";
char Down[] = "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80";
char Pass[] = "\xe2\x94\x9c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80";
#elif _WIN32
char leftUp[] = {'\t', 0};
char leftDown[] = {-77, '\t', 0}; 

char rightUp[] = {-77, '\t', 0};  

char rightDown[] = {'\t', 0};
char Up[] = {-38, -60, -60, -60, -60, -60, -60, -60, 0};   

char Down[] = {-64, -60, -60, -60, -60, -60, -60, -60, 0}; 

char Pass[] = {-61, -60, -60, -60, -60, -60, -60, -60, 0}; 

#endif

struct Node {
	int vertex;
	ll weight;
};

class Graph {
	bool directed;

  public:
	std::vector<std::vector<Node>> adjList;
	int V;
	int E;

	Graph(int N, bool DIRECTED) {
		V = N;
		E = 0;
		adjList.resize(N);
		directed = DIRECTED;
	}
	void addEdge(int u, int v, ll w) {
		E++;
		adjList[u].push_back({v, w});
		if (!directed)
			adjList[v].push_back({u, w});
	}
	void compress() {
		for (auto list : adjList)
			list.shrink_to_fit();
	}
};
class UnionFind {
	std::vector<int> id;
	std::vector<int> rank;

  public:
	UnionFind(int N) {
		id.resize(N);
		rank.resize(N);
		for (int i = 0; i < N; i++) {
			id[i] = i;
			rank[i] = 0;
		}
	}
	int find(int x) {
		if (id[x] != x)
			id[x] = find(id[x]);
		return id[x];
	}
	void Union(int x, int y) {
		int first = find(x);
		int second = find(y);
		if (first == second)
			return;
		if (rank[first] > rank[second]) {
			id[second] = first;
		}
		else if (rank[first] < rank[second]) {
			id[first] = second;
		}
		else if (second != first) {
			id[second] = first;
			rank[first]++;
		}
	}
};

void dijkstra(Graph &G, int source) {
	std::vector<ll> distance(G.V, LLONG_MAX);
	std::vector<int> parent(G.V, -1);
	std::vector<bool> done(G.V, false);
	auto cmp = [](const Node &left, const Node &right) { return left.weight > right.weight; };
	std::priority_queue<Node, std::vector<Node>, decltype(cmp)> pq(cmp);
	distance[source] = 0;
	pq.push({source, 0});
	while (pq.size() > 0) {
		Node temp = pq.top();
		pq.pop();
		if (done[temp.vertex])
			continue;
		int u = temp.vertex;
		distance[u] = temp.weight;
		done[u] = true;
		for (Node &node : G.adjList[u]) {
			int v = node.vertex;
			ll cost = node.weight;
			if (distance[v] > distance[u] + cost) {
				pq.push({v, distance[u] + cost});
				parent[v] = u;
			}
		}
	}
	for (int i = 0; i < G.V; i++)
		std::cout << distance[i] << " ";
	std::cout << "\n";
}

int dijkstraTest() {
	int v, e, u;
	ll cost;
	std::cin >> v;
	Graph g(v, false);
	std::cin >> e;
	for (int i = 0; i < e; i++) {
		std::cin >> u >> v >> cost;
		g.addEdge(u, v, cost);
	}
	std::cin >> u;
	dijkstra(g, u);
	return 0;
}

ll minimum(const std::vector<ll> &array, unsigned left, unsigned right) {
	ll min = LLONG_MAX / 10000;
	val(array.size());
	val(right);
	for (unsigned i = left; i < right; i++) {
		val(left);
		val(i);
		if (array.at(i) < min)
			min = array.at(i);
		val(right);
	}
	return min;
}

class Magic {
  public:
	std::vector<ll> A;
	std::vector<ll> M;
	int BLK_SIZE;
	Magic(int N) {
		BLK_SIZE = std::sqrt(N);
		val(BLK_SIZE);
	}
	void push_back(ll cost) {
		unsigned x = A.size();
		if (x % BLK_SIZE == 0) {
			A.push_back(cost);
			M.push_back(cost);
		}
		else {
			A.push_back(cost);
			M.back() = std::min(M.back(), cost);
		}
	}
	void pop_back() {
		unsigned x = A.size();
		if (x == 0)
			return;
		if (x % BLK_SIZE == 1) {
			A.pop_back();
			M.pop_back();
			return;
		}
		if (M.back() == A.back()) {
			A.pop_back();
			x--;
			M.back() = minimum(A, x - (x % BLK_SIZE), A.size());
		}
		else
			A.pop_back();
	}
	ll getMinimum(unsigned left) {
		unsigned index;
		if (A.size() == 0 || left == 0)
			return LLONG_MAX / 10000;
		if (left > A.size())
			index = 0;
		else
			index = A.size() - left;
		unsigned nextBlk = index / BLK_SIZE + 1;
		if (nextBlk == M.size())
			return minimum(A, index, A.size());
		return std::min(minimum(A, index, nextBlk * BLK_SIZE), minimum(M, nextBlk, M.size()));
	}
	void printStruct() {
		

		

		

		for (unsigned i = 0; i < A.size(); i++)
			std::cout << A[i] << "\t";
		std::cout << "\n";
	}
};

namespace comb {
	const ll MAX = 1000000007;
	std::vector<ll> fact;
	void initFact(int maximum) {
		fact.resize(maximum + 1, 0);
		fact[0] = 1;
		for (ll i = 1; i <= maximum; i++)
			fact[i] = ((fact[i - 1] % MAX) * (i % MAX)) % MAX;
	}
	inline ll mod(ll i) {
		return (i % MAX + MAX) % MAX;
	}
	ll powa(ll a, ll p) {
		if (p == 1)
			return mod(a);
		if (p == 0)
			return 1;
		ll ans = (powa(a, p / 2) % MAX);
		if (p % 2 == 0)
			return ((ans % MAX) * (ans % MAX)) % (MAX);
		else {
			ans = ((ans % MAX) * (ans % MAX)) % (MAX);
			ans = ((ans % MAX) * (a % MAX)) % (MAX);
			return ans;
		}
	}
	ll modInv(ll a) {
		a = mod(a);
		return powa(a, MAX - 2) % MAX;
	}
	ll atomic_nCr(ll n, ll k) {
		if (n < k)
			return 0;
		if (k == 0 || k == n)
			return 1;
		if (k == 1 || k == n - 1)
			return n;
		ll f = fact[n];
		ll s = ((fact[k] % MAX) * (fact[n - k] % MAX)) % MAX;
		return ((f % MAX) * (modInv(s) % MAX)) % MAX;
	}
	ll nCr(ll n, ll k) {
		ll ans = 1;
		while (n > 0 || k > 0) {
			ll temp = atomic_nCr(n % MAX, k % MAX);
			ans = ((ans % MAX) * (temp % MAX)) % MAX;
			n /= MAX;
			k /= MAX;
		}
		return ans;
	}
}
namespace geo2D {
	using dataType = int;
	class Point {
	  public:
		dataType x, y;
		Point() : x(0), y(0) {}
		Point(dataType X, dataType Y) : x(X), y(Y) {}
	};

	bool operator==(const Point &left, const Point &right) { return (left.x == right.x) && (left.y == right.y); }
	bool operator!=(const Point &left, const Point &right) { return (left.x != right.x) || (left.y != right.y); }

	Point operator-(const Point &right) { return Point(-right.x, -right.y); }
	Point operator+(const Point &left, const Point &right) { return Point(left.x + right.x, left.y + right.y); }
	Point operator-(const Point &left, const Point &right) { return Point(left.x - right.x, left.y - right.y); }
	Point operator*(const Point &left, dataType right) { return Point(left.x * right, left.y * right); }
	Point operator*(dataType left, const Point &right) { return Point(right.x * left, right.y * left); }
	Point operator/(const Point &left, dataType right) { return Point(left.x / right, left.y / right); }

	dataType dissq(const Point &a, const Point &b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); }
	double dis(const Point &a, const Point &b) { return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }
	double len(const Point &a) { return std::sqrt(a.x * a.x + a.y * a.y); }
	dataType lenSq(const Point &a) { return (a.x * a.x + a.y * a.y); }

	std::ostream &operator<<(std::ostream &os, const Point &a) { return os << "(" << a.x << "," << a.y << ")"; }

	Point unit(const Point &a) { return a / len(a); }

	dataType dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
	dataType cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
	Point proj(const Point &a, const Point &b) { return (b * dot(a, b)) / len(b); }
	Point projOnUnit(const Point &a, const Point &b) { return b * dot(a, b); }

	dataType turn(const Point &a, const Point &b, const Point &c) { return cross(b - a, c - b); }

	std::pair<double, double> intersection(const Point &a1, const Point &b1, const Point &a2, const Point &b2) {
		dataType t1 = cross(b1 - a1, b2 - a2),
				 t2 = cross(a2 - a1, b2 - a2),
				 t3 = cross(a2 - a1, b1 - a1);
		if (t1 == 0)
			return {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()};
		return {double(t2) / t1, double(t3) / t1};
	}

	double distFromLine(const Point &start, const Point &end, const Point &pt) {
		dataType param = dot(pt - start, end - start) / dissq(end, start);
		if (param < 0)
			return dissq(start, pt);
		if (param > 1)
			return dissq(end, pt);
		else
			return dissq(pt, start + param * (end - start));
	}
}

class SegmentTree {
	std::vector<ll> tree;
	std::vector<ll> lazy;
	int N;
	ll result(ll q1, ll q2) {
		return std::min(q1, q2);
	}
	void build_tree(int node, int treeLeft, int treeRight, const std::vector<ll> &array) {
		if (treeLeft > treeRight)
			return; 


		if (treeLeft == treeRight) {	  

			tree[node] = array[treeLeft]; 

			return;
		}

		build_tree(node * 2, treeLeft, (treeLeft + treeRight) / 2, array);			

		build_tree(node * 2 + 1, 1 + (treeLeft + treeRight) / 2, treeRight, array); 


		tree[node] = result(tree[node * 2], tree[node * 2 + 1]);
	}

	void lazy_update_tree(int node, int treeLeft, int treeRight, int rangeLeft, int rangeRight, ll Y) {
		if (lazy[node]) {
			tree[node] += lazy[node]; 


			if (treeLeft != treeRight) {
				lazy[node * 2] += lazy[node];	 

				lazy[node * 2 + 1] += lazy[node]; 

			}

			lazy[node] = 0; 

		}

		if (treeLeft > treeRight || treeLeft > rangeRight || treeRight < rangeLeft) 

			return;

		if (rangeLeft <= treeLeft && treeRight <= rangeRight) {
			tree[node] += Y;
			if (treeLeft != treeRight) {
				lazy[node * 2] += Y;
				lazy[node * 2 + 1] += Y;
			}
			return;
		}

		lazy_update_tree(node * 2, treeLeft, (treeLeft + treeRight) / 2, rangeLeft, rangeRight, Y);			 

		lazy_update_tree(1 + node * 2, 1 + (treeLeft + treeRight) / 2, treeRight, rangeLeft, rangeRight, Y); 


		tree[node] = result(tree[2 * node], tree[2 * node + 1]);
	}

	ll query_tree(int x, int treeLeft, int treeRight, int rangeLeft, int rangeRight) {
		if (lazy[x]) {
			tree[x] += lazy[x]; 


			if (treeLeft != treeRight) {
				lazy[x * 2] += lazy[x];		

				lazy[x * 2 + 1] += lazy[x]; 

			}

			lazy[x] = 0; 

		}

		if (treeLeft > treeRight || treeLeft > rangeRight || treeRight < rangeLeft)
			return LLONG_MAX; 


		if (treeLeft >= rangeLeft && treeRight <= rangeRight) 

			return tree[x];

		ll q1 = query_tree(x * 2, treeLeft, (treeLeft + treeRight) / 2, rangeLeft, rangeRight);			 

		ll q2 = query_tree(1 + x * 2, 1 + (treeLeft + treeRight) / 2, treeRight, rangeLeft, rangeRight); 


		return result(q1, q2);
	}
	void printBST(int i, int treeLeft, int treeRight, const std::string &str, int side) {
		if (side % 2) {
			if (treeLeft == treeRight) {
				std::cerr << str << Down << "([" << treeLeft << ":" << treeRight << "]" << tree[i] << "," << lazy[i] << ")\n";
				return;
			}
			printBST(2 * i + 1, 1 + (treeLeft + treeRight) / 2, treeRight, str + rightUp, 0);
			std::cerr << str << Down << "([" << treeLeft << ":" << treeRight << "]" << tree[i] << "," << lazy[i] << ")\n";
			printBST(2 * i, treeLeft, (treeLeft + treeRight) / 2, str + rightDown, 1);
		}
		else {
			if (treeLeft == treeRight) {
				std::cerr << str << Up << "([" << treeLeft << ":" << treeRight << "]" << tree[i] << "," << lazy[i] << ")\n";
				return;
			}
			printBST(2 * i + 1, 1 + (treeLeft + treeRight) / 2, treeRight, str + leftUp, 0);
			std::cerr << str << Up << "([" << treeLeft << ":" << treeRight << "]" << tree[i] << "," << lazy[i] << ")\n";
			printBST(2 * i, treeLeft, (treeLeft + treeRight) / 2, str + leftDown, 1);
		}
	}

  public:
	SegmentTree(const std::vector<ll> &array) {
		N = array.size() - 1;
		if (N != 0) {
			tree.resize(4 * N, 0);
			lazy.resize(4 * N, 0);
		}
		else {
			tree.resize(2, 0);
			lazy.resize(2, 0);
		}
		build_tree(1, 0, N, array);
	}
	ll get(int left, int right) {
		return query_tree(1, 0, N, left, right);
	}
	void updateTree(int left, int right, int value) {
		lazy_update_tree(1, 0, N, left, right, value);
	}
	void printTree() {
		printBST(3, N / 2 + 1, N, "", 0);
		std::cerr << "(" << tree[1] << "," << lazy[1] << ")\n";
		printBST(2, 0, N / 2, "", 1);

		std::cerr << "\n";
	}
};

std::vector<std::string> split(std::string str, std::string splitChars) {
	std::unordered_set<char> breaker;
	for (char ch : splitChars)
		breaker.insert(ch);
	std::vector<std::string> array;
	std::string current = "";
	for (char ch : str) {
		if (breaker.find(ch) != breaker.end()) {
			if (current != "")
				array.push_back(current);
			current = "";
		}
		else
			current.push_back(ch);
	}
	if (current != "")
		array.push_back(current);
	return array;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, m, l, r, v;
	cin >> n;
	std::vector<ll> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	cin >> m;
	SegmentTree seg(nums);
	

	for (int i = 0; i < m; ++i) {
		cin >> l >> r;
		if (cin.peek() != ' ') {
			

			if (l <= r)
				cout << seg.get(l, r) << "\n";
			else {
				cout << std::min(seg.get(0, r), seg.get(l, n - 1)) << "\n";
			}
			

		}
		else {
			cin >> v;
			

			if (l <= r) {
				

				seg.updateTree(l, r, v);
				

			}
			else {
				

				seg.updateTree(0, r, v);
				

				

				seg.updateTree(l, n - 1, v);
				

			}
		}
	}
	return 0;
}

