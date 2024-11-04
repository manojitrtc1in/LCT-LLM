#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<list>
#include<queue>
#include<cmath>
#include<functional>
#include<algorithm>
#include<utility>
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;


#if defined(_MSC_VER)||defined(__SSE4_2__)
#include<nmmintrin.h>
#endif

inline int popCount(unsigned long long x) {
#ifdef __GNUC__
	return __builtin_popcountll(x);
#else 
	x = (x >> 1 & 0x5555555555555555ULL) + (x & 0x5555555555555555ULL);
	x = (x >> 2 & 0x3333333333333333ULL) + (x & 0x3333333333333333ULL);
	x = (x >> 4 & 0x0f0f0f0f0f0f0f0fULL) + (x & 0x0f0f0f0f0f0f0f0fULL);
	x = (x >> 8 & 0x00ff00ff00ff00ffULL) + (x & 0x00ff00ff00ff00ffULL);
	x = (x >> 16 & 0x0000ffff0000ffffULL) + (x & 0x0000ffff0000ffffULL);
	return ((x >> 32) + (x & 0xffffffff));
#endif
}


inline int kthRightmostPop(unsigned long long pop1, int k) {
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






class DynamicBitVector {
	struct Node {
		int height;
		Node *left, *right;
		int rank, len;
		int sumlen;
		unsigned long long val;

		Node(int val)
			:height(1), left(0), right(0), rank(!!val), len(1), sumlen(1), val(val) {}
		Node(unsigned long long val, int len)
			: height(1), left(0), right(0), rank(popCount(val)), len(len), sumlen(len), val(val) {}
		~Node() {
			if (left)delete left;
			if (right)delete right;
		}
		Node *rotate_right() {
			Node *s = left;
			left = s->right;
			s->right = this;
			update();
			return s;
		}
		Node *rotate_left() {
			Node *s = right;
			right = s->left;
			s->left = this;
			update();
			return s;
		}
		Node *insert_node(Node *p) {
			if (!this)return p;
			left = left->insert_node(p);
			return balance();
		}
		Node* insert(int k, int v) {
			if (!this)return new Node(v);
			int h = height;
			int si = (left ? left->sumlen : 0);
			if (k < si) {
				left = left->insert(k, v);
				if (h < left->height + 1)return balance();
				rank += v;
				sumlen++;
				return this;
			}
			else if (k - si <= len && k - si < 8 * sizeof(long long) ) {
				k -= si;
				if (len<8 * sizeof(long long)) {
					val = (~((1ULL << k) - 1)&val) << 1 | (unsigned long long)v << k | (((1ULL << k) - 1)&val);
					rank += v;
					len++;
					sumlen++;
					return this;
				}
				else {
					int a = val >> (8 * sizeof(long long) - 1);
					val = (~((1ULL << k) - 1)&val) << 1 | (unsigned long long)v << k | (((1ULL << k) - 1)&val);
					rank += v;
					sumlen++;
					right = right->insert(0, a);
					if (h < right->height + 1)return balance();
					return this;
				}
			}
			else {
				right = right->insert(k - si - len, v);
				if (h < right->height + 1)return balance();
				rank += v;
				sumlen++;
				return this;
			}
		}
		int access(int k)const {
			int si = (left ? left->sumlen : 0);
			return k<si ? left->access(k) :
				k<si + len ? (val >> k - si & 1) : right->access(k - si - len);
		}
		pair<bool, Node*> erase(int k) {
			if (!this)return make_pair(false, (Node*)NULL);
			int h = height;
			int si = (left ? left->sumlen : 0);
			if (k < si) {
				rank -= left->rank;
				pair<bool, Node*> t = left->erase(k);
				left = t.second;
				if (t.first)t.second = balance();
				else {
					t.second = this;
					if (left)rank += left->rank;
					sumlen--;
				}
				return make_pair(h != height, t.second);
			}
			else if (k<si + len) {
				k -= si;
				if (1<len) {
					rank -= val >> k & 1;
					

					

					

					val = (~((1ULL << k) | (1ULL << k) - 1)&val) >> 1 | (((1ULL << k) - 1)&val);
					len--;
					sumlen--;
					return make_pair(false, this);
				}
				else {
					Node *le = left, *ri = right;
					left = right = NULL;
					delete this;
					if (!le)return make_pair(true, ri);
					if (!ri)return make_pair(true, le);
					Node *t;
					le = le->erase_max(&t);
					t->left = le;
					t->right = ri;
					return  make_pair(true, t->balance());
				}
			}
			else {
				rank -= right->rank;
				pair<bool, Node*> t = right->erase(k - si - len);
				right = t.second;
				if (t.first)t.second = balance();
				else {
					t.second = this;
					if (right)rank += right->rank;
					sumlen--;
				}
				return make_pair(h != height, t.second);
			}
		}
		int rank_lt(int k)const {
			if (!this)return 0;
			int si = (left ? left->sumlen : 0);
			if (k<si) {
				return left->rank_lt(k);
			}
			else if (k<si + len) {
				return (left ? left->rank : 0) + popCount(((1ULL << k - si) - 1)&val);
			}
			else {
				

				return right ? rank - right->rank + right->rank_lt(k - si - len) : rank;
			}
		}
		int select1(int k)const {
			int sr = (left ? left->rank : 0);
			if (k<sr) {
				return left->select1(k);
			}
			else if (k<sr + popCount(val)) {
				return (left ? left->sumlen : 0) + kthRightmostPop(val, k - sr);
			}
			else
				return right->select1(k - sr - popCount(val));
		}
		int select0(int k)const {
			int sr = (left ? left->sumlen - left->rank : 0);
			if (k<sr) {
				return left->select0(k);
			}
			else if (k<sr + len - popCount(val)) {
				return (left ? left->sumlen : 0) + kthRightmostPop(~val, k - sr);
			}
			else
				return right->select0(k - sr - (len - popCount(val)));
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
		Node* erase_max(Node **maxnode) {
			if (right) {
				right = right->erase_max(maxnode);
				return balance();
			}
			else {
				*maxnode = this;
				return left;
			}
		}
	} *root;
public:
	DynamicBitVector() :root(0) {}
	~DynamicBitVector() { if (root)delete root; }
	void insert(int k, int v) {
		root = root->insert(k, v);
	}
	void erase(int k) {
		root = root->erase(k).second;
	}
	int access(int n)const {
		return root->access(n);
	}
	int size()const {
		return root ? root->sumlen : 0;
	}
	int rank(int k)const {

		return root->rank_lt(k + 1);
	}
	int rank()const {
		return root ? root->rank : 0;
	}
	int select1(int k)const { return root->select1(k); }

	int select0(int k)const { return root->select0(k); }
};




class DynamicWaveletMatrix {
	typedef int Val;
	static const Val NIL = -1;
	static const int BITLEN = 20;
	int len;
	DynamicBitVector bv[BITLEN];
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
	DynamicWaveletMatrix() :len(0) {
	}
	DynamicWaveletMatrix(const vector<Val> &str) {
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
				k = len - bv[i].rank() + bv[i].rank(k) - 1;
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
			int ssum = bv[i].rank(s - 1);
			int esum = bv[i].rank(e - 1);
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
			int sum = bv[i].rank(k - 1);
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
				k = len - bv[i].rank() + bv[i].rank(k - 1);
			}
			else {
				k = k - bv[i].rank(k - 1);
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
	cin >> n;
	rep(i, n)cin >> a[i];
	DynamicWaveletMatrix wm(vector<int>(a, a + n));
	cin >> q;
	int lastans = 0;
	rep(i, q) {
		int t, l, r, k;
		cin >> t >> l >> r;
		l = (l + lastans - 1) % n;
		r = (r + lastans - 1) % n;
		if (r<l)swap(l, r);
		if (t == 1) {
			int v = wm.access(r);
			wm.erase(r);
			wm.insert(l, v);
		}
		else {
			cin >> k;
			k = (k + lastans - 1) % n + 1;
			lastans = wm.rank(l, r + 1, k);
			cout << ' ' << lastans << endl;
			

		}
	}
	return 0;
}