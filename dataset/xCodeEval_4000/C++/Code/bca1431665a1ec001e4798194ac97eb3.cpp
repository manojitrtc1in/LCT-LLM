#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <tuple>
#include <ctime>
using namespace std;

const int Maxn = 500005;
int n, m, q, a[Maxn];
long long sum[Maxn];
vector <int> has[Maxn];
int ans[Maxn], vis[Maxn];

namespace red_black_tree {
#define bro(x) (((x) -> ftr -> lc == (x)) ? ((x) -> ftr -> rc) : ((x) -> ftr -> lc))
#define islc(x) ((x) != NULL && (x) -> ftr -> lc == (x))
#define isrc(x) ((x) != NULL && (x) -> ftr -> rc == (x))
	template <typename T>
	class rbtree {
		protected:
			struct Node;
			Node *_root;
			Node *_hot;
			void init(T);
			void connect34(Node *, Node *, Node *, Node *, Node *, Node *, Node *);
			void SolveDoubleRed(Node *);
			void SolveDoubleBlack(Node *);
			Node *find(T, const int);
			Node *rfind(T, const int);
			Node *findatrank(int, Node *);
			int find_atrank(T, Node *);
		public:
			struct iterator;
			rbtree() : _root(NULL), _hot(NULL) { }
			rbtree(const rbtree &a) { *this = a; }
			inline int rank(T);
			inline iterator insert(T);
			inline bool erase(T);
			inline int size();
			inline bool empty();
			iterator atrank(int);
			iterator lower_bound(T);
			iterator upper_bound(T);
	};
	template <typename T>
	struct rbtree <T> :: Node {
		T val;
		bool RBc;
		Node *ftr;
		Node *lc;
		Node *rc;
		int s;
		Node(T v = T(), bool RB = true,
			Node *f = NULL, Node *l = NULL, Node *r = NULL, int ss = 1)
			: val(v), RBc(RB), ftr(f), lc(l), rc(r), s(ss) {}
		Node *succ() {
			Node *ptn = rc;
			while (ptn -> lc != NULL) {
				--(ptn -> s);
				ptn = ptn -> lc;
			}
			return ptn;
		}
		Node *left_node() {
			Node *ptn = this;
			if (!lc) {
				while (ptn -> ftr && ptn -> ftr -> lc == ptn)
					ptn = ptn -> ftr;
				ptn = ptn -> ftr;
			}
			else
				while (ptn -> lc)
					ptn = ptn -> lc;
			return ptn;
		}
		Node *right_node() {
			Node *ptn = this;
			if (!rc) {
				while (ptn -> ftr && ptn -> ftr -> rc == ptn)
					ptn = ptn -> ftr;
				ptn = ptn -> ftr;
			}
			else
				while (ptn -> rc)
					ptn = ptn -> rc;
			return ptn;
		}
		void maintain() {
			s = 1;
			if (lc)
				s += lc -> s;
			if (rc)
				s += rc -> s;
		}
	};
	template <typename T>
	struct rbtree<T>::iterator {
		private:
			Node *_real__node;
		public:
			iterator &operator++() {
				_real__node = _real__node -> right_node();
				return *this;
			}
			iterator &operator--() {
				_real__node = _real__node -> left_node();
				return *this;
			}
			T operator*() {
				return _real__node -> val;
			}
			iterator(Node *node_nn = NULL) : _real__node(node_nn) {}
			iterator(T const &val_vv) : _real__node(rfind(val_vv, 0)) {}
			iterator(iterator const &iter) : _real__node(iter._real__node) {}
	};
	template <typename T>
	typename
	rbtree<T>::iterator rbtree<T>::insert(T v) {
		Node *ptn = find(v, 1);
		if (_hot == NULL) {
			init(v);
			return iterator(_root);
		}
		ptn = new Node(v, true, _hot, NULL, NULL, 1);
		if (_hot -> val <= v)
			_hot -> rc = ptn;
		else
			_hot -> lc = ptn;
		SolveDoubleRed(ptn);
		return iterator(ptn);
	}
	template <typename T>
	void rbtree<T>::init(T v) {
		_root = new Node(v, false, NULL, NULL, NULL, 1);
	}
	template <typename T>
	typename
	rbtree<T>::Node *rbtree<T>::find(T v, const int op) {
		Node *ptn = _root;
		_hot = NULL;
		while (ptn != NULL) {
			_hot = ptn;
			ptn -> s += op;
			if (ptn -> val > v)
				ptn = ptn -> lc;
			else
				ptn = ptn -> rc;
		}
		return ptn;
	}
	template <typename T>
	typename
	rbtree<T>::Node *rbtree<T>::rfind(T v, const int op) {
		Node *ptn = _root;
		_hot = NULL;
		while (ptn != NULL && ptn -> val != v) {
			_hot = ptn;
			ptn -> s += op;
			if (ptn -> val > v)
				ptn = ptn -> lc;
			else
				ptn = ptn -> rc;
		}
		return ptn;
	}
	template <typename T>
	void rbtree<T>::SolveDoubleRed(Node *nn) {
		while ((!(nn -> ftr)) || nn -> ftr -> RBc) {
			if (nn == _root) {
				_root -> RBc = false;
				return;
			}
			Node *pftr = nn -> ftr;
			if (!(pftr -> RBc))
				return;
			Node *uncle = bro(nn -> ftr);
			Node *grdftr = nn -> ftr -> ftr;
			if (uncle != NULL && uncle -> RBc) {
				grdftr -> RBc = true;
				uncle -> RBc = false;
				pftr -> RBc = false;
				nn = grdftr;
			}
			else {
				if (islc(pftr)) {
					if (islc(nn)) {
						pftr -> ftr = grdftr -> ftr;
						if (grdftr == _root)
							_root = pftr;
						else if (grdftr -> ftr -> lc == grdftr)
							grdftr -> ftr -> lc = pftr;
						else
							grdftr -> ftr -> rc = pftr;
						connect34(pftr, nn, grdftr, nn -> lc, nn -> rc, pftr -> rc, uncle);
						pftr -> RBc = false;
						grdftr -> RBc = true;
					}
					else {
						nn -> ftr = grdftr -> ftr;
						if (grdftr == _root)
							_root = nn;
						else if (grdftr -> ftr -> lc == grdftr)
							grdftr -> ftr -> lc = nn;
						else
							grdftr -> ftr -> rc = nn;
						connect34(nn, pftr, grdftr, pftr -> lc, nn -> lc, nn -> rc, uncle);
						nn -> RBc = false;
						grdftr -> RBc = true;
					}
				}
				else {
					if (islc(nn)) {
						nn -> ftr = grdftr -> ftr;
						if (grdftr == _root)
							_root = nn;
						else if (grdftr -> ftr -> lc == grdftr)
							grdftr -> ftr -> lc = nn;
						else
							grdftr -> ftr -> rc = nn;
						connect34(nn, grdftr, pftr, uncle, nn -> lc, nn -> rc, pftr -> rc);
						nn -> RBc = false;
						grdftr -> RBc = true;
					}
					else {
						pftr -> ftr = grdftr -> ftr;
						if (grdftr == _root)
							_root = pftr;
						else if (grdftr -> ftr -> lc == grdftr)
							grdftr -> ftr -> lc = pftr;
						else
							grdftr -> ftr -> rc = pftr;
						connect34(pftr, grdftr, nn, uncle, pftr -> lc, nn -> lc, nn -> rc);
						pftr -> RBc = false;
						grdftr -> RBc = true;
					}
				}
				return;
			}
		}
	}
	template <typename T>
	void rbtree<T>::connect34(Node *nroot,		Node *nlc,			Node *nrc,
		Node *ntree1,	 Node *ntree2,	 Node *ntree3,	 Node *ntree4) {
		nlc -> lc = ntree1;
		if (ntree1 != NULL)
			ntree1 -> ftr = nlc;
		nlc -> rc = ntree2;
		if (ntree2 != NULL)
			ntree2 -> ftr = nlc;
		nrc -> lc = ntree3;
		if (ntree3 != NULL)
			ntree3 -> ftr = nrc;
		nrc -> rc = ntree4;
		if (ntree4 != NULL)
			ntree4 -> ftr = nrc;
		nroot -> lc = nlc;
		nlc -> ftr = nroot;
		nroot -> rc = nrc;
		nrc -> ftr = nroot;
		nlc -> maintain();
		nrc -> maintain();
		nroot -> maintain();
	}
	template <typename T>
	typename
	rbtree<T>::iterator rbtree<T>::lower_bound(T v) {
		Node *ptn = _root;
		while (ptn) {
			_hot = ptn;
			if (ptn -> val < v) {
				ptn = ptn -> rc;
			}
			else {
				ptn = ptn -> lc;
			}
		}
		if (_hot -> val < v) {
			ptn = _hot;
		}
		else {
			ptn = _hot -> left_node();
		}
		return iterator(ptn);
	}
	template <typename T>
	typename
	rbtree<T>::iterator rbtree<T>::upper_bound(T v) {
		Node *ptn = _root;
		while (ptn) {
			_hot = ptn;
			if (ptn -> val > v) {
				ptn = ptn -> lc;
			}
			else {
				ptn = ptn -> rc;
			}
		}
		if (_hot -> val > v) {
			ptn = _hot;
		}
		else {
			ptn = _hot -> right_node();
		}
		return iterator(ptn);
	}
	template <typename T>
	typename
	rbtree<T>::iterator rbtree<T>::atrank(int rank) {
		return iterator(findatrank(rank + 1, _root));
	}
	template <typename T>
	typename
	rbtree<T>::Node *rbtree<T>::findatrank(int rank, Node *ptn) {
		if (!(ptn -> lc)) {
			if (rank == 1) {
				return ptn;
			}
			else {
				return findatrank(rank - 1, ptn -> rc);
			}
		}
		else {
			if (ptn -> lc -> s == rank - 1)
				return ptn;
			else if (ptn -> lc -> s >= rank)
				return findatrank(rank, ptn -> lc);
			else
				return findatrank(rank - (ptn -> lc -> s) - 1, ptn -> rc);
		}
	}
	template <typename T>
	int rbtree<T>::rank(T v) {
		return find_atrank(v, _root) - 1;
	}
	template <typename T>
	int rbtree<T>::find_atrank(T v, Node *ptn) {
		if (!ptn)
			return 1;
		else if (ptn -> val >= v)
			return find_atrank(v, ptn -> lc);
		else
			return (1 + ((ptn -> lc) ? (ptn -> lc -> s) : 0) + find_atrank(v, ptn -> rc));
	}
	template <typename T>
	int rbtree<T>::size() {
		return _root -> s;
	}
	template <typename T>
	bool rbtree<T>::empty() {
		return !_root;
	}
	template <typename T>
	bool rbtree<T>::erase(T v) {
		Node *ptn = rfind(v, -1);
		if (!ptn)
			return false;
		Node *node_suc;
		while (ptn -> lc || ptn -> rc) {
			if (!(ptn -> lc)) {
				node_suc = ptn -> rc;
			}
			else if (!(ptn -> rc)) {
				node_suc = ptn -> lc;
			}
			else {
				node_suc = ptn -> succ();
			}
			--(ptn -> s);
			ptn -> val = node_suc -> val;
			ptn = node_suc;
		}
		if (!(ptn -> RBc)) {
			--(ptn -> s);
			SolveDoubleBlack(ptn);
		}
		if (ptn == _root) {
			_root = NULL;
			delete ptn;
			return true;
		}
		if (ptn -> ftr -> lc == ptn)
			ptn -> ftr -> lc = NULL;
		else
			ptn -> ftr -> rc = NULL;
		delete ptn;
		return true;
	}
	template <typename T>
	void rbtree<T>::SolveDoubleBlack(Node *nn) {
		while (nn != _root) {
			Node *pftr = nn -> ftr;
			Node *bthr = bro(nn);
			if (bthr -> RBc) {
				bthr -> RBc = false;
				pftr -> RBc = true;
				if (_root == pftr)
					_root = bthr;
				if (pftr -> ftr) {
					if (pftr -> ftr -> lc == pftr)
						pftr -> ftr -> lc = bthr;
					else
						pftr -> ftr -> rc = bthr;
				}
				bthr -> ftr = pftr -> ftr;
				if (islc(nn)) {
					connect34(bthr, pftr, bthr -> rc, nn, bthr -> lc, bthr -> rc -> lc, bthr -> rc -> rc);
				}
				else {
					connect34(bthr, bthr -> lc, pftr, bthr -> lc -> lc, bthr -> lc -> rc, bthr -> rc, nn);
				}
				bthr = bro(nn);
				pftr = nn -> ftr;
			}
			if (bthr -> lc && bthr -> lc -> RBc) {
				bool oldRBc = pftr -> RBc;
				pftr -> RBc = false;
				if (pftr -> lc == nn) {
					if (pftr -> ftr) {
						if (pftr -> ftr -> lc == pftr)
							pftr -> ftr -> lc = bthr -> lc;
						else
							pftr -> ftr -> rc = bthr -> lc;
					}
					bthr -> lc -> ftr = pftr -> ftr;
					if (_root == pftr)
						_root = bthr -> lc;
					connect34(bthr -> lc, pftr, bthr, pftr -> lc, bthr -> lc -> lc, bthr -> lc -> rc, bthr -> rc);
				}
				else {
					bthr -> lc -> RBc = false;
					if (pftr -> ftr) {
						if (pftr -> ftr -> lc == pftr)
							pftr -> ftr -> lc = bthr;
						else
							pftr -> ftr -> rc = bthr;
					}
					bthr -> ftr = pftr -> ftr;
					if (_root == pftr)
						_root = bthr;
					connect34(bthr, bthr -> lc, pftr, bthr -> lc -> lc, bthr -> lc -> rc, bthr -> rc, pftr -> rc);
				}
				pftr -> ftr -> RBc = oldRBc;
				return;
			}
			else if (bthr -> rc && bthr -> rc -> RBc) {
				bool oldRBc = pftr -> RBc;
				pftr -> RBc = false;
				if (pftr -> lc == nn) {
					bthr -> rc -> RBc = false;
					if (pftr -> ftr) {
						if (pftr -> ftr -> lc == pftr)
							pftr -> ftr -> lc = bthr;
						else
							pftr -> ftr -> rc = bthr;
					}
					bthr -> ftr = pftr -> ftr;
					if (_root == pftr)
						_root = bthr;
					connect34(bthr, pftr, bthr -> rc, pftr -> lc, bthr -> lc, bthr -> rc -> lc, bthr -> rc -> rc);
				}
				else {
					if (pftr -> ftr) {
						if (pftr -> ftr -> lc == pftr)
							pftr -> ftr -> lc = bthr -> rc;
						else
							pftr -> ftr -> rc = bthr -> rc;
					}
					bthr -> rc -> ftr = pftr -> ftr;
					if (_root == pftr)
						_root = bthr -> rc;
					connect34(bthr -> rc, bthr, pftr, bthr -> lc, bthr -> rc -> lc, bthr -> rc -> rc, pftr -> rc);
				}
				pftr -> ftr -> RBc = oldRBc;
				return;
			}
			if (pftr -> RBc) {
				pftr -> RBc = false;
				bthr -> RBc = true;
				return;
			}
			else {
				bthr -> RBc = true;
				nn = pftr;
			}
		}
	}
#undef bro
#undef islc
#undef isrc
}
using red_black_tree :: rbtree;

