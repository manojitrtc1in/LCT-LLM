














using namespace std;






inline int popCount(unsigned long long x) {

	return __builtin_popcountll(x);

	x = (x >> 1 & 0x5555555555555555ULL) + (x & 0x5555555555555555ULL);
	x = (x >> 2 & 0x3333333333333333ULL) + (x & 0x3333333333333333ULL);
	x = (x >> 4 & 0x0f0f0f0f0f0f0f0fULL) + (x & 0x0f0f0f0f0f0f0f0fULL);
	x = (x >> 8 & 0x00ff00ff00ff00ffULL) + (x & 0x00ff00ff00ff00ffULL);
	x = (x >> 16 & 0x0000ffff0000ffffULL) + (x & 0x0000ffff0000ffffULL);
	return ((x >> 32) + (x & 0xffffffff));

}


inline int id1(unsigned long long pop1, int k) {
	unsigned long long pop2, pop4, pop8, pop16, pop32;
	int pos = 0;
	pop2 = (pop1 >> 1 & 0x5555555555555555ULL) + (pop1 & 0x5555555555555555ULL);
	pop4 = (pop2 >> 2 & 0x3333333333333333ULL) + (pop2 & 0x3333333333333333ULL);
	pop8 = (pop4 >> 4 & 0x0f0f0f0f0f0f0f0fULL) + (pop4 & 0x0f0f0f0f0f0f0f0fULL);
	pop16 = (pop8 >> 8 & 0x00ff00ff00ff00ffULL) + (pop8 & 0x00ff00ff00ff00ffULL);
	pop32 = (pop16 >> 16 & 0x0000ffff0000ffffULL) + (pop16 & 0x0000ffff0000ffffULL);
	if ((pop32 & 0xffffffff) < k) {
		k -= (pop32 & 0xffffffff);
		pos |= 32;
	}
	if ((pop16 & 0x0000ffff) < k) {
		k -= (pop16 & 0x0000ffff);
		pos |= 16;
	}
	if ((pop8 >> pos & 0x000000ff) < k) {
		k -= (pop8 >> pos & 0x000000ff);
		pos |= 8;
	}
	if ((pop4 >> pos & 0x0000000f) < k) {
		k -= (pop4 >> pos & 0x0000000f);
		pos |= 4;
	}
	if ((pop2 >> pos & 0x00000003) < k) {
		k -= (pop2 >> pos & 0x00000003);
		pos |= 2;
	}
	if ((pop1 >> pos & 0x00000001) < k)pos |= 1;
	return pos;
}






class id0 {
	struct Node {
		int height;
		Node *left, *right, *par;
		int rank, len;
		int sumlen;
		unsigned long long val;

		Node(int val)
			:height(1), left(0), right(0), par(0), rank(val != 0), len(1), sumlen(1), val(val) {}
		~Node() {
			if (left)delete left;
			if (right)delete right;
		}
		Node *rotate_right() {
			Node *s = left;
			s->par = par;
			left = s->right;
			if (left)left->par = this;
			s->right = this;
			par = s;
			update();
			return s;
		}
		Node *rotate_left() {
			Node *s = right;
			s->par = par;
			right = s->left;
			if (right)right->par = this;
			s->left = this;
			par = s;
			update();
			return s;
		}
		Node *balance() {
			int bf = (right ? right->height : 0) - (left ? left->height : 0);
			if (2 == bf) {
				Node *t = right;
				if ((t->right ? t->right->height : 0) < (t->left ? t->left->height : 0)) {
					right = t->rotate_right();
				}
				return rotate_left()->update();
			}
			else if (bf == -2) {
				Node *t = left;
				if ((t->right ? t->right->height : 0) > (t->left ? t->left->height : 0)) {
					left = t->rotate_left();
				}
				return rotate_right()->update();
			}
			return update();
		}
		Node *update() {
			if (!this)return this;
			rank = popCount(val);
			sumlen = len;
			height = 0;
			if (left) {
				rank += left->rank;
				sumlen += left->sumlen;
				height = left->height;
			}
			if (right) {
				rank += right->rank;
				sumlen += right->sumlen;
				if (right->height > height)height = right->height;
			}
			height++;
			return this;
		}
	};


