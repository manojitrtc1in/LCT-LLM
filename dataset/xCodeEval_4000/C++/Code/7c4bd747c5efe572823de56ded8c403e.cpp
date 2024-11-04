#define _CRT_SECURE_NO_WARNINGS
 
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <random>
#include <sstream>
#include <set>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;

#define rep(i, n) for (ll i=0;i<n;i++)
#define rep_int_1(i, n) for (int i=1;i<n;i++)
#define rep_s(i, s, n) for (ll i=s;i<n;i++)
#define for_int(i, n, k) for (int i=0;i<n;i+=k)
#define for_int_s(i, s, n, k) for(int i=s;i<n;i+=k)
#define min_it(a, b) a = min(a, b);
#define max_it(a, b) a = max(a, b);
#define read_int(n) int n; cin >> n;
#define read_int2(f, s) int f, s; cin >> f >> s;
#define read_int3(f, s, t) int f, s, t; cin >> f >> s >> t;
 
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
  #ifndef FILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
void start(){
  fast(); 
  

}

class PersistentRadixSegmentTree {
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
 
	PersistentRadixSegmentTree(int bits)
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
 
class RadixSegmentTree {
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
	RadixSegmentTree(ll n)
		:size(n)
	{}
	void update(int _start_incl, int _end_excl, int d) {
		delta = d;
		start = _start_incl;
		end = _end_excl;
		updateTree(root, 0, size);
	}
	void get(ll _allowed) {
		allowed = _allowed;
 
		getAns(root, 0, size);
	}
};
 
class Fenvik_3d {
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
 
	Fenvik_3d(int& n)
		:base(n + 1, vvl(n + 1, vl(n + 1, 0)))
	{}
};
 
class Fenvik {
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
	Fenvik(vl& _a)
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
	void update(int _start_incl, int _end_excl, int d) {
		delta = d;
		start = _start_incl;
		end = _end_excl;
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

int number_of_1(int mask){
  int ans = 0;
  while (mask > 0){
    if (mask % 2) ans++;
    mask /= 2;
  }
  return ans;
}

int nullify_1(int mask, int number){
  if (check_bit(mask, number)){
    return mask - (1 << number);
  }else{
    return mask;
  }
}

int add_1(int mask, int bit){
  return mask | (1 << bit);
}

int first_bit_ind(int mask) {
	int ind = -1;
	int k = 0;
	while (mask > 0) {
		if ((mask % 2)) ind = k;
		mask /= 2;
		k++;
	}
	return ind;
}

bool is_subset(int upper_mask, int mask){
  int res_mask = upper_mask | mask;
  return res_mask == upper_mask;
}
int n, m, d;

void dp(int mask, vi &sets){
  sets[mask] = 0;
  if (sets[mask] == 0)
      rep (i, first_bit_ind(mask) + 1){
        if (sets[nullify_1(mask, i)]) 
          dp(nullify_1(mask, i), sets);
      }
}

const int loga = 70;

signed main() {
    int t;
    cin >> t;
    for (int _i = 0; _i < t; _i++) {
        int n;
        cin >> n;
        int x;
        cin >> x;
        if (x == 1) {
            set<int> v;
            for (int i = 0; i < n; i++) {
                int a;
                cin >> a;
                if (v.find(a) == v.end()) {
                    v.insert(a);
                } else {
                    v.erase(a);
                }
            }
            cout << v.size() << endl;
            for (auto num : v) {
                cout << num << ' ';
            } 
            continue;
        }
        int zero_cnt = 0;
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == 0) {
                zero_cnt++;
                continue;
            }
            int p = 0;
            while (a % x == 0) {
                p++;
                a /= x;
            }
            if (mp.find(a) != mp.end()) {
                mp[a][p]++;
            } else {
                mp[a] = vector<int> (loga);
                mp[a][p]++;
            }
        }
        vector<int> res;
        for (auto [k, v] : mp) {
            int p = 1;
            for (int i = 0; i < loga - 1; i++) {
                int dec = min(v[i], v[i + 1]);
                v[i] -= dec;
                v[i + 1] -= dec;
                for (int j = 0; j < v[i]; j++) {
                    res.push_back(k * (p * x));
                }
                p *= x;
            }
            for (int j = 0; j < v[loga - 1]; j++) {
                res.push_back(k * (p * x));
            }
        }
        if (zero_cnt % 2 == 1) {
            res.push_back(0);
        }
        cout << res.size() << endl;
    }
}