#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> piii;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef tuple<ll,ll,ll> plll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pil> vil;
typedef vector<pll> vll;
typedef vector<piii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vl> vvl;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef int (*itoi) (int);
typedef int (*iitoi) (int, int);
typedef int (*iiitoi) (int, int, int);
typedef ll (*ltol) (ll);
typedef ll (*lltol) (ll, ll);
typedef ll (*llltol) (ll, ll, ll);

const ld PI = acos(0)*2;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll*INF*INF;
int X4[] = {-1, 0, 1, 0}, Y4[] = {0, -1, 0, 1};
int X8[] = {-1, -1, -1, 0, 1, 1, 1, 0}, Y8[] = {-1, 0, 1, 1, 1, 0, -1, -1};

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int) (x).size())
#define NTH(v, x) ((int) (lower_bound(ALL(v), (x)) - (v).begin()))
#define SAME(v, x) ((int) (upper_bound(ALL(v), (x)) - lower_bound(ALL(v), (x))))
#define UNIQUE(v) v.erase(unique(ALL(v)), (v).end())
#define WER << ' ' <<

#define pb push_back
#define eb emplace_back
#define INP(t, x) t x; cin >> x

#define CPPIO ios::sync_with_stdio(0); cin.tie(0); cout << std::setprecision(10); cout << fixed

#define forn(x, n) for (int x=0; x<(n); x++)
#define for1(x, n) for (int x=1; x<=(n); x++)
#define ford(x, n) for (int x=(n)-1; x>=0; x--)
#define ford1(x, n) for (int x=(n); x>=1; x--)
#define forr(x, n, m) for (int x=(n); x<=(m); x++)
#define forrd(x, n, m) for (int x=(m); x>=(n); x--)

template<typename T> inline bool uax(T &a, T b) { return a<b? (a=b, 1) : 0; }
template<typename T> inline bool uin(T &a, T b) { return a>b? (a=b, 1) : 0; }
template<typename T1, typename T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
	return is >> p.first >> p.second;
}
template<typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1,T2>& p) {
	return os << '(' << p.first << ", " << p.second << ")";
}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	for (int i=0; i<(int)v.size(); i++) { os << v[i]; if (i+1<(int)v.size()) os << ' '; } return os;
}











#ifndef BINARY_INDEXED_TREE_DEFINED
template <class sum_type>
class binary_indexed_tree {
	private:
		typedef sum_type (*sum_op) (sum_type, sum_type);
		sum_op DEFAULT_ADD_OP = [](sum_type a, sum_type b) { return a + b; };
		sum_type DEFAULT_ADD_ID = 0;
	
	public:
		int max_index, min_index;
		int size;
		vector<sum_type> v;

		sum_op add_op = DEFAULT_ADD_OP;
		sum_type add_id = DEFAULT_ADD_ID;

		binary_indexed_tree<sum_type>() {}

		binary_indexed_tree<sum_type>(int min_index, int max_index,
				sum_op add_op=0, sum_type add_id=0) {
			this->max_index = max_index, this->min_index = min_index;
			if (add_op) this->add_op = add_op, this->add_id = add_id;
			assert(min_index <= max_index);
			for (size=1; size<max_index-min_index+1; size<<=1);
			v.assign(size * 2, add_id);
		}

		void update(int p, sum_type x) {
			assert(min_index <= p && p <= max_index);
			v[p=p-min_index+size] = x;
			for (p>>=1; p; p>>=1) {
				v[p] = add_op(v[p+p], v[p+p+1]);
			}
		}

		sum_type sum(int l, int r) {
			assert(min_index <= l && l <= r && r <= max_index);
			sum_type s = add_id;
			l = l - min_index + size, r = r - min_index + size;
			for (; l<=r; l>>=1, r>>=1) {
				if (l & 1) s = add_op(s, v[l++]);
				if ((r+1)&1) s = add_op(s, v[r--]);
			}
			return s;
		}
};
#endif

#define BINARY_INDEXED_TREE_DEFINED


















#ifndef TREAP_SUM_DEFINED
template <class element_type, class sum_type>
class __treap_sum_node {
	public:
		element_type key;
		sum_type sum;
		int priority, num_nodes, count;
		__treap_sum_node *left, *right;

		__treap_sum_node(element_type k, int cnt=1) : key(k), sum(cnt * ((sum_type) k)), priority(rand()), num_nodes(cnt), count(cnt), left(0), right(0) {}
		void calc_num_node() { num_nodes = count + (left? left->num_nodes : 0) + (right? right->num_nodes : 0); }
		void calc_sum() { sum = count * key + (left? left->sum : 0) + (right? right->sum : 0); }
		void set_left(__treap_sum_node *t) { left = t; calc_num_node(); calc_sum(); }
		void set_right(__treap_sum_node *t) { right = t; calc_num_node(); calc_sum(); }
};