	static Node* insert(Node *u, int k, int v) {
		Node *root = u;
		if (root == nullptr)return new Node(v);
		int dir = 0;
		while (1) {
			int si = (u->left != nullptr ? u->left->sumlen : 0);
			if (k < si) {
				if (u->left == nullptr) {
					u->left = new Node(v);
					u->left->par = u;
					break;
				}
				u->rank += v;
				u->sumlen++;
				u = u->left;
				dir = dir << 1 | 1;
			}
			else if (k - si <= u->len) {
				u->rank += v;
				u->sumlen++;
				k -= si;
				if (u->len < 64) {
					u->len++;
					u->val = (~((1ULL << k) - 1)&u->val) << 1 | (unsigned long long)v << k | (((1ULL << k) - 1)&u->val);
					return root;
				}
				else {
					int a = v;
					if (k < 64) {
						a = u->val >> 63 & 1;
						u->val = (~((1ULL << k) - 1)&u->val) << 1 | (unsigned long long)v << k | (((1ULL << k) - 1)&u->val);
						v = a;
					}
					k = 0;
					if (u->right == nullptr) {
						u->right = new Node(v);
						u->right->par = u;
						break;
					}
					u = u->right;
					dir = dir << 1 | 0;
				}
			}
			else {
				if (u->right == nullptr) {
					u->right = new Node(v);
					u->right->par = u;
					break;
				}
				k -= si + u->len;
				u->rank += v;
				u->sumlen++;
				u = u->right;
				dir = dir << 1 | 0;
			}
		}
		while (u->par != nullptr) {
			int h = u->height;
			u = u->balance();
			if (dir & 1)u->par->left = u;
			else u->par->right = u;
			dir >>= 1;
			if (h == u->height)break;
			u = u->par;
		}
		if (u == root)return u->balance();
		return root;
		

		

	}
	static int access(const Node *u, int k) {
		while (1) {
			int si = (u->left ? u->left->sumlen : 0);
			if (k < si)u = u->left;
			else if (k < si + u->len)return u->val >> k - si & 1;
			else {
				k -= si + u->len;
				u = u->right;
			}
		}
	}
	static Node* erase(Node *u, int k) {
		Node *root = u;
		if (root == nullptr)return root;
		if (root->sumlen == 1) {
			delete root;
			return nullptr;
		}
		if (k < 0 || u->sumlen <= k)return root;
		int dir = 0;
		while (1) {
			int si = (u->left != nullptr ? u->left->sumlen : 0);
			if (k < si) {
				u->sumlen--;
				u = u->left;
				dir = dir << 1 | 1;
			}
			else if (k - si < u->len) {
				u->len--;
				u->sumlen--;
				k -= si;
				int del = u->val >> k & 1;
				if (0 < u->len) {
					u->val = (~((1ULL << k) | (1ULL << k) - 1)&u->val) >> 1 | (((1ULL << k) - 1)&u->val);
					if (del == 0)return root;
					while (u) {
						u->rank--;
						u = u->par;
					}
					return root;
				}
				else {
					break;
				}
			}
			else {
				k -= si + u->len;
				u->sumlen--;
				u = u->right;
				dir = dir << 1 | 0;
			}
		}

		if (u->left == nullptr) {
			Node *ri = u->right;
			u->left = u->right = nullptr;
			if (ri)ri->par = u->par;
			if (u->par) {
				if (dir & 1)u->par->left = ri;
				else u->par->right = ri;
				dir >>= 1;
			}
			Node *s = u->par;
			delete u;
			u = s;
		}
		else {
			Node *s = u->left;
			dir = dir << 1 | 1;
			while (s->right) {
				s = s->right;
				dir = dir << 1 | 0;
			}
			u->len = s->len;
			u->val = s->val;

			Node *t;
			if (s->left) {
				t = s->left;
				t->par = s->par;
			}
			else {
				t = s->par;
				if (dir & 1)t->left = nullptr;
				else t->right = nullptr;
				dir >>= 1;
			}
			s->left = nullptr;
			delete s;
			u = t;
		}
		while (u->par != nullptr) {
			u = u->balance();
			if (dir & 1)u->par->left = u;
			else u->par->right = u;
			dir >>= 1;
			u = u->par;
		}
		return u->balance();
	}
	static int rank_lt(const Node *u, int k) {
		int r = 0;
		while (1) {
			int si = (u->left ? u->left->sumlen : 0);
			if (k < si)u = u->left;
			else if (k < si + u->len)return r + (u->left ? u->left->rank : 0) + popCount(((1ULL << k - si) - 1)&u->val);
			else {
				if (u->right == nullptr)return r + u->rank;
				k -= si + u->len;
				r += u->rank - u->right->rank;
				u = u->right;
			}
		}
		return r;
	}
	static int select1(const Node *u, int k) {
		int r = 0;
		while (1) {
			int sr = (u->left ? u->left->rank : 0);
			if (k < sr)u = u->left;
			else if (k < sr + popCount(u->val))return r + (u->left ? u->left->sumlen : 0) + id1(u->val, k - sr);
			else {
				k -= u->rank - u->right->rank;
				r += u->sumlen - u->right->sumlen;
				u = u->right;
			}
		}
		return r;
	}
	static int select0(const Node *u, int k) {
		int r = 0;
		while (1) {
			int sr = (u->left ? u->left->sumlen - u->left->rank : 0);
			if (k < sr)u = u->left;
			else if (k < sr + u->len - popCount(u->val))return r + (u->left ? u->left->sumlen : 0) + id1(~u->val, k - sr);
			else {
				k -= (u->sumlen - u->right->sumlen) - (u->rank - u->right->rank);
				r += u->sumlen - u->right->sumlen;
				u = u->right;
			}
		}
		return r;
	}

