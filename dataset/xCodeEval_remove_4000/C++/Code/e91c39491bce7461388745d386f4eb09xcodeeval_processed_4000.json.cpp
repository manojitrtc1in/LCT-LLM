









































using namespace std;





using namespace tr1;










using namespace __gnu_pbds;


typedef __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq_type;


typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> tree_type;



typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef map<string, int> mpsi;
typedef map<double, int> mpdi;
typedef map<int, int> mpii;

const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 1 }, {
		1, 1 }, { 1, -1 }, { -1, -1 } };

template<class T> inline T abs1(T a) {
	return a < 0 ? -a : a;
}


template <class T> inline T max1(T a, T b) { return b < a ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }

template<typename t, typename t1>
t min1(t a, t1 b) {
	return a < b ? a : b;
}
template<typename t, typename ... arg>
t min1(t a, arg ... arr) {
	return min1(a, min1(arr...));
}
template<typename t, typename t1>
t max1(t a, t1 b) {
	return a > b ? a : b;
}
template<typename t, typename ... arg>
t max1(t a, arg ... arr) {
	return max1(a, max1(arr...));
}


inline int jud(double a, double b) {
	if (abs(a) < eps && abs(b) < eps)
		return 0;
	else if (abs1(a - b) / max(abs1(a), abs1(b)) < eps) return 0;
	if (a < b) return -1;
	return 1;
}
template<typename t> inline int jud(t a, t b) {
	if (a < b) return -1;
	if (a == b) return 0;
	return 1;
}



template<typename it, typename t1>
inline int RangeFind(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
	if (na == 0) return 0;
	int be = 0, en = na - 1;
	if (*a <= *(a + na - 1)) {
		if (f_lb == 0)
			while (be < en) {
				int mid = (be + en + 1) / 2;
				if (jud(*(a + mid), val) != 1)
					be = mid;
				else
					en = mid - 1;
			}
		else
			while (be < en) {
				int mid = (be + en) / 2;
				if (jud(*(a + mid), val) != -1)
					en = mid;
				else
					be = mid + 1;
			}
		if (f_small && jud(*(a + be), val) == 1) be--;
		if (!f_small && jud(*(a + be), val) == -1) be++;
	} else {
		if (f_lb)
			while (be < en) {
				int mid = (be + en + 1) / 2;
				if (jud(*(a + mid), val) != -1)
					be = mid;
				else
					en = mid - 1;
			}
		else
			while (be < en) {
				int mid = (be + en) / 2;
				if (jud(*(a + mid), val) != 1)
					en = mid;
				else
					be = mid + 1;
			}
		if (!f_small && jud(*(a + be), val) == -1) be--;
		if (f_small && jud(*(a + be), val) == 1) be++;
	}
	return be;
}

template<class T> inline T lowb(T num) {
	return num & (-num);
}

inline int bitnum(ui nValue) {
	return __builtin_popcount(nValue);
}
inline int bitnum(int nValue) {
	return __builtin_popcount(nValue);
}
inline int bitnum(ull nValue) {
	return __builtin_popcountll(nValue);
}
inline int bitnum(ll nValue) {
	return __builtin_popcountll(nValue);
}
inline int id2(ui a) {
	if (a == 0) return 0;
	return 32 - __builtin_clz(a);
}
inline int id2(int a) {
	if (a == 0) return 0;
	return 32 - __builtin_clz(a);
}
inline int id2(ull a) {
	if (a == 0) return 0;
	return 64 - __builtin_clzll(a);
}
inline int id2(ll a) {
	if (a == 0) return 0;
	return 64 - __builtin_clzll(a);
}



long long pow(long long n, long long m, long long mod = 0) {
	if (m < 0) return 0;
	long long ans = 1;
	long long k = n;
	while (m) {
		if (m & 1) {
			ans *= k;
			if (mod) ans %= mod;
		}
		k *= k;
		if (mod) k %= mod;
		m >>= 1;
	}
	return ans;
}


template<class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
	if (mod == -1) mod = MOD;
	a += b;
	while (a >= mod)
		a -= mod;
	while (a < 0)
		a += mod;
}
template<class t>
void output1(t arr) {
	for (int i = 0; i < (int) arr.size(); i++)
		cerr << arr[i] << ' ';
	cerr << endl;
}
template<class t>
void output2(t arr) {
	for (int i = 0; i < (int) arr.size(); i++)
		output1(arr[i]);
}




const int maxn = 300100;

int arr[maxn];
int n, nq;
int dp[maxn];
int last[maxn];