template <class element_type, class sum_type>
using __treap_sum_pair = pair<__treap_sum_node<element_type, sum_type>*, __treap_sum_node<element_type, sum_type>* >;

template <class element_type, class sum_type>
struct treap_sum {
	private:
		typedef __treap_sum_node<element_type, sum_type> node;
		typedef __treap_sum_pair<element_type, sum_type> node_pair;

		node *root;
		int num_nodes;

	public:
		sum_type sum;
		bool enable_duplicates;
		treap_sum(bool _enable_duplicates=1) : root(0), num_nodes(0), sum(0), enable_duplicates(_enable_duplicates) {}

	private:
		node_pair* __splited(node *r, element_type key) {
			if (!r) return new node_pair(0, 0);
			if (r->key < key) {
				node_pair *p = __splited(r->right, key);
				r->set_right(p->first);
				return new node_pair(r, p->second);
			} else {
				node_pair *p = __splited(r->left, key);
				r->set_left(p->second);
				return new node_pair(p->first, r);
			}
		}

		node* __find_node(node *r, element_type key, int inc=0) {
			if (!r) return 0;
			if (r->key == key) {
				if (inc) r->count += inc, r->calc_num_node(), r->calc_sum();
				return r;
			}
			if (r->key < key) {
				if (inc) r->num_nodes += inc, r->sum += inc * key;
				return __find_node(r->right, key, inc);
			}
			if (inc) r->num_nodes += inc, r->sum += inc * key;
			return __find_node(r->left, key, inc);
		}

		node* __insert_node(node *r, node *n) {
			if (!r) return n;
			if (r->priority < n->priority) {
				node_pair *p = __splited(r, n->key);
				n->set_left(p->first);
				n->set_right(p->second);
				return n;
			}
			if (n->key < r->key) r->set_left(__insert_node(r->left, n));
			else r->set_right(__insert_node(r->right, n));
			return r;
		}

		node* __merge_node(node *n1, node *n2) {
			if (!n1) return n2;
			else if (!n2) return n1;
			else if (n1->priority < n2->priority) {
				n2->set_left(__merge_node(n1, n2->left));
				return n2;
			} else {
				n1->set_right(__merge_node(n1->right, n2));
				return n1;
			}
		}

		node* __erase_node(node *n, element_type key) {
			if (!n) return n;
			if (n->key == key) {
				node* ret = __merge_node(n->left, n->right);
				delete n;
				return ret;
			}
			if (key < n->key) n->set_left(__erase_node(n->left, key));
			else n->set_right(__erase_node(n->right, key));
			return n;
		}

		node* __kth_node(node* n, int k) {
			int left = 0;
			if (n->left) left = n->left->num_nodes;
			if (k <= left) return __kth_node(n->left, k);
			if (left+1 <= k && k <= left+n->count) return n;
			return __kth_node(n->right, k-left-n->count);
		}

		element_type __kth_smallest_sum(node* n, int k) {
			int left = 0;
			element_type left_sum = 0;
			if (n->left) left = n->left->num_nodes, left_sum = n->left->sum;
			if (k <= left) return __kth_smallest_sum(n->left, k);
			if (left+1 <= k && k <= left+n->count) return (k-left)*(n->key) + left_sum;
			return left_sum + (n->count)*(n->key) + __kth_smallest_sum(n->right, k-left-n->count);
		}

		int __count_greater(node* n, element_type key) {
			if (!n) return 0;
			if (n->key <= key) return __count_greater(n->right, key);
			return n->count + (n->right? n->right->num_nodes : 0) + __count_greater(n->left, key);
		}

		int __count_less(node* n, element_type key) {
			if (!n) return 0;
			if (n->key >= key) return __count_less(n->left, key);
			return n->count + (n->left? n->left->num_nodes : 0) + __count_less(n->right, key);
		}

		element_type __sum_greater(node* n, element_type key) {
			if (!n) return 0;
			if (n->key <= key) return __sum_greater(n->right, key);
			return (n->right? n->right->sum : 0) + (n->count * n->key) + __sum_greater(n->left, key);
		}

		element_type __sum_less(node* n, element_type key) {
			if (!n) return 0;
			if (n->key >= key) return __sum_less(n->left, key);
			return (n->left? n->left->sum : 0) + (n->count * n->key) + __sum_less(n->right, key);
		}

		void __print_node(node *n) {
			if (n) {
				__print_node(n->left);
				

				for (int i=0; i<n->count; i++) cout << n->key << ' ';
				__print_node(n->right);
			}
		}

		node* __biggest(node *n) {
			if (n->right) return __biggest(n->right);
			else return n;
		}

		node* __smallest(node *n) {
			if (n->left) return __smallest(n->left);
			else return n;
		}