	Node *root;
public:
	id0() :root(0) {}
	~id0() { if (root)delete root; }
	void insert(int k, int v) {
		root = insert(root, k, v);
	}
	void erase(int k) {
		root = erase(root, k);
	}
	int access(int n)const {
		return access(root, n);
	}
	int size()const {
		return root ? root->sumlen : 0;
	}
	int rank(int k)const {

		return rank_lt(root, k);
	}
	int rank()const {
		return root ? root->rank : 0;
	}
	int select1(int k)const { return select1(root, k); }

	int select0(int k)const { return select0(root, k); }
};





class id2 {
	typedef int Val;
	static const Val NIL = -1;
	static const int BITLEN = 20;
	int len;
	id0 bv[BITLEN];
	int encode(Val c)const {
		return c;
	}
	Val decode(int n)const {
		return n;
	}
	struct Node {
		int height, s, e, code;
		Node() {}
		Node(int a, int b, int c, int d) :height(a), s(b), e(c), code(d) {};
		bool operator <(Node a)const { return e - s<a.e - a.s; }
	};
public:
	int length()const {
		return len;
	}
	id2() :len(0) {
	}
	id2(const vector<Val> &str) {
		init(str);
	}
	void init(const vector<Val> &str) {
		len = str.size();
		int *bucket;
		bucket = new int[2 * len];
		int *cur, *next;
		cur = bucket;
		next = bucket + len;
		int rank0[BITLEN] = { 0 };
		for (int i = 0; i<len; i++) {
			int n = encode(str[i]);
			cur[i] = n;
			for (int j = BITLEN - 1; j >= 0; j--) {
				if ((n & 1 << j) == 0)rank0[j]++;

			}
		}
		for (int i = BITLEN - 1;; i--) {
			for (int j = 0; j<len; j++) {
				

				bv[i].insert(j, cur[j] >> i & 1);
			}
			if (i == 0)break;
			int idx0 = 0, idx1 = rank0[i];
			for (int j = 0; j<len; j++) {
				if (cur[j] & 1 << i)next[idx1++] = cur[j];
				else next[idx0++] = cur[j];
			}
			swap(cur, next);
		}
		delete[] bucket;
	}
	Val access(int k)const {
		int code = 0;
		for (int i = BITLEN - 1; i>0; i--) {
			if (bv[i].access(k)) {
				code |= 1 << i;
				k = len - bv[i].rank() + bv[i].rank(k);
			}
			else {
				k = k - bv[i].rank(k);
			}
		}
		if (bv[0].access(k))code |= 1;
		return decode(code);
	}
	int rank(int s, int e, Val c)const {
		int n = encode(c);
		for (int i = BITLEN - 1; i >= 0; i--) {
			int ssum = bv[i].rank(s);
			int esum = bv[i].rank(e);
			if (n & 1 << i) {
				s = len - bv[i].rank() + ssum;
				e = s + esum - ssum;
			}
			else {
				s = s - ssum;
				e = e - esum;
			}
		}
		return e - s;
	}

	void insert(int k, Val c) {
		int n = encode(c);
		for (int i = BITLEN - 1; i >= 0; i--) {
			int sum = bv[i].rank(k);
			int prev = k;
			if (n & 1 << i) {
				k = len - bv[i].rank() + sum;
				bv[i].insert(prev, 1);
			}
			else {
				k = k - sum;
				bv[i].insert(prev, 0);
			}
		}
		len++;
	}
	void erase(int k) {
		for (int i = BITLEN - 1; i >= 0; i--) {
			int prev = k;
			if (bv[i].access(k)) {
				k = len - bv[i].rank() + bv[i].rank(k);
			}
			else {
				k = k - bv[i].rank(k);
			}
			bv[i].erase(prev);
		}
		len--;
	}
};



int a[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	scanf("%d", &n);
	rep(i, n)scanf("%d", &a[i]);
	id2 wm(vector<int>(a, a + n));
	scanf("%d", &q);
	int lastans = 0;
	rep(i, q) {
		int t, l, r, k;
		scanf("%d%d%d", &t, &l, &r);
		l = (l + lastans - 1) % n;
		r = (r + lastans - 1) % n;
		if (r < l)swap(l, r);
		if (t == 1) {
			int v = wm.access(r);
			wm.erase(r);
			wm.insert(l, v);
		}
		else {
			scanf("%d", &k);
			k = (k + lastans - 1) % n + 1;
			lastans = wm.rank(l, r + 1, k);
			printf(" %d\n", lastans);
		}
	}
	return 0;
}