struct treap_node {
	int left, right, sz, fa, ge;
	double prio;
	treap_type val;
};
treap_node treap_arr[maxn];
int id0 = 0, maxl = 0;
int nxt[maxn];
struct treap {
	int sz, root;
	unsigned int prea, preb;

	treap() {
		srand(unsigned (time(NULL)));
		root = -1;
		sz = 0;
		prea = preb = 1;
	}
	inline double rannum() {
		prea = prea * rand() % 32761 + 1;
		preb = preb * rand() % 32761 + 1;
		return 1.0 * prea / preb;
	}
	

	treap_node * getrank(int ranrank, int no = -1) {
		if(no == -1) no = root;
		if(treap_arr[no].left != -1 && ranrank <= treap_arr[treap_arr[no].left].sz)
			return getrank(ranrank, treap_arr[no].left);
		if(treap_arr[no].left != -1) ranrank -= treap_arr[treap_arr[no].left].sz;
		ranrank -= treap_arr[no].ge;
		if(ranrank <= 0 || treap_arr[no].right == -1) return treap_arr + no;
		return getrank(ranrank, treap_arr[no].right);
	}
	int getnotbig(treap_type val, int no = -1) {
		if(sz == 0) return 0;
		if(no == -1) no = root;
		if(treap_arr[no].val == val) {
			if(treap_arr[no].left != -1) return treap_arr[no].ge + treap_arr[treap_arr[no].left].sz;
			return treap_arr[no].ge;
		}
		if(treap_arr[no].val > val) {
			if(treap_arr[no].left != -1) return getnotbig(val, treap_arr[no].left);
			return 0;
		}else {
			if(treap_arr[no].right != -1) return getnotbig(val, treap_arr[no].right) + treap_arr[no].sz - treap_arr[treap_arr[no].right].sz;
			return treap_arr[no].sz;
		}
	}
	inline void relaxfa(int no) {
		if(treap_arr[no].fa == -1) return;
		if(treap_arr[treap_arr[no].fa].val > treap_arr[no].val) treap_arr[treap_arr[no].fa].left = no;
		else treap_arr[treap_arr[no].fa].right = no;
	}
	inline void relax(int no) {
		treap_arr[no].sz = treap_arr[no].ge;
		if(treap_arr[no].left != -1) treap_arr[no].sz += treap_arr[treap_arr[no].left].sz;
		if(treap_arr[no].right != -1) treap_arr[no].sz += treap_arr[treap_arr[no].right].sz;
	}
	inline void relaxtofa(int no) {
		while(no != -1) {
			relax(no);
			root = no;
			no = treap_arr[no].fa;
		}
	}
	inline void right_rot(int no) {
		int fa = treap_arr[no].fa;
		treap_arr[no].fa = treap_arr[fa].fa;
		treap_arr[fa].left = treap_arr[no].right;
		if(treap_arr[no].right != -1) treap_arr[treap_arr[no].right].fa = fa;
		treap_arr[no].right = fa;
		treap_arr[fa].fa = no;
		relax(fa);
		relaxfa(no);
		relax(no);
	}
	inline void left_rot(int no) {
		int fa = treap_arr[no].fa;
		treap_arr[no].fa = treap_arr[fa].fa;
		treap_arr[fa].right = treap_arr[no].left;
		if(treap_arr[no].left != -1) treap_arr[treap_arr[no].left].fa = fa;
		treap_arr[no].left = fa;
		treap_arr[fa].fa = no;
		relax(fa);
		relaxfa(no);
		relax(no);
	}
	void insert(treap_type val) {
		int id1 = maxl;
		sz++;
		treap_arr[id0].prio = rannum();
		treap_arr[id0].left = treap_arr[id0].right = treap_arr[id0].fa = -1;
		if(id0 == maxl) {
			maxl++;
			nxt[id0] = maxl;
		}
		treap_arr[id0].val = val;
		if(sz == 1) {
			root = id0;
			treap_arr[id0].sz = 1;
			treap_arr[id0].ge = 1;
			id0 = nxt[id0];
			return;
		}
		int no = root;
		while(no != -1) {
			if(treap_arr[no].val == treap_arr[id0].val) break;
			treap_arr[id0].fa = no;
			if(treap_arr[no].val < treap_arr[id0].val) no = treap_arr[no].right;
			else no = treap_arr[no].left;
		}
		if(no != -1) {
			treap_arr[no].ge++;
			maxl = id1;
			relaxtofa(no);
			return;
		}
		treap_arr[id0].ge = 1; treap_arr[id0].sz = 1;
		if(treap_arr[id0].val < treap_arr[treap_arr[id0].fa].val) treap_arr[treap_arr[id0].fa].left = id0;
		else treap_arr[treap_arr[id0].fa].right = id0;
		while(treap_arr[id0].fa != -1 && treap_arr[id0].prio > treap_arr[treap_arr[id0].fa].prio) {
			if(treap_arr[id0].val < treap_arr[treap_arr[id0].fa].val) right_rot(id0);
			else left_rot(id0);
		}
		if(treap_arr[id0].fa == -1) root = id0;
		relaxtofa(id0);
		id0 = nxt[id0];
	}
	void del(treap_type val) {
		if(sz == 0) return;
		int no = root;
		while(no != -1) {
			if(treap_arr[no].val == val) break;
			if(treap_arr[no].val > val) no = treap_arr[no].left;
			else no = treap_arr[no].right;
		}
		if(no == -1) return;
		sz--;
		if(sz == 0) {
			nxt[root] = id0;
			id0 = root;
			root = -1;
			sz = 0;
			return;
		}
		treap_arr[no].ge--;
		if(treap_arr[no].ge != 0){
			relaxtofa(no);
			return;
		}
		while(treap_arr[no].left != -1 || treap_arr[no].right != -1) {
			if(treap_arr[no].left == -1) left_rot(treap_arr[no].right);
			else {
				if(treap_arr[no].right == -1 || treap_arr[treap_arr[no].left].prio > treap_arr[treap_arr[no].right].prio) right_rot(treap_arr[no].left);
				else left_rot(treap_arr[no].right);
			}
		}
		int no1 = no;
		if(treap_arr[treap_arr[no].fa].left == no) treap_arr[treap_arr[no].fa].left = -1;
		else treap_arr[treap_arr[no].fa].right = -1;
		relaxtofa(treap_arr[no].fa);
		nxt[no1] = id0;
		id0 = no1;
	}
};