		void __disable_duplicates(node *n) {
			n->count = 1;
			if (n->left) __disable_duplicates(n->left);
			if (n->right) __disable_duplicates(n->right);
			n->calc_num_node();
			n->calc_sum();
		}

		void __vectorize(node *n, vector<element_type> &v) {
			if (n->left) __vectorize(n->left, v);
			for (int i=0; i<n->count; i++) v.push_back(n->key);
			if (n->right) __vectorize(n->right, v);
		}
	
	public:
		int size() {
			return num_nodes;
		}

		bool empty() {
			return num_nodes == 0;
		}

		void print() {
			

			__print_node(root);
			cout << "(num_nodes: " << num_nodes << ", sum: " << sum << ")" << endl;
		}

		void insert(element_type key, int cnt=1) {
			

			node *f = __find_node(root, key);
			if (!enable_duplicates) cnt = 1;
			if (f) {
				__find_node(root, key, enable_duplicates? cnt : 0);
			} else {
				node *n = new node(key, cnt);
				root = __insert_node(root, n);
			}
			num_nodes = root->num_nodes;
			sum = root->sum;
		}

		bool erase(element_type key, int cnt=1) {
			

			

			node *f = __find_node(root, key);
			if (f) {
				if (f->count <= cnt) root = __erase_node(root, key);
				else __find_node(root, key, -cnt);
				num_nodes = root? root->num_nodes : 0;
				sum = root? root->sum : 0;
				return 1;
			} else return 0;
		}

		bool erase_key(element_type key) {
			

			

			node *f = __find_node(root, key);
			if (f) {
				root = __erase_node(root, key);
				num_nodes = root? root->num_nodes : 0;
				sum = root? root->sum : 0;
				return 1;
			} else return 0;
		}

		element_type kth(int k) {
			

			assert(1 <= k && k <= num_nodes);
			return __kth_node(root, k)->key;
		}

		element_type kth_biggest(int k) {
			return kth(num_nodes + 1 - k);
		}

		element_type kth_smallest_sum(int k) {
			

			assert(1 <= k && k <= num_nodes);
			return __kth_smallest_sum(root, k);
		}

		element_type kth_biggest_sum(int k) {
			

			assert(1 <= k && k <= num_nodes);
			return sum - __kth_smallest_sum(root, num_nodes-k);
		}

		int count(element_type key) {
			

			node *f = __find_node(root, key);
			return f? f->count : 0;
		}

		int count_greater(element_type key) {
			

			return __count_greater(root, key);
		}

		int count_less(element_type key) {
			

			return __count_less(root, key);
		}

		element_type sum_same(element_type key) {
			

			node *f = __find_node(root, key);
			return f? (f->count * f->key) : 0;
		}

		element_type sum_greater(element_type key) {
			

			return __sum_greater(root, key);
		}

		element_type sum_less(element_type key) {
			

			return __sum_less(root, key);
		}

		element_type biggest() {
			

			assert(root);
			return __biggest(root)->key;
		}

		element_type smallest() {
			

			assert(root);
			return __smallest(root)->key;
		}

		void set_duplicates(bool duplicates) {
			

			if (enable_duplicates == duplicates) return;
			enable_duplicates = duplicates;
			if (!duplicates) {
				if (root) __disable_duplicates(root);
				num_nodes = root? root->num_nodes : 0;
				sum = root? root->sum : 0;
			}
		}

	vector<element_type>& vectorize() {
		vector<element_type> *pv = new vector<element_type>(), &v = *pv;
		if (root) __vectorize(root, v);
		return v;
	}
};
#endif

#define TREAP_SUM_DEFINED








const int MAX_N = 2e5 + 20;

int N;
int P[MAX_N], Pos[MAX_N];
binary_indexed_tree<int> Bit(1, MAX_N);
treap_sum<ll,ll> Tr;


int main() {
	CPPIO;
	
	

	
	cin >> N;
	for1(i, N) {
		cin >> P[i];
		Pos[P[i]] = i;
	}

	ll cntinv = 0;

	for (ll k=1; k<=N; k++) {
		cntinv += Bit.sum(Pos[k], N);
		Bit.update(Pos[k], 1);

		Tr.insert(Pos[k]);
		ll mid = (k+1)/2, rem = k - mid;
		ll q_m = Tr.kth(mid);
		ll s = q_m - mid;

		ll sum = s * mid + mid * (mid+1) / 2 - s * rem - (k*(k+1)/2 - mid*(mid+1)/2);
		sum -= Tr.kth_smallest_sum(mid);
		sum += rem>0? Tr.kth_biggest_sum(rem) : 0;

		cout << sum+cntinv << ' ';
	}
	cout << endl;
	
	
#ifdef LOCAL_DEFINE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
	return 0;
}
