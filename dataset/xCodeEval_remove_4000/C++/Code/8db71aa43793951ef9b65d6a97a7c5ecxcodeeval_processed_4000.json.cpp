
 













using namespace std;











 
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvl> vvvl;
typedef vector<ii> vii;
typedef vector<pll> vll;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

void fast(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
void file(){
  
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
}
void start(){
  fast(); 
  

}

class id8 {
public:
	class Node;
 
	ll size;
	vector<Node*> roots;
	int last_version;
 
	class Node {
	public:
		int value;
		Node* left, * right;
 
		Node() {
			value = 0;
			left = NULL;
			right = NULL;
		}
 
		Node(Node* base) {
			value = base->value;
			left = base->getLeft();
			right = base->getRight();
		}
 
		Node* getLeft() {
			if (left == NULL) {
				left = new Node();
			}
			return left;
		}
 
		Node* getRight() {
			if (right == NULL) {
				right = new Node();
			}
			return right;
		}
 
		inline void update() {
			value = 0;
			if (left != NULL) value += getLeft()->value;
			if (right != NULL) value += getRight()->value;
		}
	};
 
	inline int addRoot(Node* vertex) {
		roots.push_back(vertex);
		last_version++;
		return last_version;
	}
 
	id8(int bits)
		:size((ll)1 << bits),
		last_version(-1)
	{
		Node* first_root = new Node();
		addRoot(first_root);
	}
 
	int index, delta;
 
	Node* UpdateTreeIndex(Node* current_root, int left, int right) {
		Node* new_root = new Node(current_root);
 
		if (left + 1 == right) {
			new_root->value += delta;
		}
		else {
			int mid = (left + right) >> 1;
 
			if (index < mid) {
				new_root->left = UpdateTreeIndex(current_root->getLeft(), left, mid);
			}
			else {
				new_root->right = UpdateTreeIndex(current_root->getRight(), mid, right);
			}
 
			new_root->update();
		}
 
		return new_root;
	}
 
	int UpdateIndex(ll ind) {
		index = ind;
		delta = 1;
 
		Node* new_root = UpdateTreeIndex(roots[last_version], 0, size);
 
		return addRoot(new_root);
	}
 
	int start, end;
	int answer;
 
	void GetTreeSegment(Node* vertex, ll left, ll right) {
		

		

		if (start <= left && right <= end) {
			answer += vertex->value;
		}
		else {
			ll mid = (left + right) >> 1;
 
			if (start < mid) GetTreeSegment(vertex->getLeft(), left, mid);
			if (mid < end) GetTreeSegment(vertex->getRight(), mid, right);
		}
		

	}
 
	int GetSegment(int version, ll S, ll E) {
		start = S;
		end = E;
 
		answer = 0;
 
		GetTreeSegment(roots[version], 0, size);
 
		return answer;
	}
};
 
class id2 {
private:
	class Node {
	public:
		ll v_max, summ, saved_op;
		Node* left, * right;
 
		Node() {
			v_max = 0;
			summ = 0;
			saved_op = 1e10;
			left = NULL;
			right = NULL;
		}
 
		Node(Node* base) {
			v_max = base->v_max;
			summ = base->summ;
			saved_op = base->saved_op;
			left = base->getLeft();
			right = base->getRight();
		}
 
		Node* getLeft() {
			if (left == NULL) {
				left = new Node();
			}
			return left;
		}
 
		Node* getRight() {
			if (right == NULL) {
				right = new Node();
			}
			return right;
		}
 
		ll get_summ(int left, int right) {
			if (saved_op != 1e10) return (right - left) * saved_op;
			if (saved_op == 1e10) return summ;
		}
 
		ll get_max(int left, int right) {
			if (saved_op == 1e10) return v_max;
			if (saved_op > 0) return (right - left) * saved_op;
			if (saved_op <= 0) return saved_op;
		}
 
		inline void updateVertex(int s, int e) {
			int mid = (s + e) >> 1;
 
			v_max = max(getLeft()->get_max(s, mid), getLeft()->get_summ(s, mid) + getRight()->get_max(mid, e));
			summ = getLeft()->get_summ(s, mid) + getRight()->get_summ(mid, e);
		}
 
		inline void push() {
			if (saved_op != 1e10) {
				getLeft()->saved_op = saved_op;
				getRight()->saved_op = saved_op;
			}
 
			saved_op = 1e10;
		}
	};
 
	ll size;
 
	ll delta = 0, start = 0, end = 0;
 
	Node* root = new Node();
 
	void updateTree(Node* vertex, int left, int right) {
		if (start <= left && right <= end) {
			vertex->saved_op = delta;
		}
		else {
			int mid = (left + right) >> 1;
 
			vertex->push();
 
			if (start < mid) updateTree(vertex->getLeft(), left, mid);
			if (mid < end) updateTree(vertex->getRight(), mid, right);
 
			vertex->updateVertex(left, right);
		}
	}
 
	ll allowed;
	void getAns(Node* vertex, int left, int right) {
		if (left + 1 == right) {
			if (vertex->get_max(left, right) > allowed) cout << left - 1 << '\n';
			if (vertex->get_max(left, right) <= allowed) cout << left << '\n';
		}
		else {
			int mid = (left + right) >> 1;
 
			vertex->push();
 
			ll res = (vertex->getLeft())->get_max(left, mid);
 
			if (res > allowed) {
				getAns(vertex->getLeft(), left, mid);
			}
			else {
				allowed -= (vertex->getLeft())->get_summ(left, mid);
				getAns(vertex->getRight(), mid, right);
			}
 
			vertex->updateVertex(left, right);
		}
	}
public:
	id2(ll n)
		:size(n)
	{}
	void update(int id3, int id0, int d) {
		delta = d;
		start = id3;
		end = id0;
		updateTree(root, 0, size);
	}
	void get(ll _allowed) {
		allowed = _allowed;
 
		getAns(root, 0, size);
	}
};
 
class id6 {
private:
	vvvl base;
 
	int magic(int x) {
		return x & (-x);
	}
 
	void updateTree(int ind_x, int ind_y, int ind_z, ll delta) {
		for (size_t ix = ind_x; ix < base.size(); ix += magic(ix))
			for (size_t iy = ind_y; iy < base[ix].size(); iy += magic(iy))
				for (size_t iz = ind_z; iz < base[ix][iy].size(); iz += magic(iz))
					base[ix][iy][iz] += delta;
	}
 
	ll getCube(int ind_x, int ind_y, int ind_z) {
		ll res = 0;
		if (ind_x < 1 && ind_y < 1 && ind_z < 1) return res;
		for (size_t ix = ind_x; ix > 0; ix -= magic(ix))
			for (size_t iy = ind_y; iy > 0; iy -= magic(iy))
				for (size_t iz = ind_z; iz > 0; iz -= magic(iz))
					res += base[ix][iy][iz];
		return res;
	}
 
public:
 
	void update(int& x, int& y, int& z, ll& delta) {
		x++; y++; z++;
		updateTree(x, y, z, delta);
	}
 
	ll get(int& x1, int& x2, int& y1, int& y2, int& z1, int& z2) {
		ll answer = 0;
 
		if (x1 < x2) swap(x1, x2);
		if (y1 < y2) swap(y1, y2);
		if (z1 < z2) swap(z1, z2);
 
		x1++; y1++; z1++;
 
		answer += getCube(x1, y1, z1);
		answer -= getCube(x1, y1, z2) + getCube(x1, y2, z1) + getCube(x2, y1, z1);
		answer += getCube(x1, y2, z2) - getCube(x2, y1, z2) - getCube(x2, y2, z1);
		

 
		return answer;
	}
 
	id6(int& n)
		:base(n + 1, vvl(n + 1, vl(n + 1, 0)))
	{}
};
 
class id5 {
private:
	vl base;
	vl a;
	int magic(int x) {
		return x & (-x);
	}
	void updateTree(int i, ll delta) {
		for (; i < base.size(); i += magic(i))
			base[i] += delta;
	}
	ll getTree(int i) {
		ll res = 0;
		for (; i > 0; i -= magic(i))
			res += base[i];
		return res;
	}
public:
	ll get(int start, int end) {
		return getTree(end + 1) - getTree(start);
	}
	void update(int ind, ll delta) {
		a[ind] += delta;
		updateTree(ind, delta);
	}
	id5(vl& _a)
		:base(_a.size() + 1, 0)
	{
		a = _a;
		int i;
		rep(i, a.size())
			updateTree(i + 1, a[i]);
	}
};
 
int x = 0;
 
class SegmentTree {
public:
	vl base_max, base_summ;
	vl saved_op;
	ll size;
 
	ll get_summ(int vertex, int left, int right) {
		if (saved_op[vertex] != 1e10) return (right - left) * saved_op[vertex];
		if (saved_op[vertex] == 1e10) return base_summ[vertex];
	}
 
	ll get_max(int vertex, int left, int right) {
		if (saved_op[vertex] == 1e10) return base_max[vertex];
		if (saved_op[vertex] > 0) return (right - left) * saved_op[vertex];
		if (saved_op[vertex] <= 0) return saved_op[vertex];
	}
 
	ll delta = 0, start = 0, end = 0;
	inline void updateVertex(int vertex, int s, int e) {
		int left = 2 * vertex;
		int right = left + 1;
 
		int mid = (s + e) >> 1;
 
		base_max[vertex] = max(get_max(left, s, mid), get_summ(left, s, mid) + get_max(right, mid, e));
		base_summ[vertex] = get_summ(left, s, mid) + get_summ(right, mid, e);
	}
 
	inline void push(int vertex) {
		int left = 2 * vertex;
		int right = left + 1;
 
		if (saved_op[vertex] != 1e10) {
			saved_op[left] = saved_op[vertex];
			saved_op[right] = saved_op[vertex];
		}
 
		saved_op[vertex] = 1e10;
	}
 
	void updateTree(int vertex, int left, int right) {
		if (start <= left && right <= end) {
			saved_op[vertex] = delta;
		}
		else {
			int mid = (left + right) >> 1;
 
			push(vertex);
 
			if (start < mid) updateTree(2 * vertex, left, mid);
			if (mid < end) updateTree(2 * vertex + 1, mid, right);
 
			updateVertex(vertex, left, right);
		}
	}
 
	ll allowed;
	int ans;
	void getAns(int vertex, int left, int right) {
		if (left + 1 == right) {
			if (get_max(vertex, left, right) > allowed) ans = left - 1;
			if (get_max(vertex, left, right) <= allowed) ans = left;
		}
		else {
			int mid = (left + right) >> 1;
 
			push(vertex);
 
			if (get_max(2 * vertex, left, mid) > allowed) {
				getAns(2 * vertex, left, mid);
			}
			else if (get_max(2 * vertex, left, mid) <= allowed) {
				allowed -= get_summ(2 * vertex, left, mid);
				getAns(2 * vertex + 1, mid, right);
			}
		}
	}
public:
	SegmentTree(ll n)
		:base_max(4 * n, 0),
		base_summ(4 * n, 0),
		saved_op(4 * n, 1e10),
		size(n)
	{}
	void update(int id3, int id0, int d) {
		delta = d;
		start = id3;
		end = id0;
		updateTree(1, 0, size);
	}
	ll get(ll _allowed) {
		allowed = _allowed;
 
		ans = 0;
 
		getAns(1, 0, size);
		return ans;
	}
};
 
class SparseTable {
private:
	const int MAX_BITS = 27;
 
	int size;
	vi max_bits;
	vvl table;
 
	inline void updateInd(ll& bit, int& first, int& second) {
		table[bit + 1][first] = max(table[bit][first], table[bit][second]);
	}
 
	void build(vl& a) {
		int i;
		rep(i, size)
			table[0][i] = a[i];
 
		int bit;
		rep(bit, MAX_BITS - 1) {
			int half = (1 << bit);
			for (int i = 0, j = half; j + half <= size; j++, i++) {
				updateInd(bit, i, j);
			}
		}
	}
 
public:
	SparseTable(int n, vl& a)
		: size(n)
		, table(MAX_BITS, vl(size))
		, max_bits(size + 1, 0)
	{
		max_bits[1] = 0;
		rep_s(len, 2, size + 1) {
			max_bits[len] = max_bits[len / 2] + 1;
		}
		build(a);
	}
 
	ll get(int start, int end) {
		end++;
 
		int length = end - start;
		int bit = max_bits[length];
		int power = 1 << bit;
 
		int result = max(table[bit][start], table[bit][end - power]);
		return result;
	}
};

inline void show(vi& a) {
	for (size_t i = 0; i < a.size(); i++) cout << a[i] << " ";
	cout << '\n';
}

inline void show_line(vi& a){
  for (size_t i = 0; i < a.size(); i++) cout << a[i];
	cout << '\n';
}

bool check_bit(int mask, int number){
  return (mask >> number) & 1;
}

int id7(ll mask){
  int ans = 0;
  while (mask > 0){
    if (mask % 2) ans++;
    mask /= 2;
  }
  return ans;
}

int id9(int mask, int number){
  if (check_bit(mask, number)){
    return mask - (1 << number);
  }else{
    return mask;
  }
}

int id1(int mask, int bit){
  return mask | (1 << bit);
}

int id4(int mask) {
	int ind = -1;
	int k = 0;
	while (mask > 0) {
		if ((mask % 2)) ind = k;
		mask /= 2;
		k++;
	}
	return ind;
}

bool is_subset(ll upper_mask, ll mask){
  ll res_mask = upper_mask | mask;
  return res_mask == upper_mask;
}



vvi graph;
vi color; 

int red = 0, black = 0;

const int N = 2e5 + 5;
int w[N];
vector<int> G[N];
pair<int, int> dp[N][2]; 

 
void dfs(int v, int p) {
  dp[v][1].second = 1 - G[v].size();
  dp[v][1].first = 1;
  for (int u: G[v]) {
    if (u != p) {
      dfs(u, v);
      int best = (dp[u][0] > dp[u][1] ? 0 : 1);
      dp[v][0].first += dp[u][best].first;
      dp[v][0].second += dp[u][best].second;
      dp[v][1].first += dp[u][0].first;
      dp[v][1].second += dp[u][0].second;
    }
  }
}
 
void dfs2(int v, int p, bool b) {
  w[v] = (b ? G[v].size() : 1);
  for (int u: G[v]) {
    if (u != p) {
      if (b) {
        dfs2(u, v, 0);
      }
      else {
        int best = (dp[u][0] > dp[u][1] ? 0 : 1);
        dfs2(u, v, best);
      }
    }
  }
}
 
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  if (n == 2) {
    cout << "2 2\n1 1\n";
    return 0;
  }
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 1);
  bool b = (dp[1][0] > dp[1][1] ? 0 : 1);
  dfs2(1, 1, b);
  pair<int, int> p = dp[1][b];
  cout << p.first << " " << n-p.second << '\n';
  for (int i = 1; i <= n; i++) {
    cout << w[i] << ' ';
  }
  cout << '\n';
}