struct SegmentNode{
	int be, en;
	vi t;
};
struct SegmentTree{
	int l;
	SegmentNode tree[SEGMENT_TREE_MAXN * 4];

	inline int GetLeft(int no) {return no << 1;}
	inline int GetRight(int no) {return (no << 1) + 1;}
	inline int GetFa(int no) {return no >> 1;}
	inline SegmentTree(){ l = 0; }

	void Build(int no, int l, int r, NODE_VAL_TYPE orig = 0, NODE_VAL_TYPE *a = NULL){
		if(l > r) r = l;
		if(l == r){
			tree[no].be = tree[no].en = l;
			if(a == NULL) tree[no].t.push_back(orig);
			else tree[no].t.push_back(a[l]);
			return;
		}
		tree[no].be = l; tree[no].en = r;
		int mid = (l + r) / 2;
		Build(GetLeft(no), l, mid, orig, a);
		Build(GetRight(no), mid + 1, r, orig, a);
		for (int i = l; i <= r; i++) {
			if (a) {
				tree[no].t.push_back(a[i]);
			} else {
				tree[no].t.push_back(0);
			}
		}
		sort(tree[no].t.begin(), tree[no].t.end());
		PushUp(no);
	}
	inline void PushUp(int no) {
	}
	inline void PushDown(int no) {
	}
	NODE_VAL_TYPE GetBigger(int l, int r, int no, int num){
		if(l > r) return 0;
		if(l <= tree[no].be && r >= tree[no].en)
			return tree[no].t.end() - upper_bound(tree[no].t.begin(), tree[no].t.end(), (num - 1));


		NODE_VAL_TYPE ans = 0;
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(r >= tree[no].be && l <= mid) ans += GetBigger(l, r, GetLeft(no), num);
		if(r >= mid + 1 && l <= tree[no].en) ans += GetBigger(l, r, GetRight(no), num);
		return ans;
	}
} sgt;

treap all;

int main() {




	ios_base::sync_with_stdio(0);


	freopen("input.txt", "r", stdin);



	scanf("%d%d", &n, &nq);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		arr[i]--;
	}
	memset(last, -1, sizeof(last));
	for (int i = 0; i < n; i++) {
		if (arr[i] == i) {
			dp[i] = i;
			all.insert(-i);
		} else if (arr[i] < i) {
			if (all.sz < i - arr[i]) dp[i] = -1;
			else dp[i] = -all.getrank(i - arr[i])->val;
			all.insert(-dp[i]);
		} else {
			dp[i] = -1;
		}
	}
	sgt.Build(1, 0, n - 1, 0, dp);

	for (int i = 0; i < nq; i++) {
		int pre, suf;
		scanf("%d%d", &pre, &suf);
		if (pre + suf >= n) {
			puts("0");
			continue;
		}
		int st = pre, en = n - suf - 1;
		printf("%d\n", sgt.GetBigger(st, en, 1, st));
	}

	return 0;
}
