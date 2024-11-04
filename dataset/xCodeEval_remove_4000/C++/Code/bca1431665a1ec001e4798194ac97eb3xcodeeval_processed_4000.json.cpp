





using namespace std;

const int Maxn = 500005;
int n, m, q, a[Maxn];
long long sum[Maxn];
vector <int> has[Maxn];
int ans[Maxn], vis[Maxn];

namespace red_black_tree {



	template <typename T>
	class id2 {
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
			id2() : _root(NULL), _hot(NULL) { }
			id2(const id2 &a) { *this = a; }
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
	struct id2 <T> :: Node {
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
	struct id2<T>::iterator {
		private:
			Node *id8;
		public:
			iterator &operator++() {
				id8 = id8 -> right_node();
				return *this;
			}
			iterator &operator--() {
				id8 = id8 -> left_node();
				return *this;
			}
			T operator*() {
				return id8 -> val;
			}
			iterator(Node *node_nn = NULL) : id8(node_nn) {}
			iterator(T const &id6) : id8(rfind(id6, 0)) {}
			iterator(iterator const &iter) : id8(iter.id8) {}
	};
	template <typename T>
	typename
	id2<T>::iterator id2<T>::insert(T v) {
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
	void id2<T>::init(T v) {
		_root = new Node(v, false, NULL, NULL, NULL, 1);
	}
	template <typename T>
	typename
	id2<T>::Node *id2<T>::find(T v, const int op) {
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
	id2<T>::Node *id2<T>::rfind(T v, const int op) {
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
	void id2<T>::SolveDoubleRed(Node *nn) {
		while ((!(nn -> ftr)) || nn -> ftr -> RBc) {
			if (nn == _root) {
				_root -> RBc = false;
				return;
			}
			Node *pftr = nn -> ftr;
			if (!(pftr -> RBc))
				return;
			Node *uncle = bro(nn -> ftr);
			Node *id3 = nn -> ftr -> ftr;
			if (uncle != NULL && uncle -> RBc) {
				id3 -> RBc = true;
				uncle -> RBc = false;
				pftr -> RBc = false;
				nn = id3;
			}
			else {
				if (islc(pftr)) {
					if (islc(nn)) {
						pftr -> ftr = id3 -> ftr;
						if (id3 == _root)
							_root = pftr;
						else if (id3 -> ftr -> lc == id3)
							id3 -> ftr -> lc = pftr;
						else
							id3 -> ftr -> rc = pftr;
						connect34(pftr, nn, id3, nn -> lc, nn -> rc, pftr -> rc, uncle);
						pftr -> RBc = false;
						id3 -> RBc = true;
					}
					else {
						nn -> ftr = id3 -> ftr;
						if (id3 == _root)
							_root = nn;
						else if (id3 -> ftr -> lc == id3)
							id3 -> ftr -> lc = nn;
						else
							id3 -> ftr -> rc = nn;
						connect34(nn, pftr, id3, pftr -> lc, nn -> lc, nn -> rc, uncle);
						nn -> RBc = false;
						id3 -> RBc = true;
					}
				}
				else {
					if (islc(nn)) {
						nn -> ftr = id3 -> ftr;
						if (id3 == _root)
							_root = nn;
						else if (id3 -> ftr -> lc == id3)
							id3 -> ftr -> lc = nn;
						else
							id3 -> ftr -> rc = nn;
						connect34(nn, id3, pftr, uncle, nn -> lc, nn -> rc, pftr -> rc);
						nn -> RBc = false;
						id3 -> RBc = true;
					}
					else {
						pftr -> ftr = id3 -> ftr;
						if (id3 == _root)
							_root = pftr;
						else if (id3 -> ftr -> lc == id3)
							id3 -> ftr -> lc = pftr;
						else
							id3 -> ftr -> rc = pftr;
						connect34(pftr, id3, nn, uncle, pftr -> lc, nn -> lc, nn -> rc);
						pftr -> RBc = false;
						id3 -> RBc = true;
					}
				}
				return;
			}
		}
	}
	template <typename T>
	void id2<T>::connect34(Node *nroot,		Node *nlc,			Node *nrc,
		Node *id1,	 Node *id9,	 Node *id0,	 Node *id4) {
		nlc -> lc = id1;
		if (id1 != NULL)
			id1 -> ftr = nlc;
		nlc -> rc = id9;
		if (id9 != NULL)
			id9 -> ftr = nlc;
		nrc -> lc = id0;
		if (id0 != NULL)
			id0 -> ftr = nrc;
		nrc -> rc = id4;
		if (id4 != NULL)
			id4 -> ftr = nrc;
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
	id2<T>::iterator id2<T>::lower_bound(T v) {
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
	id2<T>::iterator id2<T>::upper_bound(T v) {
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
	id2<T>::iterator id2<T>::atrank(int rank) {
		return iterator(findatrank(rank + 1, _root));
	}
	template <typename T>
	typename
	id2<T>::Node *id2<T>::findatrank(int rank, Node *ptn) {
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
	int id2<T>::rank(T v) {
		return find_atrank(v, _root) - 1;
	}
	template <typename T>
	int id2<T>::find_atrank(T v, Node *ptn) {
		if (!ptn)
			return 1;
		else if (ptn -> val >= v)
			return find_atrank(v, ptn -> lc);
		else
			return (1 + ((ptn -> lc) ? (ptn -> lc -> s) : 0) + find_atrank(v, ptn -> rc));
	}
	template <typename T>
	int id2<T>::size() {
		return _root -> s;
	}
	template <typename T>
	bool id2<T>::empty() {
		return !_root;
	}
	template <typename T>
	bool id2<T>::erase(T v) {
		Node *ptn = rfind(v, -1);
		if (!ptn)
			return false;
		Node *id5;
		while (ptn -> lc || ptn -> rc) {
			if (!(ptn -> lc)) {
				id5 = ptn -> rc;
			}
			else if (!(ptn -> rc)) {
				id5 = ptn -> lc;
			}
			else {
				id5 = ptn -> succ();
			}
			--(ptn -> s);
			ptn -> val = id5 -> val;
			ptn = id5;
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
	void id2<T>::SolveDoubleBlack(Node *nn) {
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
				bool id7 = pftr -> RBc;
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
				pftr -> ftr -> RBc = id7;
				return;
			}
			else if (bthr -> rc && bthr -> rc -> RBc) {
				bool id7 = pftr -> RBc;
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
				pftr -> ftr -> RBc = id7;
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



}
using red_black_tree :: id2;

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
	id2 <int> st;
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