int main() {
	srand(time(NULL));
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0, x; i < n; ++ i)
		scanf("%d", &x), a[x] ++;
	for (int i = 1; i <= m; ++ i)
		has[a[i]].push_back(i);
	sum[0] = has[0].size();
	for (int i = 1; i <= n; ++ i)
		sum[i] = sum[i - 1] + has[i].size();
	for (int i = 1; i <= n; ++ i)
		sum[i] += sum[i - 1];
	int mx = 0;
	for (int i = 1; i <= m; ++ i)
		mx = max(mx, a[i]);
	vector <tuple <int, int, int> > qry;
	for (int i = 0; i < q; ++ i) {
		long long x;
		scanf("%lld", &x), x -= n;
		if (x > sum[mx - 1]) {
			x -= sum[mx - 1];
			ans[i] = (x - 1) % m + 1;
			continue;
		}
		int l = 0, r = mx, now = -1;
		while (l <= r) {
			int mid = l + r >> 1;
			if (x > sum[mid]) l = mid + 1, now = mid;
			else r = mid - 1;
		}
		if (~now) x -= sum[now];
		qry.push_back({now + 1, x, i});
	}
	sort(qry.begin(), qry.end(), [&](auto X, auto Y) -> bool {
		if (get <0>(X) != get <0>(Y)) return get <0>(X) < get <0>(Y);
		if (get <1>(X) != get <1>(Y)) return get <1>(X) < get <1>(Y);
		return get <2>(X) < get <2>(Y);
	});
	int now = 0;
	rbtree <int> st;
	for (auto &[dep, x, id]: qry) {
		for (; now <= dep; ++ now)
			for (auto &it: has[now])
				st.insert(it);
		ans[id] = *st.atrank(x - 1);
	}
	for (int i = 0; i < q; ++ i)
		printf("%d\n", ans[i]);
	return 0;
}