#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<random>
#include<array>
#include<cassert>
#include <emmintrin.h>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())


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





class DynamicSecuence2bits {
	struct Node {
		int height;
		Node *left, *right, *par;
		int len;
		int sumlen;
		int rank[4];
		unsigned long long val[4];


		Node(int v)
			:height(1), left(0), right(0), par(0), len(1), sumlen(1){
			memset(rank, 0, sizeof(rank));
			rank[v] = 1;
			memset(val, 0, sizeof(val));
			val[v] = 1;
		}
		~Node() {
			if (left)delete left;
			if (right)delete right;
		}
	};
	static Node *rotate_right(Node *u) {
		Node *s = u->left;
		s->par = u->par;
		u->left = s->right;
		if (u->left)u->left->par = u;
		s->right = u;
		u->par = s;
		update(u);
		return  update(s);
	}
	static Node *rotate_left(Node *u) {
		Node *s = u->right;
		s->par = u->par;
		u->right = s->left;
		if (u->right)u->right->par = u;
		s->left = u;
		u->par = s;
		update(u);
		return update(s);
	}
	static Node *balance(Node *u) {
		int bf = (u->right ? u->right->height : 0) - (u->left ? u->left->height : 0);
		if (2 == bf) {
			Node *t = u->right;
			if ((t->right ? t->right->height : 0) < (t->left ? t->left->height : 0)) {
				u->right = rotate_right(t);
			}
			return rotate_left(u);
		}
		else if (bf == -2) {
			Node *t = u->left;
			if ((t->right ? t->right->height : 0) > (t->left ? t->left->height : 0)) {
				u->left = rotate_left(t);
			}
			return rotate_right(u);
		}
		return update(u);
	}
	static Node *update(Node *u) {
		if (!u)return u;
		for (int i = 0; i < 4; i++)u->rank[i] = popCount(u->val[i]);
		u->sumlen = u->len;
		u->height = 0;
		if (u->left) {
			for (int i = 0; i < 4;i++)u->rank[i] += u->left->rank[i];
			u->sumlen += u->left->sumlen;
			u->height = u->left->height;
		}
		if (u->right) {
			for (int i = 0; i < 4; i++)u->rank[i] += u->right->rank[i];
			u->sumlen += u->right->sumlen;
			if (u->right->height > u->height)u->height = u->right->height;
		}
		u->height++;
		return u;
	}


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
				u->rank[v]++;
				u->sumlen++;
				u = u->left;
				dir = dir << 1 | 1;
			}
			else if (k - si <= u->len) {
				u->rank[v]++;
				u->sumlen++;
				k -= si;
				if (u->len < 64) {
					u->len++;
					for (int i = 0; i < 4; i++) {
						u->val[i] = (~((1ULL << k) - 1)&u->val[i]) << 1 | (unsigned long long)(v == i) << k | (((1ULL << k) - 1)&u->val[i]);
					}
					return root;
				}
				else {
					if (k < 64) {
						int a;
						for (int i = 0; i < 4; i++) {
							if (u->val[i] >> 63 & 1)a = i;
							u->val[i] = (~((1ULL << k) - 1)&u->val[i]) << 1 | (unsigned long long)(v == i) << k | (((1ULL << k) - 1)&u->val[i]);
						}
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
				u->rank[v]++;
				u->sumlen++;
				u = u->right;
				dir = dir << 1 | 0;
			}
		}
		while (u->par != nullptr) {
			int h = u->height;
			u = balance(u);
			if (dir & 1)u->par->left = u;
			else u->par->right = u;
			dir >>= 1;
			if (h == u->height)break;
			u = u->par;
		}
		if (u == root)return balance(u);
		return root;
		

		

	}
	static int access(const Node *u, int k) {
		while (1) {
			int si = (u->left ? u->left->sumlen : 0);
			if (k < si)u = u->left;
			else if (k < si + u->len) {
				for (int i = 0; i < 4; i++) {
					if (u->val[i] >> (k - si) & 1)return i;
				}
				abort();
			}else {
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
				int del;
				for (int i = 0; i < 4; i++)
					if (u->val[i] >> k & 1)del = i;
				if (0 < u->len) {
					for (int i = 0; i < 4; i++)
						u->val[i] = (~((1ULL << k) | ((1ULL << k) - 1))&u->val[i]) >> 1 | (((1ULL << k) - 1)&u->val[i]);
					while (u) {
						u->rank[del]--;
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
			memcpy(u->val, s->val, sizeof(u->val));

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
			u = balance(u);
			if (dir & 1)u->par->left = u;
			else u->par->right = u;
			dir >>= 1;
			u = u->par;
		}
		return balance(u);
	}
	static array<int,4> rank_lt(const Node *u, int k) {
		array<int, 4> r;
		r.fill(0);
		if (!u)return r;
		while (1) {
			int si = (u->left ? u->left->sumlen : 0);
			if (k < si)u = u->left;
			else if (k < si + u->len) {
				if (u->left) {
					for (int i = 0; i < 4; i++)r[i] += u->left->rank[i];
				}
				r[0] += popCount(((1ULL << (k - si)) - 1)&u->val[0]);
				r[1] += popCount(((1ULL << (k - si)) - 1)&u->val[1]);
				r[2] += popCount(((1ULL << (k - si)) - 1)&u->val[2]);
				r[3] += popCount(((1ULL << (k - si)) - 1)&u->val[3]);
				break;
			}
			else {
				if (u->right == nullptr) {
					for (int i = 0; i < 4; i++)r[i] += u->rank[i];
					break;
				}
				k -= si + u->len;
				r[0] += u->rank[0] - u->right->rank[0];
				r[1] += u->rank[1] - u->right->rank[1];
				r[2] += u->rank[2] - u->right->rank[2];
				r[3] += u->rank[3] - u->right->rank[3];
				u = u->right;
			}
		}
		return r;
	}


	Node *root;
public:
	DynamicSecuence2bits() :root(0) {}
	~DynamicSecuence2bits() { if (root)delete root; }
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
	array<int,4> ranks(int k)const {

		return rank_lt(root, k);
	}
};















template<int BITLEN = 30>
class DynamicWaveletMatrix {
	int len;
	DynamicSecuence2bits bv[(BITLEN + 1) / 2];
	int rankt[(BITLEN + 1) / 2][4];

public:
	int length()const {
		return len;
	}
	DynamicWaveletMatrix() :len(0) {
		memset(rankt, 0, sizeof(rankt));
	}
	int access(int k)const {
		int code = 0;
		for (int i = (BITLEN + 1) / 2 - 1; i >= 0; i --) {
			int v = bv[i].access(k);
			code |= v << i * 2;
			int sum = 0;
			for (int j = 0; j < v; j++) {
				sum += rankt[i][j];
			}
			k = sum + bv[i].ranks(k)[v];
		}
		return code;
	}
	int rank(int s, int e, int c)const {
		for (int i = (BITLEN + 1) / 2 - 1; i >= 0; i--) {
			s = bv[i].ranks(s)[c >> (i * 2) & 3];
			e = bv[i].ranks(e)[c >> (i * 2) & 3];
			for (int j = 0; j < (c >> (i * 2) & 3); j++) {
				s += rankt[i][j];
				e += rankt[i][j];
			}
		}
		return e - s;
	}
	

	int quantile(int s, int e, int r)const {
		if (e - s <= r)return -1;
		int code = 0;
		for (int i = (BITLEN + 1) / 2 - 1; i >= 0; i--) {
			auto sr = bv[i].rank(s), er = bv[i].rank(e);
			int v;
			for (int j = 3; j >= 0;j--) {
				v = j;
				if (r < er[j] - sr[j])break;
				r -= er[j] - sr[j];
			}
			code |= v << i * 2;
			s = sr[v];
			e = er[v];
			for (int j = 0; j < v; j++) {
				s += rankt[i][j];
				e += rankt[i][j];
			}
		}
		return code;
	}
	

	int rank_lt(int s, int e, int c)const {
		int res = 0;
		for (int i = (BITLEN + 1) / 2 - 1; i >= 0; i--) {
			auto sr = bv[i].rank(s), er = bv[i].rank(e);
			s = sr[c >> (i * 2) & 3];
			e = er[c >> (i * 2) & 3];
			for (int j = 0; j < (c >> (i * 2) & 3); j++) {
				s += rankt[i][j];
				e += rankt[i][j];
				res += er[j] - sr[j];
			}
			if (s == e)return res;
		}
		return res;
	}
	int rangefreq(int s, int e, int x, int y)const {
		return rank_lt(s, e, y) - rank_lt(s, e, x);
	}
	int nextvalue(int s, int e, int x)const {
		int n = rank_lt(s, e, x + 1);
		if (e - s == n)return -1;
		return quantile(s, e, e - s - 1 - n);
	}
	int prevvalue(int s, int e, int y)const {
		int n = rank_lt(s, e, y);
		if (0 == n)return -1;
		return quantile(s, e, e - s - n);
	}

	void insert(int k, int c) {
		for (int i = (BITLEN + 1) / 2 - 1; i >= 0; i--) {
			int prev = k;
			k = bv[i].ranks(k)[c >> (i * 2) & 3];
			for (int j = 0; j < (c >> (i * 2) & 3); j++) {
				k += rankt[i][j];
			}
			bv[i].insert(prev, c >> (i * 2) & 3);
			rankt[i][c >> (i * 2) & 3]++;
		}
		len++;
	}
	void erase(int k) {
		for (int i = (BITLEN + 1) / 2 - 1; i >= 0; i--) {
			int prev = k;
			int v = bv[i].access(k);
			k = bv[i].ranks(k)[v];
			for (int j = 0; j < v; j++) {
				k += rankt[i][j];
			}
			bv[i].erase(prev);
			rankt[i][v]--;
		}
		len--;
	}
};






int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	DynamicWaveletMatrix<20> wm;
	int n, q;
	scanf("%d", &n);
	rep(i, n) {
		int a;
		scanf("%d", &a);
		wm.insert(i, a);
	}
